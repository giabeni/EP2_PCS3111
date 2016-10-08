#include "Serie.h"

#include <iostream>
#include <string>

Serie::Serie(string nome){
    this->nome = nome;
}

Serie::~Serie(){

}

/*---- Getters ------*/
string Serie::getNome(){
	return this->nome;
}

bool Serie::estaVazia(){
	return this->vazia;
}

int Serie::getTamanho(){
	return this->tamanho;
}

double Serie::getValor(int posicao){
	if(posicao >= tamanho)
		return 0;
	return this->valores[posicao];
}

double Serie::getMaximo(){
	return this->maximo;
}

double Serie::getMinimo(){
	return this->minimo;
}
