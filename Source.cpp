#include <iostream>
#include <string>
#include<conio.h>

using namespace std;

// Global Variables
int numOfService; // The number of service that the user choose

int numOfUser = 0, numOfLine = 0; // The number of user's line and the number of the user 

string yesOrNo; //To check if user enter yes or no 

bool isBreak = false, flag = false;


// Structures
struct date { // To store the date of packages

	int day, month, year;

};

struct dataOfNumbers { // To store the data of the user's numbers

	char number[12], package[16];
	float balance = 0.0;
	date startDate, renewalDate;

};

struct makingAccounts { // To store the user's data

	string name, email, address;
	char password[51];
	dataOfNumbers numbers[3];
	char id[13];
	int line;// The number of user's line

}userAccount[10000]; // This system can store data for 10000 users


// Functions
void getUserInfo(int& user); // Get informations about users

void getPassword(int& user); // Get the user's password

void checkValidateNum(int& user); // Check if the users'numbers is valid or not

void checkValidateId(int& user); // Check if the id is valid or not

void checkValidateCard();  // Check if the card is valid or not

void checkIfExistNumber(int& user);  // Check the number the user enter

int checkPackageAndBalance(int& user); // Check the packages that user subscribe in it and user's balance

void ourServices(); // Show the users our services

void choosePackage(int& user); // Choose the package that the user wants to subscribe it

void balanceTransfer(int& user); // To transfer the balance from number to another number

void callsOrMessages(int& user); // To make a call and messages

void rechargeBalance(int& user); // To recharge user's balance by card

void checkTheDate(int& user); // Check if the date is correct or not


// Main
int main() {

	int user = 0;

	cout << " \t\t\t\t\t Welcome to our telecom company " << endl;

	while (true)
	{

		getUserInfo(user); // To get iformations about users

		while (true)
		{

			cout << endl << "\t\t\t\t\t---------------------------------------------------------------------" << endl;

			ourServices();

			if (numOfService == 1) balanceTransfer(user);

			else if (numOfService == 2) choosePackage(user);

			else if (numOfService == 3) callsOrMessages(user);

			else if (numOfService == 4) callsOrMessages(user);

			else if (numOfService == 5) rechargeBalance(user);

			else if (numOfService == 6)
			{
				cout << endl << "\t\t\t\t\t------------------------------------------------------------------------------" << endl;
				cout << endl << "\t\t\t\t\t Thank you for visiting us " << endl;
				break;
			}

			else cout << endl << "Wrong choice please try again!" << endl;

		}



		cout << "Do you want to make another account : (Yes/No): ";  // To check if another user want to make an account

		while (true)
		{

			cin >> yesOrNo;
			if (yesOrNo == "No" || yesOrNo == "NO" || yesOrNo == "no") {
				isBreak = true;
				break;
			}

			else if (yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "YES") {
				user++;
				break;
			}

			else {
				cout << "Please enter (Yes/No) : ";
			}
		}
		if (isBreak) break;

	}


	return 0;
}

void getUserInfo(int& user)
{

	cout << endl << "Enter Your Name : ";  // To get the name of user
	if (user != 0) cin.ignore();
	getline(cin, userAccount[user].name);


	cout << endl << "Enter Your E-mail : "; // To get the email of user
	getline(cin, userAccount[user].email);

	cout << endl << "Enter Your Address : "; // To get the address of user
	getline(cin, userAccount[user].address);


	cout << endl << "Enter Your Password: "; // To get the password of user
	getPassword(user);

	cout << endl << endl << "Enter your ID , the id should contains 12 numbers: "; // To get the id of user
	checkValidateId(user); // To check if this id is valid or not

	userAccount[user].line = 0; // The number of user's line

	while (userAccount[user].line < 3)
	{
		cout << endl << "Enter your PhoneNumber , your phoneNumber should contains 11 numbers , and should start with (011) : "; // To get the phone numbers of user

		checkValidateNum(user); // To check if this number is valid or not

		checkTheDate(user); // To get the start dare and the renewal date for the numbers

		checkPackageAndBalance(user); // To get the balance and the package of user

		while (true)
		{

			cout << endl << "Do you need to enter more numbers : (Yes\ No) : "; // To check if the user want to 
			cin >> yesOrNo;

			if (yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "YES")
			{
				userAccount[user].line++;
				break;
			}

			else if (yesOrNo == "No" || yesOrNo == "no" || yesOrNo == "NO")
			{
				isBreak = true;
				break;
			}

			else cout << endl << "Wrong! please try again" << endl; // if the user enter anything except no or yes
		}

		if (isBreak) break;

	}
	if (userAccount[user].line == 3) cout << endl << "Sorry you can't add more than 3 numbers " << endl; // if the user want to enter more than 3 numbers
	isBreak = false;



}


