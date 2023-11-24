#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    N = 10000;
    cout << N << '\n';
    long long sum = 0, v;
    for(int i = 1; i <= N; i++) {
        cin >> v; sum += v;
    }
    
    cout << sum;
    
    return 0;
}
