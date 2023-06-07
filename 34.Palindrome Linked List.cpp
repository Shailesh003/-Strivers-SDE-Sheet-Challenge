LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* nextptr;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    LinkedListNode<int>* temp2=reverse(slow);
    LinkedListNode<int>* temp=head;
    while(temp!=NULL && temp2!=NULL){
        if(temp2->data!=temp->data)return false;
        temp=temp->next;
        temp2=temp2->next;
    }
    return true;

}