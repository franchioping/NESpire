#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <libndls.h>

void util_stuff();


int KEYS_TO_QUIT = 2;

void util_stuff(){

    printf("Hello World!\n");
    puts("TEST");


    for(int i = 0; i < KEYS_TO_QUIT; i++){
        wait_key_pressed();
    }
    return;
}