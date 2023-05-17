#pragma once

#include <fstream>
#include <iomanip> 
#include <iostream>
#include <string>
using namespace std;
#include "SavingAccount.h"
#include "CheckingAccount.h"

class Client
{
private:
	int id;
	string firstName;
	string lastName;
public:
	CheckingAccount* checking;
	SavingAccount* saving;
	void setId(int i);
	
	int getId()const;
	
	void setName(string fn, string ln);
	
	string getFirstName();
	
	string getLastName();
	
	Client(int i, string fn, string ln);
	Client();
	

};
