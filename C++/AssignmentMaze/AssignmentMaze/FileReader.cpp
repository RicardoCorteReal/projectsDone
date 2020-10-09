#include "MazeHeader.h"


void FileReader::ReadMaze(std::string localFileName)
{
	std::string line;
	std::ifstream mazeFile;
	mazeFile.open(localFileName.c_str());
	int test = mazeFile.peek();

	int i = 0;
	std::string nodeName;
	std::string n, e, s, w;
	int totalNodes = 0;
	if (!(mazeFile.fail()))
	{
		while (mazeFile >> nodeName >> n >> e >> s >> w)//COUNTS FOR RESERVATION
		{
			graphArray[i][0] = nodeName;
			graphArray[i][1] = n;
			graphArray[i][2] = e;
			graphArray[i][3] = s;
			graphArray[i][4] = w;
			i++;
		}


	}
	else
	{
		std::cout << "The file name that was entered couldn't be opened." << std::endl;
		exit(1);
	}
}
