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
    TPoro(TPoro &);
    ~TPoro();
    TPoro &operator=(TPoro &);

    // Sobrecarga del operador igualdad
    bool operator==(TPoro &);

    // Sobrecarga del operador desigualdad
     bool operator!=(TPoro &);

    // Modifica la posición
    void Posicion(int, int);
    // Modifica el volumen
    void Volumen(double);
    // Modifica el color
    void Color(char *);
    // Devuelve la coordenada x de la posición
    int PosicionX();
    // Devuelve la coordenada y de la posición
    int PosicionY();
    // Devuelve el volumen
    double Volumen();
    // Devuelve el color
    char *Color();
    // Devuelve cierto si el poro está vacío
    bool EsVacio();

    // Sobrecarga del operador SALIDA
    friend ostream& operator<<(ostream &, const TPoro &); 
    
};
