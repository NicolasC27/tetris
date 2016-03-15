/*
** display.c for display.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 26 15:37:26 2016 Chevalier Nicolas
** Last update Tue Mar 15 16:30:27 2016 romain samuel
*/

#include	"tetris.h"

void		display_name(t_tetris *game)
{
  wrefresh(game->windows->name);
}

void		display_score(t_tetris *game)
{
  box(game->windows->score, 0, 0);
  wrefresh(game->windows->score);
}

void		display_scene(t_tetris *game)
{
  box(game->windows->scene, 0, 0);
  wrefresh(game->windows->scene);
}

void		display_next(t_tetris *game)
{
  box(game->windows->next, 0, 0);
  wrefresh(game->windows->next);
}
