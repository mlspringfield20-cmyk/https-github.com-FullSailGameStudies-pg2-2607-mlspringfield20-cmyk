#include <iostream>
#include <vector>
#include <string>
#include "PG2Graphics.h"
#include "Console.h"
#include "Sorter.h"
#include "Searcher.h"
#include <map>
#include <Input.h>
#include "CardMaker.h"
#include <GameTextures.h>
#include "Tester.h"


//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

void ShowMenu(const std::vector<std::string>& menuOptions)
{
	std::cout << "\n\nLab 2 Menu: \n";
	for (auto& option : menuOptions)
	{
		std::cout << option << "\n";
	}
	std::cout << "\nSelect an option: \n";
}

void ShowCards(PG2Graphics& engine, const std::vector<Card>& cards, int row = 0)
{
	float scale = 1.0F;

	pos cardSize = GameTextures::CardSize(scale);
	int x = 5;
	int y = cardSize.y * row + 5 + 5 * row;

	std::string suit = "";
	for (auto& card : cards)
	{
		GameTextures::RenderImage(card.Face(), card.Suit(), x, y, scale);
		x += cardSize.x + 5;
	}

}

const int A2_WIDTH = 1024;
const int A2_HEIGHT = 550;
const int MESSAGE_X = 512;
const int MESSAGE_Y = 500;
int main(int argc, char* args[])
{
	Tester tests;
	srand(static_cast<unsigned int>(time(NULL)));

	//
	//create the 13 cards for 1 suit
	std::vector<Card> clubs;
	CardMaker::GetCardsForSuit(CardSuit::Clubs, clubs);
	CardMaker::ShuffleCards(clubs);

	std::vector<Card> deckOfCards;
	CardMaker::GetCardsForAllSuits(deckOfCards);
	CardMaker::ShuffleCards(deckOfCards);



	//
	// TODO: Part B-2 Build a map with the suit as the key and a vector of the cards for the suit as the value
	//
	std::map<CardSuit, std::vector<Card>> groups;



	PG2Graphics engine(A2_WIDTH, A2_HEIGHT);
	if (!engine.Init("PG2 - Lab 2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part A-2 Sorting", ConsoleColor::Green);
		Console::WriteLine("MergeSort Cards.");


		GameTextures::Initialize(engine.Renderer());

		std::vector<std::string> menuOptions{
			"1. InsertionSorted Cards", "2. MergeSorted Cards", "3. Search Cards",
			"4. Group Cards: Show All", "5. \tGroup Cards: Show Hearts","6. \tGroup Cards: Show Clubs","7. \tGroup Cards: Show Diamonds","8. \tGroup Cards: Show Spades",
			"9. Remove Suit",
			"0. Exit" };
		ShowMenu(menuOptions);



		engine.ClearScreen(0, 0, 0, 0xFF);
		bool quit = false;
		bool displayIdleMenu = true;
		std::string title = "";

		SDL_Event e;
		while (!quit)
		{
			if (displayIdleMenu)
			{
				engine.ClearScreen(50, 150, 50, 255);
				GameTextures::DrawText("Waiting for input...");
				engine.Present();
			}

			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
				{
					quit = true;
				}
				else if (e.type == SDL_KEYUP && e.key.repeat == 0)
				{
					displayIdleMenu = false;

					engine.ClearScreen(50, 150, 50, 255);
					title = "";

					switch (e.key.keysym.sym)
					{
					case SDLK_KP_1:
					case SDLK_1:
					{
						std::vector<Card> insertionSortedCards = clubs;
						//
						// TODO: Part A-1.2
						// call your InsertionSort
						//
						Sorter sorter;

						float scale = 1.0F;
						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						CardSuit suit = CardSuit::END;
						for (auto& card : insertionSortedCards)
						{
							if (suit == CardSuit::END) suit = card.Suit();
							else if (suit != card.Suit())
							{
								suit = card.Suit();
								x = 5;
								y += cardSize.y + 5;
							}

							GameTextures::RenderImage(card.Face(), card.Suit(), x, y, scale);
							x += cardSize.x + 5;
						}

						//set title
						title = "1. InsertionSorted Cards";
						break;
					}
					case SDLK_KP_2:
					case SDLK_2:
					{
						std::vector<Card> mergeSortedCards = clubs;
						//
						// TODO: Part A-2.3 
						// call your MergeSort
						//
						Sorter sorter;

						float scale = 1.0F;
						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = cardSize.y + 5;

						CardSuit suit = CardSuit::END;
						for (auto& card : mergeSortedCards)
						{
							if (suit == CardSuit::END) suit = card.Suit();
							else if (suit != card.Suit())
							{
								suit = card.Suit();
								x = 5;
								y += cardSize.y + 5;
							}

							GameTextures::RenderImage(card.Face(), card.Suit(), x, y, scale);
							x += cardSize.x + 5;
						}

						//set title
						title = "2. MergeSorted Cards";
						break;
					}
					case SDLK_KP_3:
					case SDLK_3:
					{
						std::vector<Card> sortedCards;
						CardMaker::GetCardsForSuit(CardSuit::Clubs, sortedCards);
						Card randoCard = CardMaker::GetRandomCardForSuit(CardSuit::Clubs);
						//
						// TODO: Part B-1.2
						// call BinarySearch to find the index of the card in the sorted vector
						// print the index of the card to the console
						//
						int index = -1;
						Searcher searcher;


						float scale = 1.0F;
						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						CardSuit suit = CardSuit::END;
						for (auto& card : sortedCards)
						{
							if (suit == CardSuit::END) suit = card.Suit();
							else if (suit != card.Suit())
							{
								suit = card.Suit();
								x = 5;
								y += cardSize.y + 5;
							}

							GameTextures::RenderImage(card.Face(), card.Suit(), x, y, scale);
							x += cardSize.x + 5;
						}
						y += cardSize.y + 5;
						x = (cardSize.x + 5) * index + 5;
						GameTextures::RenderImage(randoCard.Face(), randoCard.Suit(), x, y, scale);

						//set title
						title = "3. Search Cards";
						break;
					}
					case SDLK_KP_4:
					case SDLK_4:
					{
						//
						// TODO: Part B-3
						// loop over the map
						//	  call ShowCards for the vector of each suit
						//		1st parameter: pass the engine variable
						//      2nd parameter: pass the vector for each suit to the ShowCards method.
						//      3rd parameter: pass the row. each suit should be printed on a separate row.
						//    increment row after calling ShowCards
						//		
						int row = 0;

						//set title
						title = "4. Group Cards: Show All";
						break;
					}
					case SDLK_KP_5:
					case SDLK_5:
					{
						//
						// TODO: Part C-1.1
						//

						//set title
						title = "5. Group Cards: Show Hearts";
						break;
					}
					case SDLK_KP_6:
					case SDLK_6:
					{
						//
						// TODO: Part C-1.2
						//

						//set title
						title = "6. Group Cards: Show Clubs";
						break;
					}
					case SDLK_KP_7:
					case SDLK_7:
					{
						//
						// TODO: Part C-1.3
						//

						//set title
						title = "7. Group Cards: Show Diamonds";
						break;
					}
					case SDLK_KP_8:
					case SDLK_8:
					{
						//
						// TODO: Part C-1.4
						//

						//set title
						title = "8. Group Cards: Show Spades";
						break;
					}
					case SDLK_KP_9:
					case SDLK_9:
					{
						//
						// TODO: Part C-2
						//
						int row = 0;

						//set title
						title = "9. Remove Suit";
						break;
					}
					case SDLK_KP_0:
					case SDLK_0:
					{
						quit = true;
						break;
					}

					}
					GameTextures::DrawText(title, MESSAGE_X, MESSAGE_Y);
					engine.Present();
				}
			}

		}


		GameTextures::Cleanup();
	}
	engine.Close();

	return 0;
}