void checkValidateNum(int& user)
{
	while (true)
	{
		int counter1 = 0, counter2 = 0, k = 0;

		cin >> userAccount[user].numbers[userAccount[user].line].number[0];

		while (userAccount[user].numbers[userAccount[user].line].number[k] != '\n')
		{
			k++;
			userAccount[user].numbers[userAccount[user].line].number[k] = getchar();

		}
		userAccount[user].numbers[userAccount[user].line].number[11] = '\0';
		for (int i = 0; i < k; ++i)
		{
			if (userAccount[user].numbers[userAccount[user].line].number[i] >= 48 && userAccount[user].numbers[userAccount[user].line].number[i] <= 57)
				counter1++;
			counter2++;
		}

		if (counter1 != 11 || counter2 != 11 || userAccount[user].numbers[userAccount[user].line].number[0] != '0' || userAccount[user].numbers[userAccount[user].line].number[1] != '1' || userAccount[user].numbers[userAccount[user].line].number[2] != '1')
			cout << "invalid Number please try again: "; // if the user enter invalid number

		else break;
	}


}


void checkValidateId(int& user)
{
	while (true)
	{
		int counter1 = 0, counter2 = 0, k = 0;

		userAccount[user].id[0] = getchar();

		while (userAccount[user].id[k] != '\n')
		{
			k++;
			userAccount[user].id[k] = getchar();

		}
		for (int i = 0; i < k; ++i)
		{
			if (userAccount[user].id[i] >= 48 && userAccount[user].id[i] <= 57)
				counter1++;
			counter2++;
		}
		if (counter1 != 12 || counter2 != 12)
			cout << endl << "invalid Id please try again : ";

		else break;
	}



}


void checkValidateCard()
{

	bool is_invalid = false;
	char card[20];
	while (true)
	{
		int counter1 = 0, counter2 = 0, k = 0;
		if (is_invalid == false)
			cin.ignore();

		card[0] = getchar();

		while (card[k] != '\n')
		{
			k++;
			card[k] = getchar();

		}
		for (int i = 0; i < k; ++i)
		{
			if (card[i] >= 48 && card[i] <= 57)
				counter1++;
			counter2++;
		}
		if (counter1 != 12 || counter2 != 12)
		{
			cout << endl << "invalid Id please try again : ";
			is_invalid = true;
		}

		else break;
	}


}


void getPassword(int& user)
{
	int index = 0;

	do {
		userAccount[user].password[index] = _getch();

		if (userAccount[user].password[index] != '\r')
		{
			cout << "*";
		}

		index++;
	} while (userAccount[user].password[index - 1] != '\r');

	userAccount[user].password[index - 1] = '\0';

	_getch();


}


void ourServices()
{
	cout << endl << "Our services:";  // To show the all services
	cout << endl << "1.Balance Transfer";  // First service
	cout << endl << "2.Packages";  // Second service
	cout << endl << "3.Calls";  // 3th service
	cout << endl << "4.Messages";  // 4th service
	cout << endl << "5.The Balance Recharge";  // 5th service
	cout << endl << "6.Close";  // 6th service

	cout << endl << endl << "Enter a number please:"; // To make the user to choose a number
	cin >> numOfService; // The number which the user chose

	while (true) // This loop to check that the user chose a correct number
	{
		if (numOfService >= 1 && numOfService <= 6) break;

		else
		{
			cout << endl << "This number is wrong please try again: ";  // If the user chose wrong number
			cin >> numOfService;
		}
	}

}


