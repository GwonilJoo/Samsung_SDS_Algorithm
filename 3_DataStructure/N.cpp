// 2243 사탕상자

/*

세그먼트 트리
query를 다르게 하는게 핵심!
왼쪽 자식 노드가 rank 이상 가지고 있으면 왼쪽 자식 노드 탐색
아니면 오른쪽 자식 노드 탐색 이때 rank -= tree[node*2]

리프의 인덱스가 사탕의 맛
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll *tree;
ll S = 1;

void init(){
  ll size = 1e6;
  while(S < size) S*=2;
  
  tree = new ll[2*S];
  for(ll i=0;i<2*S;i++) tree[i] = 0;
}

ll query(int node, int left, int right, int rank){
  if((left == right)){
    return left;
  }
  
  int mid = (left+right)/2; 
  if((node*2 <= 2*S && tree[node*2] >= rank)){ // 왼쪽 자식 노드가 rank 이상 가지고 있으면 탐색
    return query(node*2, left, mid, rank);
  }
  if(node*2+1 <= 2*S && tree[node*2+1] >= rank-tree[node*2]){
    return query(node*2+1, mid+1, right, rank-tree[node*2]);
  }
}

void update(int node, int left, int right, int index, ll diff){
  if(left <= index && index <= right){
    tree[node] += diff;
    if(left != right){
      int mid = (left+right)/2;
      update(node*2, left, mid, index, diff);
      update(node*2+1, mid+1, right, index, diff);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, a, b;
  ll c;
  
  cin >> n;
  init();
  for(int i=0;i<n;i++){
    cin >> a;
    if(a == 1){
      cin >> b;
      //cout << "a: " << a << ", b: " << b << endl;
      ll idx = query(1,1,S,b);
      cout << idx << "\n";
      update(1,1,S,idx,-1);
    }
    else{
      cin >> b >> c;
      //cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
      update(1,1,S,b,c);
    }
  }
}
