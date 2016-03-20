/*
** free.c for free.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 18:37:19 2016 Chevalier Nicolas
** Last update Sun Mar 20 18:02:38 2016 Chevalier Nicolas
*/

#include "tetris.h"

void		free_matrix(t_tetris *s)
{
  int		y;

  y = 0;
  while (y < s->scene->rows)
    {
      free(s->game.scene[y]);
      y++;
    }
  free(s->game.scene);
}

void		free_tab(t_tetriminos *tmp)
{
  int		a;

  a = 0;
  while (tmp->coord[a][0])
    free(tmp->coord[a++]);
  free(tmp->coord[a]);
  free(tmp->coord);
}

void		my_free(t_tetris *game, t_list *list)
{
  t_tetriminos	*tmp;
  t_tetriminos	*tmp2;

  tmp2 = list->first;
  while (tmp2)
    {
      tmp = tmp2;
      if (tmp->valid == true)
	free_tab(tmp);
      tmp2 = tmp2->next;
      free(tmp->name);
      free(tmp);
    }
  list->first = NULL;
  list->last = NULL;
  free(game->windows);
  free(game->scene);
  free(game->keys);
}
