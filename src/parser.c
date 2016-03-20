/*
** parser.c for parser.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar  4 15:57:57 2016 Chevalier Nicolas
** Last update Sun Mar 20 23:32:37 2016 Chevalier Nicolas
*/

#include <stdbool.h>
#include "tetris.h"

/*
** Create tab double dimensions
** {{x, y}, {x,y}, ...}
*/
int		**create_tab(t_parser *parser)
{
  int		**tab;
  int		i;
  int		lines;
  int		colums;
  int		a;

  colums = 3;
  lines = (parser->line * parser->colums) + 1;
  if ((tab = malloc(sizeof(int *) * (lines + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < lines)
    if ((tab[i] = malloc(sizeof(int) * colums)) == NULL)
      return (NULL);
  i = -1;
  while (++i < lines)
    {
      a = -1;
      while (++a < colums)
	tab[i][a] = '\0';
    }
  return (tab);
}

/*
** Search star in the files
** put in the tab temporarily
*/
int		 search_star(t_parser *parser, char *str)
{
  int		i;
  int		count;

  count = 0;
  i = -1;
  if (parser->first > 0 && parser->first < parser->colums + 1)
    {
      if (parser->color < 0)
	return (0);
      if (parser->first == 1)
	parser->tmp = create_tab(parser);
      while (str[++i])
	{
	  if (str[i] != ' ' && str[i] != '*')
	    return (0);
	  check_star(parser, str, i);
	  count++;
	}
      while (str[--i] == ' ')
	count--;
      if (count > parser->star_line)
	parser->star_line = count;
    }
  return ((parser->star_line > parser->line) ? 0 : 1);
}

/*
** End line
** Put informations in the list
*/
int		put_int_tab(t_parser *parser, int *loop, t_list *list, t_tetris *game)
{
  int		height;

  height = (*loop);
  if (parser->valid == 0)
    push_front(list, parser);
  else if ((parser->colums == height - 1))
    {
      if ((parser->valid != 0 && parser->star_line != parser->line) ||
	  ((parser->colums > game->scene->rows)
	   || (parser->line > game->scene->colums)) || (parser->color > 7))
	{
	  parser->valid = 0;
	  put_int_tab(parser, loop, list, game);
	}
      else if (parser->valid != 0)
	push_front(list, parser);
    }
  if (parser->valid == 0 || parser->colums == height - 1)
    {
      init_variable(parser);
      (*loop) = 0;
    }
  return (0);
}

int		parser_error(t_parser *parser, int nb, int *i, char *str)
{
  static int	s;

  if (*i == 0)
    s = 0;
  (nb > 9) ? check_nb(nb, i) : (0);
 if (s % 2 == 0)
    {
      if ((nb == 0 && s == 0) || (nb == 0 && s == 2))
      	return (0);
      if (s == 0)
	parser->line = nb;
      else if (s == 2)
	{
	  if (nb != parser->count_height)
	    return (0);
	  parser->colums = nb;
	}
      else if (s == 4)
	parser->color = nb;
    }
  if (s % 2 == 1)
    if (str[*i] != ' ')
      return (0);
  s++;
  return (1);
}

int		parser_tetriminos(t_parser *parser, t_list *list, char *str,
				  t_tetris *game)
{
  static int	loop;
  int		i;
  int		nb;

  i = -1;
  if (parser->first == 0)
    {
      parser->color = -1;
      parser->star_line = 0;
      while (str[++i] != '\0')
	{
	  nb = my_getnbr(&str[i]);
	  if (!(parser->valid = parser_error(parser, nb, &i, str)))
	    return (put_int_tab(parser, &loop, list, game));
	}
    }
  if (!((parser->valid = search_star(parser, str))))
    return (put_int_tab(parser, &loop, list, game));
  parser->first += 1;
  loop++;
  put_int_tab(parser, &loop, list, game);
  return (1);
}
