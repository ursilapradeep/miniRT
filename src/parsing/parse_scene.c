#include "parse.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void parse_scene(char *scene_path)
{
    int fd;
    char *line ;

    fd = open(scene_path, O_RDONLY);
    if (fd < 0)
    {
        parse_error("file doesnt exist or is not a valid file");
        exit(1);
    }
    line = get_next_line(fd);
    while(line)
    {
        line = get_next_line(fd);
    }
    close(fd);
    ft_putstr_fd("Scene parsed successfully in ", 1);
    ft_putendl_fd(scene_path, 1);
}

