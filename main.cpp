// Includes
#include <iostream>
#include <filesystem>
#include <string>


// Variables
std::filesystem::path projects_path = "Test-Projects-Folder";
std::filesystem::path full_path;
std::string output;

// Commands
std::string create_command = "cdir";
std::string delete_command = "ddir";


// Functions
void create_folder(std::string folder_name){
    full_path = projects_path / folder_name;

    std::cout << full_path << std::endl;

    // Check if Dir already exists
    if (std::filesystem::exists(full_path)){
        std::cout << "Your project already exists." << std::endl;
    }
    else if (!std::filesystem::exists(full_path)){
        std::filesystem::create_directory(full_path);
        std::cout << "Dir created." << std::endl;
    }
    else {
        std::cout << "Something Went Wrong." << std::endl;
    }   
}

void delete_folder(std::string folder_name){
    full_path = projects_path / folder_name;

    if (std::filesystem::exists(full_path)){
        std::filesystem::remove(full_path);
        std::cout << "Directory: " << full_path << std::endl;
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

    return 0;
}