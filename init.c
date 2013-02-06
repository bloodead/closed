#include <stdio.h>
#include <stdlib.h>
#include "base.h"

char**	str_len(char* str, char** ptr)
{
	int	pos;
	int	count;

	pos = 0;
	count = count_num(str, &pos);
	ptr[0] = malloc(sizeof(char) * count + 1);
	if (ptr[0] == 0)
		return 0;
	count = 0;
	while (str[pos] < '0' || str[pos] > '9')
		pos = pos + 1;
	count = count_num(str, &pos);
	ptr[1] = malloc(sizeof(char) * count + 1);
	if(ptr[1] == 0)
	{
		free (ptr[0]);
		return 0;
	}
	return (ptr);
}

void	add_list_print(t_env* env, char** ptr)
{
	int	x;
	int	y;

	x = id_atoi(ptr[0]);
	y = id_atoi(ptr[1]);
	env->x = x;
	env->y = y;
	printf("passe ici\n");


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

char**	cut_num(char* str)
{
	char** ptr;

	ptr = malloc(sizeof(char*) * 2);
	ptr = str_len(str, ptr);
	cut_incre(ptr,str);
	printf("%s %s\n",ptr[0],ptr[1]);

	return ptr;
	
}

int	init_coord(int num, t_env* env)
{
	char*	str;
	char**	ptr;

	while (num != 0)
	{
		str = id_getline(0);
		ptr= cut_num(str);
		add_list_print(env,ptr);
		num = num - 1;
	}

	return 0;
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
		init_list(num, env);
		if (env != 0)
			init_coord(num, env);
	}
	return (1);
}
