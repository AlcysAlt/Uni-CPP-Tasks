#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
	string address;
	string name;
	int sortCode;
	float money;


public:
	float withdraw();
	float deposit();

};

class ATM
{
private:
	string address;
	string name;
	int atmNo;



public:
	float withdraw();
	float checkBalance();
	void transactions();
};
class Card
{
private:
	int pin;
	int cardNumber;
	float expDate;
	string cardOwner;

public:
	float pay();
};

class Account
{
public:
	int accountNumber;
	string ownerName;
	float balance;

public:
	bool hasCredit();
	void createAccount();
	void closeAccount();
	void transactions();
	void checkBalance();

};
class Customer
{
private:
	string name;
	int contactNumber;

public:
	void useCard();


};

class Credit : public Account
{

public:
	void payBills();

};

class Savings : public Account
{

public:
	void saveMoney();

};

class Debit : public Account
{


public:
	void debitBalance();

};
int main()
{	
	Savings savings1;
    std::cout << "Hello World!\n";
}

