#include <stdio.h>
#include <stdlib.h>

int N,M,L;/* N players, M wolves, L liars */


int statement[100];

/* 1:good -1:wolf 0:undetermined*/
int is_wolf[100];

int Backtracking(int N);
int check(int i);

int main(){
    scanf("%d %d %d",&N,&M,&L);
    // N=6;M=2;L=2;
    int i;
    
    for(i=1;i<=N;i++){
        scanf("%d",&statement[i]);
        
        //printf("%d",statement[i]);
    }

    // statement[1] = -2;
    // statement[2] = -1;
    // statement[3] = 2;
    // statement[4] = 4;
    // statement[5] = 6;
    // statement[6] = 5;

    for(i=1;i<=N;i++){
        is_wolf[i] = 0;
    }
    
    int result = Backtracking(N);
    if(!result){
        printf("No Solution");
        return 0;
    }
    int count = 1;
    for(i=N;i>=1;i--){
        if(is_wolf[i] == -1 && count!=M) {
            printf("%d ",i);
            count++;
        }
        else if(is_wolf[i] == -1 && count==M) printf("%d",i);
    }

}

int Backtracking(int player){

    if(player == 0) return 1;

    /* go N with truth */

    is_wolf[player] = -1;
    int OK = check(player);
    if(OK){
        int Found = Backtracking(player-1);
        if(Found) return 1;
        
    }

    is_wolf[player] = 1;
    OK = check(player);
    if(OK){
        int Found = Backtracking(player-1);
        if(Found) return 1;
        
    }


    is_wolf[player] = 0;
    return 0;


}

int check(int i){
    /* check wolf_num */
    int wolf_max = M;
    int human_max = N-M;
    int wolf = 0;
    int human = 0;
    for(int j=N;j>=i;j--){
        if(is_wolf[j]==-1) wolf ++;
        if(is_wolf[j]==1) human ++;
    }
    if(wolf>wolf_max || human>human_max) return 0;


    /* check liars */
    int honest[N+1];   
    for(int j = 1;j<=N;j++) honest[j] = 0;
    
    for(int j = 1;j<=N;j++){
        if(statement[j]<0 && (is_wolf[-statement[j]] == 0)) continue;
        if(statement[j]>0 && (is_wolf[statement[j]] == 0)) continue;

        if(statement[j]<0 && (is_wolf[-statement[j]] == -1)) honest[j] = 1;
        if(statement[j]<0 && (is_wolf[-statement[j]] == 1)) honest[j] = -1;
        if(statement[j]>0 && (is_wolf[statement[j]] == 1)) honest[j] = 1;
        if(statement[j]>0 && (is_wolf[statement[j]] == -1)) honest[j] = -1;
    }

    int liars = 0;
    for(int j=1;j<=N;j++){
        if(honest[j] == -1) liars ++;
    }
    if(liars>L) return 0;
    
    if(i==1 && liars != L) return 0;

    if(i==1){
        int wolf_and_liar = 0;
        for(int j=1;j<=N;j++){
            if(honest[j]==-1 && is_wolf[j]==-1) wolf_and_liar++;
        }
        if(!(0 < wolf_and_liar && wolf_and_liar < M)) return 0;
    }
    return 1;
}