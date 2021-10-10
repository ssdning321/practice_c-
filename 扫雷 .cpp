
//   |   |
//---|---|---
//   |   |
//---|---|---
//   |   |
//48-0  57-9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COL 10

int Swap(char arr1[ROW][COL],int arr2[ROW][COL],int x,int y){
	if(arr2[x][y]==9){
		arr1[x][y]='*';
		return 0;
	}
	else{
		arr1[x][y]=arr2[x][y]+48;
		return 1;
	}
}
	
void Put(int arr[ROW][COL],int row,int col,int num){
	int i=0,j=0,z=0,q=0,w=0,n=0;
	for(z=0;z<num;z++){
		do{
			i=rand()%ROW;
			j=rand()%COL;
			if(arr[i][j]==0){
				arr[i][j]=9;
				break;
			}
			else{NULL;}
		}
		while(1);
	}
	if(arr[0][0]==9)
		{NULL;}//���Ͻ� 
	else{
		n=0;
		if(arr[0][1]==9)
			{n++;}
		else
			{NULL;}
		if(arr[1][0]==9)
			{n++;}
		else
			{NULL;}
		if(arr[1][1]==9)
			{n++;}
		else
			{NULL;}
		arr[0][0]=n;
	}
	if(arr[0][col-1]==9)
		{NULL;}//���Ͻ� 
	else{
		n=0;
		if(arr[0][col-2]==9)
			{n++;}
		else
			{NULL;}
		if(arr[1][col-1]==9)
			{n++;}
		else
			{NULL;}
		if(arr[1][col-2]==9)
			{n++;}
		else
			{NULL;}
		arr[0][col-1]=n;
	}
	if(arr[row-1][0]==9)
		{NULL;}//���½� 
	else{n=0;
		if(arr[row-2][0]==9)
			{n++;}
		else
			{NULL;}
		if(arr[row-2][1]==9)
			{n++;}
		else
			{NULL;}
		if(arr[row-1][1]==9)
			{n++;}
		else
			{NULL;}
		arr[row-1][0]=n;
	}
	if(arr[row-1][col-1]==9)
		{NULL;}//���½� 
	else{
		n=0;
		if(arr[row-2][col-2]==9)
			{n++;}
		else
			{NULL;}
		if(arr[row-2][col-1]==9)
			{n++;}
		else
			{NULL;}
		if(arr[row-1][col-2]==9)
			{n++;}
		else
			{NULL;}
		arr[row-1][col-1]=n;
	}
	for(q=1;q<row-1;q++){
		for(w=1;w<col-1;w++){
			if(arr[q][w]==9)
				{NULL;}
			else{
				n=0;
				if(arr[q+1][w+1]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q+1][w]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q+1][w-1]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q-1][w+1]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q-1][w]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q-1][w-1]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q][w+1]==9)
					{n++;}
				else
					{NULL;}
				if(arr[q][w-1]==9)
					{n++;}
				else
					{NULL;}
				arr[q][w]=n;
			}
		}
	}
	for(q=1,w=0;q<row-1;q++){
		if(arr[q][w]==9)
			{NULL;}//������ 
		else{
			n=0;
			if(arr[q-1][w]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q-1][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][w]==9)
				{n++;}
			else
				{NULL;}
			arr[q][w]=n;
		}
		if(arr[q][col-1]==9)
		{NULL;}//������ 
		else{
			n=0;
			if(arr[q-1][col-2]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q][col-2]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][col-2]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q-1][col-1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][col-1]==9)
				{n++;}
			else
				{NULL;}
			arr[q][col-1]=n;
		}
	}
	for(q=0,w=1;w<col-1;w++){
		if(arr[q][w]==9)
			{NULL;}//�Ϻ��� 
		else{
			n=0;
			if(arr[q+1][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][w-1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q+1][w]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[q][w-1]==9)
				{n++;}
			else
				{NULL;}
			arr[q][w]=n;
		}
		if(arr[row-1][w]==9)
			{NULL;}//�º��� 
		else{
			n=0;
			if(arr[row-2][w]==9)
				{n++;}
			else
				{NULL;}
			if(arr[row-2][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[row-2][w-1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[row-1][w+1]==9)
				{n++;}
			else
				{NULL;}
			if(arr[row-1][w-1]==9)
				{n++;}
			else
				{NULL;}
			arr[row-1][w]=n;
		}
	}

}

void Initboard(char arr[ROW][COL],int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]=' ';
		}
	}
}

void Init(int arr[ROW][COL],int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]=0;
		}
	}
}

void Displayboard(char arr[ROW][COL],int row,int col){
	for(int i=0;i<2*row-1;i++){
		for(int j=0;j<2*col-1;j++){
			if((j+2)%2==0){
				if((i+2)%2==0){
					printf(" %c ",arr[i/2][j/2]);
				}
				else
					{printf("---");}
			}
			else
				{printf("|");}
		}
		printf("\n");
	}
}




void game(){
	int num=0,t=0,u=0,z=1,m=1;
	char arr[ROW][COL]={' '};
	int realarr[ROW][COL]={0};
	srand((unsigned int)time(NULL));
	Initboard(arr,ROW,COL);
	Init(realarr,ROW,COL);
	printf("��������õ��׵�����.............\n");
	do{scanf("%d",&num);
		if(0>num||num>ROW*COL){
			printf("�������Ϸ�������������.....\n");
		}
		else
			{break;}
	}
	while(1);
	Put(realarr,ROW,COL,num);
	Displayboard(arr,ROW,COL);
	do{
		do{	
			printf("�����������");
			scanf("%d",&t);
			printf("������������");
			scanf("%d",&u);
			if(arr[t-1][u-1]!=' '){
				printf("�����ظ�������������......\n");
			}
				else
					{break;}
		}
		while(1);
		m=Swap(arr,realarr,t-1,u-1);
		Displayboard(arr,ROW,COL);
		if(0==(ROW*COL-z-num)){
			printf("�ɹ����ף�������\n");
			break;}
		else
			{NULL;}
		z++;
	}
	while(m);
	printf("��Ϸ��������");	
}

void menu(){
	int s=0;
	do{
		printf("***********************************\n");
		printf("*******1��ʼ��Ϸ  0.������Ϸ*******\n");
		printf("***********************************\n");
		scanf("%d",&s);
		if(s==1){
			game();
		}
		else if(s==0){
			printf("********��Ϸ������***************\n");
			break;
		}
		else{
			printf("�����ʽ�������������롣\n");
		}
	}
	while(1);
}

int main(){
	menu();
	return 0;
}



























