#include <iostream>
#include <string>
#include "InterfaceSerial.h"
#include "IHC.h"
#include "Grafico.h"
#include "Tela.h"
#include "Serie.h"

using namespace std;

int main() {
    string serieX, serieY, canalX, canalY, tituloX, tituloY, unidX, unidY;
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
    cin >> maxEixoY;

    Serie *sX = new Serie();
    sX->setNome(serieX);
    Serie *sY = new Serie();
    sY->setNome(serieY);

    InterfaceSerial *is = new InterfaceSerial();
    is->inicializar ("\\\\.\\COM4");
    is->registrar(canalX, sX);
    is->registrar(canalY, sY);

    Grafico* graf = new Grafico();
    graf->setTela (new Tela() );
    graf->setSerieNasAbscissas(sX);
    graf->setSerieNasOrdenadas(sY);
    graf->setEixoDasAbscissas(tituloX, unidX, minEixoX, maxEixoX);
    graf->setEixoDasOrdenadas(tituloY, unidY, minEixoY, maxEixoY);

    IHC* ihc = new IHC();
    while (!ihc->escFoiPressionado()) {
        is->atualizar();
        graf->desenhar();
        ihc->sleep();
    }


    return 0;
}
