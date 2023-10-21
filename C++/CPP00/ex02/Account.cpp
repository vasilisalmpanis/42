/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:30:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/16 18:30:39 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "account:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
	return (_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

int Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void Account::makeDeposit(int deposit) {
	if (deposit > 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal && withdrawal > 0) {
		_totalAmount -= withdrawal;
		_totalNbWithdrawals ++;
		_nbWithdrawals ++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		return true;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	return false;
}

void Account::_displayTimestamp() {
	std::time_t t = std::time(NULL);
	char mbstr[100];

	if (std::strftime(mbstr, sizeof(mbstr), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
		std::cout << mbstr;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}