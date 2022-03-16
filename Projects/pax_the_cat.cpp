// Pax the Cat from https://lwdtsupport.weebly.com/pick-a-path-stories.html

#include <iostream>

using namespace std;

int main()
{
	int playAgain = 0;

	do {
		int choice = 0, choiceDishPC = 0, choiceBB = 0, choiceSuitcasePB = 0, tryAgain = 0;  // integer variable for choices
		cout << "\033[1;34m"; // Change colour to red
		cout << "*********************************\n" << endl;
		cout << "********** PAX the CAT ********** \n" << endl;
		cout << "*** Choose Your Own Adventure *** \n" << endl;
		cout << "*********************************\n\n" << endl;
		cout << "\033[0m"; // Reset colour 
		do {
			cout << "Once upon a time there was a fluffy cat named Pax.\n" << endl;
			cout << "Pax had a favourite piece of yellow rope that he liked to play with.\n" << endl;
			cout << "One day he went to play with his rope but it was gone. Where could it be?\n" << endl;
			cout << "Could it be in the bowl or the washing machine ?\n" << endl;
			cout << "\033[1;31m"; // Change colour to red
			cout << "Enter 1 for bowl\n" << endl;
			cout << "Enter 2 for the washing machine\n" << endl;
			cin >> choice;
			cout << endl;
			cout << "\033[0m"; // Reset colour 

			if (choice == 1) // bowl
			{
				do {
					cout << "Pax hopped into the bowl. No rope here. He curled up and had a little rest.\n" << endl;
					cout << "After his rest he wondered what to do next. Maybe having a drink or something to eat would help.\n" << endl;
					cout << "\033[1;31m"; // Change colour to red
					cout << "Enter 1 for a drink\n" << endl;
					cout << "Enter 2 for something to eat\n" << endl;
					cin >> choice;
					cout << endl;
					cout << "\033[0m"; // Reset colour 

					if (choice == 1) //drink
					{
						do {
							tryAgain = 0;
							cout << "Pax had a drink from his water fountain. Then he carried on looking.\n" << endl;
							cout << "Where should he look next?\n" << endl;
							cout << "\033[1;31m"; // Change colour to red
							cout << "Enter 1 for in the dishwasher\n" << endl;
							cout << "Enter 2 for in a plastic container \n" << endl;
							cin >> choice;
							cout << endl;
							cout << "\033[0m"; // Reset colour 
							if (choice == 1)  // dishwasher
								choiceDishPC = 1;
							else if (choice == 2)
								choiceDishPC = 2;
							else {
								cout << "Not a valid choice. Please try again.\n" << endl;
								tryAgain = 1;
							}
						} while (tryAgain == 1);
					}
					else if (choice == 2) // something to eat
					{
						do {
							tryAgain = 0;
							cout << "Pax ate his dinner then he carried on looking.\n" << endl;
							cout << "Where should he look next?\n" << endl;
							cout << "\033[1;31m"; // Change colour to red
							cout << "Enter 1 for a bag\n" << endl;
							cout << "Enter 2 for a box\n" << endl;
							cin >> choice;
							cout << endl;
							cout << "\033[0m"; // Reset colour 
							if (choice == 1) //bag
								choiceBB = 1;
							else if (choice == 2)// box
								choiceBB = 2;
							else {
								cout << "Not a valid choice. Please try again.\n" << endl;
								tryAgain = 1;
							}
						} while (tryAgain == 1);
					}
					else {
						cout << "Not a valid choice. Please try again.\n" << endl;
						tryAgain = 1;
					}

				} while (tryAgain == 1); // X.H. added this do while loop with 'else{}' to auto-correct
			} // end bowl
			else if (choice == 2)// washing machine
			{
				do {
					cout << "Pax looked in the washing machine. There was an odd sock but no rope.\n" << endl;
					cout << "Maybe he should have a sleep but where would be best, on the computer on a shoe?\n" << endl;
					cout << "\033[1;31m"; // Change colour to red
					cout << "Enter 1 for on a shoe\n" << endl;
					cout << "Enter 2 for on a computer\n" << endl;
					cin >> choice;
					cout << endl;
					cout << "\033[0m"; // Reset colour 

					if (choice == 1) // shoe
					{
						do {
							tryAgain = 0;
							cout << "Pax had a little sleep on the shoe then carried on looking.\n" << endl;
							cout << "Where should he look next?\n" << endl;
							cout << "\033[1;31m"; // Change colour to red
							cout << "Enter 1 for in the dishwasher\n" << endl;
							cout << "Enter 2 for in a plastic container \n" << endl;
							cin >> choice;
							cout << endl;
							cout << "\033[0m"; // Reset colour 
							if (choice == 1)
								choiceDishPC = 1;
							else if (choice == 2)
								choiceDishPC = 2;
							else {
								cout << "Not a valid choice. Please try again.\n" << endl;
								tryAgain = 1;
							}
						} while (tryAgain == 1);
					} // end shoe
					else if (choice == 2)// computer
					{
						do {
							tryAgain = 0;
							cout << "Pax had a little sleep on the computer then carried on looking. \n" << endl;
							cout << "Where should he look next?\n" << endl;
							cout << "\033[1;31m"; // Change colour to red
							cout << "Enter 1 for a bag\n" << endl;
							cout << "Enter 2 for a box\n" << endl;
							cin >> choice;
							cout << endl;
							cout << "\033[0m"; // Reset colour 
							if (choice == 1) //bag
								choiceBB = 1;
							else if (choice == 2)// box
								choiceBB = 2;
							else {
								cout << "Not a valid choice. Please try again.\n" << endl;
								tryAgain = 1;
							}
						} while (tryAgain == 1);
					} // end computer
					else
					{ // unvalid
						cout << "Not a valid choice. Please try again.\n" << endl;
						tryAgain = 1;
					}
				} while (tryAgain == 1); // X.H. added the do-while loop with 'else{}' 
			} // end washing machine 

			else {
				cout << "Not a valid choice. Please try again.\n" << endl;
				tryAgain = 1;
			}
		} while (tryAgain == 1);


		if (choiceDishPC == 1) // dishwasher
		{
			do {
				tryAgain = 0;
				cout << "It wasn't in the dishwasher so he carried on looking.\n" << endl;
				cout << "Where should he look next?\n" << endl;
				cout << "\033[1;31m"; // Change colour to red
				cout << "Enter 1 for in the suitcase\n" << endl;
				cout << "Enter 2 for in the plastic bags \n" << endl;
				cin >> choice;
				cout << endl;
				cout << "\033[0m"; // Reset colour 
				if (choice == 1) // suitcase
					choiceSuitcasePB = 1;
				else if (choice == 2)// plastice bags
					choiceSuitcasePB = 2;
				else {
					cout << "Not a valid choice. Please try again.\n" << endl;
					tryAgain = 1;
				} // end do

			} while (tryAgain == 1); // X.H. added this do-while loop with 'else{}' to preform autocorrecting 

		}
		else if (choiceDishPC == 2) // plastic container
		{
			do {
				tryAgain = 0;
				cout << "It wasn't in the plastic container so he carried on looking.\n" << endl;
				cout << "Where should he look next?\n" << endl;
				cout << "\033[1;31m"; // Change colour to red
				cout << "Enter 1 for in the suitcase\n" << endl;
				cout << "Enter 2 for in the plastic bags \n" << endl;
				cin >> choice;
				cout << endl;
				cout << "\033[0m"; // Reset colour 
				if (choice == 1) // suitcase
					choiceSuitcasePB = 1;
				else if (choice == 2) // plastice bags
					choiceSuitcasePB = 2;
				else {
					cout << "Not a valid choice. Please try again.\n" << endl;
					tryAgain = 1;
				}
			} while (tryAgain == 1);
		}


		if (choiceBB == 1) //bag
		{
			do {
				tryAgain = 0;
				cout << "It wasn't in the bag so he carried on looking.\n" << endl;
				cout << "Where should he look next?\n" << endl;
				cout << "\033[1;31m"; // Change colour to red
				cout << "Enter 1 for in the suitcase\n" << endl;
				cout << "Enter 2 for in the plastic bags \n" << endl;
				cin >> choice;
				cout << endl;
				cout << "\033[0m"; // Reset colour 
				if (choice == 1) // suitcase
					choiceSuitcasePB = 1; // X.H. changed "choiceSuitcasePB = 2 to = 1 to match the later on if statements
				else if (choice == 2) // plastice bags
					choiceSuitcasePB = 2;
				else {
					cout << "Not a valid choice. Please try again.\n" << endl;
					tryAgain = 1;
				}
			} while (tryAgain == 1);
		}
		else if (choiceBB == 2)// box
		{
			do {
				tryAgain = 0;
				cout << "It wasn't in the box so he carried on looking.\n" << endl;
				cout << "Where should he look next?\n" << endl;
				cout << "\033[1;31m"; // Change colour to red
				cout << "Enter 1 for in the suitcase\n" << endl;
				cout << "Enter 2 for in the plastic bags \n" << endl;
				cin >> choice;
				cout << endl;
				cout << "\033[0m"; // Reset colour 
				if (choice == 1) // suitcase
					choiceSuitcasePB = 1;
				else if (choice == 2) // plastice bags
					choiceSuitcasePB = 2;
				else {
					cout << "Not a valid choice. Please try again.\n" << endl;
					tryAgain = 1;
				}
			} while (tryAgain == 1);
		}

		if (choiceSuitcasePB == 1) // suitcase
		{
			cout << "Yes, it was in the suitcase. Pax was very happy.\n" << endl;
			cout << "THE END\n\n" << endl;
		}
		else if (choiceSuitcasePB == 2) // plastice bags
		{
			cout << "No it wasn't there. Pax was very sad.\n" << endl;
			cout << "THE END\n\n" << endl;
		}

		cout << "Would you like to try again? 1 - yes, 2 - no\n" << endl;
		cin >> playAgain;
	} while (playAgain == 1);

	return 0;
}
