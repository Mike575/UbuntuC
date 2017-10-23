//#include <windows.h>
#include <stdio.h>
void main(void)  
{  
    unsigned FREQUENCY[] = {392,392,440,392,523,494,  
              392,392,440,392,587,523,  
              392,392,784,659,523,494,440,  
              689,689,523,587,523};  
 
    unsigned DELAY[] = {375,125,500,500,500,1000,  
              375,125,500,500,500,1000,  
              375,125,500,500,500,500,1000,  
              375,125,500,500,500,1000};  
    int i;  
	FILE* fp;
	fp=fopen("music.txt","w");
 /* for (i = 0; i < 25; i++)  
    {  
		putc('0'+FREQUENCY[i]/1000%10,fp);
		putc('0'+FREQUENCY[i]/100%10,fp);
		putc('0'+FREQUENCY[i]/10%10,fp);
		putc('0'+FREQUENCY[i]/1%10,fp);
		putc('\n',fp);
//		Beep(FREQUENCY[i], DELAY[i]);  
    }
 */ for (i = 0; i < 25; i++)  
    {  
		putc('0'+DELAY[i]/1000%10,fp);
		putc('0'+DELAY[i]/100%10,fp);
		putc('0'+DELAY[i]/10%10,fp);
		putc('0'+DELAY[i]/1%10,fp);
		putc('\n',fp);


//		Beep(FREQUENCY[i], DELAY[i]);  
    }  
} 
