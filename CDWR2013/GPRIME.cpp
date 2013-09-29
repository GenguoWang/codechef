#include <cstdlib>
#include <iostream>
 
using namespace std;
 
#define N 10000000
 
int main(int argc, const char *argv[])
{
    int *phi;
    char *prime;
    prime = (int*)malloc((N + 1) * sizeof(char));
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= N; i++)
        prime[i] = 1;
    for(unsigned long long i = 2; i + i <= N; i++)
        if(prime[i])
            for(unsigned long long j = i * i; j <= N; j += i)
                prime[j] = 0;
    phi = (int*)malloc((N + 1) * sizeof(int));
    for(int i = 1; i <= N; i++)
        phi[i] = i;
    for(int i = 2; i <= N; i++)
        if(prime[i])
            for(int j = i; j <= N; j += i)
                phi[j] = phi[j] / i * (i - 1); 
    unsigned long long *res;
    res = (unsigned long long *)malloc(N*sizeof(unsigned long long));
    res[0] = 0;
    res[1] = 3;
    for(int i=2;i<N;++i)
    {
        res[i] = 2*phi[i]+res[i-1];
    }
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << res[n-1] << '\n';
    }
    return 0;
}
