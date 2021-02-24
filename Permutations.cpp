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
    int n;
    cin >> n;
    if(n == 1) { cout << "1\n"; return 0; }
    if(n < 4) { cout << "NO SOLUTION\n"; return 0; }
    for(int i = ((n % 2 + 1) % 2) + 1; i <= n; i += 2)
        cout << i << " ";
    for(int i = (n % 2 + 1); i <= n; i += 2)
        cout << i << " ";
    cout << "\n";
}
