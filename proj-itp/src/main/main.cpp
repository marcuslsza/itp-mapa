#include "terreno/terreno.h"
#include "paleta/paleta.h"
#include <iostream>
#include <string>
using namespace std;

int main(void){

    string nomeArquivoPaleta, novoArquivo;
    int tamanhoMapa;

    cout << "Digite o nome do arquivo contendo a paleta de cores a ser usada na imagem: \n";
    cin >> nomeArquivoPaleta;
    

    cout << "Digite o tamanho do mapa de altitudes: \n";
    cin >> tamanhoMapa;
    


    cout << "Digite o nome do novo arquivo PPM a ser salvo: \n";
    cin >> novoArquivo;


    Paleta paleta(nomeArquivoPaleta);
    Terreno terreno(tamanhoMapa);


    return 0;
}