#include "parse.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void parse_scene(char *scene_path)
{
    int fd;
    char *line;
    char *trimmed;

    fd = open(scene_path, O_RDONLY);
    if (fd < 0)
        parse_error("file doesnt exist or is not a valid file");
    line = get_next_line(fd);
    while(line)
    {
        trimmed = trim_line(line);
        if(!is_skippable_line(trimmed))
        {
            // create tokens from the trimmed line
        }
        line = get_next_line(fd);
    }
    close(fd);
    ft_putstr_fd("Scene parsed successfully in ", 1);
    ft_putendl_fd(scene_path, 1);
}

