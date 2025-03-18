// Includes
#include <cctype>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <pthread.h>
#include <string>


// Variables
std::filesystem::path projects_path = "RemoteFolder";
std::filesystem::path Local_path = "LocalFolder";
std::filesystem::path full_path;
std::string output;

// Commands
std::string create_command = "new";
std::string delete_command = "del";
std::string push_command = "push";
std::string pull_command = "pull";



// Functions
void create_folder(std::string folder_name){

    // Check if Dir already exists
    if (std::filesystem::exists(folder_name)){
        std::cout << "Your project already exists." << std::endl;
    }
    else if (!std::filesystem::exists(folder_name)){
        std::filesystem::create_directory(folder_name);

        std::filesystem::create_directory(folder_name + "/.logit");
        std::ofstream file(folder_name + "/.logit/data.csv");

        std::cout << "Project created successfully." << std::endl;
    }
    else {
        std::cout << "Something Went Wrong." << std::endl;
    }
}

void delete_folder(std::string folder_name){
    std::string confirm;
    if (std::filesystem::exists(folder_name)){
        std::cout << "Are you sure you would like to delete (" << folder_name << ") for ever (Y, N):";
        std::cin >> confirm;
        if (confirm == "y" || confirm == "Y"){
            std::filesystem::remove_all(folder_name);
            std::cout << "Directory: " << "/" << folder_name << " has been deleted!" << std::endl;
        }
        else{
            exit(1);
        }

    }
    else {
        std::cout << "The file you are trying to delete does not exist." << std::endl;
    }
}

// Main function
int main(int argc, char *argv[]) {

    if (argc < 2){
        std::cout << "Usage: logit <command> [args]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == create_command){
        if (argc < 3){
            std::cout << "Missing folder name.";
            return 1;
        }

        create_folder(argv[2]);
    }
    else if (command == delete_command){
        if (argc < 3){
            std::cout << "Missing folder name.";
            return 1;
        }

        delete_folder(argv[2]);
    }
    else if (command == push_command){
        std::cout << "Currently pushing directory: " << std::filesystem::current_path() << std::endl;
    }
    else if (command == pull_command){

    }
    else if (command == "help"){
        std::cout << "\nUsage: logit <command> [args]\n";
        std::cout << "Commands:\n\n";
        std::cout << "  create <folder_name>\n\n";
        std::cout << "  delete <folder_name>\n\n";
        std::cout << "  push <folder_name>\n\n";
        std::cout << "  pull <folder_name>\n\n";
    }

    return 0;
}
