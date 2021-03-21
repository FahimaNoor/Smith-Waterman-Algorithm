#define Match 2
#define MisMatchPenelty -3
#define GapPenalty -2
#define A 65  ///IS THE DEFINING OF A C T G REALLY NECESSARY? if not then please remove
#define C 67
#define T 84
#define G 71


/// There can be only four types of maximum value1, value2, value3, value4(which is zero; the max is initially declared as 0)

///GLOBAL VARIABLE

int matrix[10][10];  //m+1, n+1


int match_mismatch(int i, int j){   ///have to make sure this function never receives (0,0)
    if(matrix[i][0]==matrix[0][j]) return Match;
    else return MisMatchPenelty;
}

int maximum(int i, int j){   ///have to make sure this function never receives (0,0)
    int max=0;
    int value1,value2,value3;

    value1=  matrix[i-1][j]+ match_mismatch(i,j);
    value2= matrix[i-1][j]+ GapPenalty;
    value3= matrix[i][j-1]+ GapPenalty;

    if(value1>=max) max=value1;
    if(value3>=max) max=value2;
    if(value3>=max) max=value3;

return max;

}


void print(){

for(int i=0;i<10;i++){          ///printing the matrix //check the condition. i will be +1 of the b length and j will be +1 of a length
        for(int j=0;j<10;j++){
        printf("%d\t ", matrix[i][j]);

        }
        printf("\n\n");
}


}

void main(){
    matrix[0][0]=-99;  //this index will not be used in the algorithm
    int count_1=0;
    int count_2=0;

    char a[]="ATGCATCCC";
    char b[]="TCTATATCC";




for(int i=0;i<10;i++){   /// initializing value 1 the matrix// the i condition will be +1 to the string length as [0][0] will not be used
        for(int j=0;j<10;j++){
           if(i==0 && j!=0){
            matrix[i][j]=a[count_1];
            count_1++;
           }
           if(j==0 && i!=0){
                matrix[i][j]=b[count_2];
                count_2++;

           }
        }

}


/*

for(int i=0;i<5;i++){   /// initializing value 1 the matrix
        for(int j=0;j<5;j++){
           if((i==0 || j==0) && ( i!=0 || j!=0) )  matrix[i][j]=2;

        }
}
*/

/*
for(int i=1;i<5;i++){   /// initializing value 1 the matrix
        for(int j=1;j<5;j++){


        matrix[i][j]=1;

        }
}
*/
/*
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((i==1 || j==1) && ( i!=0 &&  j!=0) ) matrix[i][j]=0;  ///exceptional case-only the first row or column are given the value of zero

        }
}
*/

 print();  //prints the matrix


//matrix[i][j]=max();    ///will put the max function. Max function will carry out the swa algo to determine the max value.


}
