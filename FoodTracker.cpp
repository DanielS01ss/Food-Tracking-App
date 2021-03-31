#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "User.h"
#include "enums.h"
#include "Aliment.h"
#include "calculator-functions.cpp"
using namespace std;


///aici putem face fisiere pentru a putea stoca pentru fiecare meniu al zilei imparte
///adica daca e sa introduca 

//// progresul reprezinta ce a mancat
///

void writeAlimente()
{
    fstream f;
    f.open("alimente.txt", ios::app);
    ///acuma va trebui sa introducem obiecte de forma celor care contin
    ///date pentru 
     ///acuma ce facem este ca vom introduce un aliment in fisier

    ///std::string nume, double val_energetica,double grasimi, double glucide, double fibre,double proteine,double cantitate
    string nume;
    string line;
    double val_energ, grasimi, glucide, fibre, proteine, cantitate,sare;
    cout << "Numele alimentului:";
    fflush(stdin);
    cin.get();
    getline(cin, nume);
    cout << "Introdu valoarea energetica a alimentului:";
    cin >> val_energ;
    cout << "Introdu grasimile:";
    cin >> grasimi;
    cout << "Introdu glucidele:";
    cin >> glucide;
    cout << "Introdu fibrele:";
    cin >> fibre;
    cout << "Proteine:";
    cin >> proteine;
    cout << "Sare:";
    cin >> sare;
    cout << "Cantitate:";
    cin >> cantitate;


    line = "\n" + nume + "," + to_string(val_energ) + "," + to_string(grasimi) + "," + to_string(glucide) + "," + to_string(fibre) + "," + to_string(proteine)+","+to_string(sare)+ "," + to_string(cantitate);
    f << line;
}

///noi aici o sa avem de creeat un user
///userul acesta este folosit doar o data
///adica per aplicatie vom avea doar un singur user


User createUser()
{
    ///aici ce vom face este ca vom citi datele pentru user si apoi il vom stoca in fisier
    system("cls");
    fstream f;
    ///am deschis fisierul in modul append pentru a putea adauga la finalul fisierului
    ///vom avea de adaugat anumite 
    f.open("users.txt", ios::app);

    ///acuma ce facem este ca 
    ///vom adauga la finalul listei
    ///si vreau sa fie ceva la modul

    /*  Prima data vom citi datele si apoi vom initializa obiectul  */
    std::string name;
    int age;
    bool sex;
    double greutate, inaltime, greutate_dorita;

    cout << "\n\n-------<<<<<< DATE UTILIZATOR >>>>-----------\n\n";
    cout << "\n\n\n";
    cout << "Name:";
    cin >> name;



    cout << "Age:";
    cin >> age;
    cout << "Sex(M/F):";
    char gender;
    cin >> gender;
    while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f')
    {
        cout << "\n\n\INTRODUCETI CORECTUL SEXUL!!!!\n\n";
        cout << "Sex(M\F):";
        cin >> gender;
    }
    gender = tolower(gender);
    if (gender == 'M')
        sex = 0;
    else
        sex = 1;

    cout << "\nGreutate:";
    cin >> greutate;

    /*
        Chestii pe care le introduce userul
         greutate dorita
         activitate
         Scop



    */

    cout << "Introduceti greutatea la care doriti sa ajungeti:";
    cin >> greutate_dorita;

    cout << "Introduceti inaltimea:";
    cin >> inaltime;

    Activitate a;
    int actv;
    cout << "\n\nIntroduceti cifra corespunzatoarea tipului de activitate pe care o intreprindeti:\n";
    cout << "1.Sendentar\n";
    cout << "2.Usoara\n";
    cout << "3.Moderata\n";
    cout << "4.Intensa\n";
    cin >> actv;
    switch (actv)
    {
    case 1:
        a = Sedentar;
        break;

    case 2:
        a = Usoara;
        break;

    case 3:
        a = Moderata;
        break;

    case 4:
        a = Intensa;
        break;
    }

    /*
        Aceasta este partea pe care o calculeaza programul
         BMI:
         Metabolism
         SCOP -> il determinam pe baza greutatii
    */

    //BMI = greutate / inaltime^2
    double bmi_number = greutate / (inaltime * inaltime);
    ///aici o sa ave asa:
    ///vom analiza care este bmi-ul in functie de rezultatul pe care l-am obtinut

    BMI b1;
    if (bmi_number < 18.5)
    {
        b1 = Under;
    }
    else if (bmi_number >= 18.5 && bmi_number < 25)
    {
        b1 = Normal;
    }
    else if (bmi_number >= 25 && bmi_number < 30)
    {
        b1 = Over;
    }
    else if (bmi_number >= 30 && bmi_number < 40)
    {
        b1 = Obese;
    }
    else {
        b1 = ObeseExtreme;
    }

    ///vom merge pe ceea ce a introdus userul
    Scop s1;
    if (greutate_dorita == greutate)
    {
        s1 = Mentinere;
    }
    else if (greutate_dorita > greutate)
    {
        s1 = Crestere_in_greutate;
    }
    else if (greutate_dorita < greutate)
    {
        s1 = Scadere_in_greutate;
    }

    ///trebuie sa stabilim metabolismul
    ///si avem asa

    Metabolism m;
    if (a == Sedentar)
    {
        switch (b1)
        {
        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }

    }
    /*
       Activitate -> usoara -> obese & obese extreme sau over  == > lent
                            -> normal ==> normal
                            ->  under => rapid

   */

    else if (a == Usoara)
    {
        switch (b1)
        {
        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }
    }
    else if (a == Moderata)
    {

        switch (b1) {

        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Over:
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;

        }

    }
    else if (a == Intensa)
    {
        switch (b1) {

        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }
    }
    //nume varsta sex greutate inaltime greutate dorita bmi activitate scop metabolism

    User u(name, age, sex, greutate, inaltime, greutate_dorita, b1, a, s1, m);
    ///toate acestea vin adaugate la fisier
    ///si le vom scrie
    string line = name + " , " + to_string(age) + " , " + to_string(sex) + " , " + to_string(greutate) + " , " + to_string(inaltime) + " , " + to_string(greutate_dorita) + " , " + to_string(b1) + " , " + to_string(a) + " , " + to_string(s1) + " , " + to_string(m);
    f << line;
    f.close();
    return u;

}






