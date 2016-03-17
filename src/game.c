/*
** game.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 01:53:41 2016 romain samuel
** Last update Thu Mar 17 15:59:07 2016 romain samuel
*/

#include "tetris.h"

int	create_compartments(t_tetris *s)
{
  int	i;
  int	j;

  i = 0;
  if ((s->game.scene = malloc(sizeof(t_compartment *) * (s->scene->rows + 1)))
      == NULL)
    return (-1);
  while (i < s->scene->rows)
    {
      j = 0;
      if ((s->game.scene[i] = malloc(sizeof(t_compartment)
				     * (s->scene->colums))) == NULL)
	return (-1);
      while (j < s->scene->colums)
	{
	  s->game.scene[i][j].filled = false;
	  s->game.scene[i][j].color = 0;
	  j++;
	}
      i++;
    }
  return (0);
}

int		time_drop(t_tetris *s)
{
  if (move_tetrimino(s, 0, 1) == -1)
    {
      fill_matrix_with_tetrimino(s);
      if (get_current_tetrimino(s) == -1)
	return (-2);
      get_next_tetrimino(s);
      clear_next(s);
      display_tetrimino(s->windows->next, *s->game.next);
      if (init_tetrimino_pos(s) == -1)
	return (-2);
      if (check_complete_lines(s) > 0)
	{
	  /*changer score*/
	  return (-1);
	}
      return (-1);
    }
  else
    return (0);
}

int		handle_keyboard_input(t_tetris *s)
{
  int		key;

  if ((key = wgetch(s->windows->name)) == -1)
    return (0);
  else
    {
      wprintw(s->windows->name, "%c", key);
      wrefresh(s->windows->name);
    }
  return (0);
}

int		main_loop(t_tetris *s)
{
  time_t	new_time;

  s->game.save_time = s->game.stime;
  while (42)
    {
      handle_keyboard_input(s);
      new_time = time(NULL) - s->game.stime;
      if (new_time > s->game.save_time)
	{
	  if (time_drop(s) == -2)
	    return (-1);
	  display_matrix(s, s->game.scene);
	  display_tetrimino(s->windows->scene, s->game.current);
	  display_scores(s, new_time);
	}
      s->game.save_time = new_time;
    }
  return (0);
}

int	game(t_tetris *s)
{
  srand(time(NULL));
  s->game.stime = time(NULL);
  wrefresh(s->windows->name);
  if (create_compartments(s) == -1)
    return (-1);
  get_next_tetrimino(s);
  if (get_current_tetrimino(s) == -1)
    return (-1);
  get_next_tetrimino(s);
  clear_next(s);
  display_tetrimino(s->windows->next, *s->game.next);
  init_tetrimino_pos(s);
  display_tetrimino(s->windows->scene, s->game.current);
  display_scores(s, 0);
  if (main_loop(s) == -1)
    return (-1);
  return (0);
}
