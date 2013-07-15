#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn], b[maxn];

long long Inversion(int _array[], int left, int right)
{
    long long res = 0;
    if(left < right)
    {
        int mid = (left + right) >> 1;
        res += Inversion(_array, left, mid);
        res += Inversion(_array, mid + 1, right);
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
                res += (mid - li + 1);
                _array[i] = b[ri];
                ri ++;
            }
        }
    }
    return res;
}

int main()
{
    freopen("IntegerArray.txt", "r", stdin);
    for(int i = 0; i < 100000; i ++)
        cin >> a[i];
    cout << Inversion(a, 0, 99999) << endl;
    /*for(int i = 0; i < len; i ++)
    {
        cout << sample[i] << endl;
    }*/
}

