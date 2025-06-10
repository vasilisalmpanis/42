#include "DivideAndRule.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

unsigned int Bank::available_id = 0;

Bank::Account::Account(int value, int id) : id(id), value(value) {
}

void Bank::Account::addValue(int value) {
	this->value += value;
}
unsigned int Bank::Account::getId() const {
	return this->id;
}

unsigned int Bank::Account::getValue() const {
	return this->value;
}
std::ostream& operator << (std::ostream& p_os, const Bank::Account& p_account) {
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return (p_os);
}

Bank::Bank() :liquidity(0) {}

void Bank::set_liquidity(int liq) {
	this->liquidity = liq;
}

void Bank::deposit(unsigned int id, int value) {
	for (std::vector<Account>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
		if (it->getId() == id) {
			int commision = value * 5 / 100;
			this->liquidity += commision;
			value -= commision;
			if (value < 0)
				return ;
			it->addValue(value);
		}
	}
}

int Bank::addAccount() {
	int id = available_id;
	this->clientAccounts.push_back(Account(0, available_id));
	++available_id;
	return id;
}

void Bank::addLiquidity(int value) {
	liquidity += value;
}
void Bank::removeLiquidity(int value) {
	liquidity -= value;
	if (liquidity < 0)
		liquidity = 0;
}
Bank::Account *Bank::getAccount(unsigned int id) {
	for (std::vector<Account>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
		if (it->getId() == id) {
			return it.base();
		}
	}
	return NULL;;
}
void Bank::AcountBalance(unsigned int id) {
	Account *acc = getAccount(id);
	if (!acc)
		return ;
	std::cout << "Account " << acc->getId() << ": " << std::endl;
	std::cout << acc->getValue() << std::endl;
	std::cout << " ----- " << std::endl;
}

void Bank::BankBalance() {
	std::cout << *this << std::endl;
}

void Bank::accountRemove(unsigned int id) {
	std::vector<Account>::iterator it = std::find_if(
			clientAccounts.begin(),
			clientAccounts.end(),
			FindAccountById(id)
			);
	if (it != clientAccounts.end())
		clientAccounts.erase(it);
	else
		throw IndexNotFoundException();
}

int Bank::requestLoan(unsigned int id, unsigned int value) {
	if (value > (unsigned int)this->liquidity)
		throw NotEnoughFundsException();
	std::vector<Account>::iterator it = std::find_if(
			clientAccounts.begin(),
			clientAccounts.end(),
			FindAccountById(id)
	);
	if (it == clientAccounts.end())
		throw IndexNotFoundException();
	it->addValue(value);
	this->liquidity -= value;
	return 0;
}

Bank::Account const &Bank::operator[](int val) {
	Account *acc = getAccount(val);
	if (acc)
		return (*(clientAccounts.data() + val));
	throw IndexNotFoundException();
}

const char *Bank::IndexNotFoundException::what() const throw() {
	return "Invalid index";
}

const char *Bank::NotEnoughFundsException::what() const throw() {
	return "Not enough funds";
}
const char *Bank::IncorrectValueException::what() const throw() {
	return "Incorect value";
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "-----Bank information-----" << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
	for (std::vector<Bank::Account>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); it++)
		p_os << *it << std::endl;
	p_os << "--------------------------" << std::endl;
	return (p_os);
}

