//Practical 3.1

#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;

    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minIndex]){
            minIndex=j;
        }
    }
    swap(arr[i],arr[minIndex]);
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int arr[100];
    int bubble[100];
    int selection[100];
    int insertion[100];


    cout<<"Enter no of students:";
    cin>>n;

    cout<<"Enter marks:";
    for(int i=0;i<n;i++){
            cin>>arr[i];

        bubble[i]=arr[i];
        selection[i]=arr[i];
        insertion[i]=arr[i];
    }

    bubbleSort(bubble,n);
    selectionSort(selection,n);
    insertionSort(insertion,n);

    cout<<"\nBubble sort:";
    printArray(bubble,n);

    cout<<"\nSelection sort:";
    printArray(selection,n);

    cout<<"\nInsertion sort:";
    printArray(insertion,n);

    return 0;

}