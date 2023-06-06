/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{   //brute force
//     Node* temp=head;
//     int l=0;
//     while(temp!=NULL){
//         l++;
//         temp=temp->next;
//     }
//     if(K>l)return head;
//     if(K==l){
//         head=head->next;
//         return head;
//     }
//     temp=head;
//     int cnt=1;
//     int i=l-K;
//     while(cnt<i){
//         temp=temp->next;
//         cnt++;
//     }
//     temp->next=temp->next->next;
//     return head;
// Optimal
    Node* dummy =new Node(-1);
    dummy->next=head;
    Node* slow=head;
    Node* fast=head;
    for(int i=0;i<K;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast !=NULL &&fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}
