/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_tetris/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 16:03:44 2016 Chevalier Nicolas
** Last update Tue Mar  1 23:42:26 2016 Chevalier Nicolas
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

void		init_list(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}
void		push_back(t_list *list, int val)
{
  t_tetriminos *tmp;

  if ((tmp = malloc(sizeof(t_tetriminos))) == NULL)
    exit_tetris("Error with malloc", -1);
  tmp->nb = val;
  tmp->prev = list->last;
  tmp->next = NULL;
  if (list->last)
    list->last->next = tmp;
  else
    {
      list->first = tmp;
      list->last = tmp;
    }
}

void		push_front(t_list *list, int val)
{
  t_tetriminos *tmp;

  if ((tmp = malloc(sizeof(t_tetriminos))) == NULL)
    exit_tetris("Error with malloc", -1);
  tmp->nb = val;
  tmp->next = list->first;
  tmp->prev = NULL;
  if (list->first)
    list->first->prev = tmp;
  else
    {
      list->last = tmp;
      list->first = tmp;
    }
}

int		parser_tetriminos(t_tetris *game, char *str, int nbfiles)
{
  static int	first;
  static int	pos[4][3];
  int		i;
  int		nb;

  i = 0;
  if (first == 0)
    {
      while (str[i] != '\0')
	{
	  if ((nb = my_getnbr(&str[i])) == 0 && nb > 9)
	    return (0);
	  else if (str[i] != ' ' && (nb == 0 || nb > 9))
	    return (0);
	  else if ((nb == 0 || nb > 9) && (str[i + 1] == 32 && str[i + 1] == '\t'))
	    return (0);
	  else if (i > 5)
	    return (0);
	  if (i % 2 == 0)
	    {
	      if (i == 2)
		my_put_nbr(nb);
	    }
	  i++;
	}
    }
 if (first > 0 && first < 3)
    {
      i = 0;
      if (first == 1)
	pos == NULL;
      while (str[i])
	{
	  if (str[i] != ' ' && str[i] != '*')
	    return (0);
	  /* my_putchar(str[i]); */
	  if (str[i] == '*')
	    {
	      pos[first - 1][i] = first;
	      pos[first - 1][i + 1] = i;
	    }
	  i++;
	}
      i = 0;
      my_putstr("{");
      while (pos[0][i] != '\0')
	{
	  my_put_nbr(pos[0][i]);
	  if (pos[0][i])
	  my_putstr(",");
	  i++;
	}
      my_putstr("}");
      my_putchar('\n');
      exit (0);
    }
  first++;
}

int		initialize_files(t_tetris *game, t_list *list)
{
  struct dirent	*dirent;
  DIR		*dir;
  char		*s;
  int		fd;
  int		i;

  if ((dir = opendir("./tetriminos/")) == NULL)
    exit_tetris("Error with opendir", -1);
  while (dirent = readdir(dir))
    if (dirent->d_type == DT_REG)
      {
	i = 0;
	fd = open(concat("./tetriminos/", dirent->d_name), O_RDONLY);
	while ((s = get_next_line(fd)))
	  {
	    if (parser_tetriminos(game, s, i++) == 0)
	      return (0);
	    /* my_putchar('\n'); */
	    free(s);
	  }
	my_putstr(dirent->d_name);
	my_putchar('\n');
      }
}

int		main()
{
  t_tetris	game;
  t_tetriminos	shape;
  t_list	list;
  int		i;

  i = 0;
  init_list(&list);
  initialize_files(&game, &list);
  initialize_game(&game);
  endwin();
  return (0);
}
