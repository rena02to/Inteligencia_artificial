import re

#funcao auxiliar que mostra o locao em que foi feita a jogada a partir da entrada
def positions(assistant):
    if assistant == 1:
        return 0,0
    elif assistant == 2:
        return 0,1
    elif assistant == 3:
        return 0,2
    elif assistant == 4:
        return 1,0
    elif assistant == 5:
        return 1,1
    elif assistant == 6:
        return 1,2
    elif assistant == 7:
        return 2,0
    elif assistant == 8:
        return 2,1
    elif assistant == 9:
        return 2,2

#print do jogo do estado atual do jogo da velha
def jogo_velha(tabuleiro):
    i = 0
    j = 0
    for i in range(3):
        for j in range(3):
            if tabuleiro[i][j] == "":
                print("- ", end="")
            else:
                print(str(tabuleiro[i][j])+" ", end="")
        print("\n", end="")
    print("\n")

#funcao para testar se ha algum vencedor
def test_winner(tabuleiro):

    #ha vencedor em alguma linha?
    diagonal_p = tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2]
    diagonal_s = tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0]
    coluna1 = tabuleiro[0][0] + tabuleiro[1][0] + tabuleiro[2][0]
    coluna2 = tabuleiro[0][1] + tabuleiro[1][1] + tabuleiro[2][1]
    coluna3 = tabuleiro[0][2] + tabuleiro[1][2] + tabuleiro[2][2]

    if tabuleiro[0] == ["X", "X", "X"] or tabuleiro[1] == ["X", "X", "X"] or tabuleiro[2] == ["X", "X", "X"]:
        return "X"
    elif tabuleiro[0] == ["O", "O", "O"] or tabuleiro[1] == ["O", "O", "O"] or tabuleiro[2] == ["O", "O", "O"]:
        return "O"
        
    #ha vencedor nas diagonais?
    elif diagonal_p == "XXX":
        return "X"
    elif diagonal_p == "OOO":
        return "O"
    elif diagonal_s == "XXX":
        return "X"
    elif diagonal_s == "OOO":
        return "O"
    
    #ha vencedor nas colunas?
    elif coluna1 == "XXX" or coluna2 == "XXX" or coluna3 == "XXX":
        return "X"
    elif coluna1 == "OOO" or coluna2 == "OOO" or coluna3 == "OOO":
        return "O"
    
    #ha posicoes vazias?
    for i in range(0, 3):
        for j in range(0, 3):
            if tabuleiro[i][j] == "":
                return
    #nao? entao deu empate
    return "EMPATE"
    
#pega a entrada do usuario (personalizada pelo programa) e retorna a mesma
#(entrada esta que posteriormente vai ser formatada em linha e coluna pela funcao positions)
def user_play(tabuleiro):
    jogada = int(input("Digite o valor correspondente a posicao: "))
    while 1 > jogada or jogada > 9:
        print("JOGADA INVALIDA!")
        jogada = int(input("Digite o valor correspondente a posicao: "))
    while tabuleiro[positions(jogada)[0]][positions(jogada)[1]] != "":
        print("JOGADA INVALIDA!")
        jogada = int(input("Digite o valor correspondente a posicao: "))
    return jogada