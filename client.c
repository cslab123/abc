#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>

int main()
{
        int soc,n;
        char buff[1024],filename[50];
        struct sockaddr_in addr;
        soc=socket(PF_INET,SOCK_STREAM,0);
        addr.sin_family=AF_INET;
        addr.sin_port=htons(7891);
        addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        
        while(connect(soc,(struct sockaddr *) &addr,sizeof(addr)));
        
        printf("Client connected to server...\n");
        
        printf("Enter the file name:");
        scanf("%s",filename);
        
        send(soc,filename,sizeof(filename),0);
        
        printf("Recieved from server:\n");
        while((n=recv(soc,buff,sizeof(buff),0)) > 0)
                printf("%s",buff);
        return 0;
}
