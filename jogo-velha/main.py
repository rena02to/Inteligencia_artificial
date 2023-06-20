import random
from sec_funct import positions
from sec_funct import jogo_velha
from sec_funct import test_winner
from sec_funct import user_play
from iastart import moviment
import os



#funcao que roda o game
def game():
    #monta o tabuleiro
    tabuleiro = [["", "", ""], ["", "", ""], ["", "", ""]]
    k = 0
    l = 0
    contador = 1
    print('='*80)
    print("\t\t\t\tJOGO DA VELHA")
    print('='*80)
    print("\n\t\tAS POSICOES DO TABULEIRO FUNCIONAM DA SEGUINTE FORMA:")
    for k in range(3):
        if k > 0:
            print("\n------")
        for l in range(3):
            if l == 1 or l == 2:
                print("|", end="")
            print(contador, end="")
            contador = contador + 1
    print("\n\nQUEM INICIA O JOGO SEMPRE USA O CARACTERE X")
    print('.'*80) 
    print("")
    print('QUEM IRA COMECAR O JOGO?\n   1 - IA\n   2 - USER')
    print('')
    player = int(input("   >>> Opcao: "))

    #determina a ordem das jogadas e qual o caractere da ia e do user
    if player == 1:
        user = "O"
        ia = "X"
        token = []
        token.append('X')
        token.append('O')
        jogador = 0
    elif player == 2:
        user = "X"
        ia = "O"
        token = []
        token.append('O')
        token.append('X')
        jogador = 1
        os.system("cls")
    else:
        game()

    #continua ate haver vencedor ou empate
    while not test_winner(tabuleiro):
        if jogador == 1:
            print(f"USER = {user}")
            print('.'*60)
            print('\nJOGADA DO USER:')
            jogada = user_play(tabuleiro)
            aux = positions(jogada)
            l = aux[0]
            k = aux[1]
            tabuleiro[l][k] = token[jogador]
        else:
            #chama a funcao que determina a jogada da ia
            auxiliar = moviment(tabuleiro, jogador, token)
            l = auxiliar[0]
            k = auxiliar[1]
            tabuleiro[l][k] = token[jogador]
            os.system("cls")
            print(f"IA = {ia}")
            print('.'*60)
            print('\nJOGADA DA IA:')
        
        #testa se ha vencedor ou empate
        vencedor = test_winner(tabuleiro)
        if vencedor:
            os.system("cls")
            jogo_velha(tabuleiro)
            print('.'*80)
            if vencedor == user:
                print("\t\t\t\t\tUSER VENCEU!")
            elif vencedor == ia:
                print("\t\t\t\t\tIA VENCEU!")
            else:
                print(f"\t\t\t\t\t{vencedor}")

            print('='*80)
            return

        jogador = (jogador + 1) % 2
        jogo_velha(tabuleiro)
     
game()