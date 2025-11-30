#pragma once
#include "../paleta/paleta.h"
#include <fstream>
#include <string>
#include <iostream>

struct Pixel{
    int r, g, b;
};

template <typename T >
class Matriz{
    int linhas; //altura maximo
    int colunas; //largura maxima

    //criando uma "matriz" de forma linear
    T *valores;

    public:
    

    Matriz(int l = 1, int c = 1)
    {
        linhas = l;
        colunas = c;
        valores = new T[l*c];
    }

    ~Matriz() {
        delete[] valores;
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

    T& obterElemento(int index)
    {
        return valores[index];
    }
    
    T& operator[] (int index)
    {
        return valores[index];
    }

    int obterLargura()
    {
        return colunas;
    }

    int obterAltura()
    {
        return linhas;
    }
};

template <typename T>
class Imagem{
    int largura = 0;
    int altura = 0;
    int maxCor = 0;
    std::string ppm = "";
    Matriz<T> *pixels = nullptr;

    public:

    Imagem() = default;

    Imagem(int larg, int alt)
    {
        largura = larg;
        altura = alt;
        maxCor = 255;
        ppm = "P3";
        pixels = new Matriz<T>(larg*alt);
    }

    ~Imagem()
    {
        delete pixels;
    }
    
    int obterAltura()
    {
        return altura;
    }

    int obterLargura()
    {
        return largura;
    }

    T& operator() (int c, int l)
    {
        int indice = (l*largura)+c;
        return pixels->obterElemento(indice);
    }
     
    void redimensionar(int newWidth, int newHeight)
    {
        delete pixels;
        pixels = new Matriz<T>(newWidth, newHeight);
        largura = newWidth;
        altura = newHeight;
    } 

    bool lerPPM(std::string arquivo)
    {
        std::ifstream filePPM(arquivo);
        if(!filePPM.is_open()) return false;

        std::string tipoPPM = "";
        int alturaPPM, larguraPPM, intensidadeCorPPM;

        filePPM >> tipoPPM >> larguraPPM >> alturaPPM >> intensidadeCorPPM;

        if(alturaPPM != altura || larguraPPM != largura)
        {
            redimensionar(larguraPPM, alturaPPM);
        }

		if(ppm != tipoPPM)
		{
			ppm = tipoPPM;
		}

        int cont = 0;
        for(int i = 0; i < alturaPPM;i++)
        {
            for(int j = 0; j < larguraPPM; j++)
            {
                int red, green, blue;
                filePPM >> red >> green >> blue;
                
                this->pixels->obterElemento(cont).r = red;
                this->pixels->obterElemento(cont).g = green;
                this->pixels->obterElemento(cont).b = blue;
                cont++;
            }
        }
        filePPM.close();
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

        int posicaoMatLin = 0;
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                arquivo << (*pixels)[posicaoMatLin].r << " ";
                arquivo << (*pixels)[posicaoMatLin].g << " ";
                arquivo << (*pixels)[posicaoMatLin].b;

                arquivo << std::endl;
                posicaoMatLin++;
            }
        }
        return true;
    }
};