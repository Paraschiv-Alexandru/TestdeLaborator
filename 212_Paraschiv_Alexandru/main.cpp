/*
Paraschiv Alexandru 212
Compilator: GNU GCC Compiler
tutore de laborator: Eduard Gabriel Szmeteanca
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
class Vaccin{
public:


    Vaccin(){}
    ~Vaccin(){}
};
class VaccinAntiSarsCov2:public Vaccin{
    friend void adaugareVaccin();
public:
    using Vaccin::Vaccin;
    VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &rhs){
        cout<<"Vaccin adaugat"<<endl;
        rata_eficienta=rhs.rata_eficienta;
        medicamente=rhs.medicamente;
    }
    VaccinAntiSarsCov2(string med,int rata){
        rata_eficienta=rata;
        medicamente=med;
    }
    void afisareSchemaVaccinare(){
        cout<<"Se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 de zile"<<endl;
    }
    VaccinAntiSarsCov2(){cout<<"Vaccin adaugat"<<endl;}
    ~VaccinAntiSarsCov2(){}
private:
    vector <string> lista_simptome{"durere de cap","Stare de voma","ameteala"};
    int rata_eficienta;
    string medicamente;
};
class VaccinAntihepatetic:public Vaccin{
    friend void adaugareVaccin();
public:
    VaccinAntihepatetic(const VaccinAntihepatetic &rhs){
        cout<<"Vaccin adaugat"<<endl;
        tip_hepatita=rhs.tip_hepatita;
        mod_vaccinare=rhs.mod_vaccinare;
    }
    VaccinAntihepatetic(){cout<<"Vaccin Adaugat"<<endl;}
    void afisareSchemaVaccinare(){
        if(tip_hepatita=="A" || tip_hepatita=="B")
            cout<<"La copii cu varsta de mai putin de un an se administreaza 2 injectari la un interval de o luna,a treia injectare dupa 6 luni de la prima. La adulti conform schemei de imunizare recomandata de medic"<<endl;
        else
            cout<<"Doar la recomandarea medicului"<<endl;
    }
    VaccinAntihepatetic(string d,string c){
        tip_hepatita=d;
        mod_vaccinare=c;
    }
    ~VaccinAntihepatetic(){}
    void set_tip_hepatita(string c){
        tip_hepatita=c;
    }
    void set_mod_vaccinare(string c){
        mod_vaccinare=c;
    }
private:
string tip_hepatita;
string mod_vaccinare;
};
class VaccinAntigripal:public Vaccin{
    friend void adaugareVaccin();
    friend istream operator>>(istream &f,const VaccinAntigripal &t);
public:
    VaccinAntigripal(const VaccinAntigripal &rhs){
        cout<<"Vaccin adaugat"<<endl;
        tip_tulpina=rhs.tip_tulpina;
        respecta=rhs.respecta;
    }
    VaccinAntigripal(){cout<<"Vaccin adaugat"<<endl;}
    void afisareSchemaVaccinare(){
        cout<<"Se administreaza la adulti 0,5 ml iar la adolescenti/copii 0,3ml si se repeta din 2 in 2 ani"<<endl;
    }
    VaccinAntigripal(string c,int d){
        tip_tulpina=c;
        respecta=0;
    }
    void set_respecta(int x){
        respecta=x;
    }
    void set_tip_tulpina(string c){
        tip_tulpina=c;
    }
    ~VaccinAntigripal(){}
private:
    string tip_tulpina;
    int respecta=0;
};
Vaccin* List[3];
vector<Vaccin> vec;
void adaugareVaccin(){
    cout<<"Alegeti tipul"<<endl;
    cout<<"1) Antigripal"<<endl;
    cout<<"2) Antihepatetic"<<endl;
    cout<<"3) Anti Sars Cov 2"<<endl;
    int t;
    cin>>t;

            if(t==1){//adaugare vaccin in vectorul V
                cout<<"Alegeti tipul tulpinii:";
                string str;
                cin>>str;
                cout<<"Respecta recomandarile date de organizatia mondiala a sanatatii?(1 pentru da si 0 pt nu)"<<endl;
                int d;
                cin>>d;
                VaccinAntigripal V{str,d};
                vec.push_back(V);
            }
            else
            if(t==2){
                cout<<"Alegeti tipul de hepatita:";
                string str;
                cin>>str;
                cout<<"Alegeti tipul de vaccinare:";
                string str2;
                cin>>str2;
                VaccinAntihepatetic V{str,str2};
                vec.push_back(V);
            }
            else
            if(t==3){
                cout<<"Alegeti medicamentul contraindicat:";
                string str;
                cin>>str;
                cout<<"Alegeti rata de eficienta:";
                int d;
                cin>>d;
                VaccinAntiSarsCov2 V{str,d};
                vec.push_back(V);
            }



}
void menu(){//preluat din proiectul personal
    int d=1;
    while(d!=0){
        cout<<"Alegeti numarul fiecarei optiuni:"<<endl;
        cout<<"1) Adaugare Vaccin"<<endl;
        cout<<"2) Stergere"<<endl;
        cout<<"3) Afisare schema Vaccin"<<endl;
        cout<<"0) Iesire"<<endl<<endl;
        cin>>d;
        int t=1;
        if(d==1){
            adaugareVaccin();
        }
        else
        if(d==2){
            cout<<"Sters"<<endl;
        }
        else
        if(d==3){
            cout<<"Alegeti vaccinul:";
            int i;
            cin>>i;
        }

    }
    cout<<"Program terminat"<<endl;
}
void operator>>(istream &f,VaccinAntigripal &t){//Modificare vaccin Antigripal
                cout<<"Alegeti tipul tulpinii:";
                string str;
                f>>str;
                cout<<"Respecta recomandarile date de organizatia mondiala a sanatatii?(1 pentru da si 0 pt nu)"<<endl;
                int d;
                f>>d;
                t.set_tip_tulpina(str);
                t.set_respecta(d);
                cout<<"Vaccin Antigripal modificat"<<endl;

}
void operator>>(istream &f,VaccinAntihepatetic &t){//Modificare Vaccin Antihepatetic
    string str,str2;
    cout<<"Alegeti tipul de hepatita:";
    f>>str;
    cout<<"Alegeti modul de administrare:";
    f>>str2;
    t.set_tip_hepatita(str);
    t.set_mod_vaccinare(str2);
    cout<<"Vaccin Antigripal modificat"<<endl;
}


int main()
{
    //menu();
    //DEMO
    /*
    VaccinAntigripal a;
    VaccinAntihepatetic b;
    VaccinAntiSarsCov2 c;
    cin>>a;
    cin>>b;
    a.afisareSchemaVaccinare();
    b.afisareSchemaVaccinare();
    c.afisareSchemaVaccinare();
    */
    //Comanda neimplementata,
    return 0;
}
