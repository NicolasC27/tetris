/*
** debug.c for debug.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 17:22:19 2016 Chevalier Nicolas
** Last update Mon Mar 14 18:40:44 2016 Chevalier Nicolas
*/

#include	<stdlib.h>
#include	"tetris.h"

/*
** Display shortcuts
*/
void		shortcuts(t_tetris *game)
{
  my_putstr(DEBUG);
  my_putstr("Key Left : ");
  my_putstr(game->keys->key_left);
  my_putstr("\nKey Right : ");
  my_putstr(game->keys->key_right);
  my_putstr("\nKey Turn : ");
  my_putstr(game->keys->key_turn);
  my_putstr("\nKey Drop : ");
  my_putstr(game->keys->key_drop);
  my_putstr("\nKey Quit : ");
  my_putstr(game->keys->key_quit);
  my_putstr("\nKey Pause : ");
  my_putstr(game->keys->key_pause);
  my_putstr("\nNext : ");
  my_putstr((game->scene->boolnext) ? "Yes" : "No");
  my_putstr("\nLevel : ");
  my_put_nbr(game->scene->level);
  my_putstr("\nSize : ");
  my_put_nbr(game->scene->rows);
  my_putstr("*");
  my_put_nbr(game->scene->colums);
}

/*
** Calcul width line for display
*/
int		width_line(int **tab, int a, int nb)
{
  int		i;
  int		y;

  i = 0;
  a = 0;
  while (tab[a][0] != '\0' && tab[a][0] == nb)
    a++;
  return (tab[a - 1][1]);
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
  my_putstr("Size ");
  my_put_nbr(tmp->width);
  my_putchar('*');
  my_put_nbr(tmp->width);
  my_putstr(" : ");
  my_putstr("Color ");
  my_put_nbr(tmp->color);
  my_putstr(" :\n");
  a = 0;
  nb = 1;
  while (tmp->coord[a][0] != '\0')
    aff_shape(tmp, &nb, &a);
}

/*
** Start the function debug
** Firstly, it display shortcuts
** Secondly, it goes into shape_list
*/
void		mode_debug(t_tetris *game, t_list *list)
{
  t_tetriminos	*tmp;
  int		i;
  int		nb;

  tmp = list->first;
  i = 0;
  nb = 0;
  while (tmp)
   {
     nb++;
     tmp = tmp->next;
   }
  shortcuts(game);
  tmp = list->first;
  my_putstr("\nTetriminos : ");
  my_put_nbr(nb);
  my_putchar('\n');
  while (tmp)
    {
      shape_list(tmp);
      tmp = tmp->next;
    };
  exit (0);
}
