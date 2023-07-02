#include<iostream>
using namespace std;
/*
顺序表基本操作：
*/
typedef struct{
    int data[100];
    int length;
}LineList;
//顺序表的插入
bool insert_LineList(LineList *L,int i,int data){
    if(i>L->length+1 && i<1){
        return false;
    }
    if(L->length>=100){
        return false;
    }
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=data;
    L->length++;
    return true;
}
//顺序表的删除
bool delete_LineList(LineList *L,int i){
     if(i>L->length+1 && i<1){
        return false;
    }
    if(L->length>=100){
        return false;
    }
    for(int j=i-1;j<=L->length-1;j++){
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}
//顺序表的输出
void printList(LineList *L){
    for(int i=0;i<L->length;i++){
        cout<<L->data[i]<<endl;
    }
}
//寻找顺序表第一个值为a的位置
int localElem(LineList *L,int a){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==a){
            return i+1;
        }
    }
    return 0;
}
//删除顺序表最小的值并用最后一位来替代
int deleteMinElem(LineList *L){
    int min=L->data[0];
    int index=0;
    if(L->length==0){
        cout<<"报错：表为空";
        return 0;
    }
    for(int i=0;i<L->length;i++){
        if(L->data[i]<min){
            min=L->data[i];
            index=i;
        }
    }
    L->data[index]=L->data[L->length-1];
    L->length--;
    return 0;
}
//逆序，空间复杂度O(1)
bool reverse(LineList *L){
    int tem=0;
    if(L->length==0){
        cout<<"报错：表为空";
        return 0;
    }
    for (int i = 0; i < L->length/2; i++)
    {
        tem=L->data[i];
        L->data[i]=L->data[L->length-i-1];
        L->data[L->length-i-1]=tem;
    }
    return true;
}
//删除每一位d的值，空间复杂度O(1),时间复杂度O(n)
bool deleteAll(LineList *L,int data){
    int tem=0;
    if(L->length==0){
        cout<<"报错：表为空";
        return 0;
    }
    for (int i = 0; i < L->length; i++)
    {
        if(L->data[i]==data){
            tem++;
        }
        else{
            L->data[i-tem]=L->data[i];
        }
        
    }
    L->length=L->length-tem;
    return true;
}
//重置
bool recreat(LineList *L){
    L->length=0;
    return true;
}
//删除区间内的值，空间复杂度O(1),时间复杂度O(n)
bool deleteLimits(LineList *L,int limit1,int limit2){
    int tem=0;
    if(L->length==0){
        cout<<"报错：表为空";
        return 0;
    }
    if(limit2<limit1){
        cout<<"报错：区间范围有误";
        return 0;
    }
    for (int i = 0; i < L->length; i++)
    {
        if(L->data[i]>=limit1 && L->data[i]<=limit2){
            tem++;
        }
        else{
            L->data[i-tem]=L->data[i];
        }
        
    }
    L->length=L->length-tem;
    return true;
}
//合并2张表
LineList* merge(LineList *L,LineList *L2){
    LineList *L3;
    if(L->length==0 || L->length==0){
        cout<<"报错：表为空";
        return NULL;
    } 
    for (int i = 0; i < L2->length; i++)
    {
        L->data[i+L->length]=L2->data[i];
    }
    L->length=L->length+L2->length;
    return L;
}
//合并2张有序表,方法1
LineList* merge2(LineList *L,LineList *L2){
    LineList *L3;
    if(L->length==0 || L2->length==0){
        cout<<"报错：表为空";
        return NULL;
    } 
    L3->length=L->length+L2->length;
    int a=0;
    int b=0;
    int index1 =0;
    int index2 =0;
        for (int i = 0; i < L3->length; i++)
    {
        if(a == L2->length){
            L3->data[i]=L->data[index1];
            index1++;    
        }else if(b == L->length){
            L3->data[i]=L2->data[index2];
            index2++;
        }
        else{
            int q=0;
            if(L->data[index1]>L2->data[index2]){
                q=L2->data[index2];
                cout<<i<<":::::"<<"index2->"<<index2<<endl;
                index2++;
                a++;
                
            }else{
                q=L->data[index1];
                cout<<i<<":::::"<<"index1->"<<index1<<endl;
                index1++;
                b++;
            }
            L3->data[i]=q;
        }
    }
    return L3;
}
//合并2张有序表,方法2
LineList* merge3(LineList *L,LineList *L2){
    LineList *L3;
    // L3->length=L->length+L2->length;
    
    cout<<L->length;
    cout<<L2->length<<endl;
    int i=0,j=0,k=0;
    while (i<L->length && j<L2->length)
    {
        if(L->data[i]>=L2->data[j]){
            cout<<L2->data[j];
            L3->data[k]=L2->data[j];
            k++;
            j++;
        }else{
            cout<<L->data[i];
            L3->data[k]=L->data[i];
            k++;
            i++;
        }
        cout<<"====";
    }
    // while (i<L->length)
    // {
    //     cout<<L->data[i];
    //     L3->data[k++]=L->data[i++];
    // }
    // while (j<L2->length)
    // {
    //     cout<<L2->data[j];
    //     L3->data[k++]=L2->data[j++];
    // }
    
    return L3;
}
//将顺序表2个位置之元素互换
LineList* reverseTwo(LineList* L,int start,int end){
    int a=0;
    for(int i=start;i<=end/2;i++){
        a=L->data[i];
        L->data[i]=L->data[end-i];
        L->data[end-i]=a;
    }
    return L;
}
int main(){
    LineList *L;
    L->length=0;
    // insert_LineList(L,1,1);
    // insert_LineList(L,2,2);
    // insert_LineList(L,3,4);
    // insert_LineList(L,4,5);
    // insert_LineList(L,5,6);
    // insert_LineList(L,6,7);
    // insert_LineList(L,7,8);
    // insert_LineList(L,8,9);
    // insert_LineList(L,9,10);
    // printList(L);
    // cout<<"--------------\n";
    // insert_LineList(L,3,3);
    // printList(L);
    // cout<<"--------------\n";
    // delete_LineList(L,3);
    // printList(L);
    // cout<<"--------------\n";
    // int location = localElem(L,5);
    // cout<<location<<endl; 
    // cout<<"--------------\n";
    // deleteMinElem(L);
    // printList(L);
    // cout<<"--------------\n";
    // reverse(L);
    // printList(L);
    
    // recreat(L);
    LineList *L2;
    L2->length=0;
    insert_LineList(L,1,1);
    insert_LineList(L,2,3);
    insert_LineList(L,3,7);
    insert_LineList(L,3,9);


    insert_LineList(L2,1,2);
    insert_LineList(L2,2,4);
    insert_LineList(L2,3,6);
    insert_LineList(L2,4,8);

  
    
    // insert_LineList(L,6,1);
    // insert_LineList(L,7,6);
    // insert_LineList(L,8,7);
    // insert_LineList(L,9,8);
    // insert_LineList(L,10,9);
    // insert_LineList(L,11,10);
    // insert_LineList(L,12,11);
    // insert_LineList(L,13,1);
    // printList(L);
    // cout<<"--------------\n";
    // deleteAll(L,1);
    // deleteLimits(L,1,6);
    // printList(merge(L,L2));
    // LineList *L3=merge2(L,L2);
    LineList *L3=merge3(L,L2);
    printList(L2);
    cout<<"==========\n";
    // printList(reverseTwo(L3,0,3));
    
    
    
    return 0;
}