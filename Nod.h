#ifndef NOD_H
#define NOD_H
class Nod
{
    private:
        char info;
        Nod* next;
    public:
        Nod();
        Nod(char caracter);
        virtual ~Nod();
        char get_nod();

};

#endif // NOD_H
