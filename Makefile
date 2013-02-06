NAME	=	id_cp
SRCS	=	main.c		\
		id_getline.c	\
		id_atoi.c	\
		init.c

OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -W -Werror
LDFLAGS	=

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all

debug: CFLAGS += -D___DEBUG -g3
debug: rebuild
