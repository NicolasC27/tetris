/*
** display.c for display.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 26 15:37:26 2016 Chevalier Nicolas
** Last update Sun Mar 20 00:01:21 2016 romain samuel
*/

#include	"tetris.h"

void		display_name(t_tetris *game)
{
  display_t_letter(game->windows->name, 0, 1);
  display_e_letter(game->windows->name, 0, 2);
  display_t_letter(game->windows->name, 8, 3);
  display_r_letter(game->windows->name, 0, 4);
  display_i_letter(game->windows->name, 0, 5);
  display_s_letter(game->windows->name, 0, 6);
  wrefresh(game->windows->name);
}

void		display_score(t_tetris *game)
{
  wclear(game->windows->score);
  wprintw(game->windows->score,
	  "\n\n   High Score\n   Score\n\n   Lines\n   Level\n\n   Timer:\n\n");
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
