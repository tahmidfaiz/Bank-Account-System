#pragma once

#include <fstream>
#include <iomanip> 
#include <iostream>
#include <string>
using namespace std;
#include "Client.h"
#include<vector>
class BankSystem
{
private:
	vector<string> log;
	Client oneClient;

public:
	int printMenu();
	void start();
	void addCheckingDialog();
	void RemoveCheckingDialog();
	void DepositCheckingDialog();
	void WithdrawCheckingDialog();
	void AddSavingDialog();
	void RemoveSavingDialog();
	void DepositSavingDialog();
	void TransferDialog();
	BankSystem(int i, string fn, string ln);
};


	

