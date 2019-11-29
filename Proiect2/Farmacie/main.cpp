#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>
using namespace std;

class Farmacie_abstracta{
protected:
  string denumire;
public:
  Farmacie_abstracta(){
    denumire="NULL";
  };
  Farmacie_abstracta(string c){
    denumire = c;
  };
  Farmacie_abstracta(Farmacie_abstracta& x)
  {
    denumire = x.denumire;
  };
  friend istream& operator>>(istream&, Farmacie_abstracta&);
  Farmacie_abstracta &operator=(Farmacie_abstracta&);
  virtual double calcul_venit()=0;
  virtual void Afisare();
};
istream& operator>>(istream& in, Farmacie_abstracta& x)
{
    in>>x.denumire;
    return in;
}
Farmacie_abstracta &Farmacie_abstracta::operator=(Farmacie_abstracta &x)
{
    denumire=x.denumire;
    return *this;
}

class Farmacie_offline: public Farmacie_abstracta{
protected:
  int nr_luni;
  double* cifra_afaceri_luna;
public:
  Farmacie_offline() : Farmacie_abstracta(){nr_luni=0;cifra_afaceri_luna=0;}
  Farmacie_offline(string c) : Farmacie_abstracta(c){nr_luni=0;cifra_afaceri_luna=0;}
  Farmacie_offline(string c, int nr ) : Farmacie_abstracta(c){nr_luni=nr;cifra_afaceri_luna=NULL;}
  Farmacie_offline(string c, int nr, double* cal ) : Farmacie_abstracta(c){nr_luni=nr;cifra_afaceri_luna=cal;}
  Farmacie_offline(Farmacie_offline& x) : Farmacie_abstracta(x){nr_luni=x.nr_luni; cifra_afaceri_luna=x.cifra_afaceri_luna;}
  ~Farmacie_offline(){delete []cifra_afaceri_luna;}
  friend istream& operator>>(istream&, Farmacie_offline&);
  Farmacie_offline &operator=(Farmacie_offline&);
  double calcul_venit(){
    double sum=0;
    int i;
    for(i=1;i<=nr_luni;i++)
      sum=sum+cifra_afaceri_luna[i];
    return sum;
  }
  void afisare()
  {
    cout<<"Denumirea= "<<denumire<<endl;
    cout<<"Nr. luni= "<<nr_luni<<endl;
    int i;
    for(i=1;i<=nr_luni;i++)
      cout<<cifra_afaceri_luna[i]<<" "<<endl;
  }

};
istream& operator>>(istream& in, Farmacie_offline& x)
{
    in>>(Farmacie_abstracta&)x;
    in>>x.nr_luni;
    x.cifra_afaceri_luna = new double;
    int i;
    for(i=1;i<=x.nr_luni;i++)
      in>>x.cifra_afaceri_luna[i];
    return in;
}
Farmacie_offline &Farmacie_offline::operator=(Farmacie_offline &x)
{
    Farmacie_abstracta::operator=(x);
    nr_luni=x.nr_luni;
    cifra_afaceri_luna=x.cifra_afaceri_luna;
    return *this;
}

