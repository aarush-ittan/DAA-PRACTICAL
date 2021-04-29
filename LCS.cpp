#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct cell{
 char c;
 int n;
};
int main(){
 string a, b;
 cout<<"\n Enter 1st string :";
 cin>>a;
 cout<<"\n Enter 2nd string :";
 cin>>b;
 struct cell tbl[a.size()+1][b.size()+1];
 for(int i=0; i<=a.size(); i++){
 for(int j=0; j<=b.size(); j++){
 if(i==0 || j==0){
 tbl[i][j].n = 0;
 tbl[i][j].c = '-';
 continue;
 }
 if(a[i-1] == b[j-1]){
 tbl[i][j].n = tbl[i-1][j-1].n + 1;
 tbl[i][j].c = 'D';
 }
 else if(tbl[i-1][j].n >= tbl[i][j-1].n){
 tbl[i][j].n = tbl[i-1][j].n;
 tbl[i][j].c = 'U';
 }else{
 tbl[i][j].n = tbl[i][j-1].n;
 tbl[i][j].c = 'L';
 }
 }
 }
 string c = "";
 int i=a.size(), j=b.size();
 while(i>=1 && j>=1){
 if(tbl[i][j].c == 'U')
 i--;
 else if(tbl[i][j].c == 'L')
 j--;
 else{
 c+=a[i-1];
 i--;
 j--;
 }
 }
 reverse(c.begin(), c.end());
 cout<<"\n Longest Common Subsequence :"<<c;
 cout<<"\n\n";
 for(int i=0; i<=a.size(); i++){
 cout<<"\n";
 for(int j=0; j<=b.size(); j++){
 cout<<" "<<tbl[i][j].n;
 }
 }
 cout<<"\n\n";
 for(int i=0; i<=a.size(); i++){
 cout<<"\n";
 for(int j=0; j<=b.size(); j++){
 cout<<" "<<tbl[i][j].c;
 }
 }
 cout<<"\n";
}
