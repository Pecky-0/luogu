#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 30;

int data[maxn];

bool cmp(int a, int b)
{
    int lenA = 0;
    int lenB = 0;
    int tempA = a;
    int tempB = b;
    while(tempA > 0)
    {
        tempA /= 10;
        lenA++;
    }
    while(tempB > 0)
    {
        tempB /= 10;
        lenB++;
    }
    long long A = a * pow(10, lenB) + b;
    long long B = b * pow(10, lenA) + a;
    return A > B;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &data[i]);
    }
    sort(data, data + n, cmp);
    for(int i = 0; i < n; ++i)
    {
        printf("%d", data[i]);
    }

    system("pause");

    return 0;
}