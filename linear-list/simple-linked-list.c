#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


typedef struct linkedList{
	int data;
	struct linkedList* next;
}linkedList;

linkedList* createNode(){
	linkedList* node = (linkedList*)malloc(sizeof(linkedList));
	memset(node,0,sizeof(linkedList));
	return node;
}

void main() {
	int num,data,i=1,chk=1,key=5;;
	linkedList* head=NULL;
	linkedList* nav=NULL;
	linkedList* pnav=NULL;
	
Start:
	system("cls");
	printf("1.Create\n2.Show\n3.Free\n4.Exit\n==========\n");
	printf(">");
	scanf("%d", &num);


	switch (num) {
	case 1://create
		/* No data 일 경우 */
		if (head == NULL) {
			head = createNode();
			printf("Input Number : ");
			scanf("%d", &data);
			nav = head;
			nav->data = data;
			chk=0;
			break;
		}
		/* nav가 제일 마지막 노드를 가리키게 하는 부분 */
		while (nav->next != NULL) {
			nav = nav->next;
		}

		nav->next = createNode();
		nav = nav->next;
		printf("Input Number : ");
		scanf("%d", &data);
		nav->data = data;
		nav = head;
		chk = 0;
		break;

	case 2://show
		if(nav==NULL){//Empty check
			printf("No data\n");
			getch();
			break;}

			i=1;
			while (nav != NULL) {
				printf("No.%d Data : %d\n", i, nav->data);
				nav = nav->next;
				i++;
			}
			getch();
			nav = head;
			break;
	case 3://free
		//chk로 free check 1= free 0 = nessesary free
		if(chk){
			printf("You are free already\n"); getch(); break;
		}
		
		while(1){
			if(nav==head){
				free(nav);
				head=nav=pnav=NULL;
				chk=1;
				break;
			}

			else{
				while(nav->next !=NULL){
					pnav = nav;
					nav = nav->next;
					}
					free(nav);
					pnav->next = NULL;
					nav = pnav;
			}
		}//end while
		break;


	case 4://exit
		if(chk){
			system("cls");
			printf("Good Bye\n");
			getch();
			exit(0); 
		}

		printf("You should free all memory\n");
		getch();
		break;
	}//end switch
	goto Start;
}//end main
