/*
** display.c for display.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 26 15:37:26 2016 Chevalier Nicolas
** Last update Mon Mar 14 21:25:49 2016 Chevalier Nicolas
*/

#include	"tetris.h"

void		display_score(t_tetris *game)
{
  box(game->windows->score, 0, 0);
  wrefresh(game->windows->score);
}

void		display_scene(t_tetris *game)
{
  box(game->windows->scene, 0, 0);
  /* TEST */
  wmove(game->windows->scene, 5, 2);
  waddch(game->windows->scene, ' ' | A_REVERSE);
  /* **** */
  wrefresh(game->windows->scene);
}
