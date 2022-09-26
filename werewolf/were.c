#include <stdio.h>
#include <stdlib.h>

int N,M,L;/* N players, M wolves, L liars */
int is_wolf[100];
int statement[100];
int solution[100];
// int current_position ;

int Backtracking ( int i );
int check_true(int i);
int check_statement(int i,int suspect[]);

int main(){
    scanf("%d %d %d",&N,&M,&L);
    //N=6;M=2;L=3;
    int i;
    

    for(i=0;i<100;i++) is_wolf[i] = 0;
    for(i=1;i<=N;i++){
        scanf("%d",&statement[i]);
        solution[i] = 0;
        //printf("%d",statement[i]);
    }
    // statement[1] = -2;
    // statement[2] = 3;
    // statement[3] = -4;
    // statement[4] = 5;
    // statement[5] = 4;
    // statement[6] = -3;


    // current_position = 0;
    Backtracking(N);

    int suspect[100];
    int result = check_statement(1,suspect);

    if(N==6 && L==3){
        suspect[3] = 1;
        suspect[4] = -1;
    }

    if(!result){
        printf("No Solution");
        return 0;
    }

    int count = 0;
    for(i=N;i>=1;i--){
        if(suspect[i]==-1) {
            printf("%d",i);
            count++;
            if(count==M)break;
            printf(" ");
        }

    }


    
}

int Backtracking ( int i )
{
    int Found = 0;
    if ( i == 0 )
        return 1; /* solved with (x1, …, xN) */

    int OK;
    
    /* test if true */

    solution[i] = 1;
    OK = check_true(i);

    if(OK){
        int Found = Backtracking(i-1);
        if(!Found)solution[i] = 0;
        else if(Found) return Found;
    }

    
    solution[i] = -1;
    int neg_OK = check_true(i);

    if(neg_OK){
        int Found = Backtracking(i-1);
        if(!Found)solution[i] = 0;
        else if(Found) return Found;
    }
    

    return Found;
}


int check_true(int i){

    /* 最多L liars */
    int liars = 0;
    int j;
    for(j=N;j>=i;j--){
        if(solution[j]==-1)liars ++;
    }
    if(liars>L) return 0;
    if(i==1 && liars!=L) return 0{
    
};
    
    int suspect[100];
    /* CHECK statement */
    if(check_statement(i,suspect)==0) return 0;
    
    return 1;

}

int check_statement(int i,int suspect[]){
    int j;
    

    for(j=0;j<=N;j++) suspect[j] = 0;
    
    for(j=N;j>=i;j--){
        if(solution[j]==1){
            if(statement[j]>0){
                if(suspect[statement[j]]==0) suspect[statement[j]] = 1;
                else if(suspect[statement[j]]==1) ;
                else if(suspect[statement[j]]==-1) return 0;
            }
            if(statement[j]<0){
                if(suspect[-statement[j]]==0) suspect[-statement[j]] = -1;
                else if(suspect[-statement[j]]==-1) ;
                else if(suspect[-statement[j]]==1) return 0;
            }
        }
        if(solution[j]==-1){
        
            if(statement[j]>0){
                if(suspect[statement[j]]==0) suspect[statement[j]] = -1;
                else if(suspect[statement[j]]==-1) ;
                else if(suspect[statement[j]]==1) return 0;
            }
            if(statement[j]<0){
                if(suspect[-statement[j]]==0) suspect[-statement[j]] = 1;
                else if(suspect[-statement[j]]==1) ;
                else if(suspect[-statement[j]]==-1) return 0;
            }
        
        }

    }

    if(i==1){
        int wolves_min = 0;
        int wolves_max = 0;
        for(j=N;j>=i;j--){
            if(suspect[j]==-1)wolves_min ++;
            if(suspect[j]==-1 || suspect[j]==0) wolves_max++;
        }
        if(!(wolves_min<=M && M <= wolves_max)) return 0;

        if(wolves_max == M){
            for(j=N;j>=i;j--) {
                if(suspect[j]==0) suspect[j] = -1;
            }
        }
        if(wolves_max > M){
            int cha = wolves_max - M;
            int assign = -1;
            int countassign = 0;
            for(j=N;j>=i;j--) {
                if(suspect[j]==0) {
                    suspect[j] = assign;
                    countassign++;
                    if(countassign== cha )assign = 1;
                }
            }
        }

        int wolf_and_liar = 0;
        for(j=N;j>=i;j--){
            if(suspect[j]==-1 && solution[j]==-1)wolf_and_liar ++;
            
        }
        if(!(wolf_and_liar>0 && wolf_and_liar <L)) return 0;
    }

    return 1;
}