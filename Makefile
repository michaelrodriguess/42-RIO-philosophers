SRCS			=	./sources/main.c \
					./sources/utils/ft_atoi.c \
					./sources/checks/ft_check_isdigit.c \
					./sources/routine/ft_init_rules.c \
					./sources/routine/ft_init_philos.c \
					./sources/routine/ft_create_philo.c \
					./sources/routine/ft_routine.c \
					./sources/routine/ft_take_forks.c \
					./sources/routine/ft_get_time.c

NAME			= philo
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -pthread 


$(NAME):	$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
