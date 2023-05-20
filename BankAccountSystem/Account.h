#pragma once
#include <fstream>
#include <iomanip> 
#include <iostream>
#include <string>
using namespace std;


class Account
{
protected:
	float balance = 0;
public:
	virtual float getBalance()const = 0;
	virtual void deposit(float amount) = 0;

};
