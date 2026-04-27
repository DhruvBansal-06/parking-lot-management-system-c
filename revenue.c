#include<stdio.h>
float revenue(char out[],char in[],int x)
{
    int h1,h2,m1,m2;
    h1 = (in[0]-'0')*10 + (in[1]-'0');
    m1 = (in[3]-'0')*10 + (in[4]-'0');
    h2 = (out[0]-'0')*10 + (out[1]-'0');
    m2 = (out[3]-'0')*10 + (out[4]-'0');
    if (h1 > h2)
    {
        h2 = h2 + 24;
    }
    int total_in = h1*60 + m1;
    int total_out = h2*60 + m2;
    int diff = total_out - total_in;
    return (diff / 60.0) * x;
}