#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int	str_len(char* str, char** ptr)
{
	int	pos;
	int	count;

	pos = 0;
	count = count_num(str, &pos);
	ptr[0] = malloc(sizeof(char) * count + 1);
	if (ptr[0] == 0)
		return (1);
	count = 0;
	if (str[pos] < '0' || str[pos] > '9')
	{
		while (str[pos] < '0' || str[pos] > '9')
			pos = pos + 1;
	}
	else
		return (1);
	count = count_num(str, &pos);
	ptr[1] = malloc(sizeof(char) * count + 1);
	if(ptr[1] == 0)
	{
		free (ptr[0]);
		return (1);
	}
	return (0);
}

char**	cut_num(char* str)
{
	char** ptr;

	ptr = malloc(sizeof(char*) * 2);
	if (str_len(str, ptr))
		return (0);
	cut_incre(ptr, str);
	return (ptr);
}

int	init_coord(int num, t_env* env)
{
	char*	str;
	char**	ptr;

	while (num != 0)
	{
		str = id_getline(0);
		ptr = cut_num(str);
		add_list_print(env, ptr);
		env = env->next;
		num = num - 1;
	}
	return (0);
}

int	init_list(int num, t_env* env)
{
	t_env*	pos;
	int	count;

	count = 1;
	pos = env;
	while (count != num )
	{
		pos->i = count;
		pos->next = malloc(sizeof(t_env));
		if (pos->next == 0)
			return (0);
		pos = pos->next;
		count = count + 1;
	}
	pos->i = count;
	return (count + 1);
}

int	init(t_point* point)
{
	char*	str;
	int	num;

	num = 1;
	while (1)
	{
		str = id_getline(0);
		num = id_atoi(str);
		if (num < 0)
		{
			printf("Mauvaise Saisie\n");
			return (0);
		}
		if (str[0] == '0')
			return (1);
		point->env = malloc(sizeof(t_env));
		if (init_list(num, point->env) != 0)
		{
			init_coord(num, point->env);
			point->next = malloc(sizeof(t_point));
			point = point->next;
			point->next = 0;
		}
		printf("cordonnee pour ce point terminer\n");
	}
	return (1);
}
