#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Function definitions
void printEncodedMaze(int [], unsigned char);
void printEncodedMazeWithPath(int [],int [], unsigned char);
void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8]);
void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], 
		    int bottomRight[8], int finalMaze[14]);
char isPathInMaze(int [], int [], unsigned char);



int main(){

	/*An array of 32 int values that represent the main maze on page 1
	  of the assignment specification*/
	int arr[32] ={-1,-2146430423,-1109928277,-1525661045,-1602496045, 			      
			-1358950569,-1451509759,-1927115297,-1578180479,	  		
			-1354977603,-1476294999,-2084818261,-1163749757,
			-1964319689,-1341614619,-1750141691,-1256060947,
			-1515522751,-1204136611,-1955867371,-1190652827,
			-1553272339,-1100839163,-1999963019,-631368865,
		         -1882138047,-1172944163,-1412279803,-1567107339,
		         -164346691,-2138762879,-1};
	
	/*An array of 32 int values that represents the path*/		
	int encoded[32] ={0, 0, 0, 0, 12, 8, 56, 32, 8032, 4416, 134115648, 67354944, 		 
	                 67109184,67109312, 133169152, 1048576, 1835008, 262144, 262144,
	                 262144,458752,65536, 65536, 65536, 65536, 983040, 67633152,
	                 67633152, 201850880,164102144, 259522560, 0};

	/* char arrays of 1's and 0's representing four 8x8 mazes*/
	char nestedMaze1[8][8] ={{1,1,1,1,1,1,1,1},
				{1,0,0,0,1,0,0,1},
				{1,0,1,0,1,1,0,1},
				{1,0,1,0,0,0,0,1},
				{1,0,1,1,1,1,0,1},
				{1,0,0,0,0,0,0,1},
				{1,0,1,0,1,0,1,1},
				{1,1,1,1,1,1,1,1}};
				
	char nestedMaze2[8][8] ={{1,1,1,1,1,1,1,1},
				{1,0,0,0,0,1,0,1},
				{1,1,1,1,0,1,0,1},
				{1,0,0,1,0,1,1,1},
				{1,1,0,0,0,0,0,1},
				{1,1,1,1,0,1,1,1},
				{1,0,0,0,0,1,0,1},
				{1,1,1,1,1,1,1,1}};
				
	char nestedMaze3[8][8] ={{1,1,1,1,1,1,1,1},
				{1,0,1,0,0,0,1,1},
				{1,0,1,0,1,0,0,1},
				{1,0,1,0,1,0,1,1},
				{1,0,1,0,1,0,1,1},
				{1,0,1,0,1,0,1,1},
				{1,0,0,0,1,0,0,1},
				{1,1,1,1,1,1,1,1}};
				
	char nestedMaze4[8][8] ={{1,1,1,1,1,1,1,1},
				{1,0,1,0,1,0,1,1},
				{1,0,1,0,0,0,0,1},
				{1,0,0,0,1,1,1,1},
				{1,1,1,0,1,0,0,1},
				{1,0,0,0,0,0,1,1},
				{1,1,0,1,1,0,0,1},
				{1,1,1,1,1,1,1,1}};
	

	int encodedMazes[4][8];			     //An int array that stores 4 int arrays of size 8
	
	
	/*Removing any garbage values from encodedMazes array*/
	for (int i =0; i <4; i++){
		for(int j =0; j <8; j++){
			encodedMazes[i][j]=0;
		}
	}
	
	int mergedMazes [14] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //int array of size 14

		
	int path[14]={0, 4096, 4096, 4096, 4096, 7936, 256, 256, 448, 112, 16, 28, 6, 0};//Encoded Path

			
	printEncodedMaze(arr,32);		    //Processes the 32x32 encoded maze and displays it
	
	printEncodedMazeWithPath(arr,encoded,32);   //Displays the 32x32 maze and and path 
	
	isPathInMaze(arr, encoded,32);		    //Checks if the path fits properly in the maze
	if(isPathInMaze(arr, encoded,32)==1){
		printf("The path fits\n");
	}
	else{
		printf("The path does not fit\n");
	}
	
	printf("\n");

	encode8by8Maze(nestedMaze1,encodedMazes[0]); //Encodes the 1st 8x8 maze into an array of 8 ints
	encode8by8Maze(nestedMaze2,encodedMazes[1]); //Encodes the 2nd 8x8 maze into an array of 8 ints
	encode8by8Maze(nestedMaze3,encodedMazes[2]); //Encodes the 3rd 8x8 maze into an array of 8 ints
	encode8by8Maze(nestedMaze4,encodedMazes[3]); //Encodes the 4th 8x8 maze into an array of 8 ints
	
	printf("The four separate 8x8 mazes: \n");
	printEncodedMaze(encodedMazes[0], 8);	     //Processes the 1st encoded maze and displays it
	printf("\n");
	printEncodedMaze(encodedMazes[1], 8);        //Processes the 2nd encoded maze and displays it
	printf("\n");
	printEncodedMaze(encodedMazes[2], 8);	    //Processes the 3rd encoded maze and displays it
	printf("\n");
	printEncodedMaze(encodedMazes[3], 8);	    //Processes the 4th encoded maze and displays it
	printf("\n");
	
	merge8by8Mazes(encodedMazes[0],encodedMazes[1],encodedMazes[2],encodedMazes[3], 
                       mergedMazes); //Merges 4 encoded 8x8 mazes into a final encoded 14x14 maze
	
	printf("Merge four encoded 8x8 mazes and output a final encoded 14x14 maze(test)\n");	
	printEncodedMaze(mergedMazes, 14);	    //Display the final encoded 14x14 maze
	printf("\n");
	
	/*Test code that generates all 256 combinations of 14x14 mazes
	  by combining all possible combinations of the given four 8x8 mazes*/	
	  
	printf("The 256 combinations of 14x14 mazes are: \n");  
	for(int a = 0; a<4 ;a++){
		for(int b = 0; b<4 ;b++){
			for(int c = 0; c<4 ;c++){
				for(int d = 0; d<4 ;d++){
				
				     	
					
					merge8by8Mazes(encodedMazes[a],encodedMazes[b],encodedMazes[c],
							encodedMazes[d],mergedMazes);
					
					printf("%d, %d, %d, %d \n", a+1,b+1,c+1,d+1);
					
					printEncodedMaze(mergedMazes, 14);
					
					if(isPathInMaze(mergedMazes,path,14)==1){
						printf("The path fits in : %d,%d,%d,%d\n", a+1,b+1,c+1,d+1);
						printf("Order of number:top left, top right, ");
                                                printf("bottom left, bottom right\n");
						
					}
					printf("\n");
				}
	
			}
	
		}
	
	}

	return 0;
}

