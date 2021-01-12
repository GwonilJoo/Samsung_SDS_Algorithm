// 2003 수들의 합 2

// 일반적으로 이중 for문으로 사용하면 시간복잡도는 O(N^2) 이다. 
// 투 포인터를 사용하면 시간복잡도를 2N = O(N) 으로 할 수 있다.

#include<iostream>
using namespace std;

int N;
long long M, A[10000];
int ans = 0;

void init(){
  cin >> N >> M;
  for(int i=0;i<N;i++)
    cin >> A[i];
}

void func(){
  int start = 0, end = 0;
  int sum = A[0];
  while(start < N && end <N){
    if(sum < M){
      sum += A[++end];
    }
    else if(sum == M){
      ans++;
      sum -= A[start++];
      sum += A[++end];
    }
    else{
      sum -= A[start++];
    }
  }
}

int main(){
  init();
  func();
  cout << ans << endl;
}
