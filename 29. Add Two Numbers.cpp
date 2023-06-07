Node *addTwoNumbers(Node *num1, Node *num2)
{
    int carry=0;
    Node *dummy=new Node(-1);
    Node* temp=dummy;
    while(num1!=NULL || num2!=NULL || carry){
        int sum=0;
        if(num1!=NULL){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2!=NULL){
            sum+=num2->data;
            num2=num2->next;
        }
        sum+=carry;
        temp->next=new Node(sum%10);
        carry=sum/10;
        temp=temp->next;
    } 
    return dummy->next;
}
