#ifndef SERIEDECANAL_H
#define SERIEDECANAL_H

#include "Serie.h"

class SerieDeCanal : public Serie{
public:
    /**
    * Cria uma SerieDeCanal com um nome e uma quantidade m�xima de valores.
    * Se a quantidade m�xima for 3, por exemplo, a Serie poder� ter os
    * valores 5, 7 e 8. Ao adicionar o valor 2, a s�rie deve ficar com os
    * valores 7, 8 e 2.
    */
    SerieDeCanal (string nome, int quantidadeMaxima);
    ~SerieDeCanal();
    /**
    * Adiciona o valor a serie.
    *
    * Apenas os �ltimos 'quantidadeMaxima' valores sao armazenados. Deve
    * ser implementado como uma fila circular.
    *
    * Por exemplo, se a serie tem quantidadeMaxima = 5 e possui os
    * valores 1, 2, 3, 5, 7, ao chamar adicionar(11), a serie ficara
    * 2, 3, 5, 7, 11.
    * (Enqueue)
    */
    virtual void adicionar (double valor);


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

protected:
    int quantidadeMaxima;
    /*dados da fila*/
    static const int tamanho = NUMERO_MAXIMO_VALORES;
    double valores[tamanho];
    int inicio = 0;
    int fim = 0;

private:
    void enqueue(double v);
    void dequeue();

};

#endif // SERIEDECANAL_H
