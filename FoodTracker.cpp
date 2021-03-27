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
using namespace std;






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
  
    User u(name,age,sex,greutate,inaltime,greutate_dorita,b1,a,s1,m);
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
    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c-'0')!=3 )
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
        cout << "Greutate:" << (u.getGreutate()) <<" kg" <<endl;
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
                cout << "Scadere in greutate"<<endl;
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

void addProduct()
{
    system("cls");
    cout << "\n\nHere we will add a product!!!\n\n";
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
        addProduct();
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

User dataGathering()
{
    User u;
    ///vom lua practic primul user
    ///si dupa vedem
    ifstream f("users.txt");
    ///si citim o linie apoi o separam
    string line;
    getline(f,line);
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
    string token = line.substr(0,pos);
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
    return u;
}

int main()
{

    User u1;

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


