// 2143 두 배열의 합

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
long long T, A[1000], B[1000];
vector<long long> As, Bs;

void init(){
  cin >> T >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> B[i];
  }
  
  for(int i=0;i<n;i++){
    long long sum = 0;
    for(int j=i;j<n;j++){
      sum += A[j];
      As.push_back(sum);
    }
  }
  
  for(int i=0;i<m;i++){
    long long sum = 0;
    for(int j=i;j<m;j++){
      sum += B[j];
      Bs.push_back(sum);
    }
  }
  
  sort(As.begin(), As.end());
  sort(Bs.begin(), Bs.end());

}

void solution(){
  long long A_pointer = 0, B_pointer = Bs.size()-1;
  long long sum = 0, ans = 0;
  
  while(A_pointer < As.size() && B_pointer >= 0){
    sum = As[A_pointer] + Bs[B_pointer];
    
    //cout << "A pointer: " << A_pointer << ", B pointer: " << B_pointer << ", sum: " << sum << endl;
    
    if(sum < T){
      A_pointer++;
    }
    else if(sum > T){
      B_pointer--;
    }
    else{
      long long tmp_A = A_pointer, tmp_B = B_pointer;
      while(tmp_A < As.size() && As[tmp_A] == As[A_pointer]) tmp_A++;
      while(tmp_B >= 0 && Bs[tmp_B] == Bs[B_pointer]) tmp_B--;
      
      ans += (tmp_A - A_pointer) * (B_pointer - tmp_B);
      
      A_pointer = tmp_A;
      B_pointer = tmp_B;
    }
  }
  
  cout << ans << endl;
}

int main(){
  init();
  solution();
}
