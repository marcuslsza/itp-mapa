#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "terreno.h"

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  Terreno terreno(0); // 2^0 + 1 = 2
  CHECK(terreno.obterLargura() == 2);
  CHECK(terreno.obterProfundidade() == 2);
  CHECK(terreno(0,0) == 10);
  CHECK(terreno(0,1) == 10);
  CHECK(terreno(1,0) == 10);
  CHECK(terreno(1,1) == 10);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
  Terreno terreno(2);
  CHECK(terreno.obterLargura() == 5);
  CHECK(terreno.obterProfundidade() == 5);
  CHECK(terreno(0,0) == 10);
  CHECK(terreno(0,4) == 10);
  CHECK(terreno(4,0) == 10);
  CHECK(terreno(4,4) == 10);
}


// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Por exemplo, você pode criar testes para os métodos das etapas Square e Diamond
// Você pode torná-los públicos temporariamente para fins de teste ou usar técnicas como "friend testing".