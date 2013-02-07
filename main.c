#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int	main(void)
{
	t_point*	point;

	point = malloc(sizeof(t_point));
	if (point == 0)
		return (0);
	if (init(point))
	{
		while (point->next != 0)
		{
			run(point->env);
			point = point->next;
		}
	}
	return (0);
}
