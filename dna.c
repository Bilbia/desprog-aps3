#include <stdio.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}


int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    if(n==0 || m==0){
        length[n][m] = 0;
        return length[n][m];
    }

    //se o length ja tiver sido calculado
    if(length[n][m]!=-1){
        return length[n][m];
    }

    //se o length n tiver sido calculado ainda
    if(a[n-1] == b[m-1]){
        length[n][m] = mlcs_w(a,n-1,b,m-1,length) + 1;
        return length[n][m];
    }

    //calcula a subsequencia da esquerda e da direita da arvore
    int esq = mlcs_w(a,n-1,b,m,length);
    int dir = mlcs_w(a,n,b,m-1,length);
    int max = esq;
    if(esq<dir){
        max = dir;
    }
    length[n][m] = max;
    return length[n][m];
}


int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            length[i][j] = -1;
        }
    }
    return mlcs_w(a,n,b,m,length);
}


int dlcs(char a[], int n, char b[], int m) {
    return 2;
}
