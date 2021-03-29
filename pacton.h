#include<iostream>
#include<jni.h>
#include "pacton2.h"

struct ip_header
{
 uint version:4;
 uint IHL:4;
 uint DSCP:6;
 uint ECN:2;
 uint total_len:16;
 
 uint id:16;

 //uint flags:3;
 uint resv:1;
 uint df:1;
 uint mf:1;
 uint frag_offset:13;

 
 uint ttl:8;
 uint proto:8;
 uint check_sum:16;
 
 uint src_ip:32;
 
 uint dest_ip:32;
 

};


struct pseudo_ip_header
{
 uint version:4;
 uint IHL:4;
 uint DSCP:6;
 uint ECN:2;
 uint total_len:16;
 
 uint id:16;

 //uint flags:3;
 uint resv:1;
 uint df:1;
 uint mf:1;
 uint frag_offset:13;

 
 uint ttl:8;
 uint proto:8;
// uint check_sum:16;
 
 uint src_ip:32;
 
 uint dest_ip:32;
 

};



struct udp_header
{
  uint src_port:16;
  uint dest_port:16;
  uint udp_length:16;
  uint chck_sum:16;
  uint8_t udp_data[];
  
};

struct tcp_header
{
 uint src_port:16;
 uint dest_port:16;
 
 uint ack_no:32;
 
 uint data_offset:4;
 uint resr:3;
 uint ns:1;
 uint cwr:1;
 uint ece:1;
 uint urg:1;
 uint ack:1;
 uint psh:1;
 uint rst:1;
 uint syn:1;
 uint fin:1;
 uint win_size:16;
 
 uint chck_sum:16;
 uint urg_ptr:16;
 
 
 jbyte data[];
// uint opt:32;
 
};

struct pseudo_tcp_header
{
 uint src_port:16;
 uint dest_port:16;
 
 uint src_no:32;
 uint ack_no:32;
 
 uint data_offset:4;
 uint resr:3;
 uint ns:1;
 uint cwr:1;
 uint ece:1;
 uint urg:1;
 uint ack:1;
 uint psh:1;
 uint rst:1;
 uint syn:1;
 uint fin:1;
 uint win_size:16;
 
// uint chck_sum:16;
 uint urg_ptr:16;
 
 
 uint8_t data[];
// uint opt:32;
 
};




struct pacprops
{
  uint ihl;
  uint16_t total;
  jbyte load_type;
  
};


struct pseudo_packet
{
 union pip
 {
  pseudo_ip_header ip_header;
  uint8_t ip_array[];
 }pseudo_ip;
};


struct packet
{
  union ip
  {
  ip_header ip_struct;
    
  uint8_t ip_array[];
  }ip_data;
  
  union tcp
  {
   tcp_header tcp_struct;
   
   uint8_t tcp_array[];
  }tcp_data;
  
   union udp
  {
   udp_header udp_struct;
   
   uint8_t udp_array[];
  }udp_data;
  
  
};


union pseudo_tcp_packet
{
  struct tcp_struct
  {
   pseudo_ip_header ip; 
   pseudo_tcp_header tcp;
  }tcp_holder;
  
  uint8_t packet_array[];
 // std::vector<uint8_t> packet_array;
};




union tcp_packet
{
  struct tcp_struct
  {
   ip_header ip; 
   tcp_header tcp;
  }tcp_holder;
  
  uint8_t packet_array[];
};

