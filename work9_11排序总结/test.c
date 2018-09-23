#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>
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

int GetMid(int *arr,int left, int right)//����ȡ��
{
	assert(arr);
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[right])
	{
		if (arr[right] < arr[mid])
			return right;
		else if (arr[left] > arr[mid])
			return left;
		else
			return mid;
	}
	else//right<left
	{
		if (arr[left] < arr[mid])
			return left;
		else if (arr[right] > arr[mid])
			return right;
		else
			return mid;
	}
}
int Quick_Sort(int* arr, int left,int right)//����ָ�뷨
{
	assert(arr);
	int mid = GetMid(arr, left, right);
	Swap(&arr[mid], &arr[right]);
	int key = right;
	while (left < right)
	{
		while ((left < right)&&(arr[left] <= arr[key]))
		{
			++left;
		}
		while ((left < right)&&(arr[right] >= arr[key]))
		{
			--right;
		}
		Swap(&arr[left], &arr[right]);
		//key = right;
	}
	Swap(&arr[right], &arr[key]);
	return right;
}
int Quick_Sort2(int *arr, int left, int right)//�ڿ�����
{
	assert(arr);
	int mid = GetMid(arr, left, right);
	Swap(&arr[mid], &arr[right]);
	int keyindex = right;
	int tmp = arr[keyindex];
	while (left < right)
	{
		while ((left < right) && (arr[left] <= tmp))
		{
			left++;
		}
		arr[right] = arr[left];
		while ((left < right) && (arr[right] >= tmp))
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[right] = tmp;
	return right;
}
int Quick_Sort3(int *arr, int left, int right)//ǰ��ָ�뷨
{
	assert(arr);
	int cur = left;
	int prev = cur - 1;
	int key = arr[right];
	int keyindex = right;
	while (cur < right)
	{
		if (arr[cur] < key && (++prev != cur))
			Swap(&arr[cur], &arr[prev]);
		++cur;
	}
	Swap(&arr[++prev], &arr[keyindex]);
	return prev;
}
void QuickSort(int *arr, int left, int right)
{
	assert(arr);
	if (left > right)
		return;
	int div = Quick_Sort3(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div+1, right);
	printf("Quick_Sort:");
	Print(arr, right+1);
}

void AdjustDown(int* arr, int n, int root)
{
	assert(arr);
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if ((child + 1<n) && (arr[child + 1] > arr[child]))
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void Heap_Sort(int *arr, int left, int sz)
{
	assert(arr);
	int i = 0;
	int end = sz-1;
	for (i = (sz - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, sz, i);
	}
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);//������������������棬����δ�����ٷŵ������棬�������ٽ���
		end--;
	}
	printf("Heap_Sort:");
	Print(arr, sz);
}
void Merge(int* arr, int left1, int right1, int left2, int right2, int* tmp)
{
	int index, start,n;
	assert(arr);
	index = left1;
	start = left1;
	n = right2 - left1 + 1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (arr[left1] < arr[left2])
		{
			//tmp[index++] = arr[left2++];//����
			tmp[index++] = arr[left1++];//����
		}
		else
		{
			//tmp[index++] = arr[left1++];//����
			tmp[index++] = arr[left2++];//����
		}
	}
	while (left1 <= right1)
		tmp[index++] = arr[left1++];
	while (left2 <= right2)
		tmp[index++] = arr[left2++];
	memcpy(arr + start, tmp + start, sizeof(int)*n);
}
void _MergeSort(int* arr,int left, int right,int* tmp)
{
	assert(arr);
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	//[left,mid][mid+1,right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	Merge(arr, left, mid, mid + 1, right, tmp);

}
void Merge_Sort(int* arr, int sz)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*sz);
	_MergeSort(arr,0,sz-1,tmp);
	printf("Merge_Sort:");
	Print(arr, sz);
	free(tmp);
}
int main()
{
	int arr[] = { 1,9,4,5,2,8,0,7,3,56};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Insertion_Sort(arr, sz);
	//Shell_Sort(arr, sz);
	//Select_Sort(arr, sz);
	//Bubble_Sort(arr,sz);
	//Heap_Sort(arr, 0, sz);
	//QuickSort(arr, 0, sz - 1);
	Merge_Sort(arr, sz - 1);
	
	system("pause");
	return 0;
}