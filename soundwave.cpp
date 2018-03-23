#include <iostream>
#include <iomanip>
using namespace std;

const short int AIR_FT_SEC = 1100;
const short int WATER_FT_SEC = 4900;
const short int STEEL_FT_SEC = 16400;

const 

int main()
{
	// declare variables
	char choice;
	double distance , time;
	
	// do/ while loop for our program
	do
	{
		// display the menu
			do
			{
			cout << "Speed of Sound Menu" << endl;
			cout << endl;
			cout << "1. Air (" << AIR_FT_SEC << " ft/sec)" << endl;
			cout << "2. Water (" << WATER_FT_SEC << " ft/sec)" << endl;
			cout << "3. Steel (" << STEEL_FT_SEC << " ft/sec)" << endl;
			cout << "4. Quit this program" << endl;
			cout << endl;
			cout << "Enter an option (1-4): ";
			cin >> choice;
			if (choice < '1' || choice > '4')
				cout << "Invalid choice, please choose 1, 2, 3, or 4. " << endl;
		} while ( choice ' 1 ' || choice > ' 4 ');
		
		if ( choice != '4' )
		{
			// get the distance from the user (must be >= 0)
			do
			{
			cout << "Enter the distance sound travelled through the medium: ";
			cin >> distance;
			if ( distance < 0 )
				cout << "Invalid distance, must be greater than or equal to 0";
			} while ( distance < 0 );
		}
		COUT << fixed << setprecision(DECIMAL_DIGITS_PRECISION)
		
		switch(choice)
		{
			case ' 1 ':		time = distance / AIR_FT_SEC;
							cout << "It took sound " << time << " seconds to ";
							break;
							
			case ' 2 ':		time = distance / WATER_FT_SEC;
							break;
			
			case ' 3 ':		time = distance / STEEL_FT_SEC;
							break;				
		}
			
		} // end of switch/case
		
		
	} while ( choice != '4' );

	return 0;
}
