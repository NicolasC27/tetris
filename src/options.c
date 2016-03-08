/*
** options.c for options.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Mon Mar  7 18:15:23 2016 Chevalier Nicolas
** Last update Tue Mar  8 18:09:14 2016 Chevalier Nicolas
*/

#include	"tetris.h"

int			is_help(char **argv, int *i)
{
  my_putstr(HELP);
  exit (0);
  return (0);
}

int			is_level(char **argv, int *i)
{
  my_putstr("test");
  exit (0);
  return (0);
}

int			is_keyleft(char **argv, int *i)
{
  my_putstr("KEY LEFT");
  exit (0);
  return (0);
}

int			is_keyright(char **argv, int *i)
{
  my_putstr("KEY RIGHT");
  exit (0);
  return (0);
}

int			is_keydrop(char **argv, int *i)
{
  my_putstr("kEY DROP");
  exit (0);
  return (0);
}

int			is_keyquit(char **argv, int *i)
{
  my_putstr("KEY QUIT");
  exit (0);
  return (0);
}

int			is_keypause(char **argv, int *i)
{
  my_putstr("KEY PAUSE");
  exit (0);
  return (0);
}

int			is_mapsize(char **argv, int *i)
{
  my_putstr("mapsize");
  exit (0);
  return (0);
}

int			is_next(char **argv, int *i)
{
  my_putstr("IS NEXT");
  exit (0);
  return (0);
}

int			is_debug(char **argv, int *i)
{
  my_putstr("DEBUG");
  exit (0);
}

static t_flags		flags[] =
{
  {"-help", is_help},
  {"l", is_level},
  {"-level=", is_level},
  {"kl", is_keyleft},
  {"-key-left=", is_keyleft},
  {"kr", is_keyright},
  {"-key-right=", is_keyright},
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

int		list_option(int argc, char **argv, int *i)
{
  int		x;

  x = -1;
  while (++x < 17)
    if (my_strncmp(&argv[0][1], flags[x].flag, 0))
      flags[x].redirection(argv, i);
}

void		options(int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    {
      if (argv[i][0] != '-')
	{
	  flags[0].redirection(argv, &i);
	  exit (0);
	}
      list_option(argc, &argv[i], &i);
    }
}
