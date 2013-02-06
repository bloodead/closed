#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int	count_num(char* str, int* pos)
{
	int	count;

	count = 0;
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		count = count + 1;
		*pos = *pos + 1;
	}
	return (count);
}
