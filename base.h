#ifndef _BASE_H_
#define _BASE_H_

typedef struct	s_point
{
	struct s_env*	env;
	struct s_point*	next;
}		t_point;

typedef struct	s_env
{
	int		i;
	int		x;
	int		y;
	struct s_env*	next;
}		t_env;

int	str_len(char* str, char** ptr);

char**	cut_num(char* str);
void	cut_incre(char** ptr, char* str);
void	add_list_print(t_env* env, char** ptr);
int	init(t_point* point);
char*	id_getline(int fd);
int	id_atoi(char* str);
int	count_num(char* str, int* pos);
void	run(t_env* env);

#endif
