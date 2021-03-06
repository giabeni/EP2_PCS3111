#include "Grafico.h"
#include <string.h>
#include <cmath>

Grafico::Grafico(Tela* tela, Serie* x, Serie *y, Eixo* abscissas, Eixo* ordenadas){
    this->tela = tela;
    this->serieX = x;
    this->serieY = y;
    this->eixoX = abscissas;
    this->eixoY = ordenadas;
}
Grafico::~Grafico(){
    delete serieX;
    delete serieY;
    delete eixoX;
    delete eixoY;
    delete tela;
}

void Grafico::desenhar() {
    this->tela->apagar();
    //adicionar eixos
    this->tela->setEixoDasAbscissas(eixoX);
    this->tela->setEixoDasOrdenadas(eixoY);
    //criando vetor de pontos
    int pontosX[NUMERO_MAXIMO_VALORES];
    int pontosY[NUMERO_MAXIMO_VALORES];

    //n�s temos a serie com um vetor de valores
    for(int i = 0; i  <= serieX->getTamanho() ; i++){
           double xSerie = serieX->getValor(i);
           int minEixo = eixoX->getEscalaMinima();
           int maxEixo = eixoX->getEscalaMaxima();
           int xMatriz = trunc((xSerie - minEixo)*(LARGURA_UTIL - 1) / (maxEixo - minEixo));
           pontosX[i] = xMatriz;
    }

    for(int i = 0; i  <= serieY->getTamanho() ; i++){
           double ySerie = serieY->getValor(i);
           int minEixo = eixoY->getEscalaMinima();
           int maxEixo = eixoY->getEscalaMaxima();
           int yMatriz = trunc((ySerie - minEixo)*(ALTURA_UTIL - 1) / (maxEixo - minEixo));
           pontosY[i] = yMatriz;
    }

    int xSuperior = LARGURA_UTIL - 1;
    int xInferior = 0;
    int ySuperior = ALTURA_UTIL - 1;
    int yInferior = 0;

    for(int i = 0; i  < serieX->getTamanho() ; i++){

        int x = pontosX[i];
        int y = pontosY[i];

        if(x >= xInferior && x <= xSuperior){
            /* dentro do limite abxixa*/
            if(y < yInferior) this->tela->adicionarForaDoLimiteDasOrdenadasEm(x, Limite::INFERIOR);
            else if(y > ySuperior) this->tela->adicionarForaDoLimiteDasOrdenadasEm(x, Limite::SUPERIOR);
            else this->tela->adicionarPontoEm( x, y );
        }else if(y >= yInferior && y <= ySuperior){
            /* dentro do limite ordenada*/
            if(x < xInferior) this->tela->adicionarForaDoLimiteDasAbscissasEm(y, Limite::INFERIOR);
            else if(x > xSuperior) this->tela->adicionarForaDoLimiteDasAbscissasEm(y,Limite::SUPERIOR);
            else this->tela->adicionarPontoEm( x, y );
        }else {
            if(x > xSuperior && y > ySuperior)
                this->tela->adicionarForaDoLimiteEm(Limite::SUPERIOR, Limite::SUPERIOR);
            if(x > xSuperior && y < yInferior)
                this->tela->adicionarForaDoLimiteEm(Limite::SUPERIOR, Limite::INFERIOR);
            if(y < yInferior&& x < xInferior)
                this->tela->adicionarForaDoLimiteEm(Limite::INFERIOR, Limite::INFERIOR);
            if(y < yInferior&& x > xSuperior )
                this->tela->adicionarForaDoLimiteEm(Limite::INFERIOR, Limite::SUPERIOR);
        }


    }

    this->tela->desenhar();

}

void Grafico::reset() {
    this->tela->apagar();
}

Serie* Grafico::getSerieNasAbscissas() {
    return this->serieX;
}
Serie* Grafico::getSerieNasOrdenadas() {
    return this->serieY;
}
Eixo* Grafico::getEixoDasAbscissas() {
    return this->eixoX;
}
Eixo* Grafico::getEixoDasOrdenadas() {
    return this->eixoY;
}
