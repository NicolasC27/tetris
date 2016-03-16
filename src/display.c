/*
** display.c for display.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 26 15:37:26 2016 Chevalier Nicolas
** Last update Wed Mar 16 17:14:03 2016 romain samuel
*/

#include	"tetris.h"

void		display_name(t_tetris *game)
{
  wrefresh(game->windows->name);
}

void		display_score(t_tetris *game)
{
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
