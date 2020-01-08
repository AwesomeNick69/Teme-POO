#include <iostream>
#include <list>
#include <typeindex>
using namespace std;

class Animal
{
protected:
    string denumire;
    string locatie;
    string mediu;
public:
    virtual void afisare() = 0;
    virtual void citire() = 0;
    Animal();
    Animal(string denumire);
    Animal(string denumire,string locatie, string mediu);
    Animal(Animal& x);
    ~Animal();
    friend ostream& operator<<(ostream&, Animal&);
    friend istream& operator>>(istream&, Animal&);
    Animal &operator=(Animal&);
};

Animal::Animal()
{
    this->denumire="";
    this->locatie="";
    this->mediu="";
}
Animal::Animal(string denumire)
{
    this->denumire=denumire;
    this->locatie="";
    this->mediu="";
}
Animal::Animal(string denumire,string locatie, string mediu)
{
    this->denumire=denumire;
    this->locatie=locatie;
    this->mediu=mediu;
}
Animal::Animal(Animal& x)
{
    this->denumire=x.denumire;
    this->locatie=x.locatie;
    this->mediu=x.mediu;
}
ostream& operator<<(ostream& out, Animal& x)
{
    out<<x.denumire<<" "<<x.locatie<<" "<<x.mediu<<endl;
    return out;
}
istream& operator>>(istream& in, Animal& x)
{
    in>>x.denumire>>x.locatie>>x.mediu;
    return in;
}
Animal &Animal::operator=(Animal &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    return *this;
}


class Nevertebrate: public Animal{
private:
    float lungime;
    float greutate;
    string clasa;
public:
    Nevertebrate() : Animal(){lungime=0, greutate=0;}
    Nevertebrate(float x, float y) : Animal(denumire){lungime=x, greutate=y;}
    Nevertebrate(float x, float y, string c) : Animal(denumire){lungime=x, greutate=y, clasa=c;}
    Nevertebrate(Nevertebrate& x) : Animal(x){lungime=x.lungime,greutate=x.greutate,clasa=x.clasa;}
    ~Nevertebrate();
    friend ostream& operator<<(ostream&, Nevertebrate&);
    friend istream& operator>>(istream&, Nevertebrate&);
    Nevertebrate &operator=(Nevertebrate& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<clasa<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate>>clasa;
    }
};

ostream& operator<<(ostream& out, Nevertebrate& x)
{
    out<<(Animal&)x;
    out<<x.lungime<<" "<<x.greutate<<" "<<x.clasa<<endl;
    return out;
}
istream& operator>>(istream& in, Nevertebrate& x)
{
    in>>(Animal&)x;
    in>>x.lungime>>x.greutate>>x.clasa;
    return in;
}
Nevertebrate &Nevertebrate::operator=(Nevertebrate &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    clasa=x.clasa;
    return *this;
}


class Vertebrate: public Animal{
protected:
    float lungime;
    float greutate;
public:
    Vertebrate() : Animal(){lungime=0, greutate=0;}
    Vertebrate(float x, float y) : Animal(denumire){lungime=x, greutate=y;}
    Vertebrate(Vertebrate& x) : Animal(x){lungime=x.lungime,greutate=x.greutate;}
    ~Vertebrate();
    friend ostream& operator<<(ostream&, Vertebrate&);
    friend istream& operator>>(istream&, Vertebrate&);
    Vertebrate &operator=(Vertebrate& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate;
    }
};

ostream& operator<<(ostream& out, Vertebrate& x)
{
    out<<(Animal&)x;
    out<<x.lungime<<" "<<x.greutate<<" "<<endl;
    return out;
}
istream& operator>>(istream& in, Vertebrate& x)
{
    in>>(Animal&)x;
    in>>x.lungime>>x.greutate;
    return in;
}
Vertebrate &Vertebrate::operator=(Vertebrate &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    return *this;
}


class Reptile: public Vertebrate{
private:
    string tipul;
    bool pericol;
    int populatie;
public:
    Reptile(): Vertebrate(){populatie=0;}
    Reptile(string a, bool b, int c): Vertebrate(lungime,greutate){tipul=a,pericol=b,populatie=c;}
    Reptile(Reptile& x) : Vertebrate(x){tipul=x.tipul,pericol=x.pericol,populatie=x.populatie;}
    ~Reptile();
    friend ostream& operator<<(ostream&, Reptile&);
    friend istream& operator>>(istream&, Reptile&);
    Reptile &operator=(Reptile& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<endl;
        cout<<tipul<<" "<<pericol<<" "<<populatie<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate;
        cin>>tipul>>pericol>>populatie;
    }
};

