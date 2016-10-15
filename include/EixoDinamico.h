#ifndef EIXODINAMICO_H
#define EIXODINAMICO_H

#include "Eixo.h"
#include "Serie.h"

class EixoDinamico : public Eixo{
public:
    EixoDinamico(Serie* serie, string unidade, int numeroDeDivisoes, double escalaMinimaInicial, double escalaMaximaInicial);
    virtual ~EixoDinamico();
    double getIncrementoDaDivisao();
    double getEscalaMinima();
    double getEscalaMaxima();


protected:

private:
    double escalaMinimaInicial;
    double escalaMaximaInicial;
    Serie* serie;
};

#endif // EIXODINAMICO_H
