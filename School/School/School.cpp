#include <iostream>
#include <string>
using namespace std;
class Tutorials
{
private:
	string topic;
	string dateSet;

public:
	void frades();
	string feedback();

};

class Module
{
private:
	string subjectCode;
	string title;

public:
	void releaseMaterial();
	void submitMaterial();


};

class Assessment
{
private:
	string topic;
	string assessmentInfo;

public:
	void grades();
	string feedback();
	void upload();

};

class Moderator
{
private:
	string name;
	float age;
	float staffNo;

public:
	string chat();
	void talk();

};

class Student
{
private:
	string name;
	float age;
	float enrollmentNo;

public:
	string chat();
	void talk();

};

class Session
{
private:
	char audio;
	char video;
	string code;
	string title;
	string chat;

public:
	void recording();
	void send_msg();
	void recordSession();
	void classRegister();

};

int main()
{

	std::cout << "Hello World!\n";
}

