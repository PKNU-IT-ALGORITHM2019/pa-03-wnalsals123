#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int raN[MAX], reN[MAX];
double start, end;
int count = 0;

void print() {
	int i = 0;
	printf("\t\tRandom1000\tReverse1000\tRandom1000\tReverse10000\tRandom100000\tReverse100000\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	//printf("Selection\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i++], rett[i++]);
	//printf("Insertion\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i++], rett[i++]);
	//printf("Merge\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i++], rett[i++]);
	//printf("Quick1\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i++], rett[i++]);
	//printf("Quick2\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i++], rett[i++]);
	//printf("Quick3\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", ratt[i++], rett[i++], ratt[i++], rett[i++], ratt[i], rett[i]);
}

void make(int randN) {
	int mn;
	if (reN[0] == 0) {
		mn = MAX;
		for (int i = 0; i < MAX; i++)
			reN[i] = mn--;
	}
	for (int j = 0; j < randN; j++) {
		mn = rand() % (randN + 1);
		raN[j] = mn;
	}
}

void bubble() {
	printf("Bubble\t\t");
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\n", 0);
}

void selection() {
	printf("Selection\t");
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\n", 0);
}

void insertion() {
	printf("Insertion\t");
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\n", 0);
}

void merge() {
	printf("Merge\t\t");
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\n", 0);
}

void quick(int pivot) {
	printf("Quick1\t\t");
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\t\t", 0);
	printf("%.3lf\n", 0);
}

int main()
{
	make(1000);
	print();
	bubble();
	getchar();
}