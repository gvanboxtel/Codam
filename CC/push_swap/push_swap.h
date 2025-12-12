#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct node {
    int content;
	int rank;
    struct node *next;
    struct node *prev;
} stack;

void	swap_a(stack **list_a);
void	swap_b(stack **list_b);
void	ss(stack **list_a, stack **list_b);
void	push_a(stack **list_a, stack **list_b);
void	push_b(stack **list_a, stack **list_b);
void	rotate_a(stack **list_a);
void	rotate_b(stack **list_b);
void	rr(stack **list_a, stack **list_b);
void	reverse_rotate_a(stack **list_a);
void	reverse_rotate_b(stack **list_b);
void	rrr(stack **list_a, stack **list_b);
stack	*ft_lstnew_double(int content);
stack	*ft_lstlast_double(stack *lst);
void	ft_lstadd_back_double(stack **lst, stack *new);
void	ft_lstadd_front_double(stack **lst, stack *new);
int		ft_lstsize_double(stack *lst);

#endif
