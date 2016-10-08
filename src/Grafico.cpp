#include "Grafico.h"
#include <string.h>
#include <cmath>

void Grafico::setSerieNasAbscissas(Serie* x) {
    this->serieX = x;
}
void Grafico::setSerieNasOrdenadas(Serie* y) {
    this->serieY = y;
}

void Grafico::setEixoDasAbscissas(string titulo, string unidade, double minimo, double maximo) {
    this->eixoX = new Eixo;

    this->eixoX->setTitulo(titulo);
    this->eixoX->setUnidade(unidade);
    this->eixoX->setEscalaMinima(minimo);
    this->eixoX->setEscalaMaxima(maximo);
    this->eixoX->setNumeroDeDivisoes( (LARGURA_UTIL-1)/DIVISAO_ABSCISSA);
}
void Grafico::setEixoDasOrdenadas(string titulo, string unidade, double minimo, double maximo) {
    this->eixoY = new Eixo;

    this->eixoY->setTitulo(titulo);
    this->eixoY->setUnidade(unidade);
    this->eixoY->setEscalaMinima(minimo);
    this->eixoY->setEscalaMaxima(maximo);
    this->eixoY->setNumeroDeDivisoes( (ALTURA_UTIL-1)/DIVISAO_ORDENADA);
}

void Grafico::desenhar() {
    //adicionar eixos
    this->tela->setEixoDasAbscissas(eixoX);
    this->tela->setEixoDasOrdenadas(eixoY);
    //criando vetor de pontos
    int pontosX[NUMERO_MAXIMO_VALORES];
    int pontosY[NUMERO_MAXIMO_VALORES];

    //nós temos a serie com um vetor de valores
    for(int i = 0; i  < serieX->getTamanho() ; i++){
           double xSerie = serieX->getValor(i);
           int minEixo = eixoX->getEscalaMinima();
           int maxEixo = eixoX->getEscalaMaxima();
           int xMatriz = trunc((xSerie - minEixo)*(LARGURA_UTIL - 1) / (maxEixo - minEixo));
           pontosX[i] = xMatriz;
    }

    for(int i = 0; i  < serieY->getTamanho() ; i++){
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
    this->tela->desenhar();
    }


}

void Grafico::reset() {
    this->tela->apagar();
}

void Grafico::setTela(Tela* t) {
    this->tela = t;
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
