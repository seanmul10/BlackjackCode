/*
=================
cHumanPlayer.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cHumanPlayer.h"
#include <iostream>
#include <fstream>
/*
=================
- Data constructor initializes the human player object 
- Is always called, thus ensures all player objects are in a consistent state.
=================
*/

cHumanPlayer::cHumanPlayer(const std::string& name): cPlayer(name) // Constructor - will create an instance of the player class.
{
	// Reads the chip count file to get the correct number of chips for the player
	std::ifstream file;
	file.open(name + "ChipCount.txt", std::ios::in); // Attempts to open the file with the current players chip total

	// If the file cannot be opened or isn't found, reset the players chip total
	if (!file)
	{
		std::cout << "\nCouldn't find player profile with that name. Setting chips to default value." << std::endl;
		cHumanPlayer::chips = 5000;
	}
	// Otherwise, welcome the player back and show them the amount of chips they have
	else {
		file >> cHumanPlayer::chips;
		std::cout << "\nWelcome back, " << name << ". You finished last time with " << cHumanPlayer::chips << " chips." << std::endl;
	}

	// If the player is out of chips, reset their total so they can play again
	if (cHumanPlayer::chips <= 0) {
		std::cout << "\nStarting again with the default number of chips." << std::endl;
		cHumanPlayer::chips = 5000;
	}

	// Close the file
	file.close();
}

/*
=================
- Check if player wants to hit, stand or double down.
=================
*/
int cHumanPlayer::pPlay(cHumanPlayer player, int stake)     // Returns whether the players hand is over 21 therefore "bust".
{
	char response;

	do {
		// Display the players possible moves
		std::cout << "Do you want to Hit(h)";

		// Only display that the player can double down if they have enough chips to cover it and have not drawn a third card
		if (player.getChipCount() >= stake && player.getPlayerHandSize() == 2) {
			std::cout << ", Double Down(d)";
		}
		std::cout << " or Stand(s)?" << std::endl;

		std::cin >> response; // Get the players response
		std::cout << "\n";

		if (response == 's') { // Return 0 for a stand
			return 0;
		}
		if (response == 'h') { // Return 1 for a hit
			return 1;
		}
		// Only return 2 for a double down if the player is elligble
		else if (response == 'd' && player.getChipCount() >= stake && player.getPlayerHandSize() == 2) {
			return 2;
		}

		// Ask the player to enter a valid move.
		std::cout << "Please enter a valid move.\n" << std::endl;

	} while (true); // Loop until the player makes a valid move
}

/*
=================
- Gets the players current amount of chips
=================
*/
short cHumanPlayer::getChipCount()
{
	return (cHumanPlayer::chips);
}

/*
=================
- Adds or removes chips from the player
=================
*/
void cHumanPlayer::setChipCount(int dChipAmount)
{
	// Writes the players chips to a text file
	cHumanPlayer::chips += dChipAmount;
	if (cHumanPlayer::chips < 0) {
		chips = 0;
	}

	// Opens the players chip count file or creates a new one if it dosen't exist
	std::ofstream file;
	file.open(cHumanPlayer::getPlayerName() + "ChipCount.txt", std::ios::out);

	// Overwrite the file with the players current chip count
	file << chips;

	// Close the file
	file.close();
}