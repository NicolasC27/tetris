/*
** options.c for options.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Mon Mar  7 18:15:23 2016 Chevalier Nicolas
** Last update Sun Mar 20 01:16:43 2016 Chevalier Nicolas
*/

#include <unistd.h>
#include "tetris.h"

static t_flags	flags[] =
{
  {"-help", is_help},
  {"l", is_level},
  {"-level=", is_level},
  {"kl", is_keyleft},
  {"-key-left=", is_keyleft},
  {"kr", is_keyright},
  {"-key-right=", is_keyright},
  {"kt", is_keyturn},
  {"-key-turn=", is_keyturn},
  {"kd", is_keydrop},
  {"-key-drop=", is_keydrop},
  {"kq", is_keyquit},
  {"-key-quit=", is_keyquit},
  {"kp", is_keypause},
  {"-key-pause=", is_keypause},
  {"-map-size=", is_mapsize},
  {"w", is_next},
  {"-without-next", is_next},
  {"d", is_debug},
  {"-debug", is_debug},
};

int		is_debug(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(**argv);
  (void)(*options);
  game->debug = true;
  return (0);
}

int		list_option(t_tetris *game, char **argv, int *i)
{
  int		x;
  int		nb;
  char		*options;
  char		*c;

  x = -1;
  c = str(&(argv[0][1]));
  while (++x < 20)
    if ((nb = my_strncmp(c, flags[x].flag, 0)))
      {
	if (!my_strncmp(c, "-debug", 0) && !my_strncmp(c, "-without-next", 0))
	  options = get_arg_options(argv, i);
	else
	  options = "\0";
	flags[x].redirection(options, game, argv, i);
	return (1);
    }
  return (0);
}

void		options(t_tetris *game, int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    if (argv[i][0] != '-')
      flags[0].redirection(NULL, game, argv, &i);
    else if (!(list_option(game, &argv[i], &i)))
      flags[0].redirection(NULL, game, argv, &i);
}
