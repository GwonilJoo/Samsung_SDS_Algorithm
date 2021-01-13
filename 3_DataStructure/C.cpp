// 1991 트리 순회

#include<iostream>
using namespace std;

class Tree{
  char node[27];

public:
  Tree(){
    node[1] = 'A';
  }
  void push(char parent, char left, char right){
    node[(parent - 'A' + 1)*2] = left;
    node[(parent - 'A' + 1)*2+1] = right;
  }
  void preorder(int cur){
    if(cur > 26 || node[cur] == '.') return;
    
    cout << node[cur];
    preorder(node[cur*2] - 'A');
    preorder(node[cur*2+1] - 'A');
  }
};

int main(){
  int N;
  Tree tree;
  char parent, left, right;
  cin >> N;
  
  for(int i=0;i<N;i++){
    cin >> parent >> left >> right;
    tree.push(parent, left, right);
  }
  
  tree.preorder(1);
}
