#include<stdio.h>
#include<stdbool.h>
struct process{
    int index;
    int arr_time,bt_time,wt_time;
    float priority;
    bool flag;
};
void display(struct process a){
    printf("Procees id = %d\n",a.index);
    printf("Arr time = %d \n",a.arr_time );
    printf("Bt time = %d \n",a.bt_time);
    printf("Wt time = %d\n",a.wt_time);
    printf("priority = %f\n",a.priority);
}
void print_wt_bt(struct process arr[],int n){
    for(int i=0;i<n;i++){
        printf("Process no = %d, Wt time = %d , Turnaround Time = %d\n",arr[i].index,arr[i].wt_time,arr[i].wt_time+arr[i].bt_time);
    }
}
int main(int argc, char const *argv[]) {
    printf("Enter number of process\n");
    int p_no;
    scanf("%d",&p_no);
    struct process arr[p_no];
    for(int i=0;i<p_no;i++){//O(n)
            arr[i].priority=1;
            arr[i].wt_time=0;
            arr[i].index=i+1;
            arr[i].flag=true;
    }
    int at,bt;
    for(int i=0;i<p_no;i++){//O(n2)
        printf("For process %d:\n",i+1);
        printf("Enter arrival time and burst time:\n");
        scanf("%d %d",&at,&bt);
        arr[i].arr_time=at;
        arr[i].bt_time=bt;
    }
    sort(arr,p_no);//O(n2)
    int curr=arr[0].index;//it stores the value of first process index
    for(int i=0;i<p_no;i++){//O(n2)
        printf("Current process: %d\n",curr);
        change_wt_priority(arr,p_no,arr[i].bt_time,i+1);//it chaanges the priority of next process
        sort(arr,p_no);
        curr=arr[i+1].index;
    }
    print_wt_bt(arr,p_no);//complexity is O(n3)
    return 0;
}
