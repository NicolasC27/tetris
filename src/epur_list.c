/*
** epur_list.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 00:53:07 2016 romain samuel
** Last update Sun Mar 20 01:12:07 2016 romain samuel
*/

#include "tetris.h"

int		epur_list(t_tetris *s)
{
  t_tetriminos	*it;

  it = s->list->first->next;
  while (s->list->first != NULL && s->list->first->valid == false)
    {
      s->list->first = s->list->first->next;
      free(s->list->first->prev);
      s->list->first->prev = NULL;
    }
  while (s->list->last != NULL && s->list->last->valid == false)
    {
      s->list->last = s->list->first->prev;
      free(s->list->first->next);
      s->list->first->next = NULL;
    }
  while (it != NULL)
    {
      if (it->valid == false)
	{
	  it = it->next;
	  it->prev->prev = ;
	}
      it = it->next;
    }
  return (0);
}
