// main.cpp: Jarvis Prestidge.
// Description: Main class to control the flow of the program.
// presents a menu to the user to handle database i/o.

#include <iostream>
#include "database.h"

using namespace std;

// Declare string and int for data type recognition
string typeStr;
int typeInt;

int Menu() {

  // Print the menu
  cout << endl;
  cout << "Composer Database" << endl;
  cout << "---------------------------------------------" << endl;
  cout << "1) Add a new composer" << endl;
  cout << "2) Retrieve a composer's data" << endl;
  cout << "3) Promote/demote a composer's rank" << endl;
  cout << "4) List all composer's" << endl;
  cout << "5) List all composer's by rank" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "Enter choice: ";

  // Return the user's choice with error checking
  int choice;

  while (true) {
    if (!(cin >> choice) || (choice != 0 && choice != 1 && 
      choice != 2 && choice != 3 && choice != 4 && choice != 5)) {
      cout << "Please only enter one of the above choices!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }
  return choice;
}

template <class T>
T GetInput(T type, string str) {
  T input;
  while (true) {
    cout << str;
    if (!(cin >> input)) {
      cout << "Invalid input." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }
  return input;
}

void AddComposer(Database &db) {

  string first_name = "First name: \t";
  string last_name = "Last name: \t";
  string composer_genre = "Music genre: \t"; 
  string composer_fact = "Fact: \t\t";
  string composer_yob = "Birth year: \t";
  string composer_ranking = "Ranking: \t";

  // Prompt user for input
  cout << "Enter the following composer information" << endl;
  cout << endl;

  // Store the input
  string first  = GetInput(typeStr, first_name);
  string last   = GetInput(typeStr, last_name);

  // Flush previous cin buffer for \n that getline would read
  cin.ignore(1000, '\n');
  cin.clear();
  string genre; cout << composer_genre; getline(cin, genre);

  // Flush previous cin buffer for \n that getline would read
  string fact; cout << composer_fact; getline(cin, fact);

  int yob       = GetInput(typeInt, composer_yob);
  int ranking   = GetInput(typeInt, composer_ranking);

  // Create the new composer with the values
  db.AddComposer(first, last, genre, fact, yob, ranking);
}

Composer* FindComposer(Database &db) {

  // String declarations
  string str = "string";
  string prompt = "Enter composer's last name: ";

  // Ask for the users input
  string name = GetInput(str, prompt);
  cout << endl;

  Composer* comp = db.GetComposer(name);
  return comp;
}

void ChangeRank(Database &db) {

  Composer* comp = FindComposer(db);

  // Get the relevent composer's object
  if (comp == nullptr) {
    // No composer has been found
    cout << "No composer with that name has been found" << endl;
    cout << endl;

    // Exit the function
    return;
  } 

  string first = comp->first_name();
  string last = comp->last_name();

  cout << "Composer " << first << " " << last << " has been found." << endl;
  cout << endl;

  // Prompt user to choose to promote or demote
  cout << "Select one of the following" << endl;
  cout << endl;
  cout << "1) Promote " << endl;
  cout << "2) Demote " << endl;
  cout << endl;
  int choice = GetInput(typeInt, "Enter choice: ");
  cout << endl;

  // Prompt user for value to promte by
  string str;
  str.append(string("Enter a value to ") + 
    ((choice == 1) ? "promote" : "demote") +
    " by: ");
  int value = GetInput(typeInt, str);
  cout << endl;

  // Promote or demote based on choice
  if (choice == 1) {
    comp->Promote(value);
  } else {
    comp->Demote(value);
  }

  // Print composers new rank
  cout << last << "'s new ranking is " << comp->ranking() << endl;
}

void DisplayAll(Database &db) {

  // Print information for all the composers
  cout << "Composer Attributes" << endl;
  cout << endl;

  for (int i = 0; i < db.next_slot_; ++i)
  {
    cout << endl;
    db.composers_[i].Display();
    cout << endl;
  }
}

int main() {

  // Create a database object
  Database db;

  while (true) {

    // Print menu and prompt for user input
    int choice = Menu();
    cout << endl;
    
    // Run code based on user input
    switch (choice) {
      case 0:
        // Exit the program
        cout << "Good-bye!" << endl;
        return 0;
      case 1:
        // Add a new composer
        AddComposer(db);
        break;
      case 2: {
        // Retrieve a composer's data
        Composer* comp = FindComposer(db);
        // Get the relevent composer's object
        if (comp == nullptr) {
          // No composer has been found
          cout << "No composer with that name has been found" << endl;
          break;
        } 
        comp->Display();
        break;
      }
      case 3:
        // Promote/demote a composer's rank
        ChangeRank(db);
        break;
      case 4:
        // List all composer's
        DisplayAll(db);
        break;
      case 5:
        // List all composer's by rank
        db.DisplayByRank();
        break;
      }

  } // End of while (hasExit)

  // Exit program
  return 0;
}