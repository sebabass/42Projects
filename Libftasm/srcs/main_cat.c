/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 18:38:04 by spariaud          #+#    #+#             */
/*   Updated: 2015/05/18 18:38:47 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int 	main(int ac, char ** av)
{
	(void)ac;
	(void)av;
    if (ac == 1) 
	{
        ft_cat(0);
		ft_cat(open(__FILE__, O_RDONLY));
	}
    else if (ac == 2) 
	{
		ft_cat(open(__FILE__, O_RDONLY));
		ft_cat(open("test", O_RDONLY));
		ft_cat(-42);
        int fd = open(av[1], O_RDONLY);
        ft_cat(fd);
        if (fd != -1) 
            close(fd);
		else 
            printf("error\n");
    }
    else 
        printf("usage: %s [file]\n", av[0]);
    return (0);
}
