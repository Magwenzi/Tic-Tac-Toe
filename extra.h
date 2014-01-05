#ifndef EXTRA_H
#define EXTRA_H


#include "lcd_const.h"											// more functions
//#include "bmp.h"											// more functions

/********************/
/* Send Data to LCD */
/********************/
void Send_Data(unsigned char LCD_Data) 
{   
   unsigned char Bit = 0;										// Bit Counter

   LCD_CS = 1;													// Makesure CS = Disable
   LCD_SCLK = 0;  												// Standby SCLK 

   LCD_CS = 0;													// Start CS = Enable
   LCD_SDATA = 1;   											// D/C# = 1(Data)
   LCD_SCLK = 1;												// Strobe Signal Bit(SDATA)
   LCD_SCLK = 0;  												// Standby SCLK 

   for (Bit = 0; Bit < 8; Bit++)								// 8 Bit Write
   {
       LCD_SCLK = 0;  											// Standby SCLK 
	   LCD_SDATA = (bit)((LCD_Data & 0x80) >> 7);				// MSB First of Data Bit(7..0)
	   LCD_SCLK = 1;											// Strobe Signal Bit(SDATA)
	   LCD_Data <<= 1;	 										// Next Bit Data
   } 
   LCD_SCLK = 0;  												// Standby SCLK 
   LCD_CS = 1;													// Stop CS = Disable  
}

/***********************/
/* Send Command to LCD */
/***********************/
void Send_CMD(unsigned char LCD_Command) 
{
   unsigned char Bit = 0;										// Bit Counter

   LCD_CS = 1;													// Makesure CS = Disable
   LCD_SCLK = 0;  												// Prepared SCLK

   LCD_CS = 0;													// Start CS = Enable
   LCD_SDATA = 0;   											// D/C# = 0(Command)
   LCD_SCLK = 1;												// Strobe Signal Bit(SDATA)
   LCD_SCLK = 0;  												// Standby SCLK 
   
   for (Bit = 0; Bit < 8; Bit++)								// 8 Bit Write
   {
       LCD_SCLK = 0;  											// Standby SCLK 
	   LCD_SDATA = (bit)((LCD_Command & 0x80) >> 7);			// MSB First of Data Bit(7..0)
	   LCD_SCLK = 1;											// Strobe Signal Bit(SDATA)
	   LCD_Command <<= 1;	 									// Next Bit Data
   }  
   LCD_SCLK = 0;  												// Standby SCLK 
   LCD_CS = 1;													// Stop CS = Disable
}
/*******************************************/
/* Long Delay Time Function(1..4294967295) */
/*******************************************/
void delay(unsigned long i)
{
  while(i > 0) {i--;}											// Loop Decrease Counter	
  return;
}
/*************************/
/* Initial LCD-NOKIA6610 */
/*************************/
void LCD_Initial(void)
{
   LCD_RESET = 0;												// Start Reset
   LCD_SCLK=0;    												// Standby SCLK
   LCD_CS=1;													// Disable CS
   LCD_SDATA=1;													// Standby SDATA
   LCD_BL=1; 													// Black Light ON = 100%
   delay(5000);													// Reset Pulse Time
   LCD_RESET=1;													// Release Reset

// Sleep out  (command 0x11) 
  Send_CMD(SLEEPOUT); 
   
  // Inversion on  (command 0x20) 
	// Send_CMD(INVON);    // seems to be required for this controller 
 
  // Color Interface Pixel Format  (command 0x3A) 
  Send_CMD(COLMOD); 
  Send_Data(0x03);      // 0x03 = 12 bits-per-pixel 
 
  // Memory access controler  (command 0x36) 
  Send_CMD(MADCTL); 
  Send_Data(0x08);      // 0xC0 = mirror x and y default = 0x00, reverse rgb 
   
  // Write contrast  (command 0x25) 
  Send_CMD(SETCON); 
  Send_Data(0x30);      // contrast 0x30  
  delay(2000); 
 
  // Display On  (command 0x29) 
  Send_CMD(DISPON); 
}

