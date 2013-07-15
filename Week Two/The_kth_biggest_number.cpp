#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;

int a[100010];
int n, kth, kth_number;

void kthNumber(int _array[], int left, int right, int k)
{
    if(left < right)
    {
        srand((unsigned) time(NULL));
        int rand_pos = rand() % (right - left + 1) + left;
        swap(_array[rand_pos], _array[left]);
        int pivot = _array[left], swap_pos = left;
        for(int i = left; i <= right; i ++)
        {
            if(_array[i] > pivot)
            {
                swap_pos ++;
                swap(_array[i], _array[swap_pos]);
            }
        }
        swap(_array[swap_pos], _array[left]);
        if(swap_pos > k)    kthNumber(_array, left, swap_pos - 1, k);
        else if(swap_pos < k)   kthNumber(_array, swap_pos + 1, right, k);
        else    kth_number = _array[swap_pos];
    }
    else if(left == right && left == k)
        kth_number = _array[left];
}

int main()
{
    freopen("IntegerArray2.txt", "r", stdin);
    while(cin >> n >> kth)
    {
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        kthNumber(a, 0, n - 1, kth);
        cout << "The " << kth << "th biggest number is " << kth_number << endl;
    }
}


