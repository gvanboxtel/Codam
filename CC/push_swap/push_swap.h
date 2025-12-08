#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include "ft_printf.h"
# include "libft.h"

int *swap_a(int *list_a);
void swap_b(int **list_b);
void ss(int **list_a, int **list_b);
void push_a(int **list_a, int **list_b, int counter);
void push_b(int **list_a, int **list_b, int counter);



#endif