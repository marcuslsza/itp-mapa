#include "../terreno/terreno.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string filenamePaleta, filenamePPM;
    int tamanho;
    
    cout << "Nome do arquivo com a paleta de cores: ";
    cin >> filenamePaleta;

    cout << "Tamanho do mapa: ";
    cin >> tamanho;

    cout << "Nome do arquivo PPM a ser salvo: ";
    cin >> filenamePPM;

    Paleta paleta(filenamePaleta);
    Terreno terreno(tamanho);
    
    terreno.geradorImagem(paleta);
}