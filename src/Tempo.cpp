#include "Tempo.h"

Tempo::Tempo(int tamanhoDaFaixa) : Serie("Tempo"){
    this->tamanhoDaFaixa = tamanhoDaFaixa;
}

Tempo::~Tempo(){
    //dtor
}

void Tempo::incrementar(){
    /* atualiza tempo*/
    this->tempoFinal = this->tempoFinal + 1;
    this->vazia = false;
    if(this->tempoFinal > this->tamanhoDaFaixa){
        this->minimo = this->minimo + 1;
    }
    this->maximo = this->tempoFinal;


}

bool Tempo::estaVazia(){
	return this->vazia;
}

int Tempo::getTamanho(){
	if(tempoFinal < tamanhoDaFaixa)
        return tempoFinal;
	return tamanhoDaFaixa;
}
double Tempo::getValor(int posicao){
    double v = this->tempoFinal - (this->tamanhoDaFaixa - posicao - 1);
    if(this->tempoFinal < this->tamanhoDaFaixa)
        return posicao + 1;
    if(v > 0)
        return v;
    else
        return this->tempoFinal + posicao;

}

double Tempo::getMaximo(){
	return this->maximo;
}

double Tempo::getMinimo(){
	return this->minimo;
}
