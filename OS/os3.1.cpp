#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > item_table;
vector<pair<int, int> > allocate_table;

void display(){
    cout<<"————起始地址——空闲区大小————"<<endl;
    for(int i = 0; i < item_table.size(); i++){
        cout<<"      "<<item_table[i].first<<"     "<<item_table[i].second<<endl;
    }
}
void display_allocate(){
    cout<<"——进程序号——起始地址——空闲区大小————"<<endl;
    for(int i = 0; i < allocate_table.size(); i++){
        cout<<"    "<< i << " ";
        cout<<"      "<<allocate_table[i].first<<"     "<<allocate_table[i].second<<endl;
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
    for(int i = 0; i < n; i++){
        for(auto j = item_table.begin(); j != item_table.end(); j++){
            // 找到fit
            if(j->second == prcs[i]){
                allocate_table.push_back(make_pair(j->first, j->second));
                item_table.erase(j);
                break;
            }else if(j->second > prcs[i]){
                allocate_table.push_back(make_pair(j->first, prcs[i]));
                j->first += prcs[i];
                j->second -= prcs[i];
                break;
            }
        } 
    }
    cout<<"------首次适应算法-------"<<endl;
    display();
    display_allocate();
    allocate_table.clear();
    item_table.clear();
    init();
}

void best(vector<int>& prcs){
    int n = prcs.size();
    for(int i = 0; i < n; i++){
        auto target = item_table.begin();   // 需要一些排错
        int min_dis = INT8_MAX;
        for(auto j = item_table.begin(); j != item_table.end(); j++){
            // 找到fit
            if((j->second - prcs[i]) >= 0 && (j->second - prcs[i]) < min_dis)
                target = j; 
        }
        if (target->second == prcs[i])
        {
            allocate_table.push_back(make_pair(target->first, target->second));
            item_table.erase(target);
        }
        else if (target->second > prcs[i])
        {
            allocate_table.push_back(make_pair(target->first, prcs[i]));
            target->first += prcs[i];
            target->second -= prcs[i];
        }
    }
    cout<<"------最佳适应算法-------"<<endl;
    display();
    display_allocate();
    item_table.clear();
    allocate_table.clear();
    init();
}
void bad(vector<int>& prcs){
    int n = prcs.size();
    for(int i = 0; i < n; i++){
        auto target = item_table.begin();   // 需要一些排错
        int max_dis = 0;
        for(auto j = item_table.begin(); j != item_table.end(); j++){
            // 找到fit
            if((j->second - prcs[i]) >= 0 && (j->second - prcs[i]) > max_dis)
                target = j; 
        }
        if (target->second == prcs[i])
        {
            allocate_table.push_back(make_pair(target->first, target->second));
            item_table.erase(target);
        }
        else if (target->second > prcs[i])
        {
            allocate_table.push_back(make_pair(target->first, prcs[i]));
            target->first += prcs[i];
            target->second -= prcs[i];
        }
    }
    cout<<"------最差适应算法-------"<<endl;
    display();
    display_allocate();
    allocate_table.clear();
    item_table.clear();
    init();
}
int main(){
    int arr[5] = {80, 30, 28, 10, 10};
    vector<int> prcs(arr, arr+5);
    init();
    first(prcs);
    best(prcs);
    bad(prcs);
    return 0;
}