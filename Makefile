NAME = push_swap
DEBUG_NAME = debug.out

SRC_DIR = src/mandatory
OBJ_DIR = obj
INC_DIR = includes
DEP_DIR = deps
LIB_DIR = libs

LIBFT_DIR = $(DEP_DIR)/libft
LIBFT = $(LIB_DIR)/libft.a

SRC_NAMES =	main.c				\
			input.c				\
			sort.c				\
			utils/arr_free.c	\
			utils/arr_len.c		\
			utils/err.c			\
			utils/fallback.c	\
			utils/get_minix.c	\
			utils/wrap_ix.c		\
			stack/is_sorted.c	\
			stack/moves/push.c	\
			stack/moves/r_rot.c	\
			stack/moves/rot.c	\
			stack/moves/swap.c
			

CC = cc
CC_EXT_SRCS = -L$(LIB_DIR) $(LIBFT) -lft
FLAGS = -I$(INC_DIR) -Ofast #-Wall -Wextra -Werror
DEBUG_FLAGS = -I$(INC_DIR) -g -fsanitize=address,undefined,integer

################################################################################

OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)/mandatory/%.o)
OBJS_DEBUG = $(SRC_NAMES:%.c=$(OBJ_DIR)/debug/%.o)

.PHONY: all debug \
clean .clean fclean re

################################################################################

all: $(NAME)

$(OBJ_DIR)/debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(DEBUG_FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

$(OBJ_DIR)/mandatory/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR) bonus
	@mkdir -p $(LIB_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)

################################################################################

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(CC_EXT_SRCS) -o $(NAME)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

################################################################################

$(DEBUG_NAME): $(LIBFT) $(OBJS_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(CC_EXT_SRCS) $(OBJS_DEBUG) -o $(DEBUG_NAME)
	@echo "$(GREY)$(NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

debug: $(DEBUG_NAME)

################################################################################

.clean:
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR)"
	@rm -rf $(OBJ_DIR) .bonus .debug_bonus

clean: .clean
	@make --no-print-directory -C $(LIBFT_DIR) clean
	
fclean: .clean
	@make --no-print-directory -C $(LIBFT_DIR) fclean 
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME), $(DEBUG_NAME), and $(LIB_DIR)"
	@rm -rf $(NAME) $(DEBUG_NAME) $(LIB_DIR)

re: fclean all

################################################################################

GREEN = \033[38;5;84m
RED = \033[38;5;9m
BLUE = \033[38;5;45m
#PURPLE = \033[38;5;63m
PINK = \033[38;5;207m
PURPLE = \033[38;5;165m
BLACK = \033[38;5;0m
BG_WHITE = \033[48;5;15m
BG_GREEN = \033[48;5;84m
BG_RED = \033[48;5;9m
BG_PURPLE = \033[48;5;54m
GREY = \033[38;5;8m
BOLD = \033[1m
DEFAULT = \033[0m
CHECKMARK = \xE2\x9C\x93
