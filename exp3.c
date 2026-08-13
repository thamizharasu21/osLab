#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main()
{
    int fd;
    char buffer[100];

    struct stat fileinfo;

    DIR*dir;
    struct dirent*entry;
    /*
    part 1:
    create and write data into a file using open() and write()
    */

    printf("\n---creating and writing file---\n");

    fd=open("student.txt",O_CREAT|O_WRONLY,0644);

    if(fd<0)
    {
        printf("file creation failed\n");
        return 1;
    }
    char data[]="linux system calls experiment\n"
    "b.sc cyber security laboratory";

    write(fd,data,strlen(data));

    close(fd);

    printf("data written successfully\n");

    /*
    part 2:
    read file content using open()and read()
    */

    printf("\n---reading file content---\n");

    fd=open("student.txt",O_RDONLY);

    if(fd<0)
    {
        printf("file opening failed\n");
        return 1;
    }

    int bytes=read(fd,buffer,sizeof(buffer)-1);

    buffer[bytes]='\0';

    printf("%s\n",buffer);

    close(fd);

    /*
    part 3:
    display file in information using stat()
    */

    printf("\n---file information---\n");

    if(stat("student.txt",&fileinfo)==0)
    {
        printf("file size :%id bytes\n",fileinfo.st_size);

        printf("number of links :%id\n",fileinfo.st_nlink);

        printf("permission :%o\n",fileinfo.st_mode&0777);
    }
    else
    {
        printf("unable to get file information\n");
    }

    /*
    part 4:
    create directory using mkdir()
    */

    printf("\n---creating directory---\n");

    if(mkdir("testdirectory",0755)==0)
{
    printf("directory created successfully\n");
}
else
{
    printf("directory mat already exist\n");
}

/*
part 5:
display directory contents using opendir()andreaddir()
*/

printf("\n---directory contents---\n");

dir=opendir(".");

if(dir==NULL)
{
    printf("cannot open directory\n");
    return 1;
}

while((entry=readdir(dir))!=NULL)
{
    printf("%s\n",entry->d_name);
}

closedir(dir);

printf("\nprogram completed successfully\n");

return 0;

}