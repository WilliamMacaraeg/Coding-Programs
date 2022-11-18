// Macaraeg, William: LAB 7; Due date: November 22, 2021
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int LIMIT = 100;


void inputMod (int FirstArray [], ifstream & infile, int & filled);

void calcMod (int FirstArray [], int SecondArray [], int ThirdArray[], int filled, double & avg, int & total, int & size1, int & size2, int & size3); //calc avg = nums / 7

void outputMod (int FirstArray [], int SecondArray [], int ThirdArray [], double avg, int filled, int size2, int size3, ofstream & outfile);

int main() 
{
  ifstream infile;
  ofstream outfile;
  int SecondArray[LIMIT];
  int ThirdArray[LIMIT];
  int FirstArray [LIMIT];
  int filled,total, size1, size2, size3;
  total = 0;
  double avg;
  bool Error;
  infile.open ("NumbersIn.txt");
  if (!infile) {
    cout << "Error! File not found!" << endl;
    exit(1);
  }
  outfile.open("NumbersOut.txt");
  outfile << fixed <<setprecision(2); 
  inputMod(FirstArray, infile, filled);
  calcMod(FirstArray,SecondArray, ThirdArray,filled,avg, total,size1,size2,size3);
  outputMod(FirstArray,SecondArray,ThirdArray,avg,filled,size2,size3,outfile);
  //cout<<avg<<endl;
  
  
}


void inputMod (int FirstArray [], ifstream & infile, int & filled){
bool numErr;
int i = 0;
filled = 0;
  while (i < LIMIT && ! infile.eof() ) {
    infile >> FirstArray [i]; 
    i++;
    filled++;
  }
}

void calcMod (int FirstArray [], int SecondArray [], int ThirdArray[], int filled, double & avg, int & total, int & size1, int & size2, int & size3){
//int i, j, k;
total = 0;
  for(int i=0; i < filled; i++) {
    total = total + FirstArray[i];
  }
avg = 1.0 * total/filled;
int j = 0;
int k = 0;
  for(int i=0; i < filled; i++) {
    if (FirstArray[i] >= avg){
      SecondArray[j] = FirstArray[i];
      j++;
      size2 = j;
    }
    if (FirstArray[i] < avg) {
      ThirdArray[k] = FirstArray[i];
      k++;
      size3 = k;
    }

  }

}

void outputMod (int FirstArray [], int SecondArray [], int ThirdArray [], double avg, int filled, int size2, int size3, ofstream & outfile) {
//int i, j, k;
outfile << "Average: " << avg <<endl;
outfile << "First Array: " ;
for(int i = 0; i < filled; i++){
    outfile<< FirstArray[i] <<" ";
}
outfile<<endl;
outfile << "Second Array: " ;
for(int i = 0; i < size2; i++){
    outfile<< SecondArray[i] <<" ";
}
outfile<<endl;
outfile << "Third Array: " ;
for(int i = 0; i < size3; i++){
    outfile<< ThirdArray[i] <<" ";
}

}

