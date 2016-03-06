/*
** free.c for free.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 18:37:19 2016 Chevalier Nicolas
** Last update Sat Mar  5 18:37:38 2016 Chevalier Nicolas
*/

#include "tetris.h"

void		my_free(t_list *list)
{
  t_tetriminos	*tmp;
  t_tetriminos	*tmp2;

  tmp2 = list->first;
  while (tmp2)
    {
      tmp = tmp2;
      tmp2 = tmp2->next;
      free(tmp);
    }
  list->first = NULL;
  list->last = NULL;
}
