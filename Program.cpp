#include <iostream>
#include <string>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include "Account.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

void display_options();
list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID);
void remove_account(list<Account>& account_list, int account_ID);

int main()
{
	int option, id;
	string name = "";
	float deposit{}, withdrawl{}, balance{};
	bool open_transaction = true;
	Account account;
	list<Account> accounts;
	list<Account>::iterator it;

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
			else {
				cout << "Unable to locate Account by that ID ";
			}
			break;

		case 6:
			// option '6' - Program should remove a specified account
			cout << "What account would you like to remove? ";
			cin >> id;
			remove_account(accounts, id);
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
	cout << endl << "1. Display Account Information";
	cout << endl << "2. Add a deposit to an account";
	cout << endl << "3. Withdraw from an account";
	cout << endl << "4. Add new account";
	cout << endl << "5. Display account by ID";
	cout << endl << "6. Remove account by ID";
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

