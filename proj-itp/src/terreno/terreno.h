#pragma once
#include "../../../doctest.h"
#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
const float rugosidade = 0.5;


class Terreno{

    Matriz<int> *terreno;
    int dimensao;
    public:

    Terreno(int n){
        dimensao =  pow(2, n) + 1;
        terreno = new Matriz<int>(dimensao, dimensao);
        for(int i = 0; i < (dimensao*dimensao); i++){
            terreno->obterElemento(i) = 0;
        }
        srand(time(0));
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
        (*this)(0, 0) = rand() % 10; //perguntar a André por que o *this.
        (*this)(0, dimensao - 1) = rand() % 10;
        (*this)(dimensao - 1, 0) = rand() % 10;
        (*this)((dimensao - 1), (dimensao - 1)) = rand() % 10;
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
        int passos = (dimensao-1)/2;
        int variancia = dimensao/2;

        while(passos >= 1){
            Diamond(passos, variancia);
            Square(passos, variancia);

            passos /= 2;
            variancia = variancia*rugosidade;
        }
    }

    void Diamond(int passos, int variancia){
        int media;
        int deslocamento;
        //laço percorrendo os cantos esquerdos superiores de cada quadrado
        for(int linha = 0; linha < dimensao-1; linha += 2*passos){
            for(int coluna = 0; coluna < dimensao-1; coluna += 2*passos){
                media = ((*this)(linha, coluna) + (*this)(linha, coluna+2*passos) + (*this)(linha+2*passos, coluna) + (*this)(linha+2*passos, coluna+2*passos))/4;
                deslocamento = (rand() % ((2*variancia) + 1)) - variancia;
                (*this)(linha+passos, coluna+passos) = media + deslocamento;
            }
        }
    }

    void Square(int passos, int variancia){
        int colunaInicial;
        int deslocamento;
        int media;
        
        for(int linha = 0; linha <= dimensao-1; linha += passos){
            //verifica se estamos na linha do ponto central.
            if((linha%(2*passos)) == 0){
                colunaInicial = passos; 
            }
            else{
                colunaInicial = 0;
            }


            for(int coluna = colunaInicial; coluna <= dimensao-1; coluna += 2*passos){
                int soma = 0;
                int qtd = 0;
                //verificar se os pontos estão dentro ou fora da matriz:
                if((coluna-passos) >= 0){
                    soma += (*this)(linha, coluna-passos);
                    qtd++;
                }
                if((coluna+passos) <= (dimensao-1)){
                    soma += (*this)(linha, coluna+passos);
                    qtd++;
                }
                if((linha-passos) >= 0){
                    soma += (*this)(linha-passos, coluna);
                    qtd++;
                }
                if((linha+passos) <= (dimensao-1)){
                    soma += (*this)(linha+passos, coluna);
                    qtd++;
                }

                media = soma/qtd;
                deslocamento = (rand() % ((2*variancia) + 1)) - variancia;

                (*this)(linha, coluna) = media + deslocamento;
            }
        }
    }

    int obterLargura(){
        return terreno->obterLargura();
    }

    int obterProfundidade(){
        return terreno->obterAltura();
    }
};
