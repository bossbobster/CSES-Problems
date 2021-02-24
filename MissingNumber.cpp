#include <iostream>
using namespace std;
 
bool taken[200005];
int main()
{
    int n, k;
    cin >> n;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> k;
        taken[k] = true;
    }
    for(int i = 1; i <= n; i ++)
        if(!taken[i])
        {
            cout << i << endl;
            break;
        }
}
