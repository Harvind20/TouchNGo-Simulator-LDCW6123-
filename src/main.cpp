#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	cout << setfill('#') << setw(40) << "\n";
	cout << setfill(' ') << setw(31) <<"Touch N' Go Simulator\n";
	cout << setfill('#') << setw(40) << "\n";
	cout << setfill (' ');
	cout << "What would you like to do today?\n";
	cout << "1. Pay" << setw(20) << "2. Top Up\n";
	cout << "3. Receive" << setw(14) << "4. Exit\n";

	string option;

	while (option != "4"){
		cin >> option;
		try{
			int choice = stoi(option);
			switch (choice){
				case 1:
					cout << "Pay\n";
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
					break;
			}
		}
		catch(invalid_argument){cout << "\u001b[1;31mInvalid Option\n\u001b[0m";}

	}
}
