#include<iostream>

using namespace std;
/*Plante*/

class Copac
{
public:
    const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLuna;
    float inaltime;
    float latimeTrunchi; 
    int x;
    Copac() : TipPlanta(1)
    {
       this->CrestereLuna = NULL;
       this->inaltime = 0;
       this->latimeTrunchi = 0;
       this->culoare = "de culoare necunoscuta";
       this->x = 0;
    }
    
    Copac(int TipPlanta, float inaltime, float latimeTrunchi, float* CrestereLuna, string culoare) : TipPlanta(TipPlanta)    
    {
        this->inaltime = inaltime;
        this->latimeTrunchi = latimeTrunchi;
        this->CrestereLuna = new float[5];
        this->culoare = culoare;
        this->x = 1;
        for(int i = 0; i < 5; i++)
            {
                this->CrestereLuna[i] = CrestereLuna[i];
            }

    }

    Copac(int TipPlanta) : TipPlanta(TipPlanta)
    {
       this->CrestereLuna = NULL;
       this->inaltime = 0;
       this->latimeTrunchi = 0;
       this->culoare = "de culoare necunoscuta";
       this->x = 0;
    }

    static void Ecosistem(string ecosistem)
    {
        Copac::ecosistem = ecosistem;
    }

    void afisare() 
    {
        cout<< "Copacul din Ecosistemul " << ecosistem << " are frunze " << culoare << " o inaltimea " << inaltime << " si latimea " << latimeTrunchi << endl;
        if(x==1)
        {
        for(int i = 0; i < 5 ; i++)
        cout<< "In luna " << i+1 << " a crescut " << CrestereLuna[i] << " metri" << endl;
        }
        cout<<endl;
        cout<<endl;

    }
};

class Trandafir
{
public:
    const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLunaTrandafir;
    float inaltime;
    int nrPet; 
    bool Spini;
    int x;
   Trandafir() : TipPlanta(2)
    {
       this->CrestereLunaTrandafir = NULL;
       this->inaltime = 0;
       this->nrPet = 0;
       this->Spini = false;
       this->culoare = "Necunoscut";
       this->x=0;


    
    }
    
    Trandafir(int TipPlanta, float inaltime, int nrPet, float* CrestereLunaTrandafir, bool Spini, string culoare) : TipPlanta(TipPlanta)    
    {
        this->inaltime = inaltime;
        this->culoare = culoare;
        this->nrPet = nrPet;
        this->Spini = Spini;
        this->x=1;
        this->CrestereLunaTrandafir = new float[5];
        for(int i = 0; i < 5; i++)
            {
                this->CrestereLunaTrandafir[i] = CrestereLunaTrandafir[i];
            }

    }


    Trandafir(int TipPlanta):TipPlanta(TipPlanta)
    {
       this->CrestereLunaTrandafir = NULL;
       this->inaltime = 0;
       this->nrPet = 0;
       this->Spini = false;
       this->culoare = "Necunoscut";
       this->x=0;

    }

    static void Ecosistem(string ecosistem)
    {
        Copac::ecosistem = ecosistem;
    }

    void afisare() 
    {
        cout<< "Trandafirul din Ecosistemul " << ecosistem << " este " << culoare << " are "<< nrPet <<" Petale "<<  "are inaltimea " << inaltime << " si ";
        if(Spini == 1)
        {
            cout<<"Are ";
        }
        else 
        {
            cout<<"Nu Are";
        }

        cout << " Spini " << endl;
        if (x==1)
        {
        for(int i = 0; i < 5 ; i++)
        cout<< "In luna " << i+1 << " a crescut " << CrestereLunaTrandafir[i] <<" metri"<< endl;
        }
      cout<<endl;
      cout<<endl;
    }
};

class Lavanda
{
    public:
    const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLunaLavanda;
    float inaltime;
    bool aroma;
    int x;

    Lavanda():TipPlanta(3)
    {
        this->culoare = "Neconoscuta";
        this->inaltime = 0;
        this->CrestereLunaLavanda = NULL;
        this->aroma = false;
        this->x=0;

    }

    Lavanda(int TipPlanta, float inaltime, string culoare, float* CrestereLunaLavanda, bool aroma):TipPlanta(TipPlanta)
    {
        this->culoare = culoare;
        this->inaltime = inaltime;
        this->aroma = aroma;
        this->x=1;
        this->CrestereLunaLavanda = new float[5];
        for(int i=0;i<5;i++)
        {
           this->CrestereLunaLavanda[i] = CrestereLunaLavanda[i];
        }
    }

    Lavanda(int TipPlanta):TipPlanta(TipPlanta)
    {
        this->culoare = "Necunoscuta";
        this->inaltime = 0;
        this->CrestereLunaLavanda = NULL;
        this->aroma = false;
        this->x=0;
    }
 static void Ecosistem(string ecosistem)
    {
        Copac::ecosistem = ecosistem;
    }

    void afisare() 
    {
        cout<< "Lavanda din Ecosistemul " << ecosistem << " e de culoarea " << culoare << " are inaltimea " << inaltime << " si ";
        if(aroma == 1)
        {
            cout<<"Are aroma";
        }
        else 
        {
            cout<<"Nu are aroma";
        }
        if (x==1)
        {
        cout<<endl;
        for(int i = 0; i < 5 ; i++)
        cout<< "In luna " << i+1 << " a crescut " << CrestereLunaLavanda[i] << " metri" << endl;
        
        }
      cout<<endl;
      cout<<endl;
    }
};


string Copac::ecosistem = "Mediterranean";
string Trandafir::ecosistem = "Mediterranean";
string Lavanda::ecosistem = "Mediterranean";

int main()
{
//Copac - initializare 
cout<<"COPAC:"<<endl;
float* CrestereLunaCopac = new float[5];
CrestereLunaCopac[0] = 0.22;
CrestereLunaCopac[1] = 0.25;
CrestereLunaCopac[2] = 0.27;
CrestereLunaCopac[3] = 0.29;
CrestereLunaCopac[4] = 0.31;


//Initializare  
Copac copac1;
Copac copac2(1, 10, 7, CrestereLunaCopac, "Verzi");
Copac copac3(1);
//Afisare 
copac2.afisare();
copac1.afisare();
copac3.afisare();

cout << endl;

//Trandafir - initializare
cout<<"TRANDAFIR:"<<endl;
float* CrestereLunaTrandafir = new float[12];
CrestereLunaTrandafir[0] = 0.10;
CrestereLunaTrandafir[1] = 0.12;
CrestereLunaTrandafir[2] = 0.15;
CrestereLunaTrandafir[3] = 0.16;
CrestereLunaTrandafir[4] = 0.19;

Trandafir tdf1;
Trandafir tdf2(2, 10, 7, CrestereLunaTrandafir, false, "Rosie");
Trandafir tdf3(2);
//Afisare 
tdf1.afisare();
tdf2.afisare();
tdf3.afisare();

cout<<endl;

//Lavanda - intializare
cout<<"LAVANDA:"<<endl;
float* CrestereLunaLavanda = new float[5];
CrestereLunaLavanda[0] = 0.15;
CrestereLunaLavanda[1] = 0.12;
CrestereLunaLavanda[2] = 0.11;
CrestereLunaLavanda[3] = 0.12;
CrestereLunaLavanda[4] = 0.10;

Lavanda lv1;
Lavanda lv2(3,10,"violet", CrestereLunaLavanda,true);
Lavanda lv3(3);
//Afisare
lv1.afisare();
lv2.afisare();
lv3.afisare();

}