#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <windows.h> //for Sleep() //to delay
#include <cstdlib> //for rand and srand to work
#include <stdlib.h> //for strlen //get string lenght
#define underline "\033[4m" //to underline specific sentences
using namespace std;

void customerSignUp();
void staffLogin();
bool login();
void customer();
void loadingbar(void);
void pwellcome();
void BoxesOfWords(string);
void displaycocacola(void);
void displayslogan(void);
void returnpreviouspage(void);
void mainmenu(int option, int suboption);
void loadScreen();
void viewallmenu(int option);
void displayburgermenu(void);
void displaybeveragemenu(void);
void displaysidemenu(void);
void selectaddmenu(int option);
void addburgermenu(void);
void addbeveragemenu(void);
void addsidemenu(void);
void readburgerinfile(void);
void readbeverageinfile(void);
void readsideinfile(void);
void seletedeletemenu(int option);
void deleteburgermenu(void);
void deletebeveragemenu(void);
void deletesidemenu(void);
void selecteditmenu(int option);
void editburgermenu(int option, int suboption);
void select_burger_details_to_edit(int editedIndex);
void rewriteinburgerfile(void);
void editbeveragemenu(int option, int suboption);
void select_beverage_details_to_edit(int editedIndex);
void rewriteinbeveragefile(void);
void editsidemenu(int option, int suboption);
void select_side_details_to_edit(int editedIndex);
void rewriteinsidefile(void);
void orderFood();
void orderBeverage();
void orderSide();
void orderDetails();
void menuChoice();
void viewOrder();
void editOrder();
void deleteOrder();
void writingSentence();
void writingSentence2();
void writingSentence3();
void errorMessage();
void errorMessage2();
void errorMessage3();
string pause = " ";
const int SIZE1 = 15;
string index[15];
string name[15];
double price[15];
string beverageindex[15];
string beveragename[15];
double beverageprice[15];
string sideindex[15];
string sidename[15];
double sideprice[15];
//struct definition
struct Orderlist { //store customer input
	string orderindex;
	string ordername;
	int newOrderIndex;
	int orderquantity;
	double totalorderprice;
} order;
//global declarations
int choice, bankno, bankpass, phoneno, phonepin, method, newIndex, newIndex2, newIndex3;
int burgerOrderNo = 0, beverageOrderNo = 0, sideOrderNo = 0;
char cont, membership;
bool customerLogin;
Orderlist burgerOrder[100];
Orderlist beverageOrder[100];
Orderlist sideOrder[100];

//customer
void customerSignUp() {
	string username, password;
	cout << "Enter a username: ";
	cin >> username;
	cout << "Enter a password: ";
	cin >> password;
	cout << endl;
	system("cls");

	ifstream userfile("user.txt");
	string storedUsername;
	bool usernameExists = false;

	while (userfile >> storedUsername) {
		if (storedUsername == username) {
			usernameExists = true;
			break; }}
	userfile.close();
	if (usernameExists) {
		cout << "Username already exists. You have already signed up. Please log in." << endl;
		cout << endl << string(120, char((175)));
		return;}
	ofstream userfileOut("user.txt", ios::app);
	userfileOut << username << " " << password << endl;
	userfileOut.close();
	cout << "Account created successfully! Please log in." << endl;}

//customer login
bool login() {
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	ifstream userfile("user.txt");
	if (!userfile) {
		cout << "Unable to open file!" << endl;
		return false;}
	string storedUsername, storedPassword;
	while (userfile >> storedUsername >> storedPassword) {
		if (storedUsername == username && storedPassword == password) {
			userfile.close();
			return true;
			cout << "Login successfully. Welcome " << username << " !" << endl;
			customerLogin = true;
			return customerLogin;
			mainmenu(5, 0);}}
	userfile.close();
	cout << "Invalid username or password. Please try again." << endl;
	return false;}

//staff
bool check(const string& username, const string& password) {
	ifstream infile("staff.txt");
	string storedUsername, storedPassword;
	while (infile >> storedUsername >> storedPassword) {
		if (storedUsername == username && storedPassword == password) {
			infile.close();
			return true;}
		else
			return false;}
	infile.close();
	return true;}

void customer() {
	bool logIn = false;
	bool exitProgram = false;
	while (!exitProgram) {
		int choice;
		cout << endl;
		BoxesOfWords("Customer Membership");
		cout << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Sign up" << endl;
		cout << "2. Log in" << endl;
		cout << "3. Skip" << endl;
		cout << endl << string(120, char(175)) << endl;
		cout << "\nOption: ";
		cin >> choice;
		switch (choice) {
		case 1:
			customerSignUp();
			break;
		case 2:
			if (login())
				logIn = true;
			else
				break;
		case 3:
			menuChoice();
			break;
		default:
			cout << "Invalid option. Please enter a valid option." << endl;}
		if (logIn) {
			cout << "You are now logged in." << endl;
			cout << endl << string(120, char((175)));
			exitProgram = true;}}}

//staff login
void staffLogin() {
	ofstream outfile("staff.txt");
	outfile << "BurgerIsTheBest 1234567" << endl;
	outfile.close();
	bool loggedIn = false;
	while (!loggedIn) {
		string username, password;
		cout << "\nUsername: ";
		cin >> username;
		cout << "\nPassword: ";
		cin >> password;
		system("cls");
		if (check(username, password)) {
			cout << "Login successful. Welcome to Kurger Bing Restaurant Ordering System!" << endl;
			loggedIn = true;}
		else {
			cout << "Invalid username or password. Please try again." << endl << endl;
			loggedIn = false;}}}

int main(void) {
	system("cls");
	loadingbar();
	displayslogan();
	pwellcome();
	system("COLOR E0"); //change background colour
	int option = 1;
	while (option != 3) {
		system("cls");
		cout << string(120, char((176)));
		cout << "\n\n";
		cout << "\t\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
		displaycocacola();
		cout << "\nOption: ";
		if (!(cin >> option)) {
			cin.clear();
			cout << "\nInvalid option. " << endl;
			cin.ignore(100, '\n');}
		else
			mainmenu(option, 0);}
	return 0;}

//Decoration
void pwellcome(void) {
	system("cls");
	system("COLOR E0");
	char welcome1[40] = "WELCOME";
	char welcome2[40] = "TO";
	char welcome3[40] = "KURGER BING RESTAURANT";
	char welcome4[40] = "ORDERING SYSTEM";
	cout << string(120, char((176)));
	cout << "\n\n\n\t\t\t\t\t\t  ";
	for (int x = 0; x < strlen(welcome1); x++) {
		cout << " " << welcome1[x];
		Sleep(100);}
	cout << "\n\n\n\t\t\t\t\t\t\t";
	for (int y = 0; y < strlen(welcome2); y++) {
		cout << " " << welcome2[y];
		Sleep(100);}
	cout << "\n\n\n\t\t\t\t\t";
	for (int z = 0; z < strlen(welcome3); z++) {
		cout << " " << welcome3[z];
		Sleep(100);}
	cout << "\n\n\n    \t\t\t\t\t  ";
	for (int a = 0; a < strlen(welcome4); a++) {
		cout << " " << welcome4[a];
		Sleep(100);}
	cout << "\n\n\n" << string(120, char((176)));
	Sleep(450);
	cout << endl;}

void displayslogan(void) {
	cout << "\n\n\n\n" << endl;
	cout << string(2, ' ') << "                            |//|/|_/| " << endl;
	cout << string(2, ' ') << "                         |/||-|/||-/|/| " << endl;
	cout << string(2, ' ') << "		            //|/|//||///" << string(5, ' ') << "____   ___     _____  ___     ____   ___     ____   ___     ____   ___" << endl;
	cout << string(2, ' ') << "   _..----.._             ||//||//||||" << string(5, ' ') << "||=)  ||=||    ||  ) ||=||    ||=)  ||=||    ||=)  ||=||    ||=)  ||=||" << endl;
	cout << string(2, ' ') << " .'     o      '.         |||//|/|/ ||" << string(5, ' ') << "||_)) || ||    ||_// || ||    ||_)) || ||    ||_)) || ||    ||_)) || ||" << endl;
	cout << string(2, ' ') << "/      o       o /        | './|_/.' | " << endl;
	cout << string(2, ' ') << "| o        o     o|       |          | " << endl;
	cout << string(2, ' ') << "/ '-.._o      __.-'/      |          | " << endl;
	cout << string(2, ' ') << "/       `````      /      |          | " << endl;
	cout << string(2, ' ') << "| ``- - ........--'`|      '.______.' " << endl;
	cout << string(2, ' ') << "/                 /      " << endl;
	cout << string(2, ' ') << " `'--------- - '`" << endl;
	for (int x = 0; x < 25; x++)
		Sleep(100);}

void displaycocacola(void) {
	cout << string(5, ' ') << "       ,_," << endl;
	cout << string(5, ' ') << "       | | " << endl;
	cout << string(5, ' ') << "       | | " << string(25, ' ') << endl;
	cout << string(5, ' ') << "       | | " << string(25, ' ') << "Main Menu : " << endl;
	cout << string(5, ' ') << "       | | " << string(30, ' ');
	cout << endl << string(5, ' ') << "," << string(15, '-') << "," << string(30, ' ') << "1. Admin ";
	cout << endl << string(5, ' ') << "," << string(15, '-') << ",";
	cout << endl << string(5, ' ') << "|" << string(15, ' ') << "|" << string(30, ' ') << "2. Customer ";
	cout << endl << string(5, ' ') << "|" << string(15, ' ') << "|";
	cout << endl << string(5, ' ') << "|" << string(3, ' ') << "COCA COLA" << "   |" << string(30, ' ') << "3. Exit ";
	cout << endl << string(5, ' ') << "|" << string(15, ' ') << "|";
	cout << endl << string(5, ' ') << "|" << string(15, ' ') << "|";
	cout << endl << string(5, ' ') << "|" << string(15, ' ') << "|";
	cout << endl << string(5, ' ') << "`" << string(15, '-') << "`" << endl;
	cout << endl << string(120, char(176));}

