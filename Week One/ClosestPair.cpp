#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double inf = 1e20;
struct point
{
    double x, y;
}x_axis[100010], y_axis[100010], tmpleft[100010];
int n;

inline bool cmp_x(point p1, point p2)
{
    return p1.x < p2.x;
}

inline bool cmp_y(point p1, point p2)
{
    return p1.y < p2.y;
}

inline double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

inline double ClosestPair(int left, int right)
{
    double res = inf;
    int len = right - left + 1;
    if(len == 2)
    {
        return dist(x_axis[left], x_axis[right]);
    }
    else if(len > 2)
    {
        int mid = (left + right) >> 1;
        res = min(ClosestPair(left, mid), ClosestPair(mid + 1, right));
        int cntr = 0, cntl = 0;
        for(int i = left; i <= mid; i ++)
        {
            if(x_axis[i].x >= x_axis[mid].x - res && x_axis[i].x <= x_axis[mid].x + res)
                tmpleft[cntl ++] = x_axis[i];
        }
        for(int i = mid + 1; i <= right; i ++)
        {
            if(x_axis[i].x >= x_axis[mid].x - res && x_axis[i].x <= x_axis[mid].x + res)
                y_axis[cntr ++] = x_axis[i];
        }
        sort(y_axis, y_axis + cntr, cmp_y);
        for(int i = 0; i < cntl; i ++)
        {
            for(int j = 0; j < cntr; j ++)
            {
                double tmpres = y_axis[j].y - tmpleft[i].y;
                if(tmpres >= res)
                    break;
                else if(fabs(tmpres) <= res)
                {
                    res = min(res, dist(tmpleft[i], y_axis[j]));
                }
            }
        }
    }
    return res;
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%lf%lf", &x_axis[i].x, &x_axis[i].y);
        }
        sort(x_axis, x_axis + n, cmp_x);
        printf("%.2lf\n", ClosestPair(0, n - 1) / 2);
    }
}
