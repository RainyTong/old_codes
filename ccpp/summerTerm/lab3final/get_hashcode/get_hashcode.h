#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <iostream>
#include <dirent.h>
#endif

#ifndef MAX
#define MAX
#define MAX_LINE 1000
#endif

#ifndef STATE_T
#define STATE_T
struct  structure1{
 char pathl[50];
 char namel[50];
 char hash[41];
 char *hash_code;
} ;

#endif



#undef BIG_ENDIAN_HOST
typedef unsigned int u32;

/****************
* Rotate a 32 bit integer by n bytes
*/



#ifndef SHA1_CONTEXT
#define SHA1_CONTEXT
struct structure2{
	u32  h0,h1,h2,h3,h4;
	u32  nblocks;
	unsigned char buf[64];
	int  count;
} ;
#endif


void get_Hashcode(int size);
char *GetFileSHA1(char *FileNameInPut, char *outSHA1, char *outError);
static void sha1_final(struct structure2 *hd);
static void sha1_write( struct structure2 *hd, unsigned char *inbuf, size_t inlen);
static void transform( struct structure2 *hd, unsigned char *data );
void sha1_init( struct structure2 *hd );
static inline u32 rol( u32 x, int n);
