#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;

int a[100010];
int n;

void QuickSort(int _array[], int left, int right)
{
    if(left < right)
    {
        srand((unsigned) time(NULL));
        int rand_pos = rand() % (right - left + 1) + left;
        swap(_array[rand_pos], _array[left]);
        int pivot = _array[left], swap_pos = left;
        for(int i = left; i <= right; i ++)
        {
            if(_array[i] < pivot)
            {
                swap_pos ++;
                swap(_array[i], _array[swap_pos]);
            }
        }
        swap(_array[swap_pos], _array[left]);
        QuickSort(_array, left, swap_pos - 1);
        QuickSort(_array, swap_pos + 1, right);
    }
}

int main()
{
    freopen("IntegerArray2.txt", "r", stdin);
    while(cin >> n)
    {
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        QuickSort(a, 0, n - 1);
        cout << "After sorting:" << endl;
        for(int i = 0; i < n - 1; i ++)
            cout << a[i] << " ";
        cout << a[n-1] << endl;
    }
}

