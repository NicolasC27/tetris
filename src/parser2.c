/*
** parser2.c for parser2.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Mar 20 00:04:38 2016 Chevalier Nicolas
** Last update Sun Mar 20 23:28:11 2016 Chevalier Nicolas
*/

#include "tetris.h"

void	check_star(t_parser *parser, char *str, int i)
{
  if (str[i] == '*')
    {
      parser->tmp[parser->tmp_colums][0] = parser->first;
      parser->tmp[parser->tmp_colums][1] = i + 1;
      parser->tmp_colums += 1;
      parser->star += 1;
    }
}

int		check_nb(int nb, int *i)
{
  int		count;

  count = 0;
  if (nb > 9)
    while (nb > 9)
      {
	nb /= 10;
	count++;
	(*i) += 1;
     }
  return (count);
}

void	init_variable(t_parser *parser)
{
  parser->first = 0;
  parser->tmp_colums = 0;
  parser->star = 0;
  parser->star_line = 0;
  parser->color = 0;
}
