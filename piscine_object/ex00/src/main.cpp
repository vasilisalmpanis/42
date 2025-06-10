#include "DivideAndRule.hpp"
#include <exception>
#include <ostream>

int main()
{

	try {
		Bank bank = Bank();
		bank.addLiquidity(999);
		int a = bank.addAccount();
		int b = bank.addAccount();
		int c = bank.addAccount();
		int d = bank.addAccount();
		int e = bank.addAccount();

		bank.deposit(a, 400);
		bank.deposit(b, 300);
		bank.deposit(c, 200);
		bank.deposit(d, 100);
		bank.deposit(e, 500);

		bank.requestLoan(a, 999);
		std::cout << "Loan was declined" << std::endl;
		Bank::Account* acc = bank.getAccount(a);
		std::cout << "account a has " << acc->getValue() << std::endl;

		const Bank::Account& acc2 = bank[a];
		std::cout << "account a has " << acc2.getValue() << std::endl;

		bank.AcountBalance(a);
		bank.BankBalance();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
