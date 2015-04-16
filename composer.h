// composer.h: Jarvis Prestidge.
// Description: The class for a Composer record.

#include <string>

// The default ranking is 10 which is the lowest possible
const int kDefaultRanking = 10;

class Composer {
 public:
  // Constructor
  Composer();
  // Here is the destructor which has the same name as the class
  // and is preceded by ~. It is called when an object is destroyed
  // either by deletion, or when the object is on the stack and
  // the method ends.
  ~Composer();
 
  // Accessors and Mutators
  void set_first_name(std::string in_first_name);
  std::string first_name();
  void set_last_name(std::string in_last_name);
  std::string last_name();
  void set_composer_yob(int in_composer_yob);
  int composer_yob();
  void set_composer_genre(std::string in_composer_genre);
  std::string composer_genre();
  void set_ranking(int in_ranking);
  int ranking();
  void set_fact(std::string in_fact);
  std::string fact();

  // Methods
  // This method increases a composer's rank by increment.
  void Promote(int increment);
  // This method decreases a composer's rank by decrement.
  void Demote(int decrement);
  // This method displays all the attributes of a composer.
  void Display();

 private:
  std::string first_name_;
  std::string last_name_;
  int composer_yob_; // year of birth
  std::string composer_genre_; // baroque, classical, romantic, etc.
  std::string fact_;
  int ranking_;
};