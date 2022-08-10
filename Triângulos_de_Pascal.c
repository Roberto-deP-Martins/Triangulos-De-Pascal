/* ABRIR ARQUIVO COM CODIFICA��O ISO 8859-1 (usada para suportar caracteres e acentua��o
do alfabeto brasileiro) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Unsigned long long int necess�rio para o tamanho dos n�meros gerados por fatoriais
unsigned long long int fatorial(int num, int corte);
unsigned long long int combinacao(int n, int k);
int qtd_digitos(int qtd_linhas);  // Retorna quantidade de digitos de um n�mero

int main() {

    setlocale(LC_ALL, "Portuguese");
    int continua = 1;
    int qtd_linhas;
    while (continua)
    {
        do {
            printf("Digite o n�mero da linha em que deseja que o tri�ngulo termine: ");
            scanf(" %ld", &qtd_linhas);
            if (qtd_linhas > 29) {
                printf("Insira um valor entre 1 e 29.\n");
            }
        } while (qtd_linhas > 29);
        int quantidade_digitos = qtd_digitos(qtd_linhas);
        for (int n = 0; n <= qtd_linhas; n++) {  // Para cada linha
            for (int k = 0; k <= n; k++) {  // Para cada coluna da linha n
                if (k == n)  // �ltima coluna
                {
                    /* Printa 1 com a quantidade de d�gitos do maior n�mero do tri�ngulo + 2,
                    como par�metro de alinhamento � direita */
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
    /* Condi��es a frente removem da opera��o o maior fatorial do divisor e calcula o fatorial do
    numerador interrompendo a sequ�ncia de multiplica��es nesse n�mero, simulando o "corte" dos valores que seria feito para acelerar o mesmo c�lculo caso fosse feito de forma manuscrita */
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

/* Corte interrompe a sequ�ncia de mulitplica��es, diminuindo o n�mero de opera��es.
Caso corte seja 1, fatorial segue normalmente */
unsigned long long int fatorial(int fact, int corte)
{
    unsigned long long resposta = 1;
    for (; fact > corte; fact--) {
        resposta = resposta * fact;
    }
    return resposta;
}