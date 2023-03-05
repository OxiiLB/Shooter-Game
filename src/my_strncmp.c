/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** compare two str chars thanks to the int given in argument
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' || (s2[i] != '\0' && i < n); i += 1) {
        if (s1[i] - s2[i] != 0) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
