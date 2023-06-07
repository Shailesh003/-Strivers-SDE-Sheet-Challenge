int findIntersection(Node *firstHead, Node *secondHead)
{
    Node* temp=firstHead;
    Node* temp2-secondHead;
    while(temp!=temp2){
        if(temp==NULL)temp=secondHead;
        else{
            temp=temp->next;
        }
        if(temp2==NULL)temp2=firstHead;
        else{
            temp2=temp2->next;
        }
    }
    return temp->data;
}