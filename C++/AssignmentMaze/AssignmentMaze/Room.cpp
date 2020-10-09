#include "MazeHeader.h"


Room::Room()
{

}

Room::Room(std::string name, std::string ln, std::string le, std::string ls, std::string lw)
{
	roomName = std::string(name);  // store name
	this->n = ln;
	this->e = le;
	this->s = ls;
	this->w = lw;
	next = NULL;                  // initialise next
}

void Room::setNext(Room* nextNode)
{
	next = nextNode;  // change next node
}

Room* Room::getNext()
{
	return next;
}

std::string Room::getRoomProp()
{
	std::string line = this->roomName + n + e + s + w;

	return line;
}

Room* RoomList::getRoom(std::string _input, Room* CurrentRoom)
{
	std::string _room;
	Room* current;
	current = CurrentRoom;
	if (_input == "N")
	{
		_room = current->n;
	}
	if (_input == "E")
	{
		_room = current->e;
	}
	if (_input == "S")
	{
		_room = current->s;
	}
	if (_input == "W")
	{
		_room = current->w;
	}
	while (current->getName() != _room)
	{
		if (current->getNext() == NULL)
		{
			current = start;
		}
		else
		{
			current = current->getNext();
		}
	}
	return current;
}

RoomList::RoomList()
{
	start = NULL;   // both set to NULL
	end = NULL;
}

bool RoomList::isEmpty()
{
	return start == NULL;
}

void RoomList::addFirstRoom(std::string name, std::string ln, std::string le, std::string ls, std::string lw)
{
	/*cout<<"Adding town "<<name <<" at start"<<endl<<endl;*/
	Room* current;
	current = new Room(name, ln, le, ls, lw);  // allocate memory
	start = current;               // change start 
	end = current;				  // and end
}

void RoomList::addRoomAtEnd(std::string name, std::string ln, std::string le, std::string ls, std::string lw)
{
	/* cout<<"Adding town "<<name << " at end"<<endl<<endl;*/

	Room* current;

	if (end == NULL)       // if list is empty
		addFirstRoom(name, ln, le, ls, lw);
	else
	{
		current = new Room(name, ln, le, ls, lw);   // allocate memory
		end->setNext(current);          // change end's next
		end = current;                  // change end
	}
}

Room* RoomList::getStart()
{
	return this->start;
}
std::string Room::getName()
{
	return this->roomName;
}
bool Room::getRoomExit(std::string i)
{
	if (i == "n")
	{
		if (this->n != "*")
		{
			return TRUE;
		}
	}
	if (i == "e")
	{
		if (this->e != "*")
		{
			return TRUE;
		}

	}
	if (i == "s")
	{
		if (this->s != "*")
		{
			return TRUE;
		}

	}
	if (i == "w")
	{
		if (this->w != "*")
		{
			return TRUE;
		}
	}
}
void RoomList::findRoom(std::string roomName)
{
	Room* current;
	current = start;
	while (current->getName() != roomName)
	{
		current->getNext();
	}
}
void RoomList::listAllNames()
{
	Room* current;

	if (!isEmpty())
	{
		std::cout << "Start of List" << std::endl;
		current = start;
		while (current != NULL)
		{
			// Funny syntax here as we have to de-reference a pointer to a pointer
			std::cout << "Next town is: " << (current->getRoomProp()) << std::endl;
			current = current->getNext();
		}
		std::cout << "End of List" << std::endl << std::endl;
	}
	else
		std::cout << "List empty" << std::endl << std::endl;
}
void RoomList::newFirstPositionRoom(std::string name, std::string ln, std::string le, std::string ls, std::string lw)
{


	if (end == NULL)       // if list is empty
		addFirstRoom(name, ln, le, ls, lw);
	else
	{
		Room* current = new Room(name, ln, le, ls, lw); //Allocate new memory location for new object

		current->setNext(start);	//Set Current Object next pointer to start* Object
		start = current;	 		//Set start* to current object

	}


}
