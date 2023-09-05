#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>

struct Node
{
	int data{ -1 };
	Node* next{ nullptr };
};

struct listNode
{
    int key = -9999;
    listNode* next = NULL;
};
struct ArrElem
{
    int key = -9999;
    listNode* first = NULL;
    listNode* end = NULL;
};

void menu();
void fill_array(std::vector<int>& arr);
void bubble_sort(std::vector<int>& arr);
void insertion_sort(std::vector<int>& arr);
void selection_sort(std::vector<int>& arr);
void output_array(std::vector<int>& arr);
void quick_sort(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);
void shell_sort(std::vector<int>& arr);
void heap_sort(std::vector<int>& arr);
int* generateArrForSimpleBucketSort(int N);
int* generateArrForGeneralPocketSort(int N, int num_keys);
int* generateArrForRadixSort(int N);
void simpleBucketSortWithoutSecondArr(int* arr, int N);
void simpleBucketSortWithSecondArr(int* arr, int N);
void pocketSort(int* arr, int N, int num_keys);
int getMax(int* arr, int N);
void radixSort(int* arr, int N);
