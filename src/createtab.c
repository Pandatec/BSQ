/*
** EPITECH PROJECT, 2018
** createtab.c
** File description:
** create fonction
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int **createtab(char *str, int first, int **tab)
{
    int d = 0;
    int u = 0;

    while (str[first] != '\0') {
        if (str[first] == '.')
            tab[d][u] = 1;
        if (str[first] == 'o')
            tab[d][u] = 0;
        u++;
        if (str[first] == '\n') {
            u = 0;
            d++;
        }
        first++;
    }
    return (tab);
}

char **createstrtab(char **tabstr, param_t p)
{
    int w = 0;
    int z = 0;
    int y = p.first;

    while (w != p.nbline) {
        tabstr[w][z] = p.str[y];
        z++;
        if (z == p.nbcol) {
            y = y + 1;
            w++;
            z = 0;
        }
        y++;
    }
    return (tabstr);
}

int condition(int **tab, int min, int d, int u)
{
    if (tab[d][u] < min && tab[d + 1][u + 1] != 0)
        min = tab[d][u];
    if (tab[d][u + 1] < min && tab[d + 1][u + 1] != 0)
        min = tab[d][u + 1];
    if (tab[d + 1][u] < min && tab[d + 1][u + 1] != 0)
        min = tab[d + 1][u];
    if (min == 9999999)
        min = -1;
    return (min);
}
