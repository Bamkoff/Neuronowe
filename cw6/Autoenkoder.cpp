#define _USE_MATH_DEFINES 
#include <iostream> 
#include <math.h> 
#include <stdlib.h> 
#define EPSILON 0.001 
#define BETA 1 
#define STALA_C 0.8 
  
using namespace std; 
  
double fRand(double fMin, double fMax) 
{ 
    double f = (double)rand() / RAND_MAX; 
    return fMin + f * (fMax - fMin); 
} 
  
double f(double u) 
{ 
    double tym = pow(M_E, -BETA*u); 
    tym = tym + 1; 
    return 1/tym; 
} 
  
double Df(double u) 
{ 
    double tym = 1-f(u); 
    return BETA * f(u) * tym; 
} 
  
double f_1(double u) 
{ 
    if(u<0) return 0; 
    else return 1; 
} 
  
int main() 
{ 
    double x[3][25]; 
    for(int a=0;a<3;a++) 
    { 
        for(int k=0;k<3;k++) 
        { 
            x[a][k] = 0; 
        }     
    } 
     
    x[0][7] = 1; 
    x[0][8] = 1; 
    x[0][12] = 1; 
    x[0][17] = 1; 
    x[0][22] = 1; 
    x[1][2] = 1; 
    x[1][3] = 1; 
    x[1][8] = 1; 
    x[1][13] = 1; 
    x[2][5] = 1; 
    x[2][6] = 1; 
    x[2][11] = 1; 
    x[2][16] = 1; 
    x[2][21] = 1; 
     
    double xp[3][25]; 
    double xpp[3][25]; 
    double y[3][16]; 
     
    double w_old[16][25]; 
    double w_new[16][25]; 
    double b_old[16]; 
    double b_new[16]; 
    double wp_old[25][16]; 
    double wp_new[25][16]; 
    double bp_old[25]; 
    double bp_new[25]; 
     
    double DE_w[16][25]; 
    double DE_wp[25][16]; 
    double DE_b[16]; 
    double DE_bp[25]; 
     
    for(int i=0;i<16;i++) 
    { 
        b_old[i] = fRand(-0.5 , 0.5); 
        for(int k=0;k<25;k++) 
        { 
            w_old[i][k] = fRand(-0.5 , 0.5); 
        } 
    } 
     
    for(int k=0;k<25;k++) 
    { 
        bp_old[k] = fRand(-0.5 , 0.5); 
        for(int i=0;i<16;i++) 
        { 
            wp_old[k][i] = fRand(-0.5 , 0.5); 
        } 
    } 
    bool warunek = false;  
     
    do 
    { 
        for(int a=0;a<3;a++) 
        { 
            for(int i=0;i<16;i++) 
            { 
                double tym = 0; 
                for(int j=0;j<25;j++) 
                { 
                    tym += w_old[i][j] * x[a][j] + b_old[i]; 
                } 
                y[a][i] = f(tym); 
            } 
        } 
        for(int a=0;a<3;a++) 
        { 
            for(int k=0;k<25;k++) 
            { 
                double tym = 0; 
                for(int i=0;i<16;i++) 
                { 
                    tym += wp_old[k][i] * y[a][i] + bp_old[k]; 
                } 
                xp[a][k] = f(tym); 
            } 
        } 
         
        for(int p=0;p<16;p++) 
        { 
            for(int q=0;q<25;q++) 
            { 
                DE_w[p][q] = 0; 
                for(int a=0;a<3;a++) 
                { 
                    double tym = 0; 
                    for(int k=0;k<25;k++)  
                    { 
                        double tym_i = 0; 
                        double tym_j = 0; 
                        for(int i=0;i<16;i++) 
                        { 
                            tym_i += wp_old[k][i] * y[a][i] + bp_old[k]; 
                        } 
                        for(int j=0;j<25;j++) 
                        { 
                            tym_j += w_old[p][j] * x[a][j] + b_old[p]; 
                        } 
                        double tym2 = xp[a][k] - x[a][k]; 
                        tym += tym2 * Df(tym_i) * wp_old[k][p] * Df(tym_j) * x[a][q]; 
                    } 
                DE_w[p][q] += tym; 
                } 
            } 
        } 
         
        for(int p=0;p<25;p++) 
        {     
            for(int q=0;q<16;q++) 
            { 
                DE_wp[p][q] = 0; 
                for(int a=0;a<3;a++) 
                { 
                     
                    double tym_i = 0; 
                     
                    for(int i=0;i<16;i++) 
                    { 
                        tym_i += wp_old[p][i] * y[a][i] + bp_old[p]; 
                    } 
                    double tym = xp[a][p] - x[a][p]; 
                    DE_wp[p][q] += tym * Df(tym_i) * y[a][q]; 
                }     
            } 
        } 
         
        for(int p=0;p<16;p++) 
        { 
            DE_b[p] = 0; 
            for(int a=0;a<3;a++) 
            { 
                double tym_k = 0; 
                for(int k=0;k<25;k++)  
                { 
                    double tym_i = 0; 
                    double tym_j = 0; 
                    for(int i=0;i<16;i++) 
                    { 
                        tym_i += wp_old[k][i] * y[a][i] + bp_old[k]; 
                    } 
                    for(int j=0;j<25;j++) 
                    { 
                        tym_j += w_old[p][j] * x[a][j] + b_old[p]; 
                    } 
                    double tym = xp[a][k] - x[a][k]; 
                    tym_k += tym * Df(tym_i) * wp_old[k][p] * Df(tym_j); 
                } 
                DE_b[p] += tym_k; 
            } 
        } 
         
        for(int p=0;p<25;p++) 
        {     
            DE_bp[p] = 0; 
            for(int a=0;a<3;a++) 
            { 
                double tym_i = 0; 
                for(int i=0;i<16;i++) 
                { 
                    tym_i += wp_old[p][i] * y[a][i] + bp_old[p]; 
                } 
                double tym = xp[a][p] - x[a][p]; 
                DE_bp[p] += tym * Df(tym_i); 
            } 
        } 
         
        warunek = false; 
         
        for(int i=0;i<16;i++) 
        { 
            b_new[i] = b_old[i] - STALA_C * DE_b[i]; 
             
            if(b_new[i]>b_old[i]) 
            { 
                if(b_new[i] - b_old[i] > EPSILON) warunek = true; 
            } 
            else 
            { 
                if(b_old[i] - b_new[i] > EPSILON) warunek = true; 
            } 
             
            for(int j=0;j<25;j++) 
            { 
                w_new[i][j] = w_old[i][j] - STALA_C * DE_w[i][j]; 
                 
                if(w_new[i][j]>w_old[i][j]) 
                { 
                    if(w_new[i][j] - w_old[i][j] > EPSILON) warunek = true; 
                } 
                else 
                { 
                    if(w_old[i][j] - w_new[i][j] > EPSILON) warunek = true; 
                } 
            } 
        } 
         
         
        for(int i=0;i<25;i++) 
        { 
            bp_new[i] = bp_old[i] - STALA_C * DE_bp[i]; 
             
            if(bp_new[i]>bp_old[i]) 
            { 
                if(bp_new[i] - bp_old[i] > EPSILON) warunek = true; 
            } 
            else 
            { 
                if(bp_old[i] - bp_new[i] > EPSILON) warunek = true; 
            } 
             
            for(int j=0;j<16;j++) 
            { 
                wp_new[i][j] = wp_old[i][j] - STALA_C * DE_wp[i][j]; 
                 
                if(wp_new[i][j]>wp_old[i][j]) 
                { 
                    if(wp_new[i][j] - wp_old[i][j] > EPSILON) warunek = true; 
                } 
                else 
                { 
                    if(wp_old[i][j] - wp_new[i][j] > EPSILON) warunek = true; 
                } 
            } 
        } 
        if(warunek) 
        { 
            for(int i=0;i<16;i++) 
            { 
                b_old[i] = b_new[i]; 
                for(int j=0;j<25;j++) 
                { 
                    w_old[i][j] = w_new[i][j]; 
                } 
            } 
            for(int i=0;i<25;i++) 
            { 
                bp_old[i] = bp_new[i]; 
                for(int j=0;j<16;j++) 
                { 
                    wp_old[i][j] = wp_new[i][j]; 
                } 
            } 
        } 
    }while(warunek); 
     
    for(int a=0;a<3;a++) 
        { 
            for(int i=0;i<16;i++) 
            { 
                double tym = 0; 
                for(int j=0;j<25;j++) 
                { 
                    tym += w_new[i][j] * x[a][j] + b_new[i]; 
                } 
                y[a][i] = f(tym); 
            } 
        } 
     
    for(int a=0;a<3;a++) 
    { 
        int licznik = 0; 
        for(int k=0;k<25;k++) 
        { 
            double tym = 0; 
            for(int i=0;i<16;i++) 
            { 
                tym += wp_new[k][i] * y[a][i] + bp_new[k]; 
            } 
            xpp[a][k] = f_1(tym); 
             
            if(licznik == 5)  
            { 
                cout<<endl; 
                licznik = 0; 
            } 
            if(xpp[a][k] == 0) cout<<" "; 
            else cout<<"#"; 
            licznik++; 
        } 
        cout<<endl<<endl; 
    } 
     
    return 0; 
}
