#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "base.h"


int	count_point_func(t_env* env)
{
	int	count;

	count = 0;
	while (env != 0)
	{
		env = env->next;
		count = count + 1;
	}

	return count;
}

void	incre_tab(t_env* tab, t_env* env)
{
	int	count;

	count = 0;
	while (env != 0)
	{
		tab[count].i = env->i;
		tab[count].x = env->x;
		tab[count].y = env->y;
		env = env->next;
		count = count + 1;
	}
}

void	calcul_point(t_env point1, t_env point2, double* resultf)
{
	double	result;
	int	result1;

	result1 = ((point1.x - point2.x) * (point1.x - point2.x)) + ((point1.y - point2.y) * (point1.y - point2.y));
	result = (double)result1;
	result = sqrt(result);
	if (result < *resultf || *resultf == 0)
		*resultf = result;
	
}

void	run(t_env* env)
{
	int	count_point;
	int	point1;
	int	point2;
	struct	s_env*	tab;
	double	resultf;

	point1 = 0;
	point2 = 1;
	resultf = 0;
	count_point = count_point_func(env);
	tab = malloc(count_point * sizeof(struct s_env));
	incre_tab(tab,env);

	while (point1 != count_point )
	{

		while (point2 != count_point)
		{
			calcul_point(tab[point1],tab[point2], &resultf);
			point2 = point2 + 1;
		}
		point1 = point1 + 1;
		point2 = point1 + 1;
	}
	printf("plus petite distance est %f\n",resultf);
		free(tab);
}
