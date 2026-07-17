#include "../libft/libft.h"

void parse_error(char *msg)
{
    ft_putstr_fd("Error: ", 2);
    ft_putendl_fd(msg, 2);
}