/*
** options.c for options.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Mon Mar  7 18:15:23 2016 Chevalier Nicolas
** Last update Thu Mar 10 19:51:15 2016 Chevalier Nicolas
*/

#include	"tetris.h"
#include	<termios.h>
#include	<unistd.h>
#include	<sys/ioctl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

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
}

int			is_debug(char *options, t_tetris *game, char **argv, int *i)
{
  game->debug = true;
}


char			*str(char *argv)
{
  char			*tmp;
  int			len;
  int			i;

  if ((tmp = malloc(sizeof(char) * my_strlen(argv) + 1)) == NULL)
    return (NULL);
  len = my_strlen(argv);
  i = 0;
  while (i < len && argv[i - 1] != '=')
    {
      tmp[i] = argv[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

char		*get_arg_options(char **argv, int *i)
{
  int			x;
  int			y;

  y = 0;
  x = -1;
  while (argv[y][++x] && argv[y][x] != '=');
  if (argv[y][x] && argv[y][x] == '=')
    x++;
  else
    {
      (*i)++;
      y++;
      x = 0;
    }
  return ((argv[y]) ? &argv[y][x] : &argv[0][0]);
}

int		list_option(t_tetris *game, int argc, char **argv, int *i)
{
  int		x;
  int		nb;
  char		*options;
  char		*c;

  x = -1;
  c = str(&(argv[0][1]));
  while (++x < 17)
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
      if (!(list_option(game, argc, &argv[i], &i)))
	{
	  flags[0].redirection(NULL, game, argv, &i);
	}
    }
}
