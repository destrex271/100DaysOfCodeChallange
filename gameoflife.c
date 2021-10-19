#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define GENNUMBER 1
#define ROW 8
#define COL 8
#define UPPER 1
#define LOWER 0

int cells[8][8];
bool lonlinessCheck(int row, int col);
bool overcrowdCheck(int row, int col);
bool aliveCheck(int row, int col);
bool isToReincarnate(int row, int col);


void populate(){
	for(int i = 0; i < ROW; i++){
		cells[i][0] = 0;
		cells[i][COL-1] = 0;
	}
	for(int j = 0; j < ROW; j++){
		cells[0][j] = 0;
		cells[ROW-1][j] = 0;
	}
	for(int i = 1; i < ROW-1; i++){
		for(int j = 1; j < COL-1; j++){
			cells[i][j] = (rand()%(UPPER-LOWER+1))+LOWER; // Populating the cells with 0's and 1's where 1 stands for alive while 0 stands for dead
		}
	}
}

void display(){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			printf("%3d ", cells[i][j]);
		}
		printf("\n");
	}
}

void main(){

	for(int gen = 0; gen < GENNUMBER; gen++){
		populate();
		printf("GEN %d\n",gen);
		display();
		printf("----------");
		for(int i = 1; i < ROW-1; i++){
			printf("Iter %d\n",i);
			for(int j = 1; j < COL-1; j++){
				if(cells[i][j] == 1){
					if(lonlinessCheck(i,j)){
						cells[i][j] = 0;
					}
					if(overcrowdCheck(i,j)){
						cells[i][j] = 0;
					}
					if(!aliveCheck(i,j)){
						cells[i][j] = 0;
					}
					if(isToReincarnate(i,j)){
						cells[i][j] = 1;
					}
				}
			}
			display();
		}
	}

}

bool lonlinessCheck(int row, int col){
	bool isDead = true;
	int liveCount = 0;
	for (int i = row - 1; i <= row+1; i++){
		for(int j = col - 1; j <= col+1; j++){//Checking the cells surrounding the given cell for alive members
			if(cells[i][j] != 0){
				liveCount++;
			}
			if(liveCount > 1){
				isDead = false;
				break;
			}
		}
	}
	return isDead;
}

bool overcrowdCheck(int row, int col){
	bool isDead = false;
	int liveCount = 0;
	for(int i = row - 1; i<= row+1; i++){
		for(int j = col - 1; j <= col+1; j++){
			if(cells[i][j] != 0){
				liveCount++;
			}
			if(liveCount >= 4){
				isDead = true;
				break;
			}
		}
	}
	return isDead;
}


bool aliveCheck(int row, int col){
	int liveCount = 0;
	for(int i = row - 1; i<= row+1; i++){
                for(int j = col - 1; j <= col+1; j++){
                        if(cells[i][j] != 0){
                                liveCount++;
                        }
                }
        }

	if(liveCount == 2 || liveCount == 3){
		return true;
	}
	return false;

}

bool isToReincarnate(int row, int col){
	int liveCount = 0;
        for(int i = row - 1; i<= row+1; i++){
                for(int j = col - 1; j <= col+1; j++){
                        if(cells[i][j] != 0){
                                liveCount++;
                        }
                }
        }
	if(liveCount == 3){
		return true;
	}
	return false;
}



