#include<stdio.h>
#include<limits.h>
#include<math.h>
void print_float_hex_to_dec(unsigned a)
{
    unsigned x,y,z;
    int i,j;
    double k;
    x = (a << 9) >> 9;
    y = ((a << 1) >> 24 ) -127;
    z =  a >> 31;
    for(i = j = k = 0; i < 23 ; i++)
    {
        j = (a >> i) & 0x1;
        k += j * pow(2,i - 23);
    }
    k += 1;
    k *= pow(2,y);
    k *= pow(-1,z);
    printf("%f\n",k);
}
void print_fraction_dec_to_bin(double pi)
{
    printf("0.");
    int i;
    pi = pi - (int)(pi);
    i = 0;
    while(i++ < 20)
    {
        if(pi < 0.5){
            printf("0");
            pi *= 2;
        }
        else
        {
            printf("1");
            pi = (pi) * 2 - 1;
        }
    }
    printf("\n");
}
main()
{
    unsigned a = 0x40490FDB;
    print_float_hex_to_dec(a);
    print_fraction_dec_to_bin(22.0/7);
    print_fraction_dec_to_bin(223.0/71);
}
