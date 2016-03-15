/*
** get_next_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 17:08:16 2016 romain samuel
** Last update Tue Mar 15 16:43:01 2016 romain samuel
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
    }
  s->game.next = it;
}

void	get_current_tetrimino(t_tetris *s)
{
  s->game.current.name = s->game.next->name;
  s->game.current.coord = s->game.next->coord;
  s->game.current.width = s->game.next->width;
  s->game.current.height = s->game.next->height;
  s->game.current.color = s->game.next->color;
}
