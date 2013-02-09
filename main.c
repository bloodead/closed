#include <stdio.h>
#include <stdlib.h>
#include "base.h"

void	free_all(t_point* head)
{
	t_env*	tmp;
	t_point*	tmp_p;

	while (head->next != 0)
	{
		while (head->env != 0)
		{
			tmp = head->env->next;
			free(head->env);
			head->env = tmp;
		}
		tmp_p = head->next;
		free(head);
		head = tmp_p;
	}
	free(head);
}

int	main(void)
{
	t_point*	point;
	t_point*	head;

	point = malloc(sizeof(t_point));
	head = point;
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
	free_all(head);
	return (0);
}
