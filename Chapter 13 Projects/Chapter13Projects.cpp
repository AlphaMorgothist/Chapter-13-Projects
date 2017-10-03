// Chapter 13 Projects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <ctime>
#include <sstream>
using namespace std;


// Jumble
void jumble() {

	// Random Seed
	srand(time(0));

	// Word/Hint Vectors
	vector<string> Word = {
		{ "zeus" },{ "thor" },{ "bryan" }
	};
	vector<string> Hints = {
		{ "God of Lightning" },{ "His hammer can only be wielded by the worthy" },{ "He is the only Magic player to have the 'I win' card by default." }
	};

	//Input vars
	string resp;
	string addVec;
	string winWord;
	string addHint;

	// Main Game Loop
	while (true) {

		int tries = 0;
		int hints = 0;
		cout << "\n\t\t\tWelcome to UNSCRAMBLE!" << endl;
		cout << "\t\t\t\tBy Morgoth\n" << endl;
		if (Word.empty()) {
			cout << "Before we begin, who is your favourite mythical person/being?" << endl;
			getline(cin, addVec);
			Word.push_back(addVec);
			cout << "\nWow, " << addVec << " you say? I would never have guessed." << endl;
			cout << "Okay, how would you describe " << addVec << " without using it's name?" << endl;
			getline(cin, addHint);
			Hints.push_back(addHint);
		}
		int rC = (rand() % Word.size());
		winWord = Word[rC];
		random_shuffle(Word[rC].begin(), Word[rC].end());

		while (true) {

			cout << "\n\t\tWord to Unscramble: ";
			cout << Word[rC] << endl;
			cout << "\nType 'hint' for a hint" << endl;
			cout << "Type 'refresh' to get a new word" << endl;
			cout << "Type 'new' to input a new word to scramble!" << endl;
			cout << "Type 'quit' to quit" << endl;
			cout << "\nResponse: ";
			getline(cin, resp);
			system("CLS");
			if (resp == "new") {
				Word[rC] = winWord;
				cout << "Before we begin, who is your favourite mythical person/being?" << endl;
				getline(cin, addVec);
				Word.push_back(addVec);
				cout << "\nWow, " << addVec << " you say? I would never have guessed." << endl;
				cout << "Okay, how would you describe " << addVec << " without using it's name?" << endl;
				getline(cin, addHint);
				Hints.push_back(addHint);
				system("CLS");
				break;
			}
			else if (resp == "refresh") {

				Word[rC] = winWord;
				break;
			}
			else if (resp == "quit") {
				cout << "\nThanks for playing!!" << endl;
				system("pause");
				break;
			}
			else if (resp == winWord) {
				tries++;
				cout << "\nCONGRATS! YOU WIN!!!" << endl;
				cout << "You got the answer in " << tries << " tries." << endl;
				cout << "You used " << hints << " hints" << endl;
				cout << "Thanks for playing!!" << endl;
				Word.erase(remove(Word.begin(), Word.end(), Word[rC]), Word.end());
				Hints.erase(remove(Hints.begin(), Hints.end(), Hints[rC]), Hints.end());
				system("pause");
				system("CLS");
				break;
			}
			else if (resp != winWord && resp == "hint") {
				cout << "\nHint: " << Hints[rC] << endl;
				hints++;
			}
			else if (resp != winWord) {
				cout << "\nThat's the wrong word! Try again." << endl;
				tries++;
			}
		}
		if (resp == "quit") {
			break;
		}
	}
}

// Fav Game
void vecAr() {
	vector<string> sVect;
	while (true) {
		vector<string>::iterator it;
		string input;
		string remover;
		int resp;
		bool del = false;

		cout << "\n\tWelcome to 'My Favourite Games!' list\n" << endl;
		cout << "Please select from the following: \n" << endl;
		cout << "1 - List all game titles" << endl;
		cout << "2 - Add a game title" << endl;
		cout << "3 - Remove a game title" << endl;
		cout << "4 - Exit" << endl;
		cout << "Response: ";
		std::cin >> resp;
		system("CLS");

		switch (resp) {

		case 1: {
			cout << "List of my favourite games:\n" << endl;
			for (it = sVect.begin(); it < sVect.end(); it++) {
				cout << *it << "\n";
			}
			cout << "\n";
			system("pause");
			system("CLS");
		}break;

		case 2: {
			cin.ignore();
			cout << "\n\n\nEnter a game name to add to the list" << endl;
			cout << "\nResponse: ";
			getline(cin, input);
			sVect.push_back(input);
			sort(sVect.begin(), sVect.end());
			system("CLS");
		}break;
		case 3: {
			cin.ignore();
			cout << "Current Games: " << endl;
			for (it = sVect.begin(); it < sVect.end(); it++) {
				cout << *it << "\n";
			}
			cout << "\nName of game to remove: ";
			getline(cin, remover);
			sVect.erase(remove(sVect.begin(), sVect.end(), remover), sVect.end());
			system("CLS");
		}break;

		case 4: {
			system("CLS");
			del = true;
			break;
		}
				system("pause");
		}
		if (del == true) {
			break;
		}
	}
}

