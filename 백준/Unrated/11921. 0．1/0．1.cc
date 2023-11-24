#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char buffer[50000000];
    fread(buffer, sizeof(char), 50000000, stdin);
    int N = 0, i;
    long long sum = 0;
    for(i = 0; buffer[i] != '\n'; i++) N = N*10+buffer[i]-'0';
    for(int j = 0; j < N; j++) {
        int v = 0;
        for(i++; buffer[i] != '\n'; i++) {
            v = v*10+buffer[i]-'0';
        }
        sum += v;
    }
    
    cout << N << '\n' << sum << '\n';

    return 0;
}