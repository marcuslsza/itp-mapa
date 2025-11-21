#pragma once
#include "../paleta/paleta.h"
#include <fstream>
#include <string>

struct Pixel{
    int r, g, b;
};

class Matriz{
    int linhas; //altura maxima
    int colunas; //largura maxima
    Pixel *valores;

    public:

    Matriz(int l = 1, int c = 1){
        linhas = l;
        colunas = c;
        valores = new Pixel[l*c];
    }

    ~Matriz(){
        delete[] valores;
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

    Pixel& operator[](int index){
        return valores[index];
    }

};

class Imagem{
    int largura = 0;
    int altura = 0;
    int maxCor = 0;
    std::string ppm = "";
    Matriz *pixels = nullptr;

    public:
    
    Imagem() = default;

    Imagem(int larg, int alt){
        largura = larg;
        altura = alt;
        maxCor = 255;
        ppm = "P3";
        pixels = new Matriz(larg, alt);
    }

    ~Imagem(){
        delete pixels;
    }
    
    int obterAltura(){
        return altura;
    }

    int obterLargura(){
        return largura;
    }

    Pixel& operator() (int coluna, int linha){ 
        int indice = (linha*largura)+coluna;
        return (*pixels)[indice];
    }

    void redimensionar(int newWidth, int newHeight){
        delete pixels;
        pixels = new Matriz(newWidth, newHeight);
        largura = newWidth;
        altura = newHeight;
    }

  
    bool lerPPM(std::string nomeArquivo){
        std::ifstream arquivo(nomeArquivo);
        int novaLargura, novaAltura;
        int vermelho, verde, azul;

        if(!(arquivo.is_open())){
            std::cerr << "Não é possível abrir o arquivo";
            return false;
        }

        arquivo >> ppm >> novaLargura >> novaAltura >> maxCor;

        if((novaLargura != largura) || (novaAltura != altura)){
            redimensionar(novaLargura, novaAltura);
        }

        int posicaoMatLin = 0;
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                arquivo >> vermelho >> verde >> azul;

                (*pixels)[posicaoMatLin].r = vermelho;
                (*pixels)[posicaoMatLin].g = verde;
                (*pixels)[posicaoMatLin].b = azul;

                posicaoMatLin++;
            }
        }
        return true;
    }

    bool salvarPPM(std::string nomeArquivo){
        
        std::ofstream arquivo(nomeArquivo, std::ios_base::out | std::ios_base::trunc);

        if(!(arquivo.is_open())){
            std::cerr << "Não foi possivel abrir o arquivo";
            return false;
        }

        arquivo << ppm << std::endl;
        arquivo << largura << " " << altura << std:: endl;
        arquivo << maxCor << std:: endl;

        return true;

    }
};