#include <iostream>
using namespace std;

class Nod
{
private:
    char info;
    Nod *next;
public:
    Nod()
    {
        cin>>info;
        next=NULL;
    }

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
    void afisare_informatie()
    {
        cout<<info<<' ';
    }
    Nod* adresa_nod()
    {
        return this;
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
        {
            //curent->alocare_initiala()
            inceput=curent;
            sfarsit=curent;
        }
        else
        {
            sfarsit->alocare_adresa(curent);
            curent->alocare_caracter();
            curent->alocare_adresa(NULL);
        }
    }

    void pop()
    {
        Nod* curent=inceput;
        if (curent==sfarsit)
            {if (curent!=NULL)
                delete curent;}
        else
            {
                Nod* inapoi_curent=inceput;
                curent=curent->interogare_next();
                while(curent!=sfarsit)
                {
                    inapoi_curent=curent;
                    curent=curent->interogare_next();
                }
                delete curent;
                sfarsit=inapoi_curent;
            }
    }

    bool isempty()
    {
        if (inceput==NULL)
            return true;
        else
            return false;
    }

    Nod* interogare_adresa_inceput()
        {return inceput->adresa_nod();}

    friend ostream &operator <<(ostream& output,Coada_de_caractere &coada);

};

ostream& operator <<(ostream& output,Coada_de_caractere &coada)
    {
        Nod* curent=coada.inceput;
        while(curent!=coada.sfarsit)
        {
            output<<curent->interogare_info(); // Inainte: curent->afisare_informatie(); Problema.
            delete curent;
            curent=curent->interogare_next();
        }
        output<< curent->interogare_info(); // Inainte: curent->afisare_informatie();
        //delete curent;
        return output;
    }


int main()
{
    Coada_de_caractere coada;
    coada.push();
    coada.push();
    Nod* p1,p2;
    p1=coada.interogare_adresa_inceput();
    cout<<p1->interogare_info();

    //cout<<coada;
    return 0;
}
