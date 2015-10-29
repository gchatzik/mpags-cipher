#include <iostream>
#include <string>


int main()
{
  // initialize int                                             
  int var{3};
  std::cout<<"Inital value of int variable is : "<< var << std::endl;
 
  // modify int                                             
  var = 4;
  std::cout<<"New value of int variable is : "<< var << std::endl;
 
  // const double                                              
  const double c{5};
  std::cout<<"The value of the constand double type of parameter is : "<< c <<std::endl;
 
  // const double * int                                             
  std::cout<<"The product of the previous parameters is : "<<c*var<<std::endl;
  
  // auto                                             
  auto f{true};

  // double/int
  double r1{2.1};
  int r2{2};
  std::cout<<"Devide double with int : "<< r1/r2 << std::endl;

  // int/int
  int r3{2};
  int r4{4};
  std::cout<<"Devide int with int : "<< r3/r4 << std::endl;

  // string
  std::string msg{"Hello!"};
  std::cout<<"Initialize string : " << msg << std::endl;

  // asign to auto the first character of the string defined before                                             
  auto sg{msg[0]};

  return 0;
}

