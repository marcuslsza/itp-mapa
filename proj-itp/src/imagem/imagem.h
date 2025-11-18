#pragma once
#include "../paleta/paleta.h"
#include <fstream>
#include <string>


struct Pixel{
    int r, g, b;
};


class Matriz{
    int linhas; //altura maximo
    int colunas; //largura maxima

    //criando uma "matriz" de forma linear
    Pixel *valores;

    public:
    //Matriz() = default;

    Matriz(int l = 1, int c = 1)
    {
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

    Pixel& operator[] (int index)
    {
        return valores[index];
    }

};

class Imagem{
    int largura = 1;
    int altura = 1;
    int maxCor = 1;
    Matriz pixels;

    public:
    
    Imagem() = default;

    Imagem(int larg, int alt)
    {
        largura = larg;
        altura = alt;
    }

    ~Imagem()
    {
        //delete[] pixels.
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

    
    void lerPPMcabecalho(std::string arquivo)
    {
        std::ifstream nomeArquivo(arquivo);
        std::string tipoImagem = "";
        
        if (nomeArquivo.is_open())
        {
            std::getline(nomeArquivo, tipoImagem);
            nomeArquivo >> largura >> altura;
            nomeArquivo >> maxCor;
        }
    }

    void lerPPMcores(std::string arquivo)
    {

    }
    
    
    bool lerPPM(std::string arquivo)
    {
        lerPPMcabecalho(arquivo);
        lerPPMcores(arquivo);
    }
};