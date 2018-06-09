#include <16f877a.h>
#use delay(clock=20M)
#include <def_877a.h>
#include <lcd_4bit.c>
#include <math.h>


#bit  cot1=portB.4
#bit  cot2=portB.5
#bit  cot3=portB.6
#bit  cot4=portB.7

#bit  hang1=portB.0
#bit  hang2=portB.1
#bit  hang3=portB.2
#bit  hang4=portB.3
long kq,kq1,kq2,ok,pt,j;

//------------------------------------------------------------------------
//--------------------------Chuong trinh con-----------------------------
//------------------------------------------------------------------------


int8  const tit0[]={"*DO AN HTN*"};
int8  const tit1[]={"-T-T-V-"};
int8  tit2[15];
int8  tit3[15];
int8 i;

void write_line1(long kq,pt){
   lcd_putcmd(clear_scr);
   lcd_putcmd(line_1);
   i=0;j=kq;
   while (j!=0)
   {
      if (j%10) tit2[i]=1;
      else      tit2[i]=0;
      //tit2[i]=j%10;
      j=j/10;
      i++;
   }
   for (j=i-1;j>=0;j--) lcd_putchar(tit2[j]);  
   if (pt==1)  lcd_putchar('+');
   else
      if  (pt==2) lcd_putchar('-');
      else
         if (pt==3)  lcd_putchar('x');
         else      
            if (pt==4)  lcd_putchar(':');
            
         
 
}
void  write_line2(long kq){
   lcd_putcmd(line_2);
   i=0;j=kq;
   while (j!=0)
   {
      tit2[i]=j%10;
      j=j/10;
      i++;
   }
   for (j=i-1;j>=0;j--) lcd_putchar(tit2[j]);  
   }



