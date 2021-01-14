// 1991 트리 순회

#include<iostream>
#include<string>
using namespace std;

class Tree{
  int node[26][2]; // left right
public:
  Tree(){
    pos[0] = 1;
    node[1] = 'A';
    for(int i=2;i<=26;i++){
      node[i] = '.';
    }
  }
  void push(char parent, char left, char right){
    pos[left-'A'] = pos[parent-'A'] * 2;
    pos[right-'A'] = pos[parent-'A'] * 2 + 1;
    
    node[pos[left -'A']] = left;
    node[pos[right-'A']] = right;
  }
  void show(){
    cout << "Tree: ";
    for(int i=1;i<=26;i++){
      cout << node[i] << " ";
    }
    cout << "\n";
  }
  void preorder(int cur){
    if(cur > 26 || node[cur] == '.') return;
    
    cout << node[cur];
    preorder(cur*2);
    preorder(cur*2+1);
  }
  void inorder(int cur){
    if(cur > 26 || node[cur] == '.') return;
    
    inorder(cur*2);
    cout << node[cur];
    inorder(cur*2+1);
  }
  void postorder(int cur){
    if(cur > 26 || node[cur] == '.') return;
    
    postorder(cur*2);
    postorder(cur*2+1);
    cout << node[cur];
  }
};

int main(){
  int N;
  Tree tree;
  char parent, left, right;
  cin >> N;
  
  for(int i=0;i<N;i++){
    scanf(" %c %c %c", &parent, &left, &right);
    //tree.push(s[0], s[2], s[4]);
    tree.push(parent, left, right);
  }
  
  //tree.show();
  
  tree.preorder(1); cout << "\n";
  tree.inorder(1); cout << "\n";
  tree.postorder(1); cout << "\n";
}
