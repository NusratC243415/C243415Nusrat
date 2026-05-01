#include<iostream>
using namespace std;
int main(){
   int n;
   cout<<"Enter the length of rod: " ;
   cin>>n;

   int price[n+1];
   cout<<"Enter price for each length: ";
   for(int i = 1;i<=n;i++){
    cin>>price[i];
   }

   int MP[n+1];
   MP[0]=0;
   for(int i = 1;i<=n;i++){
    MP[i]=0;
    for(int j=1;j<=i;j++){
        MP[i]=max(MP[i],price[j]+MP[i-j]);
    }

   }
   cout<<"The maximum profit is: "<<MP[n];
   return 0;

}
