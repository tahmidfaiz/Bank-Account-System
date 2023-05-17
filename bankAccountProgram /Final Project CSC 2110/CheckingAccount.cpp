#pragma once
#include "Account.h"
#include "CheckingAccount.h"


	float CheckingAccount::getBalance()const { return balance; }
	void CheckingAccount::deposit(float amount)
	{
		balance = getBalance() + amount;
	}
	void CheckingAccount::withdraw(float amount)
	{
		try {
			if (amount < getBalance())
			{
				balance = getBalance() - amount;
			}
			else
				throw string("It cannot withdraw an amount greater than the balance. No changes were done to the balance.");
		}
		catch (string error){
			cout << "\n"<<error << endl;
		}
	}
	CheckingAccount::CheckingAccount(float amount)
	{
		balance = amount;
	}
	CheckingAccount::CheckingAccount() {
		
			balance = 0;
		
	}
