/*
** EPITECH PROJECT, 2018
** My Strlen
** File description:
** Desc
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
