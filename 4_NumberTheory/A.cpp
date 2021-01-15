// 1735 분수 합

#include<iostream>
using namespace std;

long long gcd(long long a, long long b){
  while(b!=0){
    long long r = a%b;
    a = b;
    b = r;
  }
  
  return a;
}

int main(){
  long long A[3], B[3];
  cin >> A[1] >> B[1] >> A[2] >> B[2];
  //cout << A[1] << " " << B[1] << A[2] << " " << B[2] << endl;
  
  A[0] = A[1]*B[2] + A[2]*B[1];
  B[0] = B[1] * B[2];
  //cout << A[0] << " " << B[0] << endl;
  
  long long gcdAB = gcd(A[0], B[0]);
  //cout << gcdAB << endl;
  
  cout << A[0]/gcdAB << " " << B[0]/gcdAB << "\n";
}