//  ***************************************************************************** 
//               LCDWrite130x130bmp.c 
//  
//     Writes the entire screen from a bmp file  
//     Uses Olimex BmpToArray.exe utility 
// 
//     Inputs:  picture in bmp.h 
// 
//    Author:  Olimex, James P Lynch     July 7, 2007 
//  *****************************************************************************  
/*void LCDWrite130x130bmp(void) { 
   
  long      j;      // loop counter 
   
  // Memory access controler  (command 0x36) 
    Send_CMD(MADCTL); 
    Send_Data(0x08);     // no mirror Y (temporary to satisfy Olimex bmptoarray utility) 
							//48
  // Display OFF 
  Send_CMD(DISPOFF); 
 
  // Column address set  (command 0x2A) 
  Send_CMD(CASET); 
  Send_Data(0); 
  Send_Data(131); 
 
  // Page address set  (command 0x2B) 
  Send_CMD(PASET); 
  Send_Data(0); 
  Send_Data(131); 
   
  // WRITE MEMORY 
  Send_CMD(RAMWR); 
  for (j = 0; j < sizeof(bmp); j++) { 
    Send_Data(bmp[j]); 
  } 
 
  // Memory access controler  (command 0x36) 
    Send_CMD(MADCTL); 
    Send_Data(0xC8);     // restore to (mirror x and y, reverse rgb) 
						//C8
  // Display On 
  Send_CMD(DISPON); 
return;  
} 
		*/
//  ***************************************************************************** 
//               LCDClearScreen.c 
//  
//     Clears the LCD screen to single color (Color) 
//      
//     Inputs:  none 
// 
//    Author:  James P Lynch     July 7, 2007 
//  *****************************************************************************  
void LCDClearScreen(int Color) { 
   
  long  i;      // loop counter 
 
  // Row address set  (command 0x2B) 
  Send_CMD(PASET); 
  Send_Data(0); 
  Send_Data(131); 
 
  // Column address set  (command 0x2A) 
  Send_CMD(CASET); 
  Send_Data(0); 
  Send_Data(131); 
 
  // set the display memory to BLACK 
  Send_CMD(RAMWR); 
  for (i = 0; i < ((131 * 131) / 2); i++) { 
    Send_Data((Color >> 4) & 0xFF); 
    Send_Data(((Color & 0xF) << 4) | ((Color >> 8) & 0xF)); 
    Send_Data(Color & 0xFF);  } 
		return;
} 



// ***************************************************************************** 
//               LCDSetXY.c 
//  
//     Sets the Row and Column addresses 
//      
//     Inputs:    x  =   row address (0 .. 131) 
//        y  =   column address  (0 .. 131) 
// 
// 
//     Returns:   nothing   
// 
//    Author:  James P Lynch     July 7, 2007 
//  *****************************************************************************  
void LCDSetXY(int  x, int  y) { 
   
  // Row address set  (command 0x2B) 
  Send_CMD(PASET); 
  Send_Data(x); 
  Send_Data(x); 
 
  // Column address set  (command 0x2A) 
  Send_CMD(CASET); 
  Send_Data(y); 
  Send_Data(y); 
		return;
}
//  ************************************************************************************* 
//               LCDSetPixel.c 
//  
//  Lights a single pixel in the specified color at the specified x and y addresses 
//      
//  Inputs:   x     =   row address (0 .. 131) 
//      y     =   column address  (0 .. 131) 
//      color =   12-bit color value  rrrrggggbbbb 
//        rrrr = 1111 full red 
//              : 
//          0000 red is off 
// 
//        gggg = 1111 full green 
//              : 
//          0000 green is off 
// 
//        bbbb = 1111 full blue 
//              : 
//          0000 blue is off 
// 
//     Returns:   nothing  
// 
//    Note: see lcd.h for some sample color settings  
// 
//    Author:  James P Lynch     July 7, 2007 
//  *************************************************************************************  
void LCDSetPixel(int  x, int  y, int  color) { 
 
  LCDSetXY(x, y); 
  Send_CMD(RAMWR); 
  Send_Data((unsigned char)((color >> 4) & 0xFFFF)); 
  Send_Data((unsigned char)(((color & 0x0F) << 4) | 0x00)); 
  Send_CMD(NOP); 
} 


