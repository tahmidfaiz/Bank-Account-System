#pragma once
#include <fstream>
#include <iomanip> 
#include <iostream>
#include <string>
using namespace std;
#include "Account.h"

class CheckingAccount :public Account
{

public:
		float getBalance()const;
		void deposit(float amount);
		void withdraw(float amount);
		CheckingAccount();
		CheckingAccount(float amount);
	

};
