#include <iostream> //allows program to perform input and output
using std::cin; //program uses names from the std namespace
using std::cout;
using std::endl;
int main(){
	//variables to store weight and height
	int weight{ 0 };
	float height{ 0 };

	//prompt the user for their weight and height and read them in
	cout << "Enter weight (Kgs): ";
	cin >> weight;
	cout << "Enter height (m): ";
	cin >> height;

	//calculate bmi;
	float bmi{ weight / (height * height) };

	cout << "\nYour BMI is: " << bmi << "\n\n"; //display user's BMI

	//display BMI information table
	cout << "BMI VALUES							 \n";
	cout << "Underweight:	less than 18.5		 \n";
	cout << "Normal:		between 18.5 and 24.9\n";
	cout << "Overweight:	between 25 and 29.9	 \n";
	cout << "Normal:		30 or greater        \n";
}