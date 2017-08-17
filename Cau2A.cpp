#include <iostream>
using namespace std;

int Fibonacy(int n){
	if (n == 1 || n == 0) return 1;
	return Fibonacy(n - 1) + Fibonacy(n - 2);
}

int main(){
	cout << Fibonacy(5) << "\n";
	return 0;
}