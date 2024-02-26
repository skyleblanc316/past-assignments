#ifndef MILTIME_H
#define MILTIME_H

class milTime   //store the time of the day in military format
{//unless specified all member of a class are private (public for struct)
public:
	milTime();//default constructor, defaults to 0:0:0
	void print();//print the time in the format hh:mm:ss
	void set(int h, int m, int s); //sets time to h:m:s
	void reset(); //resets the time to 0:0:0
private:
	int hours;
	int minutes;
	int seconds;
};
#endif