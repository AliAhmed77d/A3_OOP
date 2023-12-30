/*
 Author:Ali Ahmed
 ID:20220701
 Section:s15
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Process {
public:
    Process(const std::string& name, int pid, int memoryUsage)
            : name(name), pid(pid), memoryUsage(memoryUsage) {}

    // Getter functions
    std::string getName() const { return name; }
    int getPID() const { return pid; }
    int getMemoryUsage() const { return memoryUsage; }

private:
    std::string name;
    int pid;
    int memoryUsage;
};

class TaskManager {
public:
    void fillProcessList();
    void displayByName() const;
    void displayByPID() const;
    void displayByMemoryUsage() const;

private:
    std::vector<Process> processList;

    static bool compareByName(const Process& a, const Process& b);
    static bool compareByPID(const Process& a, const Process& b);
    static bool compareByMemoryUsage(const Process& a, const Process& b);
};

void TaskManager::fillProcessList() {
    processList.push_back(Process("A", 101, 256));
    processList.push_back(Process("B", 102, 512));
    processList.push_back(Process("C", 103, 128));
}

void TaskManager::displayByName() const {
    std::vector<Process> sortedList = processList;
    std::sort(sortedList.begin(), sortedList.end(), compareByName);

    // Display the sorted list
    for (const auto& process : sortedList) {
        std::cout << "Name: " << process.getName() << " PID: " << process.getPID()
                  << " Memory Usage: " << process.getMemoryUsage() << " KB\n";
    }
}

void TaskManager::displayByPID() const {
    std::vector<Process> sortedList = processList;
    std::sort(sortedList.begin(), sortedList.end(), compareByPID);

    // Display the sorted list
    for (const auto& process : sortedList) {
        std::cout << "Name: " << process.getName() << " PID: " << process.getPID()
                  << " Memory Usage: " << process.getMemoryUsage() << " KB\n";
    }
}

void TaskManager::displayByMemoryUsage() const {
    std::vector<Process> sortedList = processList;
    std::sort(sortedList.begin(), sortedList.end(), compareByMemoryUsage);

    // Display the sorted list
    for (const auto& process : sortedList) {
        std::cout << "Name: " << process.getName() << " PID: " << process.getPID()
                  << " Memory Usage: " << process.getMemoryUsage() << " KB\n";
    }
}

bool TaskManager::compareByName(const Process& a, const Process& b) {
    return a.getName() < b.getName();
}

bool TaskManager::compareByPID(const Process& a, const Process& b) {
    return a.getPID() < b.getPID();
}

bool TaskManager::compareByMemoryUsage(const Process& a, const Process& b) {
    return a.getMemoryUsage() < b.getMemoryUsage();
}

int main() {
    TaskManager taskManager;
    taskManager.fillProcessList();

    std::cout << "Processes sorted by Name:\n";
    taskManager.displayByName();

    std::cout << "\nProcesses sorted by PID:\n";
    taskManager.displayByPID();

    std::cout << "\nProcesses sorted by Memory Usage:\n";
    taskManager.displayByMemoryUsage();

    return 0;
}
