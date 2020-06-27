/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/27 14:03:55 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
///			 void ft_list_sort(t_list **begin_list, int (*cmp)());
////////


// modes :
#define SORTED 				0 	// produce sorted str
#define REVERSED_SORTED		1	// produce descending sorted str
#define RANDOM				3	// pur random shit
#define END_RANDOM			4	// produce long str with the same begining but the end is random
 
	static char charset_full[] = "!#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	static char charset[] = "0123456789";        

char *randstring_end_random_mode(char *str, int len)
{
	srand((int)str);
	memset(str, '_', len);
	for (int n = len - 2; n < len; n++)
	{            
		int key = rand() % (int)(sizeof(charset) - 1);
		str[n] = charset[key];
	}
	str[len] = '\0';
	return (str);
}
char *randstring_random_mode(char *str, int len)
{
	srand((int)str);
	for (int n = 0; n < len; n++)
	{            
		int key = rand() % (int)(sizeof(charset) - 1);
		str[n] = charset[key];
	}
	str[len] = '\0';
	return (str);
}

char *randstring_reversed_sorted_mode(char *str, int len)
{
	static int value;

	if (value == 0)
		value = strlen(charset_full) - 1;
	bzero(str, len);
	str[0] = charset_full[value];
	value--;
	return (str);
}

char *randstring_sorted_mode(char *str, int len)
{
	static int value;

	if (value == (int)strlen(charset_full))
		value = 0;
	bzero(str, len);
	str[0] = charset_full[value];
	value++;
	return (str);
}

char *test_randstring(int len, int mode)
{

    char *str = NULL;

    if (len != 0)
	{
	    str = calloc(sizeof(char), (len + 1));
  		if (str == NULL)
			return (NULL);
		if (mode == SORTED)
			return (randstring_sorted_mode(str, len));
		else if (mode == REVERSED_SORTED)
			return (randstring_reversed_sorted_mode(str, len));
		else if (mode == RANDOM)
			return (randstring_random_mode(str, len));
		else if (mode == END_RANDOM)
			return (randstring_end_random_mode(str, len));
    }
    return (NULL);
}

static int test(int nb_elem, int size_str, int mode)
{
	int error = 0;
	int size_list = 0;
	t_list *head = NULL;
	t_list *cursor;
	size_str = (size_str < 2) ? 2 : size_str;

	if (nb_elem <= 0)
		return (0);
	head = (t_list *)malloc(sizeof (t_list));
	if (head == NULL)
		return (6000);

	cursor = head;
	for (int i = 1; i <= nb_elem; i++)	
	{
		cursor->data = test_randstring(size_str, mode); 
		if (cursor->data == NULL)
			return (6000);
		if (i == nb_elem)
			cursor->next = NULL;
		else
		{
			cursor->next = (t_list *)malloc(sizeof (t_list));
			if (cursor->next == NULL)
				return (6000);
		}	
		cursor = cursor->next;
	}	
	cursor = head;
	printf(RED"BEFORE -----\n"RESET);
	printf("Head   Address {%p} -> {%p}\n", &head, head);
	printf("Cursor Address {%p}\n\n", cursor);
	for (int i = 0; cursor != NULL; i++)
	{
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = "GREEN"%s"DARK"\ncursor->next = %p\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
	}
	
	ft_list_sort(&head, strcmp);

	size_list = ft_list_size(head);
	printf(RED"\nAFTER -----\n"RESET);
	printf("Head   Address {%p} -> {%p}\n", &head, head);
	printf("Cursor Address {%p}\n\n", cursor);
	cursor = head;
	for (int i = 0; cursor != NULL; i++)
	{
		if (cursor->next != NULL && strcmp(cursor->data, cursor->next->data) > 0)
		{
			error++;
			printf(RED);
		}
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = "GREEN"%s"DARK"\ncursor->next = %p\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
	}

	if (error == 0 && size_list == nb_elem)
	{
		printf(GREEN);
		printf("\t[✅ PASSED]\n\n");
	}
	else
	{
		printf(RED);
		if (error != 0)
			printf("\t\a[⛔️ FAILED !] [%d] errors \n\n", error);
		if (size_list != nb_elem)
		{
			printf("\t\a[⛔️ FAILED !] Size of the list after function is different ! \n\t\tNb of elements before %d / after %d\n"DARK"(assuming the ft_list_size of the current libasm is fully functional)\n", nb_elem, size_list);
			error++;
		}
	}
	printf(RESET);

	return (error);
}


int test_ft_list_sort()
{
	int error = 0;

	error += test(6, 10, REVERSED_SORTED);
/*
	error += test(20, 10, SORTED);
	error += test(6, 10, RANDOM);
	error += test(6, 4, END_RANDOM);
*/
	if (error >= 6000)
	{
		printf("Some malloc went wrong, stopping test");
		exit (1);
	}
		
	if (error == 0)
	{
		printf(GREEN);
		printf("\n\n\t\t\t\tFinal for ft_list_sort [✅ PASSED]\n\n");
	}
	else
	{
		printf(RED);
		printf("\n\n\t\aFinal for ft_list_sort [⛔️ FAILED !] [%d]\n", error);
		error++;
	}
	printf(RESET);
	return (error);
}
