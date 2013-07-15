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
        int b[3], b2[3];
        b[0] = b2[0] = _array[left], b[1] = b2[1] = _array[right];
        int mid = (left + right) >> 1;
        b[2] = b2[2] = _array[mid];
        sort(b, b + 3);
        int pos;
        if(b[1] == b2[0])   pos = left;
        else if(b[1] == b2[1])   pos = right;
        else   pos = mid;
        swap(_array[pos], _array[left]);
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
    /*cout << "After sorting:" << endl;
    for(int i = 0; i < n - 1; i ++)
        cout << a[i] << " ";
    cout << a[n-1] << endl;*/
    cout << "number of comparisons: " << num << endl;
}

