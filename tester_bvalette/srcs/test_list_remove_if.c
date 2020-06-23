/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/23 08:56:53 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"


void free_fct(void *ptr)
{

	free(ptr);
	
}

/////////
// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)	
////////

int test_ft_list_remove_if()
{
	int error = 0;

	t_list *head = NULL;
	
	head = (t_list *)malloc(sizeof (t_list));
	if (head == NULL)
		return (1);
	head->data = strdup("KEEP_00");

	head->next = (t_list *)malloc(sizeof (t_list));
	if (head->next == NULL)
		return (1);
	head->next->data = strdup("DELETE");

	head->next->next = (t_list *)malloc(sizeof (t_list));
	if (head->next->next == NULL)
		return (1);
	head->next->next->data = strdup("KEEP_02");

	head->next->next->next = (t_list *)malloc(sizeof (t_list));
	if (head->next->next->next == NULL)
		return (1);
	head->next->next->next->data = strdup("DELETE");

	t_list *cursor = head;
	printf(GREEN"BEFORE\n"RESET);
	printf("Head   Address {%p}\n", head);
	printf("Cursor Address {%p}\n\n", cursor);
	for (int i = 0; cursor != NULL; i++)
	{
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = %s\ncursor->next = %p\n\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
	}

	ft_list_remove_if(&head, "DELETE", strcmp, free_fct);	

	cursor = head;
	printf(GREEN"AFTER\n"RESET);
	printf("Head   Address {%p}\n", head);
	printf("Cursor Address {%p}\n\n", cursor);
	for (int i = 0; cursor != NULL; i++)
	{
		if (strcmp(cursor->data, "DELETE") == 0)
		{
			error++;
			printf(RED);
			printf("\t[⛔️] \n");
		}
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = %s\ncursor->next = %p\n\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
	}

	if (error == 0)
	{
		printf(GREEN);
		printf("\n\t\t[✅ PASSED] \n");
	}
	else
	{
		printf(RED);
		printf("\n\t\t[⛔️ FAILED ! %d elements are still in the list] \n", error);
	}
	printf(RESET);
	return (error);
}

