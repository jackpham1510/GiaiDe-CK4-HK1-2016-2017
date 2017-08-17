#include <iostream>
using namespace std;

void quickSort(int* , int , int);

int main(){
	int *a, n;
	cout << "Nhap so luong phan tu n: ";
	cin >> n;

	for (int i = 0; i < n; i++){
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}

	quickSort(a, 0, n - 1);

	cout << "Mang a sau khi sap xep:";
	for (int i = 0; i < n; i++){
		cout << " " << a[i];
	}
	cout << "\n";
	return 0;
}