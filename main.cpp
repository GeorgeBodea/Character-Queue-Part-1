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

    Nod(char informatie)
    {
        info=informatie;
        next=NULL;
    }

    Nod(int i)
    {
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

    void alocare_caracter(char informatie)
    {
        info=informatie;
    }

    char interogare_info()
    {
        return info;
    }
    Nod* interogare_next()
    {
        return next;
    }
    Nod* adresa_nod()
    {
        return this;
    }

    void afisare_informatie()
    {
        cout<<info<<' ';
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
    void adaugare()
    {
        Nod* curent=new Nod;
        if (inceput==NULL)
        {
            inceput=curent;
            sfarsit=curent;
            sfarsit->alocare_adresa(NULL);
        }
        else
            {
                sfarsit->alocare_adresa(curent);
                sfarsit=curent;
            }

    }

    void adaugare_pasiva(char informatie) // Altfel, se facea supraincarcarea functie adaugare, care era acelasi lucru
    {
        Nod* curent=new Nod(informatie);
        if (inceput==NULL)
        {
            inceput=curent;
            sfarsit=curent;
            sfarsit->alocare_adresa(NULL);
        }
        else
        {
            sfarsit->alocare_adresa(curent);
            sfarsit=curent;
        }
    }

    void elimina()
    {
        Nod* curent=inceput;
        if (curent==sfarsit)
            {if (curent!=NULL)
                delete curent;
                inceput=NULL;
                sfarsit=NULL;
            }
        else
            {
                inceput=inceput->interogare_next();
                delete curent;
            }
    }

    bool vida()
    {
        if (inceput==NULL)
            return true;
        else
            return false;
    }

Coada_de_caractere operator + (Coada_de_caractere &coada_de_adaugat) /// FARA AMPERSANT = RECURSIE INFINITA
    {
         Coada_de_caractere coada_finala;
         Nod* adresa_ob1=inceput;
         while(adresa_ob1!=NULL) // adaugam componentele din coada curenta
         {

             coada_finala.adaugare_pasiva(adresa_ob1->interogare_info()); // Luam caracterul dau schimbam adresa
             adresa_ob1=adresa_ob1->interogare_next();
         }
         Nod* adresa_ob2=coada_de_adaugat.inceput;
         while(adresa_ob2!=NULL)
         {
             coada_finala.adaugare_pasiva(adresa_ob2->interogare_info());
             adresa_ob2=adresa_ob2->interogare_next();
         }

         return coada_finala;
    }


    Coada_de_caractere operator - (Coada_de_caractere &coada_de_adaugat) /// FARA AMPERSANT = RECURSIE INFINITA
    {
         Coada_de_caractere coada_finala;
         Nod* adresa_ob1=inceput;
         Nod* adresa_ob2=coada_de_adaugat.inceput;
         char aux1,aux2;
         while(adresa_ob1!=NULL && adresa_ob2!=NULL) // adaugam componentele din coada curenta
         {

             aux1=adresa_ob1->interogare_info(); // Luam caracterul dau schimbam adresa
             aux2=adresa_ob2->interogare_info();
             if (aux1>aux2)
                coada_finala.adaugare_pasiva(aux1);
             else
                coada_finala.adaugare_pasiva(aux2);
             this->elimina();
             coada_de_adaugat.elimina();
             adresa_ob1=inceput;
             adresa_ob2=coada_de_adaugat.inceput;
         }

         return coada_finala;
    }

    Nod* interogare_adresa_inceput()
        {return inceput->adresa_nod();}

    friend ostream &operator <<(ostream& output,Coada_de_caractere &coada);
    friend istream &operator >>(istream& input,Coada_de_caractere &coada);

};

ostream& operator <<(ostream& output,Coada_de_caractere &coada)
    {
        Nod* curent=coada.inceput;
        while(curent!=NULL) //
        {
            output<<curent->interogare_info()<<' '; // Inainte: curent->afisare_informatie(); Problema.
            delete curent;
            curent=curent->interogare_next();
        }
        //delete curent;
        return output;
    }

    istream & operator >> (istream &input,  Coada_de_caractere &coada) //putem schimba numele parametrilor fata de prototip?
{
    char caracter;
    input>>caracter;
    coada.adaugare_pasiva(caracter);
    return input;
}



int main()
{
    Coada_de_caractere coada1,coada2;
    cin>>coada1;
    coada1.adaugare();
    cin>>coada2;
    Coada_de_caractere coada3;
    coada3=coada1+coada2;
    cout<<coada3;
    coada3=coada1-coada2;
    cout<<coada3;

    return 0;
}
