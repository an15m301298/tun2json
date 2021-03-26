//xor of 8 bit value
bitset<8> xOr8(uint8_t a1,uint8_t a2)
{
 bitset<8> b1=a1;
 bitset<8> ans;
 bitset<8> b2=a2;
 int carry_bit=0;
 int temp_ans;
 int carry_bit_ans;
 
 int x=0;
 while(x<8)
 {
  
   

   carry_bit_ans=(carry_bit+b1[x]);
   if(carry_bit_ans>1)
   {
    carry_bit=1;
    carry_bit_ans=0;
    
   }
   else
   {
    carry_bit=0;
    
   }
   
   
   temp_ans=(carry_bit_ans+b2[x]);
  if(temp_ans>1)
   {
    carry_bit=1;
    ans[x]=0;
    
  
   }
   else
   {
   
    ans[x]=temp_ans;

   }
 
 x++;
 
 //check if carry value is present
 if((x==8)&&(carry_bit==1))
  {
    /
    b1=ans;
    carry_bit=0;
    b2=1;
    x=0;
  }
 
 }
 
//combined xor answer
 return ans;
}
//end of 8bit xor

//xor of 16 bit value
bitset<16> xOr8(uint16_t a1,uint16_t a2)
{
 bitset<16> b1=a1;
 bitset<16> ans;
 bitset<16> b2=a2;
 int carry_bit=0;
 int temp_ans;
 int carry_bit_ans;
 
 int x=0;
 while(x<16)
 {
  
   

   carry_bit_ans=(carry_bit+b1[x]);
   if(carry_bit_ans>1)
   {
    carry_bit=1;
    carry_bit_ans=0;
    
   }
   else
   {
    carry_bit=0;
    
   }
   
   
   temp_ans=(carry_bit_ans+b2[x]);
  if(temp_ans>1)
   {
    carry_bit=1;
    ans[x]=0;
    
  
   }
   else
   {
   
    ans[x]=temp_ans;

   }
 
 x++;
 
 //check if carry value is present
 if((x==16)&&(carry_bit==1))
  {
    /
    b1=ans;
    carry_bit=0;
    b2=1;
    x=0;
  }
 
 }
 
//combined xor answer
 return ans;
}
//end of 16bit xor

