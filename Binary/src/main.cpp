#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<netinet/in.h>
#include<climits>
#include "array.h"
#define PORT 1337
using namespace std ;

void s_socket();
int main(){
  
  cout << "[*] Running Server..." << endl;
  while(1)
    s_socket();
  return 0;
}

void s_socket(){

  int check;
  int opt = 1;
  socklen_t clilen ;
  struct sockaddr_in cli_addr , serv_addr ;
  serv_addr.sin_family = AF_INET ;
  serv_addr.sin_addr.s_addr = INADDR_ANY ;
  serv_addr.sin_port = htons(PORT);

  int sockfd = socket(AF_INET , SOCK_STREAM , 0);
  if(!sockfd){
    cout << "[*] Error opening socket" << endl;
    exit(123);
  }

  check = bind(sockfd , (struct sockaddr *) &serv_addr , sizeof(serv_addr));
  if(check < 0){
    cout << "[*] Error on Binding" << endl;
    exit(123);
  }

  listen(sockfd , 5);

  int newsockfd = accept(sockfd , (struct sockaddr *) &cli_addr , &clilen);

  /*Reading*/
  char buffer[256];
  bzero(buffer , 256);

  char head[] = "\n|----------|Docky|----------|\n";
  char stuff[] = "\n1.Array\n2.Linked List\n99.Exit\n> ";

  do{
    send(newsockfd , head , sizeof(head) , 0);
    send(newsockfd , stuff , sizeof(stuff) , 0);
    read(newsockfd, buffer , 256);
    
    switch(atoi(buffer)){
      case 1:
        array(newsockfd);
        break;
    }
  }while(atoi(buffer) != 99);

  close(newsockfd);
  close(sockfd);
}
