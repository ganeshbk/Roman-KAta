#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
char * AddTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 );
char * SubtractTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 );
int romanToDecimal(char* input_Roman_Number );
int digitValue(char c);
void predigits(char c1,char c2);
void postdigits(char c,int n);
void decimalToRoman(long int);
char ROMAN_NUMBER[1000];

bool PROCESSERROR;

/*******************************************************************
* NAME :            char * AddTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 )
*
* DESCRIPTION :     Adds two Roman numbers which are of type character and returns the roman number which is sum 
*					of two input roman numbers.
*
* INPUTS :
*       PARAMETERS:
*           char *input_Roman_Number1     First Roman input that needs to be added.
*           char *input_Roman_Number2     Second Roman input that needs to be added.
*       GLOBALS :
*           None
* OUTPUTS :
*       GLOBALS :
*            Uses ROMAN_NUMBER
*       RETURN :
*            Type:   Char*                Pointer to the character array which contains the result of the sum.
*            
* NOTES :    The logic to add two roman numbers is to first convert them into decimal, add the decimal formats of *            both the input. Convert the result into the Roman format again and return the reuslt.     
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*/
char * AddTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 ){
	memset(&ROMAN_NUMBER[0], '\0', sizeof(ROMAN_NUMBER));
	PROCESSERROR = false;
    long int num1,num2;
	if(!PROCESSERROR)
	{		
		num1 = romanToDecimal(input_Roman_Number1);
		num2 = romanToDecimal(input_Roman_Number2);
	}
	if(!PROCESSERROR)
	{
		decimalToRoman(num1+num2);
		//int j=0;
		//for( j=0;j<i;j++)
		//	printf("%c",ROMAN_NUMBER[j]);
	return  ROMAN_NUMBER;
	}
	else
		return "fail";

}
/*******************************************************************
* NAME :            char * SubtractTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 )
*
* DESCRIPTION :     Subtracts two Roman numbers which are of type character and returns the roman number which is *					  absolute value of difference between the two input roman numbers.
*
* INPUTS :
*       PARAMETERS:
*           char *input_Roman_Number1     First Roman input that needs to be added.
*           char *input_Roman_Number2     Second Roman input that needs to be added.
*       GLOBALS :
*           None
* OUTPUTS :
*       GLOBALS :
*            Uses ROMAN_NUMBER
*       RETURN :
*            Type:   Char*                Pointer to the character array which contains the result of the sum.
*            
* NOTES :    The logic to subtract two roman numbers is to first convert them into decimal, add the decimal *			 formats of *            both the input. Convert the result into the Roman format again and return 	*			 the reuslt.     
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*/
char * SubtractTwoRomanNumbers(char *input_Roman_Number1,char *input_Roman_Number2 ){
	PROCESSERROR = false;
	memset(&ROMAN_NUMBER[0], '\0', sizeof(ROMAN_NUMBER));
    long int num1,num2;
	if(!PROCESSERROR)
	{		
		num1 = romanToDecimal(input_Roman_Number1);
		num2 = romanToDecimal(input_Roman_Number2);
	}
	if(!PROCESSERROR)
	{
		printf("In CheckZero1");
		long int diff=0;
		diff = abs(num1-num2);
		
		if(diff != 0)
		{
			decimalToRoman(diff);
			return  ROMAN_NUMBER;
		}
		else
			return "zero";
	return  ROMAN_NUMBER;
	}
	else
		return "fail";

}

/*******************************************************************
* NAME :            int romanToDecimal(char* input_Roman_Number )
*
* DESCRIPTION :     Converts the input roman number to decimal equivalent 
*
* INPUTS :
*       PARAMETERS:
*           char* input_Roman_Number     Roman input that needs to be converted to decimal.
*       GLOBALS :
*           None
* OUTPUTS :
*       GLOBALS :
*            None
*       RETURN :
*            Type:   int                 Decimal equivalent of input roman number
*            
* NOTES :           
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*/
 
int romanToDecimal(char* input_Roman_Number )
{
	int i=0;
    long int number =0;
	while(input_Roman_Number[i]){        
         if(digitValue(input_Roman_Number[i]) < 0){
             printf("Invalid roman digit : %c",input_Roman_Number[i]);
			 PROCESSERROR= true;
             return 0;
         }
            
         if((strlen(input_Roman_Number) -i) > 2){
             if(digitValue(input_Roman_Number[i]) < digitValue(input_Roman_Number[i+2])){
                 printf("Invalid roman number");
				 PROCESSERROR= true;
                 return 0;
             }
         }

         if(digitValue(input_Roman_Number[i]) >= digitValue(input_Roman_Number[i+1]))
             number = number + digitValue(input_Roman_Number[i]);
         else{
             number = number + (digitValue(input_Roman_Number[i+1]) - digitValue(input_Roman_Number[i]));
             i++;
         }
         i++;
    }
 
	return number;
}
int digitValue(char c){

    int value=0;

    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }

    return value;
}
/*******************************************************************
* NAME :            void decimalToRoman(long int number)
*
* DESCRIPTION :     Converts the input decimal number to Roman equivalent 
*
* INPUTS :
*       PARAMETERS:
*           long int number             Roman input that needs to be converted to decimal.
*       GLOBALS :
*           
* OUTPUTS :
*       GLOBALS :
*            ROMAN_NUMBER				Modifies the ROMAN_NUMBER which keeps the result at the end.
*       RETURN :
*            Type:   void
*            
* NOTES :           
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*/


int i=0; 
void decimalToRoman(long int number)
{
	
	i=0;
    if(number <= 0){
         printf("Invalid number");
         
    }

    while(number != 0){

         if(number >= 1000){
             postdigits('M',number/1000);
             number = number - (number/1000) * 1000;
         }
         else if(number >=500){
             if(number < (500 + 4 * 100)){
                 postdigits('D',number/500);
                 number = number - (number/500) * 500;
             }
             else{
                 predigits('C','M');
                 number = number - (1000-100);
             }
         }
         else if(number >=100){
             if(number < (100 + 3 * 100)){
                 postdigits('C',number/100);
                 number = number - (number/100) * 100;
             }
             else{
                 predigits('L','D');
                 number = number - (500-100);
             }
         }
         else if(number >=50){
             if(number < (50 + 4 * 10)){
                 postdigits('L',number/50);
                 number = number - (number/50) * 50;
             }
             else{
                 predigits('X','C');
                 number = number - (100-10);
             }
         }
         else if(number >=10){
             if(number < (10 + 3 * 10)){
                 postdigits('X',number/10);
                 number = number - (number/10) * 10;
             }
             else{
                 predigits('X','L');
                 number = number - (50-10);
             }
         }
         else if(number >=5){
             if(number < (5 + 4 * 1)){
                 postdigits('V',number/5);
                 number = number - (number/5) * 5;
             }
             else{
                 predigits('I','X');
                 number = number - (10-1);
             }
         }
         else if(number >=1){
             if(number < 4){
                 postdigits('I',number/1);
                 number = number - (number/1) * 1;
				 
             }
             else{
                 predigits('I','V');
                 number = number - (5-1);
             }
         }
    }
	
} 
void predigits(char c1,char c2){
    ROMAN_NUMBER[i++] = c1;
    ROMAN_NUMBER[i++] = c2;
	//
}

void postdigits(char c,int n){
    int j;
    for(j=0;j<n;j++)
         ROMAN_NUMBER[i++] = c;   
}