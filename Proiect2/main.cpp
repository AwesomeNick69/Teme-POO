#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

class ABC;
class Nod{
protected:
    int info;
    Nod *st, *dr;
    friend class ABC;

    friend ostream& operator<<(ostream&, ABC&);
    friend istream& operator>>(istream&, ABC&);
public:
    Nod(int info);
    Nod(int info, Nod *st, Nod *dr);
    ~Nod();
    Nod(Nod& x);
    friend ostream& operator<<(ostream&, Nod&);
    friend istream& operator>>(istream&, Nod&);
    Nod &operator=(Nod&);

};

class Nod_rosu_negru: public Nod{
    char culoare[20];
    //am adaugat nodul parinte pentru a usura crearea arborelui bicolor
    Nod* parinte;
public:
    friend class Arbore_bicolor;
    Nod_rosu_negru(int info, char culoare[]) : Nod(info){strcpy(culoare,"rosu");}
    Nod_rosu_negru(int info, Nod *st, Nod *dr, char color[]) : Nod(info,st,dr){strcpy(culoare,color);}
    ~Nod_rosu_negru();
    Nod_rosu_negru(Nod_rosu_negru& x) : Nod(x){strcpy(culoare,x.culoare);}
    friend ostream& operator<<(ostream&, Nod_rosu_negru&);
    friend istream& operator>>(istream&, Nod_rosu_negru&);
    Nod_rosu_negru &operator=(Nod_rosu_negru&);
    friend Insert(Nod_rosu_negru *rad, Nod_rosu_negru *q);
};

class Arbore{
protected:
    int nr_noduri;
public:
    virtual void inserare()=0;
    virtual void inordine()=0;
    virtual void inaltime()=0;
    Arbore();
    Arbore(int n);
    Arbore(Arbore& x);
    friend ostream& operator<<(ostream&, Arbore&);
    friend istream& operator>>(istream&, Arbore&);
    Arbore &operator=(Arbore&);
};

class ABC: public Arbore{
    Nod *rad;
public:
    ABC() : Arbore(){rad=NULL;}
    ABC(int n, Nod *x) : Arbore(n){rad=x;}
    ABC(ABC& x) : Arbore(x){rad=x.rad;}
    ~ABC();
    friend ostream& operator<<(ostream&, ABC&);
    friend istream& operator>>(istream&, ABC&);
    ABC &operator=(ABC& );
    void inserare(int nr);
    void inordine(Nod *rad);
};

class Arbore_bicolor: public Arbore{
    Nod_rosu_negru *rad;
public:
    Arbore_bicolor() : Arbore(){ rad=NULL;}
    Arbore_bicolor(int n, Nod_rosu_negru *x) : Arbore(n){rad=x;}
    Arbore_bicolor(Arbore_bicolor& x) : Arbore(x){rad=x.rad;}
    ~Arbore_bicolor();
    friend ostream& operator<<(ostream&, Arbore_bicolor&);
    friend istream& operator>>(istream&, Arbore_bicolor&);
    Arbore_bicolor &operator=(Arbore_bicolor&);
    void inserare(int nr);
    void inordine(Nod_rosu_negru *rad);
    void rotireStanga(Nod_rosu_negru *&, Nod_rosu_negru *&);
    void rotireDreapta(Nod_rosu_negru *&, Nod_rosu_negru *&);
    void Reparare(Nod_rosu_negru *&, Nod_rosu_negru *&);
    void inaltime(){cout<<"Inaltimea arborelui bicolor = "<<2*log2(nr_noduri+1)};
};

