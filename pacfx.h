#include "pacton.h"
#include "pacutil.h"
#include<arpa/inet.h>


//udp parser function
std::string udp_parse(uint udp_offset,uint udp_length,jbyte *pac_data,jbyte udp_mem[])
{
  uint sz=0;
  std::stringstream sst;
  std::string str;
  uint end_index=(udp_length)-(udp_offset);
//  uint udp_load=htons(pac_data[(udp_offset+4)]);
 // udp_offset=udp_offset+1;
  sst<<"udp_length:"<<udp_length<<"udp_offset:"<<udp_offset;
  
  while((udp_offset)<(end_index))
  {
  if(sz<8)
  {
   udp_mem[sz]=(jbyte)(pac_data[udp_offset]);
  }
  else
   {
     
   udp_mem[sz]=binrevo(pac_data[udp_offset]); 
  }
   
  sz++;
  udp_offset++;
  }
  
  sst>>str;
  return str;
}
//end of udp function


//auto_tcp_header
pseudo_tcp_header gen_pseudo_tcp(tcp_header *tcph)
{
  pseudo_tcp_header tcp;
  tcp.src_port=(tcph->src_port);
  tcp.dest_port=(tcph->dest_port);
 
 tcp.ack_no=(tcph->ack_no);
 
 tcp.data_offset=(tcph->data_offset);
 tcp.resr=(tcph->resr);
 tcp.ns=(tcph->ns);
 tcp.cwr=(tcph->cwr);
 tcp.ece=(tcph->ece);
 tcp.urg=(tcph->urg);
 tcp.ack=(tcph->ack);
 tcp.psh=(tcph->psh);
 tcp.rst=(tcph->rst);
 tcp.syn=(tcph->syn);
 tcp.fin=(tcph->fin);
 tcp.win_size=(tcph->win_size);
  

return tcp;  
}
//end of pseudo tcp generator

//generate real tcp header from pseudo
tcp_header tcp_from_pseudo(pseudo_tcp_header pth)
{
  
}
//end of real tcp header from pseudo

//generate template ip_header for reply
ip_header gen_reply_ip(ip_header *tcph)
{
 ip_header ip;
 ip.version=(tcph->version);
 ip.IHL=(uint8_t)(5);
 ip.ttl=(tcph->ttl);
 ip.DSCP=(tcph->DSCP);
 ip.ECN=(tcph->ECN);
 
 ip.id=(tcph->id);
 ip.total_len=(tcph->total_len);
 
 
 ip.resv=(tcph->resv);
 ip.df=(tcph->df);
 ip.mf=(0);
 ip.frag_offset=(0);
 
 ip.proto=(tcph->proto);
 ip.src_ip=(tcph->dest_ip);
 ip.dest_ip=(tcph->src_ip);
 
 return ip;
}
//end of function




//ip generate pseudo ip
pseudo_ip_header gen_pseudo_ip(ip_header *tcph)
{
 pseudo_ip_header ip;
 ip.version=(tcph->version);
 ip.IHL=(tcph->IHL);
 ip.ttl=(tcph->ttl);
 ip.DSCP=(tcph->DSCP);
 ip.ECN=(tcph->ECN);
 
 ip.id=(tcph->id);
 ip.total_len=(tcph->total_len);
 
 
 ip.resv=(tcph->resv);
 ip.df=(tcph->df);
 ip.mf=(tcph->mf);
 ip.frag_offset=(tcph->frag_offset);
 
 ip.proto=(tcph->proto);
 ip.src_ip=(tcph->src_ip);
 ip.dest_ip=(tcph->dest_ip);
 
 return ip;
}


ip_header ip_from_pseudo(pseudo_ip_header pih)
{
 ip_header ip_temp;
  
}


//tcp parser function
void tcp_parse(uint tcp_offset,uint tcp_length,jbyte *pac_data,jbyte tcp_mem)
{
  
  
}
//end of tcp parser


