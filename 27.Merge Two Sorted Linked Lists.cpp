#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
 Node<int> *temp1=first;
 Node<int> *temp2=second;
 Node<int> *dummy=new Node<int>(-1);
 Node<int> *temp3=dummy;
 while(temp1!=NULL && temp2!=NULL){
     if(temp1->data>temp2->data){
         temp3->next=temp2;
         temp3=temp3->next;
         temp2=temp2->next;
     }
     else{
         temp3->next=temp1;
         temp3=temp3->next;
         temp1=temp1->next;
     }
 }
 while(temp1!=NULL){
     temp3->next=temp1;
     temp3=temp3->next;
     temp1=temp1->next;
 }
 while(temp2!=NULL){
     temp3->next=temp2;
     temp3=temp3->next;
     temp2=temp2->next;

 }
 return dummy->next;
}
