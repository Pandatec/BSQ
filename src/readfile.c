/*
** EPITECH PROJECT, 2018
** readfile.c
** File description:
** read a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

char *get_file(char *path)
{
    char *file = NULL;
    struct stat filestat;
    int file_des;
    int ret = 0;

    if (file != NULL)
        exit (84);
    stat(path, &filestat);
    file = malloc(sizeof(char) * filestat.st_size);
    if ((file_des = open(path, O_RDONLY)) == -1)
        exit(84);
    ret = read(file_des, file, filestat.st_size);
    if (ret == -1)
        exit(84);
    file[ret] = '\0';
    close(file_des);
    return (file);
}
