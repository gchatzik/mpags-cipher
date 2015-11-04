#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <stdexcept>

std::string numbers{"0123456789"};

//**********************************************************************************************************
//  This is a function that takes as arguments a container of lower case letter of alphabet, a container
//  of number in string form e.i ZERO and the input which is a char. It returns if it is a letter the
//  letter in a upper case format and the number to string format e.i char(1)-->string(ONE).
//**********************************************************************************************************


//___________________________________________________________________________________________________________
std::string transformChar(char input,const std::vector<char>& alphabet, const std::vector<std::string>& num)
{
  if (isalpha(input)) {
    std::string tmp{""};
    if (islower(input)) {
      tmp+=toupper(input) ;
    } else {tmp+= input ; }
    return tmp;
    
  } else {
    for (int i{0}; i<10; i++) {
      if (input == numbers[i]) {
	int intg{input-'0'} ;
	return num[intg] ;
      } else {continue ;}
    }
  }
}


//____________________________________________________________________________________________________________
std::string transformChar(char input,const std::vector<char>& alphabet)
{
  std::string tmp{""};
  if (isalpha(input)){
    if (islower(input)) {
      tmp+=toupper(input) ;
    } else {tmp+= input ;} 
    return tmp;
  } else{throw std::invalid_argument("INFO - ERROR: I dont like special characters :)") ;}
}
