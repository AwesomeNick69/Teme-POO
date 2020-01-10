///PASCU NICOLAE ROBERT GRUPA:253 Code Blocks

#include <iostream>
#include <typeindex>
using namespace std;

class Candidat;
class Dosar{
protected:
    string nume;
    string domeniu;
    float mediaBac;
public:
    friend class Candidat;
    Dosar();
    Dosar(string nume, string domeniu);
    Dosar(string nume, string domeniu, float mediaBac);
    Dosar(Dosar& x);
    virtual void citire()=0;
    virtual void afisare()=0;
};
Dosar::Dosar()
{
    this->nume="Lorem Ipsum";
    this->domeniu="Lorem Ipsum";
    this->mediaBac=0.0;
}
Dosar::Dosar(string nume, string domeniu)
{
    this->nume=nume;
    this->domeniu=domeniu;
    this->mediaBac=0.0;
}
Dosar::Dosar(string nume, string domeniu, float mediaBac)
{
    this->nume=nume;
    this->domeniu=domeniu;
    this->mediaBac=mediaBac;
}
Dosar::Dosar(Dosar& x)
{
    this->nume=x.nume;
    this->domeniu=x.domeniu;
    this->mediaBac=x.mediaBac;
}
class Dosar_ID : public Dosar{
private:
    const int nr_total=0;
    int nr_dosar;
    float notaMate;
public:
    Dosar_ID(): Dosar(){nr_dosar=nr_total, notaMate=0.0;}
    Dosar_ID(float nota_Mate=0.0): Dosar(nume,domeniu,mediaBac){this->notaMate=notaMate;}
    Dosar_ID(Dosar_ID& x);
    //void citire();
    //void afisare();

};
Dosar_ID::Dosar_ID(Dosar_ID& x)
{
    this->nume=x.nume;
    this->domeniu=x.domeniu;
    this->mediaBac=x.mediaBac;
    this->nr_dosar=x.nr_dosar;
    this->notaMate=x.notaMate;
}
class Dosar_IF : public Dosar{
private:
    const int nr_total=0;
    int nr_dosar;
    float Nota;
public:
    Dosar_IF(): Dosar(){nr_dosar=nr_total, Nota=0.0;};
    Dosar_IF(float Nota): Dosar(nume,domeniu,mediaBac){this->Nota=Nota;}
    Dosar_IF(Dosar_IF& x);
   // void citire();
    //void afisare();

};
Dosar_IF::Dosar_IF(Dosar_IF& x)
{
    this->nume=x.nume;
    this->domeniu=x.domeniu;
    this->mediaBac=x.mediaBac;
    this->nr_dosar=x.nr_dosar;
    this->Nota=x.Nota;
}
class Dosar_IF2 : public Dosar{
private:
    const int nr_total=0;
    int nr_dosar;
    float mediaAbsolvita;
    float Nota;
public:
    Dosar_IF2(): Dosar(){nr_dosar=nr_total,mediaAbsolvita=0.0,Nota=0.0;};
    Dosar_IF2(float Nota): Dosar(nume,domeniu,mediaBac){this->mediaAbsolvita=mediaAbsolvita ,this->Nota=Nota;}
    Dosar_IF2(Dosar_IF2& x);
    //void citire();
    //void afisare();
};
Dosar_IF2::Dosar_IF2(Dosar_IF2& x)
{
    this->nume=x.nume;
    this->domeniu=x.domeniu;
    this->mediaBac=x.mediaBac;
    this->nr_dosar=x.nr_dosar;
    this->mediaAbsolvita=x.mediaAbsolvita;
    this->Nota=x.Nota;
}
class Candidat{
private:
    int legitimatie[10];
    Dosar *x;
    float MA[10];
    int nr_dosare;
    bool admis;
public:
    friend class Dosar;
    Candidat();
    Candidat(Dosar *x);
    Candidat(int legitimatie[], Dosar *x, float MA[], int nr_dosare);
    Candidat(bool admis);
    Candidat(Candidat& x);
    ~Candidat();
    void citire();
    void afisare();
};
Candidat::Candidat()
{
    this->nr_dosare=0;
    this->admis=false;
    this->x=NULL;
    this->legitimatie[0]=0;
}
Candidat::Candidat(Dosar *x)
{
    this->nr_dosare=1;
    this->admis=false;
    this->x=x;
    //if(typeid(x)==Dosar_ID)
    //this->legitimatie[0]=*(Dosar_ID*)x.nr;
}
Candidat::~Candidat()
{
    delete x;
}

int main()
{
    int locID, locIF,nr;
    cout<<"locID= "; cin>>locID;
    cout<<"locIF= "; cin>>locIF;
    cout<<"nr studenti= "; cin>>nr;
    Candidat *Student;

    return 0;
}
