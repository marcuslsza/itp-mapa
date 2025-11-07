#include <iostream>

template <typename T>

class Sequencia {
    T capacidade;
    T tamanho;
    T *dados;
    
    void ajustaCapacidade() {
        capacidade *= 2;
        int *novo = new int[capacidade];
        for(int i = 0; i<tamanho; i++) {
            novo[i] = dados[i];

        }
        delete[] dados;
        dados = novo;
    }

    public:

    Sequencia(int cap = 2) {
        capacidade = cap;
        tamanho = 0;
        dados = new int[capacidade];
    }

    ~Sequencia() {
        delete[] dados;
    }

    int obterTamanho() {
        return tamanho;
    }

    void adicionar(int valor) {
        if (tamanho >= capacidade) {
            ajustaCapacidade();
        }
        dados[tamanho] = valor;
        tamanho++;
    }

    int obterElemento(int indice) {
        if(indice < 0 || indice >= tamanho) {
            std::cerr << "Erro: índice inválido.";
        }
        return dados[indice];
    }

    void removerUltimo() {
        if(tamanho <= 0) {
            std::cerr << "Erro: remoção de sequência vazia.";
        }
        tamanho--;
    }
};