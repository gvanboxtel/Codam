/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:38 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/08 16:25:18 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void swap_a(int **list_a)
{
	int i;
	int temp;

	i = 0;
	if ((!(*list_a)[i]) || ((*list_a)[i] && !(*list_a)[i +1]))
		return ;
	temp = (*list_a)[0];
	(*list_a)[0] = (*list_a)[1];
	(*list_a)[1] = temp;
}

void swap_b(int **list_b)
{
	int i;
	int temp;

	i = 0;
	if ((!(*list_b)[i]) || ((*list_b)[i] && !(*list_b)[i +1]))
		return ;
	temp = (*list_b)[0];
	(*list_b)[0] = (*list_b)[1];
	(*list_b)[1] = temp;
}

void ss(int **list_a, int **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
}