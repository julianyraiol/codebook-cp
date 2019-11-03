#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

int cont; 
struct Node{
    struct Node* children[ALPHABET_SIZE];
    bool finalized;
};

Node* init(){
    Node* root = new Node();
    for(int i = 0; i < ALPHABET_SIZE; i++)
        root->children[i] = NULL;
        
    root->finalized = false;
    return root;
}

void insert(Node *root, string word){
    
    int letter;
    for(int i = 0; i < word.size(); i++){
        letter = word[i]-'a';
        
        if(root->children[letter] == NULL){
            root->children[letter] = init();
        }
        root = root->children[letter];
    }
    root->finalized = true;
}

void print(Node* root, string str) 
{ 
    if (root->finalized != false)  
    { 
        cout << str << endl; 
    } 

    for (int i = 0; i < ALPHABET_SIZE; i++)  
    { 
        if (root->children[i])  
        { 
            str.push_back(i + 'a'); 
            print(root->children[i], str); 
            str.pop_back();
        } 
    } 
} 

bool search(Node* root, string word){

    Node *aux_root = root;
    for(int i = 0; i < word.length(); i++){
        int letter = word[i] - 'a';
        if(!aux_root->children[letter]){ 
            return 0;
        }
           
        aux_root = aux_root->children[letter];
    }

    cout << ("======") << endl;

    if (aux_root != NULL && aux_root->finalized){
        print(aux_root, word);
    }
    return (aux_root != NULL && aux_root->finalized);
}


int main(){
    Node* root = init();
    string str;
    
    insert(root, "ac");
    insert(root, "accc");
    insert(root, "acccd");
    insert(root, "abb");
    insert(root, "cbb");
    insert(root, "cbbdd");
    insert(root, "abbccc");
    print(root, str);
    cout << search(root, "ac") << endl;
    
}