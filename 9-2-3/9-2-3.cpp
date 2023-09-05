#include "sort.h"
#include "sort.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	vector<int> arr;
	int N, num_keys;
	int choice, qsort_n_comps{ 0 }, qsort_n_reeqs{ 0 }, ans;
	unsigned int start_time, end_time;
	while (true) {
		cout << "Выберите пункт меню:" << endl;
		cout << "0 - выйти из программы" << endl;
		cout << "1 - простая карманная сортировка" << endl;
		cout << "2 - поразрядная сортировка" << endl;
		cout << "3 - обобщенная карманная сортировка" << endl;
		vector<int> arr1 = arr;
		int* arrr1;
		int* arrr2;
		int* arrForPocketSort;
		int* arrForRadixSort;
		cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			cout << "Введите количество элементов, которое сгенерируется, чтобы произвести простую карманную сортировку" << endl;
			cin >> N;
			cout << "1 - произвести сортировку без второго массива\n2 - произвести сортировку со вторым массивом" << endl;
			cin >> ans;
			if (ans == 1) {
				arrr1 = generateArrForSimpleBucketSort(N);
				simpleBucketSortWithoutSecondArr(arrr1, N);
				cout << endl;
				delete[] arrr1;
			}
			else if (ans == 2) {
				arrr2 = generateArrForSimpleBucketSort(N);
				simpleBucketSortWithSecondArr(arrr2, N);
				delete[] arrr2;
			}
			break;
		case 2:
			cout << "Введите количество элементов, которое сгенерируется, чтобы произвести поразрядную сортировку" << endl;
			cin >> N;
			arrForRadixSort = generateArrForRadixSort(N);
			radixSort(arrForRadixSort, N);
			delete[] arrForRadixSort;
			break;
		case 3:
			cout << "Введите количество элементов, которое сгенерируется, чтобы произвести обобщенную карманную сортировку" << endl;
			cin >> N;
			cout << "Введите, как много ключей нужно сгенерировать" << endl;
			cin >> num_keys;
			arrForPocketSort = generateArrForGeneralPocketSort(N, num_keys);
			pocketSort(arrForPocketSort, N, num_keys);
			delete[] arrForPocketSort;
			break;
		}
		cout << endl;
	}
}
