#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

/*
* The bank must receive 5% of each money inflow on these client accounts
* The accounts must never have two identical IDs
* The attributes of the structures must not be modifiable from the outside
* The bank must be able to create, delete and modify the accounts of these customers
* The bank must be able to give a loan to a customer, within the limits of its funds
* It must be impossible to add money to a client account without going through the bank
* If it makes sense, the creation of a Getter and a Setter is mandatory. Getter(s) by copy will not be accepted
* If it makes sense, the creation of a const Getter is mandatory. const Getter(s) by copy will not be accepted
*/
struct Bank
{

	struct Account
	{
		Account(int value, int id);
		unsigned int getId() const;
		unsigned int getValue() const;
		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);

		private:
		friend class Bank;	
		void addValue(int value);
		int id;
		int value;
	};

	Bank::Account const &operator[](int val);

	Bank();
	void set_liquidity(int liq);
	void deposit(unsigned int id, int value);
	int addAccount();
	void addLiquidity(int value);
	void removeLiquidity(int value);
	void AcountBalance(unsigned int id);
	int requestLoan(unsigned int id, unsigned int value);
	void BankBalance();
	void accountRemove(unsigned int id);
	Account *getAccount(unsigned int id);

	class IndexNotFoundException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class IncorrectValueException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughFundsException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
private:

	int liquidity;
	std::vector<Account > clientAccounts;
	static unsigned int available_id;
};

/* C++98 Doenst have lambdas but we can do the equivalent with a Functor
 * Functors are empty functions that define the operator(). They act like a function
 * the can also hold state.
 */
struct FindAccountById {
    unsigned int target_id;
    FindAccountById(unsigned int id) : target_id(id) {}
    bool operator()(const Bank::Account& acc) const {
        return acc.getId() == target_id;
    }
};
