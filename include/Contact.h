#pragma once

#include <string> 
#include <algorithm>

/**
 * @class Contact
 * @brief Represents a person's contact information 
 * 
 */
class Contact {
    public:
        /**
         * @brief Construct a new Contact object
         * 
         * @param name User's name
         * @param email User's email
         * @param phone_n User's phone number 
         */
        Contact(const std::string& name, const std::string& email, const std::string& phone_n);

        /**
         * @brief Get the name object
         * 
         * @return std::string 
         */
        std::string get_name() const; 

        /**
         * @brief Get the email object
         * 
         * @return std::string 
         */
        std::string get_email() const;

        /**
         * @brief Get the phone number object
         * 
         * @return std::string 
         */

        std::string get_phone_n() const; 

        /**
         * @brief Compares 2 strings for equality while being case insensitive
         * 
         * @param s1 First string to compare
         * @param s2 Second string to compare
         * @return true If the strings are equal
         * @return false If the strings are inequal
         */
        static bool compare(const std::string& s1, const std::string& s2); 

        /**
         * @brief Compares 2 strings for less-than while being case insensitive
         * 
         * @param s1 First string to compare
         * @param s2 Second string to compare
         * @return true If the first string is less than the second string 
         * @return false If the first string is not less than the second string 
         */
        static bool str_less(const std::string& s1, const std::string& s2); 

        bool operator<(const Contact& other) const; 
        
        bool operator>(const Contact& other) const;

        bool operator==(const Contact& other) const;

    private:
        /**
         * @brief The contact's full name
         * 
         */
        std::string name;

        /**
         * @brief The contact's email address
         * 
         */
        std::string email;

        /**
         * @brief The contact's phone number
         * 
         */
        std::string phone_n; 
};