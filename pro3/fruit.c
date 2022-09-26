#include "fruit.h"




/* 注意 fruit 从 001开始标序号 */

database Initialize(int M){
    database my_db;
    my_db = (database)malloc(sizeof(*my_db));

    my_db->num_of_fruit = M;

    int i;
    for(i=1;i<=M;i++){
        my_db->single_fruit[i].id = i;
        my_db->single_fruit[i].price = default_price;
        if(i<10){
            sprintf(my_db->single_fruit[i].name,"00%d",i);
            // my_db->single_fruit[i].name[0] = 0;
            // my_db->single_fruit[i].name[1] = 0;
            // my_db->single_fruit[i].name[2] = (char)i;
            // my_db->single_fruit[i].name[3] = '\0';
        }
        else if(10<=i&&i<100){
            sprintf(my_db->single_fruit[i].name,"0%d",i);
            // my_db->single_fruit[i].name[0] = 0;
            // my_db->single_fruit[i].name[1] = (char)(i/10);
            // my_db->single_fruit[i].name[2] = (char)(i%10);
            // my_db->single_fruit[i].name[3] = '\0'; 
        }
        else if(i==100){
            strcpy(my_db->single_fruit[i].name,"100");
            // my_db->single_fruit[i].name[0] = 1;
            // my_db->single_fruit[i].name[1] = 0;
            // my_db->single_fruit[i].name[2] = 0;
            // my_db->single_fruit[i].name[3] = '\0';
        }
        
    }

    int j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++) my_db->relation[i][j] = 1;
    }

    /* for test */

    // printf("%d\n",my_db->num_of_fruit);
    // printf("%d\n",my_db->single_fruit[13].id);
    // printf("%d\n",my_db->single_fruit[12].price);
    // printf("%s\n",my_db->single_fruit[10].name);

    return my_db;
}


/* 输出说明：
 * pair_db标号从0开始，共有pair_num个
 * 不需要排序，只需要存储
 * 以下就是一个存储了3个pair，分别是{001,002,003},{001,002,003,004},{001,002,003,004,005}三对，
 * 已经过测试，会输出第三对，并且价格为16
 */

pair_database could_be_eaten_together(database db){
    pair_database pair_db;
    pair_db = (pair_database)malloc(sizeof(*pair_db));



    /* 以下仅为测试案例 */
    pair_db->pair_num = 3;
    pair_db->pair[0].number_of_fruit = 3;
    for(int i = 0;i<3;i++){
        pair_db->pair[0].id_of_fruit[i] = i+1;
    }

    pair_db->pair[1].number_of_fruit = 4;
    for(int i = 0;i<4;i++){
        pair_db->pair[1].id_of_fruit[i] = i+1;
    }

    pair_db->pair[2].number_of_fruit = 5;
    for(int i =0;i<5;i++){
        pair_db->pair[2].id_of_fruit[i] = i+1;
    }
    
    /* 以上为测试案例 */

    return pair_db;
}