//metodele clasei Nod
Nod::Nod(Nod& x)
{
    this->info=x.info;
    this->st=x.st;
    this->dr=x.dr;
}
Nod::Nod(int info=0)
{
    info=info;
    this->st=NULL;
    this->dr=NULL;
}
Nod::Nod(int info, Nod *st, Nod *dr)
{
    this->info=info;
    this->st=st;
    this->dr=dr;
}
Nod::~Nod()
{
    delete st;
    delete dr;
}
ostream& operator<<(ostream& out, Nod& x)
{
    out<<x.info;
    return out;
}
istream& operator>>(istream& in, Nod& x)
{
    in>>x.info;
    x.st=NULL;
    x.dr=NULL;
    return in;
}
Nod &Nod::operator=(Nod &x)
{
    info=x.info;
    st=x.st;
    dr=x.dr;
    return *this;
}
// metodele Nod_rosu_negru
Nod_rosu_negru::~Nod_rosu_negru()
{
    delete st;
    delete dr;
}
ostream& operator<<(ostream& out, Nod_rosu_negru& x)
{
    out<<(Nod&)x<<" ";
    out<<x.culoare;
    return out;
}
istream& operator>>(istream& in, Nod_rosu_negru& x)
{
    in>>(Nod&)x;
    //in>>culoare;
    return in;
}
Nod_rosu_negru &Nod_rosu_negru::operator=(Nod_rosu_negru &x)
{
    info=x.info;
    st=x.st;
    dr=x.dr;
    strcpy(culoare,x.culoare);
    return *this;
}
//metode pentru Arbore
Arbore::Arbore()
{
    this->nr_noduri=0;
}
Arbore::Arbore(int n)
{
    this->nr_noduri=n;
}
Arbore::Arbore(Arbore& x)
{
    this->nr_noduri=x.nr_noduri;
}
ostream& operator<<(ostream& out, Arbore& x)
{
    out<<x.nr_noduri;
    return out;
}
istream& operator>>(istream& in, Arbore& x)
{
    in>>x.nr_noduri;
    return in;
}
Arbore &Arbore::operator=(Arbore &x)
{
    nr_noduri=x.nr_noduri;
    return *this;
}
//metodele ABC
ABC::~ABC()
{
    delete rad;
}
void ABC::inserare(int nr)
{
    Nod *n1, *n2, *n3;
    n1=new Nod;
    n1->info=nr;
    n1->st=NULL;
    n1->dr=NULL;
    if(rad==NULL)
        rad=n1;
    else{
        n2=rad;
        while(n2!=NULL)
            if(nr<n2->info){
                n3=n2;
                n2=n2->st;
            }else{
                n3=n2;
                n2=n2->dr;
            }
        if(nr<n3->info) n3->st=n1;
        else n3->dr=n1;
    }
}
void ABC::inordine(Nod *rad)
{
    if(rad!=NULL){
        inordine(rad->st);
        cout<<rad->info;
        inordine(rad->dr);
    }
}
ostream& operator<<(ostream& out, ABC& x)
{
    out<<(Arbore&)x<<" ";
    if(x.rad!=NULL)
    {
        x.inordine(x.rad->st);
        out<<x.rad->info;
        x.inordine(x.rad->dr);
    }
    return out;
}
istream& operator>>(istream& in, ABC& x)
{
    int inf;
    in>>(Arbore&)x;
    in>>inf;
    while(inf>=0){
        x.inserare(inf);
        in>>inf;
    }
    return in;
}
ABC &ABC::operator=(ABC &x)
{
    rad=x.rad;
    return *this;
}
//metode Arbore_bicolor
///Nu m-am descurcat din pacate prea bine la implementarea arborilor bicolori :(
void Arbore_bicolor::inordine(Nod_rosu_negru *rad)
{
    if(rad!=NULL){
        inordine(rad->st);
        cout<<rad->info;
        inordine(rad->dr);
    }

}
void Arbore_bicolor::rotireStanga(Nod_rosu_negru *&rad, Nod_rosu_negru *&pt)
{
    Nod_rosu_negru *pt_right = pt->dr;

    pt->dr = pt_right->st;

    if (pt->dr != NULL)
        pt->dr->parinte = pt;

    pt_right->parinte = pt->parinte;

    if (pt->parinte == NULL)
        rad = pt_right;

    else if (pt == pt->parinte->st)
        pt->parinte->st = pt_right;

    else
        pt->parinte->dr = pt_right;

    pt_right->st = pt;
    pt->parinte = pt_right;
}

