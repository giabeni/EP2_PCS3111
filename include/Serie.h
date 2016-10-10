#ifndef SERIE_H
#define SERIE_H

#define NUMERO_MAXIMO_VALORES 500

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * Representa uma serie, obtida pela placa.
 *
 * Series representam um conjunto de valores sequenciais. Por exemplo,
 * pode-se ter uma serie (1, 2, 3, 5, 7, 11, 13). Por enquanto a serie
 * deve ter no maximo NUMERO_MAXIMO_VALORES. Caso se tente adicionar
 * um valor adicional ao maximo, ele deve ser ignorado.
 *
 * @Version EP1
 */
class Serie {
public:
  Serie(string nome);
  virtual ~Serie();
  string getNome();

  /**
   * Informa se a serie esta vazia.
   */
  virtual bool estaVazia() = 0;

  /**
   * Informa o numero de valores que a serie possui.
   * Por exemplo, a serie (1, 2, 3, 5) possui tamanho 4.
   */
  virtual int getTamanho() = 0;

  /**
   * Obtem o valor que esta na posicao definida da serie. A contagem de
   * posicoes comeca em 0.
   *
   * Em caso de posicoes invalidas, retorne 0.
   *
   * Por exemplo, considere a serie (1, 2, 3, 5, 7, 11, 13). O metodo
   * getValor(0) deve retornar 1; getValor(6) deve retornar 13.
   */
  virtual double getValor(int posicao) = 0;

  /**
   * Obtem o maior valor da serie.
   */
  virtual double getMaximo() = 0;

  /**
   * Obtem o menor valor da serie.
   */
  virtual double getMinimo() = 0;

private:
  string nome;

protected:
  bool vazia = true;
  int tamanho = 0;
  double maximo = NAN;
  double minimo = NAN;
};

#endif // SERIE_H