char  display_logo()
{
    vector<string> logo;
    fstream f("logo.txt");
    int i = 0;
    string aux;
    while (getline(f, aux)) {
        logo.push_back(aux);
    }
    for (int i = 0; i < logo.size(); i++)
    {
        cout << logo[i];
        cout << endl;
    }

    Sleep(2000);
    system("CLS");

    cout << "\n\nWelcome to our food tracking app!!!" << endl;
    cout << "\n\nPlease choose an option from below:" << endl;
    cout << "\n\n1.Create account\n";
    cout << "\n2.Login\n\n";
    cout << "\n\n3.Exit" << endl;
    fflush(stdin);
    char c;
    cin >> c;
    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3)
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }
    f.close();
    return c;

}

void displayData(User u)
{
    system("cls");
    cout << "<<<<<<<===== THIS IS YOUR DATA =======>>>>>>>" << endl;
    cout << "Nume:" << u.getNume() << endl;
    /// name, age, sex, greutate, inaltime, greutate_dorita, b1, a, s1, m
    cout << "Varsta:" << u.getVarsta() << endl;
    cout << "Sex:" << (u.getSex() ? "F" : "M") << endl;
    cout << "Greutate:" << (u.getGreutate()) << " kg" << endl;
    cout << " Greutate dorita:" << (u.getGreutate_dorita()) << " kg" << endl;
    cout << "BMI:";
    switch (u.getPersonBmi())
    {
    case Under:
        cout << "Under" << endl;
        break;
    case Norm:
        cout << "Normal" << endl;
        break;
    case Over:
        cout << "Over" << endl;
        break;
    case Obese:
        cout << "Obese" << endl;
        break;
    case ObeseExtreme:
        cout << "Under" << endl;
        break;
    }

    cout << "Activitate:";
    switch (u.getPersonActivity())
    {
    case Sedentar:
        cout << "Sedentar" << endl;
        break;
    case Usoara:
        cout << "Usoara" << endl;
        break;
    case Moderata:
        cout << "Moderata" << endl;
        break;
    case Intensa:
        cout << "Intensa" << endl;
        break;
    }
    cout << "Scop:";

    switch (u.getPersonScope()) {
    case Scadere_in_greutate:
        cout << "Scadere in greutate" << endl;
        break;
    case Mentinere:
        cout << "Mentinere" << endl;
        break;
    case Crestere_in_greutate:
        cout << "Crestere in greutate" << endl;
        break;
    }
    cout << "Tipul de metabolism:";
    switch (u.getPersonMetabolism())
    {
    case Lent:
        cout << "Lent" << endl;
        break;
    case Normal:
        cout << "Normal" << endl;
        break;
    case Rapid:
        cout << "Rapid" << endl;
        break;
    }
}


