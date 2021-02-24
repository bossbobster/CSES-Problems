#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
int main()
{
    int t;
    unsigned long long x, y;
    cin >> t;
    while(t --)
    {
        cin >> y >> x;
        if(y < x)
        {
            if(x % 2 == 0)
                cout << (x * x - x + 1) - (x - y) << "\n";
            else
                cout << (x * x - x + 1) + (x - y) << "\n";
        }
        else if(x < y)
        {
            if(y % 2 == 0)
                cout << (y * y - y + 1) + (y - x) << "\n";
            else
                cout << (y * y - y + 1) - (y - x) << "\n";
        }
        else
            cout << (x * x - x + 1) << "\n";
    }
}
