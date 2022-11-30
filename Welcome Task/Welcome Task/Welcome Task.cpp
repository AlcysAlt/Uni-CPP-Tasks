// Welcome Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;



int main()
{
    //Decalring Variables
    char user_name[600]; // name is stored as an array with a maximum of 600 characters

    //everything else is stored as integers
    int accountNo;
    int user_age;
    int age;
    int lastDigit;
    int vowels;
    int pin;
    int reversed_age;
    //Initializing Variables
    vowels = 0;
    accountNo = 0;
    user_age = 0;
    age = 0;
    lastDigit = 0;
    vowels = 0;
    pin = 0;
    reversed_age = 0;
    //Welcomes the user and asks for their name
    std::cout << "Welcome to the USW Cyber App\n";
    std::cout << "What's your name?\n";
    //Takes user input and uses it to calculate the amount of vowels, it goes through every character in the user_name array and increases the value of int vowels if comes across a vowel
    std::cin.getline(user_name, 600);

    ////Source for the vowel counting algorithm: https://www.programiz.com/cpp-programming/examples/vowel-consonant-frequency-string
    for (int i = 0; user_name[i] != '\0'; ++i)
    {
        if (user_name[i] == 'a' || user_name[i] == 'e' || user_name[i] == 'i' || user_name[i] == 'o' || user_name[i] == 'u' || user_name[i] == 'A' || user_name[i] == 'E' || user_name[i] == 'I' || user_name[i] == 'O' || user_name[i] == 'U')
        {
            ++vowels;
        }

    }
    //Asks user for age and account number
    std::cout << "What's your age?\n";
    std::cin >> user_age;
    std::cout << "What's your account number?\n";
    std::cin >> accountNo;
    std::cout << "Generating pin...\n";
    //Makes a copy of the age number to be used in the reversing algorithm
    age = user_age;

    //Algorithm for reversing the age number, source: https://medium.com/@ManBearPigCode/how-to-reverse-a-number-mathematically-97c556626ec6
    while (user_age > 0) {
        lastDigit = user_age % 10;
        
        reversed_age = (reversed_age * 10) + lastDigit;

        user_age = user_age / 10;
        

    }
    //Calculates the pin using the number of vowels and the reversed age
    pin = vowels * reversed_age;
    //This is a series of checks that make sure the number is 4 digits, if it's too small then the number is increased and if the number is too high, the number is decreased. 
    //There are less checks for the larger numbers as the size of the number that can be generated using this method isn't as big (unless the person has over 10000 vowels in their name)
    if (pin < 10) {
        pin = pin * 1000;
    }
    else if (9 < pin < 100) {
        pin = pin * 100;

    }
    else if (99 < pin < 1000) {
        pin = pin * 10;
    }
    else if (9999 < pin < 100000) {
        pin = pin / 10;
    }
    else if (99999 < pin < 1000000) {
        pin = pin / 100;

    }
    //This outputs the user's name and account number alongside the generated pin number.
    std::cout << "Hi " << user_name << "." << "Your account " << accountNo << " has been created. Your unique pin number is " << pin << "\n";
}
        

    

