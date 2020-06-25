/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/25 08:35:59 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
///		int ft_list_size(t_list *begin_list);
////////

static int test(int nb)
{
	int error = 0;
	int function_return = 0;

	t_list *head = NULL;

	if (nb > 0)
	{
		head = (t_list *)malloc(sizeof (t_list));
		if (head == NULL)
			return (6000);

		t_list *cursor = head;
		char *str_data = (char*)calloc(sizeof(char), 50);
		for (int i = 1; i <= nb; i++)	
		{
			strcat(str_data, test_ft_itoa(i));
			cursor->data = strdup(str_data); 
			if (i == nb)
				cursor->next = NULL;
			else
				cursor->next = (t_list *)malloc(sizeof (t_list));
			if (head == NULL)
				return (6000);
			bzero(str_data, sizeof (char) * 50);	
			
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
	
	function_return = ft_list_size(head);
	printf("\nTesting list lenght %d... ", nb);
		
	if (function_return == nb)
		{
			printf(GREEN);
			printf("\t[✅ PASSED] (returned %d)\n\n", function_return);
		}
		else
		{
			printf(RED);
			printf("\t\a[⛔️ FAILED !] Was expecting [%d] and got [%d] \n", nb, function_return);
			error++;
		}
		printf(RESET);

	return (error);
}


int test_ft_list_size()
{
	int error = 0;
	int ret = 0;

	error += test(42);
	error += test(6);
	error += test(1);
	error += test(0);

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
