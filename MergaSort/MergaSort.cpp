#include<iostream>

using namespace std;

void Merga(int a[], int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = 0;
	int n = r - l + 1;
	int *b = new int[n];
	while ((i < m + 1) && (j < r + 1)) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			k++;
			i++;
		}
		else {
			b[l] = a[j];
			k++; j++;
		}

	}
	while (i < m + 1) {
		b[k] = a[i];
		k++; i++;
	}
	while (j < r + 1) {
		b[k] = a[j];
		k++;
		j++;
	}
	i = l;
	for (k = 0; k < n; k++) {
		a[i] = b[k];
		i++;
	}
	delete[]b;
}
void Input(int a[], int n) {
	for (int i = 0;i<n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ":";
		cin >> a[i];
	}
}
void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}
void MergaSort(int a[], int l, int r) {
	if (l >= r)return;
	else {
		int t = (l + r) / 2;
		MergaSort(a, l, t);
		MergaSort(a, t + 1, r);
		Merga(a, l, t, r);
	}

}
int main() {
	int n, *a;
	cout << "Nhap so phan tu cua mang:";
	cin >> n;
	a = new int[n];
	Input(a, n);
	cout << "Mang truoc sap xep:" << endl;
	Output(a, n);
	cout << "Mang sau sap xep:" << endl;
	MergaSort(a, 0, n - 1);
	Output(a, n);
	system("pause");
	return 0;
}