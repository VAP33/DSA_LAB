#include<iostream>
using namespace std;
const int MAXNODES=10;
bool visited[MAXNODES];
int adjacencymatrix[MAXNODES][MAXNODES];
void DFS(int node,int n){
	visited[node]=true;
	cout<<node<<" ";
	//Explore All Adjacent nodes at node 
	for(int i=0;i<n;i++){
		if(adjacencymatrix[node][i]==1 && !visited[i]){
			DFS(i,n);
		}
	}
}
int main(){
	cout<<"~~~~~~~~DFS~~~~~~~~"<<endl;
	int n,start,end;
	char q;
	cout<<"Enter Number of Nodes: ";
	cin>>n;
	//Initialise Adjacency Matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adjacencymatrix[i][j]=0;
		}
		visited[i]=false;
	}
	cout<<"Enter the Edges "<<endl;
	do{
		cout<<"Enter Start Node: ";
		cin>>start;
		cout<<"Enter End Node: ";
		cin>>end;
		adjacencymatrix[start][end]=1;
		cout<<"Do You Wish to enter more edges? (Y/N): ";
		cin>>q;
	}
	while(q=='y' || q=='Y');
	cout<<"The Final Adjacency Matrix is: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adjacencymatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Shortest Path According to DFS is: ";
	DFS(0,n);
	cout<<endl;
	return 0;
}
