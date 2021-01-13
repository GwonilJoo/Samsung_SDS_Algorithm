// 2042 구간 합 구하기
// index tree 이용

#include<iostream>
using namespace std;

int N, M, K;
int c, p1,p2;
long long nums[];
long long tree[];
int S; // 리프 노드의 수 : 2^D

void makeTree();
long long query(int node, int left, int right, int qLeft, int qRight);
void update(int node, int left, int right, int index, long long diff);
void show();

int main(){
  cin >> N;
  
  nums = new long long[N+1];
  for(int i=1;i<=N;i++){
    cin >> nums[i]; 
  }
  for(int i=1;i<=N;i++){
    cout << "nums: " << nums[i] << ", "; 
  }
  cout << "\n";
  
  S = 1;
  while(S<N){
    S *= 2;
  }
  tree = new long long[2*S];
  
  makeTree(1,1,S);
  
}

void makeTree(){
  for(int i=0;i<N;i++){
    tree[S+i] = nums[i+1];
  }
  for(int i=S-1;i>0;i--){
    tree[i] = tree[i*2] + tree[i*2-1];
  }
}

long long query(int left, int right){
  if(qRight < left || right < qLeft){
    return 0;
  }
  else if(qLeft <= left && right <= qRight){
    return tree[node];
  }
  else{
    int mid = (left+right)/2;
    return query(node*2, left ,mid, qLeft, qRight); + query(node*2+1, mid+1, right, qLeft, qRight);
  }
}

void update(int node, int left, int right, int index, long long diff){
  if(left <= index && index <= right){
    tree[node] += diff;
    if(left != right){
      int mid = (left+right)/2;
      update(node*2, left, mid ,index, diff);
      update(node*2+1, mid+1, right, index, diff);
    }
  }
}

void show(){
  for(int i=1;i<2*S;i++){
    cout << "tree: " << 
  }
}
