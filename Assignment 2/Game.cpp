#include<iostream>
int main(){
    using namespace std;
    int n,player1[5],player2[5],temp;
    cout<<"Enter Number of Scores: ";
    cin>>n;
    cout<<"Enter Scores for Player 1: \n";
    for(int i=0;i<n;i++){
        cout<<"Score "<<i+1<<":";
        cin>>player1[i];
    }
    cout<<"Enter Scores for Player 2: \n";
    for(int i=0;i<n;i++){
        cout<<"Score "<<i+1<<":";
        cin>>player2[i];
    }
    cout<<"Sorting Scores for Player 1:\n";
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(player1[j+1]>player1[j]){
                cout<<"Swapping score "<<player1[j+1]<<" with "<<player1[j]<<" – Leveling up!"<<endl;
                temp=player1[j];
                player1[j]=player1[j+1];
                player1[j+1]=temp;

            }

        }
    }
    cout<<"Sorting Scores for Player 2:\n";
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(player2[j+1]>player2[j]){
                cout<<"Swapping score "<<player2[j+1]<<" with "<<player2[j]<<" – Leveling up!"<<endl;
                temp=player2[j];
                player2[j]=player2[j+1];
                player2[j+1]=temp;

            }

        }
    }
    cout<<"Printing Sorted Scores of Player 1:\n";
    for(int i=0;i<n;i++){
        cout<<player1[i]<<" ";

    }
    cout<<endl;
    cout<<"Printing Sorted Scores of Player 2:\n";
    for(int i=0;i<n;i++){
        cout<<player2[i]<<" ";
    }
    cout<<endl;
    cout<<"Level complete! Scores sorted!"<<endl;
    if(player1[0]>player2[0]){
        cout<<"Winner is Player 1!\n";
    }
    else if(player1[0]<player2[0]){
        cout<<"Winner is Player 2!\n";
    }
    else{
        cout<<"That's a Tie\n";
    }

}
