#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int LIMIT = 100;
struct houseType {
  string ID;
  double yearIncome;
  int HHnum;
};


void GetData (houseType House[LIMIT], int & filled, ifstream & infile); //open the infile 

char MENU (); //user validate what user wants to find in menu?

void ShowData (houseType house[LIMIT], int filled, ofstream & outfile);

void Average (houseType house[LIMIT], int filled, ofstream & outfile); //average,  find which houses is greater than avg with if else

void Poverty (houseType house[LIMIT], int filled, ofstream & outfile); // locally declare variables?

void Sorted (houseType house[LIMIT], int Elems, ofstream & outfile); //bubble sort, SORT WITH YEARINCOME

void Median (houseType house[LIMIT], int Elems, ofstream & outfile); //how would i grab the results from "void sorted" and then use it to find median? if mod = 0, find total numbers/2 = median number, then link median num to median value. if mod = 1, num8+num9/2 = median SEARCHING AN ARRAY


int main() 
{
  ifstream infile;
  ofstream outfile;
  struct houseType House[LIMIT];
  int filled, Elems;
  char menuInput;
  infile.open ("DataIn.txt");
  if (!infile) {
    cout << "Error! File Not Found!" << endl;
    exit (1);
  }

  outfile.open("DataOut.txt");
  if (!outfile) {
    cout << "Error! File Not Found!" << endl;
    exit (1);
  }
  outfile << fixed << setprecision(2);
  GetData(House, filled, infile);

  do{
    menuInput = MENU();
    
    //switch statements in main
    switch (menuInput){
      case 'A':
        ShowData(House, filled, outfile); //do i put reference parameters?
        cout << "User chose Option A. Please refer to 'DataOut.txt to see results." << endl;
        cout << "Back to the Menu:" << endl; //take them back to the main menu, how?
        outfile << setfill('-') << setw(40) << "\n";
      break;

      case 'B':
        Average(House,filled,outfile);
        cout << "User chose Option B. Please refer to 'DataOut.txt to see results.\n";
        cout << "Back to the Menu:\n";
        outfile << setfill('-') << setw(60) << "\n";
      break;
      case 'C':
        Poverty (House, filled, outfile);
        cout << "User chose Option C. Please refer to 'DataOut.txt to see results.\n";
        cout << "Back to the Menu...\n";
        outfile << setfill('-') << setw(60) << "\n";
      break;
      case 'D':
        Sorted (House, filled, outfile); //filled = elems
        cout << "User chose Option D. Please refer to 'DataOut.txt to see results.\n";
        cout << "Back to the Menu:\n";
        outfile << setfill('-') << setw(60) << "\n";
      break;

      case 'E':
       Median ( House,  filled, outfile);
        cout << "User chose Option E. Please refer to 'DataOut.txt to see results.\n";
        cout << "Back to the Menu:\n";
        outfile << setfill('-') << setw(60) << "\n";
      break;

      case 'X':
        cout << "User chose Option X. Goodbye!\n" <<endl;
        cout << "Program Terminated.";
      break;

      default:
        cout << "Invalid user input, please try again" << endl;
      break;
    }
  }while (menuInput != 'X');

  infile.close();
  outfile.close();
  return 0;
}

void GetData (houseType House[LIMIT], int & filled, ifstream & infile){
  int i = 0;
  filled = 0;
  while (i < LIMIT && ! infile.eof()) {
    infile >>  House[i].ID >> House[i].yearIncome >> House[i].HHnum; 
    i++;
  }
  filled = i;
} //open the infile 

//PRECONDITION:
//POSTCONDITION:
//DESCRIPTION:
char MENU () {
  char menuInput;
  cout << "Woodland Hills Household Survey" << endl;
  cout << "MENU:" <<endl;
  cout << "A. Show Data\n";
  cout << "B. Average\n";
  cout << "C. Poverty\n";
  cout << "D. Sorted \n";
  cout << "E. Median\n";
  cout << "X. Exit Program\n\n";
  cout << "Please select from the following program: ";
  cin >> menuInput;
  menuInput = toupper(menuInput); 
  return menuInput;

}
 //user validate what user wants to find in menu?, switch cases for each option