void loadingbar(void) {
	for (int i = 15; i <= 100; i += 5) {
		system("cls");
		system("COLOR E"); //change front colour
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cout << i << "%" << " " << "Loading...";
		cout << " ";
		for (int j = 0; j < i; j += 2) {
			j;
			cout << " ";}
		Sleep(100);}}

//Display words with boxes
void BoxesOfWords(string words) {
	int length = words.length();
	cout << "\n";
	cout << "\t" << char(201);
	cout << string(length + 3, char(205));
	cout << char(187) << endl;
	cout << "\t" << char(186) << string(length + 3, ' ') << char(186) << endl;
	cout << "\t" << char(186) << " " << words << "  " << char(186) << endl;
	cout << "\t" << char(186) << string(length + 3, ' ') << char(186) << endl;
	cout << "\t" << char(200);
	cout << string(length + 3, char(205));
	cout << char(188) << endl;}

//Display return previous page
void returnpreviouspage(void) {
	cout << "Press any key to return.";
	getline(cin, pause);}

//main menu
void mainmenu(int option, int suboption) {
	switch (option) {
	case 1: //Admin
		cout << endl << string(120, char((175)));
		staffLogin();
		system("cls");
		cout << endl;
		cout << "             _              _  _  _  _           _           _           _  _  _          _           _     " << endl;
		cout << "           _(_)_           (_)(_)(_)(_)         (_) _     _ (_)         (_)(_)(_)        (_) _       (_)   " << endl;
		cout << "         _(_) (_)_          (_)      (_)_       (_)(_)   (_)(_)            (_)           (_)(_)_     (_)   " << endl;
		cout << "       _(_)     (_)_        (_)        (_)      (_) (_)_(_) (_)            (_)           (_)  (_)_   (_)   " << endl;
		cout << "      (_) _  _  _ (_)       (_)        (_)      (_)   (_)   (_)            (_)           (_)    (_)_ (_)   " << endl;
		cout << "      (_)(_)(_)(_)(_)       (_)       _(_)      (_)         (_)            (_)           (_)      (_)(_)   " << endl;
		cout << "      (_)         (_)       (_)_  _  (_)        (_)         (_)          _ (_) _         (_)         (_)  " << endl;
		cout << "      (_)         (_)      (_)(_)(_)(_)         (_)         (_)         (_)(_)(_)        (_)         (_)    " << endl;
		cout << endl << endl;
		cout << "   1. View Menu\t\t" << "| 2. Add Menu\t\t" << "| 3. Edit Menu\t\t" << "| 4. Delete Menu\t  " << "| 5. Main Menu" << endl;
		cout << endl << string(120, char(175)) << endl;
		cout << endl << "\n\nOption: ";
		cin >> suboption;
		if (suboption == 1)
			viewallmenu(option);
		else if (suboption == 2)
			selectaddmenu(option);
		else if (suboption == 3)
			selecteditmenu(option);
		else if (suboption == 4)
			seletedeletemenu(option);
		else if (suboption != 5) {
			cin.clear();
			cout << "\nInvalid option. Please type again. " << endl;
			cin.ignore(100, '\n');
			mainmenu(option, 0);}
		break;
	case 2: // Customer
		cout << endl << string(120, char((175)));
		system("cls");
		cout << endl << endl;
		cout << "        oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo " << endl;
		cout << "            a88888b.    dP     dP   .d88888b   d888888P   .88888.    8888ba.88ba    88888888b  888888ba   " << endl;
		cout << "           d8'   `88    88     88   88.    ''     88     d8'   `8b   88  `8b  `8b   88         88    `8b  " << endl;
		cout << "           88           88     88   `Y88888b.     88     88     88   88   88   88   a88aaaa    a88aaaa8P  " << endl;
		cout << "           88           88     88         `8b     88     88     88   88   88   88   88         88   `8b. " << endl;
		cout << "           Y8.   .88    Y8.   .8P   d8'   .8P     88     Y8.   .8P   88   88   88   88         88     88 " << endl;
		cout << "            Y88888P'    `Y88888P'    Y88888P      dP      `8888P'    dP   dP   dP   88888888P  dP     dP " << endl;
		cout << "      oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo " << endl;
		cout << endl << "\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
		customer();
		break;
	case 3:// Exit
		break;
	default:
		cout << "\nInvalid option. Please type again. " << endl;
		cin.ignore(100, '\n');
		returnpreviouspage();}}

//read recored in file
void readburgerinfile(void) {
	ifstream infile;
	infile.open("burgerlist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, index[i]);
			getline(infile, name[i]);
			infile >> price[i];
			infile.ignore();
			i++;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();}

void readbeverageinfile(void) {
	ifstream infile;
	infile.open("beveragelist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, beverageindex[i]);
			getline(infile, beveragename[i]);
			infile >> beverageprice[i];
			infile.ignore();
			i++;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();}

void readsideinfile(void) {
	ifstream infile;
	infile.open("sidelist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, sideindex[i]);
			getline(infile, sidename[i]);
			infile >> sideprice[i];
			infile.ignore();
			i++;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();}

//view menu (D)
void viewallmenu(int option) {
	string no;
	bool validNo;
	do {
		validNo = true;
		cout << endl << string(120, char((175)));
		BoxesOfWords("View Menu:");
		cout << endl;
		cout << "1. Burger Menu " << endl;
		cout << "2. Beverage Menu" << endl;
		cout << "3. Side Menu" << endl;
		cout << "\nPlease select which menu you want to view [1/2/3/ALL]: ";
		cin >> no;
		//change to uppercase
		for (int i = 0; i < no.length(); i++) {
			no[i] = toupper(no[i]);}
		if (no == "ALL") {
			displayburgermenu();
			system("pause");
			displaybeveragemenu();
			system("pause");
			displaysidemenu();
			returnpreviouspage();}
		else if (no == "1") {
			displayburgermenu();
			returnpreviouspage();}
		else if (no == "2") {
			displaybeveragemenu();
			returnpreviouspage();}
		else if (no == "3") {
			displaysidemenu();
			returnpreviouspage();}
		else {
			cout << "Invalid input. Please type again. " << endl;
			validNo = false;}
	} while (!validNo);
	cout << "\n" << string(120, '-') << endl;
	cout << endl;
	cin.ignore();
	system("cls");
	return mainmenu(1, 0);}

void displayburgermenu(void) {
	system("cls");
	cout << string(120, char(176)) << endl;
	cout << endl << "\t\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
	cout << "  \t\t\t\t    ======== Please Place Your Order Here ========" << endl;
	cout << "\n" << string(120, '=') << endl;
	cout << endl;
	ifstream infile;
	infile.open("burgerlist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, index[i]);
			getline(infile, name[i]);
			infile >> price[i];
			infile.ignore();
			i++;
			cout << showpoint << fixed << setprecision(2);
			cout << index[i - 1] << ":) " << name[i - 1] << endl;
			cout << setw(10) << "-> RM" << price[i - 1] << endl << endl;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();
	cout << string(120, '-') << endl;}

void displaybeveragemenu(void) {
	system("cls");
	cout << string(120, char(176)) << endl;
	cout << endl << "\t\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
	cout << "  \t\t\t\t    ======== Please Place Your Order Here ========" << endl;
	cout << "\n" << string(120, '=') << endl;
	cout << endl;
	ifstream infile;
	infile.open("beveragelist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, beverageindex[i]);
			getline(infile, beveragename[i]);
			infile >> beverageprice[i];
			infile.ignore();
			i++;
			cout << showpoint << fixed << setprecision(2);
			cout << beverageindex[i - 1] << ":) " << beveragename[i - 1] << endl;
			cout << setw(10) << "-> RM" << beverageprice[i - 1] << endl << endl;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();
	cout << string(120, '-') << endl;}

void displaysidemenu(void) {
	system("cls");
	cout << string(120, char(176)) << endl;
	cout << endl << "\t\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
	cout << "  \t\t\t\t    ======== Please Place Your Order Here ========" << endl;
	cout << "\n" << string(120, '=') << endl;
	cout << endl;
	ifstream infile;
	infile.open("sidelist.txt");
	int i = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, sideindex[i]);
			getline(infile, sidename[i]);
			infile >> sideprice[i];
			infile.ignore();
			i++;
			cout << showpoint << fixed << setprecision(2);
			cout << sideindex[i - 1] << ":) " << sidename[i - 1] << endl;
			cout << setw(10) << "-> RM" << sideprice[i - 1] << endl << endl;}}
	else
		cout << "Unable to open file" << endl;
	infile.close();
	cout << string(120, '-') << endl;}

//add menu (D)
void selectaddmenu(int option) {
	string no;
	bool ValidNo;
	do {
		ValidNo = true;
		BoxesOfWords("Add Menu: ");
		cout << endl;
		cout << "1. Burger Menu " << endl;
		cout << "2. Beverage Menu" << endl;
		cout << "3. Side Menu" << endl;
		cout << "4. Admin Menu" << endl;
		cout << "\nPlease select which menu that you want to ADD item [1/2/3/4]: ";
		cin >> no;
		if (no == "1")
			addburgermenu();
		else if (no == "2")
			addbeveragemenu();
		else if (no == "3")
			addsidemenu();
		else if (no == "4")
			mainmenu(1, 0);
		else {
			cout << "Invalid Input. Please type again. " << endl;
			ValidNo = false;}
	} while (!ValidNo);}

void addburgermenu() {
	ofstream outfile;
	outfile.open("burgerlist.txt", ios::app);
	int count = 0;
	string newindex, newname;
	double newprice;
	bool validformat = true, valid = true;
	do {
		validformat = true;
		displayburgermenu();
		cout << "Please enter index number that you want to add: ";
		cin >> newindex;
		readburgerinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (newindex == index[i]) {
				validformat = false;
				cout << "Index number entered has already exist. Please type again" << endl;
				system("pause");
				return addburgermenu();}}
		if (validformat = true) {
			cout << "Please enter the name (ingredient) that you want to add: ";
			cin.ignore();
			getline(cin, newname);
			cout << "Please enter the price that you want to add: RM";
			cin >> newprice;}
	} while (!validformat);
	count++;
	index[count - 1] = newindex;
	name[count - 1] = newname;
	price[count - 1] = newprice;
	//append item into file
	for (int i = 0; i < count; i++) {
		outfile << "\n" << index[i] << "\n" << name[i] << "\n" << price[i];}
	outfile.close();
	cout << endl;
	cout << "The item is ADDED SUCCESSFULLY !" << endl;
	do {
		cout << endl << string(120, char((175)));
		cout << "Do you want to ADD another item? (Y/N) : ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			addburgermenu();
		else if (toupper(cont) == 'N')
			mainmenu(1, 0);
		else {
			valid = false;
			cout << "Invalid input. Please type again" << endl;}
	} while (!valid);}

void addbeveragemenu() {
	ofstream outfile;
	outfile.open("beveragelist.txt", ios::app);
	int count = 0;
	string newindex, newname;
	double newprice;
	bool validformat = true, valid = true;
	do {
		validformat = true;
		displaybeveragemenu();
		cout << "Please enter index number that you want to add: ";
		cin >> newindex;
		readbeverageinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (newindex == beverageindex[i]) {
				validformat = false;
				cout << "Index number entered has already exist. Please type again" << endl;
				system("pause");
				return addbeveragemenu();}}
		if (validformat = true) {
			cout << "Please enter beverage name that you want to add: ";
			cin.ignore();
			getline(cin, newname);
			cout << "Please enter the price that you want to add: RM";
			cin >> newprice;}
	} while (!validformat);
	count++;
	beverageindex[count - 1] = newindex;
	beveragename[count - 1] = newname;
	beverageprice[count - 1] = newprice;
	//append item into file
	for (int i = 0; i < count; i++)
		outfile << "\n" << beverageindex[i] << "\n" << beveragename[i] << "\n" << beverageprice[i];
	outfile.close();
	cout << endl;
	cout << "The item is ADDED SUCCESSFULLY !" << endl;
	do {
		cout << endl << string(120, char((175)));
		cout << "Do you want to ADD another item? (Y/N) : ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			addbeveragemenu();
		else if (toupper(cont) == 'N')
			mainmenu(1, 0);
		else {
			valid = false;
			cout << "Invalid input. Please type again" << endl;}
	} while (!valid);}

