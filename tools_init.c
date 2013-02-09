#include <stdio.h>
#include <stdlib.h>
#include "base.h"

char**	cut_num(char* str)
{
	char**	ptr;

	ptr = malloc(sizeof(char*) * 2);
	if (str_len(str, ptr))
		return (0);
	cut_incre(ptr, str);
	return (ptr);
}

void	cut_incre(char** ptr, char* str)
{
	int	count;
	int	count2;
	int	boucle;

	boucle = 0;
	count = 0;
	while (boucle != 2)
	{
		count2 = 0;
		while (str[count] != ' ')
		{
			if (str[count] == '\0')
				break;
			ptr[boucle][count2] = str[count];
			count = count + 1;
			count2 = count2 + 1;
		}
		if (str[count] == '\0')
			break;
		count = count + 1;
		boucle = boucle + 1;
	}
}

void	add_list_print(t_env* env, char** ptr)
{
	int	x;
	int	y;

	x = id_atoi(ptr[0]);
	y = id_atoi(ptr[1]);
	env->x = x;
	env->y = y;
	free(ptr[0]);
	free(ptr[1]);
}

int	count_num(char* str, int* pos)
{
	int	count;

	count = 0;
	while (str[*pos] >= '0' && str[*pos] <= '9'  && str[*pos] != '\0')
	{
		count = count + 1;
		*pos = *pos + 1;
	}
	return (count);
}
