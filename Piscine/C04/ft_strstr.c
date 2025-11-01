#include <stdio.h>

char	ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (str[i] != '\0' && to_find[j] != '\0')
	{
		while (str[i] == to_find[j])
		{
			j++;
			i++;
		}
		if (to_find[j] == '\0')
		{
			printf("to find: %c", str[i-j]);
			return (str[i-j]);
		}
		else
			j = 0;		
		i++;
	}
	return (0);
}

int	main(void)
{
	char str[] = "khfglhkfghkjhfglkhjgabcijhsdfjhsdgs";
	char to_find[] = "\0";

	ft_strstr(str,to_find);
	return (0);
}