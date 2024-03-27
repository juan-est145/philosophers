NAME = philo

SRCS_PATH = src/

SRCS = \
$(SRCS_PATH)main.c\
$(SRCS_PATH)parse_arguments.c\
$(SRCS_PATH)error_msgs.c\
$(SRCS_PATH)prepare_philo.c\
$(SRCS_PATH)time_func.c\
$(SRCS_PATH)threads.c\

OBJS = $(SRCS:.c=.o)

HEADER = $(SRCS_PATH)philo.h

COMPILER = $(CC)

CFLAGS = -Wall -Wextra -Werror -pthread

EXEC-NAME-FLAG = -o

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(COMPILER) $(CFLAGS) $(OBJS) $(EXEC-NAME-FLAG) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

debug: CFLAGS += -g
debug: $(NAME)