/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:44 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/08 17:07:00 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void push_a(int **list_a, int **list_b, int counter)
{
	int i;
	int prev;
	int current;

	i = 0;
	if ((*list_b) == 0)
		return ;
	prev = (*list_a)[i];
	(*list_a)[i] = (*list_b)[i];
	(*list_b)[i] = 0;
	i++;
	while (i < counter)
	{
		current = (*list_a)[i];
		(*list_a)[i] = prev;
		prev = current;
		i++;
	}


}

void push_b(int **list_a, int **list_b, int counter)
{
	int i;
	int prev;
	int current;

	i = 0;
	if ((*list_a) == 0)
		return ;
	prev = (*list_b)[i];
	(*list_b)[i] = (*list_a)[i];
	(*list_a)[i] = 0;
	i++;
	while (i < counter)
	{
		current = (*list_b)[i];
		(*list_b)[i] = prev;
		prev = current;
		i++;
	}
}