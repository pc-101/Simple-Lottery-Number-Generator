#include "game.h"

void Lotto::start() {
      // Initialize struct variables
	init(Mega); 
	init(Power); 
	init(Super); 
	init(Fantasy); 
	init(Daily4); 
	init(Daily3); 

	  // Opening message 
	char ch; 
	while (choice == ' ') {
		cout << "\n\nWelcome to the California Lotto Number Generator.\n"
			<< "Please select the game you will be playing:\n"
			<< "0 : MEGA Millions\n"
			<< "1 : POWERBALL\n"
			<< "2 : SuperLotto Plus\n"
			<< "3 : Fantasy 5\n"
			<< "4 : Daily 4\n"
			<< "5 : Daily 3\n"
			<< "6 : Display all\n"
			<< "7 : Exit program" << endl << endl;

		cin >> ch; 
		cout << "\n\n" << endl;

		if (isalpha(ch)) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << setw(15) << "\nERROR: Invalid input. Input a number!" 
				<< "\nPress ENTER key to continue." << endl;
			getchar(); 
			system("cls"); 
		}

		if (ch >= '0' && ch <= '7')
		{
			if (ch == '7')
				return;
			cin.clear();
			system("cls");

			choice = ch;
			decision(choice);
		}
	}
}

void Lotto::init(type t) {
	switch (t)
	{
		// reg 1-75, mega 1-15
	case Lotto::Mega:
		mega.name = "MEGA Millions"; 
		mega.num = 5; 
		mega.numRange = 75; 
		mega.numMega = 1; 
		mega.numMRange = 15; 
		break;
		// reg 1-69, mega 1-26
	case Lotto::Power:
		power.name = "POWERBALL"; 
		power.num = 5; 
		power.numRange = 69; 
		power.numMega = 1; 
		power.numMRange = 26; 
		break;
		// reg 1-47, mega 1-27
	case Lotto::Super:
		super.name = "SuperLotto Plus"; 
		super.num = 5; 
		super.numRange = 47; 
		super.numMega = 1; 
		super.numMRange = 27; 
		break;
	case Lotto::Fantasy:
		fantasy.name = "Fantasy 5"; 
		fantasy.num = 5; 
		fantasy.numRange = 39; 
		fantasy.numMega = 0; 
		fantasy.numMRange = 0; 
		break;
	case Lotto::Daily4:
		daily4.name = "Daily 4"; 
		daily4.num = 4; 
		daily4.numRange = 9; 
		daily4.numMega = 0; 
		daily4.numMRange = 0; 
		break;
	case Lotto::Daily3:
		daily3.name = "Daily 3"; 
		daily3.num = 3; 
		daily3.numRange = 9; 
		daily3.numMega = 0; 
		daily3.numMRange = 0; 
		break;
	default:
		cout << "ERROR: Not a valid parameter for init function" << endl;
		break;
	}
}

void Lotto::decision(char ch) {
	  // Seed the pseudo-random generator 
	srand((unsigned)time(NULL));

	  // Call the appropriate private function
	switch (ch)
	{
	case '0': display(mega); break;
	case '1': display(power); break;
	case '2': display(super); break;
	case '3': display(fantasy); break;
	case '4': display(daily4); break;
	case '5': display(daily3); break;
	case '6': dispAll(); cout << "\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
			  break;
	} 

	getchar(); 
	cout << "Press ENTER to exit the program."; 
	getchar(); 
	return; 
	
}

/* Private function definitions */

void Lotto::display(lottoType t) {
	nums = t.num;
	cout << t.name << " numbers: ";
	cout << "\n============================================" << endl;

	for (int i = 0; i < nums; i++)
	{
		  // rand() % n generates a number between 0 and n - 1
		random_integer = ((rand() % t.numRange) + 1);

		  // Custom formatting based on games
		if (t.num == 5 && t.numMega > 0)
			cout << setw(5) << random_integer << setw(5);
		else if (t.num == 5 && t.numMega == 0)
			cout << setw(7) << random_integer;
		else if (t.num == 4)
			cout << setw(8) << random_integer;
		else
			cout << setw(10) << random_integer; 
	}

	  // Display a Mega number if the game type contains one
	if (t.numMega > 0)
	{
		random_integer = ((rand() % t.numMRange) + 1);
		cout << "|" << setw(10) << "Mega: " << random_integer << setw(5); 
	}
	else
	{
		setw(5); 
	}
	cout << "\n============================================" << endl;
}

void Lotto::dispAll() {
	display(mega); 
	display(power); 
	display(super); 
	display(fantasy); 
	display(daily4); 
	display(daily3); 
}