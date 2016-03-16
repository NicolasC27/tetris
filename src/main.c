/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Wed Mar 16 17:53:49 2016 romain samuel
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<fcntl.h>
#include	"tetris.h"
#include	"gnl.h"

/*
** Function which initialize terminal in ncurses
*/
int		initialize_ncurses()
{
  initscr();
  start_color();
  /*while (i < COLORS && i < COLOR_PAIRS)
    {
      init_pair(i, i, COLOR_BLACK);
      i++;
      }*/
  /*cbreak();*/
  halfdelay(2);
  noecho();
  /*keypad(stdscr, TRUE);*/
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

/*
** Get all tetriminos from dir tetriminos
*/
void		initialize_files(t_list *list)
{
  struct dirent	*dirent;
  t_parser	parser;
  DIR		*dir;
  char		*s;
  char		*link;
  int		fd;

  init_parser(&parser);
  if ((dir = opendir("./tetriminos/")) == NULL)
    exit_tetris("Error with opendir", -1);
  while ((dirent = readdir(dir)))
    if (dirent->d_type == DT_REG)
      {
	fd = open((link = concat("./tetriminos/", dirent->d_name)), O_RDONLY);
	parser.name = separate_name(dirent->d_name);
	while ((s = get_next_line(fd)))
	  {
	    parser_tetriminos(&parser, list, s);
	    free(s);
	  }
	free(link);
	close(fd);
     }
  closedir(dir);
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
