#include <16f877A.h>
#fuses XT, NOWDT
#use delay (clock=20000000)
#use fast_io(B)
#use fast_io(D)
#include <stdio.h>
#include <string.h>
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8, parity=n)

int x=0;
int r=0,z=0,i,j,k=0,w=32,uj=0;
int b=0;
/*char a[16][3];
char a1[16][3];
char a2[16][3];
char a3[16][3];*/
int string4[]= {1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0};
int string[64];
int uit=0;
int pos1[]={0,0,0};
//int string3[] = {'a',"b","c"};
int string2[] ={1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0};
#INT_EXT
RB0(){
delay_ms(200);

for( j = 0;j < 64;j++)
{
if(string2[j]==1)
{
printf("%u;%u\r\n",j+1,j+1);
k=k+1;
}

if(string2[j]==0)
{
printf("0;0\r\n");

}

//printf("0;0\r\n");
//printf("\r\n");



if(string4[j] != string2[j])
{
if(string2[j]==1)
{
pos1[1]= j;

}
if(string2[j]==0)
{
pos1[0]= j;
}

}
}
printf("88;88\r\n");

if(k<w)
{
pos1[1]=x;
w=w-1;
}
//printf("%u;%u\r\n",k,w);



if (string4[47]==0 & string4[55]==0 & string2[47]==1  & string2[55]==1)
{
uit=1;
printf("65;66\r\n");
delay_ms(200);
}

if (string4[23]==0 & string4[31]==0 & string2[23]==1  & string2[31]==1)
{
uit=1;
printf("67;68\r\n");
delay_ms(200);
}

if(uit!=1){

printf("%u;%u\r\n",pos1[0]+1,pos1[1]+1);
delay_ms(200);
}

for( j = 0;j < 64;j++)
{
string4[j] = string2[j];

}

r=0;
uit=0;
k=0;
}

void main()
{



 enable_interrupts(INT_EXT);
 enable_interrupts(global);



port_b_pullups(TRUE);
set_tris_B(0b11100001);


set_tris_D(0b10000001);

while(1)
{

if(b==0){
output_low(PIN_B1);
output_low(PIN_B2);
output_low(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}

if(b==1){
output_low(PIN_B1);
output_low(PIN_B2);
output_low(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==2){
output_low(PIN_B1);
output_low(PIN_B2);
output_high(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==3){
output_low(PIN_B1);
output_low(PIN_B2);
output_high(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==4){
output_low(PIN_B1);
output_high(PIN_B2);
output_low(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==5){
output_low(PIN_B1);
output_high(PIN_B2);
output_low(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==6){
output_low(PIN_B1);
output_high(PIN_B2);
output_high(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==7){
output_low(PIN_B1);
output_high(PIN_B2);
output_high(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==8){
output_high(PIN_B1);
output_low(PIN_B2);
output_low(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==9){
output_high(PIN_B1);
output_low(PIN_B2);
output_low(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==10){
output_high(PIN_B1);
output_low(PIN_B2);
output_high(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==11){
output_high(PIN_B1);
output_low(PIN_B2);
output_high(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==12){
output_high(PIN_B1);
output_high(PIN_B2);
output_low(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
}
if(b==13){
output_high(PIN_B1);
output_high(PIN_B2);
output_low(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}
if(b==14){
output_high(PIN_B1);
output_high(PIN_B2);
output_high(PIN_B3);
output_low(PIN_B4);
//delay_ms(2000);
};
if(b==15){
output_high(PIN_B1);
output_high(PIN_B2);
output_high(PIN_B3);
output_high(PIN_B4);
//delay_ms(2000);
}

if(input(PIN_B7)==0)
{
string[b]= 0;

}
if(input(PIN_B7)==1)
{
z=z+1;
string[b]= 1;

}

if(input(PIN_B6)==0)
{
string[b+16]= 0;

}
if(input(PIN_B6)==1)
{
z=z+1;
string[b+16]= 1;

}

if(input(PIN_B5)==0)
{
string[b+32]= 0;

}
if(input(PIN_B5)==1)
{
z=z+1;
string[b+32]= 1;

}

if(input(PIN_D0)==0)
{
string[b+48]= 0;

}
if(input(PIN_D0)==1)
{
z=z+1;
string[b+48]= 1;

}

if (input(PIN_D7)==1)
{
delay_ms(200);
printf("87;87\r\n");
uj=1;
for( i = 0;i < 64;i++)
{
if(string2[i]==1)
{
k=k+1;
}
string4[i] = string2[i];

}
if(k<w)
{
//pos1[1]=x;
w=w-1;
}
k=0;
//printf("hola");
}


if(string[b]!=string2[b]  &  string[b]==0  & uj==1)
{
x=b;
uj=0;
//printf("xxx");

//output_high(PIN_B6);
}
if(string[b+16]!=string2[b+16]  &  string[b+16]==0  & uj==1)
{
x=b+16;
uj=0;
//printf("xxx");

//output_high(PIN_B6);
}
if(string[b+32]!=string2[b+32]  &  string[b+32]==0  & uj==1)
{
x=b+32;
uj=0;
//printf("xxx");

//output_high(PIN_B6);
}
if(string[b+48]!=string2[b+48]  &  string[b+48]==0  & uj==1)
{
x=b+48;
uj=0;
//printf("xxx");

//output_high(PIN_B6);
}


b=b+1;
if(b==16){


for( i = 0;i < 64;i++)
{
string2[i] = string[i];


}
b=0;
}




}

}
