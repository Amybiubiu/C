#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FIFO(vector<int>& pages){
    cout<<"-----FIFO------"<<endl;
    double n = pages.size();
    int pagefault = 0;
    double pagefault_rate = 0;
    vector<int> memory_block(3, 0);
    for(int i = 0; i < n; i++){
        auto target = find(memory_block.begin(), memory_block.end(), pages[i]);
        if(target != memory_block.end()){
            // hit
            cout<<"0 ";
        }else{
            // pagefault
            pagefault++;
            cout<<memory_block[2]<<" ";
            memory_block.erase(memory_block.begin() + 2);
            memory_block.insert(memory_block.begin(), pages[i]);
        }
    }
    pagefault_rate = pagefault / n;
    cout<<"\n";
    cout<<"中断次数："<<pagefault<<" 缺页率："<<pagefault_rate<<endl;
}

void LRU(vector<int>& pages){
    cout<<"-----LRU------"<<endl;
    double n = pages.size();
    int pagefault = 0;
    double pagefault_rate = 0;
    vector<int> memory_block(3, 0);
    for(int i = 0; i < n; i++){
        auto target = find(memory_block.begin(), memory_block.end(), pages[i]);
        if(target != memory_block.end()){
            // hit
            cout<<"0 ";
            memory_block.erase(target);
            memory_block.insert(memory_block.begin(), pages[i]);
        }else{
            // pagefault
            pagefault++;
            cout<<memory_block[2]<<" ";
            memory_block.erase(memory_block.begin() + 2);
            memory_block.insert(memory_block.begin(), pages[i]);
        }
    }
    pagefault_rate = pagefault / n;
    cout<<"\n";
    cout<<"中断次数："<<pagefault<<" 缺页率："<<pagefault_rate<<endl;
}

int main(){
    int arr[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    vector<int> pages(arr, arr+12);
    FIFO(pages);
    LRU(pages);
    return 0;
}