#int_RB // Chuong trinh ngat Port B
void  RB_isr(void){

long kq=0, kq1=0, kq2=0;
   if(hang1==1){
      if(cot1==1){
         if (ok==0) 
         {      kq1=kq1*10+7;write_line2(kq1+48);  }
         else  {kq2=kq2*10+7;write_line1(kq1+48,pt+48);write_line2(kq2+48); }

         //lcd_putchar('7');// Hien thi ra LCD so 7
     
 
      }
      else  if(cot2==1){lcd_putcmd(clear_scr);
              if (ok==0) 
              {      kq1=kq1*10+8;write_line2(kq1+48);}
              else  {kq2=kq2*10+8;write_line1(kq1+48,pt+48);write_line2(kq2+48);}        
               
               //lcd_putchar('8');// Hien thi ra LCD so 8
   
            }
            else  if(cot3==1){lcd_putcmd(clear_scr);
                     if (ok==0) 
                     {      kq1=kq1*10+9;write_line2(kq1+48);}
                     else  {kq2=kq2*10+9;write_line1(kq1+48,pt+48);write_line2(kq2+48);}
                     //lcd_putchar('9');// Hien thi ra LCD so 9
                    
                 }
                  else  if(cot4==1){lcd_putcmd(clear_scr);
                          
                           if (ok==0)
                           {
                              pt=4;
                              ok=1;                              
                           }
                           else
                           {
                              switch (pt)
                              {
                                 case 1: kq=(kq1+kq2); kq1=kq; break;
                                 case 2: kq=kq1-kq2; kq1=kq; break;
                                 case 3: kq=kq1*kq2; kq1=kq; break;
                                 case 4: kq=kq1/kq2; kq1=kq; break;                              
                              }
                              pt=4;                            
                            }
                            write_line1(kq1+48,pt+48);
                          
                           //lcd_putchar(':');// Hien thi ra LCD ky tu :
                          
                        }
  }
  else if(hang2==1){  
         if(cot1==1){
            
                     if (ok==0) 
                     {      kq1=kq1*10+4;write_line2(kq1+48);}
                     else  {kq2=kq2*10+4;write_line2(kq1+48);}

            //lcd_putchar('4');// Hien thi ra LCD so 4
           
         }
         else  if(cot2==1){lcd_putcmd(clear_scr);
                
                     if (ok==0) 
                     {      kq1=kq1*10+5;write_line2(kq1+48);}
                     else  {kq2=kq2*10+5;write_line1(kq1+48,pt+48);write_line2(kq2+48);}

                //lcd_putchar('5');// Hien thi ra LCD so 5
                
               }
               else  if(cot3==1){lcd_putcmd(clear_scr);
                       
                     if (ok==0) 
                     {      kq1=kq1*10+6;write_line2(kq1+48);}
                     else  {kq2=kq2*10+6;write_line1(kq1+48,pt+48);write_line2(kq2+48);}

                        //lcd_putchar('6');// Hien thi ra LCD so 6
                    
                     }
                     else  if(cot4==1){lcd_putcmd(clear_scr);
                             
                              if (ok==0)
                              {
                                 pt=3;
                                 ok=1;                                 
                              }
                              else
                              {
                                 switch (pt)
                                 {
                                    case 1: kq=(kq1+kq2); kq1=kq; break;
                                    case 2: kq=kq1-kq2; kq1=kq; break;
                                    case 3: kq=kq1*kq2; kq1=kq; break;
                                    case 4: kq=kq1/kq2; kq1=kq; break;                              
                                 }
                              pt=3;                            
                              }
                              write_line1(kq1+48,pt+48);
                            
                              //lcd_putchar('x');// Hien thi ra LCD ki tu x
                         
                           }
       }
 else if(hang3==1){
                  if(cot1==1){lcd_putcmd(clear_scr);
                     
                     if (ok==0) 
                     {      kq1=kq1*10+1;write_line2(kq1+48);}
                     else  {kq2=kq2*10+1;write_line1(kq1+48,pt+48);write_line2(kq1+48);}
                     //lcd_putchar('1');// Hien thi ra LCD so 1
                   
                  }
                  else  if(cot2==1){lcd_putcmd(clear_scr);
                           
                     if (ok==0) 
                     {      kq1=kq1*10+2;write_line2(kq1+48);}
                     else  {kq2=kq2*10+2;write_line1(kq1+48,pt+48);write_line2(kq1+48);}
                           //lcd_putchar('2');// Hien thi ra LCD so 2
                     
                        }
                        else if(cot3==1){lcd_putcmd(clear_scr);
                                 
                     if (ok==0) 
                     {      kq1=kq1*10+3;write_line2(kq1+48);}
                     else  {kq2=kq2*10+3;write_line1(kq1+48,pt+48);write_line2(kq1+48);}
                                 //lcd_putchar('3');// Hien thi ra LCD so 3
                             
                              }
                              else if(cot4==1){
                                      lcd_putcmd(clear_scr);
                                       if (ok==0)
                                       {
                                          pt=2;
                                          ok=1;
                                       }
                                       else
                                       {
                                          switch (pt)
                                          {
                                             case 1: kq=(kq1+kq2); kq1=kq; break;
                                             case 2: kq=kq1-kq2; kq1=kq; break;
                                             case 3: kq=kq1*kq2; kq1=kq; break;
                                             case 4: kq=kq1/kq2; kq1=kq; break;                              
                                          }
                                       pt=2;                            
                                       }
                                       write_line1(kq1+48,pt+48);
                                      
                                       //lcd_putchar('-');// Hien thi ra LCD ky tu -
                                      
                                    }        
}

  else if(hang4==1){  
         if(cot1==1){lcd_putcmd(clear_scr);
            
                     if (ok==0) 
                     {      kq1=0;write_line2(kq1+48);}
                     else  {kq2=0;write_line1(kq1+48,pt+48);write_line2(kq1+48);}
            //lcd_putchar('.');// Hien thi ra LCD so .
         }
         else  if(cot2==1){lcd_putcmd(clear_scr);
               
                     if (ok==0) 
                     {      kq1=kq1*10+0;write_line2(kq1+48);}
                     else  {kq2=kq2*10+0;write_line1(kq1+48,pt+48);write_line2(kq1+48);}
                //lcd_putchar('0');// Hien thi ra LCD so 0
             
               }
               else  if(cot3==1){lcd_putcmd(clear_scr);
                       
                        if (ok==0)  kq=kq1;
                        else
                        {
                            switch (pt)
                            {
                               case 1: kq=(kq1+kq2); kq1=kq; break;
                               case 2: kq=kq1-kq2; kq1=kq; break;
                               case 3: kq=kq1*kq2; kq1=kq; break;
                               case 4: kq=kq1/kq2; kq1=kq; break;                              
                            }
                                                   
                        }
                        kq1=0;kq2=0;pt=0;ok=0;
                        write_line2(kq+48);
                       
                        
                        //lcd_putchar('=');// Hien thi ra LCD so =
                                             }
                     else  if(cot4==1){lcd_putcmd(clear_scr);
                            
                              if (ok==0)
                              {
                                 pt=2;
                                 ok=1;
                              }
                              else
                              {
                                 switch (pt)
                                 {
                                    case 1: kq=(kq1+kq2); kq1=kq; break;
                                    case 2: kq=kq1-kq2; kq1=kq; break;
                                    case 3: kq=kq1*kq2; kq1=kq; break;
                                    case 4: kq=kq1/kq2; kq1=kq; break;                              
                                 }
                                 pt=1;                            
                               }
                               write_line1(kq1+48,pt+48);
                            
                              //lcd_putchar('+');// Hien thi ra LCD so +
                            
                           }
       }
}
 //------------------------------------------------------------------------
 /*------------------------Chuong trinh chinh-------------------------------*/
 //------------------------------------------------------------------------
void main(){
   lcd_init();
   enable_interrupts(INT_RB);
   //enable_interrupts(GLOBAL);
   
   trisb=0xF0;
   
   while(tit0[i]!=0){
      lcd_putchar(tit0[i]);
      i++;
      delay_ms(70);      
   }
   lcd_putcmd(line_2);
   i=0;ok=0;pt=0;
   
   while(tit1[i]!=0){
      lcd_putchar(tit1[i]);
      i++;
      delay_ms(70);      
   }
   delay_ms(2000);
   write_line1(1000,1);delay_ms(2000); 
   lcd_putcmd(clear_scr);
  
   
   enable_interrupts(GLOBAL);
  
  while(1){
      //quet hang
      hang4=0;   hang1=1;   delay_ms(10); //Xuat tin hieu 1 ra hang 1, 0 ra hang 4 de do hang,      
      hang1=0;   hang2=1;   delay_ms(10); //Xuat tin hieu 1 ra hang 2, 0 ra hang 1 de do hang     
      hang2=0;   hang3=1;   delay_ms(10); //Xuat tin hieu 1 ra hang 3, 0 ra hang 2 de do hang     
      hang3=0;   hang4=1;   delay_ms(10); //Xuat tin hieu 1 ra hang 4, 0 ra hang 3 de do hang
   }
}
