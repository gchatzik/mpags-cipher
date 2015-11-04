#include <iostream>
#include <string>



//*****************************************************************************************************************************************************
//  Function that handles the argumets passed by the user
//*****************************************************************************************************************************************************



//________________________________________________________________________________________________________________________________________________________
void processCommandLine(int argc,char* argv[], bool& arghelp, bool& argh, std::string& argVersion,
			std::string& argInputFile, std::string& argOutputFile,std::string& type,char& key)
{
  for (int i{0}; i<argc; i++) {
    if (std::string(argv[i]) == "--help") {
      arghelp = true ;
    } else if (std::string(argv[i]) == "-h") {
      argh = true  ;
      //input file
    }  else if (std::string(argv[i])== "-i") {
      argInputFile = argv[i+1] ;
      //output file
    }  else if (std::string(argv[i])== "-o") {
      argOutputFile = argv[i+1] ;
    } else if ( std::string(argv[i])== "-version") {
      argVersion = argv[i+1];
      //flag for the type of encryption: Encrypting or Decrypting
    } else if ( std::string(argv[i])== "flag") {
      type = argv[i+1];
      //give the key that is used by the cipher, if not the default will be used
    } else if ( std::string(argv[i])== "key") {
      key = argv[i+1][0];
    } else {
      std::cout<<std::string(argv[i])<<" is a not known argument"<<std::endl ;
    }
  }
}
