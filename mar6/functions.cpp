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
  int num;
  cout << "Enter a number to find the digit sum for: ";
  cin >> num;
  cout << "The sum of the digits in " << num << " is " << sumDigits(num) << endl;
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
      cout << (i / 12) << right << setw(20) << investmentAmount << endl;
    }
  }
}

void Question7(){
  double investmenAmt;
  double annualInterestRate;
  cout << "The amount invested: ";
  cin >> investmenAmt;
  cout << "Annual interest rate: ";
  cin >> annualInterestRate;
  futureInvestmentValue(investmenAmt, annualInterestRate, 30);
}

void printMatrix(int n) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int oneOrZero = rand()%2;
      cout << oneOrZero << setw(8);
    }
    cout << setw(0);
    cout << endl;
  }
}
void Question8(){
  int num;
  cout << "Enter a number for matrix: ";
  cin >> num;
  printMatrix(num);
}

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Question9(){
  int x1;
  int x2;
  int y1;
  int y2;

  cout << "Enter x1: ";
  cin >> x1;
  cout << "Enter y1: ";
  cin >> y1;
  cout << "Enter x2: ";
  cin >> x2;
  cout << "Enter y2: ";
  cin >> y2;
  cout << "The distance is " << distance(x1, y1, x2, y2) << endl;
}

void convertMillis(int millis)
{
  int seconds = millis / 1000 % 60;
  int minutes = ((millis / (1000*60)) % 60);
  int hours = (millis / 1000)/60/60;

  cout << hours << ":" << minutes << ":" << seconds << endl;
}

void Question10()
{
  int millis;
  cout << "Enter millisecond: ";
  cin >> millis;
  convertMillis(millis);
}

void addCoins(int pennies, int nickels, int dimes, int quarters)
{
  int nickelsInPennies =  nickels * 5;
  int dimesInPennies = dimes * 10;
  int quartersInPennies = quarters * 25;

  int totalPennies = pennies + nickelsInPennies + dimesInPennies + quartersInPennies;
  double total = totalPennies / 100.00;
  cout << "Total: $" << total << endl;
}

void Question11()
{
  int quarters;
  int pennies;
  int nickels;
  int dimes;

  cout << "Enter your total coins: " << endl;
  cout << endl;
  cout << "Quarters: ";
  cin >> quarters;
  cout << "Dimes: ";
  cin >> dimes;
  cout << "Nickels: ";
  cin >> nickels;
  cout << "Pennies: ";
  cin >> pennies;

  cout << endl;
  addCoins(pennies, nickels, dimes, quarters);
}

void printMessage() {
  cout << "Please choose an option (1-12 or -1 to Quit)" << endl;
  cout << "1. Pentagonal numbers" << endl;
  cout << "2. Digit sum" << endl;
  cout << "3. Reverse a number" << endl;
  cout << "4. Palindrom application" << endl;
  cout << "5. Display sorted number " << endl;
  cout << "6. Display pattern" << endl;
  cout << "7. Future Investment" << endl;
  cout << "8. Print matrix" << endl;
  cout << "9. Calculate distance" << endl;
  cout << "10. Convert millis" << endl;
  cout << "11. Add Coins" << endl;
  cout << "12. Enter -1 to Quit" << endl;
}

void Question12()
{
  cout << "**********************************************" << endl;
  cout << "Welcome to user-defined functions assignments" << endl;
  cout << "**********************************************" << endl;
  printMessage();
  int option = 0;
  while (option > -1) {
    cout << "Enter the function number to test: ";
    cin >> option;
    switch (option)
    {
    case 1:
      Question1();
      break;
    case 2:
      Question2();
      break;
    case 3:
      Question3();
      break;
    case 4:
      Question4();
      break;
    case 5:
      Question5();
      break;
    case 6:
      Question6();
      break;
    case 7:
      Question7();
      break;
    case 8:
      Question8();
      break;
    case 9:
      Question9();
      break;
    case 10:
      Question10();
      break;
    case 11:
      Question11();
      break;
    case 12:
      Question12();
      break;
    case -1:
      break;
    default:
      break;
    }
  }
  cout << "Thank you for using the functions module." << endl;
}