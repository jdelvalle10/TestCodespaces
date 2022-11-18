/* 	Program name: D.A. Inventory Management System
	Description: This program is designed to store, clasify and query
	the Doral Academy clasrooms asset's inventory
	Author: Jose L. Del Valle
*/

// Libraries
#include <iostream>
using namespace std;

// User-Defined Data Types

typedef struct {
	int smartBoards; // Number of smartBoards
	int corkBoards;
	int whiteBoards;
}tBoard;

typedef struct {
	char building; // Building letter
	int roomNumber; // Room number
	int seats; // Number of seats
	int computers; // Number of PCs in the classroom
	int tvs; // Number of TVs/Monitors in the classroom
	tBoard boards; // Data Type to store board specifications

}tClassroom;

typedef struct {
	int numClass;
	tClassroom room[200];
}tSchool;


// User-Defined Function headers

void clearScreen();
void mainMenu();
void loadMockData();
void printSummary();
void exitProgram();
void printBanner();
void addNewClass();
int findRoom(int room, char building);
void editRoom();
void printRoomData(int room);
void sortRooms();
void sortBySeats();
void sortByBuilding();

// Global Variables
tSchool doral; // Table with the inventory of each classroom in 
// Doral Academy
int option = 99;
bool wantExit = false;
char test;

int main() {
	loadMockData();
	while (wantExit == false) {
		mainMenu();
		cout << "Enter option number -> ";
		cin >> option;
		switch (option) {
		case 1:
			printSummary();
			break;
		case 2:
			addNewClass();
			break;
		case 3:
			editRoom();
			break;
		case 5:
			cout << "HEY!";
			//cin >> test;
			sortRooms();
			break;
		case 0:
			exitProgram();
			wantExit = true;
			break;
		default:
			break;
		}
	}

}

// User-Defined Function Implementations

// Procedure to clear the screen
void clearScreen() {
	cout << "\033[2J\033[1;1H";
}

// Procedure to show the main menu
void mainMenu() {
	clearScreen();
	printBanner();
	cout << "              WELCOME! \n" << endl;
	cout << "1. Print Summary\n";
	cout << "2. Add new classroom\n";
	cout << "3. Edit classroom\n";
	cout << "4. Delete classroom\n";
	cout << "5. Sort Rooms\n";
	cout << "0. Exit\n\n";
	cout << "=======================================" << endl;

}

// This procedure will load the database with random data, for testing porpuses

void loadMockData() {
	doral.numClass = 3;
	//
	doral.room[0].building = 'A';
	doral.room[0].roomNumber = 102;
	doral.room[0].seats = 32;
	doral.room[0].computers = 32;
	doral.room[0].tvs = 2;
	doral.room[0].boards.corkBoards = 1;
	doral.room[0].boards.smartBoards = 1;
	doral.room[0].boards.whiteBoards = 3;
	//
	doral.room[1].building = 'B';
	doral.room[1].roomNumber = 212;
	doral.room[1].seats = 80;
	doral.room[1].computers = 2;
	doral.room[1].tvs = 0;
	doral.room[1].boards.corkBoards = 2;
	doral.room[1].boards.smartBoards = 1;
	doral.room[1].boards.whiteBoards = 1;
	//
	doral.room[2].building = 'B';
	doral.room[2].roomNumber = 117;
	doral.room[2].seats = 15;
	doral.room[2].computers = 7;
	doral.room[2].tvs = 12;
	doral.room[2].boards.corkBoards = 0;
	doral.room[2].boards.smartBoards = 1;
	doral.room[2].boards.whiteBoards = 0;
}

// Function that prints the total by each value in the database

void printSummary() {
	int totalClassrooms = doral.numClass;
	int totalComputers = 0;
	int totalSeats = 0;
	int totalTvs = 0;
	int totalCorkB = 0;
	int totalSmartB = 0;
	int totalWhiteB = 0;

	// This calculates the totals by field
	for (int i = 0; i < totalClassrooms; i++) {
		totalSeats = totalSeats + doral.room[i].seats;
		totalComputers = totalComputers + doral.room[i].computers;
		totalTvs = totalTvs + doral.room[i].tvs;
		totalCorkB = totalCorkB + doral.room[i].boards.corkBoards;
		totalSmartB = totalSmartB + doral.room[i].boards.smartBoards;
		totalWhiteB = totalWhiteB + doral.room[i].boards.whiteBoards;
	}

	clearScreen();
	char cont;
	printBanner();
	cout << "             INVENTORY SUMMARY\n\n";
	cout << "The school has a total of: \n\n";
	cout << totalSeats << " seats,\n";
	cout << totalComputers << " computers,\n";
	cout << totalTvs << " TV's\n";
	cout << totalCorkB << " corkboards\n";
	cout << totalWhiteB << " whiteboards, and\n";
	cout << totalSmartB << " smartboards\n";
	cout << "=======================================" << endl;
	cout << "\nContinue? (Y/y) ->  ";
	cin >> cont;

}

void exitProgram() {
	clearScreen();
	printBanner();
	cout << "                        Bye! See you soon!\n\n";
}

void printBanner() {
	cout << "***  ***  ***   ***  ***   ********   ***  ***   ********   ********   ********   ***  ***\n";
	cout << "***  ***  ***   ***  ***   ***        ***  ***      **      ***  ***   **   ***   ***  ***\n";
	cout << "***  ****  **    **  **    ********   ****  **      **      ***  ***   *******     **  **\n";
	cout << "***  ** *  **     *  *     ***        ** *  **      **      ***  ***   *** ***       **\n";
	cout << "***  **  ****     *  *     ********   **  ****      **      ***  ***   *** ***       **\n";
	cout << "***  ***  ***      **      ********   **   ***      **      ********   *** ***       **\n\n";
}

