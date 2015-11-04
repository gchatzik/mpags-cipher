#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

//**********************************************************************************************
// The function takes as an argument the alphabet that is used, the input character that will
// be encrypted/decrypted and the option encrypted or decrypted.
//**********************************************************************************************


//________________________________________________________________________________________________
char CaesarCipher(char inp, std::string type, const std::vector<char>& lowlet, char key)
{
  int Key{key};
  std::vector<char> tmp{};
  for (char ele : lowlet){tmp.push_back(toupper(ele)) ;}

  if (type != "Encrypting" && type != "Decrypting") {
    throw std::invalid_argument("INFO - ERROR: Invalid argument in Encrypt_Decrypt_Function") ;}

  int step{0} ;

  for (int i{0} ; i<tmp.size() ; i++) {
    if (tmp[i] == inp) { break ;}
    else { step++ ; }
  }

  if (type == "Encrypting") {
    if (tmp.size() - (step+1) >= Key) {
      return tmp[step +Key] ;
    } else {
      return tmp[key - tmp.size() + (step+1) - 1] ;
    }
  } else {
    if (step >= Key ) {
      return tmp[step-Key] ;                                                                                                                                                                                           
    } else {
      std::reverse(tmp.begin(),tmp.end());
      return tmp[key-step-1];
    }
  }
}



