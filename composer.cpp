// composer.cpp: Jarvis Prestidge.
// Description: Composer record implementation.

#include <iostream>
#include "composer.h"

// Default values for strings and integers alike, necessary
// to ensure defined behaviour
const string ds = "Unknown";
const int di = 0;

using namespace std;

// Default constructor with initialisation list
Composer::Composer() : first_name_(ds), last_name_ (ds), fact_(ds),
                       composer_genre_(ds), composer_yob_(di),
                       ranking_(di) {}

// Default destructor
Composer::~Composer() {
}

// First name
void Composer::set_first_name(string in_first_name) {
	first_name_ = in_first_name;
}

string Composer::first_name() {
	return first_name_;
}

// Last name
void Composer::set_last_name(string in_last_name) {
	last_name_ = in_last_name;
}

string Composer::last_name() {
	return last_name_;
}

// Year of birth
void Composer::set_composer_yob(int in_composer_yob) {
	composer_yob_ = in_composer_yob;
}

int Composer::composer_yob() {
	return composer_yob_;
}

// Genre of music
void Composer::set_composer_genre(string in_composer_genre) {
	composer_genre_ = in_composer_genre;
}

string Composer::Composer::composer_genre() {
	return composer_genre_;
}

// Ranking
void Composer::set_ranking(int in_ranking) {
	ranking_ = in_ranking;
}

int Composer::ranking() {
	return ranking_;
}

// Fact
void Composer::set_fact(string in_fact) {
	fact_ = in_fact;
}

string Composer::fact() {
	return fact_;
}

void Composer::Promote(int increment) {
	ranking_ += increment;
}

// This method decreases a composer's rank by decrement.
void Composer::Demote(int decrement) {
	ranking_ -= decrement;
}

// This method displays all the attributes of a composer.
void Composer::Display() {
  cout << "Composer Attributes" << endl;
  cout << endl;

  cout << "First name: \t" << first_name_ << endl;
  cout << "Last name: \t" << last_name_ << endl;
  cout << "Year of birth: \t" << composer_yob_ << endl;
  cout << "Genre: \t\t" << composer_genre_ << endl;
  cout << "Fact: \t\t" << fact_ << endl;
  cout << "Ranking: \t" << ranking_ << endl;

}