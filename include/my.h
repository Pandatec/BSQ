/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

typedef struct param_s
{
    char *str;
    int nbline;
    int nbcol;
    int first;
    int bool;
} param_t;

typedef struct tab_s
{
    int **tab;
    int *tab2;
    char **tabstr;
    char *tabstr2;
    int max[3];
} tab_t;

char *get_file(char *path);
int findparam(int *nbcol, char *str, int *bool);
param_t initparam(param_t p, char **av);
tab_t inittab(tab_t t, param_t p);
int my_getnbr(char const *str);
void my_putchar(char c);
int **createtab(char *str, int first, int **tab);
char **createstrtab(char **tabstr, param_t p);
int findnblin(char *tabstr, int nbline);
int condition(int **tab, int min, int d, int u);

#endif
