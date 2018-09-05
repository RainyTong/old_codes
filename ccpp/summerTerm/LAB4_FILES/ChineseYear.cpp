#include <iostream>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <string>

#include "ChineseYear.hpp"


#define CYCLE_YEARS    12

using namespace std;

// Casts to silence compilation warnings
static char *G_animals[CYCLE_YEARS + 1] =
                    {(char *)"Rat",
                     (char *)"Ox",
                     (char *)"Tiger",
                     (char *)"Rabbit",
                     (char *)"Dragon",
                     (char *)"Snake",
                     (char *)"Horse",
                     (char *)"Goat",
                     (char *)"Monkey",
                     (char *)"Rooster",
                     (char *)"Dog",
                     (char *)"Pig",
                     NULL};

//
// --   Utility functions
//
static int animal_pos(string animal) {
    int         i = 0;
    const char *a = animal.c_str();

    G_animals[CYCLE_YEARS] = (char *)a;
    while (strcasecmp(G_animals[i], (char *)a)) {
      i++;
    }
    if (i == CYCLE_YEARS) {
      return -1;
    }
    return i;
}

static bool valid_animal(string animal) {
    return (animal_pos(animal) == -1 ? false : true);
}

static string animal(int pos) {
    if ((pos >= 0) && (pos < CYCLE_YEARS)) {
      return string(G_animals[pos]);
    }
    return NULL;
}

//
// From now on, it’s you turn to write the code for constructors,
// operators and friend functions …`
//

ChineseYear::ChineseYear(){
  time_t tt = time(NULL);
  tm* t= localtime(&tt);
  _greg = t->tm_year+1900;
  _animal = animal(t->tm_year % 12);
}

ChineseYear::ChineseYear(string animal){

  if(valid_animal(animal)){
    _animal = animal;
    _greg = 2008 + animal_pos(animal) ;

  }else{
    ChineseYear::WrongChineseYear e;
    throw e ;//?
  }

}

ChineseYear::ChineseYear(int year){
  if(year>=1900){
    int pos = (year - 1900)%12 ;
    _animal = animal(pos);
    _greg = year;
  }else{
    ChineseYear::WrongGregorianYear e;
    throw e ;//?
  }

}

ostream &operator<<(ostream &os, const ChineseYear &cy){ //需不需要写类名?
  os << cy._animal << " " << cy._greg << "-" << cy._greg+1 ;
  return os;
}

void ChineseYear::operator+=(int number){
  this->_greg += number;
  this->_animal = animal((this->_greg-1900)%12);
}

ChineseYear& operator+(const ChineseYear &cy, int number){
  ChineseYear* ptr = new ChineseYear;
  ptr->_greg = cy._greg + number;
  ptr->_animal = animal((ptr->_greg - 1900)%12);
  delete ptr;
  return *ptr ;
}

ChineseYear& operator+(int number, const ChineseYear &cy){
  ChineseYear* ptr = new ChineseYear;
  ptr->_greg = cy._greg + number;
  ptr->_animal = animal((ptr->_greg - 1900)%12);
  delete ptr;
  return *ptr ;
}
