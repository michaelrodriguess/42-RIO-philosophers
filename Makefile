SRCS			=	./sources/main.c \
					./sources/init_values/ft_init_rules.c \
					./sources/init_values/ft_init_philos.c \
					./sources/init_values/ft_init_mutex.c \
					./sources/init_values/ft_init_forks.c \
					./sources/utils/ft_atoi.c \
					./sources/utils/ft_get_time.c	\
					./sources/utils/ft_smart_sleep.c	\
					./sources/utils/ft_create_philo.c \
					./sources/utils/ft_monitoring_isdead.c \
					./sources/utils/ft_free_trash.c \
					./sources/checks/ft_check_isdigit.c \
					./sources/checks/ft_check_isfull.c \
					./sources/checks/ft_check_allfull.c \
					./sources/routine/ft_routine.c \
					./sources/routine/ft_take_forks.c \
					./sources/routine/ft_drop_forks.c 

NAME			= philo
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -pthread 


$(NAME):	$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
