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
    /*string serieX, serieY, canalX, canalY, tituloX, tituloY, unidX, unidY;
    int minEixoX, minEixoY, maxEixoX, maxEixoY;

    cout << "Serie no eixo x: ";
    cin >> serieX;
    cout << "Canal x: ";
    cin >> canalX;
    cout << "Titulo do eixo x: ";
    cin >> tituloX;
    cout << "Unidade do eixo x: ";
    cin >> unidX;
    cout << "Escala minima do eixo x: ";
    cin >> minEixoX;
    cout << "Escala maxima do eixo x: ";
    cin >> maxEixoX;

    cout << "Serie no eixo y: ";
    cin >> serieY;
    cout << "Canal y: ";
    cin >> canalY;
    cout << "Titulo do eixo y: ";
    cin >> tituloY;
    cout << "Unidade do eixo y: ";
    cin >> unidY;
    cout << "Escala minima do eixo y: ";
    cin >> minEixoY;
    cout << "Escala maxima do eixo y: ";
    cin >> maxEixoY;*/

    SerieDeCanal *sC = new SerieDeCanal("Gabriel" , 5);
    sC->adicionar(10);
    sC->adicionar(20);
    sC->adicionar(30);
    sC->adicionar(40);
    sC->adicionar(50);
    sC->adicionar(60);

    Tempo *t = new Tempo(5);
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();

    Tela *tela = new Tela();
    EixoDinamico *eX = new EixoDinamico(t, "s", 1, 1, 10);
    EixoDinamico *eY = new EixoDinamico(sC, "s", 1, 0, 100);
    Grafico* graf = new Grafico(tela, t, sC, eX, eY);

    /*InterfaceSerial *is = new InterfaceSerial("\\\\.\\COM4");
    is->inicializar ();
    is->registrar("a", t);
    is->registrar("b", sC);*/

    graf->desenhar();

    /*while (!IHC::escFoiPressionado()) {
        //is->atualizar();
        graf->desenhar();
        IHC::sleep();
    }*/




    return 0;
}
