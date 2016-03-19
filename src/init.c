/*
** init.c for init.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Wed Feb 24 19:00:31 2016 Chevalier Nicolas
** Last update Sat Mar 19 14:46:34 2016 Chevalier Nicolas
*/

#include	"tetris.h"

char		*my_getenv(char **env, char *str)
{
  int		i;
  int		j;

  i = 0;
  while (env[i])
    {
      j = -1;
      if (env[i][++j] == 'T')
	{
	  if (env[i][j + 1] == 'E' && env[i][j + 2] == 'R' && env[i][j + 3] == 'M'
	      && env[i][j + 4] == '=')
	    return (&env[i][j + 5]);
	}
      i++;
    }
  return (0);
}

/*
** Initialize default value of game
*/
void		initialize_value(t_tetris *game, char *name, char **env)
{
  char		bp[1024];

  if (tgetent(bp, my_getenv(env, "TERM")) <= 0)
    exit_tetris("Error with term\n", -1);
  game->binary_name = name;
  game->scene->rows = ROWS;
  game->scene->colums = COL;
  game->scene->level = 1;
  game->scene->points = 0;
  game->scene->highscore = 0;
  game->keys->keyleft = tigetstr("kcub1");
  game->keys->keyright = tigetstr("kcuf1");
  game->keys->keydrop = tigetstr("kcud1");
  game->keys->keyturn = tigetstr("kcuu1");
  game->keys->keyquit = "q";
  game->keys->keypause = " ";
  game->scene->boolnext = true;
  game->scene->line = 0;
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
