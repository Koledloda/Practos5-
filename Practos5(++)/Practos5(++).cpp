#include <iostream>
#include <cmath>
#include <Windows.h>
#include <string>
#include <ctype.h>
#include <cctype>

class BankAccount
{
private:
	int accountNumber;
	double balance;
	double interestRate;

public:
	BankAccount(int accountNumber, double initializeBalance)
	{
		this->accountNumber = accountNumber;
		this->balance = initializeBalance;
		this->interestRate = 0;
	};

	void deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
	};

	bool withdraw(double amount)
	{
		if (amount > 0 && balance >= amount)
		{
			balance -= amount;
			return true;
		}
		else
		{
			std::cout << "Недостаточно денег на " << accountNumber << " балансе! Операция вывода была откланена!" << std::endl;
			return false;
		}
	};

	double getInterest() 
	{
		return this->balance * this->interestRate * 1/12;
	};

	void setInterestRate(double rate)
	{
		if (rate >= 0)
		{
			interestRate = rate;
		}
	};

	int getAccountNumber()
	{
		return this->accountNumber;
	};

	double getBalance()
	{
		return this->balance;
	}

	static bool transfer(BankAccount& from, BankAccount& to, double amount)
	{
		if (amount > 0 && from.withdraw(amount))
		{
			to.deposit(amount);
			return true;
		}
		return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");

	double initializeBalance1, initializeBalance2;

	std::string gg1;
	std::cout << "Введите баланс первого аккаунта: ";
	std::cin >> gg1;

	bool isBalanse1 = true;
	for (char c : gg1)
	{
		if (!isdigit(c))
		{
			isBalanse1 = false;
			break;
		}
	}

	if (!isBalanse1)
	{
		std::cout << "Некоректный ввод! Введите положительное число." << std::endl;
		return 0;
	}

	initializeBalance1 = std::stod(gg1);

	std::string gg2;
	std::cout << "Введите баланс второго аккаунта: ";
	std::cin >> gg2;

	bool isBalanse2 = true;
	for (char c : gg2)
	{
		if (!isdigit(c))
		{
			isBalanse2 = false;
			break;
		}
	}

	if (!isBalanse2)
	{
		std::cout << "Некоректный ввод! Введите положительное число." << std::endl;
		return 0;
	}

	initializeBalance2 = std::stod(gg2);

	BankAccount account1(1, initializeBalance1);
	BankAccount account2(2, initializeBalance2);

	std::cout << "Баланс 1 аккаунта: " << account1.getBalance() << std::endl;
	std::cout << "Баланс 2 аккаунта: " << account2.getBalance() << std::endl;

	account1.deposit(500.0);
	account2.withdraw(400.0);

	account1.setInterestRate(2);

	BankAccount::transfer(account1, account2, 300.0);

	std::cout << "Процент полученный с первого аккаунта: " << account1.getInterest() << std::endl;

	std::cout << "Баланс 1 аккаунта: " << account1.getBalance() << std::endl;
	std::cout << "Баланс 2 аккаунта: " << account2.getBalance() << std::endl;

	return 0;
};