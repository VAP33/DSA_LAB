#include<iostream>
int main(){
    using namespace std;
    int n,arr[n];
    cout<<"Enter Number of Cards: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Card "<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        cout<<"Hand After Insertion "<<i<<endl;
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";

        }
        cout<<endl;
    }
    cout<<"The Sorted Cards in Hand are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}
