/*
** debug.c for debug.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 17:22:19 2016 Chevalier Nicolas
** Last update Sat Mar  5 18:19:40 2016 Chevalier Nicolas
*/

#include	"tetris.h"

void		aff_list(int *tmp)
{
  int		i;

  i = 0;
  while (tmp[i])
    {
      my_put_nbr(tmp[i]);
      if (tmp[i + 1])
	my_putchar(',');
      i++;
    }
}

void		debug_display_list(t_list list)
{
  t_tetriminos	*tmp;
  int		a;
  int		i;

  tmp = list.first;
  while (tmp)
    {
      a = 0;
      i = 0;
      my_putchar('{');
      while (tmp->coord[a][i] != '\0')
	{
	  my_putchar('{');
	  aff_list(tmp->coord[a]);
	  my_putchar('}');
	  if (tmp->coord[a + 1][0])
	    my_putchar(',');
	  i = 0;
	  a++;
	}
      my_putchar('}');
      my_putchar('\n');
      tmp = tmp->next;
    }
}
