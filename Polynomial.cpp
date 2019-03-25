/** 
 * @Author
 * Student Name: Alp Eren Gençoğlu
 * Student ID : 150170019
 * Date: 14.03.2019
 */

#include <iostream>
#include "Polynomial.h"
using namespace std;

//
// getters
//
int* Polynomial::getvalues() const
	{return this->values;}
int Polynomial::getdegree() const
	{return this->degree;}



//
// Constructors
//
Polynomial::Polynomial() {this->degree = -1;}

Polynomial::Polynomial(int degree_in, int* values_in){
	degree = degree_in;
	values = new int[degree + 1];

	for (int i=0; i<degree+1; i++){
		values[i] = values_in[i];
	}
}

Polynomial::Polynomial(const Polynomial& pol){
	degree = pol.getdegree();
	values = new int[degree + 1];
	int* pol_values = pol.getvalues();

	for (int i=0; i<degree+1; i++){
		values[i] = pol_values[i];
	}
}



//
// addition, multiplication & assignment overloads
//
Polynomial Polynomial::operator+(const Polynomial& pol){
	int pol_degree = pol.getdegree();
	int* pol_values = pol.getvalues();
	int degree_new, degree_min, *greater, *smaller;
	if(this->degree >= pol_degree) {
		degree_new = this->degree;
		greater = this->values;
		degree_min = pol_degree;
		smaller = pol_values;
	}
	else {
		degree_new = pol_degree;
		greater = pol_values;
		degree_min = this->degree;
		smaller = this->values;
	}
	
	int* values_new = new int[degree_new+1];
	int j = 0;
	
	for(int i=0; i<degree_new+1; i++){
		if (degree_min+i < degree_new)
			values_new[i] = greater[i];
		else
			values_new[i] = greater[i] + smaller[j++];
	}

	return Polynomial(degree_new, values_new);
}

Polynomial Polynomial::operator*(const Polynomial& pol){
	int pol_degree = pol.getdegree();
	int* pol_values = pol.getvalues();
	int degree_new = this->degree + pol_degree;
	int* values_new = new int[degree_new + 1]();
	
	for (int i = 0; i<this->degree+1; i++){
		for(int j=0; j<pol_degree+1; j++){
			values_new[i+j] += this->values[i] * pol_values[j];
		}
	}

	return Polynomial(degree_new, values_new);
}

void Polynomial::operator=(const Polynomial& pol){
	int pol_degree = pol.getdegree();
	int* pol_values = pol.getvalues();

	if(this->degree != pol_degree){
		this->degree = pol_degree;
		//if(this->values != NULL) delete [] this->values;
		this->values = new int[this->degree + 1];
	}
	for(int i=0; i < this->degree+1; i++){
		this->values[i] = pol_values[i];
	}
}

//
// input & output overloads
//
ostream& operator<<(ostream& os, Polynomial& pol){
	int pol_degree = pol.getdegree();
	int* pol_values = pol.getvalues();
	for(int i=0; i<pol_degree+1; i++){
		int deg = pol_degree-i;
		if(pol_values[i]==0) continue;
		if(pol_values[i] != 1 && deg!=0)	
			os << pol_values[i];
		if(deg!=0 && deg!=1)
			os << "x^" << deg;
		else if(deg!=0)
			os << "x";
		else
			os << pol_values[i];

		if(i!=pol_degree)
			os << " + ";
		//if(pol_values[i]!=0 && pol_values[i])
	}
	return os;
}

istream& operator>>(istream& is, Polynomial& pol){
	is >> pol.degree;
	for (int i=0; i<pol.degree+1; i++){
		is >> pol.values[i];
	}
	return is;
}