#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10001
#define MOD (int)1e9

using namespace std;

typedef long long ll;

ll fat[MAXN], freq[27];
int x, y;

void init(){
  fat[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fat[i] = (fat[i-1]*i)%MOD;
}

void inverso(int a, int b){
  if(!b){
    x = 1;
    y = 0;
  }
  inverso(b, a%b);
  int x1 = y, y1 = x - (a/b)*y;
  x = x1; y = y1;
}

void frequencia(string s){
  for (int i = 0;  i < s.size(); i++)
    freq[s[i]-'A']++;
}

ll permuta(){
  ll resp = 1;
  for (int i = 0; i< 27; i++) {
    if(freq[i] > 0){
      inverso(fat[freq[i]], MOD);

      if(x > 0) x+=MOD;

      resp = (resp*x)%MOD;
    }

    freq[i] = 0;
  }
  return resp;
}

int main(){
  string entrada;
  ll resp, n;
  while (cin >> entrada, entrada != "0") {
    frequencia(entrada);
    n = entrada.size();
    resp = (permuta()*n)%MOD;
    cout << resp << endl;

  }
  return 0;
}
