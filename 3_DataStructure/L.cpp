// 1655 가운데를 말해요

/*

https://yabmoons.tistory.com/478

문제풀이
1. 최대힙의 크기는 항상 최소힙의 크기와 같거나 1만큼 더 크다
2. 최소힙의 모든 원소는 최대힙의 모든 원소보다 항상 크거나 같아야 한다.
   즉, 최소힙의 top은 최대힙의 top 보다 크거나 같아야 한다.
3. 매 iteration마다의 최대힙의 top이 중간값이다.

*/


#include<iostream>
using namespace std;

class MaxHeap{
  int tree[100010];
  int numOfNode;
public:
  MaxHeap() {numOfNode=0;}
  
  void push(int value){
    int cur=numOfNode+1;
    tree[cur] = value;
    numOfNode++;
            
    while(cur/2){
      if(tree[cur/2] < tree[cur]){
        swap(tree[cur/2], tree[cur]);
        cur /= 2;
      }
      else break;
    }
  }
  
  int pop(){
    int root = tree[1];
    
    tree[1] = tree[numOfNode];
    numOfNode--;
    
    int cur = 1;
    while(cur <= numOfNode/2){
      if(tree[cur*2] > tree[cur*2+1]){
        if(tree[cur] < tree[cur*2]){
          swap(tree[cur], tree[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(tree[cur] < tree[cur*2+1]){
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
  
  int size(){
    return numOfNode;
  }
  
  bool empty(){
    return numOfNode == 0;
  }
  
  void show(){
    cout << "MaxHeap: ";
    for(int i=1;i<=numOfNode;i++)
      cout << tree[i] << " ";
    cout << endl;
  }
};

class MinHeap{
  int tree[100010];
  int numOfNode;
public:
  MinHeap() {numOfNode=0;}
  
  void push(int value){
    int cur=numOfNode+1;
    tree[cur] = value;
    numOfNode++;
            
    while(cur/2){
      if(tree[cur/2] > tree[cur]){
        swap(tree[cur/2], tree[cur]);
        cur /= 2;
      }
      else break;
    }
  }
  
  int pop(){
    int root = tree[1];
    
    tree[1] = tree[numOfNode];
    numOfNode--;
    
    int cur = 1;
    while(cur <= numOfNode/2){
      if(tree[cur*2] < tree[cur*2+1]){
        if(tree[cur] > tree[cur*2]){
          swap(tree[cur], tree[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(tree[cur] > tree[cur*2+1]){
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
  
  int size(){
    return numOfNode;
  }
  
  bool empty(){
    return numOfNode == 0;
  }
  
  void show(){
    cout << "MinHeap: ";
    for(int i=1;i<=numOfNode;i++)
      cout << tree[i] << " ";
    cout << endl;
  }
};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  MaxHeap MaxH;
  MinHeap MinH;
  
  int N, n;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> n;
    
    if(MaxH.size() <= MinH.size()) 
      MaxH.push(n);
    else
      MinH.push(n);
      
    if(!MaxH.empty() && !MinH.empty() && MaxH.top() > MinH.top()){
      int max_value = MaxH.pop();
      int min_value = MinH.pop();
      
      MaxH.push(min_value);
      MinH.push(max_value);
    }
      
    //MaxH.show();
    //MinH.show();
    //cout << endl;
    
    cout << MaxH.top() << "\n";
  }
}
