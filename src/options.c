/*
** options.c for options.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Mon Mar  7 18:15:23 2016 Chevalier Nicolas
** Last update Mon Mar 14 21:47:26 2016 Chevalier Nicolas
*/

#include	<termios.h>
#include	<unistd.h>
#include	<sys/ioctl.h>
#include	<sys/stat.h>
#include	"tetris.h"

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

int			mode(int i)
{
  static struct termios	oldT;
  static struct termios	newT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);

      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    ioctl(0, TCSETS, &oldT);
  return (0);
}

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
  while (++x < 19)
    if ((nb = my_strncmp(c, flags[x].flag, 0)))
      {
	options = get_arg_options(argv, i);
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
    {
      if (argv[i][0] != '-')
      	{
     	  flags[0].redirection(NULL, game, argv, &i);
      	  exit (0);
      	}
      if (!(list_option(game, &argv[i], &i)))
	{
	  my_putstr("test");
	  flags[0].redirection(NULL, game, argv, &i);
	}
    }
}
