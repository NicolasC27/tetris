/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Thu Mar 17 15:23:02 2016 romain samuel
*/

#include	<sys/types.h>
#include	<fcntl.h>
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
  /*cbreak();*/
  halfdelay(2);
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  timeout(0);
  return (0);
}

/*
** Remove the end of the filename (".tetrimino")
*/
char		*separate_name(char *dirent)
{
  char		*name;
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (dirent[++i] && dirent[i] != '.')
    nb++;
  if ((name = malloc(sizeof(*name) * (nb + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb + 1)
    name[i++] = '\0';
  i = -1;
  while (++i < nb)
    name[i] = dirent[i];
  name[i] = '\0';
  return (name);
}

void		count_height(t_files *file, t_parser *parser)
{
  char		*tmp;
  int		fd;

  parser->count_height = -1;
  fd = file->fd;
  while ((tmp = get_next_line(fd)))
    {
      parser->count_height += 1;
      free(tmp);
    }
  close(fd);
  file->fd = open((file->link = concat("./tetriminos/", file->dirent->d_name)),
  		 O_RDONLY);
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
void		initialize_files(t_list *list)
{
  t_files	file;
  t_parser	parser;

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
	}
    }
  closedir(file.dir);
}

void		exit_tetris(char *str, int constant)
{
  my_putstr(str);
  exit ((constant == -1) ? (-1) : (0));
}

int		main(int argc, char **argv)
{
  t_tetris	game;
  t_list	list;

  initialize_struct(&game);
  initialize_value(&game);
  if (argc > 1)
    options(&game, argc, argv);
  init_list(&list);
  initialize_files(&list);
  if (game.debug == true)
    mode_debug(&game, &list);
  debug_display_list(list);
  game.list = list;
  initialize_game(&game);
  my_free(&game, &list);
  endwin();
  return (0);
}
