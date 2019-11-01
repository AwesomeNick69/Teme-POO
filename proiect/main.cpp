#include <iostream>
#include <fstream>
using namespace std;

class Nod;
class Management;
class Lista_dublu_inlantuita
{
    Nod* prim, *ultim;
public:
    void Adaug(int poz, int x);
    void Sterg(int poz);
    Lista_dublu_inlantuita();
    Lista_dublu_inlantuita(int x);
    Lista_dublu_inlantuita(bool x);
    ~Lista_dublu_inlantuita();
    *Lista_dublu_inlantuita(Lista_dublu_inlantuita &L){
        prim=L.prim;
        ultim=L.ultim;
    }
    friend ostream& operator<<(ostream&, Lista_dublu_inlantuita&);
    friend istream& operator<<(istream&, Lista_dublu_inlantuita&);
    friend ostream& operator<<(ostream&, Management&);
    Lista_dublu_inlantuita &operator+(Lista_dublu_inlantuita&);
    Lista_dublu_inlantuita &operator=(Lista_dublu_inlantuita&);
    Lista_dublu_inlantuita &operator-(int);
    friend class Management;
    friend class Nod;
};

class Nod
{
    int info;
    Nod* prev, *next;
public:
    Nod(int info);
    Nod(int info, Nod *prev, Nod *next);
    ~Nod();
    friend class Lista_dublu_inlantuita;
    friend class Management;
    friend ostream& operator<<(ostream&, Lista_dublu_inlantuita&);
    friend ostream& operator<<(ostream&, Management&);
   // friend istream& operator<<(istream&, Lista_dublu_inlantuita&);

};
class Management
{
    Lista_dublu_inlantuita v[100];
    int n;
public:
    *Management(Management &x)
    {
        int i;
        n=x.n;
        for(i=1;i<=n;i++)
            v[i]=x.v[i];
    }
    friend class Lista_dublu_inlantuita;
    friend ostream& operator<<(ostream&, Management&);
    friend istream& operator<<(istream&, Management&);
    Management &operator=(Management&);
};
Nod::Nod(int info=0)
{
    info=info;
    this->prev=NULL;
    this->next=NULL;
}
Nod::Nod(int info, Nod *prev, Nod *next)
{
    this->info=info;
    this->prev=prev;
    this->next=next;
}
Nod::~Nod()
{
    delete prev;
    delete next;
}

//constructorul initializare
Lista_dublu_inlantuita::Lista_dublu_inlantuita(){
        prim = NULL; ultim = NULL;
}
//constructorul parametrizat
Lista_dublu_inlantuita::Lista_dublu_inlantuita(int x)
{
        Nod *p=new Nod;
        p->info=x;
        p->prev=p->next=NULL;
        prim=ultim=p;
}

