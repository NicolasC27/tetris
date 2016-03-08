/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Tue Mar  8 13:50:03 2016 Chevalier Nicolas
*/

#include	"tetris.h"
#include	"gnl.h"

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

int		initialize_files(t_tetris *game, t_list *list)
{
  t_parser	parser;
  struct dirent	*dirent;
  DIR		*dir;
  char		*s;
  int		fd;

  init_parser(&parser);
  if ((dir = opendir("./tetriminos/")) == NULL)
    exit_tetris("Error with opendir", -1);
  while (dirent = readdir(dir))
    if (dirent->d_type == DT_REG)
      {
	fd = open(concat("./tetriminos/", dirent->d_name), O_RDONLY);
	while ((s = get_next_line(fd)))
	  {
	    parser_tetriminos(&parser, game, list, s);
	    free(s);
	  }
     }
}

int		main(int argc, char **argv)
{
  t_tetris	game;
  t_tetriminos	shape;
  t_list	list;
  int		i;

  i = 0;
  if (argc > 1)
    options(argc, argv);
  init_list(&list);
  initialize_files(&game, &list);
  debug_display_list(list);
  initialize_game(&game);
  endwin();
  return (0);
}
