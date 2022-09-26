#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 101
#define default_price 0

/* one fruit contain a 3-digit name and a price*/
typedef struct fruit{
    int id;
    char name[4];
    int price;
}FRUIT;

/* form a database of fruits
 * 
 * num_of_fruit is obviously what it meant
 * single_fruit is the array of the fruits
 * if relation[A][B] == 0 then they are not together-eaten
 * if relation[A][B] == 1 then they can be eaten together
 * order doesn't matter. relation[A][B] == relation[B][A]
 * 
 */
typedef struct fruit_Data{
    int num_of_fruit;
    FRUIT single_fruit[MAX];
    int relation[MAX][MAX];
}fruit_database; 

typedef fruit_database* database;




/* Initialize the database to contian M fruit and set default value */
/* 这个已经写完了 */
database Initialize(int M);



/* 
 * pair stores the information of the possible pairs
 * pair_database is the collection of pairs.
 * 
 */
typedef struct possible_pair{
    int number_of_fruit;
    int id_of_fruit[MAX];
}p_pair;

typedef struct{
    p_pair pair[MAX];
    int pair_num;
}* pair_database;




/* get the database, return the part where these could */
/* 就写这个函数 */
pair_database could_be_eaten_together(database db);

