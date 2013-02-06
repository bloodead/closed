#ifndef _BASE_H_
#define _BASE_H_

typedef struct	s_env
{
	int		i;
	int		x;
	int		y;
	struct s_env*	next;
}		t_env;

int	init(t_env* env);
char*   id_getline(int fd);
int	id_atoi(char* str);

#endif
