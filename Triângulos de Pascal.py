from math import factorial as fatorial

def combinacao(n, k):
    numerador = fatorial(n)
    divisor = (fatorial(k) * (fatorial(n - k)))
    resultado = numerador // divisor
    return resultado


continua = True
while continua:
    triangulo = []
    qtd_linhas = int(input('Digite o número da linha em que deseja que o triângulo termine: '))
    tamanho_justificado = len(str(combinacao(qtd_linhas, qtd_linhas // 2))) + 2
    for n in range(0, qtd_linhas + 1):
        linha = []
        for k in range(n + 1):
            if k == 0:
                linha.append('1'.rjust(tamanho_justificado))
            elif k == 1:
                linha.append(str(n).rjust(tamanho_justificado))
            elif k == n:
                linha.append('1'.rjust(tamanho_justificado))
            else:
                resultado_coeficiente = combinacao(n, k)
                resutltado_formatado = str(resultado_coeficiente).rjust(tamanho_justificado)
                linha.append(resutltado_formatado)
        triangulo.append(linha)
    for linha in triangulo:
        print(*linha)
    resposta_continua = input("Quer gerar outro triângulo? (Sim/Não): ").lower()
    if resposta_continua == 'não' or resposta_continua == 'nao' or resposta_continua == 'n':
        continua = False
