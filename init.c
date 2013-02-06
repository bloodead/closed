#include <stdio.h>
#include <stdlib.h>
#include "base.h"

char**	str_len(char* str, char** ptr)
{
	int*	pos;
	int	count;

	*pos = 0;
	count = count_num(str, pos);
	ptr[0] = malloc(sizeof(char) * count + 1);
	if (ptr[0] == 0)
		return;
	count = 0;
	while (str[*pos] < '0' || str[*pos] > '9')
		*pos = *pos + 1;
	count = count_num(str, pos);
	ptr[1] = malloc(sizeof(char) * count + 1);
	if(ptr[1] == 0)
	{
		free (ptr[0]);
		return;
	}
	return (ptr);
}

char**	cut_num(char* str)
{
	char** ptr;

	ptr = malloc(sizeof(char*) * 2);
	ptr = str_len(str, ptr);
	
}

int	init_coord(int num, t_env*)
{
	char* str;

	while (num != 0)
	{
		str = id_getline(0);
		cut_num(str);
		num = num - 1;
	}
}

int	init_list(int num, t_env* env)
{
	t_env*	pos;
	int	count;

	count = 0;
	pos = env;
	while (count != num - 1)
	{
		pos->i = count;
		pos->next = malloc(sizeof(t_env));
		if (pos->next == 0)
			return (0);
		count = count + 1;
	}
	return (count);
}

int	init(t_env* env)
{
	char*	str;
	int	num;

	num = 1;
	while (1)
	{
		str = id_getline(0);
		num = id_atoi(str);
		printf("ret %d\n", num);
		if (num == -1)
		{
			printf("Mauvaise Saisie\n");
			return (0);
		}
		if (str[0] == '0')
			return (0);
		env = init_list(num, env);
		if (env != 0)
			init_coord(num, env);
	}
	return (1);
}
