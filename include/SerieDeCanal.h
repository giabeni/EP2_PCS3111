#ifndef SERIEDECANAL_H
#define SERIEDECANAL_H

#define MAX_FILA 500

class SerieDeCanal : public Serie{
public:
    /**
    * Cria uma SerieDeCanal com um nome e uma quantidade máxima de valores.
    * Se a quantidade máxima for 3, por exemplo, a Serie poderá ter os
    * valores 5, 7 e 8. Ao adicionar o valor 2, a série deve ficar com os
    * valores 7, 8 e 2.
    */
    SerieDeCanal (string nome, int quantidadeMaxima);
    ~SerieDeCanal();
    /**
    * Adiciona o valor a serie.
    *
    * Apenas os últimos 'quantidadeMaxima' valores sao armazenados. Deve
    * ser implementado como uma fila circular.
    *
    * Por exemplo, se a serie tem quantidadeMaxima = 5 e possui os
    * valores 1, 2, 3, 5, 7, ao chamar adicionar(11), a serie ficara
    * 2, 3, 5, 7, 11.
    * (Enqueue)
    */
    virtual void adicionar (double valor);

protected:
    int quantidadeMaxima;
    /*dados da fila*/
    int tamanho = MAX_FILA;
    double* valores[tamanho];
    int inicio = 0;
    int fim = 0;

};

#endif // SERIEDECANAL_H
