#!/bin/sh

# ===== 1. Check argument =====
if [ "$1" = "push" ]; then
    mode="push"
elif [ "$1" = "pull" ]; then
    mode="pull"
else
    echo "Usage: $0 push|pull"
    exit 1
fi

# ===== 2. Detect current branch =====
branch=$(git rev-parse --abbrev-ref HEAD 2>/dev/null || true)
if [ -z "$branch" ]; then
    echo "Not in a git repository. Aborting."
    exit 1
fi
echo "Current branch: $branch"

# ===== 3. Check remotes =====
remotes=$(git remote 2>/dev/null || true)

echo "Checking remotes..."
echo "$remotes" | grep -q "^origin$" || echo "Warning: origin (Vogsphere) not found"
echo "$remotes" | grep -q "^Github$" || echo "Warning: Github remote not found"

# ===== 4. Check uncommitted changes =====
if ! git diff --quiet || ! git diff --cached --quiet; then
    echo "You have uncommitted changes."
    echo "Commit them now? (y/n)"
    read answer
    if [ "$answer" = "y" ] || [ "$answer" = "Y" ]; then
        echo "Enter commit message:"
        read msg
        git add .
        git commit -m "$msg"
        echo "Changes committed"
    else
        echo "Aborting. Commit your changes first."
        exit 1
    fi
fi

# ===== 5. Fetch remotes =====
git fetch origin >/dev/null 2>&1 || echo "Warning: Could not fetch from origin"
git fetch Github >/dev/null 2>&1 || echo "Warning: Could not fetch from Github"

# ===== 6. Pull mode =====
if [ "$mode" = "pull" ]; then
    # Check for commits on Github missing on Vogsphere
    diffs=$(git log --oneline origin/$branch..Github/$branch)
    if [ -n "$diffs" ]; then
        echo "Commits on Github missing on Vogsphere:"
        echo "$diffs"
        echo "Merge Github into local branch? (y/n)"
        read answer
        if [ "$answer" = "y" ] || [ "$answer" = "Y" ]; then
            if git merge Github/$branch; then
                echo "Merge successful"
            else
                echo "Merge conflicts detected. Resolve manually."
                exit 1
            fi
        else
            echo "Skipped merge."
        fi
    else
        echo "No differences between Github and Vogsphere"
    fi
fi

# ===== 7. Push to remotes =====
# Push to origin (Vogsphere)
if git push origin "$branch"; then
    echo "Pushed to Vogsphere (origin)"
else
    echo "Warning: Push to Vogsphere failed. Probably not on Codam network"
fi

# Push to Github
if git push Github "$branch"; then
    echo "Pushed to Github"
else
    echo "Error: Push to Github failed"
fi
