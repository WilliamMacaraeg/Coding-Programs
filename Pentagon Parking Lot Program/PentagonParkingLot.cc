//  Lab 4 by William Macaraeg
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int STARTING_TIME = 6;
const int ENDING_TIME = 22;

int main() 
{
  //declarations
  char userVehicle, userRepeat;
  int startTime, endTime, totalTime, carCount = 0, truckCount = 0, seniorCount = 0;
  float vehicleCost, truckIncome = 0, carIncome = 0, totalIncome = 0;
  string vehicleType;
  

  //loop do while
  do {

    //user input
    cout << "Please enter your Vehicle Type (C=Cars,T=Trucks,S=Senior Citizen): ";
    
    cin >> userVehicle;
    userVehicle = toupper(userVehicle);
    while( (userVehicle != 'C' && userVehicle != 'T' && userVehicle != 'S') ){
      cout << "Error, please enter valid Vehicle Type:";
      cin >> userVehicle;
      userVehicle = toupper(userVehicle);
    }

    bool timeErr;
    do{
      cout << "Please enter starting time (Military Hour Only! ie. 600 = 6): \n";
      cin >> startTime;
    
      cout << "Please enter ending time (Military Hour Only! 2200 = 22): \n";
      cin >> endTime;

      if(!(startTime >= STARTING_TIME && startTime <= ENDING_TIME && endTime <= ENDING_TIME && endTime >= STARTING_TIME && endTime > startTime)){
        cout << "Error! Please re-enter starting time (Military Only!): \n\n";
        timeErr=true;
      }
      else
        timeErr=false;
    }while(timeErr==true);
     
    
    

    //calculations
    totalTime = endTime - startTime;
    if ( userVehicle == 'C' ){
      if (totalTime <= 2){
        vehicleCost = 0;
      } 
      else if (totalTime <= 5){
        vehicleCost = (totalTime - 2) * 1;
      }
      else {
        vehicleCost = (3 * 1) + ((totalTime-5) * 0.5);
      }
      carIncome = carIncome + vehicleCost;
      vehicleType = "Car" ;
      carCount++;  
    }
    else if ( userVehicle == 'T'){
      if (totalTime <= 2){
        vehicleCost = 0;
      } 
      else if (totalTime <= 4){
        vehicleCost = (totalTime - 2) * 2;
      }
      else {
        vehicleCost = (2 * 2) + ((totalTime-4) * 1);
      }
      truckIncome = truckIncome + vehicleCost;
      vehicleType = "Truck";
      truckCount++;
    }
    else if ( userVehicle == 'S'  ) {
      vehicleCost = 0;
      vehicleType = "Senior Citizen";
      seniorCount++;
    }
  

    //output type, hours with "00", and cost.
    cout << setprecision(2) << fixed;
    cout << left << setw(6) << "Pentagon Parking Lot \n";
    cout << left << "Car Type: " << right << setw(10) << vehicleType << endl;
    cout << left << "Total Hours: " << right << setw(7) << totalTime << endl;
    cout << "Total Income: " << "$" << right << setw(5) << vehicleCost << endl; 
    
   cout << "Would you like to add another vehicle?(Y/N): ";
    cin >> userRepeat;
    userRepeat = toupper(userRepeat);

   while((userRepeat != 'Y' && userRepeat != 'N')) {
    cout << "Error! Would you like to add another vehicle?(Y/N): ";
    cin >> userRepeat;
    userRepeat = toupper(userRepeat);  
   }
  }while((userRepeat=='Y' || userRepeat=='y')); //can end program with any letter than Y. userRepeat=='Y' || userRepeat=='y'
  //cout total charges of everything
  totalIncome = truckIncome + carIncome;
  cout << setprecision(2) << fixed;
  cout << "TOTAL CHARGES: \n";
  cout << left << setw(27) << "Number of Cars: " << right << setw(8) <<carCount << endl;
  cout << left << setw(27) << "Number of Trucks: " << right << setw(8) << truckCount << endl;
  cout << left << setw(27) << "Number of Senior Citizens: " << right << setw(8) << seniorCount << endl;
  cout << left << setw(27) << "Car Charges: " << right << "$" << setw(7) << carIncome << endl;
  cout << left << setw(27) << "Truck Charges: " << right << "$" << setw(7) <<  truckIncome << endl;
  cout << left << setw(27) << "Total Charges: " << right << "$" << setw(7) << totalIncome << endl;
  cout << "Thank you, Good bye.\n";
  cout << "Program ended.";
}
