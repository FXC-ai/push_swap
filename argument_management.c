#include "push_swap.h"



int ft_check_double(int arg_count, int *args)
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
                ft_printf("\n\nNON !!!\n\n");
                return (0);
            }
            j++;
        }   
        i++;
    }
    ft_printf("\n\nOUI !!!\n\n");
    return (1);
}



int main(int argc, char const *argv[])
{
    int arg_count = argc;
    char const **arg = argv;
    int i;

    arg_count = argc;
    arg = argv;
    i = 0;
    while (i < arg_count)
    {
        if (i == 0)
        {
            ft_printf("Arg n 0 : %s\n", arg[0]);
        }
        else
        {
            ft_printf("Arg n %d : %d\n", i, ft_atoi(arg[i]));
        }
        i++;
    }

    int test[9] = {77, 1, 2, 3, 4, 5, 6, 7, 8};
    ft_check_double(9, test);
    
    return 0;
}
