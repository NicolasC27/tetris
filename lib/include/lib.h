/*
** lib.h for lib.h in /home/cheval_8/PSU_2015_minitalk/lib/include
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Feb 18 20:07:00 2016 Chevalier Nicolas
// Last update Mon Feb 29 23:48:54 2016 Chevalier Nicolas
*/

#ifndef LIB_H_
# define LIB_H_

/*
** Includes
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Defines
*/
# define TRUE		1
# define FALSE		0
# define BLACK		"\033[0;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GREY		"\033[0;37m"
# define DEFAULT	"\033[0;m"

/*
** write.c
*/
int		my_write(char *, char *);
int		my_write_nb(int, char *);

/*
** my_getnbr.c
*/
int		my_getnbr(char *);

/*
** my_putchar.c
*/
void		my_putchar(char);

/*
** my_put_nbr.c
*/
int		my_put_nbr(int);

/*
** my_putstr.c
*/
int		my_putstr(char *);

/*
** my_strlen.c
*/
int		my_strlen(char *);

/*
** my_realloc.c
*/
char		*my_realloc(char *, int);

/*
** my_memset.c
*/
void		*my_memset(void *, int, int);

/*
** concat.c
*/
char		*concat(char *, char *);

#endif /* !LIB_H_ */
