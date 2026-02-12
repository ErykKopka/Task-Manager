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
    string text;
    ifstream read("tasks.txt");
    vector<string> tasks;
    while(getline(read, text)){
        tasks.push_back(text);
    }
    read.close();
    ofstream save("tasks.txt");

    do{
        clearScreen();
        for(int i=0;i<tasks.size();i++){
            cout<<i+1<<" "<<tasks.at(i)<<endl;
        }
        cout<<endl<<endl;

        cout<<"1 - Dodaj zadanie"<<endl;
        cout<<"2 - Usun zadanie"<<endl;
        cout<<"0 - Wyjscie"<<endl;

        cin>>menu;

        switch(menu){
            case 1:{
                tasks.resize(tasks.size()+1);
                cout<<"Task name: ";
                cin>>tasks.back();
                break;
            }
            case 2:{
                cout<<"Which task to remove: ";
                cin>>tmp;
                if(tasks.size()>=tmp and tmp>0){
                    tasks.erase(tasks.begin()+tmp-1);
                }
                else{
                    cout<<"Wrong task number. "<<endl;
                }
                break;
            }
        }

    }while(menu!=0);

    for(string task : tasks){
        save<<task<<endl;
    }

    save.close();
    return 0;
}