#pragma once
#include "../../../doctest.h"
#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

class Terreno{

    Matriz<int> *terreno;
    int dimensao;
    public:

    Terreno(int n){
        dimensao =  pow(2, n) + 1;
        terreno = new Matriz<int>(dimensao, dimensao);
        srand(time(0));
        matrizInicial();
    }

    ~Terreno() {
        delete terreno;
    }

    int& operator()(int linha, int coluna){
        int indice = ((linha*dimensao) + coluna); //1*2 +0
        std::cout << indice << std::endl;
        std::cout << terreno->obterElemento(indice) << std::endl;
        return terreno->obterElemento(indice);
    }

    void matrizInicial(){
        (*this)(0, 0) = 10;//rand() % 10;
        (*this)(0, dimensao - 1) = 10; //rand() % 10;
        (*this)(dimensao - 1, 0) = 10;//rand() % 10;
        (*this)((dimensao - 1), (dimensao - 1)) = 10;//rand() % 10;
    }

    int obterLargura(){
        return terreno->obterLargura();
    }

    int obterProfundidade(){
        return terreno->obterAltura();
    }
};