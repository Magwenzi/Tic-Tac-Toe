#ifndef LCDC_H 
#define LCDC_H 

// Define Software SPI Pin Signal //
sbit LCD_BL    = P2^0;											// Black Light Control
sbit LCD_CS    = P2^1;											// CS# 
sbit LCD_SCLK  = P2^2;											// SCLK 
sbit LCD_SDATA = P2^3;											// SDATA
sbit LCD_RESET = P2^4;											// RESET#
sbit button1 = P3^0	;												// Button 1
sbit button2 = P3^1	;												// Button 2
sbit button3 = P3^2	;												// Button 3
sbit button4 = P3^3	;												// Button 4
sbit button5 = P3^4	;												// Button 5

// Philips PCF8833 LCD controller command codes 
#define NOP      0x00  // nop 
#define SWRESET    0x01  // software reset 
#define BSTROFF    0x02  // booster voltage OFF 
#define BSTRON     0x03  // booster voltage ON 
#define RDDIDIF    0x04  // read display identification 
#define RDDST      0x09  // read display status 
#define SLEEPIN    0x10  // sleep in 
#define SLEEPOUT    0x11  // sleep out 
#define PTLON      0x12  // partial display mode 
#define NORON      0x13  // display normal mode 
#define INVOFF     0x20  // inversion OFF 
#define INVON      0x21  // inversion ON 
#define DALO      0x22  // all pixel OFF 
#define DAL      0x23  // all pixel ON 
#define SETCON     0x25  // write contrast 
#define DISPOFF    0x28  // display OFF 
#define DISPON     0x29  // display ON 
#define CASET      0x2A  // column address set 
#define PASET      0x2B  // page address set 
#define RAMWR      0x2C  // memory write 
#define RGBSET     0x2D  // colour set 
#define PTLAR      0x30  // partial area 
#define VSCRDEF    0x33  // vertical scrolling definition 
#define TEOFF      0x34  // test mode 
#define TEON      0x35  // test mode 
#define MADCTL     0x36  // memory access control 
#define SEP      0x37  // vertical scrolling start address 
#define IDMOFF     0x38  // idle mode OFF 
#define IDMON      0x39  // idle mode ON 
#define COLMOD     0x3A  // interface pixel format 
#define SETVOP     0xB0  // set Vop   
#define BRS      0xB4  // bottom row swap 
#define TRS      0xB6  // top row swap 
#define DISCTR     0xB9  // display control 
#define DOR      0xBA  // data order 
#define TCDFE      0xBD  // enable/disable DF temperature compensation 
#define TCVOPE     0xBF  // enable/disable Vop temp comp 
#define EC      0xC0  // internal or external  oscillator 
#define SETMUL     0xC2  // set multiplication factor 
#define TCVOPAB    0xC3  // set TCVOP slopes A and B 
#define TCVOPCD    0xC4  // set TCVOP slopes c and d 
#define TCDF      0xC5  // set divider frequency 
#define DF8COLOR    0xC6  // set divider frequency 8-color mode 
#define SETBS      0xC7  // set bias system 
#define RDTEMP     0xC8  // temperature read back 
#define NLI      0xC9  // n-line inversion 
#define RDID1      0xDA  // read ID1 
#define RDID2      0xDB  // read ID2 
#define RDID3      0xDC  // read ID3 

// Booleans 
#define NOFILL 0 
#define FILL    1 
 
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
 
// Font sizes 
#define SMALL  0 
#define MEDIUM 1 
#define LARGE  2 
 
// hardware definitions 
#define SPI_SR_TXEMPTY 
#define LCD_RESET_LOW     pPIOA->PIO_CODR   = BIT2 
#define LCD_RESET_HIGH    pPIOA->PIO_SODR   = BIT2 
 
