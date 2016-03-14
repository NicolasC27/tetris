/*
** free.c for free.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 18:37:19 2016 Chevalier Nicolas
** Last update Mon Mar 14 21:02:38 2016 Chevalier Nicolas
*/

#include "tetris.h"

void		free_tab(t_tetriminos *tmp)
{
  int		i;
  int		a;

  a = 0;
  i = 0;
  while (tmp->coord[a][0])
    free(tmp->coord[a++]);
  free(tmp->coord[a]);
  /* free(tmp->coord[a + 1]); */
  free(tmp->coord);
}

void		my_free(t_list *list)
{
  t_tetriminos	*tmp;
  t_tetriminos	*tmp2;

  tmp2 = list->first;
  while (tmp2)
    {
      my_putstr("Je PASSE");
      tmp = tmp2;
      free_tab(tmp);
      tmp2 = tmp2->next;
      free(tmp);
    }
  list->first = NULL;
  list->last = NULL;
}
