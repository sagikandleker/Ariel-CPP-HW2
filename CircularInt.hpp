#pragma once
#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

class CircularInt{
	private:
		int min, max;
		int now;

	public:
		CircularInt(int a, int b);
		CircularInt(const CircularInt& h);
		CircularInt operator+(const CircularInt& h);
		CircularInt operator+(int num);
		CircularInt operator-(int num);
		CircularInt operator-();
		CircularInt& operator+=(int num);
		CircularInt operator--(int);
		CircularInt& operator--();
		CircularInt operator++(int);
		CircularInt& operator++();
		CircularInt operator*=(int num);
		vector<int> operator/(int num);

		friend CircularInt operator-(int num,const CircularInt & h);
		
		friend ostream& operator<< (ostream& os, const CircularInt &m);
	
};


//inline CircularInt operator-(int num,const CircularInt & h);

inline ostream& operator<<(ostream& os, const CircularInt &m) {
	os << m.now;
	return os;
}

inline ostream &operator<<(ostream &os, vector<int> vec) {
	string result = "";
	for(int i = 0; i < vec.size(); i++ )
	{
		result = result + to_string(vec[i]) + " ";
	}
	return os << result;
}
