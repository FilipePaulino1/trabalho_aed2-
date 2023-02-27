#include <stdio.h>
#include <string.h>

void precompute_shifts(char *pattern, int *shifts)
{
    int i, j, m = strlen(pattern);

    for (i = 0; i < 256; i++)
        shifts[i] = m + 1;
    for (j = 0; j < m; j++)
        shifts[(int)pattern[j]] = m - j;
}

void galil_giancarlo(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i = m - 1, j, k, shift, shifts[256];

    precompute_shifts(pattern, shifts);
    while (i < n)
    {
        j = m - 1;
        k = i;
        while (j >= 0 && text[k] == pattern[j])
        {
            k--;
            j--;
        }
        if (j == -1)
        {
            printf("Padrão encontrado na posição: %d\n", k + 1);
            shift = shifts[(int)text[k + m]];
        }
        else
        {
            shift = shifts[(int)text[i + 1]];
        }
        i += shift;
        if (shift > m)
        {
            memmove(text + i - m + 1, text + i - 2 * m + j + 2, m - j - 2);
            i -= m - j - 2;
        }
    }
}

int main()
{
    char *text = "ABAAABCDBBABCDDEBCABC";
    char *pattern = "ABC";
    galil_giancarlo(text, pattern);
    return 0;
}