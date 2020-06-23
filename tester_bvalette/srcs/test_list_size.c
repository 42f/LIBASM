/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/23 08:22:15 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// 			 void	ft_list_push_front(t_list **begin_list, void *data);
////////

int test_ft_list_size()
{
	int error = 0;
	char *new_str = "hello";

	t_list *head = NULL;
	
	head = (t_list *)malloc(sizeof (t_list));
	if (head == NULL)
		return (1);
	head->data = "bye";
	head->next = NULL;
	printf(GREEN"BEFORE\n"RESET);
	printf("Head Address {%p}\n\n", head);
	printf("head->data = %s\nhead->next = %p\n\n", head->data, head->next);
	
	ft_list_push_front(&head, new_str);

	printf(GREEN"AFTER\n"RESET);
	printf("Head Address {%p}\n\n", head);
	printf("head->data = %s\nhead->next = %p\n\n", head->data, head->next);
	printf("head->->next->data = %s\nhead->next->next = %p\n", head->next->data, head->next->next);

		
	if (head->next != NULL && strcmp(head->data, new_str) == 0
		&& head->next->next == NULL && strcmp(head->next->data, "bye") == 0)
		{
			printf(GREEN);
			printf("\n\t\t[✅ PASSED] \n");
		}
		else
		{
			printf(RED);
			printf("\n\t\t[⛔️ FAILED !] \n");
			error++;
		}
		printf(RESET);
	return (error);
}

