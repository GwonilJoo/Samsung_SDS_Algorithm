// 2014 소수의 곱

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Heap{
  vector<int> tree;

public:
  Heap(){
    tree.push_back(0);
  }
  
  void push(int n){
    tree.push_back(n);
    
    int cur = tree.size()-1;
    while(cur/2){
      if(tree[cur] < tree[cur/2]){
        swap(tree[cur], tree[cur/2]);
        cur/=2;
      }
      else break;
    }
  }
  
  int pop(){
    int root = tree[1];
    tree[1] = tree[tree.size()-1];
    tree.pop_back();
    
    int cur = 1;
    while(cur <= (tree.size()-1)/2){
      if(tree[cur*2] < tree[cur*2+1]){
        if(tree[cur*2] < tree[cur]){
          swap(tree[cur], tree[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(tree[cur*2+1] < tree[cur]){
          swap(tree[cur], tree[cur*2+1]);
          cur = cur*2+1;
        }
        else break;
      }
    }
    
    return root;
  }
  
  int top(){
    return tree[1];
  }
  
  void show(){
    cout << "tree: ";
    for(int i=1;i<tree.size();i++)
      cout << tree[i] << " ";
    cout << endl;
  }
};

int K, N, *prime;
int root;

int main(){
  Heap heap;
  
  cin >> K >> N;
  
  prime = new int[K];
  
  for(int i=0;i<K;i++){
    cin >> prime[i];
    heap.push(prime[i]);
  }
  
  //heap.show();
  for(int i=1;i<=N;i++){
    root = heap.pop();
    //cout << i << "'s root: " << root << endl;
    //heap.show();
    for(int j=0;j<K;j++){
      long long tmp = (long long)root*prime[j];
      if(tmp < (long long)pow(2,31))
        heap.push((int)tmp);
    }
    while(root == heap.top()) // 중복 제거!
      heap.pop();
      
    //heap.show();
  }
  
  cout << root << "\n";
  
  delete [] prime;
}
