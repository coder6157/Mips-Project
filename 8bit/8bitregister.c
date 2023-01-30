#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
        int sel;
        char word[1024];
        unsigned char reg = 0;
        while(1)
        {
                printf("1) Author info\n2) check status\n3) clear status\n4) save status\n5) load status\n6) set LED color\n7) clear LED color\n8) toggle reset\n9) turn on\n10) turn off\n0) Exit\n");
        scanf("%d",&sel);
        switch(sel){
            case 1 :
                    printf("Ayub Khan\n2844931\n");
                     break;


            case 2 :if((reg & 1) >0){
                     printf("\nPOWER Pin: ON\n");
                    }
                     else printf("\nOFF");


                    if((reg & (1<<7)) > 0){
                        printf("\nRESET Pin : High\n");
                    }
                    else
                    {
                    printf("\nRESET Pin: Low\n");
                    }

                    if((reg & (3<<5)) > 0){
                       if( ((reg & (1<<5)) > 0) & ((reg & (1<<6)) > 0)){
                           printf("\nCOLOR: BLUE\n");
                           break;
                       }
                        else if( ((reg & (1<<5)) > 0) & ((reg & (1<<6))==0)){
                        printf("\nCOLOR: RED\n");
                            break;
                        }
                        else if( ((reg & (1<<5)) == 0) & ((reg & (1<<6)) > 0)){
                        printf("\nCOLOR:GREEN\n");
                            break;
                        }
                    }
else printf("\nColor:none\n");
                    break;


            case 3: reg = reg * 0;
                    break;
            case 4: printf("\nEnter the file name");
                    scanf("%s",word);
                     sel = open(word,O_CREAT | O_WRONLY,0600);
                     write(sel,&reg,1);
                     close(sel);
                    break;

             case 5: printf("\n Enter file name");
                    scanf("%s",word);
                    sel= open(word,O_RDONLY);
                    read(sel,&reg,1);
                    close(sel);
                    break;





            case 6: printf("Enter Selected Color");
                    scanf("%s",word);
                    if(strcasecmp(word,"Red")==0){
                        reg = reg & ~(3<<5)| (1<<5);
                    }
                    else if(strcasecmp(word,"Green")==0){
                        reg = reg & ~(3<<5)| (1<<6);
                    }
                    else if(strcasecmp(word,"Blue")==0){
                        reg = reg & ~(3<<5) |(3<<5);
                    }
                    else printf("Color not found\n");
                    break;


            case 7: reg = reg & ~(3<<5);
                    break;

            case 8: reg = reg ^ (1<<7);
                    break;

            case 9: reg = reg | 1;
                    break;

            case 10: reg = reg & ~1;
                    break;
 case 0: return(0);



        }


        }



        return(0);
}

