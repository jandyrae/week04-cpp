#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>

using namespace std;

class Account {
private:
	int account_ID;
	string account_name;
	float account_balance;
	static int next_ID;

public:
	Account();
	Account(int account_ID, string account_name, float account_balance);
	int get_id();
	float get_balance();
	void account_info(void);
	void account_display(void) const;
	void account_deposit(float deposit);
	void account_withdrawl(float withdrawl);
	void account_create(list<Account>& account_list);
	void display_account_list(list<Account>& account_list);
	void update_balance(float new_balance);
};