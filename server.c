#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

int main()
{
        int welcome,new_soc,n,fd;
        char buff[1024],fname[50];
        struct sockaddr_in addr;
        welcome=socket(PF_INET,SOCK_STREAM,0);
        addr.sin_family=AF_INET;
        addr.sin_port=htons(7891);
        addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        
        bind(welcome,(struct sockaddr *) &addr ,sizeof(addr));
        
        printf("Server is online...\n");
        
        listen(welcome,5);
        
        new_soc=accept(welcome,NULL,NULL);
        
        recv(new_soc,fname,50,0);
        
        printf("Requesting for the file : %s\n",fname);
        
        fd=open(fname,O_RDONLY);
        
        if(fd<0)
        {
                send(new_soc,"\nFile Not Found\n",strlen("File Not Found")+1,0);
        }
        else
        {
                while((n=read(fd,buff,sizeof(buff))) > 0)
                        send(new_soc,buff,n,0);
        }
        printf("\nFile sent successfully\n");
        return 0;
}
