##
## Makefile for tetris in /home/cheval_8/rendu/PSU_2015_tetris
##
## Made by Chevalier Nicolas
## Login   <cheval_8@epitech.net>
##
## Started on  Wed Feb 24 16:02:04 2016 Chevalier Nicolas
## Last update Tue Mar 15 20:21:48 2016 romain samuel
##


NAME		=	tetris

SRC		=	main.c \
			check_complete_line.c \
			init.c \
			delete_line.c \
			display.c \
			display_matrix.c \
			display_tetrimino.c \
			game.c \
			fill_matrix_with_tetrimino.c \
			get_max_size.c \
			get_next_tetrimino.c \
			initialize_game.c \
			init_tetrimino_pos.c \
			move_tetrimino.c \
			parser.c \
			debug.c \
			list.c \
			free.c \
			options.c \
			options_remaining.c \
			options_key.c \
			options_utils.c \
			debug_code.c \
			rotation.c

MOD		=	$(addprefix src/, $(SRC:.c=.o))

LIB		=	-Llib/
LIB		+=	-Ilib/include -Llib/ -lmyutils

LIBMYUTILS_MAKE	=	make -C lib/
LIBMYUTILS	=	lib/libmyutils.a

CFLAGS		=	-W -Wall -Werror -Wextra
CFLAGS		+=	-Wno-overlength-strings
CFLAGS		+=	-Iinclude/
CFLAGS		+=	-D_BSD_SOURCE -D_POSIX_SOURCE
CFLAGS		+=	$(LIB)

LDFLAGS		=	$(LIB)

all:		$(LIBMYUTILS) $(NAME)

$(NAME):	$(MOD)
		gcc $(MOD) -o $(NAME) $(LDFLAGS) -lncurses

$(LIBMYUTILS):
	 	$(LIBMYUTILS_MAKE)

clean		:
		 rm -rf $(MOD)
		 $(LIBMYUTILS_MAKE) clean

fclean		: clean
		  rm -rf $(NAME)
		  $(LIBMYUTILS_MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re
