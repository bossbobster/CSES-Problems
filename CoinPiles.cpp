#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
int main()
{
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b;
        if((a + b) % 3 == 0 && a * 2 >= b && b * 2 >= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
