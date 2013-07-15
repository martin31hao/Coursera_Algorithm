#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[100010];
long long num;

void QuickSort(int _array[], int left, int right)
{
    if(left < right)
    {
        swap(_array[left], _array[right]);
        int pivot = _array[left], swap_pos = left;
        for(int i = left; i <= right; i ++)
        {
            if(_array[i] < pivot)
            {
                swap_pos ++;
                swap(_array[i], _array[swap_pos]);
            }
        }
        num += right - left;
        swap(_array[swap_pos], _array[left]);
        QuickSort(_array, left, swap_pos - 1);
        QuickSort(_array, swap_pos + 1, right);
    }
}

int main()
{
    freopen("QuickSortText.txt", "r", stdin);
    int n = 10000;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    num = 0;
    QuickSort(a, 0, n - 1);
    cout << "number of comparisons: " << num << endl;
}

