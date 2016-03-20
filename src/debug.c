/*
** debug.c for debug.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 17:22:19 2016 Chevalier Nicolas
** Last update Sun Mar 20 01:17:04 2016 Chevalier Nicolas
*/

#include <stdlib.h>
#include "tetris.h"

void		display_keys(char *key)
{
  int		i;

  i = -1;
  while (key[++i])
    if (key[i] == 27)
      my_putstr("^E");
    else if (key[i] == 32)
      my_putstr("(space)");
    else
      my_putchar(key[i]);
}

/*
** Display shortcuts
*/
void		shortcuts(t_tetris *game, int nb)
{
  my_putstr(DEBUG);
  my_putstr("Key Left : ");
  display_keys(game->keys->keyleft);
  my_putstr("\nKey Right : ");
  display_keys(game->keys->keyright);
  my_putstr("\nKey Turn : ");
  display_keys(game->keys->keyturn);
  my_putstr("\nKey Drop : ");
  display_keys(game->keys->keydrop);
  my_putstr("\nKey Quit : ");
  display_keys(game->keys->keyquit);
  my_putstr("\nKey Pause : ");
  display_keys(game->keys->keypause);
  my_putstr("\nNext : ");
  my_putstr((game->scene->boolnext) ? "Yes" : "No");
  my_putstr("\nLevel : ");
  my_put_nbr(game->scene->level);
  my_putstr("\nSize : ");
  my_put_nbr(game->scene->rows);
  my_putstr("*");
  my_put_nbr(game->scene->colums);
  my_putstr("\nTetriminos : ");
  my_put_nbr(nb);
  my_putchar('\n');
}

/*
** Display shape the current link
*/
void		aff_shape(t_tetriminos *tmp, int *nb, int *a)
{
  int		k;
  int		width;

  k = 0;
  width = width_line(&tmp->coord[*a], *a, (*nb)++);
  while (++k < width + 1)
    {
      if (tmp->coord[*a][1] == k)
	{
	  my_putchar('*');
	  (*a)++;
	}
      else
	my_putchar(' ');
    }
  my_putchar('\n');
}

/*
** Display informations list and goes into the function aff_shape
*/
void		shape_list(t_tetriminos *tmp)
{
  int		a;
  int		nb;

  my_putstr("Tetriminos : ");
  my_putstr("Name ");
  my_putstr(tmp->name);
  my_putstr(" : ");
  if (tmp->valid == 1)
    {
      my_putstr("Size ");
      my_put_nbr(tmp->width);
      my_putchar('*');
      my_put_nbr(tmp->height);
      my_putstr(" : ");
      my_putstr("Color ");
      my_put_nbr(tmp->color);
      my_putstr(" :\n");
      a = 0;
      nb = 1;
      while (tmp->coord[a][0] != '\0')
	aff_shape(tmp, &nb, &a);
    }
  else
      my_putstr("Error\n");
}

/*
** Start the function debug
** Firstly, it display shortcuts
** Secondly, it goes into shape_list
*/
void		mode_debug(t_tetris *game, t_list list)
{
  t_tetriminos	*tmp;
  t_tetriminos	*tmp2;
  char		buff[10];
  int		nb;

  tmp = list.first;
  nb = 0;
  while (tmp)
   {
     nb++;
     tmp = tmp->next;
   }
  shortcuts(game, nb);
  tmp2 = list.first;
  tmp2 = sort_list(tmp2);
  while (tmp2)
    {
      shape_list(tmp2);
      tmp2 = tmp2->next;
    }
  mode(0, 0);
  my_putstr("Press a key to start Tetris\n");
  read(0, buff, 10);
  mode(1, 0);
}
