#include<array>
#include<sstream>

#include "pacfx.h"



extern "C"
jstring Java_com_lecturehall_vpnmode_Vpnser_passPack(JNIEnv *jenv,jobject jobj,jbyteArray data,jint dsize)
{
packet fire_pac;
std::string props,ip_str,udp_str,meta_str;
//get length of buffer
uint packet_len=(jenv)->GetArrayLength(data);
pacprops pprops;

//get byte buffer
jbyte *pac_buff=(jenv)->GetByteArrayElements(data,NULL);
pprops=getProps(pac_buff);



//ip header parser
ip_parse(pac_buff,fire_pac.ip_data.ip_array,((pprops.ihl*4)));


//ip header json structure build
ip_str=dataSmith(&fire_pac.ip_data.ip_struct);



//packet_payload switcher
switch((+pprops.load_type))
{
//tcp_parser
  case 6:
  
  
  break;
//udp_parser
  case 17:
 //udp header parser 
  meta_str=udp_parse(((pprops.ihl)*4),(+pprops.total),pac_buff,fire_pac.udp_data.udp_array);

//udp header json
udp_str=dataSmith(&fire_pac.udp_data.udp_struct);
  break;
  
}
//end of payload switcher




//packet json structure
props="\n\n"+ip_str+"\n"+udp_str;
 
 
//json return to java
return (jenv)->NewStringUTF(props.c_str());
}

/*jstring Java_com_lecturehall_vpnmode_Vpnser_passPack(JNIEnv *jenv,jobject jobj,jbyteArray headers,jint dsize)
{

}*/
/*std::string props="\n\nIHL: ";

props=props+mkstr((+pprops.ihl));
props=props+"\ntotal";
props=props+mkstr((+pprops.total));
props=props+"\nTYPE";
props=props+mkstr((+pprops.load_type));
*/