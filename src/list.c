/*
** list.c for list.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 17:16:51 2016 Chevalier Nicolas
** Last update Sat Mar 12 19:11:01 2016 Chevalier Nicolas
*/

#include	"tetris.h"

void		init_list(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}

void		push_back(t_list *list, t_parser *parser)
{
  t_tetriminos *tmp;

  if ((tmp = malloc(sizeof(t_tetriminos))) == NULL)
    exit_tetris("Error with malloc", -1);
  tmp->name = parser->name;
  tmp->coord = parser->tmp;
  tmp->next = list->first;
  tmp->width = parser->line;
  tmp->height = parser->colums;
  tmp->color = parser->color;
  tmp->next = NULL;
  if (list->last)
    list->last->next = tmp;
  else
    list->first = tmp;
  list->last = tmp;
}

void		push_front(t_list *list, t_parser *parser)
{
  t_tetriminos *tmp;

  if ((tmp = malloc(sizeof(t_tetriminos))) == NULL)
    exit_tetris("Error with malloc", -1);
  tmp->name = parser->name;
  tmp->coord = parser->tmp;
  tmp->next = list->first;
  tmp->width = parser->line;
  tmp->height = parser->colums;
  tmp->color = parser->color;
  tmp->prev = NULL;
  if (list->first)
    list->first->prev = tmp;
  else
    list->last = tmp;
  list->first = tmp;
}

void		init_parser(t_parser *parser)
{
  parser->first = 0;
  parser->colums = 0;
  parser->line = 0;
  parser->star = 0;
  parser->tmp_colums = 0;
}
