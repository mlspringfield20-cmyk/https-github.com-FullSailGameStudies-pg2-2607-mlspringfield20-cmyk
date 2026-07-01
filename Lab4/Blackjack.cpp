#include <iostream>
#include "Console.h"
#include "Input.h"
#include "WarGame.h"
#include "HighScore.h"
#include "Tester.h"
#include "BlackjackGame.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include "GameConfig.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main(int argc, char* args[])
{
	//turn on automatic leak check at program exit
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);// Report memory leaks when the process terminates
	_CrtSetBreakAlloc(-1); //break on a specific allocation number if you know it
	_CrtDumpMemoryLeaks();// Explicit dump (not strictly necessary if LEAK_CHECK_DF is set)

	srand(static_cast<unsigned int>(time(NULL)));

	Tester tests;
	Console::ResizeWindow(150, 30);

	std::string playerExtension = ".psv";
	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Load Config", "2. New Player", "3. Load Player", "4. Play Blackjack", "5. Exit" };

	std::string configExtension = ".configSV";
	std::string configFile = "smallFish.configSV";
	GameConfig config;

	BlackjackPlayer p1;

	do
	{
		Console::Clear();
		if (p1.Name().size() > 0)
		{
			std::cout << "Current player: " << p1.Name() << "\n";
		}
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// TODO: Part A-1.2: List config files
			//
			std::string path = "./"; //use current directory
			

			//
			// TODO: Part A-1.3: Load Game Config
			//

			break;
		}
		case 2:
		{
			//
			// TODO: Part B-1.3: SavePlayer
			//

			break;
		}
		case 3:
		{

			try 
			{
				//
				// TODO: Part A-2: List Players
				//
				std::string path = "./"; //use current directory


				//
				// TODO: Part B-2.4: LoadPlayer
				//
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "Filesystem error: " << e.what() << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << "General error: " << e.what() << std::endl;
			}

			break;
		}
		case 4:
		{
			if (not p1.Name().empty())
			{
				BlackjackGame game(config.NumberOfPlayers, config.NumberOfDecks, config.MinimumBet);
				game.Play(p1);
			}
			else
			{
				std::cout << "Please load a player first.\n";
			}
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}