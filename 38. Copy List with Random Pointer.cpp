LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{ 
    if(head==NULL)return NULL;
    LinkedListNode<int>* temp=head;
    while(temp!=NULL){
        LinkedListNode<int>* n=new LinkedListNode<int>(temp->data);
        n->next=temp->next;
        temp->next=n;
        temp=temp->next->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->random!=NULL){
            temp->next->random=temp->random->next;
        }
        temp=temp->next->next;
    }
    temp=head;
    LinkedListNode<int>* dummy=new LinkedListNode<int>(-1);
    LinkedListNode<int>* temp2=dummy;
    LinkedListNode<int>* fast;
    while(temp!=NULL){
        fast=temp->next->next;
        temp2->next=temp->next;
        temp->next=fast;
        temp=fast;
        temp2=temp2->next;
    }
    return dummy->next;
}