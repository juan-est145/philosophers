NAME = philo

SRCS_PATH = philo/

SRCS = $(SRCS_PATH)main.c\
$(SRCS_PATH)parse_arguments.c\

OBJS = $(SRCS:.c=.o)

HEADER = $(SCRS_PATH)philo.h

COMPILER = $(CC)

CFLAGS =  -Wall -Werror -Wextra

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