#include "sort.h"
using namespace std;

bool comp(int a, int b) {
	return a ? (a > b) : b;
}

void fill_array(vector<int>& arr) {
	cout << "Введите количество элементов в массиве (не больше 10 000)" << endl;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % 1000);
	}
}

void bubble_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		for (int j{ 0 }; j < arr.size() - 1; j++) {
			n_comps++;
			if (comp(arr[j], arr[j + 1])) {
				n_reeqs += 3;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	// проверяет соселние элементы и меняетм местами
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void insertion_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int i, key, j;

	for (i = 1; i < arr.size(); i++)
	{
		n_reeqs++;
		key = arr[i];
		j = i - 1;
		n_comps++;
		while (j >= 0 && comp(arr[j], key))
		{
			n_comps++;
			arr[j + 1] = arr[j];
			n_reeqs++;
			j--;
		}

		n_comps++;
		if (arr[j + 1] != key) {
			arr[j + 1] = key;
			n_reeqs++;
		}
	}
	// один элемент сравнивает со всеми, пока тот не встанет на место
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void selection_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		int min_ind = i;
		for (int j{ i + 1 }; j < arr.size(); j++) {
			n_comps++;
			if (comp(arr[min_ind], arr[j])) {
				min_ind = j;
			}
		}
		if (min_ind != i) {
			n_reeqs += 3;
			swap(arr[i], arr[min_ind]);
		}
	}
	// поиск наибольшего элемента и перемещение его в отсортированную часть списка
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void quick_sort(vector<int>& arr, int start, int end, int& n_comps, int& n_assigs) {
	int pivot{ arr[(start + end) / 2] };

	int low{ start };
	int high{ end };
	while (low <= high) {
		n_comps++;
		while (arr[low] < pivot) {
			low++;
			n_comps++;
		}

		++n_comps;
		while (arr[high] > pivot) {
			high--;
			n_comps++;
		}

		if (low <= high) {
			n_comps++;
			if (arr[low] != arr[high]) {
				swap(arr[low], arr[high]);
				n_assigs += 3;
			}
			low++;
			high--;
		}
	}
	// выбор опорного элемента, разделение пополам и рекурсия пока не будет 1 или 0 элементов
	if (start < high)
		quick_sort(arr, start, high, n_comps, n_assigs);
	if (low < end)
		quick_sort(arr, low, end, n_comps, n_assigs);
}

void heapify(vector<int>& arr, int i, int size, int& n_comps, int& n_reeqs) {
	int largest{ i };
	int left{ 2 * i + 1 };
	int right{ 2 * i + 2 };

	n_comps++;
	if (left < size && arr[left] > arr[largest])
		largest = left;

	n_comps++;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		if (arr[largest] != arr[i]) {
			n_reeqs += 3;
			swap(arr[i], arr[largest]);
		}
		heapify(arr, largest, size, n_comps, n_reeqs);
	}
}

void heap_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	int size = (int)arr.size();

	for (int i{ size / 2 - 1 }; i >= 0; i--) {
		heapify(arr, i, size, n_comps, n_reeqs);
	}

	for (int i{ size - 1 }; i >= 0; i--) {
		if (arr[0] != arr[i]) {
			n_reeqs += 3;
			swap(arr[0], arr[i]);
		}
		heapify(arr, 0, i, n_comps, n_reeqs);
	}
	// сначала создаем пирамиду и делаем так, чтобы наименьший элемент был на вершине. Меняем  верхний и последний элементы массива, проводим просеивание. И так пока не будет отсортировано. 
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void shell_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int temp{};
	for (int gap{ (int)arr.size() }; gap > 0; gap /= 2) {
		for (int i{ gap }; i < arr.size(); ++i) {
			n_reeqs++;
			int temp{ arr[i] };
			int j{};
			n_comps++;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				n_comps++;
				arr[j] = arr[j - gap];
				n_reeqs++;
			}
			arr[j] = temp;
			n_reeqs++;
		}
	}
	// сравнение элементов с шагом, который постепенно уменьшается
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void push_back(Node*& head, int data) {
	Node* cur{ head };
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = new Node;
	cur->next->data = data;
}

void output_array(vector<int>& arr) {
	for (int i{ 0 }; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int* generateArrForSimpleBucketSort(int N)
{
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = i;
	}
	random_shuffle(&arr[0], &arr[N]);
	return arr;
}

int* generateArrForGeneralPocketSort(int N, int num_keys)
{
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % num_keys;
	}

	return arr;
}

int* generateArrForRadixSort(int N)
{
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	return arr;
}

