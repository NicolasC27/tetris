/*
** tetris.h for tetris.h in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:04:04 2016 Chevalier Nicolas
** Last update Thu Mar 17 15:21:43 2016 romain samuel
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
# include <dirent.h>
# include <string.h>
# include <time.h>
# include "lib.h"

/*
** Defines
*/
# define ROWS		20
# define COL		10
# define DEBUG		"*** DEBUG MODE ***\n"
# define HELP		"Usage: ./tetris [options]\nOptions:\n\
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

typedef struct		s_key
{
  char			*keyleft;
  char			*keyright;
  char			*keyturn;
  char			*keydrop;
  char			*keyquit;
  char			*keypause;
}			t_key;

typedef struct		s_scene
{
  int			rows;
  int			colums;
  int			points;
  int			level;
  int			timer;
  int			highscore;
  bool			boolnext;
  int			next;
  int			line;
}			t_scene;

typedef struct		s_tetriminos
{
  char			*name;
  int			**coord;
  bool			valid;
  int			width;
  int			height;
  int			color;
  int			**simple_coord;
  int			x_translation;
  int			y_translation;
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
  int			tmp_colums;
  int			**tmp;
  int			first;
  int			colums;
  int			color;
  int			line;
  int			star;
  int			star_line;
  int			count_height;
  bool			valid;
  char			*name;
}			t_parser;

typedef struct		s_compartment
{
  int			color;
  bool			filled;
}			t_compartment;

typedef struct		s_game
{
  t_tetriminos		current;
  t_tetriminos		*next;
  t_compartment		**scene;
  t_compartment		**tetrimino;
  int			direction;
  int			score;
  int			level;
  time_t		stime;
  time_t		save_time;
  int			max_next_height;
  int			max_next_width;
}			t_game;

typedef struct		s_tetris
{
  t_windows		*windows;
  t_scene		*scene;
  t_key			*keys;
  t_list		list;
  t_game		game;
  int		        **tmp;
  int			help;
  bool			debug;
}			t_tetris;

typedef struct		s_files
{
  struct dirent		*dirent;
  DIR			*dir;
  char			*s;
  char			*link;
  int			fd;
}			t_files;

typedef struct		s_flags
{
  char			*flag;
  int			(*redirection)(char *, t_tetris *, char **, int *);
}			t_flags;

/*
** delete_line.c
*/
int			del_line(t_tetris *s, int line);

/*
** utils_op.c
*/
char			*str(char *);
char			*get_arg_options(char **, int *);

/*
** options.c
*/
void			options(t_tetris *, int, char **);
int			mode(int);

/*
** copy_coord_tab.c
*/
int			**copy_coord_tab(t_tetriminos *tetri);

/*
** check_complete_line.c
*/
int			check_complete_line(t_tetris *s, t_compartment *line);
int			check_complete_lines(t_tetris *s);

/*
** clear_next.c
*/
void			clear_next(t_tetris *s);

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
void			push_back(t_list *, t_parser *);
void			push_front(t_list *, t_parser *);
void			init_parser(t_parser *);

/*
** display.c
*/
void			display_scene(t_tetris *);
void			display_score(t_tetris *);
void			display_name(t_tetris *game);
void			display_next(t_tetris *game);

/*
** display_matrix.c
*/
void			display_compartment(WINDOW *win,
					    t_compartment **matrix,
					    int i,
					    int j);
void			display_matrix(t_tetris *s, t_compartment **matrix);

/*
** fill_matrix_with_tetrimino.c
*/
int			fill_matrix_with_tetrimino(t_tetris *s);

/*
** display_termitrino.c
*/
void			display_tetrimino(WINDOW *win, t_tetriminos tetri);

/*
** move_tetrimino.c
*/
int			move_tetrimino(t_tetris *s, int x, int y);

/*
** game.c
*/
int			create_compartments(t_tetris *s);
int			game(t_tetris *s);

/*
** get_max_size.c
*/
int			get_max_termitrino_width(t_tetriminos *root);
int			get_max_termitrino_height(t_tetriminos *root);

/*
** my_puterr.c
*/
int			my_puterr(char *str);

/*
** get_next_tetrimino.c
*/
void			get_next_tetrimino(t_tetris *s);
int			get_current_tetrimino(t_tetris *s);

/*
** init_tetrimino_pos.c
*/
int			init_tetrimino_pos(t_tetris *s);

/*
** initialize_game.c
*/
void			initialize_game(t_tetris *game);

/*
** parser.c
*/
int			parser_tetriminos(t_parser *, t_list *, char *);

/*
** free.c
*/
void			my_free(t_tetris *, t_list *);

/*
** main.c
*/
int			initialize_ncurses();
void			exit_tetris(char *, int);

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
** debug.c
*/
void			mode_debug(t_tetris *, t_list *);

/*
** rotations.c
*/
int			rotate_tetrimino(t_tetriminos tetri);

#endif /* !TETRIS_H_ */
