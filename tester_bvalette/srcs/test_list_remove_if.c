/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/24 09:46:50 by bvalette         ###   ########.fr       */
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

static int test_list(char *str_ref, char *str_0, char *str_1, char *str_2, char *str_3)
{
	int error = 0;
	char *str_test[] = {str_0, str_1, str_2, str_3};
	int nb_to_del = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (strcmp(str_ref, str_test[i]) == 0)
			nb_to_del++;
	}

	t_list *head = NULL;
	
	head = (t_list *)malloc(sizeof (t_list));
	if (head == NULL)
		return (1);
	head->data = strdup(str_0);
	if (head->data == NULL)
		return (1);
	head->next = NULL;

	head->next = (t_list *)malloc(sizeof (t_list));
	if (head->next == NULL)
		return (1);
	head->next->data = strdup(str_1);
	if (head->next->data == NULL)
		return (1);
	head->next->next = NULL;

	head->next->next = (t_list *)malloc(sizeof (t_list));
	if (head->next->next == NULL)
		return (1);
	head->next->next->data = strdup(str_2);
	if (head->next->next->data == NULL)
		return (1);
	head->next->next->next = NULL;

	head->next->next->next = (t_list *)malloc(sizeof (t_list));
	if (head->next->next->next == NULL)
		return (1);
	head->next->next->next->data = strdup(str_3);
	if (head->next->next->next->data == NULL)
		return (1);
	head->next->next->next->next = NULL;

	t_list *cursor = head;

	printf(GREEN"BEFORE\n"RESET);
	printf("Head   Address {%p}\n", head);
	printf("Cursor Address {%p}\n\n", cursor);
	for (int i = 0; cursor != NULL; i++)
	{
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = "GREEN"%s"DARK"\ncursor->next = %p\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
	}

	ft_list_remove_if(&head, "DELETE", strcmp, free_fct);	
	
	cursor = head;

	printf(GREEN"AFTER\n"RESET);
	printf("Head   Address {%p}\n", head);
	printf("Cursor Address {%p}\n\n", cursor);

	int i = 0;
	while (cursor != NULL)
	{
		if (strcmp(cursor->data, str_ref) == 0)
		{
			printf(RED);
			printf("\t[⛔️] \n");
			error++;
		}
		printf("[Elem #%2d]  %p\n", i, cursor);
		printf(DARK"cursor->data = "GREEN"%s"DARK"\ncursor->next = %p\n"RESET, cursor->data, cursor->next);
		cursor = cursor->next;
		i++;
	}

	if (error == 0 && i == (4 - nb_to_del))
	{
		printf(GREEN);
		printf("\n\t\t[✅ PASSED] \n");
	}
	else if (i <= (4 - nb_to_del))
	{
		printf(RED);
		printf("\n\t\t[⛔️ FAILED ! missing %d elements] \n", 4 - (nb_to_del));
		error++;
	}
	else
	{
		printf(RED);
		printf("\n\t\t[⛔️ FAILED ! %d element(s) still in the list] \n", error);
		error++;
	}
	printf(RESET);
	return (error);
}


int test_ft_list_remove_if()
{
	int error = 0;

	error += test_list("DELETE", "1_OK", "DELETE", "DELETE", "DELETE");
	error += test_list("DELETE", "1_OK", "DELETE", "2_OK", "DELETE");
	error += test_list("DELETE", "1_OK", "DELETE", "DELETE", "2_OK");
	error += test_list("DELETE", "DELETE", "1_OK", "2_OK", "3_OK");
	error += test_list("DELETE", "1_OK", "2_OK", "3_OK", "4_OK");
	error += test_list("DELETE", "1_OK", "DELETE", "2_OK", "3_OK");
	error += test_list("DELETE", "1_OK", "2_OK", "DELETE", "3_OK");

	return (error);
}
