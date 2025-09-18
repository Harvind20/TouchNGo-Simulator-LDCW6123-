#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void payByPhone(double& bal);
void payment(double& bal);
void payByQR(double& bal);
void payByToll(double& bal);

int main(){
	string option;
	double balance = 50.0;

	while (option != "4"){
		cout << setfill('#') << setw(40) << "\n";
		cout << setfill(' ') << setw(42) <<"\u001b[1;37mTouch N' Go Simulator\u001b[0m\n";
		cout << setfill('#') << setw(40) << "\n";
		cout << setfill (' ');
		cout << "\u001b[1;39mYour Balance\u001b[0m: RM" << balance << endl;
		cout << "What would you like to do today?\n";
		cout << "1. Pay" << setw(20) << "2. Top Up\n";
		cout << "3. Receive" << setw(14) << "4. Exit\n";
		cin >> option;
		try{
			int choice = stoi(option);
			switch (choice){
				case 1:
					payment(balance);
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

void payment(double& bal){
	string option;
	cout << "Select your payment method:\n";
	cout << "1. Pay by Phone Number" << setw(23) << "2. Pay by QR\n";
	cout << "3. Pay Toll" << setw(29) << "4. Back\n";
	cin >> option;
	int method = stoi(option);
	switch (method){
		case 1:
			payByPhone(bal);
			break;
		case 2:
			payByQR(bal);
			break;
		case 3:
			payByToll(bal);
			break;
		case 4:
			break;
		default:
			cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
			cout << "Please select the offered options.\n";
			break;
	}
}

void payByPhone(double& bal){
	string pNum,amt,reference;
	cout << "Phone Number: ";
	cin >> pNum;
	cout << "Amount: ";
	cin >> amt;
	cout << "Reference: ";
	cin.ignore();
	getline(cin,reference);

	double phoneNumber = stod(pNum);
	double amount = stod(amt);
	cout << amount << endl;

	if (amount < 0){
		cout << "\u001b[1;31mInvalid Amount\n\u001b[0m";
		cout << "Please input a valid amount.\n";
		return;
	}
	if (bal >= amount){
		cout << setprecision(2) << fixed;
		cout << "\u001b[1;32mPayment Success!\u001b[0m\n";
		cout << "Paid RM" << amount << " for " << reference << endl;
	}
	else{
		cout << "\u001b[1;31mPayment Failed!\u001b[0m Not enough money in your account.\n";
		return;
	}

	bal -= amount;
	cout << setprecision(2) << fixed;
	cout << "Balance: RM" << bal << endl;
	if (bal <= 10){
		cout << "\u001b[1;33mWarning!\u001b[0m Account balance is low. Consider topping up.\n";
	}
	return;
}

void payByQR(double& bal){
	string amt,reference;
	string load[] = {"‾‾‾","———","___"};

	cout << "Amount: ";
	cin >> amt;
	cout << "Reference: ";
	cin.ignore();
	getline(cin,reference);

	double amount = stod(amt);

	if (amount < 0){
		cout << "\u001b[1;31mInvalid Amount\n\u001b[0m";
		cout << "Please input a valid amount.\n";
		return;
	}
	cout << "Scanning QR\n";
	for (int j = 0; j<10; j++){
		for (int i = 0;i < 3;i++){
			cout << "[" << load[i] << "]\r";
			fflush(stdout);
			std::chrono::milliseconds dura(150);
			std::this_thread::sleep_for(dura);
		}
	}
	if (bal >= amount){
		cout << setprecision(2) << fixed;
		cout << "\u001b[1;32mPayment Success!\u001b[0m\n";
		cout << "Paid RM" << amount << " for " << reference << endl;
	}
	else{
		cout << "\u001b[1;31mPayment Failed!\u001b[0m Not enough money in your account.\n";
		return;
	}

	bal -= amount;
	cout << setprecision(2) << fixed;
	cout << "Balance: RM" << bal << endl;
	if (bal <= 10){
		cout << "\u001b[1;33mWarning!\u001b[0m Account balance is low. Consider topping up.\n";
	}
	return;
}

void payByToll(double& bal){
	if (bal < 2.10){
		cout << "\u001b[1;31mPayment Failed!\u001b[0m Not enough money in your account.\n";
		return;		
	}
	cout << "\u001b[1;32mPayment Success!\u001b[0m\n";
	cout << "Paid RM2.10 for toll.\n";
	bal -= 2.10;
	cout << setprecision(2) << fixed;
	cout << "Balance: RM" << bal << endl;
	if (bal <= 10){
		cout << "\u001b[1;33mWarning!\u001b[0m Account balance is low. Consider topping up.\n";
	}
	return;
}
