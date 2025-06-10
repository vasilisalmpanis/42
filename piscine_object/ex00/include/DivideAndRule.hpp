#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

struct Account
{
	Account(int value, int id);
	void addValue(int value);
	unsigned int getId() const;
	unsigned int getValue() const;
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);

	private:
		int id;
		int value;
};

/* C++98 Doenst have lambdas but we can do the equivalent with a Functor
 * Functors are empty functions that define the operator(). They act like a function
 * the can also hold state.
 */
struct FindAccountById {
    unsigned int target_id;
    FindAccountById(unsigned int id) : target_id(id) {}
    bool operator()(const Account& acc) const {
        return acc.getId() == target_id;
    }
};

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
	Bank();
	void set_liquidity(int liq);
	void deposit(unsigned int id, int value);
	int addAccount();
	void addLiquidity(int value);
	void removeLiquidity(int value);
	Account *getAccount(unsigned int id);
	void AcountBalance(unsigned int id);
	void BankBalance();
	void accountRemove(unsigned int id);
	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
private:
	int liquidity;
	std::vector<Account > clientAccounts;
	static unsigned int available_id;
};
