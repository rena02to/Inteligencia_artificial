#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 14

//matriz de distancias
int dist [MAX][MAX] = {
    {0, 11, 20, 27, 40, 43, 39, 28, 18, 10, 18, 30, 30, 32},
    {11, 0, 9, 16, 29, 32, 28, 19, 11, 4, 17, 23, 21, 24},
    {20, 9, 0, 7, 20, 22, 19, 15, 10, 11, 21, 21, 13, 18},
    {27, 16, 7, 0, 13, 16, 12, 13, 13, 18, 26, 21, 11, 17},
    {40, 29, 20, 13, 0, 3, 2, 21, 25, 31, 38, 27, 16, 20},
    {43, 32, 22, 16, 3, 0, 4, 23, 28, 33, 41, 30, 17, 20},
    {39, 28, 19, 12, 2, 4, 0, 22, 25, 29, 38, 28, 13, 17},
    {28, 19, 15, 13, 21, 23, 22, 0, 9, 22, 18, 7, 25, 30},
    {18, 11, 10, 13, 25, 28, 25, 9, 0, 13, 12, 12, 23, 28},
    {10, 4, 11, 18, 31, 33, 29, 22, 13, 0, 20, 27, 20, 23},
    {18, 17, 21, 26, 38, 41, 38, 18, 12, 20, 0, 15, 35, 39},
    {30, 23, 21, 21, 27, 30, 28, 7, 12, 27, 15, 0, 31, 37},
    {30, 21, 13, 11, 16, 17, 13, 25, 23, 20, 35, 31, 0, 5},
    {32, 24, 18, 17, 20, 20, 17, 30, 28, 23, 39, 37, 5, 0}
};

//matriz de conexoes
int conexao[MAX][MAX] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

//matriz que indica qual linha tem conexao com qual
//1 = azul, 2 = amarelo, 3 = vermelho, 4 = verde
int linha[MAX][MAX] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0},
    {0, 0, 1, 0, 1, 0, 0, 4, 0, 0, 0, 0, 4, 0},
    {0, 0, 0, 1, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 4, 2, 0, 0, 0, 2, 0, 0, 4, 0, 0},
    {0, 2, 3, 0, 0, 0, 0, 2, 0, 0, 3, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0}
};

//funcao para calcular o tempo de viagem entre duas estacoes
int tempo(int estacao_origem, int estacao_destino){
    return(dist[estacao_origem][estacao_destino] * 2);
}

//retorna a melhor rota entre duas estacoes usando o algoritmo A*
//printa a rota que foi usanda para chegar no destino
int busca(int estacao_origem, int estacao_destino){
    int i = 0;
    int posicao = 0;

    int tempo_total = 0, contador = 0, no_atual = 0, no_pai = estacao_origem;

    int no_visitado[MAX], tempo_viagem[MAX], ordem_estacoes[MAX], linha_estacao[MAX];

    int f = 0, g = 0, h = 0;

    int f_no_melhor = 1000, no_melhor = 0, linha_no_melhor = 0;

    for(i = 0; i < MAX; i++){
        no_visitado[i] = 0;
        tempo_viagem[i] = 0;
        ordem_estacoes[i] = 0;
        linha_estacao[i] = 0;
    }

    no_visitado[estacao_origem] = 1;
    ordem_estacoes[posicao] = estacao_origem;
    tempo_viagem[posicao] = 0;
    posicao = 1;

    while(ordem_estacoes[posicao] != estacao_destino){
        for(no_atual = 0; no_atual < MAX; no_atual++){
            contador = 0;
            for(i = 0; i < MAX; i++){
                if(conexao[no_atual][i] == 1){
                    contador++;
                }
            }

            if(conexao[no_pai][no_atual] == 1 && no_visitado[no_atual] == 0){
                g = tempo(no_pai, no_atual);
                if((linha[no_pai][no_atual] != linha_estacao[posicao-1]) && (linha_estacao[posicao-1] != 0 && linha[no_pai][no_atual] != 0)){
                    g = g + 4;
                }

                h = tempo(no_atual, estacao_destino);
                f = g + h;
                if(f_no_melhor >= f){
                    f_no_melhor = f;
                    no_melhor = no_atual;
                    linha_no_melhor = linha[no_pai][no_atual];
                    no_visitado[no_melhor] = 1;
                }
            }
        }
        tempo_viagem[posicao-1] = tempo(no_pai, no_melhor);
        tempo_total = tempo_total + tempo_viagem[posicao-1];
        linha_estacao[posicao] = linha_no_melhor;

        if((linha_estacao[posicao] != linha_estacao[posicao - 1]) && (linha_estacao[posicao] != 0 && linha_estacao[posicao -1 ] != 0)){
            tempo_total = tempo_total + 4;
        }

        printf("ESTACAO_%d -> ESTACAO_%d TEMPO: %d Minutos\n", no_pai+1, no_melhor+1, tempo_viagem[posicao-1]);
        no_pai = no_melhor;
        posicao++;
        ordem_estacoes[posicao] = no_pai;
    }
    return tempo_total;

}

//principal
void main(){
    //alterar aqui para receber entrada do usuario, ou alterar a estacao de origem/estacao de destino
    int estacao_origem = 1, estacao_destino = 4;
    printf("TEMPO TOTAL: %d", busca(estacao_origem-1, estacao_destino-1));
}