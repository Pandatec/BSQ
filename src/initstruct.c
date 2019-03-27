/*
** EPITECH PROJECT, 2018
** initstruct.c
** File description:
** all the init fonction
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

param_t initparam(param_t p, char **av)
{
    p.str = get_file(av[1]);
    p.nbline = findnblin(p.str, p.nbline);
    p.nbcol = 0;
    p.bool = 0;
    p.first = findparam(&p.nbcol, p.str, &p.bool);
    return (p);
}

tab_t inittab(tab_t t, param_t p)
{
    t.tab = (int **)malloc(sizeof(int*) * p.nbline);
    t.tab2 = (int *)malloc(sizeof(int) * p.nbcol * p.nbline);
    if (t.tab == NULL || t.tab2 == NULL)
        exit (84);
    for(int j = 0 ; j < p.nbline ; j++)
        t.tab[j] = &t.tab2[j * p.nbcol];
    t.tabstr = (char **)malloc(sizeof(char*) * p.nbline);
    t.tabstr2 = (char *)malloc(sizeof(char) * p.nbcol * p.nbline);
    if (t.tabstr == NULL || t.tabstr2 == NULL)
        exit (84);
    for(int j = 0 ; j < p.nbline ; j++)
        t.tabstr[j] = &t.tabstr2[j * p.nbcol];
    t.max[0] = 0;
    return (t);
}
