/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:56:31 by spariaud          #+#    #+#             */
/*   Updated: 2015/05/18 18:30:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(void)
{
	test_ft_bzero();
	test_ft_strcat();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_puts();
	test_ft_strlen();
	test_ft_memset();
	test_ft_memcpy();
	test_ft_strdup();
	test_ft_isblank(); 	// Bonus
	test_ft_isspace();	// Bonus
	test_ft_isupper(); 	// Bonus
	test_ft_islower();	// Bonus
	test_ft_ispunct();	// Bonus
	test_ft_strchr();	// Bonus
	return (0);
}

int		test_ft_isalpha()
{
	char	*str;
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISALPHA *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check a-z                --> ");
	error = 0;
	i = 0;
	while (ALPHA_LOW[i])
	{
		if (ft_isalpha(ALPHA_LOW[i]) && ft_isalpha(ALPHA_LOW[i]) == isalpha(ALPHA_LOW[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}

	// TEST 2
	if (!error)
		result_ok();
	printf("Test 2: check A-Z                --> ");
	error = 0;
	i = 0;
	while (ALPHA_UPP[i])
	{
		if (ft_isalpha(ALPHA_UPP[i]) && ft_isalpha(ALPHA_UPP[i]) == isalpha(ALPHA_UPP[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 3
	printf("Test 3: check no alpha           --> ");
	str = "0123456789/.,;' \t=)(&{][}$#!.><?";
	i = 0;
	error = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && ft_isalpha(str[i]) == isalpha(str[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isdigit()
{
	int		error;
	char	*str;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISDIGIT *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-9                --> ");
	error = 0;
	i = 0;
	while (DIGITAL[i])
	{
		if (ft_isdigit(DIGITAL[i]) && ft_isdigit(DIGITAL[i]) == isdigit(DIGITAL[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 2
	printf("Test 2: check no digit           --> ");
	str = "abcdefghijklmnuvwxyzABCDEFGHIJKLMNOPQRSTUZ.,;' \t=)(&{][}$#!.><?";
	i = 0;
	error = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && ft_isdigit(str[i]) == isdigit(str[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isalnum()
{
	int		error;
	char	*str;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISALNUM *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-9                --> ");
	error = 0;
	i = 0;
	while (DIGITAL[i])
	{
		if (ft_isdigit(DIGITAL[i]) && ft_isdigit(DIGITAL[i]) == isdigit(DIGITAL[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 2
	printf("Test 2: check a-z                --> ");
	error = 0;
	i = 0;
	while (ALPHA_LOW[i])
	{
		if (ft_isalpha(ALPHA_LOW[i]) && ft_isalpha(ALPHA_LOW[i]) == isalpha(ALPHA_LOW[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 3
	printf("Test 3: check A-Z                --> ");
	error = 0;
	i = 0;
	while (ALPHA_UPP[i])
	{
		if (ft_isalpha(ALPHA_UPP[i]) && ft_isalpha(ALPHA_UPP[i]) == isalpha(ALPHA_UPP[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 4
	printf("Test 4: check no alnum           --> ");
	str = "^μ%	 .,;' \t=)(&{][}$è_-~#!.@><?";
	i = 0;
	error = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && ft_isdigit(str[i]) == isdigit(str[i]))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isascii()
{
	int		i;
	int		error;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISASCII *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check ascii              --> ");
	i = 0;
	error = 0;
	while (i < 128)
	{
		if (ft_isascii(i) && ft_isascii(i) == isascii(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 2
	printf("Test 1: check no ascii neg       --> ");
	i = -128;
	error = 0;
	while (i < 0)
	{
		if (!ft_isascii(i) && ft_isascii(i) == isascii(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 3
	printf("Test 3: check no ascii pos       --> ");
	i = 128;
	error = 0;
	while (i < 256)
	{
		if (!ft_isascii(i) && ft_isascii(i) == isascii(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isprint()
{
	int		i;
	int		error;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISPRINT *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check print              --> ");
	i = 32;
	error = 0;
	while (i < 127)
	{
		if (ft_isascii(i) && ft_isascii(i) == isascii(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 2
	printf("Test 1: check no print neg,31    --> ");
	i = -128;
	error = 0;
	while (i < 31)
	{
		if (!ft_isprint(i) && ft_isprint(i) == isprint(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	// TEST 3
	printf("Test 3: check no print,+         --> ");
	i = 127;
	error = 0;
	while (i < 256)
	{
		if (!ft_isprint(i) && ft_isprint(i) == isprint(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_toupper()
{
	int		i;
	int		error;
	char	c;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_TOUPPER *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_toupper(i) == toupper(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_tolower()
{
	int		i;
	int		error;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_TOLOWER *************\n");
	printf("--------------------------------------------\n\n");
	
	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_tolower(i) == tolower(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);

}

int		test_ft_bzero()
{
	char	t1str1[] = "";
	char	t1str2[] = "";
	char	t2str1[] = "123456789";
	char	t2str2[] = "123456789";
	char	t3str1[] = "123456789";
	char	t3str2[] = "123456789";

	printf("--------------------------------------------\n");
	printf("*************** TEST FT_BZERO **************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check empty              --> ");
	
	ft_bzero(t1str1, 0);
	bzero(t1str2, 0);
	if (strcmp(t1str1, t1str2) == 0)
		result_ok();
	else
		result_ko();

	// TEST 2
	printf("Test 2: check complete string    --> ");
	
	bzero(t2str1, 10);
	bzero(t2str2, 10);
	if (strcmp(t2str1, t2str2) == 0)
		result_ok();
	else
		result_ko();

	// TEST 3
	printf("Test 3: check no complete string --> ");
	
	bzero(t3str1, 3);
	bzero(t3str2, 3);
	if (strcmp(t3str1, t3str2) == 0)
		result_ok();
	else
		result_ko();

	return (1);
}

int		test_ft_strcat(char *s1, const char *s2)
{
	char	str1[100] = "";

	bzero(str1, 100);
	printf("--------------------------------------------\n");
	printf("*************** TEST FT_STRCAT *************\n");
	printf("--------------------------------------------\n\n");


	// TEST 1
	printf("Test 1: empty                    --> ");
	if (strcmp(ft_strcat(str1, ""), "") == 0)
		result_ok();
	else
		result_ko();

	// TEST 2
	printf("Test 2: Bonjour                  --> ");
	if (strcmp(ft_strcat(str1, "Bonjour"), "Bonjour") == 0)
		result_ok();
	else
		result_ko();

	// TEST 3
	printf("Test 3: Test2 + les gens!        --> ");
	if (strcmp(ft_strcat(str1, " les gens!"), "Bonjour les gens!") == 0)
		result_ok();
	else
		result_ko();

	return (1);
}

int		test_ft_strlen()
{
	printf("--------------------------------------------\n");
	printf("*************** TEST FT_STRLEN *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: empty                    --> ");
	if (ft_strlen("") == 0 && ft_strlen("") == strlen(""))
		result_ok();
	else
		result_ko();

	// TEST 2
	printf("Test 2: Digit 10                 --> ");
	if (ft_strlen(DIGITAL) == 10 && ft_strlen(DIGITAL) == strlen(DIGITAL))
		result_ok();
	else
		result_ko();

	// TEST 2
	printf("Test 3: Alpha 26                 --> ");
	if (ft_strlen(ALPHA_LOW) == 26 && ft_strlen(ALPHA_LOW) == strlen(ALPHA_LOW))
		result_ok();
	else
		result_ko();

	return (1);
}

int		test_ft_memset()
{
	char	b1[100];
	char	b2[100];
	int		i;

	printf("--------------------------------------------\n");
	printf("*************** TEST FT_MEMSET *************\n");
	printf("--------------------------------------------\n\n");

	// Test1
	printf("Test 1: zero                     --> ");
	ft_memset(b1, 'z', 0);
	if (b1[0] != 'z')
		result_ok();
	else
		result_ko();

	// Test2
	i = 0;
	printf("Test 2: 100-a                    --> ");
	ft_memset(b1, 'a', 100);
	memset(b2, 'a', 100);
	while (i < 100)
	{
		if (b1[i] == 'a' && b1[i] == b2[i])
			i++;
		else
		{
			result_ko();
			return (0);
		}
	}
	result_ok();
	return (1);
}

int		test_ft_puts()
{
	printf("--------------------------------------------\n");
	printf("**************** TEST FT_PUTS **************\n");
	printf("--------------------------------------------\n\n");

	// Test1
	printf("Test 1: empty                    --> ");
	if (ft_puts("") == puts(""))
		result_ok();
	else
		result_ko();
	

	// Test2
	printf("Test 2: digit                    --> ");
	if (ft_puts(DIGITAL) == puts(DIGITAL))
		result_ok();
	else
		result_ko();
	

	// Test3
	printf("Test 3: alpha                    --> ");
	if (ft_puts(ALPHA_LOW) == puts(ALPHA_LOW))
		result_ok();
	else
	result_ko();

	return (1);
}

int		test_ft_memcpy()
{
	char	b1[100];
	char	b2[100];
	char	b3[100];

	printf("--------------------------------------------\n");
	printf("*************** TEST FT_MEMCPY *************\n");
	printf("--------------------------------------------\n\n");

	// Test1
	printf("Test 1: Simple                   --> ");
	memset(b1, 'a', 100);
	memset(b2, 'z', 100);
	if (ft_memcpy(b1, b2, 100) == memcpy(b1, b2, 0))
		result_ok();
	else
		result_ko();

	return (1);
}

int		test_ft_strdup()
{
	char	t1[100] = "";
	char	t2[100] = "Bonjour les gens";

	printf("--------------------------------------------\n");
	printf("*************** TEST FT_STRDUP *************\n");
	printf("--------------------------------------------\n\n");

	// Test1
	printf("Test 1: Empty                    --> ");
	if (strcmp(ft_strdup(t1), strdup(t1)) == 0)
		result_ok();
	else
		result_ko();

	// Test2
	printf("Test 2: Simple                   --> ");
	if (strcmp(ft_strdup(t2), strdup(t2)) == 0)
		result_ok();
	else
		result_ko();
	return (1);
}

int		test_ft_isblank()
{
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISBLANK *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_isblank(i) == isblank(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isspace()
{
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISSPACE *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_isspace(i) == isspace(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_isupper()
{
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISUPPER *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_isupper(i) == isupper(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_islower()
{
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISLOWER *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_islower(i) == islower(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_ispunct()
{
	int		error;
	int		i;

	printf("--------------------------------------------\n");
	printf("************** TEST FT_ISPUNCT *************\n");
	printf("--------------------------------------------\n\n");

	// TEST 1
	printf("Test 1: check 0-255              --> ");
	i = 0;
	error = 0;
	while (i < 256)
	{
		if (ft_ispunct(i) == ispunct(i))
			i++;
		else
		{
			result_ko();
			error = 1;
			break;
		}
	}
	if (!error)
		result_ok();

	return (1);
}

int		test_ft_strchr()
{
	char	test1[10] = "toto";
	char	test2[10] = "tata";
	char	test3[50] = "test un peu nul";
	char	test4[50] = "$^ rwss \n Test";
	char	test5[50] = "@voila la +_ petite";
	char	test6[50] = "";

	printf("--------------------------------------------\n");
	printf("*************** TEST FT_STRCHR *************\n");
	printf("--------------------------------------------\n\n");

	// Test 1
	printf("Test 1:                          --> ");
	if (strcmp(ft_strchr(test1, 'o'), strchr(test1, 'o')) != 0)
		result_ko();
	else
		result_ok();
	// Test 2
	printf("Test 2:                          --> ");
	if (ft_strchr(test2, '1') != NULL)
		result_ko();
	else
		result_ok();
	// Test 3
	printf("Test 3:                          --> ");
	if (strcmp(ft_strchr(test3, 'l'), strchr(test3, 'l')) != 0)
		result_ko();
	else
		result_ok();
	// Test 4
	printf("Test 4:                          --> ");
	if (strcmp(ft_strchr(test4, 'T'), strchr(test4, 'T')) != 0)
		result_ko();
	else
		result_ok();
	// Test 5
	printf("Test 5:                          --> ");
	if (ft_strchr(test5, 'x') != NULL)
		result_ko();
	else
		result_ok();
	// Test 6
	printf("Test 6:                          --> ");
	if (ft_strchr(test6, '1') != NULL)
		result_ko();
	else
		result_ok();
	return (1);
}
