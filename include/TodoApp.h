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
      /*struct TaskComparatorDescending {
        bool operator()( Task& lhs,  Task& rhs) const {
          return lhs.getTitle() > rhs.getTitle();  // Descending order by title
        }
      };*/
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

    void searchTask(const string& title) {
      /*for(auto task:tasks){
        if(task.getTitle()==title){
          task.printTask();
          return;
        }
      }
      cout << "Task \"" << title << "\" not found" << endl;*/



      Task task(title, "");  // Create a task with only title
      auto it = tasks.find(task);  // O(log n) search in set

      if (it != tasks.end()) {
        cout << "Task \"" << title << "\" found" << endl;
        it->printTask();
      } else {
        cout << "Task \"" << title << "\" not found" << endl;
      }

          /*
      Task task(title, "");  // Temporary Task object with title only
      auto it = tasks.find(task);  // Find the task in O(log n)

      if (it != tasks.end()) {
        cout << "Task \"" << title << "\" found:" << endl;
        it->printTask();  // Call printTask directly on the Task object
      } else {
        cout << "Task \"" << title << "\" not found" << endl;
      }
           */
    }


    void listTasks() const{
            cout<<"\nTodo List: "<<endl;
            for(auto task:tasks){
                task.printTask();
            }
            cout<<endl;
        }

    void descendingSort() const {
      /*sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
          return a.getTitle() > b.getTitle();  // Descending order
      });*/

      for (auto it = tasks.rbegin(); it != tasks.rend(); ++it) {
        it->printTask();
      }

      // Now, sortedTasks is in descending order
      /*for (const auto& task : sortedTasks) {
        task.printTask();
      }*/
    }

        /*void descendingSort() const{
          *//*sort(tasks.begin(),tasks.end(), []( Task& a,  Task& b){
              return a.getTitle()>b.getTitle();
          });*//*

          auto it=tasks.end();
          it--;
          while (it!=tasks.begin() && tasks.size()>1){
            it->printTask();
            it--;
          }
          it->printTask();
          cout<<endl;

          *//*cout<<"\nTodo List in descending nature: "<<endl;
          sort(tasks.rbegin(),tasks.rend());
          for(auto task:tasks){
            task.printTask();
          }
          cout<<endl;*//*
        }*/

        void markTaskCompleted(const string& title){
          Task task(title, "");
          auto it=tasks.find(task);

          if(it != tasks.end()){
            // Create a copy of the found task
            Task updatedTask = *it;

            tasks.erase(it);
            updatedTask.markComplete();
            tasks.insert(updatedTask);

            cout << "Marked task \"" << title << "\" as complete" <<endl;
            return;
          }
          cout << "Task \"" << title << "\" not found" <<endl;
        }

    void updateTask(const string& title, const string& description){
      Task task(title, "");
      auto it=tasks.find(task);

      if(it != tasks.end()){
        // Create a copy of the found task
        Task updatedTask = *it;

        tasks.erase(it);
        updatedTask.setDescription(description);
        tasks.insert(updatedTask);

        cout << "Updated description for the task \"" << title << "\"" <<endl;
        return;
      }
      cout << "Task \"" << title << "\" not found" <<endl;
    }
};

#endif // TODOAPP_H