void addNewClass() {
	char answer;
	clearScreen();
	printBanner();
	int n = doral.numClass;

	cout << "Add classroom:\n\n";
	cout << "--------------------\n";

	cout << "Building? (A, B, C, D, or H) -> ";
	cin >> doral.room[n].building;

	cout << "Room number -> ";
	cin >> doral.room[n].roomNumber;

	cout << "Number of Computers -> ";
	cin >> doral.room[n].computers;

	cout << "Number of TV's -> ";
	cin >> doral.room[n].tvs;

	cout << "Number of seats -> ";
	cin >> doral.room[n].seats;

	cout << "Number of corkboards -> ";
	cin >> doral.room[n].boards.corkBoards;

	cout << "Number of smartboards -> ";
	cin >> doral.room[n].boards.smartBoards;

	cout << "Number of whiteboards -> ";
	cin >> doral.room[n].boards.whiteBoards;

	// Display the data just entered.
	cout << "\nConfirmation:\nRoom " << doral.room[n].roomNumber << doral.room[n].building << endl;
	cout << doral.room[n].seats << " seats,\n";
	cout << doral.room[n].computers << " computers \n";
	cout << doral.room[n].tvs << " TV's\n";
	cout << doral.room[n].boards.corkBoards << " corkboards, " << doral.room[n].boards.smartBoards << " smartboards, and " << doral.room[n].boards.whiteBoards << " whiteboards. \n\n";
	cout << "Number of classrooms: " << doral.numClass << endl;
	cout << "Save new classroom? (Y/y) -> ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		doral.numClass++;
	}


}

// This funtion locates the room in the table. If found, returns the room's index
// else, returns 99

int findRoom(int room, char building) {
	bool found = false;
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == building && doral.room[i].roomNumber == room) {
			return i;
		}
	}
	return 99;
}

void editRoom() {
	int number;
	char build, answer;
	int index, room;

	clearScreen();
	printBanner();
	cout << "Enter the room number (only digits) -> ";
	cin >> number;
	cout << "Enter room's building -> ";
	cin >> build;
	room = findRoom(number, build);
	if (room == 99) {
		cout << "\n[ERROR] That room does not exist! Try again.\n Done? (Y/y) ";
		cin >> answer;
	}
	else {
		printRoomData(room);
		cout << "New number of seats -> ";
		cin >> doral.room[room].seats;
		cout << "New number of Computers -> ";
		cin >> doral.room[room].computers;
		cout << "New number of TV's -> ";
		cin >> doral.room[room].tvs;
		cout << "New number of SmartBoards -> ";
		cin >> doral.room[room].boards.smartBoards;
		cout << "New number of WhiteBoards -> ";
		cin >> doral.room[room].boards.whiteBoards;
		cout << "New number of Corkboards -> ";
		cin >> doral.room[room].boards.corkBoards;
		cout << "Done? (Y/y) -> ";
		cin >> answer;
		cout << "New Data: \n";
		printRoomData(room);
	}
}

void printRoomData(int room) {
	char answer;
cout << doral.room[room].roomNumber << "-" << doral.room[room].building << endl;
cout << "Seats: " << doral.room[room].seats << " Computers: " << doral.room[room].computers << " TV's: " << doral.room[room].tvs << " SBs: " << doral.room[room].boards.smartBoards << " WBs: " << doral.room[room].boards.whiteBoards << " CB's: " << doral.room[room].boards.corkBoards << endl;

}


void sortRooms() {
	int option2 = 99;
	clearScreen();
	cout << "              SORT ROOMS \n" << endl;
	cout << "1. By number of seats\n";
	cout << "2. By building \n";
	cout << "0. Exit \n";
	cout << "=======================================" << endl;
	cout << "Option -> ";
	cin >> option2;
	switch (option2) {
		case 1:
			sortBySeats();
			break;
		case 2:
			sortByBuilding();
			break;
		default:
			break;
		}
}

void sortBySeats() {
	char answer;
	tClassroom aux{};
	for (int j = 0; j < doral.numClass - 1; j++) {
		for (int i = 0; i < doral.numClass - 1; i++) {
			if (doral.room[i].seats < doral.room[i + 1].seats) {
				aux = doral.room[i];
				doral.room[i] = doral.room[i + 1];
				doral.room[i + 1] = aux;
			}
		}
	}
	for (int i = 0; i < doral.numClass; i++) {
		printRoomData(i);
	}
	cout << "\nDone? (Y/y) -> ";
	cin >> answer;
}

void sortByBuilding() {
	char answer;
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == 'A' || doral.room[i].building == 'a') {
			printRoomData(i);
		}
	}
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == 'B' || doral.room[i].building == 'b') {
			printRoomData(i);
		}
	}
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == 'C' || doral.room[i].building == 'c') {
			printRoomData(i);
		}
	}
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == 'D' || doral.room[i].building == 'c') {
			printRoomData(i);
		}
	}
	for (int i = 0; i < doral.numClass; i++) {
		if (doral.room[i].building == 'H' || doral.room[i].building == 'h') {
			printRoomData(i);
		}
	}
	cout << "\nDone? (Y/y) -> ";
	cin >> answer;
}
