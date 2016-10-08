#include "SerieDeCanal.h"

SerieDeCanal::SerieDeCanal(string nome, int quantidadeMaxima) : Serie(nome){
    this->quantidadeMaxima = quantidadeMaxima;
}

SerieDeCanal::~SerieDeCanal(){
    //dtor
}

void SerieDeCanal::adicionar(double valor){
    if(this->getMaximo() == NAN && this->getMinimo() == NAN){
        this->maximo = valor;
        this->minimo = valor;
        this->vazia = false;
    }else{
        if(valor < this->getMinimo()) this->minimo = valor;
        if(valor > this->getMaximo()) this->maximo = valor;
    }

    this->valores[this->fim] = valor;
    if(this->fim == this->tamanho)
        this->fim = 0;
    else
        this->fim++;

    //ATUALIZAR INICIO : inicio = fim - quantidadeMaxima
}
