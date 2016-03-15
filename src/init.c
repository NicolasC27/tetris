/*
** init.c for init.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 19:00:31 2016 Chevalier Nicolas
** Last update Mon Mar 14 21:49:11 2016 Chevalier Nicolas
*/

#include	"tetris.h"

/*
** Initialize default value of game
*/
void		initialize_value(t_tetris *game)
{
  game->scene->rows = ROWS;
  game->scene->colums = COL;
  game->scene->level = 1;
  game->scene->points = 0;
  game->keys->keyquit = "q";
  game->keys->keyright = "^EOC";
  game->keys->keyleft = "^E0D";
  game->keys->keydrop = "^E0A";
  game->keys->keyturn = "^E0A";
  game->keys->keypause = "p";
  game->scene->boolnext = false;
  game->debug = false;
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

t_key		*initialize_key(t_tetris *game)
{
  if ((game->keys = malloc(sizeof(t_key))) == NULL)
    exit_tetris("Error with memory allocation\n", -1);
  return (game->keys);
}

/*
** Initialize structure from game
*/
void     	initialize_struct(t_tetris *game)
{
  game->windows = initialize_windows(game);
  game->scene = initialize_scene(game);
  game->keys = initialize_key(game);
}
