#include <stdio.h>
#include <stdlib.h>

void printmap(char map[][10],int right){
	printf("  X 0  1  2  3  4  5  6  7  8  9    10 11 12 13 14 15 16 17 18 19\nY\n");
	if (right==0){
		for(int i=0;i<10;i++){
			printf("%d   ",i);
			for(int j=0;j<20;j++){
				printf("%c  ",map[j][i]);
				if(j==9) printf("  ");
			}
			printf("\n");
		}
	}
	else{
		for(int i=0;i<10;i++){
			printf("%d   O  O  O  O  O  O  O  O  O  O    ",i);
			for(int j=10;j<20;j++){
				printf("%c  ",map[j][i]);
			}
			printf("\n");
		}
	}
}

void p5(char map[][10],int player){
	int x=-1,y=-1,option=0,counter=1,option1=0,option2=0,option3=0,option4=0;
	printf("player %d placing the 1x5 ship\n",player);
	while(!(player*10-10<=x&&x<player*10)){	
		printf("enter the x coordinate you want to place the ship(%d~%d):",player*10-10,player*10-1);
		scanf("%d",&x);
		if(!(player*10-10<=x&&x<player*10)){
			printf("value entered out of range!\n");
			x=-1;
		}
	}
	while(!(0<=y&&y<10)){	
		printf("enter the y coordinate you want to place the ship(0~9):");
		scanf("%d",&y);
		if(!(0<=y&&y<10)){
			printf("value entered out of range!\n");
			x=-1;
		}
	}
	printf("options to place ship on [%d %d]:\n",x,y);
	if(y-4>=0) {
		printf("%d  [%d %d][%d %d][%d %d][%d %d][%d %d] [UP]\n",counter,x,y,x,y-1,x,y-2,x,y-3,x,y-4);
		option1=1;
		counter++;
	}
	if(x+4<player*10) {
		printf("%d  [%d %d][%d %d][%d %d][%d %d][%d %d] [RIGHT]\n",counter,x,y,x+1,y,x+2,y,x+3,y,x+4,y);
		option2=1;
		counter++;
	}
	if(y+4<10) {
		printf("%d  [%d %d][%d %d][%d %d][%d %d][%d %d] [DOWN]\n",counter,x,y,x,y+1,x,y+2,x,y+3,x,y+4);
		option3=1;
		counter++;
	}
	if(x-4>=player*10-10) {
		printf("%d  [%d %d][%d %d][%d %d][%d %d][%d %d] [LEFT]\n",counter,x,y,x-1,y,x-2,y,x-3,y,x-4,y);
		option4=1;
		counter++;
	}
	while(!(0<option&&option<=counter)){
		printf("your option:");
		scanf("%d",&option);
		if(!(0<option&&option<=counter-1)) {
			printf("value entered out of range!\n");
			option=0;
		}
	}
	if(option==1){
		if(option1) option=1;
		else if(option2) option=2;
		else if(option3) option=3;
		else option=4;
	}
	else if(option==2){
		if(option1){
			if(option2) option=2;
			else if(option3) option=3;
			else option=4;
		}
		else{
			if(option2) option=3;
			else option=4;
		}
	}
	else if(option==3){
		if(!option4) option=3;
		else if(option1&&option2&&option3) option=3;
		else option=4;
	}
	switch(option){
		case 1:map[x][y]='5';map[x][y-1]='5';map[x][y-2]='5';map[x][y-3]='5';map[x][y-4]='5';break;
		case 2:map[x][y]='5';map[x+1][y]='5';map[x+2][y]='5';map[x+3][y]='5';map[x+4][y]='5';break;
		case 3:map[x][y]='5';map[x][y+1]='5';map[x][y+2]='5';map[x][y+3]='5';map[x][y+4]='5';break;
		case 4:map[x][y]='5';map[x-1][y]='5';map[x-2][y]='5';map[x-3][y]='5';map[x-4][y]='5';break;
	}
}

