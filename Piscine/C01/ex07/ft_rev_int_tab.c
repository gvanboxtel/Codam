/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:37:40 by marvin            #+#    #+#             */
/*   Updated: 2025/08/06 09:37:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	
	int s = size-1;
	int temp[size];
	int i = 0;
	
	while (i <= s)
	{
		temp[i] = tab[(s) - i];
		i++;
	}
	
	i = 0;
	printf("reversed array: ");
	while (i <= s)
	{
		tab[i] = temp[i];
		
		printf("%d ", tab[i]);
		i++;
	}
}

int	main(void)
{
	int myNumbers[] = {25,50,75,100};
	int *ptr = myNumbers;
	int size;

	size = 4;
	ft_rev_int_tab(ptr, size);
	return (0);

}