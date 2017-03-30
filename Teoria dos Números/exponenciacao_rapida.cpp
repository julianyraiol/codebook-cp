#include <bits/stdc++.h>

using namespace std;

/*Exponenciação Rápida Modular*/

typedef long long int ll;

ll exp(ll b, ll e, ll m){
    ll x;
    if(e == 0) return 1;
    if(e == 1) return b;

    if(e%2) return (b*exp(b,e-1,m))%m;
    else{
        x = exp(b,e/2,m);
        return (x*x)%m;
    }
}

int main()
{
    ll b, p, m, r;

    while(cin >> b >> p >> m){
        r = exp(b, p, m);
        cout << r << endl;
    }
    return 0;
}
