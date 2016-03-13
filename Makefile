##
## Makefile for tetris in /home/cheval_8/rendu/PSU_2015_tetris
## 
## Made by Chevalier Nicolas
## Login   <cheval_8@epitech.net>
## 
## Started on  Wed Feb 24 16:02:04 2016 Chevalier Nicolas
## Last update Sat Mar 12 14:33:45 2016 Chevalier Nicolas
##


NAME		= tetris

SRC		= main.c \
		  init.c \
		  display.c \
		  parser.c \
		  debug.c \
		  list.c \
		  free.c \
		  options.c \
		  options_remaining.c \
		  options_key.c \
		  options_utils.c

MOD		= $(addprefix src/, $(SRC:.c=.o))

LIB		= -Llib/
LIB		+= -Ilib/include -Llib/ -lmyutils

LIBMYUTILS_MAKE	= make -C lib/
LIBMYUTILS	= lib/libmyutils.a

# CFLAGS		= -W -Wall -Werror -Wextra
# CFLAGS		+= -ansi -pedantic
CFLAGS		+= -Iinclude/
CFLAGS		+= -D_BSD_SOURCE -D_POSIX_SOURCE
CFLAGS		+= $(LIB)

LDFLAGS		= $(LIB)

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