void welcome(User u)
{
    system("cls");
    cout << "WELCOME!";
    cout << "\n\nChoose your option:\n";
    cout << "1.Display data\n";
    cout << "2.Add product\n";
    cout << "3.Exit\n";
    char c;
    cin >> c;
    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3)
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }

    switch (c)
    {
    case '1':
        displayData(u);
        break;
    case '2':
        writeAlimente();
        break;
    case '3':
        exit(0);
        break;

    }
}

void login(User u)
{
    ///aici trebuie sa citim datele si sa facem gathering

    welcome(u);


}

///ce face functia de data gathering este ca ne returneaza toate datele #
///de care avem nevoie si ni le returneaza sub forma de obiect user

User dataGathering()
{
    User u;
    ///vom lua practic primul user
    ///si dupa vedem
    ifstream f("users.txt");
    ///si citim o linie apoi o separam
    string line;
    getline(f, line);
    ///acuma stringul asta va fi spart pe tokenuri
    //nume varsta sex greutate inaltime greutate dorita bmi activitate scop metabolism

    /*
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    INTREBARE
      CE fel de data type este size_t????????
    !!!!!!!!!!!!!!!!!!!!!!!!!!!
    */

    //nume
    size_t pos = 0;
    pos = line.find(",");
    string token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setNume(token);

    //varsta
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setVarsta(stoi(token));
    ///ce face string::npos???

    ///sex
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setSex(stoi(token));

    ///greutate
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setGreutate(stod(token));

    ///inaltime
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setInaltime(stod(token));

    ///greutate dorita
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setGreutateDorita(stod(token));


    ///bmi
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonBMI((BMI)stoi(token));

    ///activitate
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonActivity((Activitate)stoi(token));


    ///scop
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonalScope((Scop)stoi(token));

    ///metabolism
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonMetabolism((Metabolism)stoi(token));
    f.close();
    return u;
}




void getAlimente(Aliment alim[], int &k)
{
    ///ce face aceasta functie este ca va trebuie sa intre in fisierul cu alimente
    ///si ce va face aceasta functie este ca va intra in fisier
    ///si va lua fiecare linie ca pe un string si dupa ce il parsuieste
    ///va atribui alimentele in vector

    ifstream f("alimente.txt");
    ///declaram o linie
    string line, token;
    ///citim aceasta linie din fisier
   
    size_t pos = 0;
    int i = 0;
    /*
    std::string nume
    double val_energetica
    double grasimi
    double glucide
    double fibre 
    double proteine
    double sare
    double cantitate
    */
   while (!f.eof())
    {
        getline(f, line);
        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setNume(token);

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setValEnergetica(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setGrasimi(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setGlucide(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setFibre(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setProteine(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setSare(stod(token));
        

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setCantitate(stod(token));
        i++;
    }
   k = i;
     ///setam pozitia la 0
     
     ///cautam prima virgula
     ///si returnam pozitia primei virgule
     
     ///ce avem pana la prima virgula care a fost mentionat ca si pozitie
     /// vom lua si vom stoca intr-un token
     ///si token practic este prima chestie care ne intereseaza
     ////adica daca avem ceva la modul name calories si fat
     ///ce va face este ca va
    
     ///dupa acesta vom sterge totul pana la token inclusiv
     

}

///acuma ce mai trebuie sa facem este sa creem functia care ne calculeaza 
///cat trebuie sa consume userul nostru
///baza pe preferinte



int main()
{

    User u1;
    Aliment a[10];
    int nr = 0;
    getAlimente(a,nr);

    
    double kcalPerDay, fats, glucides, fibres, proteins, salt;
    kcalPerDay = calculateKcals(u1);
    fats = calculateFats(u1,kcalPerDay);
    fibres = calculateFibres(kcalPerDay);
    glucides = calculateCarbs(u1,kcalPerDay);
    proteins = calculateProteins(u1,kcalPerDay);
    char c = display_logo();
    switch (c)
    {
    case '1':
        u1 = createUser();
        Sleep(3000);
        welcome(u1);
        break;
    case '2':
        u1 = dataGathering();
        login(u1);
        exit(0);
        break;
    case '3':
        exit(0);
        break;


    }
   
    return 0;
}


