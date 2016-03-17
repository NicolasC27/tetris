/*
** get_next_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 17:08:16 2016 romain samuel
** Last update Thu Mar 17 15:42:10 2016 romain samuel
*/

#include "tetris.h"

int		get_nb_list_elem(t_tetriminos *root)
{
  t_tetriminos	*it;
  int		i;

  it = root;
  i = 0;
  while (it != NULL)
    {
      i++;
      it = it->next;
    }
  return (i);
}

void		get_next_tetrimino(t_tetris *s)
{
  int		nb;
  int		i;
  t_tetriminos	*it;

  i = 0;
  it = s->list.first;
  nb = rand() % get_nb_list_elem(s->list.first);
  while (i < nb)
    {
      it = it->next;
      i++;
    }/*
  if (it->valid == false)
    {
      get_next_tetrimino(s);
      return;
      }*/
  s->game.next = it;
}

int	get_current_tetrimino(t_tetris *s)
{
  s->game.current.name = s->game.next->name;
  if ((s->game.current.coord = copy_coord_tab(s->game.next)) == NULL)
    return (-1);
  s->game.current.width = s->game.next->width;
  s->game.current.height = s->game.next->height;
  s->game.current.color = s->game.next->color;
  if ((s->game.current.simple_coord = copy_coord_tab(s->game.next)) == NULL)
    return (-1);
  s->game.current.x_translation = 0;
  s->game.current.y_translation = 0;
  return (0);
}
