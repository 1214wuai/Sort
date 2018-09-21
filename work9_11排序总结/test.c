#include<stdio.h>
#include<stdlib.h>
//1.实现插入、希尔、选择、堆排、冒泡、快排、归并排序 
//2.总结各个排序的性能、稳定性等优缺点。
void Print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Insertion_Sort(int arr[], int sz)
{
	//一个插入排序是一种简单排序，它的思路是：每次从未排好的序列中选出第一个元素插入到已排好的序列中。
	//它的算法步骤可以大致归纳如下：
		//1. 从未排好的序列中拿出首元素，并把它赋值给temp变量；
		//2. 从排好的序列中，依次与temp进行比较，如果元素比temp大，则将元素后移（实际上放置temp的元素位置已经空出）
		//3. 直到找到一个元素比temp小， 将temp放入该位置；
	int i = 0;
	int j = 0;
	for (i = 1; i < sz; i++)
	{
		int tmp = arr[i];
		for (j = i; (j > 0) && (arr[j - 1] > tmp); j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
	printf("Insertion_Sort:");
	Print(arr, sz);
}

void Shell_Sort(int arr[], int sz)
{
	int gap = sz;//gap越小越接近有序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)//每组同时进行
		{
			int end = i;
			int tmp = arr[end + gap];
 			while (end >= 0 && arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
	printf("Shell_Sort:");
	Print(arr, sz);
}
void Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
void Select_Sort(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	
	while (left < right)
	{
		int min = left;
		int max = right;
		int i = left;
		while (i < right)
		{
			if (arr[i] > arr[max])
				max = i;//找到最大的数
			if (arr[i] < arr[min])
				min = i;//找到最小的数
			i++;
		}
		Swap(&arr[left], &arr[min]);
		if (left == max)//如果最左边的数恰好最大，而最左边的数在上一行代码已经跟下标为min的数交换过
			max = min;
		Swap(&arr[right], &arr[max]);
		left++;
		right--;
	}
	printf("Select_Sort:");
	Print(arr, sz);
}

void Bubble_Sort(int arr[], int sz)
{
	int i, j;
	for (i = 0; i < sz; i++)
	{
		//int tmp = arr[i];
		for (j = i; j < sz; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(&arr[i], &arr[j]);
			}
		}
	}
	printf("Bubble_Sort:");
	Print(arr, sz);
}

void Quick_Sort(int arr[], int sz)
{
	int* key = &arr[0];
	int left = 1;
	int right = sz - 1;
	while (left < right)
	{
		while ((left < right)&&(arr[left] <= key))
		{
			++left;
		}
		while ((left < right)&&(arr[right] >= key))
		{
			--right;
		}
		Swap(&arr[left], &arr[right]);
		//Swap(&arr[left], &key);
	}
	Swap(&arr[left], key);
	printf("Quick_Sort:");
	Print(arr, sz);
}
test()
{
	int x = 1;
	int y = 2;
	Swap(&x, &y);
}
int main()
{
	int arr[] = { 5,9,4,6,2,8,0,7,3,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Insertion_Sort(arr, sz);
	//Shell_Sort(arr, sz);
	//Select_Sort(arr, sz);
	//Bubble_Sort(arr,sz);
	Quick_Sort(arr, sz);
	//test();
	system("pause");
	return 0;
}