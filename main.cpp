#include <iostream>
using namespace std;

class Nod
{
private:
    char info;
    Nod *next;
public:
    void alocare_initiala()
    {cin>>info;
    next=NULL;}

    Nod *alocare_adresa(Nod* adresa)
    {
        next=adresa;
    }

    void alocare_caracter()
    {
        cin>>info;
    }

    char interogare_info()
    {
        return info;
    }
    Nod* interogare_next()
    {
        return next;
    }
};

class Coada_de_caractere
{
    private:
Nod *inceput,*sfarsit;
    public:
Coada_de_caractere()
{
    inceput=NULL;
    sfarsit=NULL;
}
void push()
{
Nod* curent=new Nod;
if (inceput==NULL)
    {curent->alocare_initiala();
     inceput=curent;
     sfarsit=curent;}
else
    {
    sfarsit->alocare_adresa(curent);
    curent->alocare_caracter();
    curent->alocare_adresa(NULL);
    }
}

bool isempty()
{
    if (inceput==NULL)
        return true;
    else return false;
}

};


int main()
{
    Coada_de_caractere coada;
    //coada.push();
    //coada.push();
    return 0;
}
