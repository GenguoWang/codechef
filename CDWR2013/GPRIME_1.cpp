#include <cstdlib>
#include <iostream>
 
using namespace std;
 
#define N 10000000
 
int prime[N+1];
int main(int argc, const char *argv[])
{
    unsigned long long *phi;
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= N; i++)
        prime[i] = 0;
    for(int i = 2; i + i <= N; i++)
        if(prime[i]==0&&i<=3163)
        {
            for(int j = i * i; j <= N; j += i)
            {
                prime[j] = i;
            }
        }
    phi = (unsigned long long*)malloc((N + 1) * sizeof(unsigned long long));
    int tmp;
    phi[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        if(prime[i]==0)
        {
            phi[i] = i-1;
            continue;
        }
        tmp = prime[i];
        if(i%tmp==0)
        {
            if(i/tmp % tmp==0)
            {
                phi[i] = tmp*phi[i/tmp];
            }
            else
            {
                phi[i] = (tmp-1)*phi[i/tmp];
            }
        }
    }
    unsigned long long *res=phi;
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
