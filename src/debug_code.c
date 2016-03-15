/*
** debug_code.c for debug_code.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Mon Mar 14 18:34:37 2016 Chevalier Nicolas
** Last update Tue Mar 15 15:32:14 2016 Chevalier Nicolas
*/

#include "tetris.h"

void		aff_list(int *tmp)
{
  static int	k;
  int		i;

  k = 1;
  i = 0;
  while (tmp[i])
    {
      my_put_nbr(tmp[i]);
      if (k + 1 == tmp[i])
	k++;
      if (tmp[i + 1])
      	my_putchar(',');
      i++;
    }
}

/*
** Display table dual dimensions shapes
*/
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