void balanceTransfer(int& user)
{
	cout << endl << "Enter your number please: ";
	checkIfExistNumber(user);
	if (flag)
	{

		cout << endl << "Enter the balance you want to send: ";
		float balance_Transfer;
		cin >> balance_Transfer;
		if (balance_Transfer > userAccount[numOfUser].numbers[numOfLine].balance)
			cout << "Sorry you don't have enough balance to transfer !" << endl;
		else
		{
			userAccount[numOfUser].numbers[numOfLine].balance -= balance_Transfer;
			float balance1 = userAccount[numOfUser].numbers[numOfLine].balance;

			cout << endl << "Enter the number you that want to transfer balance to: ";
			checkIfExistNumber(user);
			if (flag) {

				userAccount[numOfUser].numbers[numOfLine].balance += balance_Transfer;
				float balance2 = userAccount[numOfUser].numbers[numOfLine].balance;

				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);

				cout << endl << "Your balance now is: " << balance1 << " L.E " << "      The balance of the another number is: " << balance2 << " L.E " << endl;
			}
			else cout << endl << "Sorry this number is out the network! please try again later " << endl;
		}

	}
	else cout << "Sorry this number is out the network!";


}


int checkPackageAndBalance(int& user)
{
	bool isBreak2 = false;
	while (true)
	{
		cout << endl << "Do You Subscribe In Any Package:(Yes\ No) : ";
		cin >> yesOrNo;

		if (yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "YES")
		{
			cout << endl << "Our Packages: { 1.ConnectX , 2.ConnectBundles, 3.NezamHekaia, 4.Felixat} " << endl;
			while (true)
			{
				int numOfPackage;
				cout << endl << "Please enter the number of package you subscribed: ";
				cin >> numOfPackage;

				if (numOfPackage == 1)
				{
					strcpy_s(userAccount[user].numbers[userAccount[user].line].package, "ConnectX");
					isBreak2 = true;
					break;
				}
				else if (numOfPackage == 2)
				{
					strcpy_s(userAccount[user].numbers[userAccount[user].line].package, "ConnectBundles");
					isBreak2 = true;
					break;
				}

				else if (numOfPackage == 3)
				{
					strcpy_s(userAccount[user].numbers[userAccount[user].line].package, "NezamHekaia");
					isBreak2 = true;
					break;
				}

				else if (numOfPackage == 4)
				{
					strcpy_s(userAccount[user].numbers[userAccount[user].line].package, "Felixat");
					isBreak2 = true;
					break;
				}



				else cout << endl << " This number is wrong! please try again";

			}




			cout << endl << "Enter the balance of this number:"; cin >> userAccount[user].numbers[userAccount[user].line].balance;

			if (isBreak2)
			{
				break;
			}
		}

		else if (yesOrNo == "No" || yesOrNo == "no" || yesOrNo == "NO")
		{
			cout << endl << "Enter the balance of this number:";
			cin >> userAccount[user].numbers[userAccount[user].line].balance;
			return 0;
		}

		else cout << endl << "Wrong please try again! ";


	}

}


