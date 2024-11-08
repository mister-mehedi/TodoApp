#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#include "Task.h"
#include "TodoApp.h"


using namespace std;


// search and completed feature remains...
int main(){
    cout << "Hello world!" << endl;

    //Task tast1("A","a for apple");
    //cout<<tast1.getTitle()<<endl;

    TodoApp todoApp;
    int choice;
    string title, description;

    do{
        cout << "\nTodo App Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "4. List Tasks\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
        case 1:
            cout << "Enter task title: ";
            getline(cin,title);
            cout << "Enter task description: ";
            getline(cin,description);
            todoApp.addTask(title,description);
            break;
        case 2:
            cout << "Enter task title to remove: ";
            getline(cin,title);
            todoApp.remmoveTask(title);
            break;
        case 4:
            todoApp.listTasks();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    }while(choice!=5);

    return 0;
}