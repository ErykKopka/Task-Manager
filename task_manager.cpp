#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

void clearScreen(){
    cout<<"\033[2J\033[1;1H";
}

class Task{
private:
    int id;
    string taskTitle;
    string taskDesc;
    bool completed;
public:
    Task(int id, string taskTitle, string taskDesc="")
    : id(id), taskTitle(taskTitle), taskDesc(taskDesc), completed(false){}
    int getId() const{
        return id;
    }
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
    void switchCompletion(bool completion){
        completed=!completed;
    }
};

class TaskManager{
private:
    vector<Task> tasks;
    int nextId=1;
public:
    const Task& getTask(int id) const{
        auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& t){ return t.getId() == id; });
        if(it != tasks.end()) return *it;
    }
    const std::vector<Task>& getTasks() const{
        return tasks;
    }   
    int getTaskCount() const{
        return tasks.size();
    } 
    void addTask(string title,string desc){
        tasks.emplace_back(nextId,title,desc);
        nextId++;
    }
    void removeTask(int id){
        auto it=find_if(tasks.begin(),tasks.end(),[id](const Task& obj){return id==obj.getId();});
        if(it!=tasks.end()){
            tasks.erase(it);
        }
    }
};

int main(){  //{}  =  + [] g++ task_manager.cpp -o task_manager.exe
    int menu,tmp;
    string text,text2;
    TaskManager manager;
    map<int,int> idMap;
    int displayCounter;
    do{
        clearScreen();
        idMap.clear();
        displayCounter=1;
        for(const Task& task : manager.getTasks()){
            cout << displayCounter << ". " << task.getTitle() << endl;
            idMap[displayCounter] = task.getId();
            displayCounter++;
        }
        cout<<endl<<endl;

        cout<<"1 - Add task"<<endl;
        cout<<"2 - Remove task"<<endl;
        cout<<"0 - Exit"<<endl;

        cin>>menu;

        switch(menu){
            case 1:{
                cin.ignore();
                cout<<"Task name: ";
                getline(cin, text);
                cout<<"Task description: ";
                getline(cin, text2);
                manager.addTask(text,text2);
                break;
            }
            case 2:{
                cout<<"Which task to remove: ";
                cin>>tmp;
                tmp=idMap.at(tmp);
                auto it = idMap.find(tmp);
                if(it != idMap.end()){
                    manager.removeTask(tmp);
                } 
                else{
                    cout<<"Zadanie nr.  "<<tmp<<" nie istnieje."<<endl;
                }
                break;
            }
        }

    }while(menu!=0);

    return 0;
}