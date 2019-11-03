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

int print_by_prefix(Node* root, string word){
    int index, cont = 0;
    for(char letter:word){
        index = letter - 'a';
        if(!root->children[index]){
            return 0;
        }
        root = root->children[index];
    }
    return root->numbers;
}

int main(){
    int n, cont = 0;
    Node* root = new Node();
    string operation, word, str;

    cin >> n;
    while(n--){
        cin >> operation >>  word;
        if(operation == "add")
            insert(root, word);
        else
            cout << print_by_prefix(root, word) << endl;
    }
}
