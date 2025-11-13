#include "../sequencia/sequencia.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

struct Cor{
    int r, g, b;
};

class Paleta{
    Sequencia<Cor> cores;
    int tamanho;

    Cor stringParaCor(std::string hexa){
        Cor resultado;
        int posicao_inicial = 1;

        for(int i = 1; i < 4; i++){
            int soma = 0;
            int valor_int;
            for(int j = posicao_inicial; j < (posicao_inicial + 2) ; j++){
                int expoente = 1;
                if((hexa[j] >= 48) || (hexa[j] <= 57)){
                    valor_int = (hexa[j] - 48) * pow(16, expoente);
                }
                if((hexa[j] >= 97) || (hexa[j] <= 122)){
                    valor_int = (hexa[j] - 87) * pow(16, expoente);
                }
                expoente--;
                soma += valor_int;
            }
            posicao_inicial += 2;
            if(i == 1){
                resultado.r = soma;
            }
            else if (i == 2)
            {
                resultado.g = soma;
            }
            else{
                resultado.b = soma;
            }
        }
        return resultado;
    }

    public:

    Paleta(){
        tamanho = 0;
    }

    Paleta(std::string arquivo){
        std::ifstream nomeArquivo(arquivo);
        std::string temp = "";

        Sequencia<Cor> previaPaleta;

        if(nomeArquivo.is_open()){
            while(std::getline(nomeArquivo, temp)){
                previaPaleta.adicionar(stringParaCor(temp));
                tamanho++;
            }
        }
        else{
            std::cerr << "Erro ao abrir o arquivo" << std::endl;
        }

        cores = previaPaleta;

    }

    int obterTamanho(void){
        return tamanho;
    }

    void adicionarCor(Cor cor){
        cores[tamanho] = cor;
        tamanho++;
    }

    Cor obterCor(int index){
        if((index < 0) or (index >= tamanho)){
            return {0, 0, 0};
        }
        return cores[index];
    }




};