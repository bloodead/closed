#include <stdio.h>

int	len_number(char* str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] < '0' || str[count] > '9')
			return (0);
		count = count + 1;
	}
	return (count);
}

int	generate_int(char str, int num, int count)
{
	num = num + (str - 48);
	if (count > 1)
		num = num * 10;
	return (num);
}

int	id_atoi(char* str)
{
	int	ret;
	int	num;
	int	count;
	int	count2;

	ret = 0;
	count2 = 0;
	count = len_number(str);
	if (count == 0)
		return (-1);
	num = count;
	while (count2 != num)
	{
		ret = generate_int(str[count2], ret, count);
		count2 = count2 + 1;
		count = count - 1;
	}
	return (ret);
}
