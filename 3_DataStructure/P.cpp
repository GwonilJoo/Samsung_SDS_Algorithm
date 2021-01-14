// 1275 커피숍2

#include<iostream>
using namespace std;

int N, Q;
long long *nums;
long long *tree;
long long S;

long long makeTree(int node, int left, int right);
long long query(int node, int left, int right, int qLeft, int qRight);
void update(int node, int left, int right, int index, long long diff);

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  cin >> N >> Q;
  nums = new long long[N+1];
  for(int i=1;i<=N;i++){
    cin >> nums[i];
  }
  
  S = 1;
  while(S<N) S*=2;
  tree = new long long[2*S];
  
  makeTree(1,1,S);
 /* 
  cout << "\nTree: ";
  for(int i=1;i<2*S;i++)
    cout << tree[i] << " ";
  cout << endl;
  */
  long long x,y,a,b;
  for(int i=0;i<Q;i++){
    cin >> x >> y >> a >> b;
    
    if(x<=y) cout << query(1,1,S,x,y) << "\n";
    else cout << query(1,1,S,y,x) << "\n";
    
    update(1,1,S,a,b-nums[a]);
    nums[a] = b;
    //tree[S+a] = b;
  }
  
  delete [] nums;
  delete [] tree;
}

long long makeTree(int node, int left, int right){
  if(left == right){
    if(left <= N)
      return tree[node] = nums[left];
    else{
      return tree[node] = 0;
    }
  }
  
  int mid = (left+right)/2;
  return tree[node] = makeTree(node*2, left, mid) + makeTree(node*2+1, mid+1, right);
}


long long query(int node, int left, int right, int qLeft, int qRight){
  if(right < qLeft || left > qRight)
    return 0;
  else if(qLeft <= left && right <= qRight)
    return tree[node];
  else{
    int mid = (left+right)/2;
    return query(node*2, left, mid, qLeft, qRight) + query(node*2+1, mid+1, right, qLeft, qRight);
  }
}

void update(int node, int left, int right, int index, long long diff){
  if(left <= index && index <= right){
    tree[node] += diff;
    if(left != right){
      int mid = (left+right)/2;
      update(node*2, left, mid, index, diff);
      update(node*2+1, mid+1, right, index, diff);
    }
  }
}