class Farmacie_online: public Farmacie_abstracta{
protected:
  char* adresa_web;
  int nr_vizitatori;
public:
  double calcul_venit();
  void Afisare(){
  {
      cout<<"Denumirea= "<<denumire<<endl;
      cout<<"Nr. vizitatori=  "<<nr_vizitatori<<endl;
      cout<<"Wed: "<<endl;
      cout<<adresa_web;
  }
  Farmacie_online() : Farmacie_abstracta(){adresa_web=NULL; nr_vizitatori=0;}
  Farmacie_online(string c) : Farmacie_abstracta(c){adresa_web=NULL; nr_vizitatori=0;}
  Farmacie_online(string c, int nr ) : Farmacie_abstracta(c){nr_vizitatori=nr; adresa_web=NULL;}
  Farmacie_online(string c, char *adr, int nr ) : Farmacie_abstracta(c){nr_vizitatori=nr; strcpy(adresa_web,adr);}
  Farmacie_online(Farmacie_online& x) : Farmacie_abstracta(x){nr_vizitatori=x.nr_vizitatori; strcpy(adresa_web,x.adresa_web);}
  ~Farmacie_online(){delete adresa_web;}
  friend istream& operator>>(istream&, Farmacie_online&);
  Farmacie_online &operator=(Farmacie_online&);
};
istream& operator>>(istream& in, Farmacie_online& x)
{
    in>>(Farmacie_abstracta&)x;
    in>>x.nr_vizitatori;
    in>>x.adresa_web;
    return in;
}
Farmacie_online &Farmacie_online::operator=(Farmacie_online &x)
{
    Farmacie_abstracta::operator=(x);
    nr_vizitatori=x.nr_vizitatori;
    strcpy(adresa_web,x.adresa_web);
    return *this;
}

class Farmacie_dubla_specializare:  public Farmacie_offline,  public Farmacie_online{
  int nr_angajati;
public:
  double calcul_venit();
  Farmacie_dubla_specializare() : Farmacie_offline(),Farmacie_online {nr_angajati=0;}
  Farmacie_dubla_specializare(string c) : Farmacie_abstracta(c),Farmacie_offline(c),Farmacie_online(c){nr_angajati=0;}
  Farmacie_dubla_specializare(string c, int nr, int nra ,double* cal ) : Farmacie_offline(c,nr,cal),Farmacie_online(){nr_angajati=0;}
  Farmacie_dubla_specializare(string c, char *adr, int nr, int nra ) : Farmacie_online(c,nr,adr),Farmacie_offline{nr_angajati=0;}
  Farmacie_dubla_specializare(string c, char *adr, int nr1, int nr2, double* cal,int nra ): Farmacie_online(c,nr,adr),Farmacie_offline(c,nr,cal)(nr_angajati=0);
  Farmacie_dubla_specializare(Farmacie_online& x) : Farmacie_abstracta(x){nr_vizitatori=x.nr_vizitatori; strcpy(adresa_web,x.adresa_web);}
  ~Farmacie_dubla_specializare(){delete adresa_web; delete cifra_afaceri_luna;}
  friend istream& operator>>(istream&, Farmacie_dubla_specializare&);
  Farmacie_dubla_specializare &operator=(Farmacie_dubla_specializare&);
  //double calcul_venit();
};
istream& operator>>(istream& in, dubla_specializare& x)
{
    in>>(Farmacie_abstracta&)x;
    in>>(Farmacie_offline(&)x;
    in>>(Farmacie_online(&)x;
    in>>x.nr_angajati;
    return in;
}
Farmacie_online &Farmacie_online::operator=(Farmacie_dubla_specializare &x)
{
    Farmacie_abstracta::operator=(x);
    nr_vizitatori=x.nr_vizitatori;
    strcpy(adresa_web,x.adresa_web);
    return *this;
}

int main()
{
    Farmacie_abstracta **X;
    Farmacie_abstracta *C;
    int n,i;
    cin>>n;
    new Farmacie_abstracta*[n];
    //citire
    for(i=1;i<=n;i++){
      cin>>C;
      if(typeid(C])==typeid(Farmacie_offline))
        *dynamic_cast<Farmacie_offline*>X[i]=C;;
      if(typeid(C)==typeid(Farmacie_online))
       *dynamic_cast<Farmacie_online*>X[i]=C;
      else
        *dynamic_cast<Farmacie_dubla_specializare*>X[i]=C;
    }
    //afisare
    for(i=1;i<=n;i++){
      if(typeid(X[i])==typeid(Farmacie_offline))
        cout<<*dynamic_cast<Farmacie_offline*>X[i];
      if(typeid(X[i])==typeid(Farmacie_online))
        cout<<*dynamic_cast<Farmacie_online*>X[i];
      else
        cout<<*dynamic_cast<Farmacie_dubla_specializare*>X[i];
    }
    return 0;
}
