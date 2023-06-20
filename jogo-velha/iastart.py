from sec_funct import jogo_velha
from sec_funct import positions
from sec_funct import test_winner

#funcao que determina se os locais sem caracteres
def positions_null(tabuleiro):
    armazena = []
    contador = 1
    while contador <= 9:
        i = positions(contador)[0]
        j = positions(contador)[1]
        if tabuleiro[i][j] == "":
            armazena.append((i, j))
        contador = contador + 1
    return armazena

#determina o score com base no caracter do jogador (e a depender de quem comecou inverte o resultado)
score = {
    'X' : 1,
    'O' : -1,
    'EMPATE' : 0
}

#funcao minimax
def minimax(tabuleiro, jogador, token):
    winner = test_winner(tabuleiro)
    if(winner):
        if token[0] == 'X':
            return score[winner]
        else:
            return (score[winner]) * -1
    
    jogador = (jogador + 1) % 2
    
    possibilidades = positions_null(tabuleiro)
    melhor_valor = None
    for coordenadas in possibilidades:
        tabuleiro[coordenadas[0]][coordenadas[1]] = token[jogador]
        valor = minimax(tabuleiro, jogador, token)
        tabuleiro[coordenadas[0]][coordenadas[1]] = ""
        if(melhor_valor is None):
            melhor_valor = valor
        elif jogador == 0:
            if melhor_valor < valor:
                melhor_valor = valor
        elif jogador == 1:
            if melhor_valor > valor:
                melhor_valor = valor
    return melhor_valor

#define o melhor movimento para a ia com base no score
def moviment(tabuleiro, jogador, token):
    possibilidades = positions_null(tabuleiro)
    melhor_jogada = None
    melhor_valor = None
    
    #busca as coordenadas possiveis e testa todas
    #o valor da melhor jogada e comparado com base em quantas possibilidades de vitoria ha a patir de uma posicao valida
    for coordenadas in possibilidades:
        tabuleiro[coordenadas[0]][coordenadas[1]] = token[jogador]
        valor = minimax(tabuleiro, jogador, token)
        tabuleiro[coordenadas[0]][coordenadas[1]] = ""
        if(melhor_valor is None):
            melhor_valor = valor
            melhor_jogada = coordenadas
        elif jogador == 0:
            if melhor_valor < valor:
                melhor_valor = valor
                melhor_jogada = coordenadas
        elif jogador == 1:
            if melhor_valor > valor:
                melhor_valor = valor
                melhor_jogada = coordenadas
        
    return melhor_jogada