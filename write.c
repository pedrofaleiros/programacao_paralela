#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE * file = fopen("tempos.txt", "w");

    

    fclose(file);

    return 0;
}