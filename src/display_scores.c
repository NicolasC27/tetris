/*
** display_scores.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 18:40:32 2016 romain samuel
** Last update Sun Mar 20 02:59:08 2016 Chevalier Nicolas
*/

#include "tetris.h"

int	my_intlen(int nb)
{
  int	i;
  int	div;

  i = 1;
  div = 10;
  while (nb / div >= 1)
    {
      div *= 10;
      i++;
    }
  return (i);
}

int	display_timer(t_tetris *s, time_t timer)
{
  int	seconds;
  int	minutes;

  minutes = timer / 60;
  seconds = timer % 60;
  wmove(s->windows->score, 8, 15);
  wprintw(s->windows->score, "%02d:%02d", minutes, seconds);
  return (0);
}

int	display_scores(t_tetris *s, time_t timer)
{
  display_score(s);
  wmove(s->windows->score, 2, 20 - (my_intlen(s->scene->highscore)));
  wprintw(s->windows->score, "%d", s->scene->highscore);
  wmove(s->windows->score, 3, 20 - (my_intlen(s->scene->points)));
  wprintw(s->windows->score, "%d", s->scene->points);
  wmove(s->windows->score, 5, 20 - (my_intlen(s->scene->line)));
  wprintw(s->windows->score, "%d", s->scene->line);
  wmove(s->windows->score, 6, 20 - (my_intlen(s->scene->level)));
  wprintw(s->windows->score, "%d", s->scene->level);
  display_timer(s, timer);
  wrefresh(s->windows->score);
  return (0);
}
