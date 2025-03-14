// Includes
#include <iostream>
#include <filesystem>
#include <string>


// Variables
std::filesystem::path projects_path = "Test-Projects-Folder";
std::string folder_name;
std::filesystem::path full_path;
std::string output;


// Functions
void create_folder(){
    std::cout << "Enter the name of the folder to create: ";
    std::cin >> folder_name;
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

void delete_folder(){
    std::cout << "Enter the folder you want to delete: ";
    std::cin >> folder_name;
    full_path = projects_path / folder_name;

    if (std::filesystem::exists(full_path)){
        std::filesystem::remove(full_path);
    }
    else {
        std::cout << "The file you are trying to delete does not exist." << std::endl;
    }
}

int main() {

    std::cout << "Would you like to Create or Delete a folder? (C, D): ";
    std::cin >> output;

    if (output == "c" || output == "C"){
        // Create folder
        create_folder();


        std::cout << "Folder creation process completed!" << std::endl;
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.ignore();
    }
    else if (output == "d" || output == "D"){
        delete_folder();

        std::cout << "Folder Deletion Complete!" << std::endl;
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.ignore();
    }

    return 0;
}