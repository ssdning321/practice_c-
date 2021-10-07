#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
#define SPEED 300
#define W 0
#define S 1
#define A 2
#define D 3

void welcometogame();
void gotoxy(int x,int y);
void color(int c);
void explaination();
void creatmap();
void creatsnake();
void movestatus();
void diecause();
void keyboard();
void gameover();
void creatfood();
typedef struct Snake{
	int x;
	int y;
	struct Snake* next;
}Snake;
int status=A,sleeptime=SPEED;
int score=0,add=10;
int hightest=0;
int die=0;//1撞死 2撞自己死 3退出 
Snake* p=new Snake,*food=new Snake;
void welcometogame(){
	gotoxy(48,4);
	color(11);
	cout<<"贪 吃 蛇 大 作 战"<<endl; 
	for(int i=10,j=0;i<=30;i++){//24-96
		if(i==10){
			for(j=24;j<97;j++){
				gotoxy(j,i);
				color(9);
				cout<<"-";
			}
		}
		else if(i==30){
			for(j=24;j<97;j++){
				gotoxy(j,i);
				color(9);
				cout<<"-";
			}
		}
		else{
			for(j=24;j<97;j+=72){
				gotoxy(j,i);
				cout<<"|";
			}
		}
	}
	gotoxy(49,15);
	color(13);
	cout<<"1.start of game";//14
	gotoxy(49,20);
	color(10);
	cout<<"2.explain of game";//16
	gotoxy(49,25);
	color(11);
	cout<<"3.end of game";//12
	gotoxy(45,35);
	color(8);
	cout<<"please input number[ ]";
	int n;
	gotoxy(65,35);
	cin>>n;
	switch(n){
		case 1:
			creatmap();
			creatsnake();
			creatfood();
			keyboard();
			break;
		case 2:
			explaination();
			break;
		case 3:
			system("cls");
			while(1){
				Sleep(999999);
			}
			break;
		default:
			gotoxy(50,37);
			color(12);
			cout<<"输入有误,请重新输入"<<endl;
			getchar();
			getchar();
			system("cls");
			color(7);
			welcometogame();
			break; 
	}
}
void explaination(){
	system("cls");
	gotoxy(48,10);
	color(23);
	cout<<"使用'W' 或者'↑'控制上";
	gotoxy(48,13);
	color(23);
	cout<<"使用或者控制下";
	gotoxy(48,16);
	color(23);
	cout<<"使用或者控制左";
	gotoxy(48,19);
	color(23);
	cout<<"使用或者控制右";
	gotoxy(48,22);
	color(23);
	cout<<"吃到☉得10分"; 
	gotoxy(48,25);
	color(23);
	cout<<"蛇身●〇〇〇〇";
	gotoxy(48,28);
	color(23); 
	cout<<"吃到☆得分更高";
	gotoxy(48,31);
	color(23);
	cout<<"撞到墙壁或者自己失败";
	gotoxy(48,34);
	color(23);
	cout<<"按任意键返回.........";
	getwchar();
	getwchar();
	color(15);
	system("cls");
	welcometogame();
}
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return;
}
void color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return;
}
void creatmap(){
	system("cls");//120 40
	int i,j;
	color(7);
	for(i=0;i<120;i+=2){
		gotoxy(i,0);
		cout<<"■";
		gotoxy(i,39);
		cout<<"■";
	}
	for(j=1;j<39;j++){
		gotoxy(0,j);
		cout<<"■";
		gotoxy(118,j);
		cout<<"■";
	}
	for(i=2;i<118;i+=2){//无色的格子 
		for(j=1;j<39;j++){
			color(0);
			gotoxy(i,j);
			cout<<"□";
		}
	}	
}
void creatsnake(){
	Snake* tail=NULL;
	for(int i=0;i<3;i++){
		Snake *head=new Snake;
		head->x=60-2*i;
		head->y=19;
		head->next=tail;
		tail=head;
	}
	p->next=tail;
	while(tail){
		gotoxy(tail->x,tail->y);
		color(5);
		cout<<"〇";
		tail=tail->next;
	}
	return;

	
}
void creatfood(){
	int x,y,z=1;
	x=((rand()%58)+1)*2;
	y=(rand()%28)+1;
	Snake *q=p->next;
	while(q){
		if(q->x==x&&q->y==y){
			z=0;
			break;
		}
		q=q->next;
	}
	if(z==0){
		creatfood();
		return;
	}
	else {
		gotoxy(x,y);
		color(11);
		cout<<"☉";
		food->x=x;
		food->y=y;
		food->next;
	}
	return;
	
}
void diecause(){
	if(p->next->x==0|p->next->y==0|p->next->x==118|p->next->y==39){
		die=1;
		gameover();
	}
	Snake *q=new Snake;
	q=p->next;
	while(q->next){
		if(q->next->x==p->next->x&&q->next->y==p->next->y){
			die=2;
			delete q;
			gameover();
			break;
		}
		q=q->next;
	}
	
}
void movestatus(){
	if(status==A){
		if(food->x+2==p->next->x&&food->y==p->next->y){
			score+=add;
			gotoxy(food->x,food->y);
			color(5);
			cout<<"〇";
			Snake *q=new Snake;
			q->x=food->x;
			q->y=food->y;
			q->next=p->next;
			p->next=q;
			creatfood();
		}
		else{
			Snake *newhead=new Snake;
			newhead->x=p->next->x-2;
			newhead->y=p->next->y;
			newhead->next=p->next;
			p->next=newhead;
			gotoxy(newhead->x,newhead->y);
			color(5);
			cout<<"〇";
			while(newhead->next->next){
				newhead=newhead->next;
			}
			gotoxy(newhead->next->x,newhead->next->y);
			color(0);
			cout<<"□";
			delete newhead->next;
			newhead->next=NULL;	
		}
	}
	else if(status==D){
		if(food->x-2==p->next->x&&food->y==p->next->y){
			score+=add;
			gotoxy(food->x,food->y);
			color(5);
			cout<<"〇";
			Snake *q=new Snake;
			q->x=food->x;
			q->y=food->y;
			q->next=p->next;
			p->next=q;
			creatfood();
		}
		else{
			Snake *newhead=new Snake;
			newhead->x=p->next->x+2;
			newhead->y=p->next->y;
			newhead->next=p->next;
			p->next=newhead;
			gotoxy(newhead->x,newhead->y);
			color(5);
			cout<<"〇";
			while(newhead->next->next){
				newhead=newhead->next;
			}
			gotoxy(newhead->next->x,newhead->next->y);
			color(0);
			cout<<"□";
			delete newhead->next;
			newhead->next=NULL;	
		}
	}
	else if(status==W){
		if(food->x==p->next->x&&food->y+1==p->next->y){
			score+=add;
			gotoxy(food->x,food->y);
			color(5);
			cout<<"〇";
			Snake *q=new Snake;
			q->x=food->x;
			q->y=food->y;
			q->next=p->next;
			p->next=q;
			creatfood();
		}
		else{
			Snake *newhead=new Snake;
			newhead->x=p->next->x;
			newhead->y=p->next->y-1;
			newhead->next=p->next;
			p->next=newhead;
			gotoxy(newhead->x,newhead->y);
			color(5);
			cout<<"〇";
			while(newhead->next->next){
				newhead=newhead->next;
			}
			gotoxy(newhead->next->x,newhead->next->y);
			color(0);
			cout<<"□";
			delete newhead->next;
			newhead->next=NULL;	
		}
	}
	else if(status==S){
		if(food->x==p->next->x&&food->y-1==p->next->y){
			score+=add;
			gotoxy(food->x,food->y);
			color(5);
			cout<<"〇";
			Snake *q=new Snake;
			q->x=food->x;
			q->y=food->y;
			q->next=p->next;
			p->next=q;
			creatfood();
		}
		else{
			Snake *newhead=new Snake;
			newhead->x=p->next->x;
			newhead->y=p->next->y+1;
			newhead->next=p->next;
			p->next=newhead;
			gotoxy(newhead->x,newhead->y);
			color(5);
			cout<<"〇";
			while(newhead->next->next){
				newhead=newhead->next;
			}
			gotoxy(newhead->next->x,newhead->next->y);
			color(0);
			cout<<"□";
			delete newhead->next;
			newhead->next=NULL;	
		}
	}
	return;
}

