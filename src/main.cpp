#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	cout << "Hello\n";
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
					cout << "Invalid Option\n";
					break;
			}
		}
		catch(invalid_argument){cout << "Invalid Option\n";}

	}
}
