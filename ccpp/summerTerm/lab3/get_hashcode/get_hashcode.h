static inline u32 rol( u32 x, int n);
void sha1_init( SHA1_CONTEXT *hd );
static void transform( SHA1_CONTEXT *hd, unsigned char *data );
static void sha1_write( SHA1_CONTEXT *hd, unsigned char *inbuf, size_t inlen);
static void sha1_final(SHA1_CONTEXT *hd);
char *GetFileSHA1(char *FileNameInPut, char *outSHA1, char *outError);
STATE_T** get_Hashcode (STATE_T **data);
