// Macaraeg, William: LAB 9; Due date: December 06, 2021 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputMod (int *userInput1, int *userInput2,int *userInput3);

void calcMod (int *userInput1, int *userInput2,int *userInput3, int & largeNum, int & smallNum, int & mod1, int & mod2, int & mod3);

void outputMod (int *userInput1, int *userInput2,int *userInput3, int largeNum, int smallNum, int mod1, int  mod2, int mod3);

int main() 
{
  int num1, num2, num3, largeNum, smallNum, mod1, mod2, mod3;
  int *p1=&num1, *p2=&num2, *p3=&num3;
  
  
  inputMod (p1, p2, p3);
  calcMod (p1, p2,p3, largeNum, smallNum,  mod1, mod2,  mod3);
  outputMod (p1, p2,p3, largeNum, smallNum,  mod1,  mod2, mod3);
}

void inputMod (int *userInput1, int *userInput2,int *userInput3) {
  int num;
  cout <<"Please enter 3 different numbers between 1-100\n";
  
  cout << "Enter Number 1:";
  cin >> num;
  *userInput1 = num;
  while(*userInput1 <= 0 || *userInput1 >= 101){
    cout << "Invalid number, please enter Number 1 again:";
    cin >> num;
    *userInput1 = num;
  }
  cout << "Enter Number 2:";
  cin >> num;
  *userInput2 = num;
  while( (*userInput2 <= 0 || *userInput2 >= 101) || (*userInput2 == *userInput1)){
    cout << "Invalid number, please enter Number 2 again:";
    cin >> num;
    *userInput2 = num;
  }
  cout << "Enter Number 3:";
  cin >> num;
  *userInput3 = num;
  while((*userInput3 <= 0 || *userInput3 >= 101) ||(*userInput3 == *userInput1)  || (*userInput3 == *userInput2) ){
    cout << "Invalid number, please enter Number 1 again:";
    cin >> num;
    *userInput3 = num;
  }
}



void calcMod (int *userInput1, int *userInput2,int *userInput3, int & largeNum, int & smallNum, int & mod1, int & mod2, int & mod3){
  
  smallNum = *userInput1;
  if (smallNum > *userInput2) {
    smallNum = *userInput2;
    largeNum = *userInput1;
  }
  else {
    largeNum = *userInput1;
  }

  if (smallNum > *userInput3){
    smallNum = *userInput3;
    
  }
  if (largeNum < *userInput3){
    largeNum = *userInput3;
  }


  mod1 =*userInput1 % 2;
  mod2 =*userInput2 % 2;
  mod3 =*userInput3 % 2;
}
void outputMod (int *userInput1, int *userInput2,int *userInput3, int largeNum, int smallNum, int mod1, int  mod2, int mod3) {
  cout << "RESULTS: \n";
  cout << "Number 1: " << *userInput1 << endl;
  cout << "Number 2: " << *userInput2 << endl;
  cout << "Number 3: " << *userInput3 << endl;
  cout << "LARGEST Number: " << largeNum << endl;
  cout << "SMALLEST Number: " << smallNum << endl;

    if (mod1 == 0) {
    cout << "Number 1 is even!" << endl;
  }
  if (mod1 == 1) {
    cout << "Number 1 is odd!" << endl;
  }
  if (mod2 == 0) {
    cout << "Number 2 is even!" << endl;
  }
  if (mod2 == 1) {
    cout << "Number 2  is odd!" << endl;
  }
  if (mod3 == 0) {
    cout << "Number 3 is even!" << endl;
  }
  if (mod3 == 1) {
    cout << "Number 3 is odd!" << endl;
  }

}