//  ************************************************************************************************* 
//               LCDSetLine.c 
//  
//  Draws a line in the specified color from (x0,y0) to (x1,y1)  
//      
//  Inputs:   x     =   row address (0 .. 131) 
//      y     =   column address  (0 .. 131) 
//      color =   12-bit color value  rrrrggggbbbb 
//        rrrr = 1111 full red 
//              : 
//          0000 red is off 
// 
//        gggg = 1111 full green 
//              : 
//          0000 green is off 
// 
//        bbbb = 1111 full blue 
//              : 
//          0000 blue is off 
// 
//  Returns:   nothing  
// 
//  Note:  good write-up on this algorithm in Wikipedia (search for Bresenham's line algorithm) 
//    see lcd.h for some sample color settings   
// 
//  Authors:   Dr. Leonard McMillan, Associate Professor UNC 
//      Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962) 
// 
//      Note: taken verbatim from Professor McMillan's presentation:  
//            http://www.cs.unc.edu/~mcmillan/comp136/Lecture6/Lines.html 
// 
//  *************************************************************************************************  
void LCDSetLine(int x0, int y0, int x1, int y1, int color) { 
 
        int dy = y1 - y0; 
        int dx = x1 - x0; 
        int stepx, stepy; 
if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; } 
        if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; } 
        dy <<= 1;        // dy is now 2*dy 
        dx <<= 1;        // dx is now 2*dx 
 
  LCDSetPixel(x0, y0, color); 
 
        if (dx > dy) { 
            int fraction = dy - (dx >> 1);  // same as 2*dy - dx 
            while (x0 != x1) { 
                if (fraction >= 0) { 
                    y0 += stepy; 
                    fraction -= dx;    // same as fraction -= 2*dx 
                } 
                x0 += stepx; 
                fraction += dy;    // same as fraction -= 2*dy 
                LCDSetPixel(x0, y0, color); 
            } 
        } else { 
            int fraction = dx - (dy >> 1); 
            while (y0 != y1) { 
                if (fraction >= 0) { 
                    x0 += stepx; 
                    fraction -= dy; 
                } 
                y0 += stepy; 
                fraction += dx; 
                LCDSetPixel(x0, y0, color); 
            } 
        } 
		return;
}
//  ***************************************************************************************** 
//               LCDSetRect.c 
//  
//  Draws a rectangle in the specified color from (x1,y1) to (x2,y2) 
//  Rectangle can be filled with a color if desired  
//      
//  Inputs:   x     =   row address (0 .. 131) 
//      y     =   column address  (0 .. 131) 
//      fill  =   0=no fill, 1-fill entire rectangle  
//      color =   12-bit color value for lines  rrrrggggbbbb 
//        rrrr = 1111 full red 
//          : 
//        0000 red is off 
// 
//        gggg = 1111 full green 
//          : 
//        0000 green is off 
// 
//        bbbb = 1111 full blue 
//          : 
//        0000 blue is off 
//   Returns:   nothing  
// 
//    Notes: 
// 
//    The best way to fill a rectangle is to take advantage of the "wrap-around" featute 
//    built into the Philips PCF8833 controller. By defining a drawing box, the memory can 
//    be simply filled by successive memory writes until all pixels have been illuminated. 
// 
//      1.  Given the coordinates of two opposing corners (x0, y0) (x1, y1) 
//          calculate the minimums and maximums of the coordinates 
// 
//        xmin = (x0 <= x1) ? x0 : x1; 
//        xmax = (x0 > x1) ? x0 : x1; 
//        ymin = (y0 <= y1) ? y0 : y1; 
//        ymax = (y0 > y1) ? y0 : y1; 
// 
//      2. Now set up the drawing box to be the desired rectangle 
// 
//        Send_CMD(PASET);    // set the row boundaries 
//        Send_Data(xmin); 
//        Send_Data(xmax); 
//        Send_CMD(CASET);    // set the column boundaries 
//        Send_Data(ymin); 
//        Send_Data(ymax); 
// 
//      3. Calculate the number of pixels to be written divided by 2 
// 
//        NumPixels = ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1) 
// 
//        You may notice that I added one pixel to the formula.  
//        This covers the case where the number of pixels is odd and we  
//        would lose one pixel due to rounding error. In the case of 
//        odd pixels, the number of pixels is exact.  
//        in the case of even pixels, we have one more pixel than 
//        needed, but it cannot be displayed because it is outside 
//        the drawing box. 
// 
//        We divide by 2 because two pixels are represented by three bytes. 
//        So we work through the rectangle two pixels at a time. 
// 
//      4.  Now a simple memory write loop will fill the rectangle 
// 
//        for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) { 
//          Send_Data((color >> 4) & 0xFF); 
//          Send_Data(((color & 0xF) << 4) | ((color >> 8) & 0xF)); 
//          Send_Data(color & 0xFF); 
//        } 
// 
//    In the case of an unfilled rectangle, drawing four lines with the Bresenham line 
//    drawing algorithm is reasonably efficient. 
// 
//    Author:  James P Lynch      July 7, 2007 
//  *****************************************************************************************  
 
