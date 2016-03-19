/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Sat Mar 19 00:58:07 2016 Chevalier Nicolas
*/

#include	<sys/types.h>
#include	<fcntl.h>
#include	<termcap.h>
#include	"tetris.h"
#include	"gnl.h"

/*
** Function which initialize terminal in ncurses
*/
int		initialize_ncurses()
{
  int		i;

  i = 0;
  initscr();
  start_color();
  while (i < COLORS && i < COLOR_PAIRS)
    {
      init_pair(i, COLOR_BLACK, i);
      i++;
      }
  cbreak();
  halfdelay(2);
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  timeout(0);
  return (0);
}

void		initialize_parser(t_files *file, t_parser *parser, t_list *list)
{
  file->fd = open((file->link = concat("./tetriminos/", file->dirent->d_name)),
		 O_RDONLY);
  parser->name = separate_name(file->dirent->d_name);
  count_height(file, parser);
  parser->valid = 1;
  while ((file->s = get_next_line(file->fd)))
    {
      if (parser->valid == 1)
	parser_tetriminos(parser, list, file->s);
      free(file->s);
    }
}

/*
** Get all tetriminos from dir tetriminos
*/
int		initialize_files(t_list *list)
{
  int		count;
  t_files	file;
  t_parser	parser;

  count = 0;
  init_parser(&parser);
  if ((file.dir = opendir("./tetriminos/")) == NULL)
    exit_tetris("Error with opendir", -1);
  while ((file.dirent = readdir(file.dir)))
    {
      if (file.dirent->d_type == DT_REG)
	{
	  initialize_parser(&file, &parser, list);
	  free(file.link);
	  close(file.fd);
	  count++;
	}
    }
  closedir(file.dir);
  return ((count != 0) ? (1) : (0));
}

void		exit_tetris(char *str, int constant)
{
  my_putstr(str);
  exit ((constant == -1) ? (-1) : (0));
}

int		main(int argc, char **argv, char **env)
{
  t_tetris	game;
  t_list	list;
  bool		files;

  files = true;
  initialize_struct(&game);
  initialize_value(&game, argv[0]);
  if (argc > 1)
    options(&game, argc, argv);
  init_list(&list);
  if (!(initialize_files(&list)))
      files = false;
  if (game.debug == true)
    mode_debug(&game, list);
  debug_display_list(list);
  game.list = list;
  if (files == true)
    initialize_game(&game);
  my_free(&game, &list);
  endwin();
  return (0);
}
