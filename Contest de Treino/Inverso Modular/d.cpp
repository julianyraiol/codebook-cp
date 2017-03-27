#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 2001
#define MOD 1300031

using namespace std;

typedef long long ll;

ll fat[MAXN], freq[28];
int x, y;

void init(){
  fat[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fat[i] = (fat[i-1]*i)%MOD;
}

void inverso(ll a, ll b){
  if(!b){
    x = 1; y = 0;
    return;
  }
  inverso(b, a%b);
  int x1 = y, y1 = x - (a/b)*y;
  x = x1; y = y1;
}

int main(){_
  string entrada;
  ll resp, n;
  init();
  while (cin >> entrada) {

    n = fat[entrada.size()];

    resp = n * (inverso()) %MOD;
    cout << resp << endl;

  }
  return 0;
}
