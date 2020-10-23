//Kevin Lee
//Lab #6
//Kevin6523@gmail.com
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//Method declaration
void inputData(double balance, double rate, double payment);
void printHeader();
void printResult(int month, double balance, double interest, double minPayment, double sumInterest);
void input(double& balance, double& rate, double& payment);
void calcData(double balance, double rate, double payment, double& interest, double& minPayment);
int main()
{
	int month = 1;
	double balance, rate, payment, sumInterest, interest, minPayment;
	input(balance, rate, payment);
	inputData(balance, rate, payment);
	printHeader();
	int test = 1;
	while(test > 0)
	{
		calcData(balance, rate, payment, interest, minPayment);
		//Update sum of interest
		sumInterest += interest;
		//Update balance
		balance = balance - (minPayment-interest);
		printResult(month, balance, interest, minPayment, sumInterest);
		//Update month
		month ++;
		test = balance;
		
	}
}
void input(double& balance, double& rate, double& payment)
{
	/*Pre: balance: reference to balance
	rate: reference to yearly apr rate
	payment: reference to min payment rate
	Post: None
	Purpose: Input variables from file
	*/
	//Variable initialization
	double balance1, rate1, payment1;
	//Open an input file
	ifstream myfile("lab6.txt");
	//Test if file exists
	if(myfile.fail() == 1)
	{
		cout<<"Error file does not exist."<<endl;
		exit(100);
	}
	myfile>> balance1;
	balance = balance1;
	myfile>>rate1;
	rate = rate1;
	myfile>>payment1;
	payment = payment1;

}
void calcData(double balance, double rate, double payment, double& interest, double& minPayment)
{
	/*Pre: balance: balance
	rate: yearly apr rate
	payment: min payment rate
	interest: reference to interest
	minPayment: reference to minPayment
	Post: None
	Purpose: Calculate interest and minpayment
	*/
	double payment1 = payment / 100.0;
	double rate1 = rate/1200.0;
	double interest1, minPayment1;
	if(balance< 15)
	{
		interest1 = balance * rate1;
		interest = interest1;
		minPayment1 = balance + interest;
		minPayment = minPayment1;
	}
	else if(balance * payment1 < 15)
	{
		minPayment1 = 15.00;
		minPayment = minPayment1;
		interest1 = balance * rate1;
		interest = interest1;
	}
	else
	{
		interest1 = balance * rate1;
		interest = interest1;
		minPayment1 = (balance + interest) * payment1;
		minPayment = minPayment1;
	}
}
void printHeader()
{
	/*Pre: None
	Post: None
	Purpose: Print header to output file
	*/
	//Appending output to output file
	ofstream myfile("lab6output.txt",ios::app);
	myfile<<"Month"<<"\t"<<"Balance"<<"\t"<<"\t"<<"Interest"<<"\t"<<"Minimum"<<"\t"<<"\t"<<"Sum of"<<endl;
	myfile<<"\t"<<"\t"<<"\t"<<"this month"<<"\t"<<"\t"<<"\t"<<"interest paid"<<endl;
	
}
void inputData(double balance, double rate, double payment)
{
	/*Pre: balance: current balance
	rate: apr rate
	payment: minimum payment percent
	Post: None
	Purpose: Put data into the output file
	*/
	//Creates output file
	ofstream myfile("lab6output.txt");
	myfile<<"Balance Owing: $"<<balance<<"\n";
	myfile<<"APR as % "<<rate<<"\n";
	myfile<<"Percent of minimum payment as % "<<payment<<"\n";

}
void printResult(int month, double balance, double interest, double minPayment, double sumInterest)
{	/*Pre: month: month #
	balance: current balance
	interest: interest
	minPayment: minimum payment amt
	sumInterest: sum of interest paid
	Post: None
	Purpose: Print results
	*/
	ofstream myfile("lab6output.txt",ios::app);
	myfile<<month<<"\t"<<fixed<<setprecision(2)<<right<<balance<<"\t"<<"\t"<<interest<<"\t"<<"\t"<<minPayment<<"\t"<<"\t"<<sumInterest<<endl;
	
}