void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color) { 
  int   xmin, xmax, ymin, ymax; 
  int    i; 
   
  // check if the rectangle is to be filled 
  if (fill == FILL) { 
     
    // best way to create a filled rectangle is to define a drawing box 
    // and loop two pixels at a time 
     
    // calculate the min and max for x and y directions 
    xmin = (x0 <= x1) ? x0 : x1; 
    xmax = (x0 > x1) ? x0 : x1; 
    ymin = (y0 <= y1) ? y0 : y1; 
    ymax = (y0 > y1) ? y0 : y1; 
     
    // specify the controller drawing box according to those limits 
    // Row address set  (command 0x2B) 
    Send_CMD(PASET); 
    Send_Data(xmin); 
    Send_Data(xmax); 
     
    // Column address set  (command 0x2A) 
    Send_CMD(CASET); 
    Send_Data(ymin); 
    Send_Data(ymax); 
     
    // WRITE MEMORY 
    Send_CMD(RAMWR); 
     
    // loop on total number of pixels / 2 
    for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) { 
       
      // use the color value to output three data bytes covering two pixels 
      Send_Data((color >> 4) & 0xFF); 
      Send_Data(((color & 0xF) << 4) | ((color >> 8) & 0xF)); 
      Send_Data(color & 0xFF); 
    } 
		} else { 
      
       // best way to draw un unfilled rectangle is to draw four lines 
    LCDSetLine(x0, y0, x1, y0, color); 
    LCDSetLine(x0, y1, x1, y1, color); 
    LCDSetLine(x0, y0, x0, y1, color); 
    LCDSetLine(x1, y0, x1, y1, color); 
    } 
		return;
}

//  ************************************************************************************* 
//               LCDSetCircle.c 
//  
//  Draws a line in the specified color at center (x0,y0) with radius  
//      
//  Inputs:   x0     =   row address (0 .. 131) 
//      y0     =   column address  (0 .. 131) 
//      radius =   radius in pixels 
//      color  =   12-bit color value  rrrrggggbbbb 
// 
//  Returns:   nothing   
// 
//  Author:    Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962) 
// 
//         Note: taken verbatim Wikipedia article on Bresenham's line algorithm   
//          http://www.wikipedia.org 
// 
//  *************************************************************************************  
 
void LCDSetCircle(int x0, int y0, int radius, int color) { 
  int f = 1 - radius; 
  int ddF_x = 0; 
  int ddF_y = -2 * radius; 
  int x = 0; 
  int y = radius; 
  
  LCDSetPixel(x0, y0 + radius, color); 
  LCDSetPixel(x0, y0 - radius, color); 
  LCDSetPixel(x0 + radius, y0, color); 
  LCDSetPixel(x0 - radius, y0, color); 
  
  while (x < y) { 
    if (f >= 0) { 
      y--; 
      ddF_y += 2; 
      f += ddF_y; 
    } 
    x++; 
    ddF_x += 2; 
    f += ddF_x + 1;     
    LCDSetPixel(x0 + x, y0 + y, color); 
    LCDSetPixel(x0 - x, y0 + y, color); 
    LCDSetPixel(x0 + x, y0 - y, color); 
    LCDSetPixel(x0 - x, y0 - y, color); 
    LCDSetPixel(x0 + y, y0 + x, color); 
    LCDSetPixel(x0 - y, y0 + x, color); 
    LCDSetPixel(x0 + y, y0 - x, color); 
    LCDSetPixel(x0 - y, y0 - x, color); 
  } 
} 
 
