CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = corewar
SRCS = srcs/main.c \
		srcs/parse_arguments.c \
		srcs/ranking_players.c \
		srcs/game.c \
		srcs/operations/live.c \
		srcs/operations/ld.c \
		srcs/operations/st.c \
		srcs/operations/sti.c \
		srcs/operations/and.c \
		srcs/operations/zjmp.c \
		srcs/operations/fork.c \
		srcs/operations/lfork.c \
		srcs/operations/aff.c \
		srcs/operations/add.c \
		srcs/operations/xor.c \
		srcs/operations/ldi.c \
		srcs/operations/sub.c \
		srcs/operations/lldi.c \
		srcs/operations/or.c \
		srcs/operations/lld.c \
		srcs/extra.c\
		srcs/checks.c \
		srcs/parse_codage.c \
		srcs/help_for_instr.c \
		srcs/help_for_process.c \
		srcs/help_for_error.c \
		srcs/op.c \
		srcs/parse_flags.c \
		$(addprefix srcs/visualizer/, run_visualizer.c key_hook.c init_ncurses.c \
			draw_info.c draw_map.c show_end_game.c show_end_game_2.c )

OBJ = $(SRCS:.c=.o)
LIBDIR = libft
LIB = libftprintf.a
HEAD = corewar.h op.h visualizer.h

all: $(NAME)

$(NAME):$(OBJ)
	make -C $(LIBDIR)
	make -C asm_dir
	cp asm_dir/asm .
	$(CC) $(CFLAGS) $^ $(LIBDIR)/$(LIB) -o $@ -lncurses

%.o:%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	make clean -C asm_dir
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBDIR)
	make fclean -C asm_dir
	rm -f asm
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
