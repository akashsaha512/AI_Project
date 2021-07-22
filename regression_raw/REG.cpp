#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;

float B0,B1,R;
class reg_eqn
{
public:

    int i;
    float a[1000],b[1000],xbar=0,ybar=0,X[1000],Y[1000],XY[1000],XX[1000],sxx=0,sxy=0;

    void get_data(float x[1000],float y[1000]);
    void find_mean();
    void calc();
    void return_value(float z);


};

void reg_eqn :: get_data(float x[1000],float y[1000])
{
    for(i=1;i<=491;i++)
    {
        a[i]=x[i];
        b[i]=y[i];
    }
}





void reg_eqn :: find_mean()
{
    for(i=1;i<=491;i++)
    {
        xbar=xbar+a[i];
        ybar=ybar+b[i];
    }

    xbar=xbar/491.00;
    ybar=ybar/491.00;
}



void reg_eqn :: calc()
{
    for(i=1;i<=491;i++)
    {
       X[i] = a[i] - xbar;
       Y[i] = b[i] - ybar;
       XY[i] = X[i] * Y[i];
       XX[i] = pow(X[i],2);
       sxy = sxy + XY[i];
       sxx = sxx + XX[i];
    }
    B1 = (sxy / sxx);
    B0 = ybar - (B1 * xbar);
}



    void reg_eqn :: return_value(float z)
    {
        R=B0+(B1 * z);
    }

int main()
{
    int i;
    float x[1000],y[1000],z;

    ifstream infile;
    infile.open("input.txt");

    ofstream outfile;
    outfile.open("output.txt");

    for(i=1;i<=491;i++)
    {
        infile>>x[i]>>y[i];
        outfile<<"("<<x[i]<<","<<y[i]<<")"<<' ';
    }

    infile>>z;
    outfile<<endl<<endl<<"Max_Resolution= "<<z;


    reg_eqn bob;
    bob.get_data(x,y);
    bob.find_mean();
    bob.calc();
    bob.return_value(z);


    outfile<<endl<<"B0="<<B0<<endl<<"B1="<<B1<<endl<<"Predicted_Price= "<<R;
    infile.close();
    outfile.close();

    getch();
}
