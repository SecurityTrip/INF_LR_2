#include <iostream>

using namespace std;
string repeat;

double check_input(char flag)
{
	if (flag == 'v')
	{
		double in_value;
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong type of input data, try again: "; cin >> in_value; cout << endl;
		}
		return in_value;
	}
	if (flag == 'c')
	{
		double in_value;
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value < 0 || in_value >1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong type of input data, try again: "; cin >> in_value; cout << endl;
		}
		return in_value;
	}

	
}

string repeat_check()
{
	cout << "\nRepeat? (Y/N) " << endl;
	cin >> repeat;
	while (((repeat == "Y") || (repeat == "y") || (repeat == "N") || (repeat == "n")) != 1 || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Unidentified operator, try again" << endl;
		cout << "Repeat? (Y/N) " << endl;
		cin >> repeat;
		cout << endl;
	}
	return repeat;
}


int main()
{
	double volume, initial_concentration, required_concentration, solute;
	
	cout << "Concentration calculator" << endl;
	
	while (repeat != "N" && repeat != "n")
	{
		cout << "Input a solution volume: "; volume = check_input('v');
		cout << "Input an initial concentration: "; initial_concentration = check_input('c');
		cout << "Input a required concentration: "; required_concentration = check_input('c');

		solute = volume * initial_concentration;

		if (required_concentration<initial_concentration)
		{
			cout << "Add " << solute / required_concentration - volume << " volume units of water";
		}
		if (required_concentration > initial_concentration)
		{
			cout << "Add " << (required_concentration * volume) / initial_concentration - volume << " volume units of a solute";
		}
		if (required_concentration == initial_concentration)
		{
			cout << "Nothing to do" << endl;
		}

		repeat = repeat_check();
	}
}