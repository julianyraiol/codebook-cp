#include <iostream>
using namespace std;

int mdc(int a, int b){
    int aux;
    
    while(b){
        aux = b;
        b = a%b;
        a = aux;
    }

    return a;
}


int main(){
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << mdc(a, b) << endl;
    }
    return 0;
}
