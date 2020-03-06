#include <iostream>
#include <iomanip>

using namespace std;

int getPentagonalNumber(int n)
{
/* This function takes an integer n as a
parameter and returns a corresponding
pentagonal number */

  int p = n * (3 * n - 1)/2;
  return p;
}//end getPentagonalNumber()

void Question1()
{
  for(int x = 1; x <= 50; x++)
  {
    int p = getPentagonalNumber(x);
    if (x % 6 ==0)
      cout << setw(8)<<p<<endl;
    else
      cout << setw(8)<<p ;
  }//end for
  cout << endl;
}//end Question1()

int sumDigits(int n) {
  int d = 0;
  if (n >= 10) {
    d = sumDigits(n/10);
  }
  int digit = n % 10;
  return digit + d;
}

void Question2() {
  cout << sumDigits(123) << endl;
}

void Question3(){};
void Question4(){};
void Question5(){};
void Question6(){};
void Question7(){};
void Question8(){};
void Question9(){};
void Question10(){};
void Question11(){};
void Question12(){};