/*
** initialize_game.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 15:26:53 2016 romain samuel
** Last update Thu Mar 17 15:51:27 2016 romain samuel
*/

#include "tetris.h"

void		initialize_game(t_tetris *s)
{
  int		max_width;
  int		max_height;

  initialize_ncurses();
  max_width = get_max_termitrino_width(s->list.first);
  max_height = get_max_termitrino_height(s->list.first);
  s->windows->scene = newwin(s->scene->rows + 2,
				s->scene->colums + 2, 0, 25);
  s->windows->score = newwin(11, 23, 8, 0);
  s->windows->name = newwin(6, 23, 0, 0);
  if (s->scene->boolnext == true)
    {
      s->windows->next = newwin(4 + max_width, 4 + max_height,
				0, 29 + s->scene->colums);
      display_next(s);
    }
  s->game.max_next_height = 2 + max_height;
  s->game.max_next_width = 2 + max_width;
  keypad(s->windows->name, true);
  display_name(s);
  display_scene(s);
  display_score(s);
  game(s);
}
