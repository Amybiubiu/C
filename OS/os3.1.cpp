#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > item_table;

void display(){
    cout<<"————起始地址——空闲区大小————"<<endl;
    for(int i = 0; i < item_table.size(); i++){
        cout<<"      "<<item_table[i].first<<"     "<<item_table[i].second<<endl;
    }
}

void init(){
    item_table.push_back(make_pair(0, 100));
    item_table.push_back(make_pair(100, 50));
    item_table.push_back(make_pair(150, 30));
    item_table.push_back(make_pair(180, 20));
}

void first(vector<int>& prcs){
    int n = prcs.size();
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++){
        for(auto j = item_table.begin(); j != item_table.end(); j++){
            // 找到fit
            if(j->second == prcs[i]){
                res[i] = 1;
                item_table.erase(j);
                break;
            }else if(j->second > prcs[i]){
                res[i] = 1;
                j->first += prcs[i];
                j->second -= prcs[i];
                break;
            }
        } 
    }
    display();
    for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void best(vector<int>& prcs){

}
void bad(vector<int>& prcs){
    
}
int main(){
    int arr[5] = {80, 30, 28, 10, 10};
    vector<int> prcs(arr, arr+5);
    init();
    first(prcs);
    return 0;
}