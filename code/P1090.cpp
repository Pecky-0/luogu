#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

const int maxn = 1e4 + 10;

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;

        pq.push(data);
    }

    int ans = 0;

    while(1)
    {
        int x = pq.top();
        pq.pop();
        if(pq.empty())
        {
            break;
        }
        int y = pq.top();
        pq.pop();

        ans += x + y;
        pq.push(x + y);
    }

    cout << ans << endl;

    system("pause");
    return 0;
}