ostream& operator<<(ostream& out, Reptile& x)
{
    out<<(Vertebrate&)x;
    out<<x.tipul<<" "<<x.pericol<<" "<<x.populatie<<endl;
    return out;
}
istream& operator>>(istream& in, Reptile& x)
{
    in>>(Vertebrate&)x;
    in>>x.tipul>>x.pericol>>x.populatie;
    return in;
}
Reptile &Reptile::operator=(Reptile &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    tipul=x.tipul;
    pericol=x.pericol;
    populatie=x.populatie;
    return *this;
}


class Mamifere: public Vertebrate{
private:
    string tipul;
    int viteza;
    int populatie;
public:
    Mamifere(): Vertebrate(){populatie=0;}
    Mamifere(string a, int b, int c): Vertebrate(lungime,greutate){tipul=a,viteza=b,populatie=c;}
    Mamifere(Mamifere& x) : Vertebrate(x){tipul=x.tipul,viteza=x.viteza,populatie=x.populatie;}
    ~Mamifere();
    friend ostream& operator<<(ostream&, Mamifere&);
    friend istream& operator>>(istream&, Mamifere&);
    Mamifere &operator=(Mamifere& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<endl;
        cout<<tipul<<" "<<viteza<<" "<<populatie<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate;
        cin>>tipul>>viteza>>populatie;
    }
};

ostream& operator<<(ostream& out, Mamifere& x)
{
    out<<(Vertebrate&)x;
    out<<x.tipul<<" "<<x.viteza<<" "<<x.populatie<<endl;
    return out;
}
istream& operator>>(istream& in, Mamifere& x)
{
    in>>(Vertebrate&)x;
    in>>x.tipul>>x.viteza>>x.populatie;
    return in;
}
Mamifere &Mamifere::operator=(Mamifere &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    tipul=x.tipul;
    viteza=x.viteza;
    populatie=x.populatie;
    return *this;
}


class Pasari: public Vertebrate{
private:
    string tipul;
    bool migratoare;
    int viteza;
    int populatie;
public:
    Pasari(): Vertebrate(){populatie=0;}
    Pasari(string a, bool b, int c, int d): Vertebrate(lungime,greutate){tipul=a,migratoare=b,populatie=d,viteza=c;}
    Pasari(Pasari& x) : Vertebrate(x){tipul=x.tipul,populatie=x.populatie,migratoare=x.migratoare,viteza=x.viteza;}
    ~Pasari();
    friend ostream& operator<<(ostream&, Pasari&);
    friend istream& operator>>(istream&, Pasari&);
    Pasari &operator=(Pasari& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<endl;
        cout<<tipul<<" "<<migratoare<<" "<<populatie<<viteza<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate;
        cin>>tipul>>migratoare>>populatie>>viteza;
    }
};

ostream& operator<<(ostream& out, Pasari& x)
{
    out<<(Vertebrate&)x;
    out<<x.tipul<<" "<<x.viteza<<" "<<x.populatie<<x.migratoare<<endl;
    return out;
}
istream& operator>>(istream& in, Pasari& x)
{
    in>>(Vertebrate&)x;
    in>>x.tipul>>x.viteza>>x.populatie>>x.migratoare;
    return in;
}
Pasari &Pasari::operator=(Pasari &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    tipul=x.tipul;
    viteza=x.viteza;
    populatie=x.populatie;
    migratoare=x.migratoare;
    return *this;
}


class Pesti: public Vertebrate{
private:
    string tipul;
    int viteza;
    int populatie;
public:
    Pesti(): Vertebrate(){populatie=0;}
    Pesti(string a, int b, int c): Vertebrate(lungime,greutate){tipul=a,viteza=b,populatie=c;}
    Pesti(Pesti& x) : Vertebrate(x){tipul=x.tipul,viteza=x.viteza,populatie=x.populatie;}
    ~Pesti();
    friend ostream& operator<<(ostream&, Pesti&);
    friend istream& operator>>(istream&, Pesti&);
    Pesti &operator=(Pesti& );
    void afisare(){
        cout<<denumire<<" "<<mediu<<" "<<locatie<<endl;
        cout<<lungime<<" "<<greutate<<" "<<endl;
        cout<<viteza<<populatie<<endl;
    }
    void citire(){
        cin>>denumire>>mediu>>locatie;
        cin>>lungime>>greutate;
        cin>>viteza>>populatie;
    }
};

