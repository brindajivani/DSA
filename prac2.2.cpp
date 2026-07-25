//Practical 2.2

#include<iostream>
using namespace std;

int iterativeBinarySearch(int arr[], int n, int key){
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==key)
            return mid;

        else if(key<arr[mid])
            high=mid-1;

        else
            low=mid+1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int key){
    if(low>high)
        return -1;

    int mid = (low+high)/2;

    if(arr[mid]==key)
        return mid;

    else if(key<arr[mid])
        return recursiveBinarySearch(arr,low,mid-1,key);

    else
        return recursiveBinarySearch(arr,mid+1,high,key);
}

int main(){
    int arr[50],n,key;

    cout<<"Enter number of book codes:";
    cin>>n;

    cout<<"Enter book codes:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter target book code:";
    cin>>key;

    int result1 = iterativeBinarySearch(arr,n,key);

    if(result1==-1)
        cout<<"\nBook code not found.";
    else
        cout<<"\nBook code found at position"<<result1+1;

    int result2=recursiveBinarySearch(arr,0,n-1,key);

    if(result2==-1)
        cout <<"\nBook code not found.";
    else
        cout <<"\nBook code found at position"<< result2+1;

    return 0;
}