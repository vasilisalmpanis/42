#include "DivideAndRule.hpp"

int main()
{

	Bank bank = Bank();
	bank.addLiquidity(999);
	int a = bank.addAccount();
	int b = bank.addAccount();
	int c = bank.addAccount();
	int d = bank.addAccount();
	int e = bank.addAccount();

	bank.removeLiquidity(200);
	bank.deposit(a, 400);
	bank.deposit(b, 300);
	bank.deposit(c, 200);
	bank.deposit(d, 100);
	bank.deposit(e, 500);


	bank.AcountBalance(a);
	bank.BankBalance();
	return (0);
}
