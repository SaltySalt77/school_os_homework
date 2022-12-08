NAME1 = program01
NAME2 = program02
NAME3 = init_nbr
CC = cc
INC_LINK = -I./incs

SRCS_NAME1 = program01.c init_add_share_memory.c semaphore.c
SRCS_NAME2 = program02.c init_add_share_memory.c semaphore.c
SRCS_NAME3 = init_nbr.c init_add_share_memory.c


SRCS_PATH = ./srcs
SRCS1 = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME1))
SRCS2 = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME2))
SRCS3 = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME3))

OBJS_NAME1 = $(SRCS_NAME1:.c=.o)
OBJS_NAME2 = $(SRCS_NAME2:.c=.o)
OBJS_NAME3 = $(SRCS_NAME3:.c=.o)
OBJS_PATH = ./objs
OBJS1 = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME1))
OBJS2 = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME2))
OBJS3 = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME3))

all : $(NAME1) $(NAME2) $(NAME3)

$(NAME1) : $(OBJS1)
	$(CC) -o $(NAME1) $(OBJS1)

$(NAME2) : $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2)

$(NAME3) : $(OBJS3)
	$(CC) -o $(NAME3) $(OBJS3)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) -c $< -o $@

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	rm -rf $(NAME3)
re :
	$(MAKE) fclean
	$(MAKE) all


.PHONY: all clean fclean