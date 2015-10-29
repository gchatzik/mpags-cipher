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

int main(){


  char input{'x'};
  while(std::cin>>input)
    {
      transformChar(input);
    }


  return 0;
}
