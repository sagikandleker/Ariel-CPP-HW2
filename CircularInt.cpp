#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;

struct CircularInt{

	int min;
	int max;
	int now;

	friend CircularInt operator-(int num,const CircularInt & h);
	// constructor getting two numbers that will be the range

	CircularInt(int a, int b)
	{
		if(a > b)
		{
			this->max = a;
			this->min = b;
		}
		else
		{
			this->min = a;
			this->max = b;
		}
		this->now = this->min;
	}

	//copy constructor

	CircularInt(const CircularInt& h)
	{
		this->min = h.min;
		this->max = h.max;
		this->now = h.now;
	}

	//overload operator + by adding another class object

	CircularInt operator+(const CircularInt& h)
	{
		CircularInt hour{min,max};
		hour.now = this->now + h.now;
		
		/*while(hour.now > max){
			hour.now = hour.now - max;
		}*/
		
		if(hour.now > max)
		{
			hour.now = hour.now % max;
		}
		return hour;
	}

	//overload operator + by adding number

	CircularInt operator+(int num) {
		CircularInt hour{min,max};
		hour.now=now+num;
		while(hour.now>max){
			hour.now=hour.now-max;
		}
		return hour;
	}

	//overload operator - by decreasing number

	CircularInt operator-(int num) {
		CircularInt hour{min,max};
		hour.now=num-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}

	//overload operator - by decreasing max range number

	CircularInt operator-() {
		CircularInt hour{min,max};
		hour.now=max-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}


	//overload operator += by adding number and return the current class object

	CircularInt& operator+=(int num) {
		this->now = this->now+num;
		if(this->now > max)
		{
			this->now = this->now % max;
		}
		return *this;
	}

	CircularInt operator--(int){
		CircularInt temp(*this);
		operator--();
		return temp;
	}
	CircularInt& operator--(){
		now--;
		while(now<min){
			now=now+max;
		}
		return *this;
	}

	CircularInt operator++(int){
		CircularInt temp(*this);
		operator++();
		return *this;
	}

	CircularInt& operator++(){
		this->now++;
		if(this->now > 12)
		{
			this->now = this->now % max;
		}
		return *this;
	}

	CircularInt operator*=(int num){
		this->now*=num;
		
		if(this->now > max)
		{
			this->now = this->now % max;
		}
		return *this;
	}


	vector<int> operator/(int num){

		vector<int> vec;
		for(int i = min; i <= max; i++)
		{
			int temp = i*num;
			if(temp > max)
			{
				temp = temp % max;
			}
			if(temp == now)
			{
				vec.push_back(i);
			}
		}

		if(vec.size() == 0)
		{
			throw string("There is no number x in {1,12} such that x*"+to_string(num)+"=10");
		}

		return vec;
	}
};

CircularInt operator-(int num,const CircularInt & h) {
	CircularInt temp{h.min,h.max};
	temp.now=num-h.now;
	
	if(temp.now < temp.min)
	{
		temp.now = temp.now % temp.max + temp.max;
	}
	return temp;
	}
//overload operator << print class object number

std::ostream &operator<<(std::ostream &os, CircularInt const &m) {
	return os << m.now;
}

std::ostream &operator<<(std::ostream &os, vector<int> vec) {
	string result = "";
	for(int i = 0; i < vec.size(); i++ )
	{
		result = result + to_string(vec[i]) + " ";
	}
	return os << result;
}
