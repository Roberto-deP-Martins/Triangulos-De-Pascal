def fatorial(num, corte):  # Corte interrompe a sequência de mulitplicações, compensando não ter o maior fatorial do divisor presente na operação
    valor = num
    for i in range(num - 1, corte, -1):
        valor = valor * i
    return valor


def combinacao(n, k):
    subtracao_divisor = n - k
    # Remove-se maior fatorial do divisor da operação e interrompe-se o cálculo do fatorial do
    # numerador nesse número, simulando o corte dos valores no cálculo feito a mão
    if subtracao_divisor > k:
        divisor = fatorial(k, 1)
        numerador = fatorial(n, subtracao_divisor)

    else:
        divisor = fatorial(n - k, 1)
        numerador = fatorial(n, k)
    resultado = numerador // divisor
    return resultado


continua = True
while continua:
    qtd_linhas = int(input('Digite o número da linha em que deseja que o triângulo termine: '))
    tamanho_justificado = len(str(combinacao(qtd_linhas, qtd_linhas // 2))) + 2
    for n in range(0, qtd_linhas + 1):  # n = linha do Triângulo
        for k in range(n + 1):  # k = coluna do triângulo
            if k == 0 or k == n:
                resutltado_formatado = '1'.rjust(tamanho_justificado)
            elif k == 1:
                resutltado_formatado = str(n).rjust(tamanho_justificado)
            else:
                resultado_coeficiente = combinacao(n, k)
                resutltado_formatado = str(resultado_coeficiente).rjust(tamanho_justificado)
            if k == n:  # Se o número da coluna é igual ao da linha, essa é a última coluna e quebra-se a linha 
                print(resutltado_formatado)
            else:
                print(resutltado_formatado, end= ' ')
    print('\n')
    resposta_continua = input("Quer gerar outro triângulo? (Sim/Não): ").lower()
    if resposta_continua == 'não' or resposta_continua == 'nao' or resposta_continua == 'n':
        continua = False