#ifndef INTERFACESERIAL_H
#define INTERFACESERIAL_H

#include "SerieDeCanal.h"
#include <string>
#include <windows.h>

using namespace std;

/**
 * Faz a interface com a placa, usando a porta serial
 *
 * Os dados sao lidos seguindo o seguinte formato:
 * T: NOME1, NOME2, NOME3,... // para os titulos
 * A: VALOR1, VALOR2, VALOR3,... // para os valores
 *
 * Baseado em http://playground.arduino.cc/Interfacing/CPPWindows
 * @Version EP2
 */
class InterfaceSerial {
public:
  /**
   * Cria a comunicacao usando uma porta.
   * @Version EP2
   */
  InterfaceSerial(string porta);
  virtual ~InterfaceSerial();

  /**
   * Inicializa a interface serial.
   * @Version EP2
   */
  void inicializar();

  /**
   * Registra a serie de canal a um canal.
   * @Version EP2
   */
  void registrar(string canal, SerieDeCanal* serie);

  /**
   * Atualiza as series registradas com o canal.
   *
   * Em caso de problema de leitura, retorna false. Caso
   * contrario, retorna true.
   */
  bool atualizar();

  /**
   * Obtem um arranjo com todos os nomes dos canais disponiveis
   * @Version EP2
   */
  string* getNomeDosCanais();

  /**
   * Informa a quantidade de canais disponiveis.
   * @Version EP2
   */
  int getQuantidadeDeCanais();

private:
  // Metodos internos, de apoio
  void conectar();
  void desconectar();
  int ler(char *buffer, unsigned int numeroDeCaracteres);
  int encontraHeader(char* buffer, int inicio, int tamanho);

  string* canaisRegistrados;
  SerieDeCanal** registradas;
  int quantidadeDeSeriesRegistradas;
  string* canais;
  int quantidadeDeCanais;
  string porta;
  bool conectado = false;

  // Variaveis para comunicacao em baixo nivel - Windows
  HANDLE serial;
  COMSTAT status;
  DWORD errors;
};

#endif // INTERFACESERIAL_H
