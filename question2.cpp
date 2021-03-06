///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 2 *****
// Question 2 consists of 3 parts
// 2.1  Create a class "Time" which implements a 24hr clock in the format hh:mm   
//      Include default constructor, destructor, accessor and mutator (see how they are used in main to
//      determine the format required.
//      Put the declaration and definition in appropriate files! 
// 2.2  Overload the stream insertion operator for your class to print the time in format hh:mm 
// 2.3  Overload the POSTFIX increment operator to increment the minutes (include carry if needed)


// ***** DO NOT MODIFY CODE BELOW THIS LINE *****
class Time
{
	
public:
	Time(int = 0, int = 0);
	void set(int hrs, int min)
	{
		sethrs(hrs);
		setmin(min);
	}
	friend ostream &operator<<(ostream &output, const Time & t)
	{
		output << t.hrs << ":" << t.min;
		return output;
	}

	void sethrs(int hrss)
	{
		hrs = hrss;
	}

	void setmin(int mins)
	{
		min = mins;
	}
	void get(int &hours, int &minutes)
	{
		hours = hrs;
		minutes = min;
	}

	Time operator++(int)
	{
		Time temp = *this;
		helpincrement();
		return temp;
	}

private:
	int hrs;
	int min;
	void helpincrement()
	{
		if (min < 60)
			min++;
		else
			hrs++;
		    min = 0;
	}
};


int main(int argc, char *argv[]) {

	Time myTime(8, 40);									// instantiate time class 

	cout <<myTime<< endl;			// demonstrate overloaded stream insertion operator

	myTime.set(10, 30);									// change the time

	int hours, mins;									// get changed time
	myTime.get(hours, mins);
	cout << "Design 1 starts at " << mins << " past " << hours;   // display time in another format

}