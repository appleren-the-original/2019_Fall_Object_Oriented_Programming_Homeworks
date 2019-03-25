/** 
 * @Author
 * Student Name: Alp Eren Gençoğlu
 * Student ID : 150170019
 * Date: 14.03.2019
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {
  private:
	int degree;
	int* values;
  
  public:
	Polynomial(int, int*);
	Polynomial(const Polynomial&);
	Polynomial();

	int* getvalues() const;
	int getdegree() const;
	
	Polynomial operator+(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	void operator=(const Polynomial&);


	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
};

#endif