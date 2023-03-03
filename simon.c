#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4     // número de bits no padrão oculto
#define M 2 * N // número total de bits na sequência

int b[M];     // sequência de bits
int x[N];     // vetor x
int y[N];     // vetor y
int a[N][N];  // matriz a
int b_hat[N]; // vetor b_hat

// função que verifica se dois vetores são iguais
int equal_vectors(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

// função que gera uma sequência de bits aleatórios
void generate_bits(int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 2;
    }
}

// função que exibe uma sequência de bits
void print_bits(int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", b[i]);
    }
    printf("\n");
}

// função que executa o algoritmo de Simon
void simon_algorithm()
{
    // gerar sequência de bits aleatórios
    generate_bits(b, M);

    // exibir a sequência de bits
    printf("Sequência de bits: ");
    print_bits(b, M);

    // gerar vetor x
    for (int i = 0; i < N; i++)
    {
        x[i] = b[i];
    }

    // gerar matriz a
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = rand() % 2;
            }
        }
    }

    // calcular vetor y
    for (int i = 0; i < N; i++)
    {
        y[i] = 0;
        for (int j = 0; j < N; j++)
        {
            y[i] += a[i][j] * x[j];
        }
        y[i] %= 2;
    }

    // gerar vetor b_hat
    for (int i = 0; i < N; i++)
    {
        b_hat[i] = b[i + N] ^ y[i];
    }

    // exibir vetor b_hat
    printf("Vetor b_hat: ");
    print_bits(b_hat, N);

    // verificar se b_hat é igual a y
    if (equal_vectors(b_hat, y, N))
    {
        printf("O padrão oculto é: ");
        print_bits(x, N);
    }
    else
    {
        printf("Não foi possível encontrar o padrão oculto.\n");
    }
}

int main()
{
    // inicializar gerador de números aleatórios
    srand(time(NULL));

    // executar o algoritmo de Simon
    simon_algorithm();

    return 0;
}