//Liabraries used
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <map>
#include <stdlib.h>


using namespace std;

//functions used

void start();
void signin();
void signup();
void displayingshops();


class account

{
    string name, no;

    public:

    friend void signin();
    friend void mopping();
    friend void signup();

};
void displayingshops()

{
    int n;
    cout << "Enter your area to choose our parent Shop ." << endl;
    cout << "1.Andheri\n2.Mira-Bhayandar\n3.Bandra\n4.Borivali\n5.Dahisar\n6.Goregaon\n7.Jogshwari\n8.Juhu" << endl;
    cin >> n;
}

//Mapping concpt used

void mopping(string file, string name)

{
    string pro;
    int x;
    float qty, bill = 0;

    map<string, float> product;

    product["Rice"] = 40;
    product["Moong Dal"] = 100;
    product["Toor Dal"] = 98;
    product["Masoor Dal"] = 60;
    product["Urad Dal"] = 104;
    product["Oil"] = 150;
    product["Salt"] = 18;
    product["Turmeric Powder"] = 20;
    product["Red Chili Powder"] = 100;
    product["Other Spices"] = 62;
    product["Chawli"] = 20;
    product["Lobia"] = 50;
    product["Green Peas"] = 70;
    product["Kidney Beans"] = 102;
    product["Moth Beans"] = 62;
    product["Masoor (Whole)"] = 200;
    product["Chickpeas"] = 144;
    product["Whole Wheat Flour"] = 45;
    product["Besan"] = 120;
    product["Maida"] = 60;
    product["Jowar Flour"] = 123;
    product["Rice Flour"] = 131;
    product["Nachni Flour"] = 120;
    product["Bajra Flour"] = 140;
    product["Sooji"] = 65;
    product["Rava"] = 45;
    product["Poha"] = 75;
    product["Peanuts"] = 110;
    product["Puffed Rice"] = 108;
    product["Sugar"] = 80;
    product["Tea"] = 100;
    product["Coffee "] = 10;


    map<string, float>::iterator itr;

    cout << "       Products    " << setw(10) << "Price   " << setw(10) << endl;

    for (itr = product.begin(); itr != product.end(); itr++)
    {
        cout << setw(16) << itr->first << " : " << setw(5) << itr->second << endl;
    }
    cout << "Enter 1 if you want product else  0 and  enter quantity " << endl;


    ofstream fout;
   
    fout.open(file, ios::app);

    fout << " Name of product            "
         << "Quantity" << endl;

    for (itr = product.begin(); itr != product.end(); itr++)
    {
        cout << itr->first << endl;
        cin >> x;

        if (x == 1)
        {
            cin >> qty;
            fout << setw(16) << itr->first << "  :          " << setw(5) << qty << endl;
            bill = bill + (itr->second) * qty;
            
        }
        
    }

    cout << "Your total bill is " << bill << endl;

    int num;

    srand(time(0));

    for (int i = 1; i <= 1; i++)

    {

        num = rand() % 100;
        cout << "You can come to our shop in " << num << " minutes.So at that time crowd will be less." << endl;

    }

    cout << "THANK YOU!!!\n Visit Again..";

    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    ofstream xout;
    file = name + ".txt";

    xout.open(file, ios::app);

    xout << "Logout time : " << asctime(ti);
}


void signup()
{
    string name, no;

    cout << "Enter your Name and Mobile number\n";
    cin >> name >> no;

    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    ofstream fout("info.txt", ios::app);
    fout << "Login time : " << asctime(ti);


    fout << "Name : " << name << endl
         << "Mobile number : " << no << endl;
    fout.close();


    cout << "Your account is created Successfully\n";

    signin();
}

void signin() //create account
{
    string name, str, atr, file;
    int ct = 0;

    ifstream fin("info.txt", ios::in);

    cout << "Enter your username for login" << endl;
    cin >> name;
    str = "Name : " + name;

    while (!fin.eof())
    {
        getline(fin, atr);
        if (!(str.compare(atr)))
        {
            ct++;

            time_t tt;
            struct tm *ti;
            time(&tt);
            ti = localtime(&tt);
            ofstream xout;
            file = name + ".txt";
            xout.open(file, ios::app);
            xout << "Login time : " << asctime(ti);
            cout << "Your account opened successfully\n";
        }
    }
    if (ct == 0)
    {
        cout << "You have not signedup yet.\nPlease create your account\n";
        signup();
    }
    if (ct == 1)
    {

        displayingshops();

        mopping(file, name);

    }
}
void start()
{
    int choice;

    cout << "WELCOME TO OUR SHOP IN ICHALKARANJI" << endl;

    cout << "1.Signin\n2.Sign up \n";

    cin >> choice;

    if (choice == 1)
        signin();
    else
        signup();
}

int main()
{

    start();
    
}
