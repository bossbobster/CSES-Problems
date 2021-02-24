#include <iostream>
using namespace std;
 
int arr[1000000];
int main()
{
    long long n, cur = 0;
    cin >> n;
    cin >> arr[0];
    for(int i = 1; i < n; i ++)
    {
        cin >> arr[i];
        if(arr[i] < arr[i - 1])
        {
            cur += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    cout << cur << endl;
}
