#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#define MAX 100000
#define MID 10000
#define MIN 1000

int raN[MAX], reN[MAX], temp[MAX];
int count = 0;
time_t start, end;

void make(int randN, int reverN) {
	int mn;
	if (randN != 0) {
		count = randN;
		for (int j = 0; j < randN; j++) {
			mn = rand() % (randN + 1);
			raN[j] = mn;
		}
	}
	if (reverN != 0) {
		count = reverN;
		mn = reverN;
		for (int i = 0; i < reverN; i++)
			reN[i] = mn--;
	}
}

double bubble(int *p, int randN, int reverN) {
	int hold = 0;
	make(randN, reverN);
	start = clock();
	for (int loop = 0; loop < count - 1; loop++) {
		for (int i = 0; i < count - 1 - loop; i++) {
			if (p[i] > p[i + 1]) {
				hold = p[i];
				p[i] = p[i + 1];
				p[i + 1] = hold;
			}
		}
	}
	end = clock();
	return (double)(end - start) / (CLOCKS_PER_SEC);
}

double selection(int *p, int randN, int reverN) {
	int min, temp;
	make(randN, reverN);
	start = clock();
	for (int i = 0; i < count - 1; i++)	{
		min = i;
		for (int j = i + 1; j < count; j++)	{
			if (p[j] < p[min])
				min = j;
		}
		temp = p[min];
		p[min] = p[i];
		p[i] = temp;
	}
	end = clock();
	return (double)(end - start) / (CLOCKS_PER_SEC);
}

double insertion(int *p, int randN, int reverN) {
	int i, j, remember;
	make(randN, reverN);
	start = clock();
	for (i = 1; i < count; i++)	{
		remember = p[(j = i)];
		while (--j >= 0 && remember < p[j]) {
			p[j + 1] = p[j];
			p[j] = remember;
		}
	}
	end = clock();
	return (double)(end - start) / (CLOCKS_PER_SEC);
}

void c_merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			temp[k++] = list[i++];
		else
			temp[k++] = list[j++];
	}
	if (i > mid) {
		for (l = j; l <= right; l++)
			temp[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			temp[k++] = list[l];
	}
	for (l = left; l <= right; l++)
		list[l] = temp[l];
}

void merge_sort(int *p, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(p, left, mid);
		merge_sort(p, mid + 1, right);
		c_merge(p, left, mid, right);
	}
}

double merge(int *p, int randN, int reverN) {
	make(randN, reverN);
	start = clock();
	merge_sort(p, 0, count - 1);
	end = clock();
	return (double)(end - start) / (CLOCKS_PER_SEC);
}

void quick_sort(int *p, int left, int right, int qn) {
	int i = left, j = right, temp, pivot, index;
	if (qn == 1)
		pivot = p[right];
	else if (qn == 2)
		pivot = p[(left + right) / 2];
	else
		pivot = p[rand() % (right + 1 - left) + left];
	do{
		while (p[i] < pivot)
			i++;
		while (p[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		quick_sort(p, left, j, qn);
	if (i < right)
		quick_sort(p, i, right, qn);
}

double quick(int *p, int randN, int reverN, int qn) {
	make(randN, reverN);
	start = clock();
	quick_sort(p, 0, count - 1, qn);
	end = clock();
	return (double)(end - start) / (CLOCKS_PER_SEC);
}

void print() {
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\tRandom1000\tReverse1000\tRandom10000\tReverse10000\tRandom100000\tReverse100000\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Bubble\t\t");
	printf("%.3lf\t\t", bubble(raN, MIN, 0));
	printf("%.3lf\t\t", bubble(reN, 0, MIN));
	printf("%.3lf\t\t", bubble(raN, MID, 0));
	printf("%.3lf\t\t", bubble(reN, 0, MID));
	printf("%.3lf\t\t", bubble(raN, MAX, 0));
	printf("%.3lf\n", bubble(reN, 0, MAX));
	printf("Selection\t");
	printf("%.3lf\t\t", selection(raN, MIN, 0));
	printf("%.3lf\t\t", selection(reN, 0, MIN));
	printf("%.3lf\t\t", selection(raN, MID, 0));
	printf("%.3lf\t\t", selection(reN, 0, MID));
	printf("%.3lf\t\t", selection(raN, MAX, 0));
	printf("%.3lf\n", selection(reN, 0, MAX));
	printf("Insertion\t");
	printf("%.3lf\t\t", insertion(raN, MIN, 0));
	printf("%.3lf\t\t", insertion(reN, 0, MIN));
	printf("%.3lf\t\t", insertion(raN, MID, 0));
	printf("%.3lf\t\t", insertion(reN, 0, MID));
	printf("%.3lf\t\t", insertion(raN, MAX, 0));
	printf("%.3lf\n", insertion(reN, 0, MAX));
	printf("Merge\t\t");
	printf("%.3lf\t\t", merge(raN, MIN, 0));
	printf("%.3lf\t\t", merge(reN, 0, MIN));
	printf("%.3lf\t\t", merge(raN, MID, 0));
	printf("%.3lf\t\t", merge(reN, 0, MID));
	printf("%.3lf\t\t", merge(raN, MAX, 0));
	printf("%.3lf\n", merge(reN, 0, MAX));
	//printf("Quick1\t\t");
	//printf("%.3lf\t\t", quick(raN, MIN, 0, 1));
	//printf("%.3lf\t\t", quick(reN, 0, MIN, 1));
	//printf("%.3lf\t\t", quick(raN, MID, 0, 1));
	//printf("%.3lf\t\t", quick(reN, 0, MID, 1));
	//printf("%.3lf\t\t", quick(raN, MAX, 0, 1));
	//printf("%.3lf\n", quick(reN, 0, MAX, 1));
	printf("Quick2\t\t");
	printf("%.3lf\t\t", quick(raN, MIN, 0, 2));
	printf("%.3lf\t\t", quick(reN, 0, MIN, 2));
	printf("%.3lf\t\t", quick(raN, MID, 0, 2));
	printf("%.3lf\t\t", quick(reN, 0, MID, 2));
	printf("%.3lf\t\t", quick(raN, MAX, 0, 2));
	printf("%.3lf\n", quick(reN, 0, MAX, 2));
	printf("Quick3\t\t");
	printf("%.3lf\t\t", quick(raN, MIN, 0, 3));
	printf("%.3lf\t\t", quick(reN, 0, MIN, 3));
	printf("%.3lf\t\t", quick(raN, MID, 0, 3));
	printf("%.3lf\t\t", quick(reN, 0, MID, 3));
	printf("%.3lf\t\t", quick(raN, MAX, 0, 3));
	printf("%.3lf\n", quick(reN, 0, MAX, 3));
}

int main()
{
	print();
	getchar(); 
}