// mask definitions 
#define   BIT0        0x00000001 
#define   BIT1        0x00000002 
#define   BIT2        0x00000004 
#define   BIT3        0x00000008 
#define   BIT4        0x00000010 
#define   BIT5        0x00000020 
#define   BIT6        0x00000040 
#define   BIT7        0x00000080 
#define   BIT8        0x00000100 
#define   BIT9        0x00000200 
#define   BIT10       0x00000400 
#define   BIT11       0x00000800 
#define   BIT12       0x00001000 
#define   BIT13       0x00002000 
#define   BIT14       0x00004000 
#define   BIT15       0x00008000 
#define   BIT16       0x00010000 
#define   BIT17       0x00020000 
#define   BIT18       0x00040000 
#define   BIT19       0x00080000 
#define   BIT20       0x00100000 
#define   BIT21       0x00200000 
#define   BIT22       0x00400000 
#define   BIT23       0x00800000 
#define   BIT24       0x01000000 
#define   BIT25       0x02000000 
#define   BIT26       0x04000000 
#define   BIT27       0x08000000 
#define   BIT28       0x10000000 
#define   BIT29       0x20000000 
#define   BIT30       0x40000000 
#define   BIT31       0x80000000 



code unsigned char FONT6x8[97][8] = { 
 
0x06,0x08,0x08,0x00,0x00,0x00,0x00,0x00,  //  columns, rows, num_bytes_per_char 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  space  0x20 
0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00,  //  ! 
0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,  //  " 
0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00,  //  #   
0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,0x00,  //  $ 
0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00,  //  % 
0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00,  //  & 
0x30,0x30,0x20,0x40,0x00,0x00,0x00,0x00,  //  ' 
0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00,  //  ( 
0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00,  //  ) 
0x00,0x20,0xA8,0x70,0x70,0xA8,0x20,0x00,  //  * 
0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00,  //  + 
0x00,0x00,0x00,0x00,0x30,0x30,0x20,0x40,  //  , 
0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,  //  - 
0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,  //  . 
0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,  //  / (forward slash) 
0x70,0x88,0x88,0xA8,0x88,0x88,0x70,0x00,  //  0  0x30 
0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00,  //  1 
0x70,0x88,0x08,0x70,0x80,0x80,0xF8,0x00,  //  2 
0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00,  //  3 
0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00,  //  4 
0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00,  //  5 
0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00,  //  6 
0xF8,0x08,0x08,0x10,0x20,0x40,0x80,0x00,  //  7 
0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00,  //  8 
0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00,  //  9 
0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00,  //  : 
0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00,  //  ; 
0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00,  //  < 
0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00,  //  = 
0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00,  //  > 
0x70,0x88,0x08,0x30,0x20,0x00,0x20,0x00,  //  ? 
0x70,0x88,0xA8,0xB8,0xB0,0x80,0x78,0x00,  //  @  0x40 
0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00,  //  A 
0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00,  //  B 
0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00,  //  C 
0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00,  //  D 
0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00,  //  E 
0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00,  //  F 
0x78,0x88,0x80,0x80,0x98,0x88,0x78,0x00,  //  G 
0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00,  //  H 
0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00,  //  I 
0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00,  //  J 
0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00,  //  K 
0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00,  //  L 
0x88,0xD8,0xA8,0xA8,0xA8,0x88,0x88,0x00,  //  M 
0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00,  //  N 
0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00,  //  O 
0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00,  //  P  0x50 
0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00,  //  Q 
0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00,  //  R 
0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00,  //  S 
0xF8,0xA8,0x20,0x20,0x20,0x20,0x20,0x00,  //  T 
0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,  //  U 
0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00,  //  V 
0x88,0x88,0x88,0xA8,0xA8,0xA8,0x50,0x00,  //  W 
0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00,  //  X 
0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00,  //  Y 
0xF8,0x08,0x10,0x70,0x40,0x80,0xF8,0x00,  //  Z 
0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00,  //  [ 
0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,  //  \  (back slash) 
0x78,0x08,0x08,0x08,0x08,0x08,0x78,0x00,  //  ]   
0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00,  //  ^ 
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,  //  _ 
0x60,0x60,0x20,0x10,0x00,0x00,0x00,0x00,  //  `  0x60 
0x00,0x00,0x60,0x10,0x70,0x90,0x78,0x00,  //  a 
0x80,0x80,0xB0,0xC8,0x88,0xC8,0xB0,0x00,  //  b 
0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00,  //  c 
0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00,  //  d 
0x00,0x00,0x70,0x88,0xF8,0x80,0x70,0x00,  //  e 
0x10,0x28,0x20,0x70,0x20,0x20,0x20,0x00,  //  f 
0x00,0x00,0x70,0x98,0x98,0x68,0x08,0x70,  //  g 
0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,0x00,  //  h 
0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00,  //  i 
0x10,0x00,0x10,0x10,0x10,0x90,0x60,0x00,  //  j 
0x80,0x80,0x90,0xA0,0xC0,0xA0,0x90,0x00,  //  k 
0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00,  //  l 
0x00,0x00,0xD0,0xA8,0xA8,0xA8,0xA8,0x00,  //  m 
0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,0x00,  //  n 
0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00,  //  o 
0x00,0x00,0xB0,0xC8,0xC8,0xB0,0x80,0x80,  //  p  0x70 
0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08,  //  q 
0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,0x00,  //  r 
0x00,0x00,0x78,0x80,0x70,0x08,0xF0,0x00,  //  s 
0x20,0x20,0xF8,0x20,0x20,0x28,0x10,0x00,  //  t 
0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00,  //  u 
0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00,  //  v 
0x00,0x00,0x88,0x88,0xA8,0xA8,0x50,0x00,  //  w 
0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00,  //  x 
0x00,0x00,0x88,0x88,0x78,0x08,0x88,0x70,  //  y 
0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00,  //  z 
0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00,  //  { 
0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00,  //  | 
0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00,  //  } 
0x40,0xA8,0x10,0x00,0x00,0x00,0x00,0x00,  //  ~ 
0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00};  //  DEL 
 
