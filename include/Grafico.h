#ifndef GRAFICO_H
#define GRAFICO_H

#include <string>
#include "Serie.h"
#include "Eixo.h"
#include "Tela.h"

using namespace std;

/**
 * O grafico deve receber duas series, as informacoes dos eixos e plotar
 * na tela (que tem tamanho limitado). Portanto, deve-se converter as
 * coordenadas das serie para o espaco disponivel no eixo.
 *
 * Note que ela deve permitir o uso de diferentes series e eixos.
 *
 * @Version EP2
 */
class Grafico {
public:
  Grafico(Tela* tela, Serie* x, Serie *y, Eixo* abscissas, Eixo* ordenadas);
  virtual ~Grafico();

  /**
   * Desenha o grafico, colocando na tela os eixos e os pontos.
   */
  virtual void desenhar();

  /**
   * Apaga a tela.
   */
  virtual void reset();

  virtual Serie* getSerieNasAbscissas();
  virtual Serie* getSerieNasOrdenadas();
  virtual Eixo* getEixoDasAbscissas();
  virtual Eixo* getEixoDasOrdenadas();
private:

  Serie* serieX;
  Serie* serieY;

  Eixo* eixoX;
  Eixo* eixoY;

  Tela* tela;
};

#endif // GRAFICO_H
