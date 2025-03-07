/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:30:08 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/13 13:30:10 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	all;
	void	*ptr;

	all = nmemb * size;
	ptr = malloc(all);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, all);
	return (ptr);
}
/*
int main(void)
{
    size_t num_elements = 5;
    size_t element_size = sizeof(int);

    // Allocate memory using the custom ft_calloc function
    int *arr = (int *)ft_calloc(num_elements, element_size);

    if (arr == NULL) {
        perror("Failed to allocate memory");
        return 1; // Exit with error code
    }

    // Print the allocated memory values
    printf("Memory allocated and initialized to zero:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Modify the allocated memory
    for (size_t i = 0; i < num_elements; i++) {
        arr[i] = i + 1;
    }

    // Print the modified values
    printf("\nModified memory values:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);
    int *arr1 = (int *)calloc(num_elements, element_size);

    if (arr1 == NULL) {
        perror("Failed to allocate memory");
        return 1; // Exit with error code
    }

    // Print the allocated memory values
    printf("Memory allocated and initialized to zero:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr1[%zu] = %d\n", i, arr1[i]);
    }

    // Modify the allocated memory
    for (size_t i = 0; i < num_elements; i++) {
        arr1[i] = i + 1;
    }

    // Print the modified values
    printf("\nModified memory values:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr1[%zu] = %d\n", i, arr1[i]);
    }

    // Free the allocated memory
    free(arr1);

    return 0;
}
*/
