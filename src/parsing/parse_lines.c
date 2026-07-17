#include"libft.h"
#include"parse.h"

char *trim_line(char *line)
{
    char *trimmed;
    trimmed = ft_strtrim(line , "\t\r\n");
    free(line);
    if (!trimmed)
        parse_error("Memory allocation failed during trimming a line");
    return (trimmed);
}

int is_skippable_line(char *line)
{
    return (line[0] == '\0' || line[0] == '#');
}