void keyboard(){
	while(1){
		if(GetAsyncKeyState(0x41)&&status!=D){
			status=A;
		}
		else if(GetAsyncKeyState('D')&&status!=A){
			status=D;
		}
		else if(GetAsyncKeyState('S')&&status!=W){
			status=S;
		}
		else if(GetAsyncKeyState('W')&&status!=S){
			status=W;
		}
		else if(GetAsyncKeyState(VK_SPACE)){
			gotoxy(40,0);
			color(4);
			cout<<"按SPACE继续游戏，ESC退出游戏"; 
			while(1){
				Sleep(300);
				if(GetAsyncKeyState(VK_SPACE)){
					break;
				}
				else if(GetAsyncKeyState(VK_ESCAPE)){
					die=3;
					break;
				}
				else{
					NULL;
				}
			}
			gotoxy(40,0);
			color(7);
			cout<<"■■■■■■■■■■■■■■■■■■■■■";
			
		}
		gotoxy(4,0);
		color(4);
		cout<<"得分："<<score;
		diecause();
		movestatus();
		gameover();
		Sleep(SPEED);
	}
}
void gameover(){
	switch(die){
		case 1:
		case 2:
		case 3:
			break;
		default:
			return;
			break;
	}
	gotoxy(45,6);
	color(4);
	cout<<" you are dead,press ENTER key to continue....";
	getwchar();
	getwchar();
	system("cls");
	gotoxy(50,5);
	color(4);
	cout<<"gameover";
	gotoxy(48,8);
	color(13);
	cout<<"your score:"<<score;
	if(score>hightest){
		hightest=score;
	}
	color(3);
	gotoxy(45,11);
	cout<<"the heightest score:"<<hightest;
	gotoxy(45,14);
	color(4);
	cout<<"press RNTER key to continue...";
	getwchar();
	system("cls");
	welcometogame();
	return;
}

int main(){
	srand((unsigned)time(NULL));
	CONSOLE_CURSOR_INFO CURSORINFO;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CURSORINFO);
	CURSORINFO.bVisible=false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CURSORINFO);
	SetConsoleTitle("吃了李朝阳");
	system("mode con cols=120 lines=40");
	welcometogame();
	return 0;
}























