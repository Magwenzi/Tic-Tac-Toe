/* Include  Section */
#include <reg52.h>												// Standard 8052 SFR : File
#include <stdio.h>												// For "sprintf" Function
#include "extra.h"											// more functions

// ************************************** 
//  forward references  
// ************************************** 
/*
const unsigned char FONT6x8[97][8]; 
const unsigned char FONT8x8[97][8]; 
const unsigned char FONT8x16[97][16]; 
void LCDWrite130x130bmp(void); 
void LCDClearScreen(void); 
void LCDSetXY(int x, int y); 
void LCDSetPixel(int  x, int  y, int  color); 
void LCDSetLine(int x1, int y1, int x2, int y2, int color); 
void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color); 
void LCDSetCircle(int x0, int y0, int radius, int color); 
void LCDPutChar(char c, int  x, int  y, int size, int fcolor, int bcolor); 
void LCDPutString (char *lcd_string, const char *font_style, unsigned char x, unsigned char y,  
                   unsigned char fcolor, unsigned char bcolor); 
void Delay (unsigned long a); 


// 12-bit color definitions 
#define WHITE    0xFFF 
#define BLACK    0x000 
#define RED    0xF00 
#define GREEN    0x0F0 
#define BLUE    0x00F 
#define CYAN    0x0FF 
#define MAGENTA  0xF0F 
#define YELLOW   0xFF0 
#define BROWN    0xB22 
#define ORANGE   0xFA0 
#define PINK    0xF6A     
*/

char board [4][4] ;
char board3 [3][3];

    int player = 0;
    int winner = 0;
    int row = 0;
    int column = 0;
    int line = 0;
		int i = 0;
		unsigned int tx1, ty1, tx2, ty2, tsize;
		unsigned char one = 0, two = 0, draw = 0, choice, end = 1;
		int hi,lo;

/******************
User def func
******************/
unsigned char board3x3 (void);
unsigned char board4x4 (void);
unsigned char button (void);
unsigned char buttonC (void);
unsigned char buttonR (void);

/* Main Program Start Here */
void main (void) 
{
//	char input ;
 

	
	LCD_Initial();	 											// Initial LCD-NOKIA6610

while(end){
	LCDClearScreen(WHITE);	
	
		do{

	// Choose game
	LCDPutStr("Select Game:", 10, 120, LARGE, WHITE, BLACK);
	LCDPutStr("Press button1", 10, 110, MEDIUM, BROWN, WHITE);
	LCDPutStr("for 3x3", 10, 100, MEDIUM, BLUE, WHITE);
	LCDPutStr("Press button2", 10, 90, MEDIUM, BROWN, WHITE);
	LCDPutStr("for 4x4", 10, 80, MEDIUM, BLUE, WHITE);
	
	choice = button();
	}while(choice>1);

	
	LCDClearScreen(WHITE);
//	tx1 = ty1 = tx2 = ty2 = 46;
//	tsize = 23;
// 	for (row =0; row<3 ; row++ ){
// 		for (column =0; column<3 ; column++ ){
// 			LCDSetRect(tx1+2, ty1+2, tx2+tsize, ty2+tsize, FILL, WHITE);
// 			ty1 += tsize;
// 			ty2 = ty1;
// 		}
// 		tx1 += tsize;
// 		tx2 = tx1;
// 	}
//	LCDWrite130x130bmp();									//Display bmp

	LCDSetRect(46, 46, 126, 126, FILL, BLACK); 
	
if(choice == 0){
	do{

	// Display Games
  LCDPutChar(one+two+draw+0x30, 110, 113, MEDIUM, BLUE, WHITE);				
	
	choice = board3x3();
	if (choice  == 0) draw +=1; 
	if (choice  == 1) one +=1; 
	if (choice  == 2) two +=1;

	}while(one < 5|| two < 5 );

	if( one>5||two>5){
		LCDClearScreen(BLACK);	
		LCDPutStr("Player:", 10, 120, LARGE, WHITE, BLACK);
		LCDPutChar(winner+0x30, 10, 110, MEDIUM, BLUE, WHITE);
		LCDPutStr("Has Won the game", 10, 100, MEDIUM, BROWN, WHITE);
		LCDPutStr("Press button", 10, 100, MEDIUM, RED, WHITE);
		
		button();
	}
	
	player = 0;
  winner = 0;
	one = 0;
	two = 0;
	draw = 0;
}

if(choice == 1){
	do{

	// Display Games
  LCDPutChar(one+two+draw+0x30, 110, 113, MEDIUM, BLUE, WHITE);				
	
	choice = board4x4();
	if (choice  == 0) draw +=1; 
	if (choice  == 1) one +=1; 
	if (choice  == 2) two +=1;

	}while(one < 5|| two < 5 );
	
	if( one>5||two>5){
		LCDClearScreen(BLACK);	
		LCDPutStr("Player:", 10, 120, LARGE, WHITE, BLACK);
		LCDPutChar(winner+0x30, 10, 110, MEDIUM, BLUE, WHITE);
		LCDPutStr("Has Won the game", 10, 100, MEDIUM, BROWN, WHITE);
		LCDPutStr("Press button", 10, 100, MEDIUM, RED, WHITE);
		
		button();
	}
	
	player = 0;
  winner = 0;
	one = 0;
	two = 0;
	draw = 0;
}

}
 	
	LCDSetCircle(1, 1 , 5, BLUE);
	LCDSetRect(130, 1, 21,21, 1, RED);
	LCDPutStr("pString", 130, 130, 3,BLUE,RED);

	return;
}
/*
void drawmove_3 (void){
	
	LCDSetLine(50+26*, 50, 70, 70, BLACK);
	LCDSetLine(50, 70, 70, 50, BLACK);

	LCDSetCircle(60, 60, 10, BLACK);
//         LCDPutChar(board3[0][0], 12, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[0][1], 30, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[0][2], 48, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[1][0], 12, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[1][1], 30, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[1][2], 48, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[2][0], 12, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[2][1], 30, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board3[2][2], 48, 30, MEDIUM, BLACK, WHITE);

}
void drawmove_4 (void){
	
 	for (row =0; row<4 ; row++ )
 		for (column =0; column<4 ; column++ )
 			LCDSetRect(47+20*row, 47+20*column, 65+20*row, 65+20*column, FILL, WHITE);

//         LCDPutChar(board[0][0], 12, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[0][1], 30, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[0][2], 48, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[0][3], 64, 68, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[1][0], 12, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[1][1], 30, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[1][2], 48, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[1][3], 64, 48, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[2][0], 12, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[2][1], 30, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[2][2], 48, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[2][3], 64, 30, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[3][0], 12, 12, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[3][1], 30, 12, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[3][2], 48, 12, MEDIUM, BLACK, WHITE);
//         LCDPutChar(board[3][3], 64, 12, MEDIUM, BLACK, WHITE);

}
*/
unsigned char button (void) {
	unsigned char temp;
	
while (1){
		
  if (!button1)  // column 0 is pressed 
  {  temp = 0; break;  } 
  else if (!button2)  // column 1 is pressed 
  {  temp = 1; break;  } 
	else if (!button3)  // column 2 is pressed 
  {  temp = 2; break;   } 
	else if (!button4)  // column 3 is pressed 
  {  temp = 3; break;   } 
  else    // no key pressed 
  { continue;  } 
	
	}
	  delay(20000);
	return temp;
}


