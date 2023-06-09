#include <iostream>
#include <string>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include "Account.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

void display_options();
list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID);
void remove_account(list<Account>& account_list, int account_ID);
void banks_total_balance(list<Account>& account_list, float account_balance);
void apply_to_balance(list<Account>& account_list);
//void banks_dividend(list<Account>& account_list, float dividend, float get_bal);

int main()
{
	int option, id;
	string name = "";
	float deposit{}, withdrawl{}, balance{};
	float dividend {};
	bool open_transaction = true;
	Account account;
	list<Account> accounts;
	list<Account>::iterator it;
	float current_bal = 1.0f;

	while (open_transaction) {
		display_options();
		cin >> option;
		switch (option)
		{
		case 0:
			// option '0' - Program should quit
			cout << "\nThank you for visiting our bank. \nCome back soon! \n";
			open_transaction = false;
			break;

		case 1:
			// option '1' - Program should display account information
			cout << "\n-----------------\n";
			if (accounts.size() == 0)
			{
				cout << "No accounts to display.";
				cout << "\n-----------------\n";
			};
			account.display_account_list(accounts);
			break;

		case 2:
			// option '2' - Program should prompt for a deposit amount
			cout << "What account ID do you want to deposit into? ";
			cin >> id;
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				it->account_deposit(deposit);
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 3:
			// option '3' - Program should prompt for a withdrawal amount
			cout << "What account ID do you want to withdraw from? ";
			cin >> id;
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				it->account_withdrawl(withdrawl);
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 4:
			// option '4' - Program should create a new account
			account.account_info();
			account.account_create(accounts);
			break;

		case 5:
			// option '5' - Program should find an account by its id
			// int id;
			cout << "What account ID do you want to display? ";
			cin >> id;
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				cout << "------------------\n";
				it->account_display();
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 6:
			// option '6' - Program should remove a specified account
			cout << "What account would you like to remove? ";
			cin >> id;
			remove_account(accounts, id);
			break;
		
		case 7:
			// option '7' - Program should return the total balance of the accounts
			cout << "------------------\n";
			cout << "------------------\n";
			banks_total_balance(accounts, balance);
			cout << "\n------------------\n";
			break;

		case 8:
			// option '8' - Program should add a dividend to all of the accounts
			cout << "------------------\n";

			apply_to_balance(accounts);
			//current_bal = account.get_balance();
			//auto updated = std::transform(accounts.begin(), accounts.end(), accounts.begin(), [](float dividend, float current_bal)
				//{ return current_bal * dividend; });
			//accounts.erase(updated, accounts.end());
			//banks_dividend(accounts,  dividend, current_bal);
			break;

		default:
			// none of the above
			break;
		}
	}

}

void display_options()
{
	cout << endl << "Account menu: ";
	cout << endl << "0. Quit Program";
	cout << endl << "1. Display all accounts information";
	cout << endl << "2. Add a deposit to an account";
	cout << endl << "3. Withdraw from an account";
	cout << endl << "4. Add new account";
	cout << endl << "5. Display account by ID";
	cout << endl << "6. Remove account by ID";
	cout << endl << "7. Bank's total balance";
	cout << endl << "8. Add dividend to all accounts";
	cout << endl << "Your choice: ";
}

list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID)
{
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++)
	{
		if (it->get_id() == account_ID) {
			return it;
		}
	}
	return it;
}

void remove_account(list<Account>& account_list, int account_ID)
{
	auto removed_account = remove_if(account_list.begin(), account_list.end(), [account_ID](Account& remove)
		{
			return account_ID == remove.get_id();
		});
	account_list.erase(removed_account, account_list.end());
}

void banks_total_balance(list<Account>& account_list, float account_balance)
{
	auto bank_balance = accumulate(account_list.begin(), account_list.end(), 0.0f, [](float bank_balance, auto total)
		{
			return bank_balance + total.get_balance();
		});
	 cout << "The total balance at the bank is $ " << bank_balance;
}


void apply_to_balance(list<Account>& account_list) {
	cout << "------------------\n";
	cout << "Enter a dividend as a percentage: ";
	float dividend = 1.0f;
	cin >> dividend;
	dividend /= 100;
	for_each(account_list.begin(), account_list.end(), [dividend](auto& acct)
		{
			float new_balance = acct.get_balance() * (1 + dividend);
			acct.update_balance(new_balance);
		});
};

/*
void banks_dividend(list<Account>& account_list, float dividend, float get_bal)
{
	// Applies a specified function object to each element in a source range or to a pair of
	// elements from two source ranges and copies the return values of the function object into a destination range.
	auto updated = std::transform(account_list.begin(), account_list.end(), account_list.begin(), [dividend, get_bal](float dividend, float get_bal) { return get_bal * dividend; });
	account_list.erase(updated, account_list.end());
}
*/