#include "../sequencia/sequencia.h"
#include "cores.hex"

struct Cor {
    int r, g, b;
};

class Paleta {
    Sequencia<Cor> cores;
    int tamanho;
    



    public:
    Paleta() {
        tamanho = 0;
    }

    Paleta(std::string arquivo) {
        
    }

    int obterTamanho() {return tamanho;}

    void adicionarCor(Cor c) {
        cores.adicionar(c);
        tamanho++;
    }

    Cor obterCor(int indice) {
        if(indice >= tamanho || indice < 0) {
            Cor corInvalida = {0, 0, 0};
            return corInvalida;
        }
        return cores[indice];
    }
};
#include "sequencia.h"

class Cor{
    int r, g, b;
};

class Paleta{
    Sequencia<Cor> cores;
    int tamanho;


    public:

    Paleta(){
        tamanho = 0;
    };


    int obterTamanho(void){
        return tamanho;
    }


};
