#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void clearScreen(){
    cout<<"\033[2J\033[1;1H";
}

int main(){  //{}  =  +  g++ task_manager.cpp -o task_manager.exe
    int menu;
    int tmp;
    string tekst;
    ifstream odczyt("zadania.txt");
    vector<string> zadania;
    while(getline(odczyt, tekst)){
        zadania.push_back(tekst);
    }
    odczyt.close();
    ofstream zapis("zadania.txt");

    do{
        clearScreen();
        for(int i=0;i<zadania.size();i++){
            cout<<i+1<<" "<<zadania.at(i)<<endl;
        }
        cout<<endl<<endl;

        cout<<"1 - Dodaj zadanie"<<endl;
        cout<<"2 - Usun zadanie"<<endl;
        cout<<"0 - Wyjscie"<<endl;

        cin>>menu;

        switch(menu){
            case 1:{
                zadania.resize(zadania.size()+1);
                cout<<"Wpisz tresc zadania: ";
                cin>>zadania.back();
                break;
            }
            case 2:{
                cout<<"Ktore zadanie usunac: ";
                cin>>tmp;
                if(zadania.size()>=tmp and tmp>0){
                    zadania.erase(zadania.begin()+tmp-1);
                }
                else{
                    cout<<"Bledny numer zadania"<<endl;
                }
                break;
            }
        }

    }while(menu!=0);

    for(string zadanie : zadania){
        zapis<<zadanie<<endl;
    }

    zapis.close();
    return 0;
}