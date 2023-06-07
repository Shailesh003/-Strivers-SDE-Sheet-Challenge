Node* merge(Node* head1,Node* head2){
	if(head1==NULL)return head2;
	if(head2==NULL)return head1;
	Node* dummy=new Node(-1);
	Node* temp=head1;
	Node* temp2=head2;
	Node* temp3=dummy;
	while(temp !=NULL && temp2!=NULL){
		if(temp->data>temp2->data){
			temp3->bottom=temp2;
			temp2=temp2->bottom;
			temp3=temp3->bottom;
		}
		else{
			temp3->bottom=temp;
			temp=temp->bottom;
			temp3=temp3->bottom;
		}
	}
	if(temp!=NULL){
		temp3->bottom=temp;
	}
	if(temp2!=NULL){
		temp3->bottom=temp2;
	}
	return dummy->bottom;
}
   
Node* flatten(Node* root) 
{	
	if(root==NULL || root->next==NULL)return root;
	root->next=flatten(root->next);
	root=merge(root,root->next);
	root->next=NULL;
	return root;
}
