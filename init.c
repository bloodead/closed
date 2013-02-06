#include <stdio.h>
#include "base.h"

t_env*	init_list(int num, t_env* env)
{
	t_env*	pos;
	int	count;

	count = 0;
	pos = env;
	while (count != num)
	{
		pos->i = count;
		pos->next = malloc(sizeof(env_t));
		count = count + 1;
	}
	return (env);
}

int	init(t_env* env)
{
	char*	str;
	int	num;

	str = id_getline(0);
	num = id_atoi(str);
	if (num == -1)
	{
		printf("Mauvaise Saisie\n");
		return (0);
	}
	env = init_list(num, env);
}
