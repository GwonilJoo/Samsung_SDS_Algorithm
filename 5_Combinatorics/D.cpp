// 1256 사전
/*


*/

#include<iostream>
#include<cstring>

using namespace std;

long long MAX = 1000000000;
long long D[201][201];
int N, M;
string str = "";

void pascal(){
  //cout << "N: " << N << ", M: " << M << endl;
  for(int i=0;i<=N+M;i++){
    D[i][0] = 1;
    for(int j=0;j<i;j++){
      D[i][j] = D[i-1][j-1] + D[i-1][j];
      D[i][j] = D[i][j] > MAX ? MAX : D[i][j]; // overflow 방지
    }
    D[i][i] = 1;
  }
 /* 
  cout << "pascal\n";
  for(int i=0;i<=N+M;i++){
    for(int j=0;j<=i;j++){
      cout << D[i][j] << " ";
    }
    cout << endl;
  }
  cout << "pascal end\n\n";
  */
}


void findAns(int n, int k, long long length){
  //cout << "n: " << n << ", k: " << k << ", length: " << length <<  ", D: " << D[n-1][k] << endl;
  if(n==0) return;
  if(k == 0){
    for(int i=0;i<n;i++){
      str += 'a';
    }
    return;
  }
  
  if(D[n-1][k] >= length){
    str += 'a';
    findAns(n-1, k, length);
  }
  else{
    str += 'z';
    findAns(n-1, k-1, length-D[n-1][k]);
  }
}

/*
// 재귀와 메모리제이션으로 comb 구하기

long long combination(int n, int r){
  if(n == r || r == 0)
    return 1;
  else if(D[n][r] != 0)
    return D[n][r];
  else
    return D[n][r] = min((long long)1e9, combination(n-1,r-1)+combination(n-1,r));
}
*/

int main(){
  long long K;
  
  cin >> N >> M >> K;
  
  //pascal();
  //cout << N+M << " " << M << " " << K << endl;
  
  if(K > D[N+M][M]){
    cout << -1 << "\n";
    return 0;
  }
  
  findAns(N+M, M, K);

  cout << str << "\n";
}
