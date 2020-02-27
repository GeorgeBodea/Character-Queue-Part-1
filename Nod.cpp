#include <iostream>
#include "Nod.h"
Nod::Nod()
{

}


Nod::Nod(char caracter)
{
    info=caracter;
}

char Nod::get_nod()
{
return info;
}


Nod::~Nod()
{
    //dtor
}
