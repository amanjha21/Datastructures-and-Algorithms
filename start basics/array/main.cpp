#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array
{
      int *A;
      int size;
      int length;
};

void display(struct Array arr)
{
      int i;
      printf("The Elements of Array are: \n");
      for (i = 0; i < arr.length; i++)
      {
            cout << arr.A[i] << endl;
      }
}

void initilize(struct Array *arr)
{
      cout << "Enter the size of array: " << endl;
      cin >> arr->size;
      arr->A = (int *)malloc(arr->size * sizeof(int));
      //arr->A = new int[arr->size];
      do
      {
            cout << "Enter the no. of elements: ";
            cin >> arr->length;

            if (arr->length > arr->size)
            {
                  cout << "number should be less than or equals to array size" << endl;
            }
      } while (arr->length > arr->size);

      cout << "Enter all the  elements" << endl;
      int i;
      for (i = 0; i < arr->length; i++)
      {
            scanf("%d", &arr->A[i]);
      }
}

void append(struct Array *arr, int element)
{
      if (arr->length >= arr->size)
      {
            cout << "The array is already full" << endl;
            return;
      }
      arr->A[arr->length] = element;
      arr->length++;
}

void Insert(struct Array *arr, int index, int element)
{
      if (index >= arr->length)
      {
            printf("Sorry cannot insert !!! \n");
            return;
      }
      int i;
      for (i = arr->length; i > index; i--)
      {
            arr->A[i] = arr->A[i - 1];
      }
      arr->A[index] = element;
      arr->length++;
}

void Delete(struct Array *arr, int index)
{
      if (index >= arr->length)
      {
            cout << "Sorry cannot delete!!! -- index doesn't exist " << endl;
            return;
      }
      int i;
      for (i = index; i < arr->length - 1; i++)
      {
            arr->A[i] = arr->A[i + 1];
      }
      arr->length--;
}

//simple linear search
int linearSearch(struct Array *arr, int element)
{
      int i;
      for (i = 0; i < arr->length; i++)
      {
            if (arr->A[i] == element)
                  return i;
      }
      return -1;
}

void Swap(int *x, int *y)
{
      int temp = *x;
      *x = *y;
      *y = temp;
}
//linear search with improvement
int linearSearch2(struct Array *arr, int element)
{
      int i;
      for (i = 0; i < arr->length; i++)
      {
            if (arr->A[i] == element)
            {
                  Swap(&arr->A[i], &arr->A[0]);
                  // Swap(&arr->A[i], &arr->A[i-1]);
                  return i;
            }
      }
      return -1;
}
int binarySearch(struct Array *arr, int element)
{
      int l, h, m;
      l = 0;
      h = arr->length - 1;

      while (l <= h)
      {
            m = (l + h) / 2;
            if (arr->A[m] == element)
            {
                  return m;
            }
            else if (arr->A[m] > element)
            {
                  h = m - 1;
            }
            else
            {
                  l = m + 1;
            }
      }
      return -1;
}

void reverse(struct Array *arr)
{
      int i, j;
      for (i = 0, j = arr->length - 1; i < j; i++, j--)
      {
            Swap(&arr->A[i], &arr->A[j]);
      }
      return;
}
void leftShift(struct Array *arr)
{
      int i;
      for (i = 0; i < arr->length; i++)
      {
            arr->A[i] = arr->A[i + 1];
      }
      arr->A[arr->length - 1] = 0;
      return;
}

void leftRotate(struct Array *arr)
{
      int i;
      int firstElement = arr->A[0];
      for (i = 0; i < arr->length; i++)
      {
            arr->A[i] = arr->A[i + 1];
      }
      arr->A[arr->length - 1] = firstElement;
      return;
}
void rightShift(struct Array *arr)
{
      int i;
      for (i = arr->length; i > 0; i--)
      {
            arr->A[i] = arr->A[i - 1];
      }
      arr->A[0] = 0;
      return;
}

void rightRotate(struct Array *arr)
{
      int i;
      int lastElement = arr->A[arr->length - 1];
      for (i = arr->length; i > 0; i--)
      {
            arr->A[i] = arr->A[i - 1];
      }
      arr->A[0] = lastElement;
      return;
}

void insertInSortedArray(struct Array *arr, int element)
{
      if (arr->size == arr->length)
      {
            printf("Sorry cannot insert !!! \n");
            return;
      }
      int i = arr->length - 1;
      // cout << "element: " << element << ", mm: " << arr->A[i - 1];
      while (element < arr->A[i])
      {
            arr->A[i + 1] = arr->A[i];
            i--;
      }
      arr->A[i + 1] = element;
      arr->length++;
}

bool checkSorted(struct Array *arr)
{
      int i;
      bool isSorted = true;
      for (i = 0; i < arr->length - 1; i++)
      {
            if (arr->A[i] > arr->A[i + 1])
                  isSorted = false;
      }
      return isSorted;
}
void arrangeNegativeFirst(struct Array *arr)
{
      int i = 0, j = arr->length - 1;
      while (j > i)
      {
            while (arr->A[i] < 0)
                  i++;
            while (arr->A[j] >= 0)
                  j--;
            if (i < j)
                  Swap(&arr->A[i], &arr->A[j]);
      }
}

void mergeArray(struct Array *a, struct Array *b, struct Array *c)
{
      // struct Array c;
      c->size = a->length + b->length;
      c->length = c->size;
      c->A = (int *)malloc(c->size * sizeof(struct Array));
      int i = 0, j = 0, k = 0;
      while (i < a->length && j < b->length)
      {
            if (a->A[i] <= b->A[j])
                  c->A[k++] = a->A[i++];
            else
                  c->A[k++] = b->A[j++];
      }
      for (; i < a->length; i++)
            c->A[k++] = a->A[i];
      for (; j < b->length; j++)
            c->A[k++] = b->A[j];
      return;
}
int main()
{
      struct Array a;
      initilize(&a);
      struct Array b;
      initilize(&b);
      cout << "a: ";
      display(a);
      cout << "b: ";
      display(b);
      //append(&a, 23);
      //display(a);
      //Insert(&a,4,24);
      //Delete(&a, 2);
      // cout << "linear search status: " << linearSearch(&a, 3) << endl;
      // cout << "binary search status: " << binarySearch(&a, 3) << endl;
      // reverse(&a);
      //rightShift(&a);
      //leftShift(&a);
      //rightRotate(&a);
      //leftRotate(&a);
      // insertInSortedArray(&a, 5);
      // cout << "isSorted: " << checkSorted(&a) << endl;
      // arrangeNegativeFirst(&a);
      struct Array c;
      mergeArray(&a, &b, &c);
      display(c);

      return 0;
}
