#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>


std::string transformChar(char input)
{

 //Definee two string with Up and Low letters used to check the input of the user
 //Have the same order in char between the low and upper string
 std::string lowlet{"abcdefghijklmnopqrstuvwxyz"};
 std::string Upplet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
 std::string Number{"0123456789"};
 std::string map[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NIGN"};

 std::stringstream ss;
 std::string s{""};
 //for upper
 for (int i{0}; i < 26; i++ )
   {
     if (input != Upplet[i]) continue;
     else 
       {
	 s = s+input;
	 std::cout<<s<<std::endl;
	 return s;
       } 
   }

 //for low
 for (int i{0}; i < 26; i++)
   {
     if (input != lowlet[i]) continue;
     else {
       s=s+Upplet[i];
       std::cout<<s<<std::endl;
       return s;
     } 
   }

 //for number
 for (int i{0}; i < 10; i++ )
   {
     if (input != Number[i]) continue;	 
     else {
       s=s+map[i];
       std::cout<<s<<std::endl;
       return s; } // it is already a string 
   }

 std::cout<<"Not Known symbol"<<std::endl;
 return s;


}

int main(int argc, char* argv[]){


//iter over the pass array                                                                                                                                                                                               
for (int i{0}; i<argc; i++)
 {
   if (std::string(argv[i]) == "--help")
     {
       // argument is a --helf argument                                                                                                                                                                                 
       std::cout<<"--help argument passed : "<<std::string(argv[i])<<std::endl
		<<" means : bablablablab"  <<std::endl;
     }
   else if (std::string(argv[i]) == "-h")
     {
       //if argument is -h                                                                                                                                                                                  
       std::cout<<"-h argument passed : "<<std::string(argv[i])<<std::endl
		<<" means : balavkavkak"  <<std::endl;
     }
   else if (std::string(argv[i])== "-i")
     { //if argument is -i
       std::cout<<"-i argument passed :  "<<std::string(argv[i])<<std::endl
		<<" means : The input file is : "<<std::string(argv[i])<<std::endl;
       
     }
   else if (std::string(argv[i])== "-o")
     { //if argument is -o
       std::cout<<"-o argument passed :  "<<std::string(argv[i])<<std::endl
       <<" means : The Output file is : "<<std::string(argv[i])<<std::endl;
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

   
