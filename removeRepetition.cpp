//
//  main.cpp
//  text2
//
//  Created by mac on 2020/1/3.
//  Copyright © 2020 mac. All rights reserved.


#include <iostream>
using namespace std;

int main(){
    int arr[8]={1,2,2,44,3,6,8,6};
    int n = sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    int l = 0;
    for(int i = 0; i<n-l; i++){
        for(int j=i+1; j<n-l; j++){
            if(arr[i] == arr[j]){
                int d=i;
                while(d < n-l-1){
                    arr[d]= arr[d+1];
                    d++;
                }
                l++;
            }
        }
    }
    cout<<l<<endl;
    for(int i=0; i<n-l; i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
    return 0;
}
