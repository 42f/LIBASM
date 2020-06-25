/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/25 10:43:30 by bvalette         ###   ########.fr       */
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
//    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
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
		value = INT_MAX;
	bzero(str, len);
	str = test_ft_itoa(value);
	value--;
	str[len] = '\0';
	return (str);
}

char *randstring_sorted_mode(char *str, int len)
{
	static int value;

	bzero(str, len);
	str = test_ft_itoa(value);
	value++;
	str[len] = '\0';
	return (str);
}

char *test_randstring(int len, int mode)
{

    char *str = NULL;

    if (len != 0)
	{
	    str = malloc(sizeof(char) * (len + 1));
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
//	int function_return = 0;

	t_list *head = NULL;

	if (nb_elem > 0)
	{
		head = (t_list *)malloc(sizeof (t_list));
		if (head == NULL)
			return (6000);

		t_list *cursor = head;
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
		printf("Head   Address {%p}\n", head);
		printf("Cursor Address {%p}\n\n", cursor);
		for (int i = 0; cursor != NULL; i++)
		{
			printf("[Elem #%2d]  %p\n", i, cursor);
			printf(DARK"cursor->data = "GREEN"%s"DARK"\ncursor->next = %p\n"RESET, cursor->data, cursor->next);
			cursor = cursor->next;
		}
	}
	
/*	function_return = ft_list_size(head);
	printf("\nTesting list lenght %d... ", nb_elem);
		
	if (function_return == nb_elem)
		{
			printf(GREEN);
			printf("\t[✅ PASSED] (returned %d)\n\n", function_return);
		}
		else
		{
			printf(RED);
			printf("\t\a[⛔️ FAILED !] Was expecting [%d] and got [%d] \n", nb_elem, function_return);
			error++;
		}
		printf(RESET);
*/
	return (error);
}


int test_ft_list_sort()
{
	int error = 0;
	int ret = 0;

	error += test(6, 10, SORTED);
	error += test(6, 10, REVERSED_SORTED);
	error += test(6, 10, RANDOM);
	error += test(6, 4, END_RANDOM);

	if (error >= 6000)
	{
		printf("Some malloc went wrong, stopping test");
		exit (1);
	}
		
	printf("Test with null data_ref pointer... Should not segfault");
	ret = ft_list_size(NULL);
	printf(GREEN"[✅ PASSED]\n"RESET);
	if (ret == 0)
	{
		printf(GREEN);
		printf("\t\t\t\t[✅ PASSED] (returned %d)\n\n", ret);
	}
	else
	{
		printf(RED);
		printf("\t\a[⛔️ FAILED !] Was expecting [0] and got [%d] \n", ret);
		error++;
	}
	printf(RESET);
	return (error);
}
