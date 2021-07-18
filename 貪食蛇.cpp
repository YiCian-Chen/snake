#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <time.h>

void gotoxy(int x, int y);
void testbody(int x,int y); 
void testfruit(int x,int y);
void testedge(int x,int y);
void printegde();
void end();

int fx,fy;
std::deque<int> bx={10},by={10};
int body = 1;

int main() {
	system("mode con cols=90 lines=30"); //設定開啟視窗大小
	system("color 71"); //設定背景色和前景色
	system("title 貪吃蛇 v1.0"); //設定視窗標題
    int x=10,y=10;//蛇的初始位置  
    char c=77,tmpc=77,d;//蛇的初始動作方向(right)
	srand( time(NULL) );
	fx=rand()%70+5,fy=rand()%15+5;
    
    gotoxy(fx,fy);
	printf("0");
	printegde();
//print遊戲畫面 
	gotoxy(0,26);
	printf("蛇的位置:%d-%d",x,y);
	gotoxy(0,27);
	printf("水果位置:%d-%d",fx,fy);
	gotoxy(0,28);
	printf("目前蛇長:%d",body);
//print遊戲畫面
    
    while(1){
    //偵測鍵盤讀入 
    	if(kbhit()){
    		d = getch();
    		if(d == (-32))
    			c = getch();
    		else if(d == 27)
    			end();
    		if(c == 72 || c == 80 || c == 75 || c == 77 ){
    			
    			if(tmpc == 72){//up
    				if(c == 77){
    					tmpc = 77;
    					x++;
					}
					else if(c == 75){
    					tmpc = 75;
    					x--;
					} 
					else
						y--; 
				}
				else if(tmpc == 80){//down
    				if(c == 77){
    					tmpc = 77;
    					x++;
					}
					else if(c == 75){
    					tmpc = 75;
    					x--;
					} 
					else
						y++; 
				}
				else if(tmpc == 75){//left
    				if(c == 72){
    					tmpc = 72;
    					y--;
					}
					else if(c == 80){
    					tmpc = 80;
    					y++;
					} 
					else
						x--; 
				}
				else if(tmpc == 77){//right
    				if(c == 72){
    					tmpc = 72;
    					y--;
					}
					else if(c == 80){
    					tmpc = 80;
    					y++;
					} 
					else
						x++; 
				}
			}
			else{
				if(tmpc == 72)
					y--;
				else if(tmpc == 80)
					y++;
				else if(tmpc == 75)
					x--;
				else if(tmpc == 77)
					x++;
			}
    	}
    	else{
			if(tmpc == 72)
				y--;
			else if(tmpc == 80)
				y++;
			else if(tmpc == 75)
				x--;
			else if(tmpc == 77)
				x++;
		}
    	testedge(x,y);//偵測邊界死亡 
    	testbody(x,y);//偵測身體碰撞死亡 
    	testfruit(x,y);//偵測有沒有吃到水果 
   
		Sleep(200);	
    	//system("cls");

	//print遊戲畫面 
		gotoxy(9,26);
		printf("     ");
		gotoxy(9,26);
		printf("%d-%d",x,y);		
	//print遊戲畫面
	
	//print蛇 
		gotoxy(x,y);
		printf("*");
		gotoxy(bx[0],by[0]);
		printf(" ");
	//print蛇
		
	 //更新蛇的位置 
		bx.pop_front();
    	by.pop_front();
    	bx.push_back(x);
    	by.push_back(y);
	//更新蛇的位置
	
	gotoxy(0,29);
    }
    
}




void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出裝置控制代碼
    SetConsoleCursorPosition(hOut, pos);//兩個引數分別是指定哪個窗體，具體位置
}

void testbody(int x,int y){
	for(int i=0;i<body;i++){
		if(x == bx[i] && y == by[i]){
			end(); 
		}	
	}
}

void testfruit(int x,int y) {
	if(x == fx && y == fy){
		srand( time(NULL) );
		fx=rand()%70+5;
		fy=rand()%15+5;
		body++;

		bx.push_back(x);
    	by.push_back(y);
		gotoxy(fx,fy);
		printf("0");
		
		gotoxy(9,27);
		printf("     ");
		gotoxy(9,27);
		printf("%d-%d",fx,fy);
		gotoxy(9,28);
		printf("%d",body);
	}

}

void end() {
	system("cls");
	gotoxy(25,10);
	printf("!!gameover!!");
	gotoxy(28,15);
	printf("score: %d",body);
	gotoxy(25,20);
	system("pause");
	exit(0);
}


void testedge(int x,int y) {
	if(x<1)
		end();
	else if(x>77)
		end();
	else if (y<1)
		end();
	else if(y>24)
		end();
}

void printegde() {
	for(int ix=78,iy=24;iy>=0;iy--){
			gotoxy(ix,iy);
			printf("■");
	}
	for(int ix=78,iy=24;ix>=0;ix-=2){
		gotoxy(ix,iy);
		printf("■");
	}
	for(int ix=0,iy=24;iy>=0;iy--){
		gotoxy(ix,iy);
		printf("■");
	}
	for(int ix=78,iy=0;ix>=0;ix-=2){
		gotoxy(ix,iy);
		printf("■");
	} 	
}
