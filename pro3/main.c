#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fruit.h"

void scan_tip(database my_db);
void scan_price(database my_db);
void print_output(database my_db);

int main(){
    /* N, the number of tips, and M, the number of fruits in the basket*/
    int N,M;

    //scanf("%d %d",&N,&M);
    N=16;M=20;

    /* initialize the database */
    database my_db;
    my_db = Initialize(M);


    /* scan the tip to record the information of eating rules */
    int i;
    for(i=0;i<N;i++){
        scan_tip(my_db);
    }

    /* scan the price */

    for(i=0;i<M;i++) scan_price(my_db);


    /* get pair information */
    print_output(my_db);

}

void scan_tip(database my_db){
    char name1[4],name2[4];
    scanf("%s %s",name1,name2);

    int id1,id2;

    int i;
    /* find the id */
    for(i=1;i<=my_db->num_of_fruit;i++){
        if(!strcmp(my_db->single_fruit[i].name,name1)) id1 = i;
        if(!strcmp(my_db->single_fruit[i].name,name2)) id2 = i;
    }

    /* set relation value */
    my_db->relation[id1][id2] = 0;
    my_db->relation[id2][id1] = 0;

}

void scan_price(database my_db){
    char name[4];
    int price;
    scanf("%s %d",name,&price);

    int id;

    int i;

    /* find the id */
    for(i=1;i<=my_db->num_of_fruit;i++){
        if(!strcmp(my_db->single_fruit[i].name,name)){
            id = i;
            break;
        } 
    }

    /* set price value */
    my_db->single_fruit[id].price = price;
}

void print_output(database my_db){
    pair_database my_pair_base;
    my_pair_base = could_be_eaten_together(my_db);

    


    int i;

    /* 函数过程中记录的最大的组合数字 */
    int max_fruit_num=0;

    /* 函数过程中记录的最大组合的pair的id */
    int max_id=0;

    /* 函数过程中临时记录的价格和 */
    int price_sum=0;

    /* 函数过程中记录的最大组合的价格和 */
    int max_price_sum=0;



    for(i=0;i<my_pair_base->pair_num;i++){

        /* 先计算价格和 */
        price_sum = 0;
        for(int j=0;j<my_pair_base->pair[i].number_of_fruit;j++){
            int id = my_pair_base->pair[i].id_of_fruit[j];
            price_sum += my_db->single_fruit[id].price;
        }

        
        /* 更新最新的max_id */
        if(max_fruit_num < my_pair_base->pair[i].number_of_fruit){
            max_fruit_num = my_pair_base->pair[i].number_of_fruit;
            max_id = i;
            max_price_sum = price_sum;
        }
        /* 如果有tie，那么根据价格高低来决定选择哪一个 */
        else if(max_fruit_num == my_pair_base->pair[i].number_of_fruit){
            if(max_price_sum < price_sum);
            else if(max_price_sum > price_sum){
                max_id = max_fruit_num;
                max_price_sum = price_sum;
            }
        }

    }



    printf("%d\n",max_fruit_num);
    for(i=0;i<max_fruit_num;i++){
        int this_id = my_pair_base->pair[max_id].id_of_fruit[i];
        printf("%s ", my_db->single_fruit[this_id].name);

    }
    printf("\n");

    printf("%d\n",max_price_sum);

}