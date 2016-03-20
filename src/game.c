/*
** game.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 01:53:41 2016 romain samuel
** Last update Sun Mar 20 01:22:17 2016 romain samuel
*/

#include "tetris.h"

int		get_level_time(t_scene *s)
{
  int		nb;

  if (s->level > 9)
    nb = 9;
  else
    nb = s->level;
  return (10 - nb);
}

int		main_loop(t_tetris *s)
{
  time_t	new_time;
  int		i;

  i = 0;
  s->game.save_time = s->game.stime;
  while (42)
    {
      handle_keyboard(s);
      new_time = time(NULL) - s->game.stime;
      if (i > get_level_time(s->scene))
	{
	  i = 0;
	  if (time_drop(s) == -2)
	    return (0);
	  display_matrix(s, s->game.scene);
	  display_tetrimino(s->windows->scene, s->game.current);
	  display_scores(s, new_time);
	}
      s->game.save_time = new_time;
      i++;
    }
  return (0);
}

int		game_loop(t_tetris *s)
{
  while (42)
    {
      clear_matrix(s);
      display_matrix(s, s->game.scene);
      manage_highscore(s);
      s->game.stime = time(NULL);
      get_next_tetrimino(s);
      if (get_current_tetrimino(s) == -1)
	return (-1);
      get_next_tetrimino(s);
      if (s->scene->boolnext == true)
	{
	  clear_next(s);
	  display_tetrimino(s->windows->next, *s->game.next);
	}
      init_tetrimino_pos(s);
      display_tetrimino(s->windows->scene, s->game.current);
      display_scores(s, 0);
      if (main_loop(s) == -1)
	return (-1);
    }
}

int		game(t_tetris *s)
{
  srand(time(NULL));
  wrefresh(s->windows->name);
  if (create_compartments(s) == -1)
    return (-1);
  game_loop(s);
  free_matrix(s);
  return (0);
}
