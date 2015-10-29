#include <iostream>
#include <string>
#include <typeinfo>


void transformChar(char input)
{

  //Definee two string with Up and Low letters used to check the input of the user   
  //Have the same order in char between the low and upper string                                                                                                                                                          

  std::string lowlet{"abcdefghijklmnopqrstuvwxyz"};
  std::string Upplet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string Number{"0123456789"};
  std::string map[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NIGN"};

  //for upper
  for (int i{0}; i < 26; i++ )
    {
      if (input != Upplet[i]) continue;
      else
	{
	  std::cout<<input<<std::endl;
	  return;
	}
    }

  //for low
  for (int i{0}; i < 26; i++)
    {
      if (input != lowlet[i]) continue;
      else {
	std::cout<<Upplet[i]<<std::endl;
	return;
      }
    }

  //for number                                                                                                                                                                                                            
  for (int i{0}; i < 10; i++ )
    {
      if (input != Number[i]) continue;
      else {
	std::cout<< map[i]<<std::endl;
	return;
      }
    }

}

int main(int argc, char* argv[]){

  //iter over the pass array
  for (int i{0}; i<argc; i++)
    {
      if (std::string(argv[i]) == "--help")
	{
	  // argument is a --helf argument                              
	  std::cout<<std::string(argv[i])<<" : bablablab"<<std::endl;
	}
      else if (std::string(argv[i]) == "-h")
	{
	  //if argument is -h                             
	  std::cout<<std::string(argv[i])<<" : balavkavk"<<std::endl;
	}
      else if (std::string(argv[i])== "-i")
	{ //if argument is -i
	  std::cout<<std::string(argv[i])<<" : inputFile"<<std::endl;

	}
      else if (std::string(argv[i])== "-o")
	{ //if argument is -o
	  std::cout<<std::string(argv[i])<<" : OutputFile"<<std::endl;
	}
      else
	{//Other argument                                                                                                                                                                                                 
	  std::cout<<std::string(argv[i])<<" is a not known argument"<<std::endl;
	}

    }



  char input{'x'};
  while(std::cin>>input)
    {
      transformChar(input);
    }


  return 0;
}
