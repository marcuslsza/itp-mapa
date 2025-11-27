#pragma once
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "../imagem/imagem.h"
#include "../../../doctest.h"

class Terreno {
    Matriz<int> *terreno;
    int medida;
    public:

    Terreno(int n)
    {
        medida = pow(2, n) + 1;
        //Cria novo terreno quadrado de tamanho 2^n + 1
        terreno = new Matriz<int>(medida,medida);
        
        //Define os valores aleatórios dos 4 cantos do terreno;
        srand(time(0));
        
        //Intervalo de alturas: [1, 10]
        terreno[0] = rand()%10+1;
        terreno[medida] = rand()%10+1;
        terreno[medida*(medida-1)] = rand()%10+1;
        terreno[medida*(medida-1) + (medida-1)] = rand()%10+1;
    }

    ~Terreno() 
    {
        delete terreno;
    }

    int obterLargura()
    {
        return terreno->obterLargura();
    }

    int obterProfundidade()
    {
        return terreno->obterAltura();
    }

    Matriz<int>& operator() (int lin, int col)
    {
        //Retorna uma célula específica da matriz terreno(l, c)
        return terreno[(lin*medida)+col];
    }

    void diamondStep()
    {
        
    }

    void squareStep()
    {

    }
};                          
