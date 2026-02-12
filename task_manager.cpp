#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void clearScreen(){
    cout<<"\033[2J\033[1;1H";
}

class Task{
private:
    const int id;
    string taskTitle;
    string taskDesc;
    bool completed;
public:
    Task(int id, string taskTitle, string taskDesc="")
    : id(id), taskTitle(taskTitle), taskDesc(taskDesc), completed(false){}
    const string& getTitle() const{
        return taskTitle;
    }
    const string& getDesc() const{
        return taskDesc;
    }
    bool isCompleted() const{
        return completed;
    }
    void changeTitle(string title){
        taskTitle=title;
    }
    void changeDesc(string desc){
        taskDesc=desc;
    }
    void swtichCompletion(bool completion){
        if(completion==false){
            completed=true;
        }
        else{
            completed=false;
        }
    }
};

class TaskManager{
private:
    vector<Task> tasks;
    int nextId=1;
public:
    const Task& getTask(int id) const{
        return tasks.at(id);
    }
    int getTaskCount() const{
        return tasks.size();
    }
    void addTask(string title,string desc){
        tasks.emplace_back(nextId,title,desc);
        nextId++;
    }
    void removeTask(){

    }
};

int main(){  //{}  =  +  g++ task_manager.cpp -o task_manager.exe
    int menu;
    string text,text2;

    TaskManager manager;

    do{
        clearScreen();
        
        cout<<endl<<endl;

        cout<<"1 - Add task"<<endl;
        cout<<"2 - Remove task"<<endl;
        cout<<"0 - Exit"<<endl;

        cin>>menu;

        switch(menu){
            case 1:{
                cout<<"Task name: ";
                cin>>text;
                cout<<"Task description: ";
                cin>>text2;
                manager.addTask(text,text2);
                break;
            }
            case 2:{
                
                break;
            }
        }

    }while(menu!=0);

    return 0;
}