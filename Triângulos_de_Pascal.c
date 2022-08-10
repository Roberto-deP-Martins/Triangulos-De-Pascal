/* ABRIR ARQUIVO COM CODIFICAÇÃO ISO 8859-1 (usada para suportar caracteres e acentuação
do alfabeto brasileiro) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Unsigned long long int necessário para o tamanho dos números gerados por fatoriais
unsigned long long int fatorial(int num, int corte);
unsigned long long int combinacao(int n, int k);
int qtd_digitos(int qtd_linhas);  // Retorna quantidade de digitos de um número

int main() {

    setlocale(LC_ALL, "Portuguese");
    int continua = 1;
    int qtd_linhas;
    while (continua)
    {
        do {
            printf("Digite o número da linha em que deseja que o triângulo termine: ");
            scanf(" %ld", &qtd_linhas);
            if (qtd_linhas > 29) {
                printf("Insira um valor entre 1 e 29.\n");
            }
        } while (qtd_linhas > 29);
        int quantidade_digitos = qtd_digitos(qtd_linhas);
        for (int n = 0; n <= qtd_linhas; n++) {  // Para cada linha
            for (int k = 0; k <= n; k++) {  // Para cada coluna da linha n
                if (k == n)  // Última coluna
                {
                    /* Printa 1 com a quantidade de dígitos do maior número do triângulo + 2,
                    como parâmetro de alinhamento à direita */
                    printf("%*llu\n", quantidade_digitos + 2, 1);
                }
                else if (k == 0) {
                   printf("%*llu", quantidade_digitos + 2, 1);
                }
                else if (k == 1)
                {
                    printf("%*llu", quantidade_digitos + 2, n);
                }
                else
                {
                    printf("%*llu", quantidade_digitos + 2, combinacao(n, k));
                }
            }
        }
        printf("\n");
        char resposta_continua;
        printf("Insira qualquer tecla para continuar, ou digite N para encerrar: ");
        getchar();  // Limpa buffer
        resposta_continua = getchar();
        if (resposta_continua == 'N' || resposta_continua == 'n')
        {
            continua = 0;
        }
    }
    

    return 0;
}

int qtd_digitos(int qtd_linhas) {
    int quantidade_digitos;
    unsigned long long int maior_valor = combinacao(qtd_linhas, qtd_linhas / 2);
    while (maior_valor > 0) {
        maior_valor /= 10;
        quantidade_digitos += 1;
    }
    return quantidade_digitos;
}

unsigned long long int combinacao(int n, int k) {
    unsigned long long subtracao_divisor, numerador, divisor, resultado;
    subtracao_divisor = n - k;
    /* Condições a frente removem da operação o maior fatorial do divisor e calcula o fatorial do
    numerador interrompendo a sequência de multiplicações nesse número, simulando o "corte" dos valores que seria feito para acelerar o mesmo cálculo caso fosse feito de forma manuscrita */
    if (subtracao_divisor > k) {
        divisor = fatorial(k, 1);
        numerador = fatorial(n, subtracao_divisor);
        resultado = numerador / divisor;
    }
    else {
        divisor = fatorial(subtracao_divisor, 1);
        numerador = fatorial(n, k);
        resultado = numerador / divisor;
    }
    return resultado;
}

/* Corte interrompe a sequência de mulitplicações, diminuindo o número de operações.
Caso corte seja 1, fatorial segue normalmente */
unsigned long long int fatorial(int fact, int corte)
{
    unsigned long long resposta = 1;
    for (; fact > corte; fact--) {
        resposta = resposta * fact;
    }
    return resposta;
}