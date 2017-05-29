#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double Mf=5.9736*pow(10,24);
    double Mh=7.349*pow(10,22);
    double Ra=4.055*pow(10,8);
    double Rp=3.633*pow(10,8);
    double Va=964;
    double Vp=1076;
    double G=6.67384*pow(10,-11);
    double dt=3600;
    double X=Ra;
    double Y=1;
    double Vx=1;
    double Vy=(-1)*Va;
    double sx,sy,ax,ay,E;
    int i,N=3000;
    FILE *fp = fopen("adatok.txt","w");
    FILE *fp2 = fopen("energia.txt","w");
    for(i=0;i<N;i++)
    {

        E=(0.5*Mh*((Vx*Vx)+(Vy*Vy)))+(Mf*Mh*G/((X*X)+(Y*Y)));
        sx=X;
        sy=Y;
        ax=G*Mf*(-sx)/pow(sqrt((sx*sx)+(sy*sy)),3);
        ay=G*Mf*(-sy)/pow(sqrt((sx*sx)+(sy*sy)),3);
        fprintf(fp,"%.0f %.0f\n",X,Y);
        fprintf(fp2,"%.0f %.0f\n",i*dt,E);
        printf("X: %.2f \t Y: %.2f\n",X,Y);
        printf("VX: %.2f \t VY: %.2f\n",Vx,Vy);
        printf("FX: %.2f \t FY: %.2f\n",ax,ay);
        X=X+Vx*dt;
        Y=Y+Vy*dt;
        Vx=Vx+ax*dt;
        Vy=Vy+ay*dt;

    }
    printf("%f\n",G*Mf*(-sx));
    printf("%f\n",pow(sqrt((sx*sx)+(sy*sy)),3));
    close(fp);
    close(fp2);
    return 0;
}
