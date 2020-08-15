#include<iostream>

using namespace std;

#define size 8

void initial();
void findPossible();
void check(int x,int y);
void display();
void displayRate();

int rate[8][8];
bool seen[8][8];
int counter=0;

int main(){
    int x,y;
    initial();
    findPossible();
    cout<<"give x position in board";
    cin>>x;
    cout<<"give y position in board";
    cin>>y;
    check(x-1,y-1);
    cout<<"END"<<endl;
    //cout<<seen[2][7];
    display();
    return 0;
}

void initial(){
    for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
	    seen[i][j] = false;
	}
    }
    for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
	    rate[i][j] = 0;
	}
    }
} 


void findPossible(){
    for(int i=0;i<size;i++){
	for(int j=0;j<size;j++){
	    if(i-2>=0 && j-1>=0 )
		rate[i][j]++;
	    if(i-2>=0 && j+1<8 )
		rate[i][j]++;
	    if(i+2<8 && j-1>=0 )
		rate[i][j]++;
	    if(i+2<8 && j+1<8 )
		rate[i][j]++;
	    if(i-1>=0 && j-2>=0 )
		rate[i][j]++;
	    if(i-1>=0 && j+2<8 )
		rate[i][j]++;
	    if(i+1<8 && j-2>=0 )
		rate[i][j]++;
	    if(i+1<8 && j+2<8 )
		rate[i][j]++;
	}
    }
    for(int i=0;i<size;i++){
	for(int j=0;j<size;j++){
	    cout<<rate[i][j]<<"   ";
	}
	cout<<endl;
    }
}

void check(int x,int y){
    int nextX,nextY,least=size+2;
    
    seen[x][y]=true;
    
    if(x-2>=0 && y-1>=0){
	
	rate[x-2][y-1]--;
	
	if(rate[x-2][y-1]<least && seen[x-2][y-1] == false){
	    nextX = x-2;
	    nextY = y-1;
	    least = rate[x-2][y-1];
	}
    }
    if(x-2>=0 && y+1<8){
	
	rate[x-2][y+1]--;
	
	if(rate[x-2][y+1]<least && seen[x-2][y+1] == false){
	    nextX = x-2;
	    nextY = y+1;
	    least = rate[x-2][y+1];
	}
    }
    if(x+2<8 && y-1>=0){
	
	rate[x+2][y-1]--;
	
	if(rate[x+2][y-1]<least && seen[x+2][y-1] == false){
	    nextX = x+2;
	    nextY = y-1;
	    least = rate[x+2][y-1];
	}
    }
    if(x+2<8 && y+1<8){
	
	rate[x+2][y+1]--;
	
	if(rate[x+2][y+1]<least && seen[x+2][y+1] == false){
	    nextX = x+2;
	    nextY = y+1;
	    least = rate[x+2][y+1];
	}
    }
    if(x+1<8 && y-2>=0){
	
	rate[x+1][y-2]--;
	
	if(rate[x+1][y-2]<least && seen[x+1][y-2] == false){
	    nextX = x+1;
	    nextY = y-2;
	    least = rate[x+1][y-2];
	}
    }
    if(x+1<8 && y+2<8){
	
	rate[x+1][y+2]--;
	
	if(rate[x+1][y+2]<least && seen[x+1][y+2] == false){
	    nextX = x+1;
	    nextY = y+2;
	    least = rate[x+1][y+2];
	}
    }
    if(x-1>=0 && y+2<8){
	
	rate[x-1][y+2]--;
	
	if(rate[x-1][y+2]<least && seen[x-1][y+2] == false){
	    nextX = x-1;
	    nextY = y+2;
	    least = rate[x-1][y+2];
	}
    }
    if(x-1>=0 && y-2>=0){
	
	rate[x-1][y-2]--;
	
	if(rate[x-1][y-2]<least && seen[x-1][y-2] == false){
	    nextX = x-1;
	    nextY = y-2;
	    least = rate[x-1][y-2];
	}
    }
    cout<<"least : "<<least<<"  now "<< x<<","<<y<<"   next   "<<nextX<<","<<nextY<<"   counter  "<<counter<<endl;
    //if(isFull())
    
    if(counter == 63)
	return ;
    counter++;
   // displayRate();
    display();
    check(nextX,nextY);
}

void displayRate(){
    for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
	    cout<<rate[i][j]<<"   ";
	}
	cout<<endl;
    }
}

void display(){
    for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
	    if(seen[i][j] == true)
		cout<<"1  ";
	    else 
		cout<<"0  ";
	}
	cout<<endl;
    }
}



