#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char marca[50];
    char modelo[50];
    char cor[20];
    char placa[10];

} veiculo;


FILE *db;
int pos = 0;
char placa[10];

void init() {
    db = fopen("parkif.bin", "wb+");
    fclose(db);
}

void add(veiculo v) {
    // printf("\n[OK]\n");
    db = fopen("parkif.bin", "ab");
    if(db != NULL) {
        fwrite(&v, sizeof(veiculo), 1, db);
        pos++;
    }
    fclose(db);
}

int rem(char *placa) {
    veiculo *dbAux;
    veiculo v;
    int i, j=0, aux=0;
    int ret=1;
    int tCarros = conta_carros();
    
    if(tCarros>0){

        db = fopen("parkif.bin", "rb");    
        dbAux = malloc(tCarros+10 * sizeof(veiculo));

        if(db != NULL) {
            do {
                ret = fread(&v, sizeof(veiculo), 1, db);
                if(ret == 1) {
                    if (strcmp(placa, v.placa)==0){
                        aux++;
                    }else{
                        dbAux[j]=v;
                        j++;
                    }
                }
            } while(ret == 1);
        }
        fclose(db);
        
        init();

        for(i=0; i<j; i++){
            add(dbAux[i]);
        }

        if (aux!=0){
            printf("\n[OK]\n");
        }else{
            printf("\n[ERRO]: Placa nao encontrada!\n");
        }

    }else{
        printf("\n[ERRO]: Não a carros!\n");
    }

    return -1;
}

void view() {
    db = fopen("parkif.bin", "rb");
    veiculo v;
    int ret=1;
    int cont=1;
    printf("\n[VISUALIZACAO DE VEICULO]\n\n");
    if(db != NULL) {
        do {
            ret = fread(&v, sizeof(veiculo), 1, db);
            if(ret == 1) {
              printf("\n%i | %s / %s / %s / %s", cont, v.marca, v.modelo, v.cor, v.placa);
              cont++;
            }
        } while(ret == 1);
    }
    fclose(db);
    printf("\n");
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int conta_carros(){
    db = fopen("parkif.bin", "rb");
    veiculo v;
    int ret=1;
    int cont=1;

    if(db != NULL) {
        do {
            ret = fread(&v, sizeof(veiculo), 1, db);
            if(ret == 1) {
              cont++;
            }
        } while(ret == 1);
    }
    fclose(db);

    return cont;
}

#endif