void choosePackage(int& user)
{
	cout << endl << "Enter your PhoneNumber , your phoneNumber should contains 11 numbers , and should start with (011): ";
	checkIfExistNumber(user);

	if (!flag) cout << endl << "Sorry this number is out the network! please try again later " << endl;

	else
	{
		while (true)
		{

			cout << endl << "Our Packages: " << endl;
			cout << "1.ConnectX (for 20 L.E)" << endl;
			cout << " 2.ConnectBundles(for 50 L.E)" << endl;
			cout << " 3.NezamHekaia (for 45 L.E )" << endl;
			cout << " 4.Felixat (for 60 L.E)" << endl;
			cout << " 5.Renew the package";

			int packageNum;
			cout << endl << "Please enter the number of package that you want to subscribe: ";
			cin >> packageNum;

			if (packageNum == 1) // For the first package
			{
				if (userAccount[numOfUser].numbers[numOfLine].balance > 20)
				{

					strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "ConnectX");

					cout << endl << "Enter the date of today " << endl;
					cout << "Enter the day: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

					cout << endl << "Enter the month: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

					cout << endl << "Enter the year: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;

					userAccount[numOfUser].numbers[numOfLine].balance -= 20;
					cout << endl << "You subscribed in package ConnectX successfully , Your balance now is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].balance;

					cout << endl << "The renewal date for this package is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

				}
				else cout << endl << "Sorry you don't have enough money to subscribe !";

				break;
			}

			else if (packageNum == 2) // For the 2nd package
			{
				if (userAccount[numOfUser].numbers[numOfLine].balance > 20)
				{

					strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "ConnectBundles");

					cout << endl << "Enter the date of today " << endl;
					cout << "Enter the day: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

					cout << endl << "Enter the month: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

					cout << endl << "Enter the year: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


					userAccount[numOfUser].numbers[numOfLine].balance -= 50;
					cout << endl << "You subscribed in package ConnectBundles successfully , Your balance now is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].balance;

					cout << endl << "The renewal date for this package is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

				}
				else cout << endl << "Sorry you don't have enough money to subscribe !";

				break;

			}

			else if (packageNum == 3) // For the 3rd package
			{
				if (userAccount[numOfUser].numbers[numOfLine].balance > 20)
				{

					strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "NezamHekaia");
					userAccount[numOfUser].numbers[numOfLine].balance -= 45;

					cout << endl << "Enter the date of today " << endl;
					cout << "Enter the day: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

					cout << endl << "Enter the month: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

					cout << endl << "Enter the year: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


					cout << endl << "You subscribed in package NezamHekaia successfully , Your balance now is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].balance;

					cout << endl << "The renewal date for this package is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

				}
				else cout << endl << "Sorry you don't have enough money to subscribe !";

				break;
			}

			else if (packageNum == 4) // For the 4th package
			{
				if (userAccount[numOfUser].numbers[numOfLine].balance > 20)
				{

					strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "Felixat");
					userAccount[numOfUser].numbers[numOfLine].balance -= 60;

					cout << endl << "Enter the date of today " << endl;
					cout << "Enter the day: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

					cout << endl << "Enter the month: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

					cout << endl << "Enter the year: ";
					cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;

					cout << endl << "You subscribed in package Felixat successfully , Your balance now is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].balance;

					cout << endl << "The renewal date for this package is: ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
					cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

				}
				else cout << endl << "Sorry you don't have enough money to subscribe !";

				break;

			}

			else if (packageNum == 5) // For the 5th package
			{
				int res = strcmp(userAccount[numOfUser].numbers[numOfLine].package, "Felixat");
				if (res == 0)
				{
					if (userAccount[numOfUser].numbers[numOfLine].balance > 60)
					{

						strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "Felixat");

						cout << endl << "Enter the date of today " << endl;
						cout << "Enter the day: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

						cout << endl << "Enter the month: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

						cout << endl << "Enter the year: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


						userAccount[numOfUser].numbers[numOfLine].balance -= 60;
						cout << endl << "You subscribed in package Felixat successfully , Your balance now is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].balance;

						cout << endl << "The renewal date for this package is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;
					}
					else cout << endl << "Sorry you don't have enough money to subscribe !";
				}
				res = strcmp(userAccount[numOfUser].numbers[numOfLine].package, "ConnectX");
				if (res == 0)
				{
					if (userAccount[numOfUser].numbers[numOfLine].balance > 20)
					{

						strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "ConnectX");

						cout << endl << "Enter the date of today " << endl;
						cout << "Enter the day: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

						cout << endl << "Enter the month: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

						cout << endl << "Enter the year: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


						userAccount[numOfUser].numbers[numOfLine].balance -= 20;
						cout << endl << "You subscribed in package ConnectX successfully , Your balance now is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].balance;

						cout << endl << "The renewal date for this package is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

					}
					else cout << endl << "Sorry you don't have enough money to subscribe !";
				}

				res = strcmp(userAccount[numOfUser].numbers[numOfLine].package, "NezamHekaia");
				if (res == 0)
				{
					if (userAccount[numOfUser].numbers[numOfLine].balance > 45)
					{

						strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "NezamHekaia");

						cout << endl << "Enter the date of today " << endl;
						cout << "Enter the day: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

						cout << endl << "Enter the month: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

						cout << endl << "Enter the year: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


						userAccount[numOfUser].numbers[numOfLine].balance -= 45;
						cout << endl << "You subscribed in package NezamHekaia successfully , Your balance now is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].balance;

						cout << endl << "The renewal date for this package is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

					}
					else cout << endl << "Sorry you don't have enough money to subscribe !";
				}

				res = strcmp(userAccount[numOfUser].numbers[numOfLine].package, "ConnectBundles");
				if (res == 0)
				{
					if (userAccount[numOfUser].numbers[numOfLine].balance > 50)
					{

						strcpy_s(userAccount[numOfUser].numbers[numOfLine].package, "ConnectBundles");

						cout << endl << "Enter the date of today " << endl;
						cout << "Enter the day: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.day;

						cout << endl << "Enter the month: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.month;

						cout << endl << "Enter the year: ";
						cin >> userAccount[numOfUser].numbers[numOfLine].startDate.year;


						userAccount[numOfUser].numbers[numOfLine].balance -= 50;
						cout << endl << "You subscribed in package ConnectBundles successfully , Your balance now is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].balance;

						cout << endl << "The renewal date for this package is: ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.day << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.month + 1 << " / ";
						cout << userAccount[numOfUser].numbers[numOfLine].startDate.year;

					}
					else cout << endl << "Sorry you don't have enough money to subscribe !";
				}


				break;

			}

			else cout << endl << "Wrong number please try again! ";

		}
	}
}


