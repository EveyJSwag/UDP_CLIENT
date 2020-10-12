#ifndef PACKET_TYPE
#define PACKET_TYPE

#include <stdint.h>

#define SET_LI_VI_MODE(li, vi, mode)    ( (li) << 0 | (vi) << 2 | (mode) << 5 )

typedef unsigned char  uint8;
typedef signed   char  int8;

typedef unsigned short us16;

typedef unsigned int   uint32;


namespace packets
{
    typedef struct NTP
    {
        uint8     li_vn_mode;

        uint8     stratum; 
        int8      poll;
        int8      precision;

        uint32    root_delay;  
        uint32    root_dispersion;
        uint32    reference_indentifier;

        uint32    reference_timestamp;
        uint32    reference_timestamp_frac;

        uint32    originate_timestamp;
        uint32    originate_timestamp_frac;

        uint32    recv_timestamp;
        uint32    recv_timestamp_frac;

        uint32    trans_timestamp;
        uint32    trans_timestamp_frac;

    } NTP;

    

}

#endif