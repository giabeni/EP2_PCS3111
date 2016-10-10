#include "SerieDeCanal.h"

SerieDeCanal::SerieDeCanal(string nome, int quantidadeMaxima) : Serie(nome){
    this->quantidadeMaxima = quantidadeMaxima;
}

SerieDeCanal::~SerieDeCanal(){
    //dtor
}

void SerieDeCanal::adicionar(double valor){
    /*if(this->getMaximo() == NAN && this->getMinimo() == NAN){
        this->maximo = valor;
        this->minimo = valor;
        this->vazia = false;
    }else{
        if(valor < this->getMinimo()) this->minimo = valor;
        if(valor > this->getMaximo()) this->maximo = valor;
    }*/

    this->valores[this->fim] = valor;
    //qtdMax = tamanho - inicio + fim se inicio > fim
    // qtdMax = fim - inicio se fim > inicio
    if(this->fim == this->tamanho - 1){
        this->fim = 0;
        this->inicio++;
    }else{
        this->fim++;
        if(this->inicio < this->fim)
            this->inicio = this->fim - this->quantidadeMaxima;
        else
            this->inicio = this->tamanho + this->fim - this->quantidadeMaxima;

    }
}

bool SerieDeCanal::estaVazia(){
	return this->vazia;
}

int SerieDeCanal::getTamanho(){
	return this->fim - this->inicio;
}

double SerieDeCanal::getValor(int posicao){
	if(this->inicio + posicao > this->tamanho - 1){
        return this->valores[posicao - this->tamanho + this->inicio];
	}else{
        return this->valores[this->inicio + posicao];
	}
}

double SerieDeCanal::getMaximo(){
	double maximo = this->valores[inicio];
	for(int i = inicio; i != fim; i++){
        if(i == tamanho) i = 0;
        if(this->valores[i] > maximo)
            maximo = this->valores[i];
	}

	return maximo;
}

double SerieDeCanal::getMinimo(){
	double minimo = this->valores[inicio];
	for(int i = inicio; i != fim; i++){
        if(i == tamanho) i = 0;
        if(this->valores[i] < minimo)
            minimo = this->valores[i];
	}

	return minimo;
}