unsigned char buttonC (void) {
	unsigned char temp;
	
	LCDPutStr("Col", 104, 97,MEDIUM, BLACK, CYAN);
	while (1){
		
  if (!button1)  // column 0 is pressed 
  {  temp = 0; break;  } 
  else if (!button2)  // column 1 is pressed 
  {  temp = 1; break;  } 
	else if (!button3)  // column 2 is pressed 
  {  temp = 2; break;   } 
	else if (!button4)  // column 3 is pressed 
  {  temp = 3; break;   } 
  else    // no key pressed 
  { continue;  } 
	
	}
	  delay(20000);
	LCDPutStr("   ", 104, 97,1, WHITE, WHITE);
	
	return temp;
}
unsigned char buttonR (void) {
	unsigned char temp;
	LCDPutStr("Row", 104, 97,MEDIUM, BLACK, CYAN);

	while (1){
		
  if (!button1)  // column 0 is pressed 
  {  temp = 0; break;  } 
  else if (!button2)  // column 1 is pressed 
  {  temp = 1; break;  } 
	else if (!button3)  // column 2 is pressed 
  {  temp = 2; break;   } 
	else if (!button4)  // column 3 is pressed 
  {  temp = 3; break;   } 
  else    // no key pressed 
  { continue;  } 
	
	}
	  delay(20000); 

	LCDPutStr("  ", 104, 97,MEDIUM, WHITE, WHITE);
	return temp;
}
unsigned char board3x3 (void){

winner = 0;
board3 [0][0] = '1';
board3 [0][1] = '2';
board3 [0][2] = '3';
board3 [1][0] = '4';
board3 [1][1] = '5';
board3 [1][2] = '6';
board3 [2][0] = '7';
board3 [2][1] = '8';
board3 [2][2] = '9';

	// Draw the 3x3 board game
	for (row =0; row<3 ; row++ )
 		for (column =0; column<3 ; column++ )
 			LCDSetRect(48+26*row, 48+26*column, 72+26*row, 72+26*column, FILL, WHITE);
	
for (i = 0; i<9 && winner==0; i++)
    {
			// Display Moves
      LCDPutChar(i+0x30, 46, 114, MEDIUM, BLUE, RED);
			
			/**********
			// show the 3x3 game
			drawgrid_3();
			***********/
      
			player = player%2 + 1;
			// Display player
      LCDPutChar(player+0x30, 52, 98, MEDIUM, GREEN, PINK);


//display Won loss and draw
			if (player == 1){
				    LCDPutChar(one+0x30, 120, 71, MEDIUM, GREEN, WHITE);
				    LCDPutChar(two+0x30, 120, 59, MEDIUM, BLUE, WHITE);
				    LCDPutChar(draw+0x30, 120, 47, MEDIUM, BLACK, WHITE);}
			else {
				    LCDPutChar(two+0x30, 120, 71, MEDIUM, GREEN, WHITE);
				    LCDPutChar(one+0x30, 120, 59, MEDIUM, BLUE, WHITE);
				    LCDPutChar(draw+0x30, 120, 47, MEDIUM, BLACK, WHITE);}


		do{
            row = buttonR();
            column = buttonC();
				
		}while( board3[row][column]== 'X' || board3[row][column]== 'O'|| row == 3 || column == 3);
    
		board3[row][column] = (player == 1) ? 'X' : 'O';
		
		// draw x/o
		if (board3[row][column] == 'X') {
			LCDSetLine(50+26*(2-row), 50+26*column, 70+26*(2-row), 70+26*column, BLACK);
			LCDSetLine(50+26*(2-row), 70+26*column, 70+26*(2-row), 50+26*column, BLACK);
		}
		else if (board3[row][column] == 'O'){
			LCDSetCircle(60+26*(2-row), 60+26*column, 10, RED);
		}
 
        if((board3[0][0]==board3[1][1] && board3[0][0]==board3[2][2]) ||
           (board3[0][2]==board3[1][1] && board3[0][2]==board3[2][0]))
           winner = player;
        else
            for(line = 0; line <=2; line++)
                if((board3[line][0]==board3[line][1] && board3[line][0]==board3[line][2])||
                    (board3[0][line]==board3[1][line] && board3[0][line]==board3[2][line]))
                    winner = player;
    }
		
return winner;
}
unsigned char board4x4 (void){

winner = 0;
board[0][0]	= '1';
board[0][1]	= '2';
board[0][2]	= '3';
board[0][3]	= '4';
board[1][0]	= '5';
board[1][1]	= '6';
board[1][2]	= '7';
board[1][3]	= '8';
board[2][0]	= '9';
board[2][1]	= 'a';
board[2][2]	= 'b';
board[2][3]	= 'c';
board[3][0]	= 'd';
board[3][1]	= 'e';
board[3][2]	= 'f';
board[3][3]	= 'g';

	
 	for (row =0; row<4 ; row++ )
 		for (column =0; column<4 ; column++ )
 			LCDSetRect(47+20*row, 47+20*column, 65+20*row, 65+20*column, FILL, WHITE);
	
// For the 4x4 game
		for (i = 0; i<16 && winner==0; i++)
    {
			hi = i%10;
			lo = i/10;
			// Display Moves
      LCDPutChar(lo+0x30, 46, 114, MEDIUM, BLUE, RED);
      LCDPutChar(hi+0x30, 54, 114, MEDIUM, BLUE, RED);
			
			// show the 4x4 game
			//drawgrid_4();
        player = player%2 + 1;
			// Display player
      LCDPutChar(player+0x30, 52, 98, MEDIUM, GREEN, PINK);

//display Won loss and draw
			if (player == 1){
				    LCDPutChar(one+0x30, 120, 71, MEDIUM, GREEN, WHITE);
				    LCDPutChar(two+0x30, 120, 59, MEDIUM, BLUE, WHITE);
				    LCDPutChar(draw+0x30, 120, 47, MEDIUM, BLACK, WHITE);}
			else {
				    LCDPutChar(two+0x30, 120, 71, MEDIUM, GREEN, WHITE);
				    LCDPutChar(one+0x30, 120, 59, MEDIUM, BLUE, WHITE);
				    LCDPutChar(draw+0x30, 120, 47, MEDIUM, BLACK, WHITE);}


		do{
            row = buttonR();
            column = buttonC();
				
		}while( board[row][column]== 'X' || board[row][column]== 'O');
        
		board[row][column] = (player == 1) ? 'X' : 'O';

		// draw x/o
		if (board[row][column] == 'X') {
			LCDSetLine(49+20*(3-row), 49+20*column, 63+20*(3-row), 63+20*column, BLACK);
			LCDSetLine(49+20*(3-row), 63+20*column, 63+20*(3-row), 49+20*column, BLACK);
		}
		else if (board[row][column] == 'O'){
			LCDSetCircle(56+20*(3-row), 56+20*column, 7, RED);
		}
 
 
        if((board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]==board[3][3]) ||
           (board[0][3]==board[1][2] && board[0][3]==board[2][1] && board[0][0]==board[3][0] ))
           winner = player;
        else
            for(line = 0; line <=3; line++)
                if((board[line][0]==board[line][1] && board[line][0]==board[line][2] && board[line][0]==board[line][3])||
                    (board[0][line]==board[1][line] && board[0][line]==board[2][line] && board[0][line]==board[3][line]))
                    winner = player;
    }
		return winner;
}
