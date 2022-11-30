// Welcome Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
using namespace std;
//Algorithm for counting the number of digits in the pin, used in another algorithm to make any pin 4 digits.
// Source: https://www.tutorialspoint.com/determining-how-many-digits-there-are-in-an-integer-in-cplusplus#:~:text=The%20formula%20will%20be%20integer,to%20get%20number%20of%20digits
int count_digit(int number) {
    return int(log10(number) + 1);
}


int main()
{
    //Decalring Variables
    char user_name[600]; // name is stored as an array with a maximum of 600 characters
    char username_FA[300];
    char password_FA[300];
    //This is for the loop that check whether the user entered their pin and account information correctly
    bool login;
    //This value is for checking whether the loop for password strength should run or stop, it's stored as a boolean value (true or false)
    bool askForNewPass;
    //everything else is stored as integers
    int accountNo;
    int user_age;
    int age;
    int lastDigit;
    int vowels;
    int pin;
    int reversed_age;
    int numberOfDigits;
    int upperCase;
    int symbols;
    int lowerCase;
    int numbers;
    int length;
    int i;
    int accountNo_check;
    int pin_check;

    //Initializing Variables
    vowels = 0;
    accountNo = 0;
    user_age = 0;
    age = 0;
    lastDigit = 0;
    vowels = 0;
    reversed_age = 0;
    upperCase = 0;
    symbols = 0;
    lowerCase = 0;
    numbers = 0;
    askForNewPass = true;
    login = true;
    //Welcomes the user and asks for their name
    std::cout << "Welcome to the USW Cyber App\n";
    std::cout << "What's your name?\n";
    std::cin.getline(user_name, 600);

    //Takes user input and uses it to calculate the amount of vowels, it goes through every character in the user_name array and increases the value of int vowels if comes across a vowel
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
    numberOfDigits = count_digit(pin);
    //This is a series of checks that make sure the number is 4 digits, if it's too small then the number is increased and if the number is too high, the number is decreased.
    if (numberOfDigits == 1) {
        pin = pin * 1000;

    }
    else if (numberOfDigits == 2) {
        pin = pin * 100;
    }
    else if (numberOfDigits == 3) {
        pin = pin * 10;
    }
    else if (numberOfDigits == 4) {
        pin = pin;
    }
    else if (numberOfDigits == 5) {
        pin = pin / 10;

    }
    else if (numberOfDigits == 6) {
        pin = pin / 100;
    }
    else if (numberOfDigits == 7) {
        pin = pin / 1000;
    }

    //This outputs the user's name and account number alongside the generated pin number.
    std::cout << "Hi " << user_name << "." << " Your account " << accountNo << " has been created. Your unique pin number is " << pin << "\n";
    while (login == true){


        std::cout << "Please enter your account number\n";
        std::cin >> accountNo_check;
        std::cout << "Please enter your pin\n";
        std::cin >> pin_check;
        if ((accountNo_check == accountNo) && (pin_check == pin)) {
            login = false;
        }
        else {
            cout << "Incorrect pin and account number. Please try again\n";
            login = true;
        }
    }

    std::cout << "Please enter a username: \n";
    std::cin >> username_FA;

    while (askForNewPass == true) {

        std::cout << "Here are the requirements for your password: \n" << "Minimum length of 18 characters \n" << "At least 4 Upper Case Letters\n" << "At least 3 numbers \n" << "At least 3 symbols\n";
        std::cout << "Please enter a password: \n";
        cin >> ws;
        std::cin.getline(password_FA, 600);

        //This algorithm loops through the password_FA array and counts each character as either an uppercase letter, lowercase letter, number, or symbol.
        //Since the computer sees the characters in ascii, each character has an assigned number so when you tell the program to count every number beteen "A" and "G", it's going to count from ascii 65 to 71
        //I used that to make the program's character counting more accurate and more efficient as less code is used.

        for (i = 0; password_FA[i] != '\0'; i++) {
            if (password_FA[i] >= 'A' && password_FA[i] <= 'Z')
                upperCase++;
            else if (password_FA[i] >= 'a' && password_FA[i] <= 'z')
                lowerCase++;
            else if (password_FA[i] >= '0' && password_FA[i] <= '9')
                numbers++;
            else if (password_FA[i] != ' ')
                symbols++;
        }
        length = lowerCase + upperCase + numbers + symbols;
        //These if statements make sure that the user can only proceed after entering a strong enough password
        if (length >= 18) {
            askForNewPass = false;
            if (upperCase >= 4) {

                askForNewPass = false;

                if (numbers >= 3) {

                    askForNewPass = false;

                    if (symbols >= 3) {

                        askForNewPass = false;

                        cout << "Password strength: Strong\n" << "Password Accepted, you can now exit the program\n";

                        ofstream user_details("2FA_users.txt");
                        user_details << user_name << accountNo << username_FA << password_FA << pin;
                        user_details.close();
                    }

                    else if (symbols >= 2) {
                        cout << "Password Strength: Medium \n" << "Password doesn't contain enough symbols (minimum 3 symbols)";
                        askForNewPass = true;
                    }
                    else if (symbols >= 1) {
                        cout << "Password Strength: Weak \n" << "Password doesn't contain enough symbols (minimum 3 symbols)";
                        askForNewPass = true;

                    }
                    else if (symbols >= 0) {
                        cout << "Password Strength: Invalid \n" << "Password doesn't contain enough symbols (minimum 3 symbols)";
                        askForNewPass = true;
                    }

                }
                else if (numbers >= 2) {
                    cout << "Password Strength: Medium \n" << "Password doesn't contain enough numbers (minimum 3 numbers)";
                    askForNewPass = true;
                }
                else if (numbers >= 1) {
                    cout << "Password Strength: Weak \n" << "Password doesn't contain enough numbers (minimum 3 numbers)";
                    askForNewPass = true;

                }
                else if (numbers >= 0) {
                    cout << "Password Strength: Invalid \n" << "Password doesn't contain enough numbers (minimum 3 numbers)";
                    askForNewPass = true;

                }

              }
            else if (upperCase >= 2) {
                cout << "Password Strength: Medium \n" << "Password doesn't contain enough upper case letters (minimum 4 upper case letters)";
                askForNewPass = true;

            }
            else if (upperCase >= 1) {
                cout << "Password Strength: Weak \n" << "Password doesn't contain enough upper case letters (minimum 4 upper case letters)";
                askForNewPass = true;
            }
            else if (upperCase >= 0) {
                cout << "Password Strength: Invalid \n" << "Password doesn't contain enough upper case letters (minimum 4 upper case letters)";
                askForNewPass = true;
            }
            }
            else if (length >= 16) {
                cout << "Password Strength: Medium \n" << "Password too short (minimum 18 characters)";
                askForNewPass = true;
            }
            else if (length >= 14) {
                cout << "Password Strength: Weak \n" << "Password too short (minimum 18 characters)";
                askForNewPass = true;
            }
            else if (length < 14) {
                cout << "Password Strength: Invalid \n" << "Password too short (minimum 18 characters)";
                askForNewPass = true;
            }







        
    }
}