//  ***************************************************************************** 
//               LCDPutChar.c 
//  
//     Draws an ASCII character at the specified (x,y) address and color 
//      
//     Inputs:    c       =   character to be displayed        
//        x       =   row address (0 .. 131) 
//        y       =   column address  (0 .. 131) 
//        size    =   font pitch (SMALL, MEDIUM, LARGE) 
//             fcolor  =   12-bit foreground color value    rrrrggggbbbb 
//             bcolor  =   12-bit background color value    rrrrggggbbbb 
// 
// 
//     Returns:   nothing   
// 
// 
//        Notes:  Here's an example to display "E" at address (20,20) 
// 
//      LCDPutChar('E', 20, 20, MEDIUM, WHITE, BLACK); 
// 
//            (27,20)        (27,27) 
//          |             | 
//          |             | 
//             ^  V             V 
//             :  _ # # # # # # #   0x7F 
//             :  _ _ # # _ _ _ #   0x31 
//             :  _ _ # # _ # _ _   0x34 
//             x  _ _ # # # # _ _   0x3C 
//             :  _ _ # # _ # _ _   0x34 
//             :  _ _ # # _ _ _ #   0x31 
//             :  _ # # # # # # #   0x7F 
//             :  _ _ _ _ _ _ _ _   0x00 
// 
//          ------y-------> 
//          ^             ^ 
//          |             | 
//          |             | 
//            (20,20)       (20,27) 
// 
// 
//  The most efficient way to display a character is to make use of the "wrap-around" feature 
//  of the Philips PCF8833 LCD controller chip.   
// 
//  Assume that we position the character at (20, 20)  that's a  (row, col) specification. 
//  With the row and column address set commands, you can specify an 8x8 box for the SMALL and MEDIUM 
//  characters or a 16x8 box for the LARGE characters. 
// 
//      Send_CMD(PASET);    // set the row drawing limits 
//      Send_Data(20);      // 
//      Send_Data(27);      // limit rows to (20, 27) 
//  
//      Send_CMD(CASET);    // set the column drawing limits 
//      Send_Data(20);      //  
//      Send_Data(27);      // limit columns to (20,27) 
// 
//  When the algorithm completes col 27, the column address wraps back to 20 
//  At the same time, the row address increases by one (this is done by the controller) 
// 
//  We walk through each row, two pixels at a time. The purpose is to create three 
//  data bytes representing these two pixels in the following format (as specified by Philips 
//  for RGB 4 : 4 : 4 format (see page 62 of PCF8833 controller manual). 
// 
//      Data for pixel 0:  RRRRGGGGBBBB 
//      Data for Pixel 1:  RRRRGGGGBBBB 
// 
//      Send_CMD(RAMWR);    // start a memory write (96 data bytes to follow) 
// 
//      Send_Data(RRRRGGGG);    // first pixel, red and green data 
//      Send_Data(BBBBRRRR);    // first pixel, blue data; second pixel, red data 
//      Send_Data(GGGGBBBB);    // second pixel, green and blue data 
//        : 
//      and so on until all pixels displayed! 
//        : 
//      Send_CMD(NOP);      // this will terminate the RAMWR command 
// 
// 
//    Author:  James P Lynch    July 7, 2007 
//  ***************************************************************************** 

 void LCDPutChar(char c, int  x, int  y, int Size, int fColor, int bColor) { 
   
//  extern const unsigned char FONT6x8[97][8]; 
//  extern const unsigned char FONT8x8[97][8]; 
//  extern const unsigned char FONT8x16[97][16]; 
     
  int      i,j; 
  unsigned int    nCols; 
  unsigned int    nRows; 
  unsigned int    nBytes; 
  unsigned char    PixelRow; 
  unsigned char    Mask; 
  unsigned int    Word0; 
  unsigned int    Word1; 
  unsigned char    *pFont; 
   
  unsigned char    *pChar; 
  unsigned char    *FontTable[] = {(unsigned char *)FONT6x8,  
              (unsigned char *)FONT8x8,  
              (unsigned char *)FONT8x16};  
   
  // get pointer to the beginning of the selected font table 
  pFont = (unsigned char *)FontTable[Size];   
   
  // get the nColumns, nRows and nBytes 
  nCols = *pFont; 
  nRows = *(pFont + 1); 
  nBytes = *(pFont + 2); 
 
  // get pointer to the last byte of the desired character 
  pChar = pFont + (nBytes * (c - 0x1F)) + nBytes - 1; 
   
  // Memory access controler  (command 0x36) 
    Send_CMD(MADCTL); 
    Send_Data(0x40); 
							
  // Row address set  (command 0x2B) 
  Send_CMD(PASET); 
  Send_Data(x); 
  Send_Data(x + nRows - 1); 
   
  // Column address set  (command 0x2A) 
  Send_CMD(CASET); 
  Send_Data(y); 
  Send_Data(y + nCols - 1); 
   
  // WRITE MEMORY 
  Send_CMD(RAMWR); 
   
  // loop on each row, working backwards from the bottom to the top 
  for (i = nRows - 1; i >= 0; i--) { 
     
    // copy pixel row from font table and then decrement row 
    PixelRow = *pChar--; 
   
    // loop on each pixel in the row (left to right) 
    // Note: we do two pixels each loop 
    Mask = 0x80; 
    for (j = 0; j < nCols; j += 2) { 
     
      // if pixel bit set, use foreground color; else use the background color 
      // now get the pixel color for two successive pixels 
      if ((PixelRow & Mask) == 0) 
        Word0 = bColor; 
      else 
        Word0 = fColor; 
      Mask = Mask >> 1; 
      if ((PixelRow & Mask) == 0) 
        Word1 = bColor; 
      else 
        Word1 = fColor; 
      Mask = Mask >> 1; 
       
      // use this information to output three data bytes 
      Send_Data((Word0 >> 4) & 0xFF); 
      Send_Data(((Word0 & 0xF) << 4) | ((Word1 >> 8) & 0xF)); 
      Send_Data(Word1 & 0xFF); 
    }   
  } 
 // Memory access controler  (command 0x36) 
    Send_CMD(MADCTL); 
    Send_Data(0xC8);     // restore to (mirror x and y, reverse rgb) 

  // terminate the Write Memory command 
  Send_CMD(NOP);   
} 

