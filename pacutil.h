#include<stdio.h>
#include<arpa/inet.h>
#include<jni.h>
#include<sstream>


//makes a string from input number
std::string mkstr(uint num)
{
std::string st;
std::stringstream str;
str<<num;

str>>st;
return st;
}
//end of string from uint

//calculte 16bit checksum
//from Doug Currie stack overflow
uint16_t genChecksum16(uint8_t *buf)
{
int len=sizeof(buf);
uint16_t Checksum;
int i=0;
 while(len>0)  //len = Total num of bytes
{
    Checksum = ((buf[i]<<8) + buf[i+1]) + Checksum; //get two bytes at a time and  add previous calculated checsum value

    len -= 2; //decrease by 2 for 2 byte boundaries
    i += 2;
}

 Checksum = (Checksum>>16) + Checksum; //Add the carryout

 Checksum = (unsigned int)~Checksum;
  
return Checksum;  
}
//end of 16bit checksum fx






//combines 2 8bit array values to form a 16bit value
uint16_t memAdd16(jbyte *food)
{
 uint16_t *data;

data=(uint16_t*)(food);

return ntohs(*data);
}
//end of buffer adder

//returns an ipv4 representation of a long ip
const char* ipmake(uint ipint)
{
  in_addr sin;
//sin.s_addr=(639703144);

sin.s_addr=(ipint);

 return (inet_ntoa(sin));
}

//make string of raw bytes
std::string fixit(uint8_t arrd[],uint sz)
{
 uint sp=0;
 std::stringstream sst;
 std::string readi;
 while(sp<sz)
 {
  sst<<(+arrd[sp]);
  sp++; 
 }
 
 sst>>readi;
return readi; 
}
//___end of function


//packet filler initial uint8_t==jbyte
void  filler(uint8_t *src_arr,uint8_t dest_arr[],int size)
{
  
  int sz=size;
  //cout<<"size: "<<sz<<"\n\n";
  
  for(int x=0;x<sz;x++)
  {
   dest_arr[x]=src_arr[x];
  }
  
  
}

//half split and reverse a byte in memory
jbyte devo(jbyte de)
{

union bitt
{
  struct nobit
{
  uint a:4;
  uint b:4;
 
}nb;
  
 uint8_t no;
}byt,cach;
  byt.no=de;
  cach.nb.a=byt.nb.b;
  cach.nb.b=byt.nb.a;
  //save IHL
 // ihl=byt.nb.a;
  return cach.no;
}

//remove empty space from string and replace with .
void cstr_fix(char arr[],int ds)
{
 uint sz=0;
 uint d_off=(ds-8);
 while(sz<(d_off))
 {
  if(arr[sz]==' ')
  {
    arr[sz]='.';
  }
  
  sz++;
 }

}
//end if str fix



//half split and reverse memory of 8 bits
jbyte revo(jbyte de)
{

union bitt
{
  struct nobit
{
  uint a:4;
  uint b:4;
 
}nb;
  
 uint8_t no;
}byt,cach;
  byt.no=de;
  cach.nb.a=byt.nb.b;
  cach.nb.b=byt.nb.a;
  //save IHL
  return cach.no;
}


//reverse 8 bits
uint8_t binrevo(jbyte de)
{
 union bitt
{
  struct nobit
{
  uint a:1;
  uint b:1;
  uint c:1;
  uint d:1;
  uint e:1;
  uint f:1;
  uint g:1;
  uint h:1;
   
}nb;
  uint8_t no;
}byt,cach;

  byt.no=de;
  
  //cout.operator<<(byt.no)<<endl;
  cach.nb.a=byt.nb.h;
  cach.nb.b=byt.nb.g;
  cach.nb.c=byt.nb.f;
  cach.nb.d=byt.nb.e;
  cach.nb.e=byt.nb.d;
  cach.nb.f=byt.nb.c;
  cach.nb.g=byt.nb.b;
  cach.nb.h=byt.nb.a;
  
  return cach.no;
}

uint8_t* arr_revo8(uint8_t)
{
  
}



//make string of raw bytes with chars added
std::string stringa(uint8_t arrd[],uint sz)
{
  uint sp=0;
 std::stringstream sst;
 std::string readi;
 while(sp<sz)
 {
  
  if(arrd[sp]>32&&(+arrd[sp])<127)
 {
  
  sst<<binrevo(arrd[sp]);
 }
 else
 {
  sst<<+binrevo(arrd[sp]);
  }
  sp++; 
 }
  
 sst>>readi;
 return readi;
}

//end of function