ostream& operator<<(ostream& out, Pesti& x)
{
    out<<(Vertebrate&)x;
    out<<x.tipul<<" "<<x.viteza<<" "<<x.populatie<<endl;
    return out;
}
istream& operator>>(istream& in, Pesti& x)
{
    in>>(Vertebrate&)x;
    in>>x.tipul>>x.viteza>>x.populatie;
    return in;
}
Pesti &Pesti::operator=(Pesti &x)
{
    denumire=x.denumire;
    locatie=x.locatie;
    mediu=x.mediu;
    lungime=x.lungime;
    greutate=x.greutate;
    tipul=x.tipul;
    viteza=x.viteza;
    populatie=x.populatie;
    return *this;
}


template <class T>
class AtlasZoologic{
private:
    const int nr_animale;
    list<Animal*> L;
public:
    AtlasZoologic(){nr_animale=0;L=NULL;}
    AtlasZoologic(int nr=0){nr_animale=nr;L=NULL;}
    AtlasZoologic(int nr, list<Animal*> L) {nr_animale=nr,this->L=L;}
    ~AtlasZoologic(){delete L;}
    AtlasZoologic(AtlasZoologic& x) {nr_animale=x.nr_animale, L=x.L;}
    friend ostream& operator<<(ostream&, AtlasZoologic&)
    {
        for(i=0;i<nr_animale;i++){
            if(typeid(L[i]).name()==Nevertebrate){
                out<<*(Nevertebrate*)L[i];
            }
            if(typeid(L[i]).name()==Mamifere){
                out<<*(Mamifere*)L[i];
            }
            if(typeid(L[i]).name()==Reptile){
                out<<*(Reptile*)L[i];
            }
            if(typeid(L[i]).name()==Pasari){
                out<<*(Pasari*)L[i];
            }
        }
    }
    friend istream& operator>>(istream&, AtlasZoologic&){
        nr_animale++;
        if(typeid(L[i]).name()==Nevertebrate)
            *(Nevertebrate*)L.push_back(in);
        if(typeid(L[i]).name()==Mamifere)
            *(Mamifere*)L.push_back(in);
        if(typeid(L[i]).name()==Reptile)
            *(Reptile*)L.push_back(in);
        if(typeid(L[i]).name()==Pasari)
            *(Pasari*)L.push_back(in);
    }
    AtlasZoologic &operator=(AtlasZoologic& );
    AtlasZoologic &operator+=(Animal& );
    void afisare();
};
template <class T>
AtlasZoologic<T>& AtlasZoologic<T>::operator+=(Animal &x){
    nr_animale++;
    L.push_back(*(Animal*));
}
template <>
class AtlasZoologic<Pesti>
{
    private:
    const int nr_animale;
    list<Animal*> L;
public:
    AtlasZoologic(){nr_animale=0;L=NULL;}
    AtlasZoologic(int nr=0){nr_animale=nr;L=NULL;}
    AtlasZoologic(int nr, list<Animal*> L) {nr_animale=nr,this->L=L;}
    ~AtlasZoologic(){delete L;}
    AtlasZoologic(AtlasZoologic& x) {nr_animale=x.nr_animale, L=x.L;}
    friend ostream& operator<<(ostream&, AtlasZoologic&)
    {
        int nr;
        for(i=0;i<nr_animale;i++){
            if(typeid(L[i]).name()==Pesti){
                out<<*(Pesti*)L[i];
                if(*(Pesti*)L[i]->tip=="rapitor" && *(Pesti*)L[i]->lungime>=1)
                    nr++;
            }
        }
        out<<nr;
    }
    friend istream& operator>>(istream&, AtlasZoologic& ){
        nr_animale++;
        if(typeid(L[i]).name()==Pesti)
            (Pesti*)L[nr_animale].push_back(in);
    }
    AtlasZoologic &operator=(AtlasZoologic& );
    AtlasZoologic &operator+(Animal& );
    void afisare();
};
template <class T>
AtlasZoologic<T>& AtlasZoologic<T>::operator+=(Animal &x){
    nr_animale++;
    L.push_back(*(Animal*));
}
int main()
{
    int n;
    AtlasZoologic x[100];
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>AtlasZoologic[i];
    for(i=1;i<=n;i++)
        cout<<AtlasZoologic[i]<<' ';
    return 0;
}
