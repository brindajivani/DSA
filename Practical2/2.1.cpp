//Practical 2.1

#include<iostream>
using namespace std;

int iterativeLinearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }
        int recursiveLinearSearch(int arr[],int n,int key,int index){
            if(index==n){
                return -1;
        }
            if(arr[index]==key){
                return index;
        }
        return recursiveLinearSearch(arr,n,key,index+1);
    }
    int main(){
        int arr[50],n,key;

        cout<<"Enter no of licence plates:";
        cin>>n;

        cout<<"Enter licence plates no:";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<"Enter target plate:";
        cin>>key;

        int result1 = iterativeLinearSearch(arr,n,key);

        if(result1 == -1){
            cout<<"\nLicence plate not found";
        }else{
            cout<<"\nLicence plate found"<<result1+1;
        }
        int result2 = recursiveLinearSearch(arr,n,key,0);

        if(result2 == -1){
            cout<<"\nLicence plate not found";
        }else{
            cout<<"\nLicence plate found"<<result2+1;
        }
        return 0;

    }