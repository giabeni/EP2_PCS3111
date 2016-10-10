#ifndef TEMPO_H
#define TEMPO_H

#include "Serie.h"

class Tempo : public Serie{
public:
    /**  * O nome da serie deve ser sempre "Tempo". O tamanhoDaFaixa
    * define o tamanho da faixa de tempo. Se o tamanhoDaFaixa for
    * 3, por exemplo, o tamanho máximo da Serie sera 3 e,
    * portanto, só os 3 últimos valores serão guardados.  */
    Tempo(int tamanhoDaFaixa);
    virtual ~Tempo();

    /**  * Coloca o próximo valor de tempo nesta Serie.  */
    virtual void incrementar();



    /**
    * Informa se a serie esta vazia.
    */
    bool estaVazia();

    /**
    * Informa o numero de valores que a serie possui.
    * Por exemplo, a serie (1, 2, 3, 5) possui tamanho 4.
    */
    int getTamanho();

    /**
    * Obtem o valor que esta na posicao definida da serie. A contagem de
    * posicoes comeca em 0.
    *
    * Em caso de posicoes invalidas, retorne 0.
    *
    * Por exemplo, considere a serie (1, 2, 3, 5, 7, 11, 13). O metodo
    * getValor(0) deve retornar 1; getValor(6) deve retornar 13.
    */
    double getValor(int posicao);

    /**
    * Obtem o maior valor da serie.
    */
    double getMaximo();

    /**
    * Obtem o menor valor da serie.
    */
    double getMinimo();

private:
    int tamanhoDaFaixa;
    /*dados da fila*/
    static const int tamanho = NUMERO_MAXIMO_VALORES;
    double valores[tamanho];
    int inicio = 0;
    int fim = 0;
};

#endif // TEMPO_H
