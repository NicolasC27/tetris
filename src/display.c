/*
** display.c for display.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 26 15:37:26 2016 Chevalier Nicolas
** Last update Thu Mar 17 02:06:13 2016 romain samuel
*/

#include	"tetris.h"

void	display_t_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 1 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 2 + x);
  waddch(win, ' ');
  wmove(win, 3, 2 + x);
  waddch(win, ' ');
  wmove(win, 4, 2 + x);
  waddch(win, ' ');
  wmove(win, 5, 2 + x);
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_e_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 5 + x);
  waddch(win, ' ');
  wmove(win, 3, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 5 + x);
  waddch(win, ' ');
  wmove(win, 5, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_r_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 13 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 13 + x);
  waddch(win, ' ');
  wmove(win, 2, 15 + x);
  waddch(win, ' ');
  wmove(win, 3, 13 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 13 + x);
  waddch(win, ' ');
  wmove(win, 4, 15 + x);
  waddch(win, ' ');
  wmove(win, 5, 13 + x);
  waddch(win, ' ');
  wmove(win, 5, 15 + x);
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_i_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 17 + x);
  waddch(win, ' ');
  wmove(win, 2, 17 + x);
  waddch(win, ' ');
  wmove(win, 3, 17 + x);
  waddch(win, ' ');
  wmove(win, 4, 17 + x);
  waddch(win, ' ');
  wmove(win, 5, 17 + x);
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_s_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 19 + x);
  waddch(win, ' ');
  wmove(win, 3, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 21 + x);
  waddch(win, ' ');
  wmove(win, 5, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

int		init_title_color_pairs()
{
  int		i;

  i = 1;
  while (i < 7)
    {
      init_pair(i, COLOR_BLACK, i);
      i++;
    }
  return (0);
}

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
