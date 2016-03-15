/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Tue Mar 15 16:05:56 2016 Chevalier Nicolas
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
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  timeout(0);
  return (0);
}

/*
** Initialize windows scene and score for the moment
*/
void		initialize_game(t_tetris *game)
{
  initialize_ncurses();
  game->windows->scene = newwin(game->scene->rows,
				game->scene->colums, 0, game->scene->colums * 1.9);
  game->windows->score = newwin(game->scene->rows / 2,
				game->scene->colums * (1.8),
				game->scene->rows / 3, 0);
  display_scene(game);
  display_score(game);
  while (42);
}

/*
** Remove the end of the filename (".tetrimino")
*/
char		*separate_name(char *dirent)
{
  char		*name;
  int		i;

  if ((name = malloc(sizeof(char) * my_strlen(dirent) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (dirent[++i] && dirent[i] != '.')
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
	while ((s = get_next_line(fd)))
	  {
	    parser.name = separate_name(dirent->d_name);
	    parser_tetriminos(&parser, list, s);
	    free(parser.name);
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
  initialize_game(&game);
  my_free(&game, &list);
  endwin();
  return (0);
}
