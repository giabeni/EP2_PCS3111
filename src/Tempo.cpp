#include "Tempo.h"

Tempo::Tempo(int tamahoDaFaixa) : Serie("Tempo"){
    this->tamanhoDaFaixa = tamanhoDaFaixa;
}

Tempo::~Tempo(){
    //dtor
}

void Tempo::incrementar(){

    double valor;
    if(this->estaVazia())
        valor = 1;
    else
        valor = this->valores[this->fim - 1] + 1;

    if(this->getMaximo() == NAN && this->getMinimo() == NAN){
        this->maximo = 1;
        this->minimo = 1;
        this->vazia = false;
    }

    this->valores[this->fim] = valor;
    //qtdMax = tamanho - inicio + fim se inicio > fim
    // qtdMax = fim - inicio se fim > inicio
    if(this->fim == this->tamanho - 1){
        this->fim = 0;
        this->inicio++;
    }else{
        this->fim++;
        if(this->inicio < this->fim)
            this->inicio = this->fim - this->tamanhoDaFaixa;
        else
            this->inicio = this->tamanho + this->fim - this->tamanhoDaFaixa;
    }

    this->minimo = this->valores[inicio];
    this->maximo = this->valores[fim - 1];


}

bool Tempo::estaVazia(){
	return this->vazia;
}

int Tempo::getTamanho(){
	return this->fim - this->inicio;
}

double Tempo::getValor(int posicao){
	if(this->inicio + posicao > this->tamanho - 1){
        return this->valores[posicao - this->tamanho + this->inicio];
	}else{
        return this->valores[this->inicio + posicao];
	}
}

double Tempo::getMaximo(){
	return this->maximo;
}

double Tempo::getMinimo(){
	return this->minimo;
}
