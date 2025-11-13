#include <iostream>

template <typename T>

class Sequencia {
    int capacidade;
    int tamanho;
    T *dados;
    
    void ajustaCapacidade() {
        capacidade *= 2;
        T *novo = new T[capacidade];
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
        dados = new T[capacidade];
    }

    ~Sequencia() {
        delete[] dados;
    }

    int obterTamanho() {
        return tamanho;
    }

    void adicionar(T valor) {
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

    T& operator[] (int index) {
        return dados[index];
    }

};