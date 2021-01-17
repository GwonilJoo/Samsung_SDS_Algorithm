// 5639 이진 검색 트리

#include<iostream>
#include<vector>
using namespace std;

int tree[10000];
int size = 0;

void make_tree(){
  int value;
  
  while(true){
    cout << scanf("%d", &value) << endl;
    tree[size] = value;
    size++;
  }
}

void show(){
  cout << "tree: ";
  for(int i=0;i<size;i++)
    cout << tree[i] << " ";
  cout << endl;
}

int main(){
  make_tree();
  show();
}
