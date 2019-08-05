/*
=================
main.cpp
Main entry point for the Card application
=================
*/
#include "GameConstants.h"
#include "cCard.h"
#include "cPack.h"
#include "cHand.h"
#include "cPlayer.h"
#include "cHumanPlayer.h"
#include "cDealer.h"

using namespace std;

int main()
{
	// Variables

	cout << "\t\tWelcome to Blackjack!\n\nDealer stands on soft 17\nBlackjack pays 3:2\n\n" << std::endl;

	cPack deck;

	// Get player name

	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl;
	// Create Dealer object

	cDealer dealer = cDealer("Dealer");

	// Create player object

	cHumanPlayer player = cHumanPlayer(name);

	// ----- GAME LOOP -----

	// Replay unless the player has run out of chips
	while (player.getChipCount() > 0) {
		cout << player.getPlayerName() << "s chips: " << player.getChipCount() << endl; // Displays the players chip count

		int stake = 0; // The stake is stored throughout the hand
		do {
			cout << "\nEnter your desired stake." << endl; // Ask the player to enter their stake
			cin >> stake;

			// If statements to check that the player has made a valid bet

			if (stake < 1) {
				cout << "Invalid bet. The minimum bet is 1 chip." << endl;
			}
			else if (stake > player.getChipCount()) {
				cout << "Invalid bet. You cannot bet more chips than you have." << endl;
			}
			else if (stake > 10000) {
				cout << "Invalid bet. The maximum bet is 10000 chips." << endl;
			}
		// While loop ensures the player has made a valid bet
		} while (stake < 1 || stake > 10000 || stake > player.getChipCount());
#
		// Deduct the players chips from them

		player.setChipCount(-stake);

		// Deal Cards

		for (int i = 0; i < 2; i++)
		{
			dealer.setPlayerHand(deck.getCard());
			player.setPlayerHand(deck.getCard());
		}

		// Show the players hand
		player.showPlayerHand();
		cout << endl << "\nYou have a total of " << player.getPlayerHandValue() << ".\n" << std::endl;

		// If the dealer has blackjack, there is no need to see what they are showing
		if (!dealer.pHasNatural())
		{
			dealer.flipFirstCard();
			dealer.showPlayerHand();
			cout << endl << "The dealer is showing " << dealer.getPlayerHandValue() << ".\n" << std::endl;
		}

		// Check player wants to hit, stand (or double down) if they are not bust or have 21 already
		// If the dealer has blackjack, skip this section
		while (!player.pIsBust() && player.getPlayerHandValue() != 21 && !dealer.pHasNatural()) {
			
			// Method returns 0 = Stand, 1 = Hit or 2 = Double Down; depending on the players decision
			int move = player.pPlay(player, stake);

			// If the player dosen't stand
			if (move > 0) {
				player.setPlayerHand(deck.getCard()); // Draw another card
				player.showPlayerHand(); // Show the player their new hand
				if (move == 1) {
					// If the player has hit, tell them their current total
					cout << endl << "You now have a total of " << player.getPlayerHandValue() << ".\n" << endl;
				}
				else {
					// Double the players stake and remove the required amount from their stack
					player.setChipCount(-stake);
					stake *= 2;
					// Tell them their final total and break from the while loop
					cout << endl << "You doubled down and got " << player.getPlayerHandValue() << ".\n" << endl;
					break;
				}
			}
			else {
				// If the player stands, tell them their final total
				cout << endl << "You stood on " << player.getPlayerHandValue() << ".\n" << endl;
				break;
			}
		}

		// If the player is bust, their is no need to play the dealers hand out
		if (player.pIsBust()) {
			cout << "You busted!\n" << endl;
		}
		else {
			// Show the dealers full hand after flipping their other card
			dealer.flipFirstCard();
			dealer.showPlayerHand();
			cout << "\nThe dealer has " << dealer.getPlayerHandValue() << ".\n" << endl;

			// As long as the dealer is neither bust, has Blackjack or a total above 16, keep drawing cards
			while (!dealer.pIsBust() && !player.pHasNatural()) {
				if (dealer.pIsTwisting()) {
					dealer.setPlayerHand(deck.getCard());
					// Show the dealers new hand
					dealer.showPlayerHand();
					cout << endl << "The dealer now has " << dealer.getPlayerHandValue() << ".\n" << endl;
				}
				else {
					// Display the dealers final score if they stand
					cout << endl << "Dealer stands on " << dealer.getPlayerHandValue() << ".\n" << endl;
					break;
				}
			}

			// Display if the dealer has bust
			if (dealer.pIsBust()) {
				cout << "The dealer busted!\n" << endl;
			}
		}

		cout << endl;

		// Check for winner

		// Pushed blackjack
		if (player.pHasNatural() && dealer.pHasNatural()) {
			cout << "Both " << player.getPlayerName() << " and the Dealer had Blackjack. The hand is a push." << endl;
			
			// Player recieves their original stake back
			player.setChipCount(stake);
		}
		// Player blackjack
		else if (player.pHasNatural()) {
			cout << player.getPlayerName() << " had Blackjack. You win!" << endl;

			// Player receives twice and a half of their original stake plus
			player.setChipCount(stake * 2.5f);
		}
		// Dealer blackjack
		else if (dealer.pHasNatural()) {
			cout << "The Dealer had Blackjack. You lose." << endl;
		}
		// Player bust
		else if (player.pIsBust()) {
			cout << player.getPlayerName() << " went bust. You lose." << endl;
		}
		// Dealer bust
		else if (dealer.pIsBust()) {
			cout << "The dealer went bust. You win!" << endl;

			// Player recieves twice their original stake
			player.setChipCount(stake * 2);
		}
		// Player wins
		else if (player.getPlayerHandValue() > dealer.getPlayerHandValue()) {
			cout << player.getPlayerName() << "s " << player.getPlayerHandValue() << " beats the Dealers " << dealer.getPlayerHandValue() << ". You win!" << endl;
			
			// Player recieves twice their original stake
			player.setChipCount(stake * 2);
		}
		// Dealer wins
		else if (dealer.getPlayerHandValue() > player.getPlayerHandValue()) {
			cout << "The Dealers " << dealer.getPlayerHandValue() << " beats " << player.getPlayerName() << "s " << player.getPlayerHandValue() << ". You lose." << endl;
		}
		// Draw
		else {
			cout << player.getPlayerName() << "s hand was the same as the Dealers. The hand is a push." << endl;

			// Player recieves their original stake back
			player.setChipCount(stake);
		}

		// If player is out of chips, break from the game loop and end the game

		if (player.getChipCount() <= 0) {
			cout << "Game over. You are out of chips!" << endl;
			break;
		}

		// Ask player if they want to play again

		char response;
		do {
			// Show the player their current chip total before asking if they want to play on
			cout << player.getPlayerName() << ", you have " << player.getChipCount() << " chips. Do you want to play again? (Y/N): ";
			cin >> response;
			cout << "\n";
		} while (response != 'n' && response != 'y');
		if (response == 'n') {
			cout << "Thank you for playing!" << endl;
			break;
		}

		// Clear both players hands and reshuffle the deck

		player.clearHand();
		dealer.clearHand();
		deck.shufflePack();;
	}

	// ----- END GAME LOOP -----

	system("PAUSE");
	return 0;
}