void Arbore_bicolor::rotireDreapta(Nod_rosu_negru *&rad, Nod_rosu_negru *&pt)
{
    Nod_rosu_negru *pt_left = pt->st;

    pt->st = pt_left->dr;

    if (pt->st != NULL)
        pt->st->parinte = pt;

    pt_left->parinte = pt->parinte;

    if (pt->parinte == NULL)
        rad = pt_left;

    else if (pt == pt->parinte->st)
        pt->parinte->st = pt_left;

    else
        pt->parinte->dr = pt_left;

    pt_left->dr = pt;
    pt->parinte = pt_left;
}

void Arbore_bicolor::Reparare(Nod_rosu_negru *&rad, Nod_rosu_negru *&pt)
{
    Nod_rosu_negru *parent_pt = NULL;
    Nod_rosu_negru *grand_parent_pt = NULL;

    while ((pt != rad) && (strcasecmp(pt->culoare,"negru")!=0) && (strcmp(pt->parinte->culoare,"rosu")==0))
    {

        parent_pt = pt->parinte;
        grand_parent_pt = pt->parinte->parinte;


        if (parent_pt == grand_parent_pt->st)
        {

            Nod_rosu_negru *uncle_pt = grand_parent_pt->dr;


            if (uncle_pt != NULL && strcmp(uncle_pt->culoare,"rosu")==0)
            {
                grand_parent_pt->culoare = RED;
                parent_pt->culoare = BLACK;
                uncle_pt->culoare = BLACK;
                pt = grand_parent_pt;
            }

            else
            {

                if (pt == parent_pt->dr)
                {
                    rotateLeft(rad, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parinte;
                }


                rotateRight(rad, grand_parent_pt);
                swap(parent_pt->culoare, grand_parent_pt->culoare);
                pt = parent_pt;
            }
        }


        else
        {
            Nod_rosu_negru *uncle_pt = grand_parent_pt->st;


            if ((uncle_pt != NULL) && (uncle_pt->culoare == RED))
            {
                strcpy(grand_parent_pt->culoare,"rosu");
                strcpy(parent_pt->culoare , "negru");
                strcpy(uncle_pt->culoare , "negru");
                pt = grand_parent_pt;
            }
            else
            {

                if (pt == parent_pt->st)
                {
                    rotireDreapta(rad, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parinte;
                }


                rotireStanga(rad, grand_parent_pt);
                swap(parent_pt->culoare, grand_parent_pt->culoare);
                pt = parent_pt;
            }
        }
    }

    strcpy(rad->color , "negru");
}

Nod_rosu_negru* Insert(Nod_rosu_negru* rad, Nod_rosu_negru *q)
{
    if (rad == NULL)
       return q;

    if (q->info< rad->info)
    {
        rad->st  = Insert(rad->st, q);
        rad->st->parinte = rad;
    }
    else if (q->info > rad->info)
    {
        rad->dr = BSTInsert(rad->dr, q);
        rad->dr->parinte = rad;
    }
    return rad;
}
void Arbore_bicolor::inserare(Nod_rosu_negru *rad)
{
    Nod_rosu_negru *q = new Nod_rosu_negru;
    rad=Insert(rad,q);
}
istream& operator>>(istream& in, Arbore_bicolor& x)
{
    int inf;
    in>>(Arbore&)x;
    in>>inf;
    while(inf>=0){
        x.inserare(inf);
        in>>inf;
    }
    return in;
}
ostream& operator<<(ostream& out, Arbore_bicolor& x)
{
    out<<(Arbore&)x<<" ";
    if(x.rad!=NULL)
    {
        x.inordine(x.rad->st);
        out<<x.rad->info;
        x.inordine(x.rad->dr);
    }
    return out;
}
Arbore_bicolor &Arbore_bicolor::operator=(Arbore_bicolor &x)
{
    rad=x.rad;
    return *this;
}
/*
Arbore_bicolor::~Arbore_bicolor()
{
    delete rad;
}
*/
int main()
{
    ABC A;
    Arbore_bicolor C;
    cin>>A;
    cout<<A;
    cin>>C;
    cout<<C;
    return 0;
}
