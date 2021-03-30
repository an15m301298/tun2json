struct dns_struct
{
 uint dns_id:16;
 uint query_type:1;
 uint opcode:4;
 uint auth_ans:1;
 uint trunc_code:1;
 uint rec_desired:1;
 uint rec_avail:1;
 uint z_bit:3;
 uint r_code:4;
 uint qn_count:16;
 uint ans_rec_count:16;
 uint ns_count:16;
 uint ans_rec_countpp:16;
 
 uint8_t dns_payload[];
};


union dns_union
{
 dns_struct dns;
 uint8_t dns_array[];

};