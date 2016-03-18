/*
** utils_options.c for utils_options.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar 11 18:16:57 2016 Chevalier Nicolas
** Last update Fri Mar 18 00:50:48 2016 Chevalier Nicolas
*/

#include "tetris.h"

char		*str(char *argv)
{
  char		*tmp;
  int		len;
  int		i;

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

/*
** Get arguments options such -kl (--key-turn={GET})
*/
char		*get_arg_options(char **argv, int *i)
{
  int		x;
  int		y;

  y = 0;
  x = -1;
  while (argv[y][++x] && argv[y][x] != '=');
  if (argv[y][x] && argv[y][x] == '=')
    x++;
  else if (!(my_strncmp(argv[y], "-d", 0)))
    {
      (*i)++;
      y++;
      x = 0;
    }
  return ((argv[y]) ? &argv[y][x] : &argv[0][0]);

}
