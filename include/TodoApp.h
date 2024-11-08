#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#include "Task.h"

using namespace std;

#ifndef TODOAPP_H
#define TODOAPP_H


class TodoApp
{
    private:
        set<Task> tasks;

    public:
        TodoApp()=default;
        //virtual ~TodoApp();

        void addTask(const string& title, const string& description){
            Task task(title, description);
            tasks.insert(task);
            cout<<"Added task: \""<<title<<"\""<<endl;
        }

        void remmoveTask(const string& title){
            Task task(title, "");
            auto it=tasks.find(task);

            if(it != tasks.end()){
                tasks.erase(it);
                cout << "Removed task \"" << title << "\"" << endl;
            }else{
                cout << "Task \"" << title << "\" not found" << endl;
            }
        }

        void listTasks() const{
            cout<<"\nTodo List: "<<endl;
            for(auto task:tasks){
                task.printTask();
            }
            cout<<endl;
        }
};

#endif // TODOAPP_H
