#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<netinet/in.h>

void array(int  newsockfd){
    int num ;
    char buff[256];
    char ask[] = "\nEnter the Number of elements: ";
    send(newsockfd, ask , sizeof(ask) , 0);
    read(newsockfd , buff , 256);
    num = atoi(buff);
    bzero(buff , 256);
    int arr[num];
    char ask2[] = "\nEnter elements (seperated by newline):\n";
    send(newsockfd, ask2 , sizeof(ask2) , 0);
    for(int i = 0 ; i < num ; i++){
        read(newsockfd , buff , 256);
        arr[i] = atoi(buff);
        bzero(buff , 256);                
    }

    char s[100];
    for(int i = 0 ; i < num ; i++){
        snprintf(s, sizeof(s), "%d", arr[i]);
        send(newsockfd , s , sizeof(s) , 0);
        send(newsockfd , " " , 1 , 0);
    }
    send(newsockfd , "\n" , 2 , 0);
}