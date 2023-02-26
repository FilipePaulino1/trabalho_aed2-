#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000 // tamanho máximo das strings

void pre_process(char *pattern, int m, int *lps)
{
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void colussi_search(char *text, int n, char *pattern, int m)
{
    int lps[m];
    pre_process(pattern, m, lps);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            printf("Padrão encontrado na posição %d.\n", i - m);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char text[MAX_N];
    char pattern[MAX_N];
    printf("Digite o texto: ");
    fgets(text, MAX_N, stdin);
    printf("Digite o padrão: ");
    fgets(pattern, MAX_N, stdin);
    int n = strlen(text) - 1;
    int m = strlen(pattern) - 1;
    colussi_search(text, n, pattern, m);
    return 0;
}