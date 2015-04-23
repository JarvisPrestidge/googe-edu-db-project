// database.h: Jarvis Prestidge.
// Description: Class for a database of Composer records.

#ifndef H_DATABASE
#define H_DATABASE

#include "Composer.h"

// Our database holds 100 composers, and no more.
const int kMaxComposers = 100;

class Database {
  
 public:
  // Constructor
  Database();

  // Destructor
  ~Database();

  // Add a new composer using operations in the Composer class
  void AddComposer(string in_first_name, string in_last_name,
                    string in_genre, string in_fact, 
                    int in_yob, int in_ranking);

  // Search for a composer based on last name and return it
  Composer* GetComposer(string in_last_name);

  // Display all composers in the database.
  void DisplayAll();

  // Sort database records by rank and then display all.
  void DisplayByRank();

  int next_slot_;

  Composer composers_[kMaxComposers];

};

#endif