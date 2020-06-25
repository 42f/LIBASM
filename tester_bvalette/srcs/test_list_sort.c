/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/25 09:28:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
///			 void ft_list_sort(t_list **begin_list, int (*cmp)());
////////

char *randstring(int length) {

//    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    static char charset[] = "0123456789";        
    char *randomString = NULL;

    if (length != 0)
	{
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString != NULL)
		{            
			srand((int)randomString);
            for (int n = 0; n < length; n++)
			{            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }

    return randomString;
}

static int test(int nb_elem, int size_str)
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
			cursor->data = randstring(size_str); 
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

	error += test(6, 10);
	error += test(6, 50);
	error += test(10, 5);

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
