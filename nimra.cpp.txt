#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char arr[9] = {'1','2','3','4','5','6','7','8','9' };
	
	cout << "\t|\t|"<<endl;
	cout <<  setw(4)<<arr[0]<<"\t|"<<setw(4)<<arr[1]<<"\t|"<<setw(4)<<arr[2] << endl;
	cout << "___|__|___"<<endl;
	cout << "\t|\t|"<<endl;
	cout <<  setw(4)<<arr[3]<<"\t|"<<setw(4)<<arr[4]<<"\t|"<<setw(4)<<arr[5] << endl;
	cout << "___|__|___"<<endl;
	cout << "\t|\t|" << endl;
	cout <<  setw(4)<<arr[6]<<"\t|"<<setw(4)<<arr[7]<<"\t|"<<setw(4)<<arr[8] << endl;
	cout << "\t|\t|";
}