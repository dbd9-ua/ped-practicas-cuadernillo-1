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
TPoro::TPoro(TPoro &sth)
{
    this->x = sth.x;
    this->y = sth.y;
    this->volumen = sth.volumen;
    this->color = sth.color;
}

TPoro &TPoro::operator=(TPoro &sth)
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

    return *this; // lvalue
}

TPoro::~TPoro()
{
    //?
}
bool TPoro::operator==(TPoro &tporo2)
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

/* ostream &operator<<(ostream &os, const TPoro &poro)
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
 */
bool TPoro::operator!=(TPoro &sth)
{
    return !(sth==*this);
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

int TPoro::PosicionX(){
    return this->x;
}

int TPoro::PosicionY(){
    return this->y;
}

double TPoro::Volumen(){
    return this->volumen;
}

char* TPoro::Color(){
    return this->color;
}

bool TPoro::EsVacio(){
    if(this->x==0 &&
        this->y==0&&
        this->color==nullptr&&
        this->volumen==0){
        return true;
    }else{
        return false;
    }
}