void ShowData (houseType house[LIMIT], int filled, ofstream &outfile) {
outfile << "SHOW DATA PAGE: \n";
outfile  << "ID" << setfill(' ') << setw(18) <<  "YEAR INCOME" << setw(18) << "Residents " << endl ;
for(int i = 0; i < filled; i++){
    outfile<< setw(3) << house[i].ID;
    outfile<< setw(14) <<house[i].yearIncome;
     outfile << setw(14)<< house[i].HHnum << endl;
}

}

void Average (houseType house[LIMIT], int filled, ofstream & outfile) { 
  double total=0, avg;

  outfile << "AVERAGE PAGE:\n";
  outfile << "ID" << setfill(' ') << setw(23) << "Yearly Income" << endl;
  for (int i = 0; i < filled; i++){
    total += house[i].yearIncome;
  }
  avg = total/filled;
  
  for (int i = 0; i < filled; i++){
    if(house[i].yearIncome > avg){
      outfile << house[i].ID << setw(18) <<house[i].yearIncome << endl;

    }
  }
  outfile << "Average Income = " << avg << endl; 
}



void Poverty (houseType house[LIMIT], int filled, ofstream& outfile){
  double P;
  int i;
  int pCount = 0;
  outfile << "POVERTY PAGE: \n";
  outfile <<"ID" << setfill (' ') << setw(18) << "Yearly Income" << setw(12) << "Residents" << setw(17) << "Poverty Level" <<endl;
  for (int i = 0; i < filled; i++){ //find percent
      P = 8000.00 + 500.00 * (house[i].HHnum -2);
      if (house[i].yearIncome < P){
        outfile << house[i].ID << setw(14) << house[i].yearIncome << setw(10) << house[i].HHnum << setw(18) << P << endl;
        pCount++;
      }
  }
  outfile <<"Percentage of households below the poverty line: "<< 100.0*pCount/filled<<"%"<<endl << endl;

} // locally declare variables?

void Sorted (houseType house[LIMIT], int Elems, ofstream & outfile) { //wont show data out
  int Swap, Temp, Count;
  int i = Elems;
  outfile << "SORTED PAGE:\n";
  outfile << "ID" << setfill(' ') << setw(30) << "YearIncome(Low to High)" << setw(15) << "Residents\n" << endl;

  do {
    Swap = 0;
    for (Count =0; Count < (Elems - 1); Count++){ //sorting out an array
      if(house[Count].yearIncome > house[Count + 1].yearIncome){
        Temp = house[Count].yearIncome;
        house[Count].yearIncome = house[Count + 1].yearIncome;
        house[Count + 1].yearIncome = Temp;
        Swap = 1;
      }
    }
    Elems--;
    }
  while (Swap !=0);
  
  for (int Count =0; Count < i; Count++){
   outfile << house[Count].ID << setw(18) << house[Count].yearIncome << setw(18) << house[Count].HHnum << endl;
  }

}
 //bubble sort, SORT WITH YEARINCOME

void Median (houseType house[LIMIT], int Elems, ofstream & outfile){
  int Swap, Temp, Count;
  int amount = Elems-1;
  do {
    Swap = 0;
    for (Count =0; Count < (Elems - 1); Count++){
      if(house[Count].yearIncome > house[Count + 1].yearIncome){
        Temp = house[Count].yearIncome;
        house[Count].yearIncome = house[Count + 1].yearIncome;
        house[Count + 1].yearIncome = Temp;
        Swap = 1;
      }
    }
    Elems--;
    }
  while (Swap !=0);
  outfile << "Median:" << ((house[amount/2].yearIncome + house[(amount/2 + 1)].yearIncome)/2) << endl;
}

