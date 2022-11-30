

#include <iostream>
#include <string>
#include<fstream>



bool isPrime(int n) {
    bool primeNumber = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            primeNumber = 0;
        }
    }
    return primeNumber;
}

int prime_function(int n) {
    return pow(2.00, (n - 1.00));
}

int triangle_function(int n) {
    int tn = (n * (n + 1)) / 2;
    return tn;
}

long long int my_factorial(long long int n) {
    long long int i;
    long long int factorial = 1;
    for (i = 1; i <= n; i++) {
        factorial = factorial * i;

    }
    return factorial;
}

int num_divisors(int n) {
    int divisor = 0;
    int i = 1;
    for (; i <= sqrt(n); i++) {
        if (n % i == 0) {

            if (n / i == i)
                divisor = divisor + 1;

            else
                divisor = divisor + 2;
        }
    }
    return divisor;
}

long long int countLines(std::string name) {
    long long int count = 0;
    std::string line;
    std::ifstream myFile(name);

    if (myFile.is_open())
    {
        while (getline(myFile, line))
            count++;

        std::cout << "There are " << count << " lines in " << name << std::endl;
    }
    myFile.close();
    return 0;
}

using namespace std;

int main()

{   /*
    for (int c = 1; c <= 50; c++) {
        cout << c << " has "<< num_divisors(c) << " divisors. \n";
    }
    */

    /*
    string fileName;
    cin >> fileName;
    cout << countLines(fileName);
    */

    /*
    cout << num_divisors(12);
    */

}

