#ifndef MAZEHEADER_H
#define MAZEHEADER_H
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

class Room
{
private:
	std::string roomName;          // town's name    
	Room* next;            // link to next
public:
	Room();                // no argument constructor
	Room(std::string name, std::string ln, std::string le, std::string ls, std::string lw);
	void setNext(Room* nextNode);

	std::string getRoomProp();
	bool getRoomExit(std::string m);
	Room* getNext();
	std::string getName();
	std::string n, e, s, w;
};

class RoomList
{
private:
	Room * start, *end;

public:
	RoomList();
	bool isEmpty();
	void addFirstRoom(std::string name, std::string ln, std::string le, std::string ls, std::string lw);
	void addRoomAtEnd(std::string name, std::string ln, std::string le, std::string ls, std::string lw);
	void listAllNames();
	void findRoom(std::string roomName);
	void newFirstPositionRoom(std::string name, std::string ln, std::string le, std::string ls, std::string lw);
	Room* getStart();
	Room* getRoom(std::string __input, Room* CurrentRoom);


};
class FileReader
{
public:
	std::string graphArray[12][5];
	void ReadMaze(std::string file);

};
#endif