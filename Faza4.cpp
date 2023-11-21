#include<iostream>

using namespace std;
/*Plante*/

//CLASA COPAC
class Copac
{
private:
const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLuna;
    float inaltime;
    float latimeTrunchi; 
    int x;
public:
//Constructor fara parametru
    Copac() : TipPlanta(1)
    {
       this->CrestereLuna = NULL;
       this->inaltime = 0;
       this->latimeTrunchi = 0;
       this->culoare = "de culoare necunoscuta";
       this->x = 0;
    }

 
  //Constructor cu n par.
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
//Constructor cu 1 par.
    Copac(int TipPlanta) : TipPlanta(TipPlanta)
    {
       this->CrestereLuna = NULL;
       this->inaltime = 0;
       this->latimeTrunchi = 0;
       this->culoare = "de culoare necunoscuta";
       this->x = 0;
    }

//Constructor de Copiere
    Copac(const Copac& copy) : TipPlanta(copy.TipPlanta)
    {
        this->inaltime = copy.inaltime;
        this->culoare = copy.culoare;
        this->latimeTrunchi = copy.latimeTrunchi;
        this->x = copy.x;
        this->CrestereLuna = new float[5];
        for(int i =0; i<5; i++)
        this->CrestereLuna[i] = copy.CrestereLuna[i];
    }
//Destructor
    ~Copac()
    {
        delete[]CrestereLuna;
    }


//Functie Statica
    static void Ecosistem(string ecosistem)
    {
        Copac::ecosistem = ecosistem;
    }
//Afisare
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
//Geteri si Seteri   
    int getTipPlanta()
    {
        return this->TipPlanta;
    }

    static void setEcosistem(string ecosistem)
    {
    Copac::ecosistem = ecosistem;
    }

    static string getEcosistem()
    {
        return Copac::ecosistem;
    }

    void setCuloare(string culoare)
    {
        this->culoare = culoare;
    }

    string getCuloare()
    {
        return culoare;
    }

   void setCrestere(float* CrestereLuna)
    {
        this->CrestereLuna = CrestereLuna;
        if(this->CrestereLuna != NULL)
        {
            delete[]this->CrestereLuna;
        }
    }

    float* getCrestereLuna()
    {
        return CrestereLuna;
    }

void setInaltime(float inaltime)
{
    this->inaltime = inaltime;
}

float getInaltime()
{
    return inaltime;
}

void setLatimeTrunchi(float latimeTrunchi)
{
    this->latimeTrunchi = latimeTrunchi;
}

float getLatimeTrunchi()
{
    return latimeTrunchi;
}

//Functie Friend
friend void CrestereMedieCopac(Copac cmCopac);
friend int GetLatimeTrunchi(Copac copac);
//Friend istream
friend istream& operator>>(istream& iStream, Copac& copac);
//Friend ostream
friend ostream& operator<<(ostream& oStream, Copac copac);
//Operator de atribuire
Copac& operator=(const Copac& copac)
{
    if (this != &copac)
    {
this->culoare = copac.culoare;
this->inaltime = copac.inaltime;
this->latimeTrunchi = copac.latimeTrunchi;
this->x = copac.x;
if (this->CrestereLuna != NULL)
{
    delete[]CrestereLuna;
}

    this->CrestereLuna = new float[5];
    for(int i =0; i<5;i++)
    {
        this->CrestereLuna[i] = copac.CrestereLuna[i];
    }

    }

    return *this;
}

//Operator +
Copac operator+(int valoare)
{
    Copac aux = *this;
    aux.inaltime = this->inaltime + valoare;
    return aux;
}

//Operator []
float& operator[](int index)
{
    if(index >= 0 && index < 5)
    {
        return CrestereLuna[index];
    }
}

//Operator ()
float operator()(int i, int j)
{
    float suma = 0;
    if(i-1>=0 && j-1<5)
    {
        for(int k=i-1;k<j;k++)
        {
        suma += this->CrestereLuna[k];
        }


    }

    float media = suma/(j-i+1);
    return media;
}

};

