#include<iostream>
using namespace std;

class TPoro
{
  private:
    int x, y;
    double volumen;
    char *color;

  public:
    TPoro();
    TPoro(int, int, double);
    TPoro(int, int, double, char *);
    TPoro(const TPoro &);
    ~TPoro();
    TPoro &operator=(const TPoro &);//retorna un rvalue este operador

    // Sobrecarga del operador igualdad
    bool operator==(const TPoro &)const;

    // Sobrecarga del operador desigualdad
     bool operator!=(const TPoro &) const;

    // Modifica la posición
    void Posicion(int, int);
    // Modifica el volumen
    void Volumen(double);
    // Modifica el color
    void Color(char *);
    // Devuelve la coordenada x de la posición
    int PosicionX()const;
    // Devuelve la coordenada y de la posición
    int PosicionY()const;
    // Devuelve el volumen
    double Volumen()const;
    // Devuelve el color
    char *Color()const;
    // Devuelve cierto si el poro está vacío
    bool EsVacio()const;

    // Sobrecarga del operador SALIDA
    friend ostream& operator<<(ostream &, const TPoro &); //no modifica la clase pero podría porque es friend.
    
};
