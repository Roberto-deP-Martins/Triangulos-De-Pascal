import Foundation

extension String {
    func leftPadding(toLength: Int, withPad character: Character) -> String {
        let stringLength = self.count
        if stringLength < toLength {
            return String(repeatElement(character, count: toLength - stringLength)) + self
        } else {
            return String(self.suffix(toLength))
        }
    }
}


/* Corte interrompe a sequência de mulitplicações, diminuindo o número de operações.
Caso corte seja 1, fatorial segue normalmente */
func fatorial(num: Int, corte: Int) -> Int {
    var resultado = 1
    var numero = num
    while numero > corte {
        resultado = resultado * numero
        numero -= 1
    }
    return resultado
}

func combinacao(n : Int, k : Int) -> Int {
    let subtracaoDivisor = n - k
    let resultado: Int
    /* Condições a frente removem da operação o maior fatorial do divisor e calcula o fatorial do
    numerador interrompendo a sequência de multiplicações nesse número, simulando o "corte" dos valores que seria feito para acelerar o mesmo cálculo caso fosse feito de forma manuscrita */

    if subtracaoDivisor > k {
        let divisor = fatorial(num: k, corte: 1)
        let numerador = fatorial(num: n, corte: subtracaoDivisor)
        resultado = numerador / divisor
    }
    else {
        let divisor = fatorial(num: subtracaoDivisor, corte: 1)
        let numerador = fatorial(num: n, corte: k)
        resultado = numerador / divisor
    }
    return resultado
}

var continua = true
let respostasNegativas : Set = ["não", "nao", "n"]
var qtdLinhas : Int?
while continua {
    repeat {
        print("Digite o número de linhas desejadas: ", terminator:"")
        let entradaLinhas = readLine()!
        qtdLinhas = Int(entradaLinhas)
        
        if (qtdLinhas == nil) {
            print("Parece que você não digitou um número, tente novamente.")
        }
        else if (qtdLinhas! > 29) {
            print("Digite um número menor que 30.")
        }
    } while (qtdLinhas == nil || qtdLinhas! > 29)  // Verifica se valor digitado é um int
    let qtdDigitos = "\(qtdLinhas)".count
    for n in (0...qtdLinhas!) {  // Para cada linha
        for k in (0...n) {  // Para cada coluna da linha n
            if k == n {  // Última coluna
                /* Printa 1 com a quantidade de dígitos do maior número do triângulo + 2, como parâmetro de alinhamento à direita */
                print("1".leftPadding(toLength: qtdDigitos + 2, withPad: " "))
            }
            else if k == 0 {
                print("1".leftPadding(toLength: qtdDigitos + 2, withPad: " "), terminator: "")
            }
            else if k == 1 {
                print("\(n)".leftPadding(toLength: qtdDigitos + 2, withPad: " "), terminator: "")
            }
            else {
                print("\(combinacao(n: n, k: k))".leftPadding(toLength: qtdDigitos + 2, withPad: " "), terminator: "")
            }
        }
    }
    print("\nDeseja gerar outro triângulo? (Sim/Não): ")
    let respostaContinua = readLine()!.lowercased()
    if respostasNegativas.contains(respostaContinua) {
        continua = false
    }
}