class Trandafir
{
private:
    const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLunaTrandafir;
    float inaltime;
    int nrPet; 
    bool Spini;
    int x;
public:

//Constructor fara parametru
   Trandafir() : TipPlanta(2)
    {
       this->CrestereLunaTrandafir = NULL;
       this->inaltime = 0;
       this->nrPet = 0;
       this->Spini = false;
       this->culoare = "Necunoscut";
       this->x=0;


    
    }
    //Constructor cu n par.
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

//Constructor cu 1 par.
    Trandafir(int TipPlanta):TipPlanta(TipPlanta)
    {
       this->CrestereLunaTrandafir = NULL;
       this->inaltime = 0;
       this->nrPet = 0;
       this->Spini = false;
       this->culoare = "Necunoscut";
       this->x=0;

    }
//Constructor de Copiere
    Trandafir(const Trandafir& copy) : TipPlanta(copy.TipPlanta)
    {
        this->inaltime = copy.inaltime;
        this->culoare = copy.culoare;
        this->nrPet = copy.nrPet;
        this->x = copy.x;
        this->Spini = copy.Spini;
        this->CrestereLunaTrandafir = new float[5];
        for(int i =0; i<5; i++)
        this->CrestereLunaTrandafir[i] = copy.CrestereLunaTrandafir[i];
    }
//Destructor
    ~Trandafir()
    {
        delete[]CrestereLunaTrandafir;
    }

    static void Ecosistem(string ecosistem)
    {
       Trandafir::ecosistem = ecosistem;
    }
//Afisare
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
//Geteri si Seteri
    int getTipPlanta()
    {
        return this->TipPlanta;
    }

    static void setEcosistem(string ecosistem)
    {
    Trandafir::ecosistem = ecosistem;
    }

    static string getEcosistem()
    {
        return Trandafir::ecosistem;
    }

    void setCuloare(string culoare)
    {
        this->culoare = culoare;
    }

    string getCuloare()
    {
        return culoare;
    }

   void setCrestere(float* CrestereLunaTrandafir)
    {
        this->CrestereLunaTrandafir = CrestereLunaTrandafir;
        if(this->CrestereLunaTrandafir != NULL)
        {
            delete[]this->CrestereLunaTrandafir;
        }
    }

    float* getCrestereLuna()
    {
        return CrestereLunaTrandafir;
    }

void setInaltime(float inaltime)
{
    this->inaltime = inaltime;
}

float getInaltime()
{
    return inaltime;
}

void setNrPet(int nrPet)
{
    this->nrPet = nrPet;
}

int getNrPet()
{
    return nrPet;
}

void setSpini(bool Spini)
{
    this->Spini = Spini;
}

bool getSpini()
{
    return Spini;
}
//Functie Friend
friend void CrestereMedieTrandafir(Trandafir cmtdf);

friend void RupePetalele(const Trandafir& copytdf);

//Operator Unari Prefixata
Trandafir& operator++()
{
    this->nrPet++;
    return *this;
}

//Friend pentru Operator <<
friend ostream& operator<<(ostream& oStream, Trandafir tdf);
//Friend pentru Operator >>
friend istream& operator>>(istream& iStream, Trandafir& tdf);


//Operator cast (explicit)
explicit operator float()
{
    return inaltime;
}


};

class Lavanda
{
    private:
    const int TipPlanta;
    static string ecosistem;
    string culoare;
    float* CrestereLunaLavanda;
    float inaltime;
    bool aroma;
    int x;

