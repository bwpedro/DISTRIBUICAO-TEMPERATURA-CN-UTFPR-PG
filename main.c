#include <stdio.h>
#include "projeto.h"

int main(){
    int n, nInteracao = 1; 
    float tol, max = 0, maxAnt = 0, dif = 0;
    printf("Valor de n: ");
    scanf("%d",&n);
    printf("Valor da tolerância: ");
    scanf("%f",&tol);

    n = n - 1;

    float m0[n][n], m1[n][n], mMax[n][n];

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
        
        // calcula o valor para todos os pontos
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m1[i][j] = calculaMedia(n, m0, i, j);
                if(m0[i][j] >= m1[i][j])
                    mMax[i][j] = m0[i][j];
                else
                    mMax[i][j] = m1[i][j];
                if(mMax[i][j] > max)
                    max = mMax[i][j]; 
            }
        }
        printf("\n%d˚ Interação:\n",nInteracao++);
        printf("Máximo anterior: %f\n",maxAnt);
        printf("Máximo atual: %f\n",max);
        printf("Tolerância atual: %f\n",dif);
        printf("Tolerância desejada: %f\n",tol);
        dif = max - maxAnt;
        maxAnt = max;
    } while(dif > tol);

    printf("\n");
}