void p3(char map[][10],int player){
	int x=-1,y=-1,option=0,counter=1,success=0,option1=0,option2=0,option3=0,option4=0;
	printf("player %d placing the 1x3 ship\n",player);
	while(!success){
		while(!(player*10-10<=x&&x<player*10)){
			printf("enter the x coordinate you want to place the ship(%d~%d):",player*10-10,player*10-1);
			scanf("%d",&x);
			if(!(player*10-10<=x&&x<player*10)) {
				printf("value entered out of range!\n");
				x=-1;
			}
		}
		while(!(0<=y&&y<10)){	
			printf("enter the y coordinate you want to place the ship(0~9):");
			scanf("%d",&y);
			if(!(0<=y&&y<10)) {
				printf("value entered out of range!\n");
				x=-1;
			}
		}
		if(map[x][y]!='O'){
			x=-1;
			y=-1;
			printf("A ship is already here!\n");
		}
		else success=1;
	}
	printf("options to place ship on [%d %d]:\n",x,y);
	if(y-2>=0&&map[x][y-1]=='O'&&map[x][y-2]=='O') {
		printf("%d  [%d %d][%d %d][%d %d] [UP]\n",counter,x,y,x,y-1,x,y-2);
		option1=1;
		counter++;
	}
	if(x+2<player*10&&map[x+1][y]=='O'&&map[x+2][y]=='O') {
		printf("%d  [%d %d][%d %d][%d %d] [RIGHT]\n",counter,x,y,x+1,y,x+2,y);
		option2=1;
		counter++;
	}
	if(y+2<10&&map[x][y+1]=='O'&&map[x][y+2]=='O') {
		printf("%d  [%d %d][%d %d][%d %d] [DOWN]\n",counter,x,y,x,y+1,x,y+2);
		option3=1;
		counter++;
	}
	if(x-2>=player*10-10&&map[x-1][y]=='O'&&map[x-2][y]=='O') {
		printf("%d  [%d %d][%d %d][%d %d] [LEFT]\n",counter,x,y,x-1,y,x-2,y);
		option4=1;
		counter++;
	}
	while(!(0<option&&option<=counter)){
		printf("your option:");
		scanf("%d",&option);
		if(!(0<option&&option<=counter-1)) {
			printf("value entered out of range!\n");
			option=0;
		}
	}
	if(option==1){
		if(option1) option=1;
		else if(option2) option=2;
		else if(option3) option=3;
		else option=4;
	}
	else if(option==2){
		if(option1){
			if(option2) option=2;
			else if(option3) option=3;
			else option=4;
		}
		else{
			if(option2) option=3;
			else option=4;
		}
	}
	else if(option==3){
		if(!option4) option=3;
		else if(option1&&option2&&option3) option=3;
		else option=4;
	}
	switch(option){
		case 1:map[x][y]='3';map[x][y-1]='3';map[x][y-2]='3';break;
		case 2:map[x][y]='3';map[x+1][y]='3';map[x+2][y]='3';break;
		case 3:map[x][y]='3';map[x][y+1]='3';map[x][y+2]='3';break;
		case 4:map[x][y]='3';map[x-1][y]='3';map[x-2][y]='3';break;
	}
}

void p4(char map[][10],int player){
	int x=-1,y=-1,option=0,counter=1,success=0,option1=0,option2=0,option3=0,option4=0;
	printf("player %d placing the 1x4 ship\n",player);
	while(counter==1){
		while(!success){
			while(!(player*10-10<=x&&x<player*10)){	
				printf("enter the x coordinate you want to place the ship(%d~%d):",player*10-10,player*10-1);
				scanf("%d",&x);
				if(!(player*10-10<=x&&x<player*10)) {
					printf("value entered out of range!\n");
					x=-1;
				}
			}
			while(!(0<=y&&y<10)){	
				printf("enter the y coordinate you want to place the ship(0~9):");
				scanf("%d",&y);
				if(!(0<=y&&y<10)) {
					printf("value entered out of range!\n");
					y=-1;
				}
			}
			if(map[x][y]!='O'){
				x=-1;
				y=-1;
				printf("A ship is already here!\n");
			}
			else success=1;
		}
		printf("options to place ship on [%d %d]:\n",x,y);
		if(y-3>=0&&map[x][y-1]=='O'&&map[x][y-2]=='O'&&map[x][y-3]=='O') {
			printf("%d  [%d %d][%d %d][%d %d][%d %d] [UP]\n",counter,x,y,x,y-1,x,y-2,x,y-3);
			option1=1;
			counter++;
		}
		if(x+3<player*10&&map[x+1][y]=='O'&&map[x+2][y]=='O'&&map[x+3][y]=='O') {
			printf("%d  [%d %d][%d %d][%d %d][%d %d] [RIGHT]\n",counter,x,y,x+1,y,x+2,y,x+3,y);
			option2=1;
			counter++;
		}
		if(y+3<10&&map[x][y+1]=='O'&&map[x][y+2]=='O'&&map[x][y+3]=='O') {
			printf("%d  [%d %d][%d %d][%d %d][%d %d] [DOWN]\n",counter,x,y,x,y+1,x,y+2,x,y+3);
			option3=1;
			counter++;
		}
		if(x-3>=player*10-10&&map[x-1][y]=='O'&&map[x-2][y]=='O'&&map[x-3][y]=='O') {
			printf("%d  [%d %d][%d %d][%d %d][%d %d] [LEFT]\n",counter,x,y,x-1,y,x-2,y,x-3,y);
			option4=1;
			counter++;
		}
		if (counter==1) {
			printf("the location is too small to place the 1x4 ship, change x and y coordinate\n");
			x=-1;
			y=-1;
			success=0;
		}
	}
	while(!(0<option&&option<=counter)){
		printf("your option:");
		scanf("%d",&option);
		if(!(0<option&&option<=counter-1)) {
			printf("value entered out of range!\n");
			option=0;
		}
	}
	if(option==1){
		if(option1) option=1;
		else if(option2) option=2;
		else if(option3) option=3;
		else option=4;
	}
	else if(option==2){
		if(option1){
			if(option2) option=2;
			else if(option3) option=3;
			else option=4;
		}
		else{
			if(option2) option=3;
			else option=4;
		}
	}
	else if(option==3){
		if(!option4) option=3;
		else if(option1&&option2&&option3) option=3;
		else option=4;
	}
	switch(option){
		case 1:map[x][y]='4';map[x][y-1]='4';map[x][y-2]='4';map[x][y-3]='4';break;
		case 2:map[x][y]='4';map[x+1][y]='4';map[x+2][y]='4';map[x+3][y]='4';break;
		case 3:map[x][y]='4';map[x][y+1]='4';map[x][y+2]='4';map[x][y+3]='4';break;
		case 4:map[x][y]='4';map[x-1][y]='4';map[x-2][y]='4';map[x-3][y]='4';break;
	}
}

