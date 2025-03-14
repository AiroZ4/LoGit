// Includes
#include <iostream>
#include <filesystem>
#include <string>


// Variables
std::filesystem::path projects_path = "Test-Projects-Folder";
std::string folder_name;


// Functions
void create_folder(){

    std::filesystem::path full_path = "Test-Projects-Folder/" + folder_name;

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

int main() {
    std::cout << "Enter the name of the folder to create: ";
    std::cin >> folder_name;
    projects_path = std::filesystem::path(folder_name);

    // Create folder
    create_folder();


    std::cout << "Folder creation process completed!" << std::endl;
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.ignore();


    return 0;
}