//ip data builder
std::string dataSmith(ip_header *datas)
{
std::string json1;
std::stringstream json_bob;

std::string jgen="{";
std::string jrev="}";
std::string jass=":";

   json_bob<<jgen<<"\"version\""<<jass<<datas->version<<";\"IHL\":"<<(datas->IHL)<<";\"DSCP\":"<<datas->DSCP<<";\"ECN\":"<<datas->ECN<<";\"total\":"<<ntohs(datas->total_len)<<";\"packet_id\":"<<ntohs(datas->id)<<";\"flag_resv\":"<<datas->resv<<";\"frag_offset\":"<<datas->frag_offset<<";\"ttl\":"<<datas->ttl<<";\"proto\":"<<datas->proto<<";\"check_sum\":"<<ntohs(datas->check_sum)<<";\"source\":"<<ipmake(datas->src_ip)<<";\"dest\":\""<<ipmake(datas->dest_ip)<<"\""<<"}\n\n";

 json_bob>>json1;
 return json1;
}


//udp data builder

std::string dataSmith(udp_header *datas)
{
std::string json1;
std::stringstream json_bob;

std::string jgen="{";
std::string jrev="}";
std::string jass=":";

std::string data=fixit(datas->udp_data,(htons(datas->udp_length)));
   json_bob<<jgen<<"{\"src_port\":"<<htons(datas->src_port)<<";\"dest_port\":"<<htons(datas->dest_port)<<";\"length\":"<<htons(datas->udp_length)<<";\"check_sum\":"<<htons(datas->chck_sum)<<";\"udp_data\":\"";
   //<<data<<";}}";
 json_bob>>json1;
 return json1;
}





//ip paser function
void ip_parse(jbyte *data_arr,jbyte darrs[],int ip_size)
{
 //std::stringstream packsz;
 //filler(data_arr,pack.data,pack_size);
 int sz=0;
 
 while(sz<ip_size)
 {
   
   if((sz==0))
   {
   darrs[sz]=(revo(data_arr[sz]));
  
   }
  else if(sz==6)
  {
   darrs[sz]=(binrevo(data_arr[sz]));
     
   }
    else if(sz==7)
  {
   darrs[sz]=(binrevo(data_arr[sz]));
     
   }
   else
   {
     darrs[sz]=(jbyte)(data_arr[sz]);
   }
   sz++;
  }
 
}
//end of ip parse

//generate ip header checksum
uint16_t genIpChecksum(pseudo_ip_header pih)
{
uint16_t checksum;
 pseudo_packet ip_buff;
 
 ip_buff.pseudo_ip.ip_header=pih;
 
 checksum=genChecksum16(ip_buff.pseudo_ip.ip_array);
 return checksum;
}
//end of function

//generate tcp checksum


//Auto Reply function
void autoSync(packet main_packet,uint8_t res[])
{
pseudo_tcp_packet tcp_pack;
  pseudo_ip_header pseudo_ip=gen_pseudo_ip(&main_packet.ip_data.ip_struct);
  pseudo_tcp_header pseudo_tcp=gen_pseudo_tcp(&main_packet.tcp_data.tcp_struct);
  
  tcp_pack.tcp_holder.ip=pseudo_ip;
  tcp_pack.tcp_holder.tcp=pseudo_tcp;

filler(tcp_pack.packet_array,res,sizeof(tcp_pack.packet_array));
}
//end of function

//gets main properties of packet
pacprops getProps(jbyte pdu[])
{
 int pihl;
 jbyte proto;
 
pacprops pp;
 
 union bitt
{
  struct nobit
{
  uint a:4;
  uint b:4;
 
}nb;
  
 uint8_t no;
}byt,cach;


  byt.no=pdu[0];
  cach.nb.a=byt.nb.b;
  cach.nb.b=byt.nb.a;
  //save IHL
  pihl=byt.nb.a;
  proto=(jbyte)pdu[9];
  
  
  pp.ihl=(+pihl);
  pp.total=(uint16_t)((memAdd16(&(pdu[2]))));
  pp.load_type=(jbyte)(proto);
  
  /*std::string rdata="\n\nIHL: ";
 
 
  rdata=rdata+mkstr((+pp.ihl));
  rdata=rdata+"\nPROTO: ";
  rdata=rdata+mkstr((+pp.load_type));
  rdata=rdata+"\nTotal: ";
  rdata=rdata+mkstr((+pp.total));
  */
 return pp;
}
