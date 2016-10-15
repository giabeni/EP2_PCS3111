#include <iostream>
#include <string>
#include "InterfaceSerial.h"
#include "IHC.h"
#include "Grafico.h"
#include "Tela.h"
#include "SerieDeCanal.h"
#include "Tempo.h"

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

    SerieDeCanal *sC = new SerieDeCanal("Gabriel" , 3);
    sC->adicionar(2);
    sC->adicionar(235);
    sC->adicionar(23);
    sC->adicionar(10);
    sC->adicionar(0);
    sC->adicionar(400);
    sC->adicionar(20);

    for(int i = 0; i < 3; i++){
        cout << sC->getValor(i) << endl;
    }
    cout << sC->getMaximo() << " and " << sC->getMinimo() << endl;

    Tempo *t = new Tempo(10);

    cout << t->getValor(0) << endl;

    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();
    t->incrementar();

    for( int i = 0; i < 6 ; i++){
        cout << t->getValor(i) << " ";
    }
        cout << endl;


    cout << t->getMaximo() << " and " << t->getMinimo();







    return 0;
}
