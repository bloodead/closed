#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int	main(void)
{
	t_env*	env;

	env = malloc(sizeof(t_env));
	if (env == 0)
		return (0);
	init(env);
	(void) env;
	return (0);
}
