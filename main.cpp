#include <iostream>
#include <string>
#include "InterfaceSerial.h"
#include "IHC.h"
#include "Grafico.h"
#include "Tela.h"
#include "SerieDeCanal.h"
#include "Tempo.h"
#include "EixoDinamico.h"


using namespace std;

int main() {
    string  tituloX, tituloY, unidX, unidY;
    int serieX, serieY, qtdMaxX, qtdMaxY;
    double minEixoX, minEixoY, maxEixoX, maxEixoY;
    char dinamX, dinamY;
    //Calculando numero de divisoes
    int numDivX = (LARGURA_UTIL - 1)/DIVISAO_ABSCISSA;
    int numDivY = (ALTURA_UTIL - 1)/DIVISAO_ORDENADA;

    InterfaceSerial *is = new InterfaceSerial("\\\\.\\COM4");
    //is->inicializar();

    cout << "Aperte o botao reset da placa" << endl;

    /* Entrada eixo X*/
    cout << "Escolha uma serie para o eixo X:" << endl;
    cout << "0) Tempo" << endl;

    /* Escolhe serie */
    for(int i = 0; i < is->getQuantidadeDeCanais(); i++){
        cout << i+1 <<") " << is->getNomeDosCanais()[i] << endl;
    }
    cin >> serieX;

    cout << "Informe a quantidade maxima de valores: ";
    cin >> qtdMaxX;
    cout << "O eixo deve ser (e)statico ou (d)inamico ? ";
    cin >> dinamX;
    if(serieX != 0){
        cout << "Informe o titulo: ";
        cin >> tituloX;
    }
    cout << "Informe a unidade do eixo X: ";
    cin >> unidX;
    cout << "Infomre a escala minima inicial do eixo X: ";
    cin >> minEixoX;
    cout << "Informe a escala maxima inicial do eixo X: ";
    cin >> maxEixoX;

    Tempo *tempo = new Tempo(qtdMaxX);
    SerieDeCanal *sX;
    Eixo *eX;

    if(dinamX == 'd'){
        if(serieX == 0){
            eX = new EixoDinamico(tempo, unidX, numDivX, minEixoX, maxEixoX);
        }else{
            sX = new SerieDeCanal(is->getNomeDosCanais()[serieX-1], qtdMaxX);
            eX = new EixoDinamico(sX, unidX, numDivX, minEixoX, maxEixoX);
        }
    }else{
        if(serieX != 0)
            sX = new SerieDeCanal(is->getNomeDosCanais()[serieX-1], qtdMaxX);
        eX = new Eixo(tituloX, unidX, numDivX, minEixoX, maxEixoX);
    }






    /* Entrada eixo Y*/
    cout << "Escolha uma serie para o eixo Y:" << endl;
    if(serieX != 0) cout << "0) Tempo" << endl;

    /* Escolhe serie */
    for(int i = 0; i < is->getQuantidadeDeCanais(); i++){
        cout << i+1 <<") " << is->getNomeDosCanais()[i] << endl;
    }
    cin >> serieY;

    cout << "Informe a quantidade maxima de valores: ";
    cin >> qtdMaxY;
    cout << "O eixo deve ser (e)statico ou (d)inamico ? ";
    cin >> dinamY;
    if(serieY != 0){
        cout << "Informe o titulo: ";
        cin >> tituloY;
    }
    cout << "Informe a unidade do eixo Y: ";
    cin >> unidY;
    cout << "Infomre a escala minima inicial do eixo Y: ";
    cin >> minEixoY;
    cout << "Informe a escala maxima inicial do eixo Y: ";
    cin >> maxEixoY;

    Eixo *eY;
    SerieDeCanal *sY;
int x;
    if(dinamY == 'd'){
        if(serieY == 0){
            eY = new EixoDinamico(tempo, unidY, numDivY, minEixoY, maxEixoY);
        }else{
            sY = new SerieDeCanal(is->getNomeDosCanais()[serieY-1], qtdMaxY);
            eY = new EixoDinamico(sY, unidY, numDivY, minEixoY, maxEixoY);
        }
    }else{
        if(serieY != 0 )
            sY = new SerieDeCanal(is->getNomeDosCanais()[serieY-1], qtdMaxY);
        eY = new Eixo(tituloY, unidY, numDivY, minEixoY, maxEixoY);
    }

    /* Inicializando Grafico */

    Tela *tela = new Tela();
    Grafico *g;

    if(serieX == 0)
        g = new Grafico(tela, tempo, sY, eX, eY);
    else if(serieY == 0)
        g = new Grafico(tela, sX, tempo, eX, eY);
    else
        g = new Grafico(tela, sX, sY, eX, eY);

    double i = 0;
    while (!IHC::escFoiPressionado()) {
        if(serieX == 0 || serieY == 0){
            tempo->incrementar();
        }
        //is->atualizar();
        sY->adicionar(10*i);
        g->desenhar();
        i = i + 1;
        IHC::sleep();
    }

    delete is;
    delete tempo;
    delete sX;
    delete eX;
    delete sY;
    delete eY;
    delete tela;
    delete g;


    return 0;
}