// Score Board
void hiScor() {

	bool quitting = false;
	typedef unsigned short int val;
	vector<int> Scores;
	vector<int>::iterator it;
	for (int i = 0; i <= 4; i++) {
		Scores.push_back(1000);
	}
	enum switches { display = 1, add, erase, quit };
	while (true) {
		cout << "\nPlease choose from the following: " << endl;
		cout << "\n1: Display high scores" << endl;
		cout << "2: Add a score" << endl;
		cout << "3: Remove a score" << endl;
		cout << "4: Quit" << endl;
		cout << "\n";
		int choice;
		cout << "Response: ";
		cin >> choice;
		system("CLS");

		switch (choice) {
		case display: {
			for (it = Scores.begin(); it < Scores.end(); it++) {
				cout << "Scores: " << *it << endl;
			}
		}break; // 
		case add: {
			while (true) {
				cout << "\n\tPlease enter a score to add: ";
				val nScore;
				cin >> nScore;
				system("CLS");
				if (nScore <= 65000) {
					Scores.push_back(nScore);
					sort(Scores.begin(), Scores.end(), greater<int>());
					break;
				}
				else {
					cout << "Please choose a lower number." << endl;
				}
			}
		}break;
		case erase: {
			for (it = Scores.begin(); it < Scores.end(); it++)
			{
				cout << *it << "\n";
			}
			cout << "\nPlease enter a score to remove: ";
			val rScore;
			cin >> rScore;
			Scores.erase(remove(Scores.begin(), Scores.end(), rScore), Scores.end());
			sort(Scores.begin(), Scores.end(), greater<int>());
		}break;
		case quit: {
			quitting = true;
			break;
		}
		}
		if (quitting == true) {
			break;
		}
		system("pause");

	}
}

//Inventory Room Sim 
void inVen() {
	vector<string> inventory;
	vector<string> room = {
		{ "sword" },{ "apple" },{ "rusty key" },{ "shield" },{ "skull" }
	};
	vector<string>::iterator iter;
	string playName;
	string action;

	string drop;

	while (true) {
		cout << "\n\t\tWelcome to...\n\t\t\tThe ROOM." << endl;
		cout << "\nPlease enter your name, adventurer." << endl;
		cout << "\nName: ";
		getline(cin, playName);
		system("CLS");
		if (playName != "") {
			break;
		}
	}
	cout << "\nWelcome, " << playName << ", to...\n\t\t\tTHE ROOM" << endl;
	cout << "\nYou awake, dazed and confused. \nThe musty smell of cold, damp stone fills the air" << endl;
	cin.ignore();
	while (true) {
		cout << "You appear to be in some sort of dungeon.\nYou have no recollection of how you arrived here" << endl;
		cout << "What do you do?" << endl;
		cout << "\nType 'help' for help\n" << endl;
		cout << "Action: ";
		cin >> action;
		system("CLS");
		if (action == "help") {
			cout << "\nYou can choose from the following actions: \n" << endl;
			cout << "look - Survey your surroundings" << endl;
			cout << "inventory - Displays your inventory" << endl;
			cout << "get - Pick up an item from your surroundings" << endl;
			cout << "drop - Drop an item from your inventory\n" << endl;
			system("pause");
		}
		else if (action == "look") {
			cout << "You take a look around you." << endl;
			cout << "You see:" << endl;
			int n = 1;
			for (iter = room.begin(); iter < room.end(); iter++) {
				cout << n << ": " << *iter << "\n";
				n++;
			}
			cout << "\n" << endl;
		}
		else if (action == "inventory") {
			if (inventory.empty()) {
				cout << "\nYou aren't carrying anything\n" << endl;
			}
			else {
				int o = 1;
				cout << "Items in your inventory: " << endl;
				for (iter = inventory.begin(); iter < inventory.end(); iter++) {
					cout << o << ": " << *iter << endl;
					o++;
				}
				cout << "\n";
			}
		}
		else if (action == "get") {
			cin.ignore();
			string get;
			cout << "\nWhat would you like to try and pick up?" << endl;
			cout << "Item to grab: ";
			getline(cin, get);
			ptrdiff_t pos = find(room.begin(), room.end(), get) - room.begin();
			if (get == "apple") {
				cout << "You take the apple, but it withers in your hands.." << endl;
				get = "rotten apple";
			}
			if (pos < room.size()) {
				inventory.push_back(get);
				room.erase(room.begin() + pos);
				cout << "You take the " << get << " from the room." << endl;
			}
			else {
				cout << "\nYou take a look around for the " << get << ", but it's nowhere to be found." << endl;
			}
			cin.ignore();
		}
		else if (action == "drop") {
			cin.ignore();
			string drop;
			cout << "\nWhich item from your inventory would you like to drop?" << endl;
			cout << "Item to drop: ";
			getline(cin, drop);
			ptrdiff_t dro = find(inventory.begin(), inventory.end(), drop) - inventory.begin();
			if (dro < inventory.size()) {
				room.push_back(drop);
				inventory.erase(inventory.begin() + dro);
				cout << "You drop the " << drop << " on the floor.\n" << endl;
			}
			else {
				cout << "\nYou try to drop a " << drop << ", but you never had one.\n" << endl;
			}
		}
		else if (action == "quit") {
			break;
		}
	}


}

void hangMan() {

}

// WIP
int main()
{
	int choice;
	cout << "\n\t\t\tChapter 13 Projects" << endl;
	cout << "\n1: [Projects 13.1] Word Jumble" << endl;
	cout << "2: [Projects 13.2] Favourite Games List" << endl;
	cout << "3: [Projects 13.3] High Score Table" << endl;
	cout << "4: [Projects 13.4] Inventory System" << endl;
	cout << "\nSelection: ";
	enum choose { Jumble = 1, favGame, hiScore, inVent };
	cin >> choice;
	system("CLS");
	switch (choice) {
	case Jumble: {
		cin.ignore();
		jumble();
	}break;
	case favGame: {
		cin.ignore();
		vecAr();
	}break;
	case hiScore: {
		cin.ignore();
		hiScor();
	}
	case inVent: {
		cin.ignore();
		inVen();
	}
	}
	return 0;
}

