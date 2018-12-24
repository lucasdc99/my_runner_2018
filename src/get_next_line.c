/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_realloc(char *ptr)
{
    char *temp = ptr;
    int i = 0;

    ptr = malloc(sizeof(char) * (my_strlen(ptr) + READ_SIZE));
    while (temp[i]) {
        ptr[i] = temp[i];
        i++;
    }
    return (ptr);
}

char *read_line(char **buffer, char *str, int sizeStr, int fd)
{
    int size = 1;
    int count = 0;

    while (*buffer[0] != '\n') {
        size = read(fd, buffer[0], READ_SIZE);
        if (size <= 0)
            return (NULL);
        str = my_realloc(str);
        buffer[0][size] = '\0';
        count = 0;
        for (; *buffer[0] != '\n' && count < size; *buffer[0]++) {
            str[sizeStr] = *buffer[0];
            count++;
            sizeStr++;
        }
    }
    *buffer[0]++;
    return (str);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * READ_SIZE);
    char *buffer = malloc(sizeof(char) * READ_SIZE);
    static char over[READ_SIZE];
    int sizeStr = 0;

    if (!str || !buffer || fd == -1 || READ_SIZE < 1)
        return (NULL);
    for (int i = 0; over[i] != 0; i++) {
        str[i] = over[i];
        over[i] = 0;
        sizeStr++;
    }
    str = read_line(&buffer, str, sizeStr, fd);
    for (int i = 0; *buffer != '\0'; i++) {
        over[i] = *buffer;
        *buffer++;
    }
    return (str);
}