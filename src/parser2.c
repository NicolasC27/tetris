/*
** parser2.c for parser2.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Mar 20 00:04:38 2016 Chevalier Nicolas
** Last update Sun Mar 20 00:06:10 2016 Chevalier Nicolas
*/

#include "tetris.h"

void		check_star(t_parser *parser, char *str, int i)
{
  if (str[i] == '*')
    {
      parser->tmp[parser->tmp_colums][0] = parser->first;
      parser->tmp[parser->tmp_colums][1] = i + 1;
      parser->tmp_colums += 1;
      parser->star += 1;
    }
}
