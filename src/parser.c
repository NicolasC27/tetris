/*
** parser.c for parser.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar  4 15:57:57 2016 Chevalier Nicolas
** Last update Fri Mar 18 20:49:51 2016 Chevalier Nicolas
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
      if (parser->color == 0)
	{
	  parser->valid = 0;
	  return (0);
	}
      if (parser->first == 1)
	parser->tmp = create_tab(parser);
      while (str[++i])
	{
	  if (str[i] != ' ' && str[i] != '*')
	    {
	      parser->valid = 0;
	      return (0);
	    }
	  if (str[i] == '*')
	    {
	      parser->tmp[parser->tmp_colums][0] = parser->first;
	      parser->tmp[parser->tmp_colums][1] = i + 1;
	      parser->tmp_colums += 1;
	      parser->star += 1;
	    }
	  count++;
	}
    }
  while (str[--i] == ' ')
    count--;
  if (count > parser->star_line)
    parser->star_line = count;
  if (parser->star_line > parser->line)
    {
      parser->valid = 0;
      return (0);
      }
  return (1);
}

/*
** End line
** Put informations in the list
*/
int		put_int_tab(t_parser *parser, int *loop, t_list *list)
{
  int		height;

  height = (*loop);
  if (parser->valid == 0)
    push_front(list, parser);
  else if ((parser->colums == height - 1))
    {
      if ((parser->valid != 0) && (parser->star_line != parser->line))
	{
	  parser->valid = 0;
	  put_int_tab(parser, loop, list);
	  }
      if (parser->valid != 0)
	push_front(list, parser);
    }
  if (parser->valid == 0 || parser->colums == height - 1)
    {
      parser->first = 0;
      parser->tmp_colums = 0;
      parser->star = 0;
      parser->star_line = 0;
      parser->color = 0;
      (*loop) = 0;
    }
}

int		parser_error(t_parser *parser, int nb, int i, char *str)
{
  if (i % 2 == 0)
    if (nb == 0 || nb > 9)
      return (0);
    else if (i == 0)
      parser->line = nb;
    else if (i == 2)
      {
	if (nb != parser->count_height)
	  return (0);
	parser->colums = nb;
      }
    else if (i == 4)
      parser->color = nb;
  if (i % 2 == 1)
    if (str[i] != ' ')
      return (0);
  return (1);
}

int		parser_tetriminos(t_parser *parser, t_list *list, char *str)
{
  static int	loop;
  int		i;
  int		nb;

  i = -1;
  parser->valid = 1;
  if (parser->first == 0)
    {
      parser->star_line = 0;
      while (str[++i] != '\0')
	{
	  nb = my_getnbr(&str[i]);
	  if (!(parser_error(parser, nb, i, str)))
	    {
	      parser->valid = 0;
	      put_int_tab(parser, &loop, list);
	      return (0);
	    }
	}
    }
  if (!(search_star(parser, str)))
    put_int_tab(parser, &loop, list);
  if (parser->valid == 0)
    return (0);
  parser->first += 1;
  loop++;
  put_int_tab(parser, &loop, list);
  return (1);
}
