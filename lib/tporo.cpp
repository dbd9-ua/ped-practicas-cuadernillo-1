#include "./../include/tporo.h"
#include <string.h>

TPoro::TPoro()
{ // un TPoro que además es vacío
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = NULL;
}
TPoro::TPoro(int x, int y, double d){
    this->x=x;
    this->y=y;
    this->volumen=d;
    this->color=NULL;
}
TPoro::TPoro(int x, int y, double d, char* c/*cadena del color*/){
    this->x=x;
    this->y=y;
    this->volumen=d;
    this->color=c;
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

/* ostream& operator<<(ostream& os,const TPoro& poro){
    if(!poro.EsVacio()){ 
        os.setf(ios::fixed); 
        os.precision( 2 ); 
        os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" "; 
        if(poro.color!=NULL) 
        os<<poro.color; 
        else 
        os<<"-"; 
        } 
        else 
        os << "()"; 
        return os; 
}
 */
int TPoro::getx(){
    return this->x;
}
void TPoro::setx(int sth){
    this->x= sth;
}




