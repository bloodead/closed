NAME	=	id_cp
SRCS	=	main.c		\
		id_getline.c	\
		id_atoi.c	\
		init.c		\
		tools_init.c	\
		run.c

OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -W -Werror
LDFLAGS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all

debug: CFLAGS += -D___DEBUG
debug: rebuild
