#include "Eixo.h"

#include <iostream>
#include <string>



/* ------ Setters --------------------------*/

void Eixo::setTitulo(string titulo){
	this->titulo = titulo;
}

void Eixo::setUnidade(string unidade){
	this->unidade = unidade;
}

void Eixo::setNumeroDeDivisoes(int numero){
	this->numeroDeDivisoes = numero;
}

void Eixo::setEscalaMinima(double escalaMinima){
	this->escalaMinima = escalaMinima;
}

void Eixo::setEscalaMaxima(double escalaMaxima){
	this->escalaMaxima = escalaMaxima;
}

/* ----- Getters -------------------------*/

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