void addsidemenu() {
	ofstream outfile;
	outfile.open("sidelist.txt", ios::app);
	int count = 0;
	string newindex, newname;
	double newprice;
	bool validformat = true, valid = true;
	do {
		validformat = true;
		displaysidemenu();
		cout << "Please enter index number that you want to add: ";
		cin >> newindex;
		readsideinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (newindex == sideindex[i]) {
				validformat = false;
				cout << "Index number entered has already exist. Please type again" << endl;
				system("pause");
				return addsidemenu();}}
		if (validformat = true) {
			cout << "Please enter beverage name that you want to add: ";
			cin.ignore();
			getline(cin, newname);
			cout << "Please enter the price that you want to add: RM";
			cin >> newprice;}
	} while (!validformat);
	count++;
	sideindex[count - 1] = newindex;
	sidename[count - 1] = newname;
	sideprice[count - 1] = newprice;
	//append item into file
	for (int i = 0; i < count; i++)
		outfile << "\n" << sideindex[i] << "\n" << sidename[i] << "\n" << sideprice[i];
	outfile.close();
	cout << endl;
	cout << "The item is ADDED SUCCESSFULLY !" << endl;
	do {
		cout << endl << string(120, char((175)));
		cout << "Do you want to ADD another item? (Y/N) : ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			addsidemenu();
		else if (toupper(cont) == 'N')
			mainmenu(1, 0);
		else {
			valid = false;
			cout << "Invalid input. Please type again" << endl;}
	} while (!valid);}

//delete menu
void seletedeletemenu(int option) {
	string no;
	bool ValidNo;
	do {
		ValidNo = true;
		BoxesOfWords("Delete Menu: ");
		cout << endl;
		cout << "1. Burger Menu " << endl;
		cout << "2. Beverage Menu" << endl;
		cout << "3. Side Menu" << endl;
		cout << "4. Admin Menu" << endl;
		cout << "\nPlease select which menu that you want to DELETE item [1/2/3/4]: ";
		cin >> no;
		if (no == "1")
			deleteburgermenu();
		else if (no == "2")
			deletebeveragemenu();
		else if (no == "3")
			deletesidemenu();
		else if (no == "4")
			return mainmenu(1, 0);
		else {
			cout << "Invalid Input. Please type again. " << endl;
			ValidNo = false;}
	} while (!ValidNo);}

//delete menu
void deleteburgermenu() {
	int count = 0, SIZE1 = 15;
	string deleteindex;
	bool foundit = true, valid = true;
	do {
		displayburgermenu();
		cout << "Please enter the index number that you want to delete: ";
		cin >> deleteindex;
		//check the item added is has exist in file anot
		readburgerinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (deleteindex == index[i]) {
				foundit = true;
				BoxesOfWords("Details Information That You Selected");
				cout << endl;
				cout << "Index Number : " << index[i] << endl;
				cout << "Name (Ingredient) : " << name[i] << endl;
				cout << "Price : RM" << price[i] << endl;
				char comfrim;
				do {
					cout << "\n" << "Are you comfirm to DELETE this item? (Y/N) :";
					cin >> comfrim;
					if (toupper(comfrim) == 'Y') {
						cout << endl;
						int count = 0;
						//reassign the array
						for (int j = i; j < SIZE1 - 1; j++) {
							index[j] = index[j + 1];
							name[j] = name[j + 1];
							price[j] = price[j + 1];}
						SIZE1--;
						rewriteinburgerfile();
						do {
							cout << endl << string(120, char((175)));
							cout << "Do you want to DELETE another item? (Y/N) : ";
							char cont;
							cin >> cont;
							cin.ignore();
							if (toupper(cont) == 'Y')
								deleteburgermenu();
							else if (toupper(cont) == 'N')
								mainmenu(1, 0);
							else {
								valid = false;
								cout << "Invalid input. Please type again" << endl;}
						} while (!valid);
					}
					else if (toupper(comfrim) == 'N')
						return returnpreviouspage();
					else
						cout << "Invalid Input" << endl;
				} while ((toupper(comfrim) == 'Y' && toupper(comfrim) == 'N'));
				cout << "Invalid input. Please type again" << endl;
				system("pause");}}
		cout << "\n" << "Invalid index number. Please type again" << endl << endl;
		system("pause");
	} while (!foundit);
	return deleteburgermenu();}

void deletebeveragemenu() {
	int count = 0, SIZE1 = 15;
	string deleteindex;
	bool foundit = true, valid = true;
	do {
		displaybeveragemenu();
		cout << "Please enter the index number that you want to delete: ";
		cin >> deleteindex;
		readbeverageinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (deleteindex == beverageindex[i]) {
				foundit = true;
				BoxesOfWords("Details Information That You Selected");
				cout << endl;
				cout << "Index Number : " << beverageindex[i] << endl;
				cout << "Name : " << beveragename[i] << endl;
				cout << "Price : RM" << beverageprice[i] << endl;
				char comfrim;
				do {
					cout << "\n" << "Are you comfirm to DELETE this item? (Y/N) :";
					cin >> comfrim;
					if (toupper(comfrim) == 'Y') {
						cout << endl;
						int count = 0;
						//reassign the array
						for (int j = i; j < SIZE1 - 1; j++) {
							beverageindex[j] = beverageindex[j + 1];
							beveragename[j] = beveragename[j + 1];
							beverageprice[j] = beverageprice[j + 1];}
						SIZE1--;
						rewriteinbeveragefile();
						cout << "The item is DELETED SUCCESSFULLY! " << endl;
						do {
							cout << endl << string(120, char((175)));
							cout << "Do you want to DELETE another item? (Y/N) : ";
							char cont;
							cin >> cont;
							cin.ignore();
							if (toupper(cont) == 'Y')
								deletebeveragemenu();
							else if (toupper(cont) == 'N')
								mainmenu(1, 0);
							else {
								valid = false;
								cout << "Invalid input. Please type again" << endl;}
						} while (!valid);
					}
					else if (toupper(comfrim) == 'N')
						return returnpreviouspage();
					else
						cout << "Invalid Input" << endl;
				} while ((toupper(comfrim) == 'Y' && toupper(comfrim) == 'N'));
				cout << "Invalid input. Please type again" << endl;
				system("pause"); }}
		cout << endl;
		cout << "Invalid index number. Please type again" << endl << endl;
		system("pause");
	} while (!foundit);
	return deletebeveragemenu();}

