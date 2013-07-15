#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int b[maxn];

void MergeSort(int _array[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) >> 1;
        MergeSort(_array, left, mid);
        MergeSort(_array, mid + 1, right);
        for(int i = left; i <= right; i ++)
            b[i] = _array[i];
        int li = left, ri = mid + 1;
        for(int i = left; i <= right; i ++)
        {
            if(li > mid)
            {
                _array[i] = b[ri];
                ri ++;
                continue;
            }
            if(ri > right)
            {
                _array[i] = b[li];
                li ++;
                continue;
            }
            if(b[li] <= b[ri])
            {
                _array[i] = b[li];
                li ++;
            }
            else
            {
                _array[i] = b[ri];
                ri ++;
            }
        }
    }
}

int main()
{
    int sample[11] = {10, 1, 2, 0, 5, 4, 3, 7, 8, 6, 9};
    int len = 11;
    MergeSort(sample, 0, len - 1);
    for(int i = 0; i < len; i ++)
    {
        cout << sample[i] << endl;
    }
}
