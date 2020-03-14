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
        cin >> info;
        next = NULL;
    }

    explicit Nod(char informatie)
    {
        info = informatie;
        next = NULL;
    }

    void seteaza_next(Nod* adresa)
    {
        next = adresa;
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
    Nod *inceput, *sfarsit;
public:
    Coada_de_caractere()
    {
        inceput = NULL;
        sfarsit = NULL;
    }
    void adaugare()
    {
        Nod* curent = new Nod;
        if (inceput == NULL)
        {
            inceput = curent;
            sfarsit = curent;
        }
        else
        {
            sfarsit -> seteaza_next(curent);
            sfarsit = curent;
        }
        sfarsit -> seteaza_next(NULL);

    }

    void adaugare(char informatie)
    {
        Nod* curent = new Nod(informatie);
        if (inceput == NULL)
        {
            inceput = curent;
            sfarsit = curent;
        }
        else
        {
            sfarsit -> seteaza_next(curent);
            sfarsit = curent;
        }
        sfarsit -> seteaza_next(NULL);
    }

    void elimina()
    {
        Nod* curent = inceput;
        if (curent == sfarsit)
        {
            inceput = NULL;
            sfarsit = NULL;
        }
        else
        {
            inceput = inceput -> interogare_next();
            delete curent;
        }
    }

    bool vida()
    {
        return inceput == NULL;
    }

    Coada_de_caractere operator + (const Coada_de_caractere &coada_de_adaugat)
    {
        Coada_de_caractere coada_finala;
        Nod* adresa_ob1 = inceput;
        while(adresa_ob1 != NULL) // adaugam componentele din coada curenta
        {
            coada_finala.adaugare(adresa_ob1 -> interogare_info()); // Luam caracterul dau schimbam adresa
            adresa_ob1 = adresa_ob1 -> interogare_next();
        }
        Nod* adresa_ob2 = coada_de_adaugat.inceput;
        while(adresa_ob2 != NULL)
        {
            coada_finala.adaugare(adresa_ob2 -> interogare_info());
            adresa_ob2 = adresa_ob2 -> interogare_next();
        }
        return coada_finala;
    }


    Coada_de_caractere operator - (Coada_de_caractere &coada_de_adaugat) // problema: se apeleaza destructorul cand avem =
    {
        Coada_de_caractere coada_finala;
        Nod* adresa_ob1 = inceput;
        Nod* adresa_ob2 = coada_de_adaugat.inceput;
        char aux1,aux2;
        while(adresa_ob1 != NULL && adresa_ob2 != NULL)
        {
            aux1 = adresa_ob1 -> interogare_info();
            aux2 = adresa_ob2 -> interogare_info();
            if (aux1 > aux2)
                coada_finala.adaugare(aux1);
            else
                coada_finala.adaugare(aux2);
            // this -> elimina();
            // coada_de_adaugat.elimina();
            adresa_ob1 = adresa_ob1->interogare_next();
            adresa_ob2 = adresa_ob2->interogare_next();
        }

        return coada_finala;
    }

    ~ Coada_de_caractere()
    {

        Nod* curent=inceput;
        Nod* aux;
        while(curent!=NULL)
        {
            aux=curent;
            curent = curent->interogare_next();
            delete aux;
        }
    }

    friend ostream &operator << (ostream& output,const Coada_de_caractere &coada);
    friend istream &operator >> (istream& input,Coada_de_caractere &coada);

};

ostream& operator << (ostream& output,const Coada_de_caractere &coada)
{
    Nod* curent = coada.inceput;
    while(curent != NULL)
    {
        output << curent -> interogare_info()<<' '; // Inainte: curent->afisare_informatie(); Problema.
        curent = curent -> interogare_next();
    }
    return output;
}

istream & operator >> (istream &input,  Coada_de_caractere &coada)
{
    char caracter;
    input >> caracter;
    coada.adaugare(caracter);
    return input; // Pentru a folosii >> de mai multe ori pe aceasi linie
}

Coada_de_caractere& operator >> (Coada_de_caractere &coada,  char informatie)
{
    coada.adaugare(informatie);
    return coada;
}

int main()
{

    Coada_de_caractere coada1, coada2, coada3, coada4;
    coada1 >> 'a' >> 'b';
    coada2.adaugare('c');
    cout << coada1 + coada2 << '\n';
    cout << "coada2 - coada1 = " <<  coada2 - coada1 << '\n';
    cout << "Dati un caracter: ";
    cin >> coada4;
    cout <<  coada4;
    cout << coada4.vida();
    return 0;
}
