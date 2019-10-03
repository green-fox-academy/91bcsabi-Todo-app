#include <iostream>
#include <string>
#include <fstream>

void printUsage() {
    std::cout << "$ todo\n" << std::endl;
    std::cout << "Command Line Todo application" << std::endl;
    std::cout << "=============================\n" << std::endl;
    std::cout << "Command line arguments:" << std::endl;
    std::cout << "      -l   Lists all the tasks.txt" << std::endl;
    std::cout << "      -a   Adds a new task" << std::endl;
    std::cout << "      -r   Removes an task" << std::endl;
    std::cout << "      -c   Completes an task" << std::endl;
}


void listTasks(){
    std::ifstream myFile;
    myFile.open("tasks.txt");
    std::string text;
    int count = 0;
    if (myFile.is_open()) {
        while (getline(myFile, text)) {
            count++;
        std::cout << text << std::endl;
        }
        myFile.close();
    }
}

void addTask(std::string newTask){
    std::ofstream myFile;
    myFile.open("tasks.txt", std::ios::app);
    myFile << "\n" + newTask;
    myFile.close();
}

void removeTasks(int position){
    std::ifstream myFile;
    myFile.open("tasks.txt");
    position = line.find(deleteLine);
    if (position != string::npos) {
        line.replace(line.find(deleteLine), deleteLine.length(), "");
    }
    myFile.close();
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printUsage();
    }else if (std::string(argv[1]) == ("-l")) {
        listTasks();
    }else if(std::string(argv[1]) == ("-a")){
        if (argc == 2){
                std::cout << "not written anything after -a .Please write something" << std::endl;
        }else{
            addTask(argv[2]);
            }
    }else if(std::string(argv[1]) == ("-r")){
        if (argc == 2) {
            std::cout << "not written anything after -r .Please write which line you want to remove" << std::endl;
        }else{
            removeTasks(argv[2]);
        }
    }
    return 0;
}