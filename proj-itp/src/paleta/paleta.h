#include "../sequencia/sequencia.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

struct Cor{
    int r, g, b;
};

class Paleta {
    Sequencia<Cor> cores;
    int tamanho = 0;
    
    Cor stringParaCor(std::string hexa){
        Cor resultado;
        int posicao_inicial = 1;
        int valor_int;

        for(int i = 0; i < 3; i++){
            int soma = 0;
            int expoente = 1;
            for(int j = posicao_inicial; j < (posicao_inicial + 2) ; j++){
                if((hexa[j] >= 48) && (hexa[j] <= 57)){
                    valor_int = (hexa[j] - 48) * pow(16, expoente);
                }
                if((hexa[j] >= 97) && (hexa[j] <= 122)){
                    valor_int = (hexa[j] - 87) * pow(16, expoente);
                }
                expoente--;
                soma += valor_int;
            }
            
            posicao_inicial += 2;
            if(i == 0){
                resultado.r = soma;
            }
            else if (i == 1)
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

    Paleta() = default;

    
    Paleta(std::string arquivo){
        std::ifstream nomeArquivo(arquivo);
        std::string temp = "";

        if(nomeArquivo.is_open()){
            while(std::getline(nomeArquivo, temp)){
                this->adicionarCor(stringParaCor(temp));
            }
        }

    }

    int obterTamanho(void){
        return tamanho;
    }

    void adicionarCor(Cor cor){
        cores.adicionar(cor);
        tamanho = cores.obterTamanho();
    }

    Cor obterCor(int index){
        if((index < 0) or (index >= tamanho)){
            return {0, 0, 0};
        }
        return cores[index];
    }
};
