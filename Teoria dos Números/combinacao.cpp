#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 2000000
#define MOD 1300031

using namespace std;

/*  usa inverso modular para resolver combinação
	Equações diofantinas
*/

typedef long long ll;

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

int main(){_
	
	ll resp, inverso1, inverso2;
	int t, n, c;
	
	cin >> t;
	init();
	while(t--){
		cin >> n >> c;
		
		inverso(fat[n-1], MOD);
		inverso1 = x;
		
		if(inverso1 < 0) inverso1+=MOD; 
		
		inverso(fat[c], MOD);
		inverso2 = x;
		if(inverso2 < 0) inverso2+=MOD; 
		
		resp = (fat[n + c - 1]*(inverso1* inverso2)%MOD)%MOD;
		cout << resp << endl;
	}
	return 0;
}
