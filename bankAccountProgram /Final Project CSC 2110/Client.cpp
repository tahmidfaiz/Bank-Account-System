#include "Client.h"
	void Client::setId(int i)
	{
		id = i;
	}
	int Client::getId()const
	{
		return id;
	}
	void Client::setName(string fn, string ln)
	{
		firstName = fn;
		lastName = ln;
	}
	string Client::getFirstName()
	{
		return firstName;
	}
	string Client::getLastName()
	{
		return lastName;
	}
	Client::Client(int i, string fn, string ln)
	{
		setId(i);
		setName(fn, ln);
		
		checking = nullptr;
		saving = nullptr;
		
	}
	Client::Client()
	{
		setId(0);
		setName("", "");
		checking = nullptr;
		saving = nullptr;
		
	
	}