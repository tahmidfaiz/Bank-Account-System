#include "SavingAccount.h"
#include "Account.h"

	float SavingAccount::getBalance()const { return balance; }
	void SavingAccount::deposit(float amount)
	{
		balance = getBalance() + amount;
	}

	void SavingAccount::setSavingRate(float rate)
	{
		savingRate = rate;
	}
	float SavingAccount::getSavingRate()const
	{
		return savingRate;
	}
	void SavingAccount::transfer(CheckingAccount& checkingAcc, float amount)
	{

		 try{
			if (balance >= amount) {
				balance = balance - amount;
				checkingAcc.deposit(amount);
			}
			else
				throw string("It cannot withdraw an amount greater than the balance. No changes were done to the balance in the Saving Account.");
		}
		catch (string error) {
			cout << "\n" << error << endl;
		}
	}
	SavingAccount::SavingAccount(float amount, float rate)
	{
		deposit(amount);
		setSavingRate(rate);
	}
	SavingAccount::SavingAccount()
	{
		deposit(0);
		setSavingRate(0);
	}
