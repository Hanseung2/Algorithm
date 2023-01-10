#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int H[99];
int n;

void upHeap(int i)
{
	int a = i / 2;
	int tmp;
	if (i == 1)
		return;
	if (H[a] < H[i]) {
		tmp = H[a];
		H[a] = H[i];
		H[i] = tmp;
	}

	upHeap(a);
}

void downHeap(int i)
{
	int leftchild = i * 2;
	int rightchild = i * 2 + 1;
	int bigger;
	int tmp;
	if (leftchild > n)
		return;
	bigger = leftchild;
	if (rightchild <= n) {
		if (H[bigger] < H[rightchild])
			bigger = rightchild;
	}
	if (H[i] < H[bigger]) {
		tmp = H[i];
		H[i] = H[bigger];
		H[bigger] = tmp;
	}
	downHeap(bigger);
}

int removemax()
{
	int key = H[1];

	H[1] = H[n];
	n -= 1;
	downHeap(1);

	return key;
}
void insertitem(int key)
{
	n += 1;
	H[n] = key;
	upHeap(n);

}
int main()
{
	char kind;
	int key;
	n = 0;

	while (1)
	{
		scanf("%c", &kind);

		if (kind == 'i')
		{
			scanf("%d", &key);
			insertitem(key);
			printf("0\n");
		}

		else if (kind == 'd')
		{
			printf("%d\n", removemax());
		}

		else if (kind == 'p')
		{
			if (n < 1)
				return;

			for (int i = 1; i <= n; i++)
			{
				printf(" %d", H[i]);
			}
			printf("\n");
		}

		else if (kind == 'q')
			break;
	}
}