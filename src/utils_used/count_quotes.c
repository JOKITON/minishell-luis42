/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:59:38 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/17 11:59:40 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//#include <stdio.h>

int look_quote(char *line, int i, int *num_prev, int num)
{
	int j;
	
	j = i + 1;
	*num_prev += 1;
	while(line[j] && line[j] != num)
	{
		j++;
	}
	if(line[j] == num)
	{
		*num_prev += 1;
	}
	return (j - i);
}

int quote_count(char *line)
{
	int qs;
	int qd;
	int j;

	qs = 0;
	qd = 0;
	j = 0;
	while(line[j])
	{
		if(line[j] == '\"')
		{
			
			j += look_quote(line, j, &qd, '\"');
		}
		if(line[j] == '\'')
		{
		
			j += look_quote(line, j, &qs, '\'');
		}
		j++;
	}
	printf("qd %d qs %d\n", qd, qs);
	if((qs > 0 && qs % 2 != 0) || (qd > 0 && qd % 2 != 0))
	{
		return(0);
	}
	return(1);
}
/*
int main()
{
    // Test examples
    char line1[] = "This is a 'test' line";
    char line2[] = "This is a \"test\" line";
    char line3[] = "This is a 'test line";
    char line4[] = "This is a test line";

    printf("Result for line1: %d\n", tokens_count(line1));  // Expected 1
    printf("Result for line2: %d\n", tokens_count(line2));  // Expected 1
    printf("Result for line3: %d\n", tokens_count(line3));  // Expected 0
    printf("Result for line4: %d\n", tokens_count(line4));  // Expected 1
}
*/
