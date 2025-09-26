#include<iostream>
#include<string>
using namespace std;
class Node{
  public:
  string task_name;
  int priority,exe_time;
  Node *next;
  Node (string a,int b, int c){
      task_name=a;
      priority=b;
      exe_time=c;
      next=NULL;
  }
  void display(){
       cout<<"Task Name: "<<task_name<<endl;
       cout<<"Priority: "<<priority<<endl;
       cout<<"Execution Time: "<<exe_time<<"s"<<endl;
   }
   void insert(Node *h,Node *t){
       Node *t1=h;
       while(t1->next!=NULL){
           t1=t1->next;
       }
       t1->next=t;
   }
};


int main(){
  int n,pri,tm;
  string name;
  Node *header=NULL;
  Node *temp=NULL, *prev=NULL , *curr=NULL;

  cout<<"Enter Number of Nodes to be inserted: ";
  cin>>n;
  for(int i=0;i<n;i++){
     cout<<"For Node "<<i+1<<": \n";
          cout<<"Name: ";
          cin>>name;
          cout<<"Priority: ";
          cin>>pri;
          cout<<"Time: ";
          cin>>tm;

      if(header==NULL){
          header=new Node(name,pri,tm);
      }
      else{
          temp=new Node(name,pri,tm);
          if(header->priority < temp->priority){
             temp->next=header;
             header=temp;
          }
          else{
              prev=header;
              curr=header->next;
              if(curr==NULL){
                  header->next=temp;
              }
              else{
                  while(curr!=NULL && curr->priority > temp->priority){
                      prev=curr;
                      curr=curr->next;
                  }
                  temp->next=curr;
                  prev->next=temp;
              }
          }
      }
  }
  cout << "\nDisplaying All Nodes:\n";
  Node* t1 = header;
  while (t1 != NULL) {
      t1->display();
      cout << "----------------\n";
      t1 = t1->next;
  }
  return 0;
}


