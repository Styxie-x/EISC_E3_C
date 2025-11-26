#include "fonction/fonction.h"

void exo1(){
    printf("\nexo 1 \n");
    int * p;
    p = 0;
    // *p = 4;
    // printf("%d",*p);
    printf("the problem was segmentation error where we are trying to assign a value to null pointer. Here is the output of corrected code :");
    p = (int *)malloc(sizeof(int));
    *p = 4;
    printf("%d\n", *p);
    free(p);
}

void exo2(){
    printf("\nexo 2 \n");
    int *p1, *p2;
    p1 = (int *)malloc(sizeof(int)*100);
    for(uint8_t i = 0; i< 100; i++){
        p1[i] = i;
    }
    for(uint8_t i = 0; i< 100; i++){
        printf("%d; ", p1[i]);
    }
    printf("\n\n");
    p2 = p1;
    for(uint8_t i = 0; i< 100; i++){
        p2[i] = p2[i]*2;
    }
    for(uint8_t i = 0; i< 100; i++){
        printf("%d; ", p1[i]);
    }
    printf("\n");
    free(p2);
}

void exo3(){
    printf("\nexo 3 \n");
    float tabs[100];

    for(uint8_t i = 0; i<100; i++){
        tabs[i] = (i*0.01 - 0.5)* (i*0.01 - 0.5) + 7;
         printf("%f; ", tabs[i]);
    }
    tabs[3] = -100;
    printf("\n ---------------------------------------- minimum value of static table is :%f \n\n", min(tabs,100));

    float *tabd;
    tabd = (float *)malloc(sizeof(float)*100);

    for(uint8_t i = 0; i<100; i++){
        tabd[i] = (i*0.01 - 0.5)* (i*0.01 - 0.5) + 7;
        printf("%f; ", tabd[i]);
    }
    printf("\n ---------------------------------------- minimum value of dynamic table is : %f  \n\n", min(tabd,100));
}

void exo4(){
    printf("\n exo4 \n");
    int size = 15;
    float value = 3.0;
    float* tab = create_tab(size, value);
    for(uint8_t i = 0; i< size; i++){
        printf("%f, ", tab[i]);
    }
    printf("\n");
}


float min(float* p,int N){ // since weare using it for "parabol" it'll work but min function is wrong.
    float p_v_p = p[0];
    for(int i = 0; i< N; i++){
        p_v_p = p[i];
        for(int j = 0; j < N; j++){
            if(p[j] < p_v_p){
             p_v_p = p[j];
            }
        }
    }
    return p_v_p;
}


float *create_tab(int size, float value){
    float *tab;
    tab = (float *)malloc(sizeof(float)*size);

    if (tab != NULL) { /* succeeded */
        for(int i = 0; i < size; i++){
            tab[i] = value;
            printf("%f, ", tab[i]);
        }
        printf("\n");
    return tab;
    }
    else {   /* failed */
      printf("Memory allocation failed\n");
      return NULL;
    }
}

void exo5(){
    printf("\n exo5 \n");
    int N = 5;
    int tab1[N] = {1,0,3,0,8};
    int *p;
    p = create_double(tab1, N);

    for(int i = 0; i<N; i++){
        printf("%d, ", p[i]);
    }
    printf("\n");
    
}

int *create_double(const int* tab, int N){
    int *d_tab;
    d_tab = (int *)malloc(sizeof(int)*N);
    
    for(int i = 0; i<N; i++)
    {
        d_tab[i] = tab[i];
    }
    return d_tab;
}

