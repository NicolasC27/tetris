/*
** init.c for init.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 19:00:31 2016 Chevalier Nicolas
** Last update Wed Feb 24 19:30:14 2016 Chevalier Nicolas
*/

#include	"tetris.h"

/*
** Function which initialize terminal in ncurses
*/
int		initialize_ncurses()
{
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  timeout(0);
}

t_windows	*initialize_windows(t_tetris *game)
{
  if ((game->windows = malloc(sizeof(t_windows))) == NULL)
    exit_tetris("Error with memory allocation\n", -1);
  return (game->windows);
}

t_scene		*initialize_scene(t_tetris *game)
{
  if ((game->scene = malloc(sizeof(t_scene))) == NULL)
    exit_tetris("Error with memory allocation\n", -1);
  return (game->scene);
}


void     	initialize_struct(t_tetris *game)
{
  game->windows = initialize_windows(game);
  game->scene = initialize_scene(game);
}
