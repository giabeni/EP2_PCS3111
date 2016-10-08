#ifndef IHC_H
#define IHC_H

/**
 * Classe de apoio para interface com usuario.
 * @Version EP1
 */
class IHC {
public:
  /**
   * Informa se a tecla ESC foi pressionada.
   */
  bool escFoiPressionado();

  /**
   * Espera por alguns ms.
   */
  void sleep();
};

#endif // IHC_H
