/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Sun Mar 20 18:03:10 2016 Chevalier Nicolas
*/

#include	<sys/stat.h>
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

void		initialize_parser(t_files *file, t_parser *parser, t_list *list,
				  t_tetris *game)
{
  struct stat	buff;

  file->fd = open((file->link = concat("./tetriminos/", file->dirent->d_name)),
		  O_RDONLY);
  parser->name = separate_name(file->dirent->d_name);
  count_height(file, parser);
  parser->valid = 1;
  lstat(file->link, &buff);
  if (buff.st_size != 0)
    while ((file->s = get_next_line(file->fd)))
      {
	if (parser->valid == 1)
	  parser_tetriminos(parser, list, file->s, game);
	free(file->s);
      }
  else
    {
      file->s = "invalid";
      parser_tetriminos(parser, list, file->s, game);
    }
}

/*
** Get all tetriminos from dir tetriminos
*/
int		initialize_files(t_list *list, t_tetris *game)
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
	  initialize_parser(&file, &parser, list, game);
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
  my_puterr(str);
  exit ((constant == -1) ? (-1) : (0));
}

int		check_one_valid(t_list *list)
{
  t_tetriminos	*tmp;

  tmp = list->first;
  while (tmp)
    {
      if (tmp->valid == true)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
int		main(int argc, char **argv, char **env)
{
  t_tetris	game;
  t_list	list;
  bool		files;

  files = true;
  initialize_struct(&game);
  initialize_value(&game, argv[0], env);
  if (argc > 1)
    options(&game, argc, argv);
  init_list(&list);
  if (!(initialize_files(&list, &game)))
    files = false;
  if (game.debug == true)
    mode_debug(&game, list);
  debug_display_list(list);
  game.list = list;
  if (files == true)
    {
      if ((game.scene->rows + 2 > (tgetnum("lines")))
  	  || (game.scene->colums + 43 > (tgetnum("cols"))))
  	my_puterr("Terminal too small\n");
      else if ((check_one_valid(&list)) == 1)
	initialize_game(&game);
    }
  my_free(&game, &list);
  endwin();
  return (0);
}
