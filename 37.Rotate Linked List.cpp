Node *rotate(Node *head, int k) {
    if(head==NULL || k==0)return head;
     int l=1;
     Node* temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
         l++;
     }
     temp->next=head;
     k=k%l;
     int d=l-k;
     while(d--)temp=temp->next;
     head=temp->next;
     temp->next=NULL;
     return head;

}