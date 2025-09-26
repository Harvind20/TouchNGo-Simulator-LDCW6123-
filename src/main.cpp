#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

void payByPhone(double& bal);
void payment(double& bal);
void payByQR(double& bal);
void payByToll(double& bal);
void topUp(double& bal);
void topUpByBank(double& bal);
bool topUpByCard(double& bal);
void receive(double& bal);
void receiveAny(double& bal);
void receiveFixed(double& bal);
void receiveByQR(double& bal);

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
					topUp(balance);
					break;
				case 3:
					receive(balance);
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
	cout << "\n--- Payment Menu ---\n";
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
	cout << "Phone Number(begins with 601): ";
	cin >> pNum;
	cout << "Amount: ";
	cin >> amt;
	cout << "Reference: ";
	cin.ignore();
	getline(cin,reference);

	if (!(pNum.at(0) == '6' && pNum.at(1) == '0' && pNum.at(2) == '1')){
		cout << "\u001b[1;31mInvalid Number\n\u001b[0m";
		cout << "Please input a Malaysian Number.\n";		
		return;
	}
	else if (!(pNum.size() == 11)){
		cout << "\u001b[1;31mInvalid Number\n\u001b[0m";
		cout << "Invalid Number of digits. Please input a Malaysian Number.\n";
		return;
	}

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
	string load[] = {"/","-","\\","|"};

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
	for (int j = 0; j<8; j++){
		for (int i = 0;i < 4;i++){
			cout << "[" << load[i] << "]\r";
			fflush(stdout);
			std::chrono::milliseconds dura(100);
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

void topUp(double& bal){
    string option;
    while(true) {
        cout << "\n--- Top Up Menu ---\n";
        cout << "Select your top-up method:\n";
        cout << "1. Bank Transfer" << setw(25) << "2. Credit/Debit Card\n";
        cout << "3. Back to Main Menu" << setw(14) << "\n";
        cout << "Choose option: ";
        cin >> option;

        try{
            int method = stoi(option);
            switch (method){
                case 1:
                    topUpByBank(bal);
					return;
                    break;
                case 2:
                    topUpByCard(bal);
					return;
                    break;
                case 3:
                    return;
                default:
                    cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
                    cout << "Please select the offered options.\n";
                    break;
            }
        }
        catch(invalid_argument){
            cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
            cout << "Please select the offered options.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void topUpByBank(double& bal){
    string bankOption, amt, reference;
    string banks[] = {
        "1. Maybank", "2. CIMB Bank", "3. Public Bank",
        "4. RHB Bank", "5. Hong Leong Bank", "6. AmBank",
        "7. OCBC Bank", "8. UOB Bank", "9. Standard Chartered",
        "10. Bank Islam", "11. Back"
    };

    while(true) {
        cout << "\n--- Top Up by Bank ---\n";
        cout << "Select your bank:\n";
        for(const auto& bank : banks){
            cout << bank << endl;
        }
        cout << "Choose option: ";
        cin >> bankOption;

        if(bankOption == "11") {
            return;
        }
        try{
            int bankChoice = stoi(bankOption);
            if(bankChoice < 1 || bankChoice > 10){
                cout << "\u001b[1;31mInvalid bank selection. Please choose 1-10 or 11 to go back.\n\u001b[0m";
                continue;
            }

            cout << "Amount to top up: RM";
            cin >> amt;
            cout << "Reference: ";
            cin.ignore();
            getline(cin, reference);

            double amount = stod(amt);
            if(amount <= 0){
                cout << "\u001b[1;31mInvalid amount. Please enter a positive value.\n\u001b[0m";
                continue;
            }

            cout << "Processing bank transfer...\n";
            for(int i = 0; i < 3; i++){
                cout << "." << flush;
                std::chrono::milliseconds dura(500);
                std::this_thread::sleep_for(dura);
            }
            cout << endl;

            bal += amount;
            cout << "\u001b[1;32mTop-up successful!\u001b[0m\n";
            cout << setprecision(2) << fixed;
            cout << "Added RM" << amount << " to your account.\n";
            cout << "Reference: " << reference << endl;
            cout << "New balance: RM" << bal << endl;
            return;
        }
        catch(invalid_argument){
            cout << "\u001b[1;31mInvalid input. Please enter numbers only.\n\u001b[0m";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        catch(out_of_range){
            cout << "\u001b[1;31mInput value is too large.\n\u001b[0m";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

bool topUpByCard(double& bal) {
    string cardNum, amt, expiry, cvv, reference;
    int currentStep = 1;

    cin.ignore();
    cout << "\n--- Top Up by Card ---\n";
    cout << "Enter card details (or 'B' to go back to previous step):\n";

    while(true) {
        switch(currentStep) {
            case 1:
                cout << "Card Number (16 digits): ";
                getline(cin, cardNum);

                if(cardNum == "B" || cardNum == "b") {
                    return true;
                }
                if(cardNum.length() != 16) {
                    cout << "\u001b[1;31mInvalid card number. Must be exactly 16 digits.\n\u001b[0m";
                    continue;
                }
                try {
                    stoll(cardNum);
                    currentStep = 2;
                }
                catch(invalid_argument) {
                    cout << "\u001b[1;31mInvalid card number. Must contain digits only.\n\u001b[0m";
                }
                catch(out_of_range) {
                    cout << "\u001b[1;31mCard number is too large.\n\u001b[0m";
                }
                break;

            case 2:
                {
                    cout << "Expiry Date (MM/YY format including slash): ";
                    getline(cin, expiry);

                    if(expiry == "B" || expiry == "b") {
                        currentStep = 1;
                        continue;
                    }
                    if(expiry.length() != 5 || expiry[2] != '/') {
                        cout << "\u001b[1;31mInvalid expiry date. Please use MM/YY format including the slash (/).\n\u001b[0m";
                        continue;
                    }
                    string monthStr = expiry.substr(0, 2);
                    string yearStr = expiry.substr(3, 2);
                    try {
                        int month = stoi(monthStr);
                        int year = stoi(yearStr);

                        if(month < 1 || month > 12) {
                            cout << "\u001b[1;31mInvalid month. Please enter a month between 01-12.\n\u001b[0m";
                            continue;
                        }

                        currentStep = 3;
                    }
                    catch(...) {
                        cout << "\u001b[1;31mInvalid expiry date. Please use numbers for month and year.\n\u001b[0m";
                    }
                }
                break;

            case 3:
                cout << "CVV (3 digits): ";
                getline(cin, cvv);

                if(cvv == "B" || cvv == "b") {
                    currentStep = 2;
                    continue;
                }
                if(cvv.length() != 3) {
                    cout << "\u001b[1;31mInvalid CVV. Must be exactly 3 digits.\n\u001b[0m";
                    continue;
                }
                try {
                    stoi(cvv);
                    currentStep = 4;
                }
                catch(invalid_argument) {
                    cout << "\u001b[1;31mInvalid CVV. Must contain digits only.\n\u001b[0m";
                }
                break;

            case 4:
                cout << "Amount to top up (RM): ";
                getline(cin, amt);
                if(amt == "B" || amt == "b") {
                    currentStep = 3;
                    continue;
                }
                try {
                    double amount = stod(amt);
                    if(amount <= 0) {
                        cout << "\u001b[1;31mInvalid amount. Please enter a positive value.\n\u001b[0m";
                        continue;
                    }
                    currentStep = 5;
                }
                catch(invalid_argument) {
                    cout << "\u001b[1;31mInvalid amount. Please enter a valid number.\n\u001b[0m";
                }
                catch(out_of_range) {
                    cout << "\u001b[1;31mAmount is too large.\n\u001b[0m";
                }
                break;

            case 5:
                cout << "Reference: ";
                getline(cin, reference);

                if(reference == "B" || reference == "b") {
                    currentStep = 4;
                    continue;
                }
                try {
                    double amount = stod(amt);
                    cout << "Processing card payment...\n";
                    for(int i = 0; i < 3; i++) {
                        cout << "." << flush;
                        std::chrono::milliseconds dura(500);
                        std::this_thread::sleep_for(dura);
                    }
                    cout << endl;
                    bal += amount;
                    cout << "\u001b[1;32mTop-up successful!\u001b[0m\n";
                    cout << setprecision(2) << fixed;
                    cout << "Added RM" << amount << " to your account.\n";
                    cout << "Reference: " << reference << endl;
                    cout << "New balance: RM" << bal << endl;
                    return false;
                }
                catch(...) {
                    cout << "\u001b[1;31mError processing payment. Please try again.\n\u001b[0m";
                    currentStep = 4;
                }
                break;
        }
    }
}

void receive(double& bal) {
    string option;
    while (true) {
        cout << "\n--- Receive Menu ---\n";
        cout << "Select receive method:\n";
        cout << "1. Receive Any Amount" << setw(30) << "2. Receive Fixed Amount\n";
        cout << "3. Receive by QR" << setw(19) << "4. Back\n";
        cout << "Choose option: ";
        cin >> option;

        try {
            int method = stoi(option);
            switch (method) {
                case 1:
                    receiveAny(bal);
                    break;  // Return to main menu after completion
                case 2:
                    receiveFixed(bal);
                    break;
                case 3:
                    receiveByQR(bal);
                    break;
                case 4:
                    return;  // Return to main menu
                default:
                    cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
                    cout << "Please select the offered options.\n";
                    break;
            }
        }
        catch (invalid_argument) {
            cout << "\u001b[1;31mInvalid Option\n\u001b[0m";
            cout << "Please select the offered options.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}


void receiveAny(double& bal){
	// Generate random amount between 1.00 and 50.00
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(1.0, 50.0);
	double amount = round(dis(gen) * 100) / 100; // Round to 2 decimal places

	cout << "Generating random amount...\n";
	std::chrono::milliseconds dura(1000);
	std::this_thread::sleep_for(dura);

	bal += amount;
	cout << "\u001b[1;32mReceived RM" << fixed << setprecision(2) << amount << "\u001b[0m\n";
	cout << "New balance: RM" << fixed << setprecision(2) << bal << endl;
}

void receiveFixed(double& bal){
	string amt;
	cout << "Amount to receive: RM";
	cin >> amt;

	try{
		double amount = stod(amt);
		if(amount <= 0){
			cout << "\u001b[1;31mInvalid amount. Please enter a positive value.\n\u001b[0m";
			return;
		}

		bal += amount;
		cout << "\u001b[1;32mReceived RM" << fixed << setprecision(2) << amount << "\u001b[0m\n";
		cout << "New balance: RM" << fixed << setprecision(2) << bal << endl;
	}
	catch(invalid_argument){
		cout << "\u001b[1;31mInvalid amount. Please enter a valid number.\n\u001b[0m";
	}
	catch(out_of_range){
		cout << "\u001b[1;31mAmount is too large.\n\u001b[0m";
	}
}

void receiveByQR(double& bal){
	string amt;
	string load[] = {"/","-","\\","|"};

	cout << "Amount to receive: RM";
	cin >> amt;

	try{
		double amount = stod(amt);
		if(amount <= 0){
			cout << "\u001b[1;31mInvalid amount. Please enter a positive value.\n\u001b[0m";
			return;
		}

		cout << "Displaying QR code\n";
		for (int j = 0; j < 10; j++){
			for (int i = 0; i < 4; i++){
				cout << "[" << load[i] << "]\r";
				fflush(stdout);
				std::chrono::milliseconds dura(100); // 0.5 second delay
				std::this_thread::sleep_for(dura);
			}
		}

		bal += amount;
		cout << "\u001b[1;32mReceived RM" << fixed << setprecision(2) << amount << "\u001b[0m\n";
		cout << "New balance: RM" << fixed << setprecision(2) << bal << endl;
	}
	catch(invalid_argument){
		cout << "\u001b[1;31mInvalid amount. Please enter a valid number.\n\u001b[0m";
	}
	catch(out_of_range){
		cout << "\u001b[1;31mAmount is too large.\n\u001b[0m";
	}
}