    public:
//Constructor fara parametru
    Lavanda():TipPlanta(3)
    {
        this->culoare = "Neconoscuta";
        this->inaltime = 0;
        this->CrestereLunaLavanda = NULL;
        this->aroma = false;
        this->x=0;

    }
//Constructor cu n par.
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
//Constructor cu 1 par.
    Lavanda(int TipPlanta):TipPlanta(TipPlanta)
    {
        this->culoare = "Necunoscuta";
        this->inaltime = 0;
        this->CrestereLunaLavanda = NULL;
        this->aroma = false;
        this->x=0;
    }

//Constructor de Copiere
 Lavanda(const Lavanda& copy) : TipPlanta(copy.TipPlanta)
    {
        this->inaltime = copy.inaltime;
        this->culoare = copy.culoare;
        this->aroma = copy.aroma;
        this->x = copy.x;
        this->CrestereLunaLavanda = new float[5];
        for(int i =0; i<5; i++)
        this->CrestereLunaLavanda[i] = copy.CrestereLunaLavanda[i];
    }
//Destructor
    ~Lavanda()
    {
        delete[]CrestereLunaLavanda;
    }
 static void Ecosistem(string ecosistem)
    {
        Lavanda::ecosistem = ecosistem;
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
//Geteri si Seteri
    int getTipPlanta()
    {
        return TipPlanta;
    }

    static void setEcosistem(string ecosistem)
    {
        Lavanda::ecosistem = ecosistem;
    }

    void setCuloare(string culoare)
    {
        this->culoare = culoare;
    }

    string getCuloare()
    {
        return culoare;
    }

    void setInaltime(float inaltime)
    {
        this->inaltime = inaltime;
    }

    float getInaltime()
    {
        return inaltime;
    }

    void setAroma(bool aroma)
    {
        this->aroma = aroma;
    }

    bool getAroma()
    {
        return aroma;
    }

    void setCrestereLuna(float* CrestereLunaLavanda)
    {
        this->CrestereLunaLavanda = CrestereLunaLavanda;
        if(this->CrestereLunaLavanda != NULL)
        delete[]this->CrestereLunaLavanda;
    }

    float* getCrestereLuna()
    {
        return CrestereLunaLavanda;
    }
//Functie Friend
friend void CrestereMedieLavanda(Lavanda cmlv);
friend ostream& operator<<(ostream& output, Lavanda lv);
friend istream& operator>>(istream& input, Lavanda& lv);
//Operator!
Lavanda operator! () {
    Lavanda copy = *this;
    copy.aroma = !copy.aroma;
    return copy;
}

//Operator()
float operator()(int i, int j)
{
float schimbare;
schimbare = CrestereLunaLavanda[j-1] - CrestereLunaLavanda[i-1];
return abs(schimbare);
}

//Operator*

Lavanda operator*(int valoare)
{
    Lavanda c = *this;
    c.inaltime = this->inaltime * valoare;
    return c;
}

//Operator->
Lavanda* operator->()
{
    this->inaltime = 15000;
    return this;
}
};
//Operator>>
istream& operator>>(istream& iStream, Trandafir& tdf)
{
    cout << "Culoare: ";
    iStream >> tdf.culoare;
    cout << "Inaltime: ";
    iStream >> tdf.inaltime;
    cout << "NR Petale: ";
    iStream >> tdf.nrPet;
    cout << "Are Spini: (1/0) ";
    iStream >> tdf.Spini;
    if(tdf.CrestereLunaTrandafir != NULL)
    {
        delete[]tdf.CrestereLunaTrandafir;
    }
    tdf.CrestereLunaTrandafir = new float[5];
    for(int i=0;i<5;i++)
    {
        cout <<"Crestere in Luna "<<(i+1)<<": ";
        iStream >> tdf.CrestereLunaTrandafir[i];
    }
    return iStream;
}
//Operator<<
ostream& operator<<(ostream& oStream, Trandafir tdf)
{
    oStream <<"Culoare: " << tdf.culoare <<endl<<"Inaltime: "<<tdf.inaltime<<endl<<"Nr Petale: "<<tdf.nrPet<<endl<<"Spini (1-adv/0-fals): "<<tdf.Spini<<endl;
    for(int i = 0; i<5;i++)
    {
        oStream <<"Luna "<<i+1<<": "<<tdf.CrestereLunaTrandafir[i]<<endl;
    }
    return oStream;
}

//Functii globale
void CrestereMedieCopac(Copac cmCopac)
{
float suma = 0;
    for(int i = 0;i<5;i++)
    {
        suma = suma + cmCopac.CrestereLuna[i];
    }

    float media = suma/5;

    cout<<"Copacul a crescut cu "<<media<<" metri in medie in 5 luni"<<endl;
}

void CrestereMedieTrandafir(Trandafir cmtdf)
{

    float suma = 0;
    for(int i =0;i<5;i++)
    {
        suma = suma + cmtdf.CrestereLunaTrandafir[i];
    }

    float media = suma/5;

    cout<<"Trandafirul a crescut cu "<<media<<" metri in medie in 5 luni"<<endl;

}

void CrestereMedieLavanda(Lavanda cmlv)
{
    float suma = 0;
    for(int i =0; i<5;i++)
    {
        suma = suma + cmlv.CrestereLunaLavanda[i];
    }

    float media = suma/5;

     cout<<"Lavanda a crescut cu "<<media<<" metri in medie in 5 luni"<<endl;
}

void RupePetalele(const Trandafir& copytdf)
{
   int nrPet = copytdf.nrPet;
   nrPet = nrPet - 1;

   cout<<"Nr Petale: "<<nrPet<<endl;
}

int GetLatimeTrunchi(Copac copac)
{
    
    return copac.getLatimeTrunchi();

}
istream& operator>>(istream& iStream, Copac& copac)
{
    cout<<"Inaltime: ";
    iStream>>copac.inaltime;
    cout<<endl<<"Latime Trunchi: ";
    iStream>>copac.latimeTrunchi;
    cout<<endl<<"Culoare: ";
    iStream>>copac.culoare;
    if(copac.CrestereLuna != NULL)
    {
        delete[]copac.CrestereLuna;
    }
    copac.CrestereLuna = new float[5];
    for(int i = 0; i<5;i++)
    {
        cout<<endl<<"Crestere Luna "<<i+1<<": ";
        iStream>>copac.CrestereLuna[i];
    }
    return iStream;
}
ostream& operator<<(ostream& oStream, Copac copac)
{
    oStream << "Inaltime: "<<copac.inaltime<<endl;
    oStream << "Latime Trunchi: "<<copac.latimeTrunchi<<endl;
    oStream << "Culoare: "<<copac.culoare<<endl;
    for(int i = 0; i<5; i++)
    {
        oStream<<"Crestere in Luna "<<i+1<<": "<<copac.CrestereLuna[i]<<endl;
    }
    return oStream;
}

istream& operator>>(istream& input, Lavanda& lv)
{
    cout<<"Inaltime: ";
    input>>lv.inaltime;
    cout<<endl<<"Culoare: ";
    input>>lv.culoare;
    cout<<endl<<"Aroma? ";
    input>>lv.aroma;
    if(lv.CrestereLunaLavanda != NULL)
    {
        delete[]lv.CrestereLunaLavanda;
    }
    lv.CrestereLunaLavanda = new float[5];
    for(int i = 0; i<5; i++)
    {
    cout<<endl<<"Crestere Luna "<<i+1<<": ";
   input>>lv.CrestereLunaLavanda[i];
    }
    return input;
}
ostream& operator<<(ostream& output, Lavanda lv)
{
    output << "Inaltime: "<<lv.inaltime<<endl;
    output << "Culoare: "<<lv.culoare<<endl;
    output <<"Aroma (1-True/0-Fals): "<<lv.aroma<<endl;
    for(int i = 0; i<5; i++)
    {
        output<<"Crestere in Luna "<<i+1<<": "<<lv.CrestereLunaLavanda[i]<<endl;
    }
    return output;
}

class ingrizirePlante
{
private:
    Trandafir* trandafir;
    int inaltime;
    const int Observare;
    static int nrSaptamana;
    float cantitateApa;
    bool plouat;

public: 

