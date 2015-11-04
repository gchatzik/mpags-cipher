#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <stdexcept>
#include <typeinfo>
#include "MPAGSCipher/transformChar.hpp"
#include "MPAGSCipher/processCommandLine.hpp"
#include "MPAGSCipher/CaesarCipher.hpp"


std::vector<char> lowlet={'a','b','c','d','e','f', 'g','h','i','j','k','l'
			  ,'m','n','o','p','q','r', 's','t','u','v','w','x'
			  ,'y','z'} ;


std::vector<std::string> Numbers ={"ZERO","ONE","TWO","THREE","FOUR","FIVE"
			      ,"SIX","SEVEN","EIGHT","NIGHN","TEN"} ;


//choose type and key
char key{1};
std::string type{"Encrypting"}; //Encrypting or Decrypting


int main(int argc, char* argv[]){
  
  //initlize parameters that will be changed from the user
  bool arghelp{false} ;
  std::string argInputFile{""} ;
  std::string argOutputFile{""} ;
  std::string argVersion{""};
  bool argh{false} ;

  //change initialized parameters from parse arguments
  processCommandLine(argc,argv, arghelp, argh, argVersion, argInputFile, argOutputFile, type, key);
  
  //input
  std::string InputFile {argInputFile} ;
  std::ifstream Input_File ;
  //output 
  std::string OutputFile {argOutputFile} ;
  std::ofstream Output_File ;

  //test read/write format of the files
  bool ok_to_write = Output_File.good() ;
  bool ok_to_read  = Input_File.good() ;

  
  //initialize parameters 
  char input{'x'} ;
  std::string msg{""} ;
  std::string line{""};


  //no input or onput file
  if (argInputFile == "" && argOutputFile == "") {
    while(std::cin>>input) {
      std::string tmp{transformChar(input,lowlet)};
      std::cout<< CaesarCipher(tmp[0],type,lowlet,key)<<std::endl ;
    }
  } 

  //only output file
  else if (argInputFile == "" && argOutputFile != "") {
    Output_File.open(OutputFile) ;
    std::string temp{""};
    std::string ctemp{""};
    if (ok_to_write) {
      while(std::cin>>input)  {
        msg = transformChar(input,lowlet);
	ctemp = CaesarCipher(msg[0],type,lowlet,key);
	std::cout<<ctemp<<std::endl;
	temp+=ctemp;
      }
      temp+="\n";
      Output_File<<temp;
      Output_File.close();
    } else {throw std::invalid_argument("INFO - ERROR: Not permission to write") ;}
}

  //only input file
  else if ( argInputFile != "" && argOutputFile == "" ) {
    Input_File.open(InputFile) ;
    if (ok_to_read) {
      while( getline (Input_File,line) ) {
        for (int i{0}; i<line.length(); i++) {
	  std::cout<<CaesarCipher(transformChar(line[i], lowlet)[0],type,lowlet,key)<<std::endl;
        }
      }  Input_File.close() ;
    } else {throw std::invalid_argument("INFO - ERROR: Not permission to read") ;}
  }

  //input and output file
  else {
    Output_File.open(OutputFile) ;
    Input_File.open(InputFile) ;
    if (ok_to_read && ok_to_write) {
      while( getline(Input_File, line) ) {
	std::string temp{""};
	std::string tempc{""};
	std::string tempcc{""};
	for (int i{0}; i<line.length(); i++) {
	  temp =transformChar(line[i],lowlet);
	  tempc=CaesarCipher(temp[0],type,lowlet,key);
	  std::cout<<tempc<<std::endl;
	  tempcc+=tempc;
	} Output_File<<tempcc+"\n";
      }
      Output_File.close() ;
      Input_File.close() ;
    } else {throw std::invalid_argument("INFO - ERROR: Permission error with write/read") ;}
  }
  

  return 0;
}