void checkIfExistNumber(int& user)
{
	char NumOfUser[12]; // The user should enter his number
	cin >> NumOfUser;
	NumOfUser[11] = '\0';
	bool isFound = false;

	for (int k = 0; k <= user; ++k) // This loop to check that user enter a number of the 3 numbers that he enters before
	{
		for (int i = 0; i <= userAccount[user].line; ++i)
		{
			int res = strcmp(userAccount[k].numbers[i].number, NumOfUser);

			if (res == 0)
			{
				isFound = true;
				numOfLine = i;
				break;
			}
		}

		if (isFound)
		{
			numOfUser = k;
			break;
		}
	}
	if (!isFound)
	{
		flag = false;
	}

	else flag = true;

}


void callsOrMessages(int& user)
{

	cout << endl << "Enter your phone number please ,it should contains 11 numbers and start with (011): ";
	checkIfExistNumber(user);
	int numOfUser1 = numOfUser, numOfLine1 = numOfLine;

	if (flag) {

		if (numOfService == 3)
			cout << endl << "Enter the number you want to call please: ";

		if (numOfService == 4)
			cout << endl << "Enter the number you want to message please ,it should contains 11 numbers and start with (011): ";

		checkIfExistNumber(user);
		if (flag)
		{
			userAccount[numOfUser1].numbers[numOfLine1].balance -= 0.25;
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);

			cout << endl << "Your balance now is: " << userAccount[numOfUser1].numbers[numOfLine1].balance << " L.E ";

		}
		else cout << endl << "Sorry this number is out the network! please try again later " << endl;

	}
	else cout << endl << "Sorry this number is out the network! please try again later " << endl;


}


void rechargeBalance(int& user)
{
	cout << endl << "Enter your phone number please ,it should contains 11 numbers and start with (011): ";
	checkIfExistNumber(user);

	if (!flag) cout << endl << "Sorry this number is out the network! please try again later " << endl;

	else
	{
		cout << "Enter the numbers which on the card please , it should contains 12 numbers: ";
		checkValidateCard();

		cout << endl << "Enter the balance of this card please: ";
		int balanceOfCard;
		cin >> balanceOfCard;

		userAccount[numOfUser].numbers[numOfLine].balance += balanceOfCard;
		cout << endl << "Your balance now is: " << userAccount[numOfUser].numbers[numOfLine].balance << " L.E " << endl;
	}

}


void checkTheDate(int& user)
{
	cout << endl << "Please enter the start date of this number: " << endl; // To make the user enter the start date of the package
	cout << "Enter the day: ";
	cin >> userAccount[user].numbers[userAccount[user].line].startDate.day;

	cout << endl << "Enter the month: ";
	cin >> userAccount[user].numbers[userAccount[user].line].startDate.month;

	cout << endl << "Enter the year: ";
	cin >> userAccount[user].numbers[userAccount[user].line].startDate.year;


	cout << endl << "Do you have a renewal date:(Yes/No): ";

	bool isBreak3 = false;

	while (true)
	{
		cin >> yesOrNo;
		if (yesOrNo == "No" || yesOrNo == "NO" || yesOrNo == "no") {
			isBreak3 = true;
			break;
		}

		else if (yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "YES") {

			break;
		}

		else {
			cout << "Please enter (Yes/No) : ";
		}
	}
	if (isBreak3 == 0)
	{

		cout << endl << "Please enter the renewal date of this number: " << endl; // To make the user enter the renewal date of the package
		cout << "Enter the day: ";
		cin >> userAccount[user].numbers[userAccount[user].line].renewalDate.day;

		cout << endl << "Enter the month: ";
		cin >> userAccount[user].numbers[userAccount[user].line].renewalDate.month;

		cout << endl << "Enter the year: ";
		cin >> userAccount[user].numbers[userAccount[user].line].renewalDate.year;


	}
}
