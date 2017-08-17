#include <iostream>
#include <time.h>
#define MAX 100
using namespace std;

//Buble Sort - Sap xep noi bot
void bubleSort(int *a, int n){
	for (int i = n - 1, change = true; i >= 1 && change; i++){
		for (int j = 0; j < i; j++){
			if (a[j] < a[j + 1]){
				change = true;
				swap(a[j], a[j + 1]); //ham hoan vi cua namespace std
			}
		}
	}
}

//Selection Sort - Sap xep chon
void selectSort(int *a, int n){
	for (int i = 0, max; i < n - 1; i++){
		max = a[i];

		for (int j = i + 1; j < n; j++){
			if (a[j] > max)
				max = a[j];
		}

		a[i] = max;
	}
}

//Insert Sort - Sap xep chen
void insertSort(int *a, int n){
	for (int i = 1, temp, j; i < n; i++){
		temp = a[i];
		j = i;

		while (j > 0 && a[j - 1] < temp){
			a[j] = a[j - 1];
			j--;
		}

		a[j] = temp;
	}
}

//Quick Sort - Sap xep nhanh (de quy)
//input: left = 0 (vi tri phan tu dau mang), right = n - 1 (vi tri phan tu cuoi mang) 
void quickSort(int *a, int left, int right){
	int l = left, r = right, key = a[left];

	do{
		while (l < right && a[l] < key) l++;
		while (r >= left && a[r] > key) r--;

		if (l <= r){
			if (l < r){
				swap(a[l], a[r]); //ham hoan vi cua namespace std
			}
			l++; r--;
		}
	} while (l <= r);

	if (l < right) quickSort(a, l, right);
	if (r > left) quickSort(a, left, r);

	cout << "QuickSort: a[" << left << " - " << right << "]: ";
	for (int i = left; i <= right; i++)
	{
		cout << " " << a[i];
	}
	cout << "\n";
}

//Merge Sort - Sap xep tron (de quy)
//input: left = 0 (vi tri phan tu dau mang), right = n - 1 (vi tri phan tu cuoi mang)
void mergeSort(int *a, int left, int right){
	int mid = (left + right) / 2;

	if (left < mid) mergeSort(a, left, mid);
	if (mid + 1 < right) mergeSort(a, mid + 1, right);

	int temp[MAX]; //#define MAX 100

	for (int i = left, j = left, k = mid + 1; i <= right; i++){
		if (j <= mid && k <= right)
			temp[i] = (a[j] < a[k] ? a[j++] : a[k++]);
		else if (j > mid)
			temp[i] = a[k++];
		else
			temp[i] = a[j++];
	}
	
	cout << "MergeSort: a[" << left << " - " << right << "]: ";
	for (int i = left; i <= right; i++)
	{
		a[i] = temp[i];
		cout << " " << a[i];
	}
	cout << "\n";
}

int main(){
	srand(time(NULL));

	int a[MAX];
	int n = 10;

	cout << "Mang a ban dau:";
	for (int i = 0; i < n; i++){
		cout << " " << (a[i] = rand() % 9 + 1); // sinh ngau nhien a[i] >= 0 && a[i] <= 9
	}
	cout << "\n------------------------------------\n";

	//mergeSort(a, 0, n - 1);
	quickSort(a, 0, n - 1);

	cout << "------------------------------------\nMang a sau khi sap xep:";
	for (int i = 0; i < n; i++){
		cout << " " << a[i]; // sinh ngau nhien a[i] >= 0 && a[i] <= 9
	}
	cout << "\n";

	return 0;
}