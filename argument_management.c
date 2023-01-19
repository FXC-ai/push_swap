#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int ft_is_number(char *arg)
{
    int i;

    i = 0;
    while (arg[i] != '\0')
    {   
        if (ft_isdigit(arg[i]) == 0)
        {
            return (0);
        }   
        i++;
    }
    return (1);
}

int ft_check_args_number(int arg_count, char **args)
{
    int i;
    char *test;

    i = 0;
    while (i < arg_count)
    {
        test = args[i];
        if (ft_is_number(args[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_is_int(long nbr)
{
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        return (0);
    }
    return (1);
}

int ft_check_args_int(int arg_count, long *args)
{
    int i;

    i = 0;
    while (i < arg_count)
    {
        if (ft_is_int(args[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_check_double(int arg_count, long *args)
{
    int i;
    int j;

    i = 0;
    while (i < arg_count)
    {
        j = i + 1;
        while (j < arg_count)
        {
            if (args[i] == args[j])
            {
                return (0);
            }
            j++;
        }   
        i++;
    }
    return (1);
}

static char **ft_set_args(int arg_count, char **arg)
{
    char    **tab;
    int     i;

    tab = (char **) malloc(sizeof(char *) * arg_count);
    i = 0;
    while (i < arg_count)
    {
        tab[i] = arg[i + 1];
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

static void	ft_free_tabs(char **tab, int h)
{
	int	i;

	i = 0;
	while (i <= h)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int ft_tablen(char **tab)
{
    int count;

    count = 0;
    while (tab[count] != NULL)
    {
        count++;
    }
    return (count);
}

static long  *ft_create_tab_long(int arg_count, char **tab)
{
    int i;
    long *tab_long;

    tab_long = (long *) malloc(sizeof(long) * arg_count);
    i = 0;
    while (i < arg_count)
    {
        tab_long[i] = ft_atoi(tab[i]);
        i++;
    }
    /*
    int count = 0;
    while (count < i)
    {
        printf("tab_long = %ld\n", tab_long[count]);
        count++;
    }
    */
    printf("\n\n");
    return  tab_long;
}




int main(int argc, char *argv[])
{

    ft_printf("\n\n----------------DISPLAY BEGIN----------------\n\n");

    int         arg_count = argc;
    char        **arg = argv;
    int         i;
    char        **tab;
    int         tablen;
    long        *tab_long;

    arg_count = argc - 1;
    arg = argv;
    ft_printf("arg_count = %d \nargc = %d\n\n\n", arg_count, argc);


    if (arg_count == 0)
    {
        ft_printf("Error\n");
        return (1);
    }
    else if (arg_count == 1)
    {
        tab = ft_split(arg[1], ' ');
        tablen = ft_tablen(tab);
        if (ft_check_args_number(tablen, tab) == 0)
        {
            ft_printf("Error\n");
        }
        else
        {
            tab_long = ft_create_tab_long(tablen, tab);
            if (ft_check_args_int(tablen, tab_long) == 0)
            {
                ft_printf("Error\n");
            }
            if (ft_check_double(tablen, tab_long))
            {
                ft_printf("Error\n");
            }
            
        }




        /*
        else if (ft_check_args_int(tablen, tab) == 0)
        {
            ft_printf("Error\n");
        }*/
        ft_free_tabs(tab, tablen);
        //free (tab_long);
    }
    else
    {
        tab = ft_set_args(arg_count, arg);
        if (ft_check_args_number(arg_count, tab) == 0)
        {
            ft_printf("Error\n");
        }
        else
        {
            tab_long = ft_create_tab_long(arg_count, tab);
            if (ft_check_args_int(arg_count, tab_long) == 0)
            {
                ft_printf("Error\n");
            }
        }

        

        /*
        else if (ft_check_args_int(tablen, tab) == 0)
        {
            ft_printf("Error\n");
        }*/
        free(tab);
        //free (tab_long);
    }
    
    i = 0;
    while (tab[i] != NULL)
    {
        printf("Arg n %d : %s\n", i, tab[i]);
        i++;
    }
    
    ft_printf("\n\n----------------DISPLAY   END----------------\n\n");
    return 0;
}
