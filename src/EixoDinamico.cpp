#include "EixoDinamico.h"

EixoDinamico::EixoDinamico(Serie* serie, string unidade, int numeroDeDivisoes,
                           double escalaMinimaInicial, double escalaMaximaInicial) :
                            Eixo(serie->getNome(), unidade, numeroDeDivisoes, escalaMinimaInicial, escalaMaximaInicial){
    this->serie = serie;
    this->escalaMaximaInicial = escalaMaximaInicial;
    this->escalaMinimaInicial = escalaMinimaInicial;
}

EixoDinamico::~EixoDinamico(){
    //dtor
}

double EixoDinamico::getIncrementoDaDivisao(){
	return (this->getEscalaMaxima() - this->getEscalaMinima())/ this->getNumeroDeDivisoes();
}

double EixoDinamico::getEscalaMinima(){
    if(this->serie->getTamanho() < 2 || this->serie->getMaximo() == this->serie->getMinimo())
        return this->escalaMinimaInicial;
	return this->serie->getMinimo();
}

double EixoDinamico::getEscalaMaxima(){
    if(this->serie->getTamanho() < 2 || this->serie->getMaximo() == this->serie->getMinimo())
        return this->escalaMaximaInicial;
	return this->serie->getMaximo();
}