//  ************************************************************************************************* 
//               LCDPutStr.c 
//  
//     Draws a null-terminates character string at the specified (x,y) address, size and color 
//      
//     Inputs:    pString =   pointer to character string to be displayed        
//        x       =   row address (0 .. 131) 
//        y       =   column address  (0 .. 131) 
//        Size    =   font pitch (SMALL, MEDIUM, LARGE) 
//        fColor  =   12-bit foreground color value   rrrrggggbbbb 
//        bColor  =   12-bit background color value   rrrrggggbbbb 
// 
// 
//     Returns:   nothing   
// 
//     Notes:  Here's an example to display "Hello World!" at address (20,20) 
// 
//          LCDPutChar("Hello World!", 20, 20, LARGE, WHITE, BLACK); 
// 
// 
//    Author:  James P Lynch    July 7, 2007 
//  *************************************************************************************************  
void LCDPutStr(char *pString, int  x, int  y, int Size, int fColor, int bColor) { 
             
  // loop until null-terminator is seen 
  while (*pString != 0x00) { 
 
    // draw the character 
    LCDPutChar(*pString++, x, y, Size, fColor, bColor);   
 
    // advance the y position 
    if (Size == SMALL) 
      x = x + 6; 
    else if (Size == MEDIUM) 
      x = x + 8; 
    else 
      x = x + 8; 
     
    // bail out if y exceeds 131 
    if (x > 131) break; 
  } 
}

//  ********************************************************************************* 
//    Font tables for Nokia 6610 LCD Display Driver  (PCF8833 Controller) 
// 
//    FONT6x8   -  SMALL font (mostly 5x7) 
//    FONT8x8   -  MEDIUM font (8x8 characters, a bit thicker) 
//    FONT8x16  -  LARGE font  (8x16 characters, thicker) 
//                                                                        
//    Note:   ASCII characters 0x00 through 0x1F are not included in these fonts.                    
//      First row of each font contains the number of columns, the 
//      number of rows and the number of bytes per character. 
// 
//  Author:  Jim Parise, James P Lynch  July 7, 2007 
//  *********************************************************************************  
 
#endif
