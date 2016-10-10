#include "Serie.h"

#include <iostream>
#include <string>

Serie::Serie(string nome){
    this->nome = nome;
}

Serie::~Serie(){

}

string Serie::getNome(){
	return this->nome;
}