    Trandafir* gettrandafir()
    {
        return trandafir;
    }

    void settrandafir(Trandafir* trandafir)
    {
        this->trandafir = trandafir;
    }
    int getinaltime()
    {
        return inaltime;
    }

    void setinaltime(int inaltime)
    {
        this->inaltime = inaltime;
    }

    int getObservare()
    {
        return Observare;
    }

   float getcantitateApa()
   {
        return cantitateApa;
   }

   void setcantitateApa(float cantitateApa)
   {
        this->cantitateApa = cantitateApa;
   }

   bool getplouat()
   {
    return plouat;
   }

   void setplouat()
   {
    this->plouat = plouat;
   }

    ingrizirePlante() : Observare(++nrSaptamana)
    {
        this->trandafir = NULL;
        this->plouat = false;
        this->cantitateApa = 0;
        this->inaltime = 0;
    }

    ingrizirePlante(Trandafir* trandafir, float cantitateApa, bool plouat, int inaltime):Observare(++nrSaptamana)
    {
        this->trandafir = trandafir;
        this->cantitateApa = cantitateApa;
        this->inaltime = inaltime;
        this->plouat = plouat;
    }

    ingrizirePlante& operator=(const ingrizirePlante& ip) 
    {
        trandafir = ip.trandafir;
        cantitateApa = ip.cantitateApa;
        plouat = ip.plouat;
        inaltime = ip.inaltime;
        return *this;
    }

    ingrizirePlante operator()()
    { 
        if(!this->plouat)
          this->cantitateApa += 10; 
        return *this;
    }