void simpleBucketSortWithoutSecondArr(int* arr, int N)
{
	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int temp;
	for (int i = 0; i < N; i++)
	{
		while (arr[i] != i)
		{
			temp = arr[arr[i]];
			arr[arr[i]] = arr[i];
			arr[i] = temp;
		}
	}
	// элементы распределяются по группам, а затем сортируются внутри групп и объединяются обратно
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void simpleBucketSortWithSecondArr(int* arr, int N)
{
	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int* resMas = new int[N] {0};
	for (int i = 0; i < N; i++)
	{
		resMas[arr[i]] = arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = resMas[i];
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] resMas;
}

void pocketSort(int* arr, int N, int num_keys)
{

	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	ArrElem* arrOfLists = new ArrElem[num_keys];

	for (int i = 0; i < N; i++)
	{

		if (arrOfLists[arr[i]].key == -9999)
		{
			arrOfLists[arr[i]].key = arr[i];
			listNode* newListNode = new listNode;
			newListNode->key = arr[i];
			arrOfLists[arr[i]].first = newListNode;
			arrOfLists[arr[i]].end = newListNode;
		}
		else
		{
			listNode* newListNode = new listNode;
			newListNode->key = arr[i];
			arrOfLists[arr[i]].end->next = newListNode;
			arrOfLists[arr[i]].end = newListNode;
		}
	}


	listNode* listTopStart = arrOfLists[0].first;
	listNode* listTopLast = arrOfLists[0].end;

	for (int i = 0; i < num_keys - 1; i++)
	{
		if (listTopLast == NULL)
		{

			listTopStart = arrOfLists[i].first;
			listTopLast = arrOfLists[i].end;
			if (listTopLast != NULL)
			{
				listTopLast->next = arrOfLists[i + 1].first;
				if (arrOfLists[i + 1].key != -9999)
				{
					listTopLast = arrOfLists[i + 1].end;
				}
			}
		}
		else
		{
			listTopLast->next = arrOfLists[i + 1].first;
			if (arrOfLists[i + 1].key != -9999)
			{
				listTopLast = arrOfLists[i + 1].end;
			}
		}
	}

	listNode* temp;
	for (int i = 0; i < N; i++)
	{
		temp = listTopStart;
		arr[i] = listTopStart->key;
		listTopStart = listTopStart->next;
		delete temp;
	}

	// сортировка для случая повторяющихся ключей
	// используем вспомогательные списки для хранения элементов с одинаковыми ключами
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arrOfLists;
}

int getMax(int* arr, int N)
{
	int max = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void radixSort(int* arr, int N)
{
	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int maxElem = getMax(arr, N);
	for (int place = 1; maxElem / place > 0; place *= 10)
	{
		ArrElem* arrOfLists = new ArrElem[10];
		for (int i = 0; i < N; i++)
		{

			if (arrOfLists[(arr[i] / place) % 10].key == -9999)
			{
				arrOfLists[(arr[i] / place) % 10].key = (arr[i] / place) % 10;
				listNode* newListNode = new listNode;
				newListNode->key = arr[i];
				arrOfLists[(arr[i] / place) % 10].first = newListNode;
				arrOfLists[(arr[i] / place) % 10].end = newListNode;
				newListNode->next = NULL;
			}
			else
			{
				listNode* newListNode = new listNode;
				newListNode->next = NULL;
				newListNode->key = arr[i];
				arrOfLists[(arr[i] / place) % 10].end->next = newListNode;
				arrOfLists[(arr[i] / place) % 10].end = newListNode;
			}
		}

		listNode* listTopStart = arrOfLists[0].first;
		listNode* listTopLast = arrOfLists[0].end;

		for (int i = 0; i < 10; i++)
		{
			if (listTopLast == NULL)
			{

				listTopStart = arrOfLists[i].first;
				listTopLast = arrOfLists[i].end;
				if (listTopLast != NULL)
				{
					listTopLast->next = arrOfLists[i + 1].first;
					if (arrOfLists[i + 1].key != -9999)
					{
						listTopLast = arrOfLists[i + 1].end;
					}
				}
			}
			else
			{
				listTopLast->next = arrOfLists[i + 1].first;
				if (arrOfLists[i + 1].key != -9999)
				{
					listTopLast = arrOfLists[i + 1].end;
				}
			}
		}


		listNode* temp;
		for (int i = 0; i < N; i++)
		{
			temp = listTopStart;
			arr[i] = listTopStart->key;
			listTopStart = listTopStart->next;
			delete temp;
		}


		for (int i = 0; i < 10; i++)
		{
			arrOfLists[i].key = -9999;
			arrOfLists[i].end = NULL;
			arrOfLists[i].first = NULL;
		}
	}
	// сортировка по разрядам. сколько разрядов у самого длинного числа, массив с ячейками куда числа складываются в соответствии с тем, какое у них число в первом разряде. итд
	// в итоге сортировка без сравнений. (сортируется с конца)
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

