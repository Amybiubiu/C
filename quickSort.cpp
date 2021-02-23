#include <iostream>
#include "vector"
using namespace std;

void quickSort(vector<int> &a, int left, int right){
    if(left > right) return ;
    int i = left;
    int j = right;
    int mark = a[left];
    while (i < j)
    {
        while (i < j && a[j] > mark)
            j--;
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] < mark)
            i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = mark;
    quickSort(a, left, i-1);
    quickSort(a, i+1, right);
}
int main(){
    cout<<"vector<vector<int>>(n?)"<<endl;
    int size = 0;
    cin>>size;
    vector<int> arr(size);
    // while(cin>>temp){
    //     arr.push_back(temp);
    // }
    for(int i = 0; i < size; i++){
        int temp = 0;
        cin>>temp;
        arr[i] = temp;
    }
    // vector<int> arr = {2, 4, 6, 3, 1, 9, 5};
    // quickSort(arr, 0, 6);
    for(auto num : arr)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}