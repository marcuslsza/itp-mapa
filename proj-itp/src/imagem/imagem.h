#pragma once
#include "../paleta/paleta.h"


struct Pixel{
    int r, g, b;
};


class Matriz{
    int linhas; //altura maximo
    int colunas; //largura maxima

    //criando uma "matriz" de forma linear
    Pixel *valores;

    public:
    Matriz() = default;

    Matriz(int l, int c){
        linhas = l;
        colunas = c;
        valores = new Pixel[l*c];
    }

    ~Matriz() {
        delete[] valores;
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

};

class Imagem{
    int largura = 1;
    int altura = 1;
    Matriz pixels;

    public:
    
    Imagem() = default;

    Imagem(int alt, int larg)
    {
        largura = larg;
        altura = alt;
    }

    int obterAltura()
    {
        return altura;
    }

    int obterLargura()
    {
        return largura;
    }

    Pixel& operator() (int l, int c)
    {
        int indice = (l*altura)+c;
        return pixels[indice];
    }
};