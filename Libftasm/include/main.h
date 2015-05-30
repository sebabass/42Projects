/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:57:53 by spariaud          #+#    #+#             */
/*   Updated: 2015/05/18 18:45:20 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define		result_ok() printf("\033[32m[√]\033[0m\n")
# define		result_ko() printf("\033[31m[X]\033[0m\n")
# define		ALPHA_LOW	"abcdefghijklmnopqrstuvwxyz"
# define		ALPHA_UPP	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define		DIGITAL		"0123456789"

// Fonctions de test.
int				test_ft_bzero();
int				test_ft_strcat();
int				test_ft_isalpha();
int				test_ft_isdigit();
int				test_ft_isalnum();
int				test_ft_isascii();
int				test_ft_isprint();
int				test_ft_toupper();
int				test_ft_tolower();
int				test_ft_puts();
int				test_ft_strlen();
int				test_ft_memset();
int				test_ft_memcpy();
int				test_ft_strdup();
int				test_ft_isblank(); 	// Bonus
int				test_ft_isspace(); 	// Bonus
int				test_ft_isupper(); 	// Bonus
int				test_ft_islower(); 	// Bonus
int				test_ft_ispunct(); 	// Bonus
int				test_ft_strchr();	// Bonus

// Fonction ASM.
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_puts(const char *s);
int				ft_puterror(const char *s);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
void			ft_cat(int fd);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c); // Bonus
int				ft_isblank(int c); // Bonus
int				ft_isspace(int c); // Bonus
int				ft_isupper(int c); // Bonus
int				ft_islower(int c); // Bonus
int				ft_ispunct(int c); // Bonus

#endif
