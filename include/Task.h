#include <iostream>
#include <string>
#include <utility>

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
        Task(string  title, string  description)
            : title(std::move(title)), description(std::move(description)), completed(false) {}
        //virtual ~Task();

        void markComplete(){
            completed=true;
        }

        bool isCompleted() const{
            return completed;
        }

        string getTitle(){
            return title;
        }

        void setDescription(const string& des){
          description=des;
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
