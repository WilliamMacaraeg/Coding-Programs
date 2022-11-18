#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() 
{
  //WHILE LOOP
  cout << setprecision(2) << fixed;
  double earnedCents = 0.01, totalCents = 0;
  int day = 1;
  cout << "While Loop: \n";
  while (day <= 30) {
    cout << "Day " << day << "Pay: $\t" << earnedCents << endl;
    totalCents += earnedCents;
    earnedCents *= 2;
    day++;
  }
  cout << "\nTotal pay for 30 days: $\t" << totalCents << endl;
  cout << "Using WHILE loop.\n";

  //FOR LOOP
  cout << "\n\nFor Loop: " << endl;
  double earnedCents2 = 0.01, totalCents2 = 0;
  int day2;
  for (day2 = 1; day2 <= 30; day2++) {
    cout << "Day " << day2 << "Pay: $\t" << earnedCents2 << endl;
    totalCents2 += earnedCents2;
    earnedCents2 *= 2;
    day2++;
  }
  cout << "\nTotal pay for 30 days: $\t" << totalCents << endl;
  cout << "Using FOR loop.\n"; 

  //DO-WHILE LOOP
  cout << "\n\nDo-While Loop:" << endl;
  double earnedCents3 = 0.01, totalCents3 = 0;
  int day3 = 1;
  do {
  cout << "Day " << day3 << "Pay: $\t" << earnedCents3 << endl;
    totalCents3 += earnedCents3;
    earnedCents3 *= 2;  
    day3++;
  } while (day3 <= 30);
  cout << "\nTotal pay for 30 days: $\t" << totalCents3 << endl;
  cout << "Using DO-WHILE loop.\n";
  return 0;
}