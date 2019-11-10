link creat1() {  //头插法   倒序 
	Node *a;
	a = (Node*)malloc(sizeof(Node));
	a ->next = NULL;
	int x, i = 5;
	while(i--) {
		cin>>x;
		Node *p;
		p = (Node*)malloc(sizeof(Node));
		p -> data = x;
		p -> next = a -> next;
		a -> next = p;
	}
	return a;
}