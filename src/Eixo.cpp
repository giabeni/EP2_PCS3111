#include "Eixo.h"

#include <iostream>
#include <string>

Eixo::Eixo(string titulo, string unidade, int numeroDeDivisoes, double escalaMinima, double escalaMaxima){
    this->titulo = titulo;
    this->unidade = unidade;
    this->numeroDeDivisoes = numeroDeDivisoes;
    this->escalaMinima = escalaMinima;
    this->escalaMaxima = escalaMaxima;
}

Eixo::~Eixo(){

}

string Eixo::getTitulo(){
	return this->titulo;
}

string Eixo::getUnidade(){
	return this->unidade;
}

int Eixo::getNumeroDeDivisoes(){
	return this->numeroDeDivisoes;
}

double Eixo::getIncrementoDaDivisao(){
	return (escalaMaxima - escalaMinima)/numeroDeDivisoes;
}

double Eixo::getEscalaMinima(){
	return this->escalaMinima;
}

double Eixo::getEscalaMaxima(){
	return this->escalaMaxima;
}




