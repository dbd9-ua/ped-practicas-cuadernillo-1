#include "./../include/tporo.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    TPoro t{3,4,3.4};
    
   // cout<<t;

    if(t.EsVacio()){
        
        cout<<"t es vacío"<<endl;

    }else{
        cout <<"no es vacío"<<endl;
    }

    return 0;
}
