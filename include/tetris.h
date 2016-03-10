/*
** tetris.h for tetris.h in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:04:04 2016 Chevalier Nicolas
// Last update Thu Mar 10 20:04:43 2016 Chevalier Nicolas
*/

#ifndef TETRIS_H_
# define TETRIS_H_

/*
** Includes
*/
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include <curses.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>
# include <string.h>
# include "lib.h"

/*
** Defines
*/
# define ROWS 20
# define COL  10
# define HELP	"Usage: ./tetris [options]\nOptions:\n\
--help			Display this help\n\
-l --level={num}	Start Tetris at level num\n\
-kl --key-left={K}	Move tetrimino on LEFT with key K\n\
-kr --key-right={K}	Move tetrimino on RIGHT with key K\n\
-kt --key-turn={K}	Turn tetrimino with key K\n\
-kd --key-drop={K}	Set default DROP on key K\n\
-kq --key-quit={K}	Quit program when press key K\n\
-kp --key-pause={K}	Pause and restart game when press key K\n\
--map-size={row,col}	Set game size at row, col\n\
-w --without-next	Hide next tetrimino\n\
-d --debug		Debug mode\n"

typedef struct		s_windows
{
  WINDOW		*scene;
  WINDOW		*score;
  WINDOW		*next;
  WINDOW		*name;
}			t_windows;

typedef struct		s_keys
{
  char			*key_left;
  char			*key_right;
  char			*key_turn;
  char			*key_drop;
  char			*key_quit;
  char			*key_pause;
}			t_key;

typedef struct		s_scene
{
  int			rows;
  int			colums;
  int			points;
  int			level;
  int			timer;
  bool			boolnext;
  int			next;
}			t_scene;

typedef struct		s_tetriminos
{
  int			**coord;
  int			nb;
  struct s_tetriminos	*next;
  struct s_tetriminos	*prev;
}			t_tetriminos;

typedef struct		s_list
{
  t_tetriminos		*first;
  t_tetriminos		*last;
}		        t_list;

typedef struct		s_parser
{
  int			**tmp;
  int			tmp_colums;
  int			first;
  int			colums;
  int			line;
  int			star;
}			t_parser;

typedef struct		s_tetris
{
  t_windows		*windows;
  t_scene		*scene;
  t_tetriminos		*shape;
  t_key			*keys;
  t_list		*list;
  int		        **tmp;
  int			help;
  bool			debug;
}			t_tetris;

typedef struct		s_flags
{
  char			*flag;
  int			(*redirection)(char *, t_tetris *, char **, int *);
}			t_flags;

/*
** options
*/
int			is_help(char *, t_tetris *, char **, int *);
int			is_level(char *, t_tetris *, char **, int *);
int			is_keyleft(char *, t_tetris *, char **, int *);
int			is_keyright(char *, t_tetris *, char **, int *);
int			is_keyturn(char *, t_tetris *, char **, int *);
int			is_keydrop(char *, t_tetris *, char **, int *);
int			is_keyquit(char *, t_tetris *, char **, int *);
int			is_keypause(char *, t_tetris *, char **, int *);
int			is_mapsize(char *, t_tetris *, char **, int *);
int			is_next(char *, t_tetris *, char **, int *);
int			is_debug(char *, t_tetris *, char **, int *);

/*
** Options.c
*/
void			options(t_tetris *, int, char **);

/*
** debug.c
*/
void			debug_display_list(t_list );

/*
** init.c
*/
void			initialize_value(t_tetris *);
t_windows		*initialize_windows(t_tetris *);
t_scene			*initialize_scene(t_tetris *);
void			initialize_struct(t_tetris *);

/*
** list.c
*/
void			init_list(t_list *);
void			push_back(t_list *,  int **);
void			push_front(t_list *, int **);
void			init_parser(t_parser *);
/*
** display.c
*/
void			display_scene(t_tetris *);
void			display_score(t_tetris *);

/*
** parser.c
*/
int			parser_tetriminos(t_parser *, t_tetris *, t_list *, char *);

/*
** free.c
*/
void			my_free(t_list *);

/*
** main.c
*/
int			initialize_ncurses();
void			exit_tetris(char *, int);

#endif /* !TETRIS_H_ */
