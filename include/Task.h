#include <iostream>
#include <string>

using namespace std;

#ifndef TASK_H
#define TASK_H


class Task
{
    private:
        string title;
        string description;
        bool completed;

    public:

        Task();
        Task(const string& title, const string& description)
            : title(title), description(description), completed(false) {}
        //virtual ~Task();

        void markComplete(){
            completed=true;
        }

        bool isCompleted(){
            return completed;
        }

        string getTitle(){
            return title;
        }

        void printTask(){
            cout<<(completed? "[y] ": "[n] ")<<title<<": "<<description<<endl;
        }

        // Overload < operator to compare tasks by title
        bool operator<(const Task& other) const {
            return title < other.title;
        }
};

#endif // TASK_H