void deletesidemenu() {
	int count = 0, SIZE1 = 15;
	string deleteindex;
	bool foundit = true, valid = true;
	do {
		displaysidemenu();
		cout << "Please enter the index number that you want to delete: ";
		cin >> deleteindex;
		readsideinfile();
		//check index infile
		for (int i = 0; i < SIZE1; i++) {
			if (deleteindex == sideindex[i]) {
				foundit = true;
				BoxesOfWords("Details Information That You Selected");
				cout << endl;
				cout << "Index Number: " << sideindex[i] << endl;
				cout << "Name : " << sidename[i] << endl;
				cout << "Price : RM" << sideprice[i] << endl;
				char comfrim;
				do {
					cout << "\n" << "Are you comfirm to DELETE this item? (Y/N) :";
					cin >> comfrim;
					if (toupper(comfrim) == 'Y') {
						cout << endl;
						int count = 0;
						//reassign the array
						for (int j = i; j < SIZE1 - 1; j++) {
							sideindex[j] = sideindex[j + 1];
							sidename[j] = sidename[j + 1];
							sideprice[j] = sideprice[j + 1];}
						SIZE1--;
						rewriteinsidefile();
						cout << "The item is DELETED SUCCESSFULLY! " << endl;
						do {
							cout << endl << string(120, char((175)));
							cout << "Do you want to DELETE another item? (Y/N) : ";
							char cont;
							cin >> cont;
							cin.ignore();
							if (toupper(cont) == 'Y')
								deletesidemenu();
							else if (toupper(cont) == 'N')
								mainmenu(1, 0);
							else {
								valid = false;
								cout << "Invalid input. Please type again" << endl;}
						} while (!valid);
					}
					else if (toupper(comfrim) == 'N')
						return returnpreviouspage();
					else
						cout << "Invalid Input" << endl;
				} while ((toupper(comfrim) == 'Y' && toupper(comfrim) == 'N'));
				cout << "Invalid input. Please type again" << endl;}}
		cout << endl;
		cout << "Invalid index number. Please type again" << endl << endl;
		system("pause");
	} while (!foundit);
	return deletesidemenu();}

//edit menu (D)
void selecteditmenu(int option) {
	string no;
	bool ValidNo;
	do {
		ValidNo = true;
		BoxesOfWords("Edit Menu: ");
		cout << endl;
		cout << "1. Burger Menu " << endl;
		cout << "2. Beverage Menu" << endl;
		cout << "3. Side Menu" << endl;
		cout << "4. Admin Menu" << endl;
		cout << "\nPlease select which menu that you want to EDIT item [1/2/3/4]: ";
		cin >> no;
		if (no == "1")
			editburgermenu(0, 0);
		else if (no == "2")
			editbeveragemenu(0, 0);
		else if (no == "3")
			editsidemenu(0, 0);
		else if (no == "4")
			return mainmenu(1, 0);
		else {
			cout << "Invalid Input. Please type again. " << endl;
			ValidNo = false;}
	} while (!ValidNo);
	cout << "\n" << string(120, '-') << endl;
	cout << endl;}

void editburgermenu(int option, int suboption) {
	int foundit = 0;
	string oldindex;
	displayburgermenu();
	BoxesOfWords("Edit: ");
	cout << "\n" << "Enter index number that you want to make changes: ";
	cin >> oldindex;
	readburgerinfile();
	//check index infile
	for (int i = 0; i < SIZE1; i++) {
		if (oldindex == index[i]) {
			foundit++;
			select_burger_details_to_edit(i);}}
	if (foundit == 0) {
		cout << "Index number entered does not exist. Please type again" << endl;
		return editburgermenu(option, suboption);}}

