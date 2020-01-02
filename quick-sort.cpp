int QSort(int arr[],int low,int high)
{  
    if(low < high)
    {  
        int lt = low;	//low为枢轴位置
        int gt = high;
        int i=low+1; //low位置的元素为枢轴元素，所以用于比较的元素从low+1开始
        
        int temp = arr[low]; //将枢轴的元素储存到temp中
        
        while(i <= gt)
        {  
            if(arr[i] < temp) 	//小于枢轴元素的放在lt左边 
                sawp(arr,lt++,i++);  //即交换lt和i位置的元素，此时枢纽位置(lt)右移一位，i也因此右移
            else if(arr[i] > temp)  //大于枢轴元素的放在gt右边 
                sawp(arr,i,gt--);  //交换i和gt位置的元素，gt需要左移，i由于变为gt位置元素，所以不需要移动
            else 		//相等时，无需交换，只需把i右移一位
                i++; 
        }  
        //lt-gt的元素已经排定，只需对it左边和gt右边的元素进行递归求解
        QSort(arr,low,lt-1);  
        QSort(arr,gt+1,high);  
    }   
}  