//CSC215
//Assignment: Introducing A.I. into Skynet HK-Aerial: Wargames
//Create a new solution and project and GitHub for this assignment.
//Hint: Open two separate visual studios to do this.One for the old solution project, and one for the new solution project.Now copy all the code from the original Skynet HK - Aerial into this new project to save you from having to recode everything from scratch.Test this before you move on to make sure the code works in your new project like it did in your old project.Now close your old project and that instance of visual studio.
//Modify your new C++ program for the Skynet HK - Aerial.
//Add another AI player using the less efficient Linear search pattern.
//Add another AI player using a random number guess between grid locations 1 and 64.
//Add a human player, letting the human input grid numbers from the console.
//The easiest way to code this would be for this program’s user interface to start with the human player and use a while loop until the human guesses the location the enemy while keeping track of the number of guesses the human uses.Then the random guess AI player should guess using their own while loop until they find the enemy location and keep track of how many guesses it took them.Then the linear Search AI player should guess using their own while loop until they find the enemy location, and then finally the Binary search AI should run it’s while loop and keep track of the number of guesses it takes to find the enemy location.Once all players AI and Human have found the enemy location, then this game is over.Display the stats of each player's number of guesses it took. You don't have to physically sort them, just display the number of guesses each drone pilot took to find the enemy.
//Be sure to comment each line of code except cout statements, write very readable code using good coding standards.
//The Grid does not need to be displayed, remember the grid is abstract.Think of this as more of a guess the number game like at the end of chapter two.
//When all the players have found the enemies, the game is over, the console should ask the human player if they would like to play again.If the human player say's yes, then the game should reset all scores and play again.
//Put this new project into a new GitHub repostiory and take a screenshot of it.
//Your code should be well formatted and with lots of comments explaining your code.

// Standard Input / Output Streams Libraries
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Std stands for standard library
using namespace std;

