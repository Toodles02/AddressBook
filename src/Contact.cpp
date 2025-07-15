#include "Contact.h"

Contact::Contact(const std::string& name, const std::string& email, const std::string& phone_n) : 
name(name), email(email), phone_n(phone_n) {

}


std::string Contact::get_name() const {
    return name;
}

std::string Contact::get_email() const {
    return email; 
}

std::string Contact::get_phone_n() const {
    return phone_n; 
}

bool Contact::compare(const std::string& s1, const std::string& s2) {
    // Compare the easiest scenario to determine strings aren't equal
    if (s1.size() != s2.size()) return false;

    // size_t is an unsigned int used to represent size/index of list/array/vectors etc
    for (size_t i = 0; i < s1.size(); ++i) { // Compare each character and cast as unsigned char
        if (std::tolower(static_cast<unsigned char>(s1[i])) !=
            std::tolower(static_cast<unsigned char>(s2[i])))
            return false; 
    }
    return true; 
}

bool Contact::str_less(const std::string& s1, const std::string& s2) {
    size_t len = std::min(s1.size(), s2.size()); 

    for (size_t i = 0; i < len; ++i) {
        unsigned char c1 = std::tolower(static_cast<unsigned char>(s1[i])); 
        unsigned char c2 = std::tolower(static_cast<unsigned char>(s2[i]));

        if (c1 < c2) return true;
        if (c1 > c2) return false;  
    }

    return s1.size() < s2.size(); 
}

bool Contact::operator<(const Contact& other) const {
    return str_less(name, other.name); 
}

bool Contact::operator>(const Contact& other) const {
    return str_less(other.name, name); 
}

bool Contact::operator==(const Contact& other) const {
    return compare(name, other.name) && compare(email, other.email) && phone_n == other.phone_n;
}