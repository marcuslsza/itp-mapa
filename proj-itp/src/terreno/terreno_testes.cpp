#pragma once
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "terreno.h"
#include <iostream>

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  srand(time(0));
  Terreno terreno(0); // 2^0 + 1 = 2
  CHECK(terreno.obterLargura() == 2);
  CHECK(terreno.obterProfundidade() == 2);
  terreno.imprimirMatriz();
  CHECK(terreno(0,0) == 10);
  CHECK(terreno(0,1) == 10);
  CHECK(terreno(1,0) == 10);
  CHECK(terreno(1,1) == 10);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
  Terreno terreno(2);
  CHECK(terreno.obterLargura() == 5);
  CHECK(terreno.obterProfundidade() == 5);
  terreno.imprimirMatriz();
  CHECK(terreno(0,0) == 10);
  CHECK(terreno(0,4) == 10);
  CHECK(terreno(4,0) == 10);
  CHECK(terreno(4,4) == 10);
}

TEST_CASE("Testa o terreno gerado pela seed 10") {
  srand(10);
  Terreno terreno(2);
  CHECK(terreno(0,0) == 5);
  CHECK(terreno(0,2) == 6);
  CHECK(terreno(3,4) == 4);

  terreno.imprimirMatriz();
  std::cout << '\n';
}

TEST_CASE("Testa o terreno gerado pela seed 20") {
  srand(20);
  Terreno terreno(3);

  CHECK(terreno(0,6) == 7);
  CHECK(terreno(3,4) == 3);
  CHECK(terreno(5,4) == 6);
  terreno.imprimirMatriz();
}



// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Por exemplo, você pode criar testes para os métodos das etapas Square e Diamond
// Você pode torná-los públicos temporariamente para fins de teste ou usar técnicas como "friend testing".