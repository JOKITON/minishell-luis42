/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:44:18 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/16 09:44:22 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_sub(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	sub_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*copy_sub(const char *start, int len)
{
	char	*sub;
	int		i;

	sub = (char *)malloc(len + 1);
	i = 0;
	if (sub)
	{
		while (i < len)
		{
			sub[i] = start[i];
			i++;
		}
		sub[len] = '\0';
	}
	return (sub);
}

static void	free_all(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc((count_sub(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = copy_sub(s, sub_len(s, c));
			if (!res[i])
			{
				free_all(res, i);
				return (NULL);
			}
			i++;
			s += sub_len(s, c);
		}
	}
	res[i] = NULL;
	return (res);
}
/*
void print_result(char **result) 
{
    if (result == NULL) 
    {
        printf("NULL\n");
        return;
    }
    for (int i = 0; result[i] != NULL; i++) {
        printf("\"%s\"\n", result[i]);
    }
    printf("NULL\n");
}

int	main() 
{
    char *s;
    char c;
    char **result;

    // Test Case 1: Normal case
    s = "hello,world,this,is,a,test";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 1:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test Case 2: Single delimiter
    s = "one,two,three";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 2:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test Case 3: No delimiters
    s = "abcdef";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 3:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test Case 4: Empty string
    s = "";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 4:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test Case 5: Delimiter at the start/end
    s = ",leading,comma,";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 5:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    // Test Case 6: Consecutive delimiters
    s = "one,,three";
    c = ',';
    result = ft_split(s, c);
    printf("Test Case 6:\n");
    print_result(result);
    // Free the result
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    return 0;
}
*/
