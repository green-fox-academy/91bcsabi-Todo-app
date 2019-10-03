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

void listTasks() {
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

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printUsage();
    } else {
        if (std::string(argv[1]) == ("-l")) {
            listTasks();
        }
    }
    /*
}else if(std::string(argv[1]) == ("-a")){
    //add...
}else if(std::string(argv[1]) == ("-r")){
    //remove...
}else if(std::string(argv[1]) == ("c")){
    //completes tasks.txt
}
}
*/
    return 0;
}