//The program always start at the main function
//This also applies to C#, Java, and other languages
//The int before the main stands for integer
//Integer is the return type
//The end of the main function is return 0;
//0 is an integer, that data type must match
//If you see the void main () , you will only see a return.
int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//Int = intengers
	int enemyLocation = rand() % 64 + 1;
	int triesBinaryAI = 0;
	int triesLinearAI = 0;
	int triesHumanAI = 0;
	int triesRandomAI = 0;
	int binaryPredictionAI = 0;
	int PredictionHuman = 0;
	int PredictionLinearAI = 0;
	int PredictionRandom = 0;
	int searchGridHighNumberAI = 64;
	int searchGridLowNumberAI = 1;

	//Header
	cout << "\8X8 Grid Enemy Search \n\n";
	//The type of search this loop will do.
	cout << "(Executing Binary search...)" << endl;
	//Binary search loop
	do
	{

		//Algorithm code to use for our binary search
		binaryPredictionAI = ((searchGridHighNumberAI - searchGridLowNumberAI) / 2) + searchGridLowNumberAI;
		++triesBinaryAI;
		//Separation and organization texts
		cout << "=================================================== \n" << endl;
		cout << "Binary search results." << endl;
		if (binaryPredictionAI > enemyLocation)
			//Cout for number guess being too high
		{
			cout << binaryPredictionAI << " is too high, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid high number from " << searchGridHighNumberAI;
			searchGridHighNumberAI = binaryPredictionAI;
			cout << " to " << searchGridHighNumberAI << endl;
		}
		else if (binaryPredictionAI < enemyLocation)
			//Cout for number guess being too low
		{
			cout << binaryPredictionAI << " is too low, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid low number from " << searchGridLowNumberAI;
			searchGridLowNumberAI = binaryPredictionAI;
			cout << " to " << searchGridLowNumberAI << endl;
		}
		else if (binaryPredictionAI == enemyLocation)
			//Cout for location found
		{
			cout << "Found location! Accomplished in " << triesBinaryAI << " attempts\n";
			cout << binaryPredictionAI << " was the binary guess, enemy location is at " << enemyLocation << endl;
		}
		else
			//Cout for error
		{
			cout << "\Error, something went wrong!" << endl;
		}
	} while (binaryPredictionAI != enemyLocation);
	
	//Separation and organization text
	cout << "=================================================== \n" << endl;
	cout << "\n(Executing Linear search...)" << endl;
	//Loop for Linear search
	do
	{

		// Algorithm code to use for our binary search.
		// Lines 100 and 101 mean the exact same thing.

		PredictionLinearAI = PredictionLinearAI + 1;
		/*PredictionLinearAI++;*/ 


		++triesLinearAI;

		//Separation 
		cout << "=================================================== \n" << endl;
		cout << "Linear search results." << endl;
		if (PredictionLinearAI > enemyLocation)
			//Cout for number guess being too high
		{
			cout << PredictionLinearAI << " is too high, enemy location is at " << enemyLocation << endl;

		}
		else if (PredictionLinearAI < enemyLocation)
			//Cout for number guess being too low
		{
			cout << PredictionLinearAI << " is too low, enemy location is at " << enemyLocation << endl;

		}
		else if (PredictionLinearAI == enemyLocation)
			//Cout for location found
		{
			cout << "Found location! Accomplished in " << triesLinearAI << " attempts\n";
			cout << PredictionLinearAI << " was the linear guess, enemy location is at " << enemyLocation << endl;
		}
		else
			//Cout for error
		{
			cout << "\Error, something went wrong!" << endl;
		}
	} while (PredictionLinearAI != enemyLocation);
	//Separation and organization text.
	cout << "=================================================== \n" << endl;
	cout << "\n(Executing Random search...)" << endl;
	do
	{

		//Algorithm code to use for our random search.
		PredictionRandom = rand() % 64 + 1;


		++triesRandomAI;

		//Separation and organization text.
		cout << "=================================================== \n" << endl;
		cout << "Random search results." << endl;
		if (PredictionRandom > enemyLocation)
			//Cout for number guess being too high
		{
			cout << PredictionRandom << " is too high, enemy location is at " << enemyLocation << endl;

		}
		else if (PredictionRandom < enemyLocation)
			//Cout for number guess being too low
		{
			cout << PredictionRandom << " is too low, enemy location is at " << enemyLocation << endl;

		}
		else if (PredictionRandom == enemyLocation)
			//Cout for location found
		{
			cout << "Found location! Accomplished in " << triesRandomAI << " attempts\n";
			cout << PredictionRandom << " was the random guess, enemy location is at " << enemyLocation << endl;
		}
		else
			//Cout for error
		{
			cout << "\Error, something went wrong!" << endl;
		}
	} while (PredictionRandom != enemyLocation);
	
	//Separation and organization text
	cout << "=================================================== \n" << endl;
	cout << "\n(Executing Human search...)" << endl;
	
	//Loop for human search
	do
	{
		//User input
		cout << "Enter a guess: ";
		cin >> PredictionHuman;
	
		++triesHumanAI;
		
		//Separation and organization text
		cout << "=================================================== \n" << endl;
		cout << "Human search results." << endl;
		if (PredictionHuman > enemyLocation)
			//Cout for number guess being too high
		{
			cout << PredictionHuman << " is too high, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid high number from " << searchGridHighNumberAI;
			searchGridHighNumberAI = PredictionHuman;
			cout << " to " << searchGridHighNumberAI << endl;
		}
		else if (PredictionHuman < enemyLocation)
			//Cout for number guess being too low
		{
			cout << PredictionHuman << " is too low, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid low number from " << searchGridLowNumberAI;
			searchGridLowNumberAI = PredictionHuman;
			cout << " to " << searchGridLowNumberAI << endl;
		}
		else if (PredictionHuman == enemyLocation)
			//Cout for location found
		{
			cout << "Found location! Accomplished in " << triesHumanAI << " attempts\n";
			cout << PredictionHuman << " was the human guess, enemy location is at " << enemyLocation << endl;
		}
		else
			//Cout for error
		{
			cout << "\Error, something went wrong!" << endl;
		}
	} while (PredictionHuman != enemyLocation);

	//Search attempts for all the search types
	cout << "--------------------------------------------------- \n" << endl;
	cout << "--------------------------------------------------- \n" << endl;
	cout << "Amount of attempts..." << endl;
	cout << "Binary: " << triesBinaryAI << endl;
	cout << "Linear: " << triesLinearAI << endl;
	cout << "Random: " << triesRandomAI << endl;
	cout << "Human: " << triesHumanAI << endl;
	cout << "--------------------------------------------------- \n" << endl;
	cout << "--------------------------------------------------- \n" << endl;

	// Stops debugger from closing
	system("pause");

	return 0;
}