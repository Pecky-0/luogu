#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int last = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        if(data > last)
        {
            ans += data - last;
        }
        last = data;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}