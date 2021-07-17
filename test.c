#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//int* arr[10] = { 0 };
//	//int* (*pa)[10] = &arr;
//	int (*pAdd)(int, int) = Add;
//	int sum = (*pAdd)(1, 2);
//	printf("sum = %d\n", sum);
//	return 0;
//}

struct Stu
{
	char name[20];
	int age;
};

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

//void test1()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;
	return ((int)(*(float*)e1 - *(float*)e2));
}

//void test2()
//{
//	float f[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//}


int cmp_stu_by_age(const void* e1, const void* e2)
{
	return((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
    //cmp_stu_by_name
int cmp_stu_by_name(const void* e1, const void* e2)
{ 
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

//void test3()
//{
//	struct Stu s[3] = { {"zhangsan",20},{"lise",30},{"wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//} 

//void qsort (void* base,
//			size_t num,
//			size_t width,
//			int( *cmp)(const void* s1, const void* e2)
//			);	

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf2;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void test4()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}


void test5()
{
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
    //	bubble_sort(arr, sz);

    //	bubble_sort(f, sz);
	return 0;
}

