/** 
 * @Author
 * Student Name: Alp Eren Gençoğlu
 * Student ID : 150170019
 * Date: 14.03.2019
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Vector.h"
#include "Polynomial.h"

using namespace std;

void readData(const char* filename, vector<Vector>& vecs) {
	int number_of_vecs;
	ifstream input_file;
	input_file.open(filename);

	input_file >> number_of_vecs;

	for (int i=0; i<number_of_vecs; i++){
		vecs.push_back(Vector());
		input_file >> vecs[i];
	}
}
void readData(const char* filename, vector<Polynomial>& pols) {
	int number_of_pols;
	ifstream input_file;
	input_file.open(filename);

	input_file >> number_of_pols;

	for (int i=0; i<number_of_pols; i++){
		pols.push_back(Polynomial());
		input_file >> pols[i];
	}
}
/*void printData(vector<auto>& arr){
	int index = 1;
	for(auto i : arr) cout << index++ << ". " << i << endl;
	cout << endl;
}*/
void printData(vector<Vector>& arr){
	int size = arr.size();
	for(int i=0; i<size; i++) cout << i+1 << ". " << arr[i] << endl;
	cout << endl;
}
void printData(vector<Polynomial>& arr){
	int size = arr.size();
	for(int i=0; i<size; i++) cout << i+1 << ". " << arr[i] << endl;
	cout << endl;
}
void printMenu(){
	cout << "Possible Actions:" << endl 
		<< "1. Print Polynomial and Vector lists" << endl
		<< "2. Do a polynomial operation " << endl
		<< "3. Do a vector operation" << endl
		<< "4. Help: Print possible actions" << endl
		<< "0. Exit the program" << endl;
}
void polOperation(vector<Polynomial>& arr) {
	int size = arr.size();
	int operand1, operand2;
	char operation;
	cout << "Which polynomial operation would you like to do? (+:addition, *:multiplication):\n";
	cin >> operand1;
	cin >> operation;
	cin >> operand2;
	
	if(operand1 < 1 || operand1 > size || operand2 < 1 || operand2 > size ){
		cout << "Entered polynomial does not exist!" << endl;
		return;
	}
	
	Polynomial p;

	switch(operation){
		case '+':
			p = arr[operand1-1] + arr[operand2-1];
			break;
		case '*':
			p = arr[operand1-1] * arr[operand2-1];
			break;
		default:
			cout << "You entered an invalid operation!" << endl;
			return;
	}

	cout << "(" << arr[operand1-1] << ") " << operation << " (" << arr[operand2-1] << ") = " << p << endl;
}
void vecOperation(vector<Vector>& arr) {
	int size = arr.size();
	int operand1, operand2;
	char operation;
	cout << "Which vector operation would you like to do? (+:addition, *:scalar multiplication, .:dot product):\n";
	cin >> operand1;
	cin >> operation;
	cin >> operand2;

	Vector v;
	int res;

	switch(operation){
		case '+':
			if(operand1 < 1 || operand1 > size || operand2 < 1 || operand2 > size ){
				cout << "Entered vector does not exist!" << endl;
				return;
			}
			if(arr[operand1-1].getsize() != arr[operand2-1].getsize()){
				cout << "Sizes of two vectors do not match!" << endl;
				return;
			}
			v = arr[operand1-1] + arr[operand2-1];
			cout << arr[operand1-1] <<" + "<< arr[operand2-1] << " = " << v << endl;
			break;
		case '.':
			if(operand1 < 1 || operand1 > size || operand2 < 1 || operand2 > size ){
				cout << "Entered vector does not exist!" << endl;
				return;
			}
			if(arr[operand1-1].getsize() != arr[operand2-1].getsize()){
				cout << "Sizes of two vectors do not match!" << endl;
				return;
			}
			res = arr[operand1-1] * arr[operand2-1];
			cout << arr[operand1-1] << " . " << arr[operand2-1] << " = " << res << endl;
			break;
		case '*':
			if(operand1 < 1 || operand1 > size ){
				cout << "Entered vector does not exist!" << endl;
				return;
			}
			v = arr[operand1-1] * operand2;
			cout << arr[operand1-1] << " * " << operand2 << " = " << v << endl;
			break;
		default:
			cout << "You entered an invalid operation!" << endl;
			return;	
	}

}

int main(int argc, char const *argv[])
{
	vector<Vector> vecs;
	vector<Polynomial> pols;
	int action;

	readData("Vector.txt", vecs);
	readData("Polynomial.txt", pols);

	printMenu();

	while(true) {
		cout << "\nEnter an option: ";
		cin >> action;
		switch( action ){
			case 1:
				cout << "Vectors:\n";
				printData(vecs);
				cout << "Polynomials:\n";
				printData(pols);
				break; 
			case 2:
				polOperation(pols);
				break;
			case 3:
				vecOperation(vecs);
				break;
			case 4:
				printMenu();
				break;
			case 0:
				return 0;
		}
	}


	return 0;
}