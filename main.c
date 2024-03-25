#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 10

void set_boundary(int object[][max_size]);
void printObject_position(int object[][max_size]);
int genrateRandomObject(char temp, int rand_xPos, int rand_yPos, int x_axis, int y_axis, int max_index , int object[][max_size], int score );


int main(){

    printf("Use 'w', 'a', 's', 'd' keys to move within the boundaries.\n");
    printf("Press 'x' to exit.\n");

    srand(time(NULL));//initialize random seed
    int object[max_size][max_size];

    set_boundary(object);

    char key_input , end_game;
    bool flag = true ;


    int x_axis = max_size/2 , y_axis=max_size/2;// location of the object
    object[x_axis][y_axis]='X';

    printObject_position(object);

    int max_index= max_size-2;
    int min_index=1;

    // generates o randomly
    int rand_xPos= 1+ rand() % (max_index);
    int rand_yPos= 1+rand()%(max_index);
    object[rand_xPos][rand_yPos]='o';

    int score =0; // initializing score with 0
    char temp= object[x_axis][y_axis];

    while(1) {
        scanf(" %c", &key_input);

        score=  genrateRandomObject(temp, rand_xPos, rand_yPos, x_axis, y_axis, max_index, object, score);
        printf("\nSCORE:%d\n", score);

            switch (key_input) {
                case 'w':
                    if (x_axis > min_index) {
                        object[x_axis][y_axis] = ' ';
                        x_axis--;
                        temp = object[x_axis][y_axis];
                        object[x_axis][y_axis] = 'X';
                    } else {
                        flag = false;
                    }
                    break;

                case 'a':
                    if (y_axis > min_index) {
                        object[x_axis][y_axis] = ' ';
                        y_axis--;
                        temp = object[x_axis][y_axis];
                        object[x_axis][y_axis] = 'X';
                    } else {
                        flag = false;
                    }
                    break;

                case 's':
                    if (x_axis < max_index) {
                        object[x_axis][y_axis] = ' ';
                        x_axis++;
                        temp = object[x_axis][y_axis];
                        object[x_axis][y_axis] = 'X';
                    } else {
                        flag = false;
                    }
                    break;

                case 'd':
                    if (y_axis < max_index) {
                        object[x_axis][y_axis] = ' ';
                        y_axis++;
                        temp = object[x_axis][y_axis];
                        object[x_axis][y_axis] = 'X';
                    } else {
                        flag = false;
                    }
                    break;
                case 'x':
                    printf("\nExiting...\n");
                    printf("\nTotal score : %d\n", score);
                    printf("\nDo you want to exit game '(y/n)'\n");
                    scanf(" %c", &end_game);
                    if (end_game == 'y') {
                        printf("\nTotal score : %d\n", score);
                        return 0;
                    } else if(end_game=='n'){
                        printf("\nResuming..\n");
                    }
                    else{
                        printf("\nEnter the the correct key\n");
                    }
                    break;
                default:
                    printf("\nYou have pressed the wrong key\n");

            }

            printObject_position(object);

        if ( !flag ) {
            printf("\nOops!! You have touched the boundary\n");
            printf("Total score : %d", score);
            break;
        }


    }
    }





void set_boundary(int object[][max_size]){
    for (int i = 0; i < max_size; ++i) {
        for (int j = 0; j <max_size ; ++j) {
            if(i==0 || i==max_size-1 || j==0 || j== max_size-1){
                object[i][j]='#';
            } else{
                object[i][j]=' ';
            }
        }
        printf("\n");
    }
}


void printObject_position(int object[][max_size]){
    for (int i = 0; i <max_size ; ++i) {
        for (int j = 0; j <max_size ; ++j) {
            printf("%c\t", object[i][j]);
        }
        printf("\n");
    }
}


int genrateRandomObject(char temp, int rand_xPos, int rand_yPos, int x_axis, int y_axis, int max_index , int object[][max_size], int score ){

    if (temp == 'o') {
        score++;
        object[x_axis][y_axis] = ' ';
        do {
            rand_xPos = 1 + rand() % (max_index);
            rand_yPos = 1 + rand() % (max_index);
        } while (object[rand_xPos][rand_yPos] != ' ');
        object[rand_xPos][rand_yPos] = 'o';
    }
    return score;
}




