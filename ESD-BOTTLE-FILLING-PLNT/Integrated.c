 
#include <p18f4550.h>		 
#include "vector_relocate.h"  

//Declarations for LCD Connection
#define LCD_DATA    PORTD               //LCD data port
#define en          PORTEbits.RE2      // enable signal
#define rw          PORTEbits.RE1      // read/write signal
#define rs          PORTEbits.RE0     // register select signal

//MOTOR pins distribution
#define MTR_0 PORTDbits.RD0
#define MTR_1 PORTDbits.RD1
#define MTR_2 PORTDbits.RD2
#define MTR_3 PORTDbits.RD3
#define MTR_4 PORTDbits.RD4
#define MTR_5 PORTDbits.RD5

//Function Prototypes
void ADC_Init(void);					//initialize the ADC
unsigned int Get_ADC_Result(void);		//to Get ADC result after conversion
void Start_Conversion(void);			//to Start of Conversion
void msdelay (unsigned int time);		//to generate delay
void init_LCD(void);					//to initialise the LCD		
void LCD_command(unsigned char cmd);	//to pass command to the LCD
void LCD_data(unsigned char data);		//to write character to the LCD
void LCD_write_string(static char *str);//write string to the LCD
void delay(void);

//OPERATION FUNCTION 
void Conveyor_ON();
void Conveyor_OFF();
void Pump_ON();
void Pump_OFF();
void Solonoid_relay(bool value);
void Level_Senser();
void Keypad_interfacing();

int static level_var = 0;
int unsigned static adc_val=0;
//    TODO use 0x01 for clearing the lcd screen 

//Start of main program
void main()
{ 
    char msg1[] = "BOTTLE FILLING PLANT";
    char msg2[] = "CREATED by K-5 ";
    
    char bottledetected[]="BOTTLE DETECTED...";
    char conveyorOFF[]="Conveyor OFF..";
    char conveyorON[]="COnveyor ON..";

    ADCON1 = 0x0C;        //Configuring the PORT pins as digital I/O 
    TRISD = 0x00;         //Configuring PORTD as output 
    TRISE = 0x00;         //Configuring PORTE as output
        
    ADC_Init();				
    init_LCD();				
    LCD_write_string(msg1);	
    LCD_command(0xC0);			
    LCD_write_string(msg2);	
    LCD_command(0x01);

    // sense the water level first
    Level_Senser();

    while(level_var < 1 )
    {       
        LCD_write_string(conveyorOFF);
        msdelay(150);
        LCD_command(0x01);
        // =start conveyor belt
        Conveyor_ON();
        LCD_write_string(conveyorON);
        msdelay(150);
         

        //// .... we have kept bootle now 
        Start_Conversion();			
        adc_val= Get_ADC_Result();     //IR sensor output...
        //we get the IR result
        LCD_command (0x80);	

        //TODO:: remove this line
        LCD_data(adc_val);     
        msdelay(150);
         

        if(adc_val !=0)
        {  
            LCD_data(bottledetected);
            msdelay(150);
            lcd_data(conveyorOFF);
            Conveyor_OFF();

            //start the liqiud flow
            Pump_ON();

            //start soloniod Solonoid_relay
            Solonoid_relay(true);

            // TODO:::wait for 10sec delay

            //shut the value
            Pump_OFF();
            Solonoid_relay(false);

            //start conveyor
            Conveyor_ON();


        }   
              //TODO :       check   delay for correct postioning
        // till here we have bootle sensed and at correct position 
        
        
        
            
    
        msdelay(300);		 
    }
}

//Function Definitions
void ADC_Init()
{
    ADCON0=0b00000001;
   // ADCON0=0b00000000;	     //AN0  selected
    ADCON1=0b00001100;	     //first three anaolog 
    ADCON2=0b10001110;      //0x8E
    ADCON0bits.ADON=1; //Turn ON ADC module

 
}

void Start_Conversion()
{
 ADCON0bits.GO=1;
}

 
unsigned int Get_ADC_Result()
{
    unsigned int ADC_Result=0;
    while(ADCON0bits.GO);
    ADC_Result=ADRESL;
    PORTD=ADRESL;
    msdelay(500);
    ADC_Result|=((unsigned int)ADRESH) << 8;
    return ADC_Result;
} 

void msdelay (unsigned int time) 
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 710; j++); 
}


void init_LCD(void)		 
{
    LCD_command(0x38);      //2line 5X7 Matrix 
    msdelay(15);
    LCD_command(0x01);       //clear 
    msdelay(15);
    LCD_command(0x0C);       //cursor Off (display)
    msdelay(15);
    LCD_command(0x80);        //pos of cursor
    msdelay(15);
}

void LCD_command(unsigned char cmd) 
{
    LCD_DATA = cmd;	 
    rs = 0;			 
    rw = 0;				 
    en = 1;				 
    msdelay(15);
    en = 0;
}
//Function to write data to the LCD
void LCD_data(unsigned char data)
{
    LCD_DATA = data;	 
    rs = 1;				 
    rw = 0;				 
    en = 1;				 
  	msdelay(15);
    en = 0;
}
//Function to write string to LCD
void LCD_write_string(static char *str)   
{
    int i = 0;
    while (str[i] != 0)
    {
        LCD_data(str[i]);      // data on LCD byte by byte
        msdelay(15);
        i++;
    }
}
void Level_Senser()
{
    char msg1[] = "Water level Checking..";
    char msg2[] ="Level:";
    char ok[]="OK";
    char Low[]="LOW";
    char High[]="HIGH";

    ADCON1=0x0F;
	CMCON=0x07;
	TRISAbits.RA1=1;		//INPUT TO DETECT HIGH LEVEL
	TRISAbits.RA2=1;		//INPUT TO DETECT LOW LEVEL
	TRISB=0x00;		//PORT B AS OUTPUT TO GLOW LEDs AND BUZZER
	
    LCD_write_string(msg1);	
    LCD_command(0xC0);			
    LCD_write_string(msg2);	
    LCD_command(0xC7);
    
     
    if(PORTAbits.RA1==1 && PORTAbits.RA2==1)	//HIGH LEVEL DETECTED
    {
        PORTBbits.RB1=0;
        PORTBbits.RB0=1;
        level_var=2;			//GREEN LED WILL GLOW
        LCD_write_string(High);
    }
    else if(PORTAbits.RA1==0 && PORTAbits.RA2==0)	//LOW LEVEL DETECTED
    {
        PORTBbits.RB0=0;
        PORTBbits.RB1=1;
        level_var=1;
        LCD_write_string(low);			//RED LED AND BUZZER WILL GET ON
    }
    else
    {
        PORTBbits.RB0=0;		//BOTH LEDs AND BUZZER WILL BE OFF
        PORTBbits.RB1=0;
        level_var=0;
        LCD_write_string(ok);
    }
	 
}
void Conveyor_ON()
{
    MTR_0=1;
    MTR_1=0;
    MTR_2=1;
    MTR_3=0;
}
void Conveyor_OFF()
{

    MTR_0=0;
    MTR_1=0;
    MTR_2=0;
    MTR_3=0;

}
void Pump_ON()
{
    MTR_4=1;
    MTR_5=0;

}
void Pump_OFF()
{
    MTR_4=0;
    MTR_5=0;
}
void delay ()
{
    TICON = 0x20;
    TMR1H = 0xED    ;
    TMR1L =  0xB0    ;
    T1CONbits.TMR1ON =1 ;
    while(PIR1bits.TMR1IF == 0)
    {
        T1CONbits.TMR1ON=0;
        PIR1bits.TMR1IF=0;
    }

}