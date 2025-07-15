#include <iostream>
#include <ctime> 
#include <iomanip>
#include "AddressBook.h"

// Get the formatted date as monthName day year - time 
std::string formatted_date(); 

// Display a program entry message
void greeting(); 

// Prompt the user and return an integer
template <typename T> 
T prompt(const std::string& prompt);


// Get the user's desired action
// 0. Invalid input 
// 1. Add an address
// 2. Search an address
int get_action(); 

// Pretty print Contact information to the console 
void print_contact(Contact* contact); 
void add_contact(AddressBook* address_book);

void search_contact(AddressBook* address_book); 

// Execute program logic as long as program is active
void program_loop(AddressBook* address_book); 

// Determines if program runs next loop 
bool program_flag = true; 

// Namespace to hold console formatting output variables 
namespace UI {
    const short BOX_WIDTH = 50; 
    const std::string BORDER(32, '='); 
    const std::string BOX_BORDER(BOX_WIDTH, '-'); 
}

int main() {
    greeting(); 

    AddressBook* address_book = new AddressBook(); 

    while (program_flag) {
        program_loop(address_book); 
    }

    std::cout << "Press any key to exit..." << std::endl;
    int x;
    std::cin >> x; 

    return 0; 
}

std::string formatted_date() {
    std::time_t now = std::time(0);
    std::tm* ltm = std::localtime(&now);

    // Feed into string output stream
    std::ostringstream oss;
    oss << std::put_time(ltm, "%b %d %Y - %H:%M:%S");

    // Return buffer as string 
    return oss.str();
}

void greeting() {
    std::cout << UI::BORDER << std::endl;
    std::cout << "Welcome to the Address Book Program!" << std::endl; 
    std::cout << "Author: Rohan Brar" << std::endl;
    std::cout << formatted_date() << std::endl;  
    std::cout << UI::BORDER << std::endl; 
}

int prompt_int(const std::string& prompt) {
    std::cout << UI::BOX_BORDER << std::endl;
    std::cout << prompt << std::endl;

    int input;
    std::cin >> input; 

    return input; 
}


template <typename T>
T prompt(const std::string& prompt) {
    std::cout << UI::BOX_BORDER << std::endl;
    std::cout << prompt << std::endl;

    T input;
    std::cin >> input;

    return input; 
}

template<>
std::string prompt<std::string>(const std::string& prompt) {
    std::cout << UI::BOX_BORDER << std::endl;
    std::cout << prompt << std::endl;

    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input; 
}



int get_action() {
    int action = prompt<int>("Would you like to [1] Add a contact, [2] Search a contact, [3] Exit"); 
    if (action > 3 || action < 1) {
        return 0; 
    }
    return action; 
}


void print_contact(Contact* contact) {
    std::cout << UI::BOX_BORDER << std::endl; 
    
    // Use lambda function to print each line easier, calculate manual padding for alignment 
    auto print_line = [](const std::string& label, const std::string& value) {
        std::string full_text = label + value; 
        int padding = UI::BOX_WIDTH - 4 -  full_text.length(); // 4 is 2 for "| " and 2 for " |"
        std::cout << "| " << full_text << std::string(padding, ' ') << " |" << std::endl;
    };

    print_line("Full name: ", contact->get_name());
    print_line("Email: ", contact->get_email());
    print_line("Phone #: ", contact->get_phone_n()); 

    std::cout << UI::BOX_BORDER << std::endl;
 }

void add_contact(AddressBook* address_book) {
    // Get the contact's information
    // 1. Full Name
    // 2. Email
    // 3. Phone Number

    std::string name = prompt<std::string>("Please enter the contact's full name: "); 
    std::string email = prompt<std::string>("Please enter the contact's email address: "); 
    std::string phone_n = prompt<std::string>("Please enter the contact's phone number: ");

    Contact contact(name, email, phone_n); 

    address_book->insert(contact); 

    std::cout << "Contact has been added!" << std::endl;
}

void search_contact(AddressBook* address_book) {
    // Search by full name

    std::string name = prompt<std::string>("Please enter the contact's name you would like to search: "); 

    Contact* contact = address_book->search(name); 

    if (!contact) {
        std::cout << "Sorry, we couldn't find a contact by that name!" << std::endl; 
        return; 
    }

    std::cout << std::endl;
    std::cout << "Contact Information: " << std::endl;
 
    print_contact(contact); 
    
    int next = prompt<int>("Would you like to [1] Remove this address, [2] Menu"); 

    while (next < 1 || next > 2) {
        std::cout << "Invalid input, please try again!" << std::endl;

        next = prompt<int>("Would you like to [1] Remove this address, [2] Menu");
    }

    if (next == 1) { // Remove the contact

        try {
            address_book->remove(*contact);
        } catch(const std::invalid_argument& e) {
            std::cout << "Could not find that contact to remove!" << std::endl;
            return; 
        } 

        std::cout << "Removed contact!" << std::endl; 
    } // Continue on, but we don't need to do anything it will be automatic

}

void program_loop(AddressBook* address_book) {
    int action = get_action(); 

    // Reprompt for bad input 
    while (action == 0) {
        std::cout << "Invalid input, please enter a valid response!" << std::endl;
        action = get_action(); 
    }

    switch (action) {
        case 1: { // Add address
            add_contact(address_book);
            break; 
        }
        case 2: { // Search address
            search_contact(address_book);
            break; 
        }
        case 3: { // Exit program 
            program_flag = false; 
            return; 
        }
    }
}

