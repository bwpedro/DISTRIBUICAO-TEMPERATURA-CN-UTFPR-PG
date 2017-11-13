#include <stdio.h>
#include "projeto.h"

float elemEsq(int n, float m0[][n], int i, int j){
    if(i - 1 < 0)
        return 25.0;
    else
        return m0[i-1][j];
}

float elemDir(int n, float m0[][n], int i, int j){
    if(i + 1 == n)
        return 20.0;
    else
        return m0[i+1][j];
}

float elemCima(int n, float m0[][n], int i, int j){
    if(j - 1 < 0)
        return 20.0;
    else
        return m0[i][j-1];
}

float elemBaixo(int n, float m0[][n], int i, int j){
    if(j + 1 == n)
        return 30.0;
    else
        return m0[i][j+1];
}

float calculaMedia(int n, float m0[][n], int i, int j){
    float media = 0;

    media += elemEsq(n, m0, i, j);
    media += elemDir(n, m0, i, j);
    media += elemCima(n, m0, i, j);
    media += elemBaixo(n, m0, i, j);

    media = media / 4;

    return media;
}