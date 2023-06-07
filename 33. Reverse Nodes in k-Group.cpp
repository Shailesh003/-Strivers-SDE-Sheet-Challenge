Node* f(Node* head,int i,int n, int b[]){
	while(b[i]==0 && i<n)i++;
	if(head==NULL|| head->next==NULL || i==n)return head;
	int cnt=0;
	Node* prev=NULL;
	Node* curr=head;
	Node* nextptr;
	while(curr!=NULL&& cnt<b[i]){
		nextptr=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextptr;
		cnt++;
	}
	if(curr!=NULL){
		head->next=f(curr,i+1,n,b);
	}
	return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){

	return  f(head,0,n,b);
}