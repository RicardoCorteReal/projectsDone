#include "MazeHeader.h"


int main()
{
	// Read from the file, the map
	std::string FileName;
	FileReader myMaze;
	RoomList* mainList = new RoomList();
	std::string userInput;

	int stepCounter = 0;
	std::string optionNorth;
	std::string optionEast;
	std::string optionSouth;
	std::string optionWest;



	//This will read from the folder "debug" which, you have to type "Maze" for it to work.
	std::cout << "Please enter the name of the file: ";

	getline(std::cin, FileName);        // gets input from user to read the file 
	FileName += ".txt";
	std::string fileLocation = "C:\\" + FileName;
	myMaze.ReadMaze(fileLocation);         // initialize the map

	mainList->addFirstRoom(myMaze.graphArray[0][0], myMaze.graphArray[0][1], myMaze.graphArray[0][2], myMaze.graphArray[0][3], myMaze.graphArray[0][4]);
	for (int s = 1; s <12; s++)
	{
		mainList->addRoomAtEnd(myMaze.graphArray[s][0], myMaze.graphArray[s][1], myMaze.graphArray[s][2], myMaze.graphArray[s][3], myMaze.graphArray[s][4]);
	}

	Room* currentPosition(mainList->getStart());

	std::cout << "WELCOME TO THE MAZE, HAVE FUN!" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << std::endl;

	while (currentPosition->getName() != "L")
	{

		optionNorth = "";
		optionEast = "";
		optionSouth = "";
		optionWest = "";

		std::cout << "You are in room [" << currentPosition->getName() << "] of the maze." << std::endl;
		std::cout << "Where do you want to go next?" << std::endl;



		if (currentPosition->getRoomExit("n") == TRUE)
		{
			optionNorth = " (N)orth,";
		}
		if (currentPosition->getRoomExit("e") == TRUE)
		{
			optionEast = " (E)ast,";
		}
		if (currentPosition->getRoomExit("s") == TRUE)
		{
			optionSouth = " (S)outh,";
		}
		if (currentPosition->getRoomExit("w") == TRUE)
		{
			optionWest = " (W)est,";
		}
		std::cout << "You can go" << optionNorth << optionEast << optionSouth << optionWest << "or (Q)uit." << std::endl;
		std::cin >> userInput;

		if (userInput == "n" || userInput == "N")
		{
			if (currentPosition->getRoomExit("n") != TRUE)
			{
				std::cout << "Incorrect input." << std::endl;
			}
			else
			{
				currentPosition = mainList->getRoom("N", currentPosition);
			}
		}
		if (userInput == "e" || userInput == "E")
		{
			if (currentPosition->getRoomExit("e") != TRUE)
			{
				std::cout << "Incorrect input." << std::endl;
			}
			else
			{
				currentPosition = mainList->getRoom("E", currentPosition);
			}
		}
		if (userInput == "s" || userInput == "S")
		{
			if (currentPosition->getRoomExit("s") != TRUE)
			{
				std::cout << "Incorrect input." << std::endl;
			}
			else
			{
				currentPosition = mainList->getRoom("S", currentPosition);
			}
		}
		if (userInput == "w" || userInput == "W")
		{
			if (currentPosition->getRoomExit("w") != TRUE)
			{
				std::cout << "Incorrect input." << std::endl;
			}
			else
			{
				currentPosition = mainList->getRoom("W", currentPosition);
			}
		}
		if (userInput == "q" || userInput == "Q")
		{
			std::cout << "Thanks for playing." << std::endl;
			std::cout << "You took " << stepCounter << " steps." << std::endl;
			system("Pause");
			exit(0);
		}
		std::cout << std::endl;
		stepCounter++;

	}
	std::cout << "Congrats you won lol." << std::endl;
	std::cout << "You took " << stepCounter << " steps." << std::endl;
	system("PAUSE");
	return 0;
}



