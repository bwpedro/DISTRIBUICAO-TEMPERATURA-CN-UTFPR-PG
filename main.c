#include <stdio.h>
#include "projeto.h"

int main(){
    int n, nInteracao = 1; 
    float tol, difAnt = 0, dif = 0;
    printf("Valor de n: ");
    scanf("%d",&n);
    printf("Valor da tolerância: ");
    scanf("%f",&tol);

    n = n - 1;

    float m0[n][n], m1[n][n], mDif[n][n];

    // inicializa vetor com 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m0[i][j] = 0;  
            m1[i][j] = 0; 
        }
    }

    do{
        // passa de um vetor para o outro
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m0[i][j] = m1[i][j];
            }
        }
        dif = 0;
        // calcula o valor para todos os pontos
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m1[i][j] = calculaMedia(n, m0, i, j);
                mDif[i][j] = m1[i][j] - m0[i][j];

                if(mDif[i][j] > dif)
                    dif = mDif[i][j];
            }
        }
        printf("\n%d˚ Interação:\n",nInteracao++);
        printf("Tolerância anterior: %f\n",difAnt);
        printf("Tolerância atual: %f\n",dif);
        printf("Tolerância desejada: %f\n",tol);
        difAnt = dif;
    } while(dif > tol);

    printf("\n");


    printf("Valores dos pontos na última interação: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%f ",m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}