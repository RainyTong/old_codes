#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

//已知文件名，可得到文件大小

int getsize(const char* filename)
{

    struct stat buf;
    stat(filename,&buf);
    return buf.st_size;
}

//测试：
int main()
{

    int filesize = getsize("2.txt");
    printf("%d\n", filesize);

    return 0;
}
