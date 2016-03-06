/*
** tetris.h for tetris.h in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:04:04 2016 Chevalier Nicolas
// Last update Sat Mar  5 18:38:17 2016 Chevalier Nicolas
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
# define ROWS	40
# define COL	20

typedef struct		s_windows
{
  WINDOW		*scene;
  WINDOW		*score;
  WINDOW		*next;
  WINDOW		*name;
}			t_windows;

typedef struct		s_keys
{
  int			key_left;
  int			key_right;
  int			key_turn;
  int			key_drop;
  int			key_quit;
  int			key_pause;
}			t_key;

typedef struct		s_scene
{
  int			rows;
  int			colums;
  int			points;
  int			level;
  int			timer;
  bool			next_w;
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
  int			debug;
}			t_tetris;

/*
** debug.c
*/
void			debug_display_list(t_list );

/*
** init.c
*/
int			initialize_ncurses();
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

#endif /* !TETRIS_H_ */
