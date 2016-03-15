/*
** parser.c for parser.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar  4 15:57:57 2016 Chevalier Nicolas
** Last update Tue Mar 15 16:46:56 2016 romain samuel
*/

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
  if ((tab = malloc(sizeof(*tab) * (lines + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < lines)
    if ((tab[i] = malloc(sizeof(**tab) * colums)) == NULL)
      return (NULL);
  tab[i] = NULL;
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
void		 search_star(t_parser *parser, char *str)
{
  int		i;

  i = 0;
  if (parser->first > 0 && parser->first < parser->colums + 1)
    {
      if (parser->first == 1)
	parser->tmp = create_tab(parser);
      while (str[i])
	{
	  if (str[i] != ' ' && str[i] != '*')
	    exit (0);
	  if (str[i] == '*')
	    {
	      parser->tmp[parser->tmp_colums][0] = parser->first;
	      parser->tmp[parser->tmp_colums][1] = i + 1;
	      parser->tmp_colums += 1;
	      parser->star += 1;
	    }
	  i++;
	}
    }
}

/*
** End line
** Put informations in the list
*/
void		put_int_tab(t_parser *parser, int *loop, t_list *list)
{
  int		star;

  star = (*loop);
  if (parser->colums == star - 1)
   {
     push_back(list, parser);
     parser->first = 0;
     parser->tmp_colums = 0;
     parser->line = 0;
     parser->colums = 0;
     parser->star = 0;
     (*loop) = 0;
   }
}

int		parser_tetriminos(t_parser *parser, t_list *list, char *str)
{
  static int	loop;
  int		i;
  int		nb;

  i = 0;
  if (parser->first == 0)
    {
      while (str[i] != '\0')
	{
	  if ((nb = my_getnbr(&str[i])) == 0 && nb > 9)
	      return (0);
	  else if (str[i] != ' ' && (nb == 0 || nb > 9))
	      return (0);
	  else if ((nb == 0 || nb > 9) && (str[i + 1] == 32 && str[i + 1] == '\t'))
	      return (0);
	  if (i % 2 == 0)
	    {
	      if (i == 0)
		parser->line = nb;
	      if (i == 2)
		parser->colums = nb;
	      if (i == 2)
		parser->color = nb;
	    }
	  i++;
	}
    }
  search_star(parser, str);
  parser->first += 1;
  loop++;
  put_int_tab(parser, &loop, list);
  return (0);
}