/*This function takes in a 32 int maze array and dimension,and
  processes the encoded maze and displays it.*/
  
void printEncodedMaze(int maze[], unsigned char dimension){
	
	for (int i =0; i<dimension; i++){
		for(int j=(dimension-1); j>=0; j--){
			if(((maze[i]>>j)&1)==1){
				printf("@");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
		
	}
 	
}

/*This function takes in the maze, encoded path and dimension to display the maze and
  path together*/

void printEncodedMazeWithPath(int maze[],int encodedPath[], unsigned char dimension){
	
	for (int i =0; i<dimension; i++){
		for(int j=(dimension-1); j>=0; j--){
			if(((maze[i]>>j)&1)==1){	
				printf("@");
			}
			else if (((encodedPath[i]>>j)&1)==1){
				printf(".");
			}
			else {
				printf(" ");	
			}
		}
		printf("\n");
	}
 	
}

/*This function takes in one 8x8 char array and an int array of size 8.
  It encodes the 8x8 array (maze) into an array of 8 ints.*/

void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8]){
	
	int k =7;
	
	for (int i =0; i<8; i++){
		for(int j=0; j<8; j++){
			encodedMaze[i]|=(inputMaze[i][j]<<k);
			k--;	
		}
		
		k =7;
		
	}
 	
	
}

/*This function takes in four encoded 8x8 mazes and outputs a final encoded 14x14 maze*/

void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], 
		    int bottomRight[8], int finalMaze[14]){
		    
		    int l =0;
		    
		    for(int i =0; i<7; i++){
		    	finalMaze[i]=((topLeft[i]&~1)<<6)|(topRight[i]&(~(1<<7)));  
		    	
		    	
		    }
		    
		    for (int j =7; j<14; j++){
		    
		    	finalMaze[j]=((bottomLeft[l+1]&~1)<<6)|(bottomRight[l+1]&(~(1<<7)));
		    	l++;
		    
		    }		    
		    
}


/*This function takes in an encoded maze, encoded path and maze dimension
  and returns 1 if the given path fits properly in the maze and 0 otherwise. */
  
char isPathInMaze(int encodedMaze[], int encodedPath[], unsigned char mazeDimension){

		
		for (int i =0; i<mazeDimension; i++){
		
			if((encodedMaze[i]&encodedPath[i])!=0){
				return 0;
			}
			else{
				continue;
			}
	
		}
		return 1;


}










