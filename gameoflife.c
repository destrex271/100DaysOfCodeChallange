#include <stdio.h>

#define GENNUMBER 1
#define ROW 8
#define COL 8

int cells[8][8];

void populate(){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			cell[i][j] = (j%2); // Populating the cells with 0's and 1's where 1 stands for alive while 0 stands for dead
		}
	}
}

void main(){

	for(int gen = 0; gen < GENNUMBER; gen++){
		populate();
		for(int i = 0; i < ROw; i++){
			for(int j = 0; j < COL; j++){
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
		}
	}

}

bool lonlinessCheck(int row, int col){
	bool isDead = true;
	int liveCount = 0;
	int rcount = row;
	int colcount = col;
	if(i == 0){
		for (int i = 0 ; i <= ; i++){
                for(int j = col - 1; j <= col; j++){//Checking the cells surrounding the given cell for alive members
                        if(cells[i][j] != 0){
                                liveCount++;
                        }
                        if(liveCount > 1){
                                isDead = false;
                                break;
                        }
                }
       	 }
	}
	for (int i = row - 1; i <= row+1; i++){
		for(int j = col - 1; j <= col; j++){//Checking the cells surrounding the given cell for alive members
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



