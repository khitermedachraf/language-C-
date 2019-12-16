/* single Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}node;
   // les variables globales
   node* root=NULL;     int len,pos,n;
   // prototypes de fonctions
void append();
int length();
void Display();
void Delete();
void insertpos();
void insert_end();
int searchpos(int pos);
int occurence(int x);
void reverseList();
void trier_affichage (node* root);
void inverse (node* root );

int main(int argc, char *argv[]) {

    	int choix;

      do{
      	printf("---------Single Linked List Operations----------\n");
	    printf("1-append.\n");
	    printf("11-treier et afficher . ") ;
	    printf("12- inverse ") ;
	    printf("2-length.\n");
	    printf("3-display.\n");
	    printf("4-delete node.\n");
	    printf("5-insert node.\n");
	    printf("6-insert_end node.\n");
	    printf("7-search node.\n");
	    printf("8-occurence.\n");
	    printf("9-reverse list.\n");
	    printf("10-quitter.\n");
	    printf("\n---------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	switch(choix){
	   		case 1:append();
	   		break;
	   		case 2:len=length();
	   		 printf("length is:%d\n",len);
	   		break;
	   		case 3:Display();
	   		break;
	   		case 4:Delete();
	   		break;
	   		case 5:insertpos();
	   		break;
	   		case 6:insert_end();
	   		break;
	   		case 7:printf("donner la position ou vous voulez chercher:");
	   		        scanf("%d",&pos);
			        searchpos(pos);
	   		break;
	   		case 8:printf("donner l'entier a rechercher:");
	   		       scanf("%d",&n);
			       occurence(n);
	   		break;
	   		case 9:reverseList();
	   		break;

	   		case 11:trier_affichage(root);
	   		break;
	   		case 12 :inverse (root ) ;
	   		break ;
	   		case 10:exit(1);
	   		break;
		   }

	  }while(choix!=10);

	  getch();

	return 0;
}

void append(){

	 node* temp;
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("enter node data:");
	 scanf("%d",&temp->data);
	 temp->next=NULL;
	 if(root == NULL){
	 	root=temp;
	 }else{
	 	 node* p;
	 	 p=root;
	 	 while(p->next!=NULL){
	 	 	p=p->next;
		  }
		  p->next=temp;
	 }
}

int length(){

	 node* p;
	 int count=0;
	 p=root;
	 while(p!=NULL){
	 	count++;
	 	p=p->next;
	 }
	return count;
}

void Display(){

	 node*p;
	 if(p==NULL){
	 	printf("list is empty.\n");
	 }else{
	 	 p=root;
	 	while(p!=NULL){
	 		printf("%d-->",p->data);
	 		p=p->next;
		 }
		 printf("\n");
	 }
}

void Delete() {

		node* p;     int loc;

	printf("Give me the location:");
	scanf("%d",&loc);

	if(loc>length()){
		printf("Invalid location.\n");
	}else if(loc==1){
		p=root;
		root=root->next;
		free(p);
	}else{
		node* q;     int i=1;
		p=root;
		while(i<loc-1){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		free(q);
	}
}

void insertpos(){

	    node* temp; 	node* q=root;      int loc;

	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("enter node data:");
	 scanf("%d",&temp->data);
	 temp->next=NULL;

	printf("Give me the location:");
	scanf("%d",&loc);

	if(loc==1){  // insertion au début
		temp->next=root;
		root=temp;
	}else{ // insertion au milieu
		int i=1;
	  while(q!=NULL  &&  i<loc-1){
	  	q=q->next;
	  	i++;
	  }
	  temp->next=q->next;
	  q->next=temp;
	}
}

void insert_end(){  // insertion à la fin

	  node* q=root;  node* temp;

	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("enter node data:");
	 scanf("%d",&temp->data);
	 temp->next=NULL;

	while(q->next!= NULL){
	 	q=q->next;
	 }
	  q->next=temp;
}

int searchpos(int pos){

	  node* p=root; int i=1;
	  while(p!=NULL && i<pos){
	  	p=p->next;
	  	i++;
	  }
	printf("la valeur chreche vaut:%d\n",p->data);
}

int occurence(int x){

	  node* p=root;    int n=0;
	  while(p!=NULL){
	  	if(p->data==x){
	  		n=n+1;
		  }
		 p=p->next;
	  }
	printf("le nombre d'occurence vaut:%d\n",n);
}

void reverseList(){

      node *prevNode, *curNode;

    if(root != NULL){
        prevNode = root;
        curNode = root->next;
        root = root->next;

        prevNode->next = NULL;

        while(root != NULL){
            root = root->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = root;
        }
        root = prevNode;
    }
}

void trier_affichage (node* root)
{
    node *p , *q ;
    int x ;
    p= root ;
    while (p != NULL)
    {
        q= p->next;
        while(q!= NULL)
        {
            if(p->data > q->data)
                {
                    x = q->data ;
                    q->data = p->data ;
                    p->data= x ;
                }
            q=q->next ;
        }
        p=p->next ;
    }

}  ;

void inverse (node* root )
{
 node *q , *res , *t ;
 res = NULL ;
 t= root ;
 while (t!= NULL)
 {
    q= t ;
    t=t->next ;
    q->next=res  ;
    res = q ;

 }
 root= res ;
} ;
