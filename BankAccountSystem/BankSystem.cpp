#include "BankSystem.h"

void BankSystem::addCheckingDialog()
{
	if (oneClient.checking != nullptr)
	{
		cout << "The client already has a checking account"<<endl;
		log.push_back("Invalid attempt to overwrite a checking account.");
		return;
	}
	else
	{
		float NewBalance;
		cout << "Enter the amount of you account's balance: ";
		cin >> NewBalance;
		if (NewBalance >= 0)
		{
			CheckingAccount* checking1 = new CheckingAccount(NewBalance);
			oneClient.checking = checking1;
			log.push_back("Checking account successfully created.");
			cout << "The checking balance is : " << oneClient.checking->getBalance() << endl;
		}
		else
			cout << "Input value cannot be negative" << endl;
	}
	cout << endl;
}
void BankSystem::RemoveCheckingDialog()
{
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account\n";
		cout << "wassup";
		log.push_back("Invalid attempt to remove a non - existing checking account");
	}
	else
	{
		delete oneClient.checking;
		oneClient.checking = nullptr;
		cout << "Checking Account Removed" << endl;
		log.push_back("Checking account successfully removed");
	}
	cout << endl;
}
void BankSystem::DepositCheckingDialog()
{
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account" << endl;
		log.push_back("Invalid attempt to deposit in a non-existing checking account.");
		return;
	}
	else {
		float input;
		cout << "Enter the amount of money you'd like to deposit: ";
		cin >> input;
		if (input >= 0) {
			oneClient.checking->deposit(input);
			string str = to_string(input);
			str = str.substr(0, str.find_last_not_of('0') + 1);
			str = "$" + str + " successfully deposited in checking account.";
			log.push_back(str);
			cout << "The checking balance is : " << oneClient.checking->getBalance() << endl;
		}
		else
			cout << "Input value cannot be negative" << endl;
	}
	cout << endl;
}
void BankSystem::WithdrawCheckingDialog()
{
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account" << endl;
		log.push_back("Invalid attempt to withdraw from a non-existing checking account.");
		return;
	}
	else
	{
		cout << "Enter the amount you'd like to withdraw: ";
		float input;
		cin >> input;
		if (input > 0) {
			oneClient.checking->withdraw(input);
			string str = to_string(input);
			str = str.substr(0, str.find_last_not_of('0') + 1);
			str = "$" + str + " successfully withdrawn from checking account.";
			log.push_back(str);
			cout << "The checking balance is : " << oneClient.checking->getBalance() << endl;
		}
		else
			cout << "Input value cannot be negative" << endl;
	}
	cout << endl;
}
void BankSystem::AddSavingDialog() {

	if (oneClient.saving != nullptr)
	{
		cout << "The client already has a saving account" << endl;
		log.push_back("Invalid attempt to overwrite a saving account.");
		return;
	}
	else
	{
		float savingBalance=-1,savingRate;
		cout << "Enter the your account's inital balance: ";
		cin >> savingBalance;
		cout << "Enter the your account's saving rate: ";
		cin >> savingRate;

		if (savingBalance >= 0 && savingRate >= 0)
		{
			SavingAccount* NewSaving = new SavingAccount(savingBalance, savingRate);
			oneClient.saving = NewSaving;
			cout << "The checking balance is : " << oneClient.saving->getBalance() << endl;
			cout << "The checking rate is : " << oneClient.saving->getSavingRate() << endl;
			log.push_back("Saving account successfully created.");
		}
		else
			cout << "Input value cannot be negative" << endl;
	}
	cout << endl;
}
void BankSystem::RemoveSavingDialog() {

	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account\n";
		
		log.push_back("Invalid attempt to remove a non - existing saving account");
	}
	else
	{
		delete oneClient.saving;
		oneClient.saving = nullptr;
		cout << "Saving Account Removed" << endl;
		log.push_back("saving account successfully removed");
	}
	cout << endl;
}
void BankSystem::DepositSavingDialog() {

	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account" << endl;
		log.push_back("Invalid attempt to deposit in a non-existing saving account.");
		return;
	}
	else {
		float input;
		cout << "Enter the amount of money you'd like to deposit to your saving account: ";
		cin >> input;
		

		if (input >= 0) {
			oneClient.saving->deposit(input);
			string str = to_string(input);
			str = str.substr(0, str.find_last_not_of('0') + 1);
			str = "$" + str + " successfully deposited in saving account.";
			log.push_back(str);
			cout << "Amount in saving account: " << oneClient.saving->getBalance() << endl;
		}
		else
			cout << "Input value cannot be negative" << endl;

	}
	cout << endl;
}
void BankSystem::TransferDialog()
{
	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account " << endl;
		log.push_back("Invalid attempt to use a non-existing saving account.");
		return;
	}
	else if(oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account " << endl;
			log.push_back("Invalid attempt to use a non-existing checking account.");
			return;
	}
	else
	{


		cout << "Enter amount you'd like to transfer from saving to checking: ";
		float transferAmount;
		cin >> transferAmount;
		float temp=oneClient.checking->getBalance(); //this variable checks if the transfer has been successfully

		oneClient.saving->transfer(*oneClient.checking, transferAmount);
		if (temp == oneClient.checking->getBalance())
		{
			string str = to_string(transferAmount);
			str = str.substr(0, str.find_last_not_of('0') + 1);
			str = "The transfer of $" + str + " was not succuessful";
			log.push_back(str);
		}
		else {

			
			if (transferAmount >= 0)
			{
				string str2 = to_string(transferAmount);
					str2 = str2.substr(0, str2.find_last_not_of('0') + 1);
					str2 = "$" + str2 + " successfully transferred from saving to checking account.";
					log.push_back(str2);
					cout << "Amount in checking account: " << oneClient.checking->getBalance() << endl;
					cout << "Amount in saving account: " << oneClient.saving->getBalance() << endl;
			}
			else
				cout << "Input value cannot be negative" << endl;
		}
	}
	cout << endl;
}
void BankSystem::start()
{
	cout << "The program has begun!\n" << endl;

	int i = 0;
	while (i != 9)
	{

		i = printMenu();
		if (i == 1)
			addCheckingDialog();
		else if (i == 2)
			RemoveCheckingDialog();
		else if (i == 3)
			DepositCheckingDialog();
		else if (i == 4)
			WithdrawCheckingDialog();
		else if (i == 5)
			AddSavingDialog();
		else if (i == 6)
			RemoveSavingDialog();
		else if (i == 7)
			DepositSavingDialog();
		else if (i == 8)
			TransferDialog();
		
		else if (i == 9)
		{
			cout << endl;
			for (unsigned int i = 0; i < log.size(); i++)
				cout << i+1<<". "<<log[i] << endl;
			cout << "End of Program" << endl;
		}
		
	}
}
BankSystem::BankSystem(int i, string fn, string ln) :oneClient(i, fn, ln)
{
	cout << "";
}
int BankSystem::printMenu()
{

	int i = 0;
	cout << "=============================\nMenu                        = \n=============================\n";
	cout<<"1. Add a Checking account\n2. Remove Checking account\n3. Deposit into Checking Account\n";
	cout << "4. Withdraw from Checking Account\n5. Add a Saving account\n6. Remove Saving account\n";
	cout << "7. Deposit into Saving account\n8. Transfer from Saving to Checking account\n9. Exit\n";
	cout << "\nEnter your choice: ";
	cin >> i;
	return i;
}
