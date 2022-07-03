#include <iostream>
#include <string>
using namespace std;

int main()
{
	char vehicle;
	cout << "Which vehicle would you like to order? ";
	cin >> vehicle;
	cin.ignore(10000, '\n');		//getline function called after >>
	if (vehicle != 'S' && vehicle != 'X' && vehicle != '3')	//prompt error message if incorrect input detected
	{
		cout << "Error - Incorrect model choice." << endl;
		return (-1);
	}
	//moves on to next step if valid vehicle type was entered 

	string kind;
	cout << "Which kind would you like? ";
	getline(cin, kind);
	if (kind != "Performance" && kind != "Long Range")
	{
		cout << "Error - Incorrect kind choice." << endl;
		return (-1);
	}

	string color;
	cout << "What exterior color would you like? ";
	getline(cin, color);
	if (color != "White" && color != "Black" && color != "Blue" && color != "Grey" && color != "Red")
	{
		cout << "Error - Incorrect color choice." << endl;
		return (-1);
	}

	int wheel;
	cout << "Which wheels would you like? ";
	cin >> wheel;
	cin.ignore(10000, '\n');				//getline function is called in next section
	if (vehicle == '3') {										//wheel sizes allowed for model 3				
		if (wheel != 18 && wheel != 19) {
			cout << "Error - Incorrect wheel value." << endl;
			return (-1);
		}
	}
	if (vehicle == 'S') {										//wheel sizes for model S
		if (wheel != 19 && wheel != 21) {
			cout << "Error - Incorrect wheel value." << endl;
			return (-1);
		}
	}
	if (vehicle == 'X') {										//wheel sizes for model X
		if (wheel != 20 && wheel != 22) {
			cout << "Error - Incorrect wheel value." << endl;
			return (-1);
		}
	}

	string leather;
	cout << "Want leather interior? ";
	getline(cin, leather);
	if (leather != "Yes" && leather != "No") {
		cout << "Error - Incorrect leather choice." << endl;
		return (-1);
	}

	string autopilot;
	cout << "Want Auto-Pilot? ";
	getline(cin, autopilot);
	if (autopilot != "Yes" && autopilot != "No") {
		cout << "Error - Incorrect autopilot choice." << endl;
		return (-1);
	}

	//getting to this step means that all valid configurations were selected
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);				//changes double values to have 2 decimal for dollar/cents amounts 


	//price calculation
	double price = 0;		//initialized at 0


	if (vehicle == '3') {
		if (kind == "Long Range")
			price += 47990;
		else
			price += 55990;
		if (color == "Black")
			price += 500;
		if (color == "Blue" || color == "Grey")		//prices for Blue and Grey are the same
			price += 1000;
		if (color == "Red")
			price += 1500;
		if (wheel == 19)
			price += 1500;
		if (leather == "Yes")
			price += 1000;
		if (autopilot == "Yes")
			price += 6000;
	}

	if (vehicle == 'S') {
		if (kind == "Long Range")
			price += 79990;
		else
			price += 99990;
		if (color == "Black")
			price += 1000;
		if (color == "Blue" || color == "Grey")
			price += 1500;
		if (color == "Red")
			price += 2500;
		if (wheel == 21)
			price += 4500;
		if (leather == "Yes")
			price += 1000;
		if (autopilot == "Yes")
			price += 6000;
	}

	if (vehicle == 'X') {
		if (kind == "Long Range")
			price += 84990;
		else
			price += 104990;
		if (color == "Black")
			price += 1000;
		if (color == "Blue" || color == "Grey")
			price += 1500;
		if (color == "Red")
			price += 2500;
		if (wheel == 22)
			price += 5500;
		if (leather == "Yes")
			price += 1000;
		if (autopilot == "Yes")
			price += 6000;
	}

	//final output for user after price calculations
	cout << "Enjoy your new $" << price << " " << color << " Model " << vehicle << "!" << endl;
	return 0;

}