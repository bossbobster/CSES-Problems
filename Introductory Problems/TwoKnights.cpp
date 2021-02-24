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
    long long n;
    cin >> n;
    cout << "0" << "\n";
    if(n == 1) return 0;
    for(long long i = 2; i <= n; i ++)
        cout << (i * i * (i * i - 1) / 2) - (4 * (i - 1) * (i - 2)) << "\n";
}
