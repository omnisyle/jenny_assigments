#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <math.h>

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

int reverse(int number) {
  int rev = 0;
  while (number > 0) {
    rev = rev*10 + number %10;
    number = number/10;
  }

  return rev;
}

void Question3() {
  int num;
  cout << "Enter a number for reverse: ";
  cin >> num;
  cout << "Reversed number is " << reverse(num) << endl;
};

bool isPalindrome(int number) {
  int reversedNumber = reverse(number);
  return reversedNumber == number;
}

void Question4(){
  int num;
  cout << "Enter a number for palindrome check: ";
  cin >> num;
  cout << "Is palindrome? " << isPalindrome(num) << endl;
};

void displaySortedNumbers(int num1, int num2, int num3) {
  int arr[3] = {num1, num2, num3};
  // Insert arr[1]
  if (arr[1] < arr[0]) {
      swap(arr[0], arr[1]);
  }
  // Insert arr[2]
  if (arr[2] < arr[1]) {
    swap(arr[1], arr[2]);
    if (arr[1] < arr[0]) {
      swap(arr[1], arr[0]);
    }
  }

  cout << "The sorted numbers are: "
    << arr[0] << ", "
    << arr[1] << ", "
    << arr[2] << ", "
    << endl;
}

void Question5(){
  char numberInput[100];
  cout << "Enter three numbers: ";
  cin >> numberInput;
  int numbers[3];

  char * token = strtok(numberInput, ",");
   // loop through the string to extract all other tokens
  int count = 0;
  while(token != NULL) {
    int num = stoi(token);
    if (count < 3) {
      numbers[count] = num;
      count++;
    }
    token = strtok(NULL, ",");
  }
  displaySortedNumbers(numbers[0], numbers[1], numbers[2]);
}

void displayPattern(int n) {

  if (n > 1) {
    displayPattern(n - 1);
  }

  for (int i = 0; i < n; i++) {
    cout << n - i;
  }
  cout << endl;
}

void Question6(){
  cout << "Enter a number: ";
  int num;
  cin >> num;
  displayPattern(num);
}

void futureInvestmentValue(double investmentAmount, double annualInterestRate, int years) {
  double monthlyInterestRate = (annualInterestRate / 12.0) / 100.00;
  cout << "Years" << setw(20) << "Future Value" << endl;
  int totalMonths = 12 * years;
  for (int i = 1; i <= totalMonths; i++) {
    double monthlyInterest = investmentAmount * monthlyInterestRate;
    investmentAmount += monthlyInterest;
    if (i % 12 == 0) {
      cout << (i / 12) << setw(20) << investmentAmount << right  << endl;
    }
  }
}

void Question7(){
  double investmenAmt;
  double annualInterestRate;
  cout << "The amount invested: ";
  cin >> investmenAmt;
  cout << endl;
  cout << "Annual interest rate: ";
  cin >> annualInterestRate;
  cout << endl;
  futureInvestmentValue(investmenAmt, annualInterestRate, 30);
}

void Question8(){}
void Question9(){}
void Question10(){}
void Question11(){}
void Question12(){}