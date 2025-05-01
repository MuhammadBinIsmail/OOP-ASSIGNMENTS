#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const char* TODO_FILE = "todo.txt";
const int MAX_TASKS = 100;

class TodoList {
private:
    char tasks[MAX_TASKS][100]; 
    bool completed[MAX_TASKS];  
    int taskCount = 0;         
    void loadTasks() {
        ifstream file(TODO_FILE);
        taskCount = 0;

        char line[200];
        while (file.getline(line, sizeof(line)) && taskCount < MAX_TASKS) {
            if (strlen(line) > 0) {
                if (line[0] == '1') {
                    completed[taskCount] = true;
                    strncpy(tasks[taskCount], line + 2, sizeof(tasks[0]) - 1);
                } else {
                    completed[taskCount] = false;
                    strncpy(tasks[taskCount], line + 2, sizeof(tasks[0]) - 1);
                }
                taskCount++;
            }
        }
        file.close();
    }
    void saveTasks() {
        ofstream file(TODO_FILE);
        for (int i = 0; i < taskCount; i++) {
            file << (completed[i] ? "1 " : "0 ") << tasks[i] << "\n";
        }
        file.close();
    }
public:
    TodoList() {
        loadTasks();
    }
    void addTask(const char* task) {
        if (taskCount < MAX_TASKS) {
            strncpy(tasks[taskCount], task, sizeof(tasks[0]) - 1);
            completed[taskCount] = false;
            taskCount++;
            saveTasks();
            cout << "Task added successfully.\n";
        } else {
            cout << "Cannot add more tasks. Maximum limit reached.\n";
        }
    }
    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks in the list.\n";
            return;
        }
        cout << "To-Do List:\n";
        cout << "-----------\n";
        for (int i = 0; i < taskCount; i++) {
            cout << (i + 1) << ". " << (completed[i] ? " DONE " : " ") << " " << tasks[i] << "\n";
        }
    }
    void markTaskComplete(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= taskCount) {
            completed[taskNumber - 1] = true;
            saveTasks();
            cout << "Task marked as complete.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
};
int main() {
    TodoList todo;
    int choice;
    char task[100];
    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin.getline(task, sizeof(task));
                todo.addTask(task);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                int taskNum;
                cout << "Enter task number to mark complete: ";
                cin >> taskNum;
                todo.markTaskComplete(taskNum);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}