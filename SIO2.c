#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
void *hilo1(void *arg){
  int i=0;
  int prio=0;
  int U1 = 4, L1 = 1;
  int tt = 1, tap4, tap3, tap2, tap1;
  float ti1 = 0, ti2 = 0, ti3 = 0, ti4 = 0;  
  int U2 = 3, L2 = 7;
  int U3 = 7, L3 = 9;
  int U4 = 10, L4 = 15;
  int U5 = 15, L5 = 25;
  float ac1 = 0, ac2 = 0, ac3 = 0, ac4 = 0;
  do{
 
   
      prio = (rand() % (U1 - L1 + 1)) + L1;
      
	 if(prio==4){
	 
		 printf("\n\n******Atendiendo a cliente de prioridad alta******");
		 printf("\n\n  Comenzando en %d minutos\n",  tt);
		  int t1  = (rand() % (U2 - L2 + 1)) + L2;
		  tt = tt + t1;
		   printf("\nSe requieren %d\n minutos",  t1);
		 printf("\n\n - Finalizando en %d minutos\n", tt );
	   ti1 = ti1 + t1; 
	   tt = tt + 1;
	   ac1++; 
	   }else  if(prio==3){
		 printf("\n\n******Atendiendo a cliente de prioridad intermedia******");
		 printf("\n\n  Comenzando en %d minutos\n",  tt);
		  int t2  = (rand() % (U3 - L3 + 1)) + L3;
		  tt = tt + t2;
		  printf("\nSe requieren %d minutos\n",  t2);
		 printf("\n\n  Finalizando en %d minutos\n",  tt);
	   ti2 = ti2 + t2; 
	   tt = tt + 1;
	   ac2++;
	   }else  if(prio==2){
		 printf("\n\n******Atendiendo a cliente de prioridad baja******");
		 printf("\n\n Comenzando en %d minutos\n",  tt);
		  int t3  = (rand() % (U4 - L4 + 1)) + L4;
		  tt = tt + t3;
		    printf("\nSe requieren %d minutos\n",  t3);
		 printf("\n\n - Finalizando en %d minutos\n",  tt);
	   ti3 = ti3 + t3; 
	   tt = tt + 1;
	   ac3++;
	   }else  if(prio==1){
		 printf("\n\n******Atendiendo a cliente de prioridad nula******");
		 printf("\n\n - Comenzando en %d minutos\n",  tt);
		  int t4  = (rand() % (U5 - L5 + 1)) + L5;
		  tt = tt + t4;
		  printf("\nSe requieren %d minutos\n",  t4);
		 printf("\n\n - Finalizando en %d minutos\n",  tt);
	   ti4 = ti4 + t4; 
	   tt = tt + 1;
	   ac4++;
	   }

     i++;
 }while(i< 5);
 
 printf("\n\n****** Tiempo promedio de espera ******");
 if(ac1 != 0){
float r1 = (ti1/ac1);
printf("\n\n - Prioridad alta: %.2f minutos \n", r1);
 }
  if(ac2 != 0){
 float r2 = (ti2/ac2);
 printf("\n\n - Prioridad intermedia: %.2f minutos \n", r2);
 }
  if(ac3 != 0){
 float r3 = (ti3/ac3);
 printf("\n\n - Prioridad baja: %.2f minutos \n", r3);	
 }
  if(ac4 != 0){
 float r4 = (ti4/ac4);
 printf("\n\n - Prioridad nula: %.2f minutos \n", r4);
 }
  

  return(NULL);
}

int main(void)
{
    pthread_t mihilo;
    
    if (pthread_create(&mihilo, NULL, hilo1, NULL)){
     printf("Error creando el hilo");   
     abort();
    
    }
    if(pthread_join (mihilo, NULL)){
        printf("Error esperando finalizacion de hilos");   
     abort();
    }
    
       printf("\n\nFin de programa");   
    exit(0);
}

