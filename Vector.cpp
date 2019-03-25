/** 
 * @Author
 * Student Name: Alp Eren Gençoğlu
 * Student ID : 150170019
 * Date: 14.03.2019
 */

#include <iostream>
#include "Vector.h"
using namespace std;

//
// getters
//
int* Vector::getvalues() const
	{return this->values;}
int Vector::getsize() const
	{return this->size;}



//
// Constructors
//
Vector::Vector(){this->size = 0;}

Vector::Vector(int size_in, int* values_in){
	size = size_in;
	values = new int[size];

	for (int i=0; i<size; i++){
		values[i] = values_in[i];
	}
}

Vector::Vector(const Vector& vec){
	size = vec.getsize();
	values = new int[size];
	int* vec_values = vec.getvalues();

	for (int i=0; i<size; i++){
		values[i] = vec_values[i];
	}
}



//
// addition, multiplication & assignment overloads
//
Vector Vector::operator+(const Vector& vec) {
	int* values_new = new int[size];
	int* vec_values = vec.getvalues();

	for (int i=0; i <size; i++){
		values_new[i] = values[i] + vec_values[i];
	}
	return Vector(size, values_new);
}

int Vector::operator*(const Vector& vec) {
	int dot_product = 0;
	for(int i=0; i<size; i++){
		dot_product += values[i] * vec.values[i];
	}
	return dot_product;
}

Vector Vector::operator*(int k) {
	int* values_new = new int[size];
	for(int i=0; i<size; i++){
		values_new[i] = values[i] * k;
	}
	return Vector(size, values_new);
}

void Vector::operator=(const Vector& vec){
	int vec_size = vec.getsize();
	int* vec_values = vec.getvalues();

	if(this->size != vec_size){
		this->size = vec_size;
		//if(this->values != NULL) delete [] this->values;
		this->values = new int[this->size];
	}
	for(int i=0; i<this->size; i++){
		this->values[i] = vec_values[i];
	}
}


//
// input & output overloads
//
ostream& operator<<(ostream& os, Vector& vec) {
	int vec_size = vec.getsize();
	os << "(";
	for(int i=0; i<vec.getsize(); i++){
		os << vec.values[i];
		if( !(i==vec_size-1) ) os << ", ";
	}
	os << ")";
	return os;
}

istream& operator>>(istream& is, Vector& vec) {
	is >> vec.size;
	int vec_size = vec.getsize();
	for (int i=0;  i<vec_size; i++) {
		is >> vec.values[i];
	}
	return is;
}
