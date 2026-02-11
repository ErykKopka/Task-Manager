#include<iostream>
#include<vector>
using namespace std;

int main(){  //{}  =  +  g++ task_manager.cpp -o task_manager.exe
    int menu;
    int tmp;
    vector<string> zadania;


    do{
        cout<<"1 - Wyswietl zadania"<<endl;
        cout<<"2 - Dodaj zadanie"<<endl;
        cout<<"3 - Usun zadanie"<<endl;
        cout<<"0 - Wyjscie"<<endl;

        cin>>menu;

        switch(menu){
            case 1:{
                for(int i=0;i<zadania.size();i++){
                    cout<<i+1<<" "<<zadania.at(i)<<endl;
                }
                break;
            }
            case 2:{
                zadania.resize(zadania.size()+1);
                cout<<"Wpisz tresc zadania: ";
                cin>>zadania.back();
                break;
            }
            case 3:{
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
    return 0;
}