//Deconstructorul
Lista_dublu_inlantuita::~Lista_dublu_inlantuita()
{
    Nod *p=new Nod;
    Nod *q=new Nod;
    q=p=prim;
    while(p->next!=NULL){
        p=p->next;
        delete q;
        q=p;
    }
}
void Lista_dublu_inlantuita::Adaug(int poz, int x)
{
    Nod *p=new Nod;
    Nod *aux=new Nod;

    int i=1;
    if(poz==1){
    //adaugare pe prima pozitie
        p->info=x;
        p->prev=p->next=NULL;
        prim=ultim=p;
    }else{
        p=prim;
        for(;;){
            //adaugare la final
            if(p->next==NULL && poz-i==1){
                aux->info=x;
                aux->prev=p;
                p->next=aux;
                aux->next=NULL;
                ultim=aux;
                break;
            }
            //adaugare in interior
            if(p->next != NULL && i==poz){
                aux->info=x;
                p->prev->next=aux;
                aux->prev=p->prev;
                aux->next=p;
                p->prev=aux;
                break;
            }else;
            i++;
            p=p->next;

        }

    }


}
void Lista_dublu_inlantuita::Sterg(int poz)
{

    Nod *p=new Nod;
    Nod *aux=new Nod;
    p=prim;
    //stergere de pe prima pozitie
    if(poz==1){
        prim=prim->next;
        prim->prev=NULL;
    }else{
        while(poz>=1){
            p=p->next;
            poz--;
            if(poz==1){
                    //stergere de la final
                if(p->next==NULL){
                    ultim=p->prev;
                    ultim->next=NULL;
               }else{
                   //stergere din interior
                    aux=p;
                    p->prev->next=p->next;
                    aux->next->prev=p->prev;
                }
            }else;

        }

    }

}
Lista_dublu_inlantuita &Lista_dublu_inlantuita::operator+(Lista_dublu_inlantuita &L)
{
    //Efectuarea concatenarii
    Nod *p=prim;
    //parcurg prima lista pana la ultimul element
    while(p->next!=NULL)
        p=p->next;
    p->next=L.prim;
    L.prim->prev=p;
    ultim=L.ultim;
    return *this;
}
//Operatorul de atribuire
Lista_dublu_inlantuita &Lista_dublu_inlantuita::operator=(Lista_dublu_inlantuita &L)
{
    prim=L.prim;
    ultim=L.ultim;
    return *this;

}
/*
Lista_dublu_inlantuita::operator-()
{
    Nod *p=new Nod;
    p=prim;
    while(p->next!=NULL)
        p->info=p->info*-1;
    return *this;
}
*/
ostream& operator<<(ostream& out, Lista_dublu_inlantuita& l)
{
    Nod *p = l.prim;
    Nod *u = l.ultim;
    //Afisez din abele capete
    //de la prim
    while(p!=NULL)
    {
        out<<p->info<<" ";
        p = p->next;
    }
    out<<endl;
    //de la ultim
    while(u!=NULL)
    {
        out<<u->info<<" ";
        u = u->prev;
    }
    out<<endl;
    return out;
}
istream& operator>>(istream& in, Lista_dublu_inlantuita& l)
{
    int i=1,x;
    //introducem in lista pana la introducerea valorii 0
    in>>x;
    while(x){
        l.Adaug(i,x);
        i++;
        in>>x;
    }
    return in;
}
//constructorul parametrizat bool
Lista_dublu_inlantuita::Lista_dublu_inlantuita(bool x){
    Nod *p=new Nod();
    Nod *q=new Nod();

    int info;
    ultim=prim=p;
    if(x){
        cin>>info;
        p->prev=NULL;
        p->info=info;
        while(info){
            q->info=info;
            p->next=q;
            q->prev=p;
            p=p->next;
            cin>>info;
        }
        p->next=NULL;
        ultim=p;
    }else{
        ifstream f("Fisier.txt");
        f>>info;
        p->prev=NULL;
        p->info=info;
        while(f>>info){
            q->info=info;
            p->next=q;
            q->prev=p;
            p=p->next;
            cin>>info;
        }
        p->next=NULL;
        ultim=p;
        f.close();
    }
}
// >> si << pentru clasa Management
ostream& operator<<(ostream& out, Management& x)
{
    Nod *p=new Nod;
    Nod *u=new Nod;
    int i;
    for(i=1;i<=x.n;i++){
        p = x.v[i].prim;
        u = x.v[i].ultim;
        //Afisez din abele capete
        //de la prim
        while(p!=NULL)
        {
            out<<p->info<<" ";
            p = p->next;
        }
        out<<endl;
        //de la ultim
        while(u!=NULL)
        {
            out<<u->info<<" ";
            u = u->prev;
        }
        out<<endl;
    }
    return out;

}
istream& operator<<(istream& in, Management& x)
{
    int i=1,k,j;
    //introducem in lista pana la introducerea valorii 0
    in>>x.n;
    for(j=1;i<=x.n;j++)
        while(k){
            x.v[i].Adaug(i,k);
            i++;
            in>>k;
        }
    return in;
}
Management &Management::operator=(Management &x)
{
    int i;
    n=x.n;
    for(i=1;i<=x.n;i++)
        v[i]=x.v[i];
    return *this;
}
int main()
{
    Lista_dublu_inlantuita L,K,P;
    //Testarea metodelor
    K.Adaug(1,3);
    K.Adaug(2,3);
    K.Adaug(3,4);
    K.Adaug(4,4);
    K.Adaug(3,8);
    cout<<K;
    K.Sterg(5);
    L.Adaug(1,7);
    L.Adaug(2,8);
    L.Adaug(3,9);
    L=L+K;
    cin>>P;
    cout<<P;
    cout<<L;
    cout<<K;
    cin>>P;
    cout<<P;
    return 0;
}
