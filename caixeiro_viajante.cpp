#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 999999

using namespace std;

// define a matriz de distâncias entre as cidades
const int distancias[10][10] = {
    {0, 30, 84, 56, INF, INF, INF, 75, INF, 80},
    {30, 0, 65, INF, INF, INF, 70, INF, INF, 40},
    {84, 65, 0, 74, 52, 55, INF, 60, 143, 48},
    {56, INF, 74, 0, 135, INF, INF, 20, INF, INF},
    {INF, INF, 52, 135, 0, 70, INF, 122, 98, 80},
    {70, INF, 55, INF, 70, 0, 63, INF, 82, 35},
    {INF, 70, INF, INF, INF, 63, 0, INF, 120, 57},
    {75, INF, 135, 20, 122, INF, INF, 0, INF, INF},
    {INF, INF, 143, INF, 98, 82, 120, INF, 0, INF},
    {80, 40, 48, INF, 80, 35, 57, INF, INF, 0}
};

// define o estado inicial da busca
vector<int> estado_inicial = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// função que calcula a distância percorrida em uma rota
int distancia_total(vector<int> rota) {
    int distancia = 0;
    for (int i = 0; i < rota.size() - 1; i++) {
        distancia += distancias[rota[i]][rota[i+1]];
    }
    distancia += distancias[rota[rota.size() - 1]][rota[0]];
    return distancia;
}

// função que gera os filhos de um estado por meio da permutação de cidades
vector<vector<int>> gerar_filhos(vector<int> estado_atual) {
    vector<vector<int>> filhos;
    for (int i = 1; i < estado_atual.size() - 1; i++) {
        for (int j = i + 1; j < estado_atual.size() - 1; j++) {
            vector<int> filho = estado_atual;
            reverse(filho.begin() + i, filho.begin() + j + 1);
            filhos.push_back(filho);
        }
    }
    return filhos;
}

// função que retorna o melhor filho do estado atual
vector<int> melhor_filho(vector<vector<int>> filhos) {
    vector<int> melhor = filhos[0];
    int melhor_distancia = distancia_total(melhor);
    for (int i = 1; i < filhos.size(); i++) {
        int distancia = distancia_total(filhos[i]);
        // é melhor que a melhor distância atual, atualiza o melhor
    if (distancia < melhor_distancia) {
        melhor = filhos[i];
        melhor_distancia = distancia;
    }
}
    return melhor;
}

// função de busca por Hill-Climbing
vector<int> hill_climbing() {
    vector<int> estado_atual = estado_inicial;
    int distancia_atual = distancia_total(estado_atual);
    while (true) {
        vector<vector<int>> filhos = gerar_filhos(estado_atual);
        vector<int> melhor = melhor_filho(filhos);
        int melhor_distancia = distancia_total(melhor);
        if (melhor_distancia < distancia_atual) {
            estado_atual = melhor;
            distancia_atual = melhor_distancia;
        } else {
        break;
        }
    }
    return estado_atual;
}

// função main que executa a busca e imprime a rota encontrada
int main() {
    vector<int> rota = hill_climbing();
    cout << "Rota encontrada: ";
    for (int i = 0; i < rota.size(); i++) {
        cout << rota[i] << " ";
    }
    cout << endl;
    cout << "Distancia total percorrida: " << distancia_total(rota) << " km" << endl;
    return 0;
}
