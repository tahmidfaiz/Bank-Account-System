#pragma once
#include <fstream>
#include <iomanip> 
#include <iostream>
#include <string>
using namespace std;
#include "Account.h"
#include "CheckingAccount.h"

class SavingAccount : public Account
{
private:
	float savingRate;
public:
	float getBalance()const;
	void deposit(float amount);
	void setSavingRate(float rate);
	float getSavingRate()const;
	void transfer(CheckingAccount& checkingAcc, float amount);
	SavingAccount(float amount, float rate);
	SavingAccount();
	
};
