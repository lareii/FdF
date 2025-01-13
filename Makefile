NAME		= fdf
NAME_BONUS	= fdf_bonus

INC_DIR		= inc
LIB_DIR		= lib
SRC_DIR		= src
BUILD_DIR	= build

LIBFT_DIR	= $(LIB_DIR)/libft
MLX_DIR		= $(LIB_DIR)/minilibx-linux
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

VPATH		= src:src/map:src/render:src/window
SRCS		= fdf.c utils.c \
			init_map.c parse_map.c read_map.c \
			init_renderer.c render_map.c render_utils.c transformations.c \
			init_win.c win_hooks.c win_utils.c
BONUS_SRCS	= $(SRCS:.c=_bonus.c)
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(BUILD_DIR)/,$(BONUS_SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		= -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS		= -lm -lmlx -lft -lX11 -lXext
RM			= rm -rf

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re