    ingrizirePlante operator++()
    {
        ++this->inaltime;
        return *this;
    }

void afisare()
{
    cout<<"In observarea din Saptamana: "<<Observare<<endl;
    if(trandafir != nullptr)
    {
        cout<<"Planta Observata: Trandafir"<<endl;
    }
    else
    {
        cout<<"Planta Observata: - "<<endl;
    }
    cout<<"Inaltime: "<<inaltime<<endl;
    cout<<"Vreme: "<<(plouat ? "ploaie":"Fara ploaie")<<endl;
    cout<<"Cantitate de apa pentru hidratare: "<<cantitateApa<<" L"<<endl;

}

};

string Copac::ecosistem = "Mediterranean";
string Trandafir::ecosistem = "Mediterranean";
string Lavanda::ecosistem = "Mediterranean";
int ingrizirePlante::nrSaptamana = 0;

int main()
{
    /*
//COPAC
cout<<"COPAC:"<<endl;
//Initializam Crestere Lunara
float* CrestereLunaCopac = new float[5];
CrestereLunaCopac[0] = 0.22;
CrestereLunaCopac[1] = 0.25;
CrestereLunaCopac[2] = 0.27;
CrestereLunaCopac[3] = 0.29;
CrestereLunaCopac[4] = 0.31;

//Obiecte
Copac copac1;
Copac copac3(1, 10, 7, CrestereLunaCopac, "Verzi");
Copac copac2(1);
//Apelam Constructor de copiere pentru copac 4
Copac copac4 = copac3;
//Afisare 
cout << "Copac 1: Creat fara parametru: Valoare NULL"<< endl;
copac1.afisare();
cout<<"Copac 2: Creat cu 1 parametru: Valoare NULL"<< endl;
copac2.afisare();
cout<<"Copac 3: Creat cu 5 par."<< endl;
copac3.afisare();
cout<<"Folosind Constructorul de copiere, am creat Copac 4 cu valorile lui 3:"<< endl;
copac4.afisare();
//Calculam Media folosind functie globala si friend
CrestereMedieCopac(copac4);
//Operator de Atribuire 
cout<<"Folosim operatorul de atribuire astfel incat Copac 1 = Copac 4:"<<endl;
copac1 = copac4;
copac1.afisare();
//Operator+
cout<<"Folosim Operatorul+ si incrementam inaltimea lui Copac 4 cu 3 metri:"<<endl;
copac4 = copac4 + 3;
copac4.afisare();
//Operator[]
cout<<"Folosim Operatorul[] si aflam Cresterea in Luna 2 pentru Copac 4:"<<endl;
cout<<copac4[1]<<endl;
//Operator()
float medialuna = copac4(1,3);
cout<<"Folosim operatorul() si aflam cu ce medie a crescut Copac 4 intre luna 1 si 3:"<<medialuna;
cout << endl;
cout<<"Latime Trunchi folosind functie friend: "<<GetLatimeTrunchi(copac4)<<endl;




Copac *v_copac = new Copac[4];
for(int i = 0; i<4; i++)
{
    cout <<endl<< "Introduceti informatii pentru Copac "<<i+1<<": "<<endl;
    cin>>v_copac[i];
}

for(int i = 0; i<4; i++)
{
    cout<<endl<<"Copac "<<i+1<<": "<<endl<<v_copac[i];
}

Copac** m_copac = new Copac*[2];
    for (int i = 0; i < 3; i++) 
    {
        m_copac[i] = new Copac[2];
    }
for(int i = 0; i<2; i++)
for(int j = 0; j<2; j++)
cin>>m_copac[i][j];
for(int i = 0; i<2;i++)
for(int j = 0; j<2;j++)
{
    cout<<endl<<"Copac["<<i+1<<"]"<<"["<<j+1<<"] : ";
    cout<<m_copac[i][j];
}
*/
//Trandafir - initializare
cout<<"TRANDAFIR:"<<endl;
float* CrestereLunaTrandafir = new float[12];
CrestereLunaTrandafir[0] = 0.10;
CrestereLunaTrandafir[1] = 0.12;
CrestereLunaTrandafir[2] = 0.15;
CrestereLunaTrandafir[3] = 0.16;
CrestereLunaTrandafir[4] = 0.19;

Trandafir tdf1;
Trandafir tdf3(2, 10, 7, CrestereLunaTrandafir, false, "Rosie");
Trandafir tdf2(2);
Trandafir tdf4 = tdf3;
//Afisare 
cout<<"Trandafir 1: Creat fara parametru: Valoare NULL"<<endl;
tdf1.afisare();
cout<<"Trandafir 2: Creat cu un par."<<endl;
tdf2.afisare();
cout<<"Trandafir 3: Creat cu 6 par"<<endl;
tdf3.afisare();
cout<<"Trandafir 4: Folosind constructorul de copiere = Trandafir 3"<<endl;
tdf4.afisare();
CrestereMedieTrandafir(tdf4);
cout<<"Rup o Petala"<<endl;
RupePetalele(tdf4);

cout<<"Folosing Operatorul++, incrementam postfixata nr de petale"<<endl;
Trandafir tdf5;
tdf5.setNrPet(1);
++tdf5;
cout<<tdf5.getNrPet()<<endl;
Trandafir tdf6;
cout << "Cream Trandafir 6 si folosim operatorul >>"<<endl;
cin >> tdf6;
cout<<"Afisam valorile lui Trandafir 6 folosind operatorul<<" <<endl;
cout << tdf6;

Trandafir *v_tdf = new Trandafir[4];
for(int i = 0; i<4; i++)
{
    cout <<endl<< "Introduceti informatii pentru Trandafir "<<i+1<<": "<<endl;
    cin>>v_tdf[i];
}

for(int i = 0; i<4; i++)
{
    cout<<endl<<"Trandafir "<<i+1<<": "<<endl<<v_tdf[i];
}

float inaltimeExplicit = (float)tdf6;
cout <<endl<<"Valoare varabiliei 'Inaltime' devine de tip 'float': "<<tdf6.getInaltime()<<endl;
//Lavanda - intializare
cout<<"LAVANDA:"<<endl;
float* CrestereLunaLavanda = new float[5];
CrestereLunaLavanda[0] = 0.15;
CrestereLunaLavanda[1] = 0.12;
CrestereLunaLavanda[2] = 0.11;
CrestereLunaLavanda[3] = 0.12;
CrestereLunaLavanda[4] = 0.10;

Lavanda lv1;
Lavanda lv3(3,3,"violet", CrestereLunaLavanda,true);
Lavanda lv2(3);
/*
//Afisare
cout<<"Lavanda 1: Creat fara parametru: Valoare NULL"<<endl;
lv1.afisare();
cout<<"Lavanda 2: Creat cu 1 par: Valoare NULL"<<endl;
lv2.afisare();
cout<<"Lavanda 3: Creat cu 5 Par."<<endl;
lv3.afisare();
CrestereMedieLavanda(lv3);
cout<<"Folosind operatorul!, negam atributul aroma lui Lavanda 3"<<endl;
Lavanda aromalv3 = (!lv3);
cout<<aromalv3.getAroma()<<endl;
cout<<"Diferenta de crestere intre luna 3 si 1: "<<lv3(1,3)<<endl;
Lavanda lv4 = lv3 * 2;
cout<<"Inmultim inaltime lui Lavanda 3 cu 2: "<<lv4.getInaltime();
Lavanda lv5;
cout <<endl<< "Folosind operatorul->, Setam pointerul atributului 'inaltime' lui Lavanda 5 ca '1500' si afisam pointerul"<<endl;
lv5.setInaltime(1);
cout << lv5.getInaltime()<<endl;
cout << lv5->getInaltime()<<endl;

Lavanda *v_lv = new Lavanda[4];
for(int i = 0; i<4; i++)
{
    cout <<endl<< "Introduceti informatii pentru Lavanda "<<i+1<<": "<<endl;
    cin>>v_lv[i];
}

for(int i = 0; i<4; i++)
{
    cout<<endl<<"Lavanda "<<i+1<<": "<<endl<<v_lv[i];
}

delete[]CrestereLunaCopac;
delete[]CrestereLunaLavanda;
delete[]CrestereLunaTrandafir;
delete[]v_copac;
delete[]v_lv;
delete[]v_tdf;

for(int i = 0;i<2;i++)
{
    delete[]m_copac[i];
}
delete[]m_copac;

*/

ingrizirePlante ip1;
ingrizirePlante ip2(&tdf6, 10, false, tdf6.getInaltime());

ingrizirePlante ip3 = ip2;

cout<<"Observam plantele in prima saptamana si afisam: "<<endl;
ip1.afisare();
cout<<endl<<endl<<"Observam plantele din saptamana "<<ip2.getObservare()<<" (Trandafirul 6)"<<endl;
ip2.afisare();
cout<<endl<<endl<<"Folosind operatorul (), verificam daca a plouat. Daca nu a plouat, administram inca 10L de apa"<<endl;
ip2();
cout<<"Observam plantele din saptamana "<<ip2.getObservare()<<" (am apelat operatorul () deci cantitatea de apa va fi 0)";
cout<<endl;
ip2.afisare();
cout<<endl<<endl<<"Observam plantele din saptamana "<<ip3.getObservare()<<" (am folosit operatorul de atribuire deci va fi = cu sapt 2)"<<endl;
ip3.afisare();
++ip3;
cout<<endl<<endl<<"Observam plantele din saptamana "<<ip3.getObservare()<<" (am folosit operatorul ++ prefix. sa incrementam inaltimea)"<<endl;
ip3.afisare();

}


