#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;
 
struct Node{
    struct Node* children[ALPHABET_SIZE];
    char caracter;
    bool finalized;
    int numbers;

    Node(){
        memset(children, false, sizeof(children));
        finalized = false;
        numbers = 0;
    }
};

void insert(Node *root, string word){
    
    int index;
    for(char letter:word){
        index = letter-'a';
        
        if(!root->children[index]){
            root->children[index] = new Node();
            root->children[index]->caracter = letter;
        }
        root = root->children[index];
        root->numbers++;
    }
    root->finalized = true;
}

bool check_sets(Node* root){
    for (Node* child:root->children){ 
        if (child){ 
            if(child->numbers > 1)
                return false;
        } 
    } 
    return true;
}

int main(){
    int n, m;
    Node* root;
    string operation, word, str;

    while((cin >> n) && n){
        root = new Node();
        while(n--){
            cin >>word;
            insert(root, word);
        }
        cout << (check_sets(root)? "Conjunto Bom" : "Conjunto Ruim") << endl;
        delete(root);
    }
}