void select_burger_details_to_edit(int editedIndex) {
	//initialise 1 so can go inside the loop
	int editoption = 1, SIZE = 15;
	string oldIndex, newIndex, newName;
	double newPrice;
	bool checkIndex = true, valid = true, validP = true;
	while (editoption != 4) {
		BoxesOfWords("Details Information That You Selected");
		cout << endl;
		cout << "Index number entered: " << index[editedIndex] << endl;
		cout << "Name: " << name[editedIndex] << endl;
		cout << "Price: RM" << price[editedIndex] << endl;
		cout << endl;
		//ask user which want they want to edit
		cout << endl;
		cout << "Which information that you want to update? " << endl;
		cout << "1. Index Number " << endl;
		cout << "2. Name " << endl;
		cout << "3. Price " << endl;
		cout << "4. Admin Menu " << endl;
		cout << endl << string(120, char((175)));
		cout << "Option: ";
		cin >> editoption;
		readburgerinfile();
		if (editoption == 1) {
			do {
				checkIndex = true;
				cout << "\n" << "Enter new index number : ";
				cin >> newIndex;
				int i = 0;
				ifstream infile;
				infile.open("burgerlist.txt");
				if (infile.is_open()) {
					while (!infile.eof()) {
						getline(infile, index[i]);
						getline(infile, name[i]);
						infile >> price[i];
						infile.ignore();
						i++;
						if (i != editedIndex && newIndex == index[i]) {
							checkIndex = false;
							cout << "\n" << "The index number entered has already exists. Please type again" << endl;
							cout << endl << string(120, char((175)));}}
					infile.close();}
				else
					cout << "Unable to open file" << endl;
			} while (!checkIndex);
			if (checkIndex = true) {
				index[editedIndex] = newIndex;
				cout << endl;
				BoxesOfWords("Updated Information");
				cout << endl;
				cout << "Index number: " << index[editedIndex] << endl;
				cout << "Name: " << name[editedIndex] << endl;
				cout << "Price: RM" << price[editedIndex] << endl;
				cout << endl;
				cout << "The item is UPDATED SUCCESSFULLY !" << endl;
				rewriteinburgerfile();
				//ask user continue to edit item
				do {
					cout << endl << string(120, char((175)));
					cout << "Do you want to EDIT another item? (Y/N) : ";
					char cont;
					cin >> cont;
					cin.ignore();
					if (toupper(cont) == 'Y')
						editburgermenu(0, 0);
					else if (toupper(cont) == 'N')
						mainmenu(1, 0);
					else {
						valid = false;
						cout << "Invalid input. Please type again" << endl;}
				} while (!valid);}}
		else if (editoption == 2) {
			cout << endl << string(120, char((175)));
			cout << "\n" << "Enter new item name (ingredient) :";
			cin.ignore();
			getline(cin, newName);
			name[editedIndex] = newName;
			cout << endl;
			BoxesOfWords("Updated Information");
			cout << endl;
			cout << "Index number: " << index[editedIndex] << endl;
			cout << "Name: " << name[editedIndex] << endl;
			cout << "Price: RM" << price[editedIndex] << endl;
			cout << endl;
			cout << "The item is UPDATED SUCCESSFULLY! " << endl;
			rewriteinburgerfile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editburgermenu(0, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else if (editoption == 3) {
			do {
				cout << endl << string(120, char((175)));
				cout << "\n" << "Enter new price: RM ";
				cin >> newPrice;
				if (newPrice > 0 && newPrice < 100) {
					validP = true;
					price[editedIndex] = newPrice;
					cout << endl;
					BoxesOfWords("Updated Information");
					cout << endl;
					cout << "Index number: " << index[editedIndex] << endl;
					cout << "Name: " << name[editedIndex] << endl;
					cout << "Price: RM" << price[editedIndex] << endl;
					cout << endl;
					cout << "The item is UPDATED SUCCESSFULLY! " << endl;}
				else {
					validP = false;
					cout << "Invali input. Please type again" << endl;}
			} while (!validP);
			rewriteinburgerfile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editburgermenu(0, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else
			return mainmenu(1, 0);}}

void rewriteinburgerfile() {
	ofstream outfile;
	outfile.open("burgerlist.txt");
	for (int j = 0; j < SIZE1; j++) {
		if (index[j] == " " || name[j] == " " || price[j] == 0) {
			outfile.close();
			continue;}
		else if (index[j] == index[0])
			outfile << index[j] << "\n" << name[j] << "\n" << price[j];
		else
			outfile << "\n" << index[j] << "\n" << name[j] << "\n" << price[j];
		if (index[j + 1] != "")
			outfile << "";}}

void editbeveragemenu(int option, int suboption) {
	int foundit = 0;
	string oldindex;
	displaybeveragemenu();
	BoxesOfWords("Edit: ");
	cout << "\n" << "Enter index number that you want to make changes: ";
	cin >> oldindex;
	readbeverageinfile();
	//check index infile
	for (int i = 0; i < SIZE1; i++) {
		if (oldindex == beverageindex[i]) {
			foundit++;
			select_beverage_details_to_edit(i);}}
	if (foundit == 0) {
		cout << "Index number entered does not exist. Please type again" << endl;
		return editbeveragemenu(option, suboption);}}

void select_beverage_details_to_edit(int editedIndex) {
	//initialise 1 so can go inside the loop
	int editoption = 1, SIZE = 15;
	string oldIndex, newIndex, newName;
	double newPrice;
	bool checkIndex = true, valid = true, validP = true;
	while (editoption != 4) {
		BoxesOfWords("Details Information That You Selected");
		cout << endl;
		cout << "Index number entered: " << beverageindex[editedIndex] << endl;
		cout << "Name: " << beveragename[editedIndex] << endl;
		cout << "Price: RM" << beverageprice[editedIndex] << endl;
		cout << endl;
		//ask user which want they want to edit
		cout << endl;
		cout << "Which information that you want to update? " << endl;
		cout << "1. Index Number " << endl;
		cout << "2. Name " << endl;
		cout << "3. Price " << endl;
		cout << "4. Admin Menu " << endl;
		cout << endl << string(120, char((175)));
		cout << "Option: ";
		cin >> editoption;
		readbeverageinfile();
		if (editoption == 1) {
			do {
				checkIndex = true;
				cout << "\n" << "Enter new index number : ";
				cin >> newIndex;
				int i = 0;
				ifstream infile;
				infile.open("beveragelist.txt");
				if (infile.is_open()) {
					while (!infile.eof()) {
						getline(infile, beverageindex[i]);
						getline(infile, beveragename[i]);
						infile >> beverageprice[i];
						infile.ignore();
						i++;
						if (i != editedIndex && newIndex == beverageindex[i]) {
							checkIndex = false;
							cout << "\n" << "The index number entered has already exists. Please type again" << endl;
							cout << endl << string(120, char((175)));}
					}infile.close();}
				else
					cout << "Unable to open file" << endl;
			} while (!checkIndex);
			if (checkIndex = true) {
				beverageindex[editedIndex] = newIndex;
				cout << endl;
				BoxesOfWords("Updated Information");
				cout << endl;
				cout << "Index number: " << beverageindex[editedIndex] << endl;
				cout << "Name: " << beveragename[editedIndex] << endl;
				cout << "Price: RM" << beverageprice[editedIndex] << endl;
				cout << endl;
				cout << "The item is UPDATED SUCCESSFULLY !" << endl;
				rewriteinbeveragefile();
				//ask user continue to edit item
				do {
					cout << endl << string(120, char((175)));
					cout << "Do you want to EDIT another item? (Y/N) : ";
					char cont;
					cin >> cont;
					cin.ignore();
					if (toupper(cont) == 'Y')
						editbeveragemenu(0, 0);
					else if (toupper(cont) == 'N')
						mainmenu(1, 0);
					else {
						valid = false;
						cout << "Invalid input. Please type again" << endl;}
				} while (!valid);}}
		else if (editoption == 2) {
			cout << endl << string(120, char((175)));
			cout << "\n" << "Enter new item name (ingredient) :";
			cin.ignore();
			getline(cin, newName);
			beveragename[editedIndex] = newName;
			cout << endl;
			BoxesOfWords("Updated Information");
			cout << endl;
			cout << "Index number: " << beverageindex[editedIndex] << endl;
			cout << "Name: " << beveragename[editedIndex] << endl;
			cout << "Price: RM" << beverageprice[editedIndex] << endl;
			cout << endl;
			cout << "The item is UPDATED SUCCESSFULLY! " << endl;
			rewriteinbeveragefile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editbeveragemenu(0, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else if (editoption == 3) {
			do {
				cout << endl << string(120, char((175)));
				cout << "\n" << "Enter new price: RM ";
				cin >> newPrice;
				if (newPrice > 0 && newPrice < 100) {
					validP = true;
					beverageprice[editedIndex] = newPrice;
					cout << endl;
					BoxesOfWords("Updated Information");
					cout << endl;
					cout << "Index number: " << beverageindex[editedIndex] << endl;
					cout << "Name: " << beveragename[editedIndex] << endl;
					cout << "Price: RM" << beverageprice[editedIndex] << endl;
					cout << endl;
					cout << "The item is UPDATED SUCCESSFULLY! " << endl;}
				else {
					validP = false;
					cout << "Invali input. Please type again" << endl;}
			} while (!validP);
			rewriteinbeveragefile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editbeveragemenu(1, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else
			return mainmenu(1, 0);}}

void rewriteinbeveragefile() {
	ofstream outfile;
	outfile.open("beveragelist.txt");
	for (int j = 0; j < SIZE1; j++) {
		if (beverageindex[j] == " " || beveragename[j] == " " || beverageprice[j] == 0) {
			outfile.close();
			continue;}
		else if (beverageindex[j] == beverageindex[0])
			outfile << beverageindex[j] << "\n" << beveragename[j] << "\n" << beverageprice[j];
		else
			outfile << "\n" << beverageindex[j] << "\n" << beveragename[j] << "\n" << beverageprice[j];
		if (beverageindex[j + 1] != "")
			outfile << "";}}

void editsidemenu(int option, int suboption) {
	int foundit = 0;
	string oldindex;
	displaysidemenu();
	BoxesOfWords("Edit: ");
	cout << "\n" << "Enter index number that you want to make changes: ";
	cin >> oldindex;
	readsideinfile();
	//check index infile
	for (int i = 0; i < SIZE1; i++) {
		if (oldindex == sideindex[i]) {
			foundit++;
			select_side_details_to_edit(i);}}
	if (foundit == 0) {
		cout << "Index number entered does not exist. Please type again" << endl;
		return editsidemenu(option, suboption);}}

void select_side_details_to_edit(int editedIndex) {
	//initialise 1 so can go inside the loop
	int editoption = 1, SIZE = 15;
	string oldIndex, newIndex, newName;
	double newPrice;
	bool checkIndex = true, valid = true, validP = true;
	while (editoption != 4) {
		BoxesOfWords("Details Information That You Selected");
		cout << endl;
		cout << "Index number entered: " << sideindex[editedIndex] << endl;
		cout << "Name: " << sidename[editedIndex] << endl;
		cout << "Price: RM" << sideprice[editedIndex] << endl;
		cout << endl;
		//ask user which want they want to edit
		cout << endl;
		cout << "Which information that you want to update? " << endl;
		cout << "1. Index Number " << endl;
		cout << "2. Name " << endl;
		cout << "3. Price " << endl;
		cout << "4. Admin Menu " << endl;
		cout << endl << string(120, char((175)));
		cout << "Option: ";
		cin >> editoption;
		readsideinfile();
		if (editoption == 1) {
			do {
				checkIndex = true;
				cout << "\n" << "Enter new index number : ";
				cin >> newIndex;
				int i = 0;
				ifstream infile;
				infile.open("sidelist.txt");
				if (infile.is_open()) {
					while (!infile.eof()) {
						getline(infile, sideindex[i]);
						getline(infile, sidename[i]);
						infile >> sideprice[i];
						infile.ignore();
						i++;
						if (i != editedIndex && newIndex == sideindex[i]) {
							checkIndex = false;
							cout << "\n" << "The index number entered has already exists. Please type again" << endl;
							cout << endl << string(120, char((175)));}
					}infile.close();}
				else
					cout << "Unable to open file" << endl;
			} while (!checkIndex);
			if (checkIndex = true) {
				sideindex[editedIndex] = newIndex;
				cout << endl;
				BoxesOfWords("Updated Information");
				cout << endl;
				cout << "Index number: " << sideindex[editedIndex] << endl;
				cout << "Name: " << sidename[editedIndex] << endl;
				cout << "Price: RM" << sideprice[editedIndex] << endl;
				cout << endl;
				cout << "The item is UPDATED SUCCESSFULLY !" << endl;
				rewriteinsidefile();
				//ask user continue to edit item
				do {
					cout << endl << string(120, char((175)));
					cout << "Do you want to EDIT another item? (Y/N) : ";
					char cont;
					cin >> cont;
					cin.ignore();
					if (toupper(cont) == 'Y')
						editsidemenu(0, 0);
					else if (toupper(cont) == 'N')
						mainmenu(1, 0);
					else {
						valid = false;
						cout << "Invalid input. Please type again" << endl;}
				} while (!valid);}}
		else if (editoption == 2) {
			cout << endl << string(120, char((175)));
			cout << "\n" << "Enter new item name (ingredient) :";
			cin.ignore();
			getline(cin, newName);
			sidename[editedIndex] = newName;
			cout << endl;
			BoxesOfWords("Updated Information");
			cout << endl;
			cout << "Index number: " << sideindex[editedIndex] << endl;
			cout << "Name: " << sidename[editedIndex] << endl;
			cout << "Price: RM" << sideprice[editedIndex] << endl;
			cout << endl;
			cout << "The item is UPDATED SUCCESSFULLY! " << endl;
			rewriteinsidefile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editsidemenu(0, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else if (editoption == 3) {
			do {
				cout << endl << string(120, char((175)));
				cout << "\n" << "Enter new price: RM ";
				cin >> newPrice;
				if (newPrice > 0 && newPrice < 100) {
					validP = true;
						sideprice[editedIndex] = newPrice;
						cout << endl;
						BoxesOfWords("Updated Information");
						cout << endl;
						cout << "Index number: " << sideindex[editedIndex] << endl;
						cout << "Name: " << sidename[editedIndex] << endl;
						cout << "Price: RM" << sideprice[editedIndex] << endl;
						cout << endl;
						cout << "The item is UPDATED SUCCESSFULLY! " << endl; }
				else {
					validP = false;
					cout << "Invali input. Please type again" << endl;}
			} while (!validP);
			rewriteinsidefile();
			//ask user continue to edit item
			do {
				cout << endl << string(120, char((175)));
				cout << "Do you want to EDIT another item? (Y/N) : ";
				char cont;
				cin >> cont;
				cin.ignore();
				if (toupper(cont) == 'Y')
					editsidemenu(0, 0);
				else if (toupper(cont) == 'N')
					mainmenu(1, 0);
				else {
					valid = false;
					cout << "Invalid input. Please type again" << endl;}
			} while (!valid);}
		else
			return mainmenu(1, 0);}}

void rewriteinsidefile() {
	ofstream outfile;
	outfile.open("sidelist.txt");
	for (int j = 0; j < SIZE1; j++) {
		if (sideindex[j] == " " || sidename[j] == " " || sideprice[j] == 0) {
			outfile.close();
			continue;}
		else if (sideindex[j] == sideindex[0])
			outfile << sideindex[j] << "\n" << sidename[j] << "\n" << sideprice[j];
		else
			outfile << "\n" << sideindex[j] << "\n" << sidename[j] << "\n" << sideprice[j];
		if (sideindex[j + 1] != "")
			outfile << "";}}

void menuChoice() { //display customer main menu list
	bool validchoice;
	do {
		validchoice = true;
		system("COLOR E0");
		system("cls");
		cout << string(120, char(176)) << endl;
		cout << endl << "\t\t\t\t========= Welcome to Kinger Bing Restaurant ========= " << endl;
		cout << "\n\t\t\t===================================================================" << endl;
		cout << "\t\t\t\tWhat would you like to order?" << endl;
		cout << "\t\t\t\t1. Burger" << endl;
		cout << "\t\t\t\t2. Beverage" << endl;
		cout << "\t\t\t\t3. Side" << endl;
		cout << "\t\t\t\t4. Conclude order" << endl << endl;
		cout << "\t\t\t\t\t\tOTHERS: " << endl;
		cout << "\t\t\t\t\t5. View current order" << endl;
		cout << "\t\t\t\t\t6. Edit order" << endl;
		cout << "\t\t\t\t\t7. Delete order" << endl;
		cout << "\t\t\t================================================================" << endl;
		cout << "Your holy choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
			orderFood();
		else if (choice == 2)
			orderBeverage();
		else if (choice == 3)
			orderSide();
		else if (choice == 4)
			orderDetails();
		else if (choice == 5)
			viewOrder();
		else if (choice == 6)
			editOrder();
		else if (choice == 7)
			deleteOrder();
		else {
			errorMessage2();
			validchoice = false;}
	} while (!validchoice);}

void orderFood() { //order food section
	int quantity, notFoundB = 0;
	bool valid = true;
	string burgerindex;
	double totalorderprice;
	do {
		system("cls");
		system("COLOR E0");
		displayburgermenu();
		cout << "\n\t******************************************************" << endl;
		cout << "\t***                                                ***" << endl;
		cout << "\t*****      What would you like to eat today?     *****" << endl;
		cout << "\t***                                                ***" << endl;
		cout << "\t******************************************************" << endl;
		cout << "Your holy choice: ";
		cin >> burgerindex;
		cin.ignore();
		cout << endl;
		for (int i = 0; i < SIZE1; i++) {
			readburgerinfile();
			if (burgerindex == index[i]) {
				burgerOrderNo++;
				valid = true;
				cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
				cout << "How many would you like?: ";
				cin >> quantity;
				cin.ignore();
				BoxesOfWords("Selected Item");
				cout << endl;
				cout << index[i] << ":) " << name[i] << endl;
				cout << endl;
				cout << string(120, '-') << endl;
				cout << "Amount selected: " << quantity << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << price[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (price[i] * quantity) << endl;
				totalorderprice = price[i] * quantity;
				burgerOrder[burgerOrderNo - 1].orderindex = index[i];
				newIndex++;
				burgerOrder[burgerOrderNo - 1].newOrderIndex = newIndex;
				burgerOrder[burgerOrderNo - 1].ordername = name[i];
				burgerOrder[burgerOrderNo - 1].orderquantity = quantity;
				burgerOrder[burgerOrderNo - 1].totalorderprice = totalorderprice;
				writingSentence();
				break;}
			else {
				valid = false;
				notFoundB++;
				if (notFoundB == SIZE1) {
					errorMessage();
					notFoundB = 0;}}}
	} while (!valid);
	do {
		cout << "\n\n\t\t\t\tDo you want to continue ordering burgers? [Y-YES / N-NO]: ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			orderFood();
		else if (toupper(cont) == 'N')
			menuChoice();
		else {
			valid = false;
			errorMessage3();}
	} while (!valid);}

void orderBeverage() { //order beverage section
	int quantity, notFoundD = 0;
	bool valid = true;
	string bindex;
	double totalorderprice;
	do {
		system("cls");
		system("COLOR E0");
		displaybeveragemenu();
		cout << "\n\t******************************************************" << endl;
		cout << "\t***                                                ***" << endl;
		cout << "\t*****      What would you like to drink today?   *****" << endl;
		cout << "\t***                                                ***" << endl;
		cout << "\t******************************************************" << endl;
		cout << "Your holy choice: ";
		cin >> bindex;
		cin.ignore();
		cout << endl;
		for (int i = 0; i < SIZE1; i++) {
			readbeverageinfile();
			if (bindex == beverageindex[i]) {
				beverageOrderNo++;
				valid = true;
				cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
				cout << "How many would you like?: ";
				cin >> quantity;
				cin.ignore();
				BoxesOfWords("Selected Item");
				cout << endl;
				cout << beverageindex[i] << ":) " << beveragename[i] << endl;
				cout << endl;
				cout << string(120, '-') << endl;
				cout << "Amount selected: " << quantity << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << beverageprice[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (beverageprice[i] * quantity) << endl;
				totalorderprice = beverageprice[i] * quantity;
				beverageOrder[beverageOrderNo - 1].orderindex = bindex;
				newIndex2++;
				beverageOrder[beverageOrderNo - 1].newOrderIndex = newIndex2;
				beverageOrder[beverageOrderNo - 1].ordername = beveragename[i];
				beverageOrder[beverageOrderNo - 1].orderquantity = quantity;
				beverageOrder[beverageOrderNo - 1].totalorderprice = totalorderprice;
				writingSentence();
				break;}
			else {
				valid = false;
				notFoundD++;
				if (notFoundD == SIZE1) {
					errorMessage();
					notFoundD = 0;}}}
	} while (!valid);
	do {
		cout << "\n\n\t\t\t\tDo you want to continue ordering beverage? [Y-YES / N-NO]: ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			orderBeverage();
		else if (toupper(cont) == 'N')
			menuChoice();
		else {
			valid = false;
			errorMessage3();}
	} while (!valid);}

void orderSide() { //order side section
	int quantity, notFoundS = 0;
	bool valid = true;
	string sindex;
	double totalorderprice;
	do {
		system("cls");
		system("COLOR E0");
		displaysidemenu();
		cout << "\n\t********************************************************" << endl;
		cout << "\t***                                                  ***" << endl;
		cout << "\t*****      What side would you like to add to      *****" << endl;
		cout << "\t*****               top up your day?               *****" << endl;
		cout << "\t***                                                  ***" << endl;
		cout << "\t********************************************************" << endl;
		cout << "Your holy choice: ";
		cin >> sindex;
		cin.ignore();
		cout << endl;
		for (int i = 0; i < SIZE1; i++) {
			readsideinfile();
			if (sindex == sideindex[i]) {
				sideOrderNo++;
				valid = true;
				cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
				cout << "How many would you like?: ";
				cin >> quantity;
				cin.ignore();
				BoxesOfWords("Selected Item");
				cout << endl;
				cout << sideindex[i] << ":) " << sidename[i] << endl;
				cout << endl;
				cout << string(120, '-') << endl;
				cout << "Amount selected: " << quantity << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << sideprice[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (sideprice[i] * quantity) << endl;
				totalorderprice = sideprice[i] * quantity;
				sideOrder[sideOrderNo - 1].orderindex = sindex;
				newIndex3++;
				sideOrder[sideOrderNo - 1].newOrderIndex = newIndex3;
				sideOrder[sideOrderNo - 1].ordername = sidename[i];
				sideOrder[sideOrderNo - 1].orderquantity = quantity;
				sideOrder[sideOrderNo - 1].totalorderprice = totalorderprice;
				writingSentence();
				break;}
			else {
				valid = false;
				notFoundS++;
				if (notFoundS == SIZE1) {
					errorMessage();
					notFoundS = 0;}}}
	} while (!valid);
	do {
		cout << "\n\n\t\t\t\tDo you want to continue ordering side? [Y-YES / N-NO]: ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			orderSide();
		else if (toupper(cont) == 'N')
			menuChoice();
		else {
			valid = false;
			errorMessage3();}
	} while (!valid);}

void orderDetails() { //concluding order
	srand((unsigned)time(NULL));
	int randomno = 1000 + (rand() % 3001);  //generate random numbers for order number
	double orderTotal = 0;
	bool valid = true;
	system("cls");
	system("COLOR E0");
	cout << underline << "\nTo conclude your order, here's a list of stuff you have ordered: " << "\033[0m" << endl; //underline sentence, \033[0m is for termination of underline
	cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
	for (int i = 0; i < burgerOrderNo; i++) {
		cout << "\t\t" << i + 1 << ":) " << burgerOrder[i].ordername << endl;
		cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
		cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
		orderTotal += burgerOrder[i].totalorderprice;}
	cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
	for (int j = 0; j < beverageOrderNo; j++) {
		cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
		cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
		cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
		orderTotal += beverageOrder[j].totalorderprice;}
	cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
	for (int k = 0; k < sideOrderNo; k++) {
		cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
		cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
		cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
		orderTotal += sideOrder[k].totalorderprice;}
	cout << "\n\n\t\t\t\tGrand total: RM" << orderTotal;

	if (customerLogin == true) {
		cout << "\n\t\t\t\tYou have login as our restaurant membership, so here's a discount for you!" << endl;
		cout << "\n\t\t\t\tMembership discount: 30%" << endl;
		cout << "\n\t\t\t\tFinal payment: RM" << orderTotal * 0.70 << endl;}
	else {
		cout << "\n\t\t\t\tYou are not a membership of our restaurant so no discount is given." << endl;
		cout << "\n\t\t\t\tMembership discount: -" << endl;
		cout << "\n\t\t\t\tFinal payment: RM" << orderTotal << endl;}
	do {
		cout << "\n\t\t\t\tHow do you want to make your payment?" << endl;
		cout << "\t\t\t\t1. By cash (pay at counter)" << endl;
		cout << "\t\t\t\t2. By card (credit / debit)" << endl;
		cout << "\t\t\t\t3. By TNG (Touch n Go)" << endl;
		cout << "\t\t\t\tPayment method: ";
		cin >> method;
		cin.ignore();
		switch (method) {
		case 1: {
			cout << "\n\n\t\t\t\tThank you for your visit and support to our restaurant!" << endl;
			cout << "\t\t\t\tPlease proceed your payment with your order number " << underline << randomno << "\033[0m";
			cout << " at the counter!" << endl;
			cout << "\n\n\t\t\t\t\tWe hope to see you again!" << endl;
			exit(0);}
		case 2: {
			cout << "\n\n\t\t\t\tPlease enter your bank card number : ";
			cin >> bankno;
			cin.ignore();
			cout << "\n\n\t\t\t\tPlease enter your card password: ";
			cin >> bankpass;
			cin.ignore();
			loadScreen();
			system("COLOR 0A");
			cout << "\n\n\tPayment successful! Please wait at the pick up counter for your order with the order number " << underline << randomno << "\033[0m";
			system("COLOR 0A");
			cout << ", thank you!" << endl;
			cout << "\n\n\t\t\t\t\tWe hope to see you again!" << endl;
			exit(0);}
		case 3: {
			cout << "\n\n\t\t\t\tPlease enter your phone number : ";
			cin >> phoneno;
			cin.ignore();
			cout << "\n\n\t\t\t\tPlease enter your pin number: ";
			cin >> phonepin;
			cin.ignore();
			loadScreen();
			system("COLOR 0A");
			cout << "\n\n\tPayment successful! Please wait at the pick up counter for your order with the order number " << underline << randomno << "\033[0m";
			system("COLOR 0A");
			cout << ", thank you!" << endl;
			cout << "\n\n\t\t\t\t\tWe hope to see you again!" << endl;
			exit(0);}
		default: {
			valid = false;
			errorMessage2();
			break;}}
	} while (!valid);}

void viewOrder() { //view current order
	system("cls");
	system("COLOR E0");
	double orderTotal = 0;
	char exitChoice;
	bool valid = true;
	cout << underline << "\n\nHere's your order so far: " << "\033[0m" << endl;
	cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
	for (int i = 0; i < burgerOrderNo; i++) {
		cout << "\t\t" << i + 1 << ":) " << burgerOrder[i].ordername << endl;
		cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
		cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
		orderTotal += burgerOrder[i].totalorderprice;}
	cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
	for (int j = 0; j < beverageOrderNo; j++) {
		cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
		cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
		cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
		orderTotal += beverageOrder[j].totalorderprice;}
	cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
	for (int k = 0; k < sideOrderNo; k++) {
		cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
		cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
		cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
		orderTotal += sideOrder[k].totalorderprice;}
	do {
		cout << "\n\n\t\t\t\tPress E to exit view order page: ";
		cin >> exitChoice;
		cin.ignore();
		if (toupper(exitChoice) == 'E')
			menuChoice();
		else {
			valid = false;
			cout << "\n\t\t\t\tPlease enter E to exit!" << endl;}
	} while (!valid);}

void editOrder() { //edit specific order according to user input
	system("cls");
	system("COLOR E0");
	int editno, editchoice, newBurQuan, newBevQuan, newSideQuan, notFoundE = 0;
	string newBur, newBev, newSide;
	double newBurPrice, newBevPrice, newSidePrice, newOrderTotal = 0, orderTotal = 0;
	bool valid = true;
	cout << underline << "\n\nHere's your order so far: " << "\033[0m" << endl;
	cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
	for (int i = 0; i < burgerOrderNo; i++) {
		cout << "\t\t" << i + 1 << ":) " << burgerOrder[i].ordername << endl;
		cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
		cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
		orderTotal += burgerOrder[i].totalorderprice;}
	cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
	for (int j = 0; j < beverageOrderNo; j++) {
		cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
		cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
		cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
		orderTotal += beverageOrder[j].totalorderprice;}
	cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
	for (int k = 0; k < sideOrderNo; k++) {
		cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
		cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
		cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
		orderTotal += sideOrder[k].totalorderprice;}
	do {
		cout << "\n\n\t\t\tWhich order would you like to edit?" << endl;
		cout << "\n\n\t\t\t1. Burger" << endl;
		cout << "\n\n\t\t\t2. Beverage" << endl;
		cout << "\n\n\t\t\t3. Side" << endl;
		cout << "\n\n\t\t\tEdit: ";
		cin >> editno;
		cin.ignore();
		if (editno == 1) {
			cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
			for (int i = 0; i < burgerOrderNo; i++) {
				cout << "\t\t" << i + 1 << ".) " << burgerOrder[i].ordername << endl;
				cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
				cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
				orderTotal += burgerOrder[i].totalorderprice;}
			cout << "\n\n\t\tWhich order would you like to edit?" << endl;
			cout << "\n\n\t\tYour holy choice: ";
			cin >> editchoice;
			cin.ignore();
			cout << endl;
			for (int i = 0; i < burgerOrderNo; i++) {
				if (editchoice == burgerOrder[i].newOrderIndex) {
					int pos = i;  //set position to the index that is found in newOrderIndex
					displayburgermenu();
					cout << "\n\nChoose your new desired burger: ";
					cin >> newBur;
					cin.ignore();
					cout << "\n\nChoose your new quantity: ";
					cin >> newBurQuan;
					cin.ignore();
					for (int i = 0; i < SIZE1; i++) {
						readburgerinfile();
						if (newBur == index[i]) {
							valid = true;
							cout << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << "\t\t\tEdited Order" << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << index[i] << ":) " << name[i] << endl;
							cout << endl;
							cout << string(120, '-') << endl;
							cout << "Amount selected: " << newBurQuan << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << sideprice[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (sideprice[i] * newBurQuan) << endl;
							//replacing old values to new values
							newOrderTotal = price[i] * newBurQuan;
							burgerOrder[editchoice - 1].orderindex = index[i];
							burgerOrder[editchoice - 1].newOrderIndex = pos;
							burgerOrder[editchoice - 1].ordername = name[i];
							burgerOrder[editchoice - 1].orderquantity = newBurQuan;
							burgerOrder[editchoice - 1].totalorderprice = newOrderTotal;
							orderTotal += burgerOrder[editchoice - 1].totalorderprice;
							writingSentence3();
							break;}
						else {
							valid = false;
							notFoundE++;
							if (notFoundE == SIZE1) {
								errorMessage();
								notFoundE = 0;}}}
					break;}
				else {
					valid = false;
					notFoundE++;
					if (notFoundE == burgerOrderNo) {
						errorMessage();
						notFoundE = 0;}}}
			break;}
		else if (editno == 2) {
			cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
			for (int j = 0; j < beverageOrderNo; j++) {
				cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
				cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
				cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
				orderTotal += beverageOrder[j].totalorderprice;}
			cout << "\n\n\t\tWhich order would you like to edit?" << endl;
			cout << "\n\n\t\tYour holy choice: ";
			cin >> editchoice;
			cin.ignore();
			cout << endl;
			for (int i = 0; i < beverageOrderNo; i++) {
				if (editchoice == beverageOrder[i].newOrderIndex) {
					int pos = i;
					displaybeveragemenu();

					cout << "\n\nChoose your new desired beverage: ";
					cin >> newBev;
					cout << "\n\nChoose your new quantity: ";
					cin >> newBevQuan;
					cin.ignore();
					for (int i = 0; i < SIZE1; i++) {
						readbeverageinfile();
						if (newBev == beverageindex[i]) {
							valid = true;
							cout << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << "\t\t\tEdited Order" << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << editchoice << ":) " << beveragename[i] << endl;
							cout << endl;
							cout << string(120, '-') << endl;
							cout << "Amount selected: " << newBevQuan << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << beverageprice[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (beverageprice[i] * newBevQuan) << endl;
							newOrderTotal = beverageprice[i] * newBevQuan;
							beverageOrder[editchoice - 1].orderindex = beverageindex[i];
							beverageOrder[editchoice - 1].newOrderIndex = pos;
							beverageOrder[editchoice - 1].ordername = beveragename[i];
							beverageOrder[editchoice - 1].orderquantity = newBevQuan;
							beverageOrder[editchoice - 1].totalorderprice = newOrderTotal;
							orderTotal += beverageOrder[editchoice - 1].totalorderprice;
							writingSentence3();
							break;}
						else {
							valid = false;
							notFoundE++;
							if (notFoundE == SIZE1) {
								errorMessage();
								notFoundE = 0;}}}
					break;}
				else {
					valid = false;
					notFoundE++;
					if (notFoundE == beverageOrderNo) {
						errorMessage();
						notFoundE = 0;}}}
			break;}
		else if (editno == 3) {
			cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
			for (int k = 0; k < sideOrderNo; k++) {
				cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
				cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
				cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
				orderTotal += sideOrder[k].totalorderprice;}
			cout << "\n\n\t\tWhich order would you like to edit?" << endl;
			cin >> editchoice;
			cin.ignore();
			for (int i = 0; i < sideOrderNo; i++) {
				if (editchoice == beverageOrder[i].newOrderIndex) {
					int pos = i;
					displaysidemenu();
					cout << "\n\nChoose your new desired side: ";
					cin >> newSide;
					cout << "\n\nChoose your new quantity: ";
					cin >> newSideQuan;
					cin.ignore();
					for (int i = 0; i < SIZE1; i++) {
						readsideinfile();
						if (newSide == sideindex[i]) {
							valid = true;
							cout << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << "\t\t\tEdited Order" << endl;
							cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
							cout << editchoice << ":) " << sidename[i] << endl;
							cout << endl;
							cout << string(120, '-') << endl;
							cout << "Amount selected: " << newSideQuan << "\t\t\t | Price [1 item]: RM" << fixed << setprecision(2) << sideprice[i] << "\t\t\t | Total price : RM" << fixed << setprecision(2) << (sideprice[i] * newSideQuan) << endl;
							newOrderTotal = sideprice[i] * newSideQuan;
							sideOrder[editchoice - 1].orderindex = sideindex[i];
							sideOrder[editchoice - 1].newOrderIndex = pos;
							sideOrder[editchoice - 1].ordername = sidename[i];
							sideOrder[editchoice - 1].orderquantity = newSideQuan;
							sideOrder[editchoice - 1].totalorderprice = newOrderTotal;
							orderTotal += sideOrder[editchoice - 1].totalorderprice;
							writingSentence3();
							break;}
						else {
							valid = false;
							notFoundE++;
							if (notFoundE == SIZE1) {
								errorMessage();
								notFoundE = 0;}}}
					break;}
				else {
					valid = false;
					notFoundE++;
					if (notFoundE == sideOrderNo) {
						errorMessage();
						notFoundE = 0;}}}
			break;}
		else {
			valid = false;
			errorMessage2();
			editOrder();}
	} while (!valid);
	do {
		cout << "\n\n\t\t\t\tDo you want to continue editing your order? [Y-YES / N-NO]: ";
		char cont;
		cin >> cont;
		cin.ignore();
		if (toupper(cont) == 'Y')
			editOrder();
		else if (toupper(cont) == 'N')
			menuChoice();
		else {
			valid = false;
			errorMessage3();}
	} while (!valid);}

void deleteOrder() { //delete specific order according to user input
	system("cls");
	system("COLOR E0");
	int deleteno, deletechoice, notFoundX = 0;
	double orderTotal = 0;
	char contDelete;
	bool valid = true;
	cout << underline << "\n\nHere's your order so far: " << "\033[0m" << endl;
	cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
	for (int i = 0; i < burgerOrderNo; i++) {
		cout << "\t\t" << i + 1 << ":) " << burgerOrder[i].ordername << endl;
		cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
		cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
		orderTotal += burgerOrder[i].totalorderprice;}
	cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
	for (int j = 0; j < beverageOrderNo; j++) {
		cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
		cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
		cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
		orderTotal += beverageOrder[j].totalorderprice;}
	cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
	for (int k = 0; k < sideOrderNo; k++) {
		cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
		cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
		cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
		orderTotal += sideOrder[k].totalorderprice;}
	do {
		cout << "\n\n\t\tWhich order would you like to delete?" << endl;
		cout << "\n\n\t\t\t1. Burger" << endl;
		cout << "\n\n\t\t\t2. Beverage" << endl;
		cout << "\n\n\t\t\t3. Side" << endl;
		cout << "\n\n\t\t\tDelete: ";
		cin >> deleteno;
		cin.ignore();
		cout << endl;
		if (deleteno == 1) {
			valid = true;
			cout << "\n\t\t+-------------------------------->  Burger  <--------------------------------+" << endl;
			for (int i = 0; i < burgerOrderNo; i++) {
				cout << "\t\t" << i + 1 << ":) " << burgerOrder[i].ordername << endl;
				cout << "\t\tQuantity: " << burgerOrder[i].orderquantity << endl;
				cout << "\t\tPrice: RM" << burgerOrder[i].totalorderprice << endl;
				orderTotal += burgerOrder[i].totalorderprice;
				break;}
			cout << "\n\n\t\tWhich one would you like to delete?: ";
			cin >> deletechoice;
			cin.ignore();
			for (int i = 0; i < burgerOrderNo; i++) {
				if (deletechoice == burgerOrder[i].newOrderIndex) {
					valid = true;
					int pos = i; //define the position of the i that has found
					for (i = pos; i < burgerOrderNo - 1; i++) {
						//delete chosen order and move others order by 1
						newIndex--;
						burgerOrder[i].ordername = burgerOrder[i + 1].ordername;
						burgerOrder[i].newOrderIndex = newIndex;
						burgerOrder[i].orderquantity = burgerOrder[i + 1].orderquantity;
						burgerOrder[i].totalorderprice = burgerOrder[i + 1].totalorderprice;
						orderTotal -= burgerOrder[i + 1].totalorderprice;}
					burgerOrderNo--;
					writingSentence2();
					break;}
				else {
					valid = false;
					notFoundX++;
					if (notFoundX == burgerOrderNo) {
						errorMessage();
						notFoundX = 0;}}}}
		else if (deleteno == 2) {
			valid = true;
			cout << "\n\t\t+------------------------------->  Beverage  <-------------------------------+" << endl;
			for (int j = 0; j < beverageOrderNo; j++) {
				cout << "\t\t" << j + 1 << ":) " << beverageOrder[j].ordername << endl;
				cout << "\t\tQuantity: " << beverageOrder[j].orderquantity << endl;
				cout << "\t\tPrice: RM" << beverageOrder[j].totalorderprice << endl;
				orderTotal += beverageOrder[j].totalorderprice;
				break;}
			cout << "\n\n\t\tWhich one would you like to delete?: ";
			cin >> deletechoice;
			cin.ignore();
			for (int j = 0; j < beverageOrderNo; j++) {
				if (deletechoice == beverageOrder[j].newOrderIndex) {
					valid = true;
					int pos = j;
					for (j = pos; j < beverageOrderNo - 1; j++) {
						newIndex2--;
						beverageOrder[j].ordername = beverageOrder[j + 1].ordername;
						beverageOrder[j].newOrderIndex = newIndex2;
						beverageOrder[j].orderquantity = beverageOrder[j + 1].orderquantity;
						beverageOrder[j].totalorderprice = beverageOrder[j + 1].totalorderprice;
						orderTotal -= beverageOrder[j].totalorderprice;}
					beverageOrderNo--;
					writingSentence2();
					break;}
				else {
					valid = false;
					notFoundX++;
					if (notFoundX == beverageOrderNo) {
						errorMessage();
						notFoundX = 0;}}}}
		else if (deleteno == 3) {
			valid = true;
			cout << "\n\t\t+--------------------------------->  Side  <---------------------------------+" << endl;
			for (int k = 0; k < sideOrderNo; k++) {
				cout << "\t\t" << k + 1 << ":) " << sideOrder[k].ordername << endl;
				cout << "\t\tQuantity: " << sideOrder[k].orderquantity << endl;
				cout << "\t\tPrice: RM" << sideOrder[k].totalorderprice << endl;
				orderTotal += sideOrder[k].totalorderprice;
				break;}
			cout << "\n\n\t\tWhich one would you like to delete?: ";
			cin >> deletechoice;
			cin.ignore();
			for (int k = 0; k < sideOrderNo; k++) {
				if (deletechoice == sideOrder[k].newOrderIndex) {
					valid = true;
					int pos = k;
					for (k = pos; k < sideOrderNo - 1; k++) {
						newIndex3--;
						sideOrder[k].ordername = sideOrder[k + 1].ordername;
						sideOrder[k].newOrderIndex = newIndex3;
						sideOrder[k].orderquantity = sideOrder[k + 1].orderquantity;
						sideOrder[k].totalorderprice = sideOrder[k + 1].totalorderprice;
						orderTotal -= sideOrder[k].totalorderprice;}
					sideOrderNo--;
					writingSentence2();
					break;}
				else {
					valid = false;
					notFoundX++;
					if (notFoundX == sideOrderNo) {
						errorMessage();
						notFoundX = 0;}}}}
		else {
			valid = false;
			errorMessage2();}
	} while (!valid);
	do {
		cout << "\n\n\t\t\tDo you want to continue deleteing items in your order? [Y-YES / N-NO]: ";
		cin >> contDelete;
		cin.ignore();
		if (toupper(contDelete) == 'Y')
			deleteOrder();
		else if (toupper(contDelete) == 'N')
			menuChoice();
		else {
			valid = false;
			errorMessage3();}
	} while (!valid);}

void loadScreen() { //load the screen of process payment
	system("cls");
	system("COLOR 0A");
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;
	cout << "\n\n\n\t\t\t\tProcessing Payment...";
	cout << "\n\n\n\t\t\t\t";
	for (int i = 0; i < 25; i++)
		cout << (char)bar1;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i < 25; i++) {
		cout << (char)bar2;
		Sleep(150);}}

void writingSentence() { //display typing effect
	system("COLOR E0");
	string line = "\n\t\t\t\t._._._._._._._._._._._._._._._._._._._._._._._._._._.";
	int a = 0;
	while (line[a] != '\0') {
		cout << line[a];
		Sleep(150);
		a++;}
	string successfulAdd = "\n\n\t\t\t\t\tYour order is successfully added!";
	int b = 0;
	while (successfulAdd[b] != '\0') {
		cout << successfulAdd[b];
		Sleep(150);
		b++;};}

void writingSentence2() {
	system("COLOR E0");
	string line2 = "\n\t\t\t\t._._._._._._._._._._._._._._._._._._._._._._._._._._.";
	int c = 0;
	while (line2[c] != '\0') {
		cout << line2[c];
		Sleep(150);
		c++;}
	string successfulDel = "\n\n\t\t\t\t\tYour order is successfully deleted!";
	int d = 0;
	while (successfulDel[d] != '\0') {
		cout << successfulDel[d];
		Sleep(150);
		d++;}}

void writingSentence3() {
	system("COLOR E0");
	string line3 = "\n\t\t\t\t._._._._._._._._._._._._._._._._._._._._._._._._._._.";
	int e = 0;
	while (line3[e] != '\0') {
		cout << line3[e];
		Sleep(150);
		e++;}
	string successfulEdit = "\n\n\t\t\t\t\tYour order is successfully edited!";
	int f = 0;
	while (successfulEdit[f] != '\0') {
		cout << successfulEdit[f];
		Sleep(150);
		f++;}}

void errorMessage() { //display error message with typing effect
	system("COLOR E0");
	string error = "\n\n\n\t\t\t\tThe item you have selected is not in the list!";
	int x = 0;
	while (error[x] != '\0') {
		cout << error[x];
		Sleep(130);
		x++;}}

void errorMessage2() {
	system("COLOR E0");
	string error2 = "\n\n\n\t\t\t\tPlease choose a valid option from the list...";
	int y = 0;
	while (error2[y] != '\0') {
		cout << error2[y];
		Sleep(130);
		y++;}}

void errorMessage3() {
	system("COLOR E0");
	string error3 = "\n\n\n\t\t\t\tPlease enter the correct alphabet.";
	int z = 0;
	while (error3[z] != '\0') {
		cout << error3[z];
		Sleep(130);
		z++;}}