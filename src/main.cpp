#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void payByPhone(int& bal);

int main(){
	cout << setfill('#') << setw(40) << "\n";
	cout << setfill(' ') << setw(31) <<"Touch N' Go Simulator\n";
	cout << setfill('#') << setw(40) << "\n";
	cout << setfill (' ');
	cout << "What would you like to do today?\n";
	cout << "1. Pay" << setw(20) << "2. Top Up\n";
	cout << "3. Receive" << setw(14) << "4. Exit\n";

	string option;
	int balance = 50;

	while (option != "4"){
		cin >> option;
		try{
			int choice = stoi(option);
			switch (choice){
				case 1:
					payByPhone(balance);
					break;
				case 2:
					cout << "Top Up\n";
					break;
				case 3:
					cout << "Receive\n";
					break;
				case 4:
					cout << "Exit\n";
					break;
				default:
					cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
					cout << "Please select the offered options.\n";
					break;
			}
		}
		catch(invalid_argument){cout << "\u001b[1;31mInvalid Option\n\u001b[0m";cout << "Please select the offered options.\n";}
	}
	return 0;
}

void payByPhone(int& bal){
	string pNum,amt,reference;
	cout << "Input: \n";
	cout << "Phone Number: ";
	cin >> pNum;
	cout << "Amount: ";
	cin >> amt;
	cout << "Reference: ";
	cin.ignore();
	getline(cin,reference);

	int phoneNumber = stoi(pNum);
	int amount = stoi(amt);

	if (amount < 0){
		cout << "\u001b[1;31mInvalid Amount\n\u001b[0m";
		cout << "Please input a valid amount.\n";
		return;
	}
	if (bal >= amount){
		cout << "\u001b[1;32mPayment Success!\u001b[0m\n";
		cout << "Paid " << amount << " for " << reference << endl;
	}
	else{
		cout << "\u001b[1;31mPayment Failed!\u001b[0m Not enough money in your account.\n";
		return;
	}

	bal -= amount;
	cout << "Balance: RM" << bal << endl;
	if (bal <= 10){
		cout << "\u001b[1;33mWarning!\u001b[0m Account balance is low. Consider topping up.\n";
	}
	return;
}
