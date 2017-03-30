
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100000
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll fat[MAXN], qnt_primos, x, y;
bitset<MAXN> ehprimo;
vi primos;

void init(){
  fat[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fat[i] = (fat[i-1]*i)%MOD;
   }
}

void crivo(int n){
  ehprimo.set();

  ehprimo[0] = ehprimo[1] = 0;
  for (int i = 2; i*i <= n; i++)
    if(ehprimo[i])
      for (int j = i*i; j <= n; j+=i) {
          ehprimo[j] = 0;
      }

  primos.push_back(2);
  for (int i = 3; i <= n; i++){
    if(ehprimo[i])
      primos.push_back(i);
  }
  qnt_primos = primos.size();
}

vi decomposicao(ll n){
  vi exp;
  exp.assign(qnt_primos, 0);
  for (int i = 0; primos[i] <= n && i < qnt_primos; i++) {
    for (int j = primos[i]; j<= n; j*=primos[i])
      exp[i]+= (n/j);
  }
  return exp;
}

ll exp(int b, int e, int m){

  int r;

  if(e == 0) return 1;
  if(e == 1) return 0;

  if(e%2) return (b*exp(b, e-1,m))%m;
  else{
    r = exp(b, e/2,m)%m;
    return (r*r)%m;
  }
}

void inverso(ll a, ll b){
  if(!b){
    x = 1; y = 0;
    return;
  }
  inverso(b, a%b);
  int xa = y, ya = x - (a/b)*y;
  x = xa, y = ya;
}

ll somaDiv(ll fat_n){
  ll pf_idx = 0, pf = primos[pf_idx], ans = 1;

  while(pf*pf <= fat_n){
    int power = 0;

    while (fat_n%pf == 0) { fat_n/=pf; power++;}
    inverso(pf-1 , MOD);

    if(x < 0) x+=MOD;
    ans*= ((ll)exp( (double)pf, power+1, MOD)-1)*x;
  }

  inverso(fat_n-1 , MOD);
  if(x < 0) x+=MOD;
  if(fat_n!=1) ans*= ((ll)exp( (double)fat_n, 2, MOD)-1)*x;

  return ans;
}

int main(){_
  ll n, fat_n, soma_fat;
  init();
  crivo(MAXN);

  while(cin >> n){
    fat_n = fat[n];

    soma_fat = somaDiv(fat_n);

    cout << fat[soma_fat] << " " << fat_n << endl;
  }

  return 0;
}
