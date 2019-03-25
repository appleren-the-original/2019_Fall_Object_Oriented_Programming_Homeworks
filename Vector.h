/** 
 * @Author
 * Student Name: Alp Eren Gençoğlu
 * Student ID : 150170019
 * Date: 14.03.2019
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {
  private:
	int size;
	int* values;
  
  public:
	Vector(int, int*);
	Vector(const Vector&);
	Vector();

	int* getvalues() const;
	int getsize() const;
	
	Vector operator+(const Vector&);
	int operator*(const Vector&);
	Vector operator*(int);
	void operator=(const Vector&);

	friend ostream& operator<<(ostream&, Vector&);
	friend istream& operator>>(istream&, Vector&);
};

#endif