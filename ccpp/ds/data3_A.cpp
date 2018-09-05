#include <iostream>
#include <string.h>
#include<stdlib.h>
typedef struct node* ptr;
using namespace std;
struct node{
  int value;
  ptr next;
};


ptr merge(ptr head1,ptr head2)  {
    if (head1 == NULL)
    {
        return head2;
    }
    else if(head2 == NULL)
    {
        return head1;
    }

    ptr MergeHead = NULL;
    if (head1->value < head2->value)
    {
        MergeHead = head1;
        head1 = head1->next;
    }
    else
    {
        MergeHead = head2;
        head2 = head2->next;
    }
    ptr tmpNode = MergeHead;
    while (head1&&head2)
    {
        if (head1->value < head2->value)
        {
            MergeHead->next = head1;
            head1 = head1->next;
        }
        else
        {
            MergeHead->next = head2;
            head2 = head2->next;
        }
        MergeHead = MergeHead->next;
    }
    if (head1)
    {
        MergeHead->next = head1;
    }
    if (head2)
    {
        MergeHead->next = head2;
    }

    return tmpNode;

}

void print(ptr head){
  if(head == 0)
  return;

  while(head!=0){
    cout<<head->value<<" ";
    head = head->next;
  }
  cout<<endl;
}


int main(int argc, char *argv[]){

        int t = 0;
        cin>>t;
        int n,m;

        for(int num = 0;num < t;num++){
          cin>>n;
          cin>>m;
          ptr nlist = (ptr)malloc(sizeof(struct node));
          ptr mlist = (ptr)malloc(sizeof(struct node));
          ptr ptrn = nlist;
          ptr ptrm = mlist;

          for(int i = 0;i < n;i++){
            cin>>nlist->value;
            if(i != n-1){
              nlist -> next = (ptr)malloc(sizeof(struct node));
              nlist = nlist->next;
            }else{
              nlist->next = 0;//vs 0?
              break;
            }
          }
            for(int i = 0;i < m;i++){
              cin>>mlist->value;
              if(i != m-1){
                mlist -> next = (ptr)malloc(sizeof(struct node));
                mlist = mlist->next;
              }else{
                mlist->next = 0;//vs 0?
                break;
              }
            }
              ptr list = merge(ptrn,ptrm);
              print(list);

          }
        }