int win(char map[][10]){
	int ship1=0,ship2=0,win=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(map[i][j]!='O') ship1++; 
		}
	}
	for(int i=10;i<20;i++){
		for(int j=0;j<10;j++){
			if(map[i][j]!='O') ship2++; 
		}
	}
	if(ship1==0) {
		printf("player 2 win the game!\n");
		win=1;
	}
	if(ship2==0) {
		printf("player 1 win the game!\n");
		win=1;
	}
	return win;
}

void fire(char map[][10],char battle[][10],int player){
	int x=-1,y=-1,success=0;
	while(!success){
		while(!((3-player)*10-10<=x&&x<(3-player)*10)){	
			printf("enter the x coordinate you want to fire at(%d~%d):",(3-player)*10-10,(3-player)*10-1);
			scanf("%d",&x);
			if(!((3-player)*10-10<=x&&x<(3-player)*10)) {
				printf("value entered out of range!\n");
				x=-1;
			}
		}
		while(!(0<=y&&y<10)){	
			printf("enter the y coordinate you want to fire at(0~9):");
			scanf("%d",&y);
			if(!(0<=y&&y<10)) {
				printf("value entered out of range!\n");
				y=-1;
			}
		}
		if(battle[x][y]!='O'){
			x=-1;
			y=-1;
			printf("this place has been fired\n");
		}
		else success=1;
	}
	if(map[x][y]!='O') {
		battle[x][y]=map[x][y];
		map[x][y]='O';
		printf("hit the target!\n");
	}
	else {
		battle[x][y]='X';
		printf("miss!\n");
	}
}
void main(void){
	char map[20][10],battle[20][10];
	int conf=0,player=1;
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
			map[i][j]='O';
			battle[i][j]='O';
		}
	}
	printf("Welcome to the battle ship game! the game need 2 players. Follow the instruction. Good luck have fun\n");
	printmap(map,0);
	p5(map,1);
	printmap(map,0);
	p3(map,1);
	printmap(map,0);
	p4(map,1);
	printmap(map,0);
	printf("enter number 1 to confirm and turn computer to player 2\n");
	while(conf!=1){
		scanf("%d",&conf);
	}
	conf=0;
	system("clear");
	printmap(map,1);
	p5(map,2);
	printmap(map,1);
	p3(map,2);
	printmap(map,1);
	p4(map,2);
	printmap(map,1);
	printf("enter number 1 to confirm\n");
	while(conf!=1){
		scanf("%d",&conf);
	}
	system("clear");
	printf("game start!\n");
	printmap(battle,0);
	while(!win(map)){
		printf("player %d's turn\n",player);
		fire(map,battle,player);
		printmap(battle,0);
		if(player==1) player++;
		else player--;
	}
}