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
        srand(10);
        matrizInicial();
    }

    ~Terreno() {
        delete terreno;
    }

    int& operator()(int linha, int coluna){
        int indice = ((linha*dimensao) + coluna);
        return terreno->obterElemento(indice);
    }

    void matrizInicial(){
        (*this)(0, 0) = 10; //rand() % 10; perguntar a André por que o *this.
        (*this)(0, dimensao - 1) = 10; //rand() % 10;
        (*this)(dimensao - 1, 0) = 10; //rand() % 10;
        (*this)((dimensao - 1), (dimensao - 1)) = 10; //rand() % 10;
        DiamondSquare();
    }

    void imprimirMatriz(){
        for(int i = 0; i < terreno->obterAltura(); i++){
            for(int j = 0; j < terreno->obterLargura(); j++){
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void DiamondSquare(){
        int passosDiamond = (dimensao-1)/2;
        int passosSquare = 5;
        if(passosDiamond >= 1){
            Diamond(passosDiamond);
        }
    }

    void Diamond(int posicao){
        (*this)(posicao, posicao) = 5;
    }

    int obterLargura(){
        return terreno->obterLargura();
    }

    int obterProfundidade(){
        return terreno->obterAltura();
    }
};