/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/26 18:35:24 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_check_number(char *str)
{
    int i;

    i = 0;
    if ((str[i] == '+' && ft_isdigit(str[i+1]) == 1) || (str[i] == '-' && ft_isdigit(str[i+1]) == 1))
        i++;
    else
        return (0);

    while (str[i] != '\0')
    {
        printf("%c\n", str[i]);
        if (ft_isdigit(str[i]) == 0)
        {
            return (0);
        }
        
        i++;
    }
    return (1);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*result;
	size_t	i;
	size_t	c;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		result[i] = s1[i];
		i++;
	}
	c = 0;
	while (c < size_s2)
	{
		result[i++] = s2[c++];
	}
	result[i] = '\0';
	return (result);
}
*/


char    *ft_join_args(int argc, char *argv[])
{
    (void) argc;
    int i;
    char *result;
    char *temp;

    i = 1;
    result = ft_strdup(argv[1]);
    while (i < (argc - 1))
    {   
        temp = ft_strdup(result);
        free(result);
        result = ft_strjoin(temp, " ");
        free(temp);
        temp = ft_strdup(result);
        free(result);
        i++;
        result = ft_strjoin(temp, argv[i]);
        free(temp);
    }
    
    return (result);

}


int main(int argc, char *argv[])
{
    char    **tab_char;
    int     tablen;
    int     i;
    char    *args;

    args = NULL;
    tablen = argc - 1;
    if (argc == 1)
        return (0);
    else if (argc == 2)
        args = ft_strdup(argv[1]);
    else
        args = ft_join_args(argc , argv);

    printf("s = %s\n", args);
    
    tab_char = ft_split(args, ' ');
    free(args);

    i = 0;
    while (tab_char[i] != NULL)
    {
        printf("%d : %s\n", i, tab_char[i]);
        i++;
    }
    
        
    
    


    return (0);
}
