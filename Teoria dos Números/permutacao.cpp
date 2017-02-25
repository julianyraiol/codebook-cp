#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 20001
#define MOD 100000007

using namespace std;

/*  usa inverso modular para resolver permutação
	Embaralhando de novo
*/

typedef long long ll;

int freq[28];
ll fat[MAXN+1], x, y;

void init(){
	fat[0] = 1;
	for(int i = 1; i <= MAXN; i++)
		fat[i] = (fat[i-1]*i)%MOD;
}

void inverso(ll a, ll b){
	if(!b){
		x = 1; y = 0;
		return;
	}
	
	inverso(b, a%b);
	
	int x1 = y, y1 = x-(a/b)*y;
	
	x = x1, y = y1;
}

void frequencia(string s){
	for(int i = 0; i < s.size(); i++){
		freq[s[i] - 'a']++;
	}
}

ll calculo_permutacao(){
	ll fator = 1;
	for(int i = 0; i < 28; i++){
		if(freq[i] > 0){
			inverso( fat[freq[i]] , MOD);
			
			if(x < 0) x+= MOD;
			fator = ( fator * x)%MOD;
			x = 0;
		}
		freq[i] = 0;
	}
	return fator;
}

int main(){_
	string s;
	ll resp, fator;
	int n;
	init();
	while((cin >> s), s != "0"){
		n = fat[s.size()];
		frequencia(s);
		fator = calculo_permutacao();
		resp = (n*fator)%MOD;
		cout << resp << endl;
	}	
	return 0;
}
