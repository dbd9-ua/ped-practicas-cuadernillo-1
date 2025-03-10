#include "./../include/tporo.h"
#include <string.h>

TPoro::TPoro()
{ // un TPoro que además es vacío
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = NULL;
}
TPoro::TPoro(int x, int y, double d)
{
    this->x = x;
    this->y = y;
    this->volumen = d;
    this->color = NULL;
}
TPoro::TPoro(int x, int y, double d, char *c /*cadena del color*/)
{
    this->x = x;
    this->y = y;
    this->volumen = d;
    this->color = c;
}
TPoro::TPoro(const TPoro &sth)
{
    this->x = sth.x;
    this->y = sth.y;
    this->volumen = sth.volumen;
    this->color = sth.color;
}
TPoro::~TPoro()
{
   delete [] this->color;
   this->x=0;
   this->y=0;
   this->volumen=0.0;
}

TPoro& TPoro::operator=(const TPoro &sth)
{
    TPoro t{sth.x, sth.y, sth.volumen, sth.color};

    if (sth.color != nullptr)
    {
        this->color = new char[strlen(sth.color) + 1];
        strcpy(this->color, sth.color);
    }
    else
    {
        this->color = nullptr;
    }

    return *this; // retorna algo por referencia no por valor. a=b: a.=(b) y no es const. 
                    //Lo de rvalue y lvalue solo se estudia en el paso de parametros. valores temporales de ambitos.
}

bool TPoro::operator==(const TPoro &tporo2)const
{
    /*     En el “operator==”, dos poros son iguales si poseen la misma posición, el mismo volumen y el
    mismo color.
     */
    if ((this->x == tporo2.x && this->y == tporo2.y) /*misma posición*/ && this->volumen == tporo2.volumen &&
        strcmp(this->color, tporo2.color) == 0 /*las cadenas son iguales*/)
    {
        return true;
    }
    return false;
}

 ostream &operator<<(ostream &os, const TPoro &poro)
{
    if (!poro.EsVacio())
    {
        os.setf(ios::fixed);
        os.precision(2);
        os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";
        if (poro.color != NULL)
            os << poro.color;
        else
            os << "-";
    }
    else
        os << "()";
    return os;
}
 
bool TPoro::operator!=(const TPoro &sth)const
{
      /*     En el “operator==”, dos poros son iguales si poseen la misma posición, el mismo volumen y el
    mismo color.
     */
    if ((this->x == sth.x && this->y == sth.y) /*misma posición*/ && this->volumen == sth.volumen &&
        strcmp(this->color, sth.color) == 0 /*las cadenas son iguales*/)
    {
        return false;
    }
    return true;
}

void TPoro::Posicion(int x, int y){
    this->x=x;
    this->y=y;
}

void TPoro::Volumen(double d){
    this->volumen=d;
}

void TPoro::Color(char* color){
    //Puede ser que ya tenga un arreglo de caracteres o sea un puntero nulo
    if (this->color==nullptr)
    {
        this->color=new char[strlen(color)+1];
        strcpy(this->color,color);
    }else{
        delete this->color;//no es un puntero nulo.
        this->color=new char[strlen(color)+1];
        strcpy(this->color,color);
    }

    
}

int TPoro::PosicionX()const{
    return this->x;
}

int TPoro::PosicionY()const{
    return this->y;
}

double TPoro::Volumen()const{
    return this->volumen;
}

char* TPoro::Color()const{
    return this->color;
}

bool TPoro::EsVacio()const{
    if(this->x==0 &&
        this->y==0&&
        this->color==nullptr&&
        this->volumen==0){
        return true;
    }else{
        return false;
    }
}