code unsigned char FONT8x8[97][8] = { 
 
0x08,0x08,0x08,0x00,0x00,0x00,0x00,0x00,  //  columns, rows, num_bytes_per_char 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  space  0x20 
0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00,  //  ! 
0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00,  //  " 
0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00,  //  #   
0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00,  //  $ 
0x00,0x63,0x66,0x0C,0x18,0x33,0x63,0x00,  //  % 
0x1C,0x36,0x1C,0x3B,0x6E,0x66,0x3B,0x00,  //  & 
0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,  //  ' 
0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00,  //  ( 
0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00,  //  ) 
0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00,  //  * 
0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00,  //  + 
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30,  //  , 
0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,  //  - 
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,  //  . 
0x03,0x06,0x0C,0x18,0x30,0x60,0x40,0x00,  //  / (forward slash) 
0x3E,0x63,0x63,0x6B,0x63,0x63,0x3E,0x00,  //  0  0x30 
0x18,0x38,0x58,0x18,0x18,0x18,0x7E,0x00,  //  1 
0x3C,0x66,0x06,0x1C,0x30,0x66,0x7E,0x00,  //  2 
0x3C,0x66,0x06,0x1C,0x06,0x66,0x3C,0x00,  //  3 
0x0E,0x1E,0x36,0x66,0x7F,0x06,0x0F,0x00,  //  4 
0x7E,0x60,0x7C,0x06,0x06,0x66,0x3C,0x00,  //  5 
0x1C,0x30,0x60,0x7C,0x66,0x66,0x3C,0x00,  //  6 
0x7E,0x66,0x06,0x0C,0x18,0x18,0x18,0x00,  //  7 
0x3C,0x66,0x66,0x3C,0x66,0x66,0x3C,0x00,  //  8 
0x3C,0x66,0x66,0x3E,0x06,0x0C,0x38,0x00,  //  9 
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00,  //  : 
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30,  //  ; 
0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x00,  //  < 
0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,  //  = 
0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x00,  //  > 
0x3C,0x66,0x06,0x0C,0x18,0x00,0x18,0x00,  //  ? 
0x3E,0x63,0x6F,0x69,0x6F,0x60,0x3E,0x00,  //  @  0x40 
0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x00,  //  A 
0x7E,0x33,0x33,0x3E,0x33,0x33,0x7E,0x00,  //  B 
0x1E,0x33,0x60,0x60,0x60,0x33,0x1E,0x00,  //  C 
0x7C,0x36,0x33,0x33,0x33,0x36,0x7C,0x00,  //  D 
0x7F,0x31,0x34,0x3C,0x34,0x31,0x7F,0x00,  //  E 
0x7F,0x31,0x34,0x3C,0x34,0x30,0x78,0x00,  //  F 
0x1E,0x33,0x60,0x60,0x67,0x33,0x1F,0x00,  //  G 
0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x00,  //  H 
0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,  //  I 
0x0F,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,  //  J 
0x73,0x33,0x36,0x3C,0x36,0x33,0x73,0x00,  //  K 
0x78,0x30,0x30,0x30,0x31,0x33,0x7F,0x00,  //  L 
0x63,0x77,0x7F,0x7F,0x6B,0x63,0x63,0x00,  //  M 
0x63,0x73,0x7B,0x6F,0x67,0x63,0x63,0x00,  //  N 
0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,  //  O 
0x7E,0x33,0x33,0x3E,0x30,0x30,0x78,0x00,  //  P  0x50 
0x3C,0x66,0x66,0x66,0x6E,0x3C,0x0E,0x00,  //  Q 
0x7E,0x33,0x33,0x3E,0x36,0x33,0x73,0x00,  //  R 
0x3C,0x66,0x30,0x18,0x0C,0x66,0x3C,0x00,  //  S 
0x7E,0x5A,0x18,0x18,0x18,0x18,0x3C,0x00,  //  T 
0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x00,  //  U 
0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00,  //  V 
0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00,  //  W 
0x63,0x63,0x36,0x1C,0x1C,0x36,0x63,0x00,  //  X 
0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00,  //  Y 
0x7F,0x63,0x46,0x0C,0x19,0x33,0x7F,0x00,  //  Z 
0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,  //  [ 
0x60,0x30,0x18,0x0C,0x06,0x03,0x01,0x00,  //  \  (back slash) 
0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,  //  ]   
0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,  //  ^ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,  //  _ 
0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,  //  `  0x60 
0x00,0x00,0x3C,0x06,0x3E,0x66,0x3B,0x00,  //  a 
0x70,0x30,0x3E,0x33,0x33,0x33,0x6E,0x00,  //  b 
0x00,0x00,0x3C,0x66,0x60,0x66,0x3C,0x00,  //  c 
0x0E,0x06,0x3E,0x66,0x66,0x66,0x3B,0x00,  //  d 
0x00,0x00,0x3C,0x66,0x7E,0x60,0x3C,0x00,  //  e 
0x1C,0x36,0x30,0x78,0x30,0x30,0x78,0x00,  //  f 
0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x7C,  //  g 
0x70,0x30,0x36,0x3B,0x33,0x33,0x73,0x00,  //  h 
0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00,  //  i 
0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C,  //  j 
0x70,0x30,0x33,0x36,0x3C,0x36,0x73,0x00,  //  k 
0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,  //  l 
0x00,0x00,0x66,0x7F,0x7F,0x6B,0x63,0x00,  //  m 
0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x00,  //  n 
0x00,0x00,0x3C,0x66,0x66,0x66,0x3C,0x00,  //  o 
0x00,0x00,0x6E,0x33,0x33,0x3E,0x30,0x78,  //  p  0x70 
0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x0F,  //  q 
0x00,0x00,0x6E,0x3B,0x33,0x30,0x78,0x00,  //  r 
0x00,0x00,0x3E,0x60,0x3C,0x06,0x7C,0x00,  //  s 
0x08,0x18,0x3E,0x18,0x18,0x1A,0x0C,0x00,  //  t 
0x00,0x00,0x66,0x66,0x66,0x66,0x3B,0x00,  //  u 
0x00,0x00,0x66,0x66,0x66,0x3C,0x18,0x00,  //  v 
0x00,0x00,0x63,0x6B,0x7F,0x7F,0x36,0x00,  //  w 
0x00,0x00,0x63,0x36,0x1C,0x36,0x63,0x00,  //  x 
0x00,0x00,0x66,0x66,0x66,0x3E,0x06,0x7C,  //  y 
0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00,  //  z 
0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00,  //  { 
0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x0C,0x00,  //  | 
0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00,  //  } 
0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,  //  ~ 
0x1C,0x36,0x36,0x1C,0x00,0x00,0x00,0x00};  //  DEL 
 
                       
code const unsigned char FONT8x16[97][16] = { 
 
0x08,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  columns, rows, nbytes 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  space  0x20 
0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00,  //  ! 
0x00,0x63,0x63,0x63,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  " 
0x00,0x00,0x00,0x36,0x36,0x7F,0x36,0x36,0x36,0x7F,0x36,0x36,0x00,0x00,0x00,0x00,  //  #   
0x0C,0x0C,0x3E,0x63,0x61,0x60,0x3E,0x03,0x03,0x43,0x63,0x3E,0x0C,0x0C,0x00,0x00,  //  $ 
0x00,0x00,0x00,0x00,0x00,0x61,0x63,0x06,0x0C,0x18,0x33,0x63,0x00,0x00,0x00,0x00,  //  % 
0x00,0x00,0x00,0x1C,0x36,0x36,0x1C,0x3B,0x6E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00,  //  & 
0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  ' 
0x00,0x00,0x0C,0x18,0x18,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x00,0x00,0x00,0x00,  //  ( 
0x00,0x00,0x18,0x0C,0x0C,0x06,0x06,0x06,0x06,0x0C,0x0C,0x18,0x00,0x00,0x00,0x00,  //  ) 
0x00,0x00,0x00,0x00,0x42,0x66,0x3C,0xFF,0x3C,0x66,0x42,0x00,0x00,0x00,0x00,0x00,  //  * 
0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,  //  + 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00,  //  , 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  - 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,  //  . 
0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,  //  / (forward slash) 
0x00,0x00,0x3E,0x63,0x63,0x63,0x6B,0x6B,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  0  0x30 
0x00,0x00,0x0C,0x1C,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3F,0x00,0x00,0x00,0x00,  //  1 
0x00,0x00,0x3E,0x63,0x03,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00,  //  2 
0x00,0x00,0x3E,0x63,0x03,0x03,0x1E,0x03,0x03,0x03,0x63,0x3E,0x00,0x00,0x00,0x00,  //  3 
0x00,0x00,0x06,0x0E,0x1E,0x36,0x66,0x66,0x7F,0x06,0x06,0x0F,0x00,0x00,0x00,0x00,  //  4 
0x00,0x00,0x7F,0x60,0x60,0x60,0x7E,0x03,0x03,0x63,0x73,0x3E,0x00,0x00,0x00,0x00,  //  5 
0x00,0x00,0x1C,0x30,0x60,0x60,0x7E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  6 
0x00,0x00,0x7F,0x63,0x03,0x06,0x06,0x0C,0x0C,0x18,0x18,0x18,0x00,0x00,0x00,0x00,  //  7 
0x00,0x00,0x3E,0x63,0x63,0x63,0x3E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  8 
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x3F,0x03,0x03,0x06,0x3C,0x00,0x00,0x00,0x00,  //  9 
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,  //  : 
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00,  //  ; 
0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00,  //  < 
0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,  //  = 
0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00,  //  > 
0x00,0x00,0x3E,0x63,0x63,0x06,0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,  //  ? 
0x00,0x00,0x3E,0x63,0x63,0x6F,0x6B,0x6B,0x6E,0x60,0x60,0x3E,0x00,0x00,0x00,0x00,  //  @  0x40 
0x00,0x00,0x08,0x1C,0x36,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x00,0x00,0x00,0x00,  //  A 
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x33,0x33,0x33,0x33,0x7E,0x00,0x00,0x00,0x00,  //  B 
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x60,0x60,0x61,0x33,0x1E,0x00,0x00,0x00,0x00,  //  C 
0x00,0x00,0x7C,0x36,0x33,0x33,0x33,0x33,0x33,0x33,0x36,0x7C,0x00,0x00,0x00,0x00,  //  D 
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00,  //  E 
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00,  //  F 
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x6F,0x63,0x63,0x37,0x1D,0x00,0x00,0x00,0x00,  //  G 
0x00,0x00,0x63,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00,  //  H 
0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,  //  I 
0x00,0x00,0x0F,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00,  //  J 
0x00,0x00,0x73,0x33,0x36,0x36,0x3C,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00,  //  K 
0x00,0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00,  //  L 
0x00,0x00,0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00,  //  M 
0x00,0x00,0x63,0x63,0x73,0x7B,0x7F,0x6F,0x67,0x63,0x63,0x63,0x00,0x00,0x00,0x00,  //  N 
0x00,0x00,0x1C,0x36,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x00,0x00,0x00,0x00,  //  O 
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00,  //  P  0x50 
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x63,0x6B,0x6F,0x3E,0x06,0x07,0x00,0x00,  //  Q 
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00,  //  R 
0x00,0x00,0x3E,0x63,0x63,0x30,0x1C,0x06,0x03,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  S 
0x00,0x00,0xFF,0xDB,0x99,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,  //  T 
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  U 
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x08,0x00,0x00,0x00,0x00,  //  V 
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x36,0x00,0x00,0x00,0x00,  //  W 
0x00,0x00,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x3C,0x66,0xC3,0xC3,0x00,0x00,0x00,0x00,  //  X 
0x00,0x00,0xC3,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,  //  Y 
0x00,0x00,0x7F,0x63,0x43,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00,  //  Z 
0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,0x00,0x00,0x00,  //  [ 
0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00,  //  \  (back slash) 
0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,0x00,0x00,0x00,  //  ]   
0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  ^ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,  //  _ 
0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  `  0x60 
0x00,0x00,0x00,0x00,0x00,0x3C,0x46,0x06,0x3E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00,  //  a 
0x00,0x00,0x70,0x30,0x30,0x3C,0x36,0x33,0x33,0x33,0x33,0x6E,0x00,0x00,0x00,0x00,  //  b 
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x60,0x60,0x60,0x63,0x3E,0x00,0x00,0x00,0x00,  //  c 
0x00,0x00,0x0E,0x06,0x06,0x1E,0x36,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00,  //  d 
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x7E,0x60,0x63,0x3E,0x00,0x00,0x00,0x00,  //  e 
0x00,0x00,0x1C,0x36,0x32,0x30,0x7C,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00,  //  f 
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x66,0x3C,0x00,0x00,  //  g 
0x00,0x00,0x70,0x30,0x30,0x36,0x3B,0x33,0x33,0x33,0x33,0x73,0x00,0x00,0x00,0x00,  //  h 
0x00,0x00,0x0C,0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00,  //  i 
0x00,0x00,0x06,0x06,0x00,0x0E,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,  //  j 
0x00,0x00,0x70,0x30,0x30,0x33,0x33,0x36,0x3C,0x36,0x33,0x73,0x00,0x00,0x00,0x00,  //  k 
0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00,  //  l 
0x00,0x00,0x00,0x00,0x00,0x6E,0x7F,0x6B,0x6B,0x6B,0x6B,0x6B,0x00,0x00,0x00,0x00,  //  m 
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x00,  //  n 
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00,  //  o 
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x3E,0x30,0x30,0x78,0x00,0x00,  //  p  0x70 
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00,0x00,  //  q 
0x00,0x00,0x00,0x00,0x00,0x6E,0x3B,0x33,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00,  //  r 
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x38,0x0E,0x03,0x63,0x3E,0x00,0x00,0x00,0x00,  //  s 
0x00,0x00,0x08,0x18,0x18,0x7E,0x18,0x18,0x18,0x18,0x1B,0x0E,0x00,0x00,0x00,0x00,  //  t 
0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00,  //  u 
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x36,0x36,0x1C,0x1C,0x08,0x00,0x00,0x00,0x00,  //  v 
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x00,0x00,0x00,0x00,  //  w 
0x00,0x00,0x00,0x00,0x00,0x63,0x36,0x1C,0x1C,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,  //  x 
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x3F,0x03,0x06,0x3C,0x00,0x00,  //  y 
0x00,0x00,0x00,0x00,0x00,0x7F,0x66,0x0C,0x18,0x30,0x63,0x7F,0x00,0x00,0x00,0x00,  //  z 
0x00,0x00,0x0E,0x18,0x18,0x18,0x70,0x18,0x18,0x18,0x18,0x0E,0x00,0x00,0x00,0x00,  //  { 
0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00,  //  | 
0x00,0x00,0x70,0x18,0x18,0x18,0x0E,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00,0x00,  //  } 
0x00,0x00,0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  ~ 
0x00,0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};  //  DEL 

#endif
