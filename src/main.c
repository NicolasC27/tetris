/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Mon Feb 29 11:57:55 2016 Chevalier Nicolas
*/

#include	"tetris.h"


void		exit_tetris(char *str, int constant)
{
  my_putstr(str);
  exit ((constant == -1) ? (-1) : (0));
}

void		panel_windows(t_tetris *game)
{
  game->scene->rows = ROWS;
  game->scene->colums = COL;
  game->scene->level = 0;
  game->scene->points = 0;
}

void		initialize_game(t_tetris *game)
{
  initialize_ncurses();
  initialize_struct(game);
  panel_windows(game);
  game->windows->scene = newwin(game->scene->rows,
				game->scene->colums + 2, 0, 30);
  game->windows->score = newwin(15, 25, 10, 0);

  display_scene(game);
  display_score(game);
  while (42);
}

void		initialize_files(t_tetris *game)
{
  DIR		*dir;
  int		fd;
  struct dirent	*dirent;
  char		*s;

  if ((dir = opendir("./tetriminos/")) == NULL)
    exit_tetris("Error with opendir", -1);
  while (dirent = readdir(dir))
    if (dirent->d_type == DT_REG)
      \{
	fd = open(concat("./tetriminos/", dirent->d_name), O_RDONLY);
	while ((s = get_next_line(fd)))
	  {
	    my_putstr(s);
	    my_putchar('\n');
	  }
	my_putstr(dirent->d_name);
	my_putchar('\n');
      }
}

int		main()
{
  t_tetris	game;

  initialize_files(&game);
  initialize_game(&game);
  endwin();
  return (0);
}
