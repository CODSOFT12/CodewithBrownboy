#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool completed;

    Task() 
    {
        description = "";
    completed=false;
    
    }
};

class TodoList 
{
private:
    Task tasks[MAX_TASKS];
    int taskCount;

public:
    TodoList() 
    {
        taskCount = 0;
    }

    void addTask(string description) 
    {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].description = description;
            tasks[taskCount].completed = false;
            taskCount++;
            cout << "Task added: " << description << endl;
        }
        else {
            cout << "Task list is full. Cannot add more tasks." << endl;
        }
    }

    void viewTasks()
    {
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int taskNumber) 
    {
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int taskNumber) 
    {
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            for (int i = taskNumber - 1; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout << "Task removed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main()
{
    TodoList todoList;
    char choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case '2':
            todoList.viewTasks();
            break;
        case '3': 
        {
            int taskNumber;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber);
            break;
        }
        case '4': 
        {
            int taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            todoList.removeTask(taskNumber);
            break;
        }
        case '5':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    while (choice != '5');

    return 0;
}
