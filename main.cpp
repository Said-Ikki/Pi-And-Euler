#include <iostream>
#include <stdlib.h>

float factorial(int factor) {
  if(factor == 1 || factor == 0) {
    return 1;
  }
  else if(factor > 1) {
    return ( factor * factorial(factor - 1) );
  }
}

int main() {

  // pi according to the Leibniz formula can be represented as a series
  // pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 ...
  int decimal = 0;
  std::cout << "How accurate do you want pi?" << std::endl;
  std::cin >> decimal;
  // just any number greater than 1
  // the bigger the number, the closer the number to pi

  float summationation = 1;
  int divider = 1;
  float total = 0;
  for(int i = 0; i < decimal; i++) {
    std::cout << total << " + " << summationation << 
      "/" << divider << std::endl;
    total = total + (summationation / divider);
    
    summationation *= -1;
    
    divider += 2;
    if( abs(summationation / divider)  <  (0.01) ) {
      std::cout << "EXCEEDED REASONABLE RANGE" << std::endl;
      break;
    }
  }
  std::cout << "pi/4 ~= "<< total << std::endl;
  total = total * 4;
  std::cout << "pi ~= "<< total << std::endl;

  
  std::cout << std::endl;
  
  decimal = 0;
  std::cout << "How accurate do you want euler's number?" << std::endl;
  std::cin >> decimal;


  total = 1;
  for(int i = 1; i < decimal; i++) {
    float fac = factorial(i);
    std::cout << total << " + 1" << 
      "/" << fac << std::endl;
    total = total + ( 1 / fac );
    
    if( (1 / fac)  <  (0.00001) ) {
      std::cout << "EXCEEDED REASONABLE RANGE" << std::endl;
      break;
    }
  }
  std::cout << "e ~= "<< total << std::endl;
  
}

