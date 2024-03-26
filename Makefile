NAME = philo

SRCS_PATH = philo

SRCS = $(SCRS_PATH)/main.c

OBJS = $(SRCS:.c=.o)

HEADER = $(SCRS_PATH)/philo.h

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