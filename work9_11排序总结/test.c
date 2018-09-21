#include<stdio.h>
#include<stdlib.h>
//1.ʵ�ֲ��롢ϣ����ѡ�񡢶��š�ð�ݡ����š��鲢���� 
//2.�ܽ������������ܡ��ȶ��Ե���ȱ�㡣
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
	//һ������������һ�ּ���������˼·�ǣ�ÿ�δ�δ�źõ�������ѡ����һ��Ԫ�ز��뵽���źõ������С�
	//�����㷨������Դ��¹������£�
		//1. ��δ�źõ��������ó���Ԫ�أ���������ֵ��temp������
		//2. ���źõ������У�������temp���бȽϣ����Ԫ�ر�temp����Ԫ�غ��ƣ�ʵ���Ϸ���temp��Ԫ��λ���Ѿ��ճ���
		//3. ֱ���ҵ�һ��Ԫ�ر�tempС�� ��temp�����λ�ã�
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
	int gap = sz;//gapԽСԽ�ӽ�����
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)//ÿ��ͬʱ����
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
				max = i;//�ҵ�������
			if (arr[i] < arr[min])
				min = i;//�ҵ���С����
			i++;
		}
		Swap(&arr[left], &arr[min]);
		if (left == max)//�������ߵ���ǡ����󣬶�����ߵ�������һ�д����Ѿ����±�Ϊmin����������
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