//****************************************************************************
// HEADER FILES - Pwd - 
//****************************************************************************

#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>

//****************************************************************************
// GLOBAL VARIABLE AND FUNCTION
//****************************************************************************

int check=0;                                // FLAG VARIABLE TO CHECK PASSWORD
void sound1()
  {
    sound(500);     delay(300);
    sound(400);	    delay(180);
    sound(450);	    delay(450);          // FUNCTION TO GIVE SOUND AT STARTING
    sound(350);	    delay(180);          // OF GAME
    sound(400);	    delay(180);
    sound(350);	    delay(180);
    sound(400);     delay(180);
  }
class end
  {
    private:int i;
    public:end()
	     {
	       i=1;
	     }
	   void lvl1();
	   void lvl2();
	   void congrats();
	   void bye_bye();
  }e;

void end::lvl1()
  {
    cleardevice();
    graphdefaults();
    char text1[]="  LEVEL 1",
	 text2[]="COMPLETE";

    settextstyle(10,0,5);
    while( !kbhit() )
      {
	setcolor(i);
	outtextxy(  10, 100, text1 );
	outtextxy( 180, 200, text2 );
	if( i==7 )     i=0;
	i++;
	delay(100);
      }
    getch();
  }
void end::lvl2()
  {
    cleardevice();
    graphdefaults();
    char text1[]="  LEVEL 2",
	 text2[]="COMPLETE";

    settextstyle(10,0,5);
    while( !kbhit() )
      {
	setcolor(i);
	outtextxy(  10, 100, text1 );
	outtextxy( 180, 200, text2 );
	if( i==7 )     i=0;
	i++;
	delay(100);
      }
    getch();
  }
void end::congrats()
  {
    cleardevice();
    graphdefaults();
    char text1[]="CONGRATULATIONS!",
	 text2[]="YOU WON";

    settextstyle(10,0,5);
    while( !kbhit() )
      {
	setcolor(i);
	outtextxy(  10, 100, text1 );
	outtextxy( 180, 200, text2 );
	if( i==7 )     i=0;
	i++;
	delay(100);
      }
    getch();
    closegraph();
    exit(0);
  }

void end::bye_bye()
  {
    graphdefaults();
    char text1[]="BYE",
	 text2[]="MADE BY : ",
	 text3[]="SANCHIT NANDA",
	 text4[]="TIET";

    setcolor(9);                                               // DISPLAY TEXT
    settextstyle(4,0,3);
    outtextxy(  20, 419, text2 );
    setcolor(14);
    settextstyle(1,0,3);
    outtextxy( 170, 420, text3 );
    outtextxy( 420, 420, text4 );
    setcolor(4);
    outtextxy( 350, 420, "\n" );

    settextstyle(10,0,7);
    while( !kbhit() )
      {
	setcolor(i);
	outtextxy( 200, 100, text1 );
	outtextxy( 300, 200, text1 );
	if( i==7 )     i=0;
	i++;
	delay(100);
      }
    getch();
    exit(0);
  }
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


//****************************************************************************
// CLASS TO ACCEPT PASSWORD AND START GAME
//****************************************************************************

class password
  {
    private:int i,c,maxx,maxy,j,x,y,ctr,chance;             // PRIVATE MEMBERS
	    char pw[7],cp[],ch;

    public:password()                                        // PUBLIC MEMBERS
	     {
	       i=c=j=x=y=ctr=0;
	       chance=3;                               // CONSTRUCTOR FUNCTION
	       maxx=getmaxx();     maxy=getmaxy();
	       strcpy( pw, "sanchit"  );
	       strcpy( cp, "sanchit" );
	     }

	   void pass();                                  // FUNCTION PROTOTYPE
  };

//****************************************************************************
// FUNCTION TO ACCEPT PASSWORD
//****************************************************************************

void password::pass()
  {
    graphdefaults();                                            // DRAW BORDER
    for( j=1; j<=3; j++ )
      {
	x=125;   y=200;   ctr=0;
	setcolor(2);
	rectangle(  1,  1,    maxx,    maxy );
	rectangle(  2,  2,  maxx-1,  maxy-1 );
	rectangle( 20, 20, maxx-20, maxy-20 );
	rectangle( 21, 21, maxx-21, maxy-21 );
	setfillstyle(10,9);   floodfill(10,10,2);

	setcolor(9);                            // DISPLAY NO. OF CHANCES LEFT
	settextstyle(1,0,2);
	outtextxy(440,40,"Chances Left : ");
	gotoxy(75,4);
	cout<<chance;

	setcolor(2);                                  // ASK TO ENTER PASSWORD
	settextstyle(7,0,2);
	outtextxy(x,y,"ENTER THE PASSWORD: ");

	for( i=0; (i<=4) && ((c=getch())!=13); i++ )
	  {
	    pw[i]=c;                        // ACCEPT PASSWORD & DISPLAY STARS
	    settextstyle(7,0,5);
	    setcolor(4);
	    outtextxy(x+275,y-9,"*");
	    x+=20;
	  }

	for( i=0; i<=4; i++ )                        // CHECK ENTERED PASSWORD
	  {
	    if( pw[i]==cp[i] )
		 ctr++;
	  }

	setcolor(5);
	settextstyle(4,0,5);
	if( ctr!=5 )                                   // DISPLAY WRONG RESULT
	  {
	    outtextxy(x-25,y+30,"Access Denied");
	    chance--;
	    delay(700);
	    cleardevice();
	  }
	else if( ctr==5 )                            // DISPLAY CORRECT RESULT
	  {
	    check=1;
	    outtextxy(x-80,y+30,"Password Accepted");
	    sound1();   sound1();   nosound();

	    settextstyle(1,0,2);
	    again:
	    while( !kbhit() )
	      {
		sound(500);   delay(200);
		setcolor(14);
		outtextxy( x-50, y+140, "PRESS ENTER TO CONTINUE" );
		nosound();
		delay(500);
		setcolor(0);
		outtextxy( x-50, y+140, "PRESS ENTER TO CONTINUE" );
		delay(400);
	      }
	    ch=getch();
	    switch( ch )
	      {
		case 13:nosound();
			break;
		default:goto again;
	      }
	    cleardevice();
	    break;
	  }
      }
  }

//****************************************************************************
// CLASS TO SHOW NAME OF THE GAME AND A LOADING BAR
//****************************************************************************

class introduction
  {
    private:int ang,w,x1,x2,y1,y2;                          // PRIVATE MEMBERS
	    char ch;

    public:introduction()                                   // PUBLIC MEMBERS
	     {
	       ang=w=x1=x2=y1=y2=0;                    // CONSTRUCTOR FUNCTION
	     }

	   void gname();                                // FUNCTION PROTOTYPES
	   void loadbar();
  };

//****************************************************************************
// FUNCTION TO DISPLAY NAME OF THE GAME
//****************************************************************************

void introduction::gname()
  {
    graphdefaults();                              // DRAW OUTLINE OF TEXT AREA
    setcolor(8);
    ellipse( 320, 240, 0, 360, 300, 150 );
    ellipse( 320, 240, 0, 360, 301, 151 );

    setcolor(15);
    ellipse( 320, 240, 0, 360, 310, 170 );

    ellipse( 320, 240, 0, 360, 450, 190 );
    setfillstyle(1,4);
    floodfill( 1,   1, 15 );
    floodfill( 1, 470, 15 );

    settextjustify(1,1);                           // DISPLAY NAME OF THE GAME
    settextstyle(10,0,4);
    setcolor(5);
    outtextxy(320,170," SUPER MARIO ");
    setcolor(2);
    outtextxy(320,265,"SANCHIT");
    setcolor(9);
    outtextxy(320,315,"NANDA");
    settextstyle(4,0,4);
    setcolor(4);
    outtextxy(320,220,"Presented By:");

    settextstyle(1,0,2);
    for( ang=0; !kbhit(); ang++ )
      {                                   // LOOP TO SHOW EFFECT ON THE BORDER
	sound( ang+300 );

	setcolor(14);
	outtextxy( 320, 450, "PRESS ANY KEY TO CONTINUE" );

	setcolor(15);
	ellipse( 320, 240,     ang,  ang+20, 300, 150 );
	ellipse( 320, 240,  ang+90, ang+110, 300, 150 );
	ellipse( 320, 240, ang+180, ang+200, 300, 150 );
	ellipse( 320, 240, ang+270, ang+290, 300, 150 );
	ellipse( 320, 240,     ang,  ang+20, 301, 151 );
	ellipse( 320, 240,  ang+90, ang+110, 301, 151 );
	ellipse( 320, 240, ang+180, ang+200, 301, 151 );
	ellipse( 320, 240, ang+270, ang+290, 301, 151 );
	ellipse( 320, 240,     ang,  ang+20, 302, 152 );
	ellipse( 320, 240,  ang+90, ang+110, 302, 152 );
	ellipse( 320, 240, ang+180, ang+200, 302, 152 );
	ellipse( 320, 240, ang+270, ang+290, 302, 152 );

	setcolor(4);
	outtextxy( 320, 450, "PRESS ANY KEY TO CONTINUE" );

	setcolor(8);
	ellipse( 320, 240,   ang-1,   ang+5, 300, 150 );
	ellipse( 320, 240,  ang+89,  ang+95, 300, 150 );
	ellipse( 320, 240, ang+179, ang+185, 300, 150 );
	ellipse( 320, 240, ang+269, ang+275, 300, 150 );
	ellipse( 320, 240,   ang-1,   ang+5, 301, 151 );
	ellipse( 320, 240,  ang+89,  ang+95, 301, 151 );
	ellipse( 320, 240, ang+179, ang+185, 301, 151 );
	ellipse( 320, 240, ang+269, ang+275, 301, 151 );
	ellipse( 320, 240,   ang-1,   ang+5, 302, 152 );
	ellipse( 320, 240,  ang+89,  ang+95, 302, 152 );
	ellipse( 320, 240, ang+179, ang+185, 302, 152 );
	ellipse( 320, 240, ang+269, ang+275, 302, 152 );

	if(ang==360)
	   ang=0;
      }
    nosound();

    getch();
    cleardevice();
  }

//****************************************************************************
// FUNCTION TO DISPLAY LOADING BAR
//****************************************************************************

void introduction::loadbar()
  {
    graphdefaults();                                          // BORDER OF BAR
    setcolor(14);
    rectangle( 170, 150, 470, 180 );
    rectangle( 169, 149, 471, 181 );

    setcolor(2);                                             // DISPLAY STATUS
    settextstyle(1,0,2);
    outtextxy(200,250,"LOADING MENU . . .");
    delay(3000);

    setcolor(4);
    gotoxy(50,15);
    for( x1=171,y1=151,x2=171,y2=179; x1<470; x1++,x2++ )
      {
	sound(500);                    // TO FILL BAR AND CALCULATE PERCENTAGE
	line( x1, y1, x2, y2 );
	w=( x1-169 )/3;
	gotoxy(52,17);
	cout<<w<< " %";
	if     ( x2>370  )     delay( 10   );
	else if( x2==320 )     delay( 1000 );
	else if( x2>270  )     delay( 45   );
	else                   delay( 30   );
	nosound();
      }
    delay(700);

    setcolor(15);                                     // COVER TEXT WITH A BOX
    rectangle( 285, 250, 470, 280 );
    setfillstyle(1,0);   floodfill(290,260,15);
    setcolor(0);
    rectangle( 285, 250, 470, 280 );

    setcolor(2);                                             // DISPLAY STATUS
    settextstyle(1,0,2);
    outtextxy(300,250,"COMPLETE");

    while( !kbhit() )                         // BLINK TEXT TO PROCEED FURTHER
      {
	sound(500);   delay(200);
	setcolor(5);
	outtextxy( 180, 300, "PRESS ANY KEY TO CONTINUE" );
	nosound();
	delay(500);
	setcolor(0);
	outtextxy( 180, 300, "PRESS ANY KEY TO CONTINUE" );
	delay(400);
      }

    getch();
    cleardevice();
  }

//****************************************************************************
// CLASS TO DRAW BACKGROUND BEHIND THE MENU
//****************************************************************************

class menu_background
  {
    private:int ctr,x,y,i;                                  // PRIVATE MEMBERS

    public:menu_background()                                // PUBLIC MEMBERS
	     {
	       ctr=x=y=i=0;                            // CONSTRUCTOR FUNCTION
	     }

	   void menu_bkgrd();                           // FUNCTION PROTOTYPES
	   void help();

//****************************************************************************
// FUNCTION OT DRAW AND COLOUR MARIO'S FACE
//****************************************************************************

	   void draw_mario()
	     {
	       graphdefaults();                                  // DRAW MARIO
	       setcolor(15);
	       ellipse( 500, 150, 340,  45,  70,  60 );
	       ellipse( 500, 150,  65, 200,  70,  60 );
	       ellipse( 422, 170,  70, 320,  25,  25 );
	       ellipse( 565, 165, 285,  75,  22,  20 );
	       ellipse( 490, 150, 215, 265,  60,  65 );
	       ellipse( 490, 182, 308,  20,  80,  35 );
	       ellipse( 510, 205, 207, 348,  30,  20 );
	       ellipse( 512, 175,   0, 360,  27,  22 );
	       ellipse( 510, 167, 197, 243,  50,  20 );
	       ellipse( 510, 167, 305, 350,  50,  20 );
	       ellipse( 480, 177, 150, 235,  20,  12 );
	       ellipse( 490, 182, 195, 280,  23,  17 );
	       ellipse( 512, 190, 212, 343,  23,  17 );
	       ellipse( 537, 166, 265, 325,  20,  30 );
	       ellipse( 554, 177, 270,  45,   7,   7 );
	       ellipse( 510, 200, 175,   5,  22,  17 );
	       ellipse( 510, 237,  50, 125,  20,  28 );
	       ellipse( 490, 145, 330, 265,  12,  20 );
	       ellipse( 535, 147, 280, 205,  12,  17 );
	       ellipse( 482, 155, 358,  93,  15,  22 );
	       ellipse( 527, 153, 325,  90,  12,  17 );
	       ellipse( 476, 154, 340,  82,  17,  15 );
	       ellipse( 523, 155, 340,  85,  12,  17 );
	       circle ( 487, 150,   4 );
	       circle ( 530, 150,   4 );
	       ellipse( 495,  80,   5, 118,  80,  70 );
	       ellipse( 530, 100, 125, 190, 125, 100 );
	       ellipse( 425, 130, 112, 240,  50,  35 );
	       ellipse( 533, 102, 307,  70,  60,  40 );
	       ellipse( 520, 130,  70, 192, 100,  70 );
	       ellipse( 510, 127,  25, 180,  75,  50 );
	       ellipse( 510,  50, 330, 225,  30,  20 );
	       line   ( 495,  37, 492,  63 );
	       line   ( 495,  37, 510,  45 );
	       line   ( 510,  45, 525,  38 );
	       line   ( 525,  38, 532,  61 );
	       line   ( 500,  45, 498,  62 );
	       line   ( 500,  45, 510,  50 );
	       line   ( 510,  50, 521,  46 );
	       line   ( 521,  46, 526,  60 );
	       ellipse( 490, 115,  20, 185,  15, 20 );
	       ellipse( 491, 117,  25, 180,  15, 15 );
	       ellipse( 535, 115, 355, 160,  15, 20 );
	       ellipse( 535, 117,   0, 155,  15, 15 );
	       ellipse( 438, 167, 180, 355,   5,  9 );
	       ellipse( 447, 162, 190,  10,   5,  9 );
	       ellipse( 467, 135, 130, 220,  20, 40 );
	       ellipse( 547, 135, 330,  40,  15, 25 );
	       ellipse( 628, 152, 170, 210,  70, 20 );
	       ellipse( 430, 180, 210, 335,  17, 30 );
	       ellipse( 445, 187, 240, 312,  20, 25 );
	       ellipse( 405, 190,   7,  70,  20, 30 );
	       line   ( 412, 170, 422, 175 );
	       ellipse( 588, 190, 125, 165,  20, 40 );
	       line   ( 572, 168, 578, 165 );

	       //FILL COLOUR IN MARIO'S FACE

	       setfillstyle(1,0);  floodfill( 495, 100, 15 );     // EYE BROWS
				   floodfill( 530, 100, 15 );
				   floodfill( 480, 190, 15 );     // MUSTACHE
				   floodfill( 540, 190, 15 );
				   floodfill( 487, 155, 15 );     // EYES
				   floodfill( 530, 155, 15 );

	       setfillstyle(1,1);  floodfill( 450,  50, 15 );     // HAT
				   floodfill( 450, 100, 15 );
				   floodfill( 440, 200, 15 );
				   floodfill( 450, 200, 15 );
				   floodfill( 495,  50, 15 );     // 'M'

	       setfillstyle(1,4);  floodfill( 505, 215, 15 );     // MOUTH

	       setfillstyle(1,5);  floodfill( 500,  35, 15 );     // 'M'
				   floodfill( 500,  50, 15 );

	       setfillstyle(1,6);  floodfill( 440, 150, 15 );     // HAIR
				   floodfill( 565, 140, 15 );
				   floodfill( 490, 140, 15 );     // EYES
				   floodfill( 534, 140, 15 );

	       setfillstyle(1,12); floodfill( 495, 205, 15 );     // MOUTH
				   floodfill( 510, 195, 15 );     // NOSE
				   floodfill( 570, 165, 15 );     // EARS
				   floodfill( 560, 165, 15 );     // FACE

	       setfillstyle(1,15); floodfill( 495, 140, 15 );     // EYES
				   floodfill( 540, 140, 15 );
				   floodfill( 487, 150, 15 );
				   floodfill( 530, 150, 15 );
	     }
  };

//****************************************************************************
// FUNCTION TO DRAW CURVY LINES
//****************************************************************************

void menu_background::menu_bkgrd()
  {
    graphdefaults();

    for( ctr=1,x=0,y=0,i=1; ctr<=29; ctr++,x+=20,i++ )
      {
	setcolor(i);

	ellipse( x+80,  y+40, 120, 220, 50, 100 );           // VERTICAL LINES
	ellipse(    x, y+160, 325,  40, 50, 100 );
	ellipse( x+80, y+280, 140, 220, 50, 100 );
	ellipse(    x, y+400, 300,  40, 50, 100 );

	ellipse( x+81,  y+40, 120, 220, 50, 100 );
	ellipse(  x+1, y+160, 325,  40, 50, 100 );
	ellipse( x+81, y+280, 140, 220, 50, 100 );
	ellipse(  x+1, y+400, 300,  40, 50, 100 );

	if( i==7 )     i=0;
      }

    for( ctr=1,x=0,y=0,i=1; ctr<=22; ctr++,y+=20,i++ )
      {
	setcolor(i);

	ellipse(  x+40, y-10, 240, 310, 100, 50 );         // HORIZONTAL LINES
	ellipse( x+160, y+70,  60, 130, 100, 50 );
	ellipse( x+280, y-10, 225, 310, 100, 50 );
	ellipse( x+400, y+70,  60, 130, 100, 50 );
	ellipse( x+520, y-10, 225, 310, 100, 50 );
	ellipse( x+640, y+70,  90, 130, 100, 50 );

	ellipse(  x+40,  y-9, 240, 310, 100, 50 );
	ellipse( x+160, y+71,  60, 130, 100, 50 );
	ellipse( x+280,  y-9, 225, 310, 100, 50 );
	ellipse( x+400, y+71,  60, 130, 100, 50 );
	ellipse( x+520,  y-9, 225, 310, 100, 50 );
	ellipse( x+640, y+71,  90, 130, 100, 50 );

	if( i==7 )     i=0;
      }
  }

//****************************************************************************
// FUNCTION TO DISPLAY CONTROLS FOR USING MENU
//****************************************************************************

void menu_background::help()
  {
    char text1[]="Esc",
	 text2[]=" SCROLL ",
	 text3[]=" SELECT ",
	 text4[]=" EXIT   ";

    setcolor(15);                                             // DRAW HELP BOX
    rectangle( 350, 290, 600, 450 );
    rectangle( 349, 289, 601, 451 );
    rectangle( 348, 288, 602, 452 );
    setfillstyle(1,9);   floodfill(352,292,15);

    setcolor(4);                                                  // DRAW KEYS
    rectangle( 375, 305, 405, 335 );
    rectangle( 435, 305, 465, 335 );
    rectangle( 405, 355, 435, 385 );
    rectangle( 405, 405, 435, 435 );
    setfillstyle(1,4);
    floodfill( 380, 310, 4 );
    floodfill( 440, 310, 4 );
    floodfill( 410, 360, 4 );
    floodfill( 410, 410, 4 );

    setcolor(15);
    rectangle( 370, 300, 400, 330 );
    rectangle( 430, 300, 460, 330 );
    rectangle( 400, 350, 430, 380 );
    rectangle( 400, 400, 430, 430 );
    setfillstyle(1,15);
    floodfill( 372, 302, 15 );
    floodfill( 432, 302, 15 );
    floodfill( 402, 352, 15 );
    floodfill( 402, 402, 15 );

    setcolor(0);                                              // DRAW UP ARROW
    line( 385, 328, 385, 315 );
    line( 386, 328, 386, 315 );
    line( 380, 315, 390, 315 );
    line( 380, 315, 385, 302 );
    line( 390, 315, 386, 302 );
    setfillstyle(1,0);   floodfill(385,310,0);

    setcolor(0);                                            // DRAW DOWN ARROW
    line( 445, 302, 445, 315 );
    line( 446, 302, 446, 315 );
    line( 440, 315, 450, 315 );
    line( 440, 315, 445, 328 );
    line( 450, 315, 446, 328 );
    setfillstyle(1,0);   floodfill(445,320,0);

    setcolor(0);                                             // DRAW ENTER KEY
    line( 428, 365, 428, 355 );
    line( 427, 365, 427, 355 );
    line( 426, 365, 426, 355 );
    line( 428, 365, 415, 365 );
    line( 428, 366, 415, 366 );
    line( 415, 360, 415, 370 );
    line( 415, 360, 402, 365 );
    line( 415, 370, 402, 365 );
    setfillstyle(1,0);   floodfill(410,365,0);

    settextjustify(1,1);                         // WRITE 'ESC' INSIDE THE KEY
    setcolor(0);
    settextstyle(1,0,1);
    outtextxy( 415, 410, text1 );

    setcolor(2);                                            // TO DRAW HYPHENS
    line( 480, 320, 490, 320 );
    line( 480, 321, 490, 321 );
    line( 480, 370, 490, 370 );
    line( 480, 371, 490, 371 );
    line( 480, 420, 490, 420 );
    line( 480, 421, 490, 421 );

    setcolor(14);                                       // DISPLAY USE OF KEYS
    settextstyle(1,0,2);
    outtextxy( 550, 315, text2 );
    outtextxy( 550, 365, text3 );
    outtextxy( 550, 415, text4 );
  }

//****************************************************************************
// CLASS TO DISPLAY GAME MENU
//****************************************************************************

class game_menu
  {
    private:char ch;                                        // PRIVATE MEMBERS
	    int choice,temp,i;

//****************************************************************************
// FUNCTION TO DRAW BOX TO WRITE MENU IN
//****************************************************************************

	    void menu_box( int i, int color )
	      {                                             // DRAW & FILL BOX
		setcolor(12);
		rectangle( 30, (80*i)+10, 310, (80*i)+50 );
		setfillstyle(1,color);
		floodfill( 160, (80*i)+30, 12 );

		setcolor(4);
		rectangle( 30, (80*i)+10, 310, (80*i)+50 );
		rectangle( 29,  (80*i)+9, 311, (80*i)+51 );

		setcolor(0);                                 // DRAW  EXTENDED
		line( 28, (80*i)+9,  28, (80*i)+51 );        // BORDERS
		line( 27, (80*i)+9,  27, (80*i)+51 );
		line( 26, (80*i)+9,  26, (80*i)+51 );
		line( 26, (80*i)+8, 311,  (80*i)+8 );
		line( 26, (80*i)+7, 311,  (80*i)+7 );
		line( 26, (80*i)+6, 311,  (80*i)+6 );

		setcolor(15);
		line( 312,  (80*i)+9, 312, (80*i)+51 );
		line( 313,  (80*i)+9, 313, (80*i)+51 );
		line( 314,  (80*i)+9, 314, (80*i)+51 );
		line(  29, (80*i)+52, 314, (80*i)+52 );
		line(  29, (80*i)+53, 314, (80*i)+53 );
		line(  29, (80*i)+54, 314, (80*i)+54 );
	      }

	    void toggle( int, int );                     // FUNCTION PROTOTYPE

//****************************************************************************
// FUNCTION TO SHOW EFFECT WHEN A CHOICE IS SELECTED
//****************************************************************************

	    void select_effect( int i )
	      {
		if( i==0 )     i=4;       // CHANGE COLOUR OF EXTENDED BORDERS
		delay(350);

		setcolor(15);
		line( 28, (80*i)+9,  28, (80*i)+51 );
		line( 27, (80*i)+9,  27, (80*i)+51 );
		line( 26, (80*i)+9,  26, (80*i)+51 );
		line( 26, (80*i)+8, 311,  (80*i)+8 );
		line( 26, (80*i)+7, 311,  (80*i)+7 );
		line( 26, (80*i)+6, 311,  (80*i)+6 );

		setcolor(0);
		line( 312,  (80*i)+9, 312, (80*i)+51 );
		line( 313,  (80*i)+9, 313, (80*i)+51 );
		line( 314,  (80*i)+9, 314, (80*i)+51 );
		line(  29, (80*i)+52, 314, (80*i)+52 );
		line(  29, (80*i)+53, 314, (80*i)+53 );
		line(  29, (80*i)+54, 314, (80*i)+54 );

		sound(800); delay(100); nosound();
		delay(250);

		setcolor(0);
		line( 28, (80*i)+9,  28, (80*i)+51 );
		line( 27, (80*i)+9,  27, (80*i)+51 );
		line( 26, (80*i)+9,  26, (80*i)+51 );
		line( 26, (80*i)+8, 311,  (80*i)+8 );
		line( 26, (80*i)+7, 311,  (80*i)+7 );
		line( 26, (80*i)+6, 311,  (80*i)+6 );

		setcolor(15);
		line( 312,  (80*i)+9, 312, (80*i)+51 );
		line( 313,  (80*i)+9, 313, (80*i)+51 );
		line( 314,  (80*i)+9, 314, (80*i)+51 );
		line(  29, (80*i)+52, 314, (80*i)+52 );
		line(  29, (80*i)+53, 314, (80*i)+53 );
		line(  29, (80*i)+54, 314, (80*i)+54 );

		sound(700); delay(100); nosound();
		delay(400);
	      }

    public:void gmenu();                                     // PUBLIC MEMBERS
  };

//****************************************************************************
// FUNCTION TO TOGGLE MENU
//****************************************************************************

void game_menu::toggle( int i, int temp )
  {
    char m1[]="1:   PLAY GAME      ",
	 m2[]="2:   ABOUT GAME     ",
	 m3[]="3:   GAME CONTROLS  ",
	 m4[]="4:   QUIT GAME      ";

    setcolor(15);                              // DE-HIGHLIGHT PREVIOUS CHOICE
    switch( temp )
      {
	case 1:menu_box(1,7);
	       outtextxy( 50, 100, m1 );
	       break;
	case 2:menu_box(2,7);
	       outtextxy( 50, 180, m2 );
	       break;
	case 3:menu_box(3,7);
	       outtextxy( 50, 260, m3 );
	       break;
	case 0:
	case 4:menu_box(4,7);
	       outtextxy( 50, 340, m4 );
	       break;
      }
    switch(i)                                          // HIGHLIGHT NEW CHOICE
      {
	case 1:menu_box(1,14);
	       setcolor(4);
	       outtextxy( 50, 100, m1 );
	       break;
	case 2:menu_box(2,14);
	       setcolor(4);
	       outtextxy( 50, 180, m2 );
	       break;
	case 3:menu_box(3,14);
	       setcolor(4);
	       outtextxy( 50, 260, m3 );
	       break;
	case 0:
	case 4:menu_box(4,14);
	       setcolor(4);
	       outtextxy( 50, 340, m4 );
	       break;
      }
    sound(800); delay(50); nosound();
  }

//****************************************************************************
// CLASS TO START NEW GAME
//****************************************************************************

class new_game
  {
    private:                                                // PRIVATE MEMBERS

//****************************************************************************
// FUNCTION TO COVER MARIO WITH A BOX
//****************************************************************************

	    void rep_mario( int x, int y )
	      {
		int poly[8];
		setfillstyle(1,1);
		setcolor(1);
		poly[0]=x-15;
		poly[1]=y-20;
		poly[2]=x+33;
		poly[3]=y-20;
		poly[4]=x+33;
		poly[5]=y+10;
		poly[6]=x-20;
		poly[7]=y+10;
		fillpoly( 4,poly );
	      }

						    // FUNCTION PROTOTYPES
	    void spaceship( int, int );


//****************************************************************************
// FUNCTION TO DRAW MARIO AND KIARA
//****************************************************************************

	    void mario( int x, int y, int ctr )
	      {
		int sh=7,b ,f ;
		if( ctr%2==0 )
		  {
		    b=x-4;
		    f=x+6;
		  }
		else
		  {
		    b=x+6;
		    f=x-4;
		  }
		setfillstyle(1,sh);                               // HIND SHOE
		setcolor(0);
		fillellipse( b, y+6, 7, 4 );

		setfillstyle(1,14);
		setcolor(14);               	                  // FACE
		fillellipse( x, y-5, 10, 10 );

		int l,e;
		if( ctr>=-1000 )
		  {
		    l=x+4;
		    e=l+2;
		  }
		else
		  {
		    l=x-4;
		    e=l-2;
		    setcolor(4);
		    setfillstyle(9,4);
		    fillellipse( x-5, y-16, 6, 3 );
		    fillellipse( x+5, y-16, 6, 3 );
		  }

		setfillstyle(1,15);
		setcolor(0);                                      // EYE
		fillellipse( l, y-7, 4, 4 );

		setfillstyle(1,0);
		fillellipse( e, y-7, 2, 2 );                      // EYE

		setfillstyle(1,8);
		setcolor(0);                                      // FORE SHOE
		fillellipse( f, y+6, 7, 4 );

		if( ctr>=0 )
		  {
		    fillellipse( x+21, y-3, 12, 2 );              // DRAW GUN
		    fillellipse( x+14, y-2,  3, 3 );
		    fillellipse( x+12,   y,  1, 5 );

		    setfillstyle(1,14);                           // DRAW HAND
		    fillellipse( x+10, y+2,  7, 2 );
		  }
		else if( ctr>-1500 )
		  {
		    setcolor(2);
		    line( x+15, y-2, x+15, y-10 );
		    line( x+16, y-2, x+16, y-10 );

		    setfillstyle(1,4);
		    setcolor(0);
		    fillellipse( x+15, y-12, 4, 2 );

		    setfillstyle(1,14);
		    setcolor(0);
		    fillellipse( x+10, y+2, 7, 2 );
		  }
	      }

	    void walk_sound();

    public:void story();                                     // PUBLIC MEMBERS

  };

//****************************************************************************
// FUNCTION TO DRAW & MOVE ZANG'S SPACESHIP
//****************************************************************************

void new_game::spaceship( int x, int y )
  {
    for( int a=x; a>=y; a-=10 )
      {
	setcolor(1);
	setfillstyle(1,1);
	fillellipse( a, 200, 60, 20 );
	fillellipse( a, 205, 90, 10 );

	setcolor(8);
	setfillstyle(6,8);
	fillellipse( a-10, 200, 60, 20);
	fillellipse( a-10, 205, 90, 10);

	sound(200);   delay(20);
      }
    nosound();
  }

//****************************************************************************
// FUNCTION TO CREATE WALKING SOUND
//****************************************************************************

void new_game::walk_sound()
  {
    for( int i=300; i>=275; i-- )
      {
	sound( i*3 );
	delay(1);
      }
    nosound();
  }

//****************************************************************************
// FUNCTION TO DRAW CLOUDS
//****************************************************************************

	    void draw_cloud( int x, int y, int c )
	      {
		setfillstyle(1,c);
		setcolor(c);
		fillellipse(    x,    y, 25, 10 );
		fillellipse( x-45,    y, 25, 10 );
		fillellipse( x-15, y-10, 25, 10 );
		fillellipse( x+15, y-10, 25, 10 );
		fillellipse( x+45,    y, 25, 10 );
		fillellipse( x+15, y+10, 25, 10 );
		fillellipse( x-15, y+10, 25, 10 );
	      }

//****************************************************************************
// FUNCTION TO ANIMATE STORY OF THE GAME
//****************************************************************************

void new_game::story()
  {
    graphdefaults();                                        // DRAW BACKGROUND
    int x1=1,x2=getmaxx(),y1=350,y2=350;
    setcolor(15);
    line( x1, y1, x2, y2);
    setfillstyle(1,1); floodfill(20,20,15);
    setfillstyle(9,6); floodfill(20,400,15);

    graphdefaults();
    int x=0,y=680,ctr=-1000;                                  // TO SHOW MARIO
    while( x<200 )
      {
	rep_mario( x, 339 );
	x+=10;   ctr++;
	mario( x, 339, ctr);
	walk_sound();
	delay(50);
      }
    draw_cloud( x, 260, 15 );
    delay(500);
    setcolor(0);
    outtextxy( x-50, 250, "Today I will" );
    outtextxy( x-50, 260, "propose her " );
    delay(2000);
    draw_cloud( x, 260, 1 );
    delay(200);
    int h=-2000;
    while( y>250 )
      {
	rep_mario( y+4,339 );                                 // TO SHOW KIARA
	y-=10;   h--;
	mario( y, 339, h );
	walk_sound();
	delay(50);
      }
    spaceship( 750, 250 );                                // TO SHOW SPACESHIP
    int g=339;
    while( g>250 )
      {
	rep_mario( y+4, g );
	h--;   g-=10;
	mario( y, g, h );
	delay(50);
      }
    rep_mario( y+4, g );
    spaceship( 250, -150 );

    draw_cloud( x, 260, 15 );
    setcolor(0);
    outtextxy( x-50, 250, "I should try" );
    outtextxy( x-50, 260, " saving her " );
    settextstyle(0,0,2);
    while( !kbhit() )                         // BLINK TEXT TO PROCEED FURTHER
      {
	sound(500);   delay(200);
	setcolor(14);
	outtextxy( 200, 420, "PRESS ANY KEY TO CONTINUE" );
	nosound();
	delay(500);
	setcolor(6);
	outtextxy( 200, 420, "PRESS ANY KEY TO CONTINUE" );
	delay(400);
      }
    nosound();
    getch();
    cleardevice();
  }

//****************************************************************************
// CLASS TO SHOW USER ABOUT THE GAME
//****************************************************************************

class about_game
  {
    private:int r,c,i,x1,x2,y1,y2,ch;                       // PRIVATE MEMBERS

    public:about_game()                                     // PUBLIC MEMBERS
	     {
	       r=c=i=x1=x2=y1=y2=ch=0;                 // CONSTRUCTOR FUNCTION
	     }
	   void aboutg();                                // FUNCTION PROTOTYPE
  };

//****************************************************************************
// FUNCTION TO DISPLAY STORY OF THE GAME
//****************************************************************************

void about_game::aboutg()
  {
    graphdefaults();
    y1=1; y2=11;
    char text1[]="   Zang ,an old enemy of Mario has  ",
	 text2[]="kidnapped Kiara ,Mario 's girlfriend",
	 text3[]=" so as to take revenge from Mario . ",
	 text4[]="  Help Mario to fetch Zang and save ",
	 text5[]="                Kiara .             ",
	 text6[]="              GOOD LUCK             ",
	 text7[]="     PRESS 'B' TO GO BACK TO MENU   ";

    setfillstyle(1,15);
    floodfill(1,1,1);
    int x=0,y=0,xf,yf;
    for(int c=0,j;c<=2000;c++)
      {
	j=random(8);
	setcolor(j);
	xf=random(640);
	yf=random(480);
	line(x,y,xf,yf);
	line(x,y+1,xf,yf+1);
	x=xf;   y=yf;
      }
    nosound();
    delay(2000);

    setcolor(12);                                  // DRAW BOX TO DISPLAY TEXT
    rectangle( 100, 100, 540, 380 );
    setfillstyle(1,0);   floodfill(200,200,12);
    setcolor(15);
    rectangle( 100, 100, 540, 380 );
    rectangle(  99,  99, 541, 381 );
    rectangle(  98,  98, 542, 382 );
    rectangle(  97,  97, 543, 383 );
    rectangle(  96,  96, 544, 384 );

    settextjustify(1,1);                                       // DISPLAY TEXT
    settextstyle(7,0,2);
    setcolor(2);
    outtextxy( 320, 120, text1 );
    outtextxy( 320, 150, text2 );
    outtextxy( 320, 180, text3 );
    outtextxy( 320, 210, text4 );
    outtextxy( 320, 240, text5 );
    setcolor(5);
    settextstyle(10,0,3);
    outtextxy( 330, 300, text6 );
    setcolor(14);
    settextstyle(2,0,7);
    outtextxy( 300, 350, text7 );

    again:
    while( !kbhit() )
      {
	sound1();
      }
    ch=getch();
    switch( ch )
      {
	case 98:nosound();
		break;
	default:goto again;
      }
  }

//****************************************************************************
// CLASS TO SHOW GAME CONTROLS
//****************************************************************************

class game_controls
  {
    private:int r,c,i,x1,x2,y1,y2,ch;            	    // PRIVATE MEMBERS

    public:game_controls()                                  // PUBLIC MEMBERS
	     {
	       r=c=i=x1=x2=y1=y2=ch=0;                 // CONSTRUCTOR FUNCTION
	     }
	   void gcontrols();                             // FUNCTION PROTOTYPE
  };

//****************************************************************************
// FUNCTION TO DRAW GAME CONTROLLER KEYS
//****************************************************************************

void game_controls::gcontrols()
  {
    graphdefaults();
    settextjustify(1,1);
    y1=1; y2=11;
    char keywd1[]="Esc",
	 keywd2[]="Space",
	 keywd3[]="To move Left",
	 keywd4[]="To move Right",
	 keywd5[]="To Exit",
	 keywd6[]="To Pause",
	 keywd7[]="To Jump",
	 keywd8[]="To Shoot",
	 text1[]="  For sideways jumping ,press jump key    ",
	 text2[]="then press and hold right/left arrow key .",
	 text3[]="      PRESS 'B' TO GO BACK TO MENU    ";

    setfillstyle(1,15);
    floodfill(1,1,1);
    int x=0,y=0,xf,yf;
    for(int c=0,j;c<=2000;c++)
      {
	j=random(8);
	setcolor(j);
	xf=random(640);
	yf=random(480);
	line(x,y,xf,yf);
	line(x,y+1,xf,yf+1);
	x=xf;   y=yf;
      }
    nosound();
    delay(2000);

    setcolor(12);                                   // DRAW BOX TO DRAW KEYS IN
    rectangle( 100, 100, 540, 380 );
    setfillstyle(1,0);   floodfill(200,200,12);
    setcolor(15);
    rectangle( 100, 100, 540, 380 );
    rectangle(  99,  99, 541, 381 );
    rectangle(  98,  98, 542, 382 );
    rectangle(  97,  97, 543, 383 );
    rectangle(  96,  96, 544, 384 );

    setcolor(4);
    rectangle( 155, 125, 185, 155 );
    rectangle( 235, 125, 265, 155 );
    rectangle( 350, 125, 380, 155 );
    rectangle( 455, 125, 485, 155 );
    rectangle( 175, 205, 205, 235 );
    rectangle( 285, 205, 485, 235 );
    setfillstyle(1,4);
    floodfill( 160, 130, 4 );
    floodfill( 240, 130, 4 );
    floodfill( 355, 130, 4 );
    floodfill( 460, 130, 4 );
    floodfill( 180, 210, 4 );
    floodfill( 290, 210, 4 );

    setcolor(15);
    rectangle( 150, 120, 180, 150 );
    rectangle( 230, 120, 260, 150 );
    rectangle( 345, 120, 375, 150 );
    rectangle( 450, 120, 480, 150 );
    rectangle( 170, 200, 200, 230 );
    rectangle( 280, 200, 480, 230 );
    setfillstyle(1,15);
    floodfill( 152, 122, 15 );
    floodfill( 232, 122, 15 );
    floodfill( 347, 122, 15 );
    floodfill( 452, 122, 15 );
    floodfill( 172, 202, 15 );
    floodfill( 282, 202, 15 );

    setcolor(0);                                            // DRAW LEFT ARROW
    line( 178, 135, 165, 135 );
    line( 178, 136, 165, 136 );
    line( 165, 130, 165, 140 );
    line( 165, 130, 152, 135 );
    line( 165, 140, 152, 135 );
    setfillstyle(1,0);   floodfill(160,135,0);

    setcolor(0);                                           // DRAW RIGHT ARROW
    line( 245, 135, 232, 135 );
    line( 245, 136, 232, 136 );
    line( 245, 130, 245, 140 );
    line( 245, 130, 258, 135 );
    line( 245, 140, 258, 135 );
    setfillstyle(1,0);   floodfill(250,135,0);

    setcolor(0);                                              // DRAW UP ARROW
    line( 185, 228, 185, 215 );
    line( 186, 228, 186, 215 );
    line( 180, 215, 190, 215 );
    line( 180, 215, 185, 202 );
    line( 190, 215, 186, 202 );
    setfillstyle(1,0);   floodfill(185,210,0);

    setcolor(0);                                   // DISPLAY FUNCTION OF KEYS
    settextstyle(1,0,1);
    outtextxy( 360, 130, keywd1 );
    outtextxy( 370, 210, keywd2 );
    outtextxy( 465, 130,    "P" );
    setcolor(2);
    settextstyle(2,0,4);
    outtextxy( 165, 170, keywd3 );
    outtextxy( 260, 170, keywd4 );
    outtextxy( 365, 170, keywd5 );
    outtextxy( 465, 170, keywd6 );
    outtextxy( 190, 250, keywd7 );
    outtextxy( 370, 250, keywd8 );
    settextstyle(7,0,1);
    setcolor(5);
    outtextxy( 330, 280, text1 );
    outtextxy( 330, 310, text2 );
    setcolor(14);
    settextstyle(2,0,7);
    outtextxy( 300, 350, text3 );

    again:
    while( !kbhit() )
      {
	sound1();
      }
    ch=getch();
    switch( ch )
      {
	case 98:nosound();
		break;
	default:goto again;
      }
  }



//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


class level3
  {
    public:void rep_mario( int x, int y, int c )
	     {
	       setfillstyle(1,c);
	       setcolor(c);
	       rectangle(x-20,y-20,x+33,y+10);
	       floodfill(x,y,c);
	     }
	   void draw_cloud( int x, int y, int c )
	     {
	       setfillstyle(1,c);
	       setcolor(c);
	       fillellipse(    x,    y, 25, 10 );
	       fillellipse( x-45,    y, 25, 10 );
	       fillellipse( x-15, y-10, 25, 10 );
	       fillellipse( x+15, y-10, 25, 10 );
	       fillellipse( x+45,    y, 25, 10 );
	       fillellipse( x+15, y+10, 25, 10 );
	       fillellipse( x-15, y+10, 25, 10 );
	     }
	   void vil_zang( int x, int y, int ctr )
	      {
		int sh=7,b ,f ;
		if( ctr%2==0 )
		  {
		    b=x-4;
		    f=x+6;
		  }
		else
		  {
		    b=x+6;
		    f=x-4;
		  }
		setfillstyle(1,sh);                               // HIND SHOE
		setcolor(0);
		fillellipse( b, y+6, 7, 4 );

		setfillstyle(1,0);                                // FACE
		setcolor(8);
		fillellipse( x, y-5, 10, 10 );

		setfillstyle(1,15);                               // EYE
		setcolor(0);
		fillellipse( x-4, y-7, 4, 4 );

		setfillstyle(1,0);                                // EYE
		fillellipse( x-6, y-7, 2, 2 );

		setfillstyle(1,8);                                // FORE SHOE
		setcolor(0);
		fillellipse( f, y+6, 7, 4 );
	      }
	   void mario( int x, int y, int ctr, int c )
	      {
		int sh=7,b ,f ;
		if( ctr%2==0 )
		  {
		    b=x-4;
		    f=x+6;
		  }
		else
		  {
		    b=x+6;
		    f=x-4;
		  }
		setfillstyle(1,sh);                               // HIND SHOE
		setcolor(0);
		fillellipse( b, y+6, 7, 4 );

		setfillstyle(1,c);
		setcolor(c);               	                  // FACE
		fillellipse( x, y-5, 10, 10 );

		int l,e;
		if( ctr>=-1000 )
		  {
		    l=x+4;
		    e=l+2;
		  }
		else
		  {
		    l=x-4;
		    e=l-2;
		    setcolor(4);
		    setfillstyle(9,4);
		    fillellipse( x-5, y-16, 6, 3 );
		    fillellipse( x+5, y-16, 6, 3 );
		  }

		setfillstyle(1,15);
		setcolor(0);                                      // EYE
		fillellipse( l, y-7, 4, 4 );

		setfillstyle(1,0);
		fillellipse( e, y-7, 2, 2 );                      // EYE

		setfillstyle(1,8);
		setcolor(0);                                      // FORE SHOE
		fillellipse( f, y+6, 7, 4 );

		if( ctr>=0 )
		  {
		    fillellipse( x+21, y-3, 12, 2 );              // DRAW GUN
		    fillellipse( x+14, y-2,  3, 3 );
		    fillellipse( x+12,   y,  1, 5 );

		    setfillstyle(1,c);                           // DRAW HAND
		    fillellipse( x+10, y+2,  7, 2 );
		  }
		else if( ctr>-1500 )
		  {
		    setcolor(2);
		    line( x+15, y-2, x+15, y-10 );
		    line( x+16, y-2, x+16, y-10 );

		    setfillstyle(1,4);
		    setcolor(0);
		    fillellipse( x+15, y-12, 4, 2 );

		    setfillstyle(1,c);
		    setcolor(0);
		    fillellipse( x+10, y+2, 7, 2 );
		  }
	      }
	    void main3()
	      {
		clrscr();
		int gd=DETECT,gm=DETECT;
		initgraph( &gd, &gm, "c:\\turboc3\\bgi" );
		game_bkgrd(0);
		castle();
		gameplay();
		fight();
		end e3;
		e3.congrats();
	      }

	    void fight();
	    void gun_sound();
	    void jump( int&x, int&y );
	    void walk_sound();
	    void castle();
	    void game_bkgrd(int);
	    void gameplay();
  };

void level3::fight()
  {
    cleardevice();
    int x,y;
    game_bkgrd(1);
    vil_zang(440,339,1);
    x=320;y=99;
    while( y<339 )
      {
	rep_mario( x,y,12 );
	y+=10;   x-=5;
	mario(x, y, 1,14);
	walk_sound();
	delay(50);
      }

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, "  WHERE IS  " );
    outtextxy( 180, 263, " SHE ? ZANG"  );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    draw_cloud( 430, 260, 15 );
    setcolor(0);
    outtextxy( 380, 253, "YOU WILL NEVER" );
    outtextxy( 380, 263, " GET HER BACK"  );
    delay(3000);
    draw_cloud( 430, 260, 15 );
    setcolor(0);
    outtextxy( 430-50, 253, "YOU FIRST HAVE" );
    outtextxy( 430-50, 263, "TO KILL ME"  );
    delay(3000);
    draw_cloud( 430, 260, 12 );

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, " AS YOU WISH" );
    outtextxy( 180, 263, " SO... DIE" );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    for( int i=1; i<=3; i++ )                                    // SHOOT ZANG
      {
	gun_sound();
	int x=250,y=335;
	while( x<420 )
	  {
	    setcolor(12);
	    setfillstyle(1,12);
	    fillellipse( x, y, 5, 5 );
	    x=x+5;
	    setfillstyle(1,0);
	    fillellipse( x, y, 5, 5 );
	    delay(5);
	  }
	setcolor(12);
	setfillstyle(1,12);
	fillellipse( x, y, 5, 5 );
	delay(500);
      }
    draw_cloud( 430, 260, 15 );
    setcolor(0);
    outtextxy( 430-50, 253, " YOU STILL" );
    outtextxy( 430-50, 263, "CAN'T KILL ME" );
    delay(3000);
    draw_cloud( 430, 260, 12 );
    int up=339;
    for( int j=1; j<=2; j++ )
      {
	gun_sound();
	int x=420,y=335;
	while( x>150 )
	  {
	    setcolor(12);
	    setfillstyle(1,12);
	    fillellipse( x, y, 5, 5 );
	    x-=5;
	    if(up>300)
	      {
		rep_mario(200,up,12);
		mario(200,up-10,1,14);
		up-=10;
	      }
	    setfillstyle(1,14);
	    fillellipse( x, y, 5, 5 );
	    delay(5);
	  }
	while(up<339)
	  {
	    rep_mario(200,up,12);
	    mario(200,up+10,1,14);
	    up+=10;
	  }
	setcolor(12);
	setfillstyle(1,12);
	fillellipse( x, y, 5, 5 );
	delay(500);
      }

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, " I SHOULD " );
    outtextxy( 180, 263, "  UPGRADE"  );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, "SUPER MARIO" );
    outtextxy( 180, 263, "POWER UP..."  );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    for(int g=1;g<=7;g++)
      {
	rep_mario(200,339,12);
	delay(200);
	mario(200,339,1,14);
	delay(150);
      }
    mario(200,339,1,4);

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, "NOW YOU HAVE" );
    outtextxy( 180, 263, "TO DIE, ZANG" );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    gun_sound();
    x=250,y=335;
    i=0;
    while( x<420 )
      {
	setcolor(12);
	setfillstyle(1,12);
	fillellipse( x, y, 14, 14 );
	x+=5;
	setfillstyle(1,i);
	fillellipse( x, y, 14, 14 );
	delay(50);
	i++;
	if(i==8)
	   i=0;
      }
    setcolor(12);
    setfillstyle(1,12);
    fillellipse( x, y, 14, 14 );
    delay(200);

    setcolor(0);
    for(int s=0;s<150;s++)
      {
	circle(440,339,s);
	delay(30);
      }

    delay(500);
    cleardevice();
    game_bkgrd(1);
    mario(200,339,1,14);

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, "AT LAST,I" );
    outtextxy( 180, 263, " KILLED HIM" );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    x=320;y=99;
    int h=-2000;
    while( y<339 )
      {
	rep_mario( x,y,12 );
	y+=10;   x+=5;   h--;
	mario(x, y, h,14);
	walk_sound();
	delay(50);
      }

    draw_cloud( 430, 260, 15 );
    setcolor(0);
    outtextxy( 430-50, 253, "THANKS FOR" );
    outtextxy( 430-50, 263, "SAVING ME"  );
    delay(3000);
    draw_cloud( 430, 260, 12 );

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 258, " WELCOME" );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    draw_cloud( 230, 260, 15 );
    setcolor(0);
    outtextxy( 180, 253, " LETS GET" );
    outtextxy( 180, 263, "OUT OF HERE" );
    delay(3000);
    draw_cloud( 230, 260, 12 );

    int x1=200,x2=440;
    y=339;   h=-2000;
    while( y>80 )
      {
	rep_mario(x1,y,12);
	rep_mario(x2,y,12);
	y-=10;    x1+=3;   x2-=3;   h--;
	mario(x1,y,1,14);
	mario(x2,y,h,14);
	walk_sound();
	delay(50);
      }
  }
void level3::gun_sound()
  {
    for( int i=500; i>=450; i-- )
      {
	sound( i*10 );
	delay(1);
      }
    for( i=450; i<=500; i++ )
      {
	sound( i*10 );
	delay(1);
      }
    nosound();
  }

void level3::jump( int&x, int&y )
  {
    char c;
    for( int i=1; i<=6; i++ )
      {
	c=0;
	for( int u=1; u<=20; u++ )
	  {
	    if( kbhit() )
	      {
		c=getch();
	      }
	    rep_mario( x, y ,1);
	    if( i<=3 )
		 y-=3;
	    else
		 y+=3;

	    if( (c==77) && (x<350) )
		 x+=4;
	    else if( c==75 )
		 x-=4;
	    mario( x, y, 1 ,14);
	    delay(10);
	  }
      }
  }

//****************************************************************************
// FUNCTION TO CREATE WALKING SOUND
//****************************************************************************

void level3::walk_sound()
  {
    for( int i=300; i>=275; i-- )
      {
	sound( i*3 );
	delay(1);
      }
    nosound();
  }

void level3::castle()
  {
    setcolor(0);
    rectangle( 370, 269, 610, 349 );
    rectangle( 390, 189, 590, 269 );
    rectangle( 410, 109, 570, 189 );
    setfillstyle(1,8);
    floodfill( 490, 275, 0 );
    floodfill( 490, 195, 0 );
    floodfill( 490, 115, 0 );

    setcolor(0);
    setfillstyle(1,6);

    rectangle( 370, 295, 450, 349 );
    ellipse  ( 410, 298,   0, 180, 40, 20 );
    rectangle( 520, 305, 550, 340 );
    ellipse  ( 535, 305,   0, 180, 15, 20 );
    floodfill( 375, 300,   0 );
    floodfill( 525, 310,   0 );
    floodfill( 410, 290,   0 );
    floodfill( 535, 300,   0 );

    rectangle( 420, 220, 450, 255 );
    ellipse  ( 435, 220,   0, 180, 15, 20 );
    rectangle( 530, 220, 560, 255 );
    ellipse  ( 545, 220,   0, 180, 15, 20 );
    floodfill( 425, 225,   0 );
    floodfill( 535, 225,   0 );
    floodfill( 435, 215,   0 );
    floodfill( 545, 215,   0 );

    rectangle( 440, 140, 470, 175 );
    ellipse  ( 455, 140,   0, 180, 15, 20 );
    rectangle( 510, 140, 540, 175 );
    ellipse  ( 525, 140,   0, 180, 15, 20 );
    floodfill( 445, 145,   0 );
    floodfill( 515, 145,   0 );
    floodfill( 455, 135,   0 );
    floodfill( 525, 135,   0 );

    int m,n=249,inc=0,dec=1;
    setfillstyle(9,7);
    for(int i=1;i<=3;i++)
      {
	m=375+inc;
	for(int j=1;j<=(9-dec);j++)
	  {
	    setcolor(4);
	    rectangle(   m,   n, m+20, n+20 );
	    floodfill( m+5, n+5,    4 );
	    setcolor(0);
	    rectangle(   m,   n, m+20, n+20 );
	    m+=30;
	  }
	n-=80;
	inc+=30;
	dec+=2;
      }
    rectangle( 485, 29, 495, 109 );
    rectangle( 495, 29, 565,  59 );
    setfillstyle(1,4);
    floodfill(490,35,0);
    setfillstyle(1,14);
    floodfill(500,35,0);
    setcolor(0);
    settextstyle(0,0,2);
    outtextxy(500,37,"ZANG");
  }

//****************************************************************************
// FUNCTION TO DRAW BACKGROUND OF ACTUAL GAME
//****************************************************************************

void level3::game_bkgrd(int val)
  {
    graphdefaults();                                  // DRAW SKY AND PLATFORM
    int x1=0,x2=getmaxx(),y1=350,y2=350;
    setcolor(15);
    line( x1, y1, x2, y2);
    if(val==0)
      {
	setfillstyle(1,1);   floodfill(20,20,15);
	setfillstyle(9,2);   floodfill(20,400,15);      // DRAW SUN AND CLOUDS
	int cc=15,cy=60;
	draw_cloud( 100, cy, cc );
	draw_cloud( 300, cy, cc );
      }
    else if(val==1)
      {
	int m,n=351;
	setcolor(6);
	setfillstyle(1,2);
	rectangle(1,1,getmaxx(),getmaxy());
	line(x1,y1,x2,y2);
	for(int i=1;i<=6;i++)
	  {
	    m=0;
	    for(int j=1;j<=26;j++)
	      {
		ellipse(  m+8,  n+4,   4, 100, 8, 4 );
		ellipse( m+23,    n, 220, 308, 8, 4 );
		ellipse( m+23,  n+8, 325,  35, 4, 8 );
		ellipse( m+27, n+21,  95, 210, 4, 8 );
		ellipse( m+21, n+21, 200, 285, 8, 4 );
		ellipse(  m+5, n+23,  10, 115, 8, 4 );
		ellipse(  m+4, n+18, 100, 200, 4, 8 );
		ellipse(    m,  n+3, 290,  10, 4, 8 );
		floodfill( m+8, n+4, 6);
		m+=25;
	      }
	    n+=21;
	  }
	setcolor(15);
	line(x1,y1,x2,y2);

	ellipse( 20,  25, 270,  12, 80, 125 );
	ellipse( 80, 180, 170, 238, 40, 200 );
	setfillstyle(1,4);
	floodfill(10,10,15);
	ellipse(   5, 25, 300,  12, 80, 125 );
	ellipse( -10, 25, 320, 360, 80, 125 );
	ellipse( -20, 25, 270,   5, 80, 125 );
	ellipse( -40, 25, 340,  12, 80, 125 );
	line( 30, 180, 30, 270 );
	line( 20, 220, 20, 340 );
	line(  5, 200,  5, 250 );

	ellipse( 619,  25, 165, 270, 80, 125 );
	ellipse( 559, 180, 302,  10, 40, 200 );
	setfillstyle(1,4);
	floodfill(630,10,15);
	ellipse( 635, 25, 168, 240, 80, 125 );
	ellipse( 650, 25, 180, 220, 80, 125 );
	ellipse( 660, 25, 175, 270, 80, 125 );
	ellipse( 680, 25, 168, 200, 80, 125 );
	line( 610, 180, 610, 270 );
	line( 620, 220, 620, 340 );
	line( 635, 200, 635, 250 );

	line( 300,  0,  48, 295 );
	line( 340,  0, 592, 295 );
	line( 258, 50, 382,  50 );
	line( 258,  0, 258,  50 );
	line( 382,  0, 382,  50 );
	line( 248,  0, 248,  60 );
	line( 392,  0, 392,  60 );

	setfillstyle(1,2);
	floodfill( 300, 10, 15 );
	setfillstyle(1,1);
	floodfill( 260, 10, 15 );
	floodfill( 380, 10, 15 );
	setfillstyle(1,6);
	floodfill( 250, 10, 15 );
	floodfill( 390, 10, 15 );

	int poly1[8]={ 150, 40, 200, 10, 200, 70, 150, 120 };
	int poly2[8]={ 490, 40, 440, 10, 440, 70, 490, 120 };
	setfillstyle(1,1);
	fillpoly(4,poly1);
	fillpoly(4,poly2);

	setfillstyle(4,7);
	floodfill( 200,   5, 15 );
	setfillstyle(5,7);
	floodfill( 440,   5, 15 );
	setfillstyle(1,12);
	floodfill( 320, 240, 15 );
      }
  }

//****************************************************************************
// FUNCTION TO ACCEPT KEYS FROM USER TO PLAY GAME
//****************************************************************************

void level3::gameplay()
  {
    graphdefaults();
    int x=10,y=339;
    mario( x, y, 1 ,14);
    delay(4000);
    int ctr=0;                                  // TO SHOW MARIO
    while( x<340 )
      {
	rep_mario( x, 339 ,1);
	x+=10;   ctr++;
	mario( x, y, ctr, 14);
	walk_sound();
	delay(50);
      }
    delay(1000);
  }



//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

class level2
  {
    private:int x,y,x_ship,y_ship,bx,life,enemy_num,score,m,n1,n2,n3,n4;

    public:level2()
	     {
	       x=150;  y=200;  x_ship;  y_ship;
	       bx=660;  life=3;  enemy_num=0;  score;
	     }

	   void enemy_wo(int x_ship,int y_ship)
	     {
	       setcolor(0);
	       setfillstyle(1,0);
	       fillellipse(x_ship+8,y_ship,40,15);
	       setcolor(15);
	       setfillstyle(1,15);
	       fillellipse(x_ship,y_ship,40,15);
	       setcolor(1);
	       ellipse(x_ship,y_ship-15,240,300,70,20);
	       ellipse(x_ship,y_ship-12,240,300,70,20);
	     }

	   void init();
	   void move(int&x,int&y,char ch);
	   void scor();
	   void shoot(int x,int y,int&x_ship,int&y_ship);
	   void choice(char ch);
	   void blink();
	   void enemy_wi(int&,int&,char);
	   void main2();
  };


void level2::init()
  {
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    graphdefaults();
    move(x,y,0);

    setcolor(15);
    setfillstyle(1,0);
    line   (  50, 450, 150, 450 );
    line   (  50, 470, 150, 470 );
    ellipse(  50, 460,  90, 270, 10, 10 );
    ellipse( 150, 460, 270,  90, 10, 10 );
    floodfill(151,451,15);

    line   ( 200, 450, 300, 450 );
    line   ( 200, 470, 300, 470 );
    ellipse( 200, 460,  90, 270, 10, 10 );
    ellipse( 300, 460, 270,  90, 10, 10 );
    floodfill(301,451,15);

    setcolor(9);
    outtextxy( 210, 457, "SCORE: 0000" );
    outtextxy(  59, 457, "LIFE:"      );

    for(int i=1; i<=3; i++ )
      {
	setcolor(14);
	setfillstyle(1,14);
	fillellipse( 95+(i*18), 460, 6, 4 );
      }
    setcolor(15);
    line(0,380,640,380);
    line(0,90,640,90);
    setfillstyle(1,6);
    floodfill(1,1,15);
    floodfill(1,400,15);
  }
void level2::move(int&x,int&y,char ch)
  {
    for(int i=0;i<=5;i++)
      {
	if(ch==72&&y>200)
	  {
	    y-=12;
	  }
	else if(ch==80&&y<344)
	  {
	    y+=12;
	  }
	setfillstyle(1,0);
	setcolor(0);
	fillellipse(x+20,y-35,100,50);

	setfillstyle(1,0);
	setcolor(0);
	fillellipse(x+14,y-35,96,65);
	fillellipse(x_ship,y_ship,50,30);

	x_ship-=8;
	enemy_wo(x_ship,y_ship);

	setcolor(7);

	ellipse(x,y,10,145,90,70);
	ellipse(x+78,y-12 ,270,0,10,10);

	ellipse(x+77,y-72,220,270,90,70);
	ellipse(x-42,y+93,57,110,94,140);
	ellipse(x-10,y-55,200,290,50,30);
	setfillstyle(1,7);
	floodfill(x,y-40,7);
	setfillstyle(1,1);
	floodfill(x-20,y-30,7);

	delay(17);
      }
  }
void level2::scor()
  {
    setfillstyle(1,0);
    setcolor(0);
    fillellipse( 278, 460, 20, 6 );
    setcolor(9);

    switch( score/100 )
      {
	case 0:outtextxy( 210, 457, "       0" );   break;
	case 1:outtextxy( 210, 457, "       1" );   break;
	case 2:outtextxy( 210, 457, "       2" );   break;
	case 3:outtextxy( 210, 457, "       3" );   break;
      }
    switch( (score/10)%10 )
      {
	case 0:outtextxy( 210, 457, "        0" );   break;
	case 1:outtextxy( 210, 457, "        1" );   break;
	case 2:outtextxy( 210, 457, "        2" );   break;
	case 3:outtextxy( 210, 457, "        3" );   break;
	case 4:outtextxy( 210, 457, "        4" );   break;
	case 5:outtextxy( 210, 457, "        5" );   break;
	case 6:outtextxy( 210, 457, "        6" );   break;
	case 7:outtextxy( 210, 457, "        7" );   break;
	case 8:outtextxy( 210, 457, "        8" );   break;
	case 9:outtextxy( 210, 457, "        9" );   break;
      }
    switch( score%10 )
      {
	case 0:outtextxy( 210, 457, "         00" );   break;
	case 1:outtextxy( 210, 457, "         10" );   break;
	case 2:outtextxy( 210, 457, "         20" );   break;
	case 3:outtextxy( 210, 457, "         30" );   break;
	case 4:outtextxy( 210, 457, "         40" );   break;
	case 5:outtextxy( 210, 457, "         50" );   break;
	case 6:outtextxy( 210, 457, "         60" );   break;
	case 7:outtextxy( 210, 457, "         70" );   break;
	case 8:outtextxy( 210, 457, "         80" );   break;
	case 9:outtextxy( 210, 457, "         90" );   break;
      }
  }
void level2::shoot(int x,int y,int&x_ship,int&y_ship)
  {
    char ch;
    for(bx=x+95;bx<=700;bx+=10)
      {
	setcolor(0);
	circle(bx-10,y-30,3);

	setcolor(14);
	circle(bx+20,y-30,3);
	enemy_wo(x_ship,y_ship);
	x_ship-=8;
	if(getpixel(bx,y-30)==15)
	  {
	    bx=700;
	    setcolor(0);
	    setfillstyle(1,0);
	    score+=5;
	    scor();
	    setcolor(0);
	    fillellipse(x_ship,y_ship,50,30);
	    main2();
	  }
	delay(10);
      }
  }
void level2::choice(char ch)
  {
    switch(ch)
      {
	case 72:                                //75  Left
	case 80:move(x,y,ch);
		break;
	case 32:if(bx>640)
		shoot(x,y,x_ship,y_ship);
		break;
	case 27:exit(0);
	case 'p':a:
		 ch=getch();
		 switch(ch)
		   {
		     case 'p':break;
		     default:goto a;
		   }
		 break;
      }
  }
void level2::blink()
  {
    x_ship=950;
    setfillstyle(1,0);
    setcolor(0);
    for(int i=0;i<3;i++)
      {
	move(x,y,0);
	delay(350);
	setfillstyle(1,0);
	setcolor(0);
	fillellipse(x+17,y-35,100,60);
	delay(700);
      }
    life--;
    if(life==0)
	 exit(0);
    setcolor(0);
    setfillstyle(1,0);
    fillellipse( 95+((life+1)*18), 460, 6, 4 );

    move(x,y,0);
    delay(500);
  }
void level2::main2()
  {
    char ch;
    static int ctr=0;
    if(ctr==0)
      {
	init();
	delay(3000);
	ctr++;
      }
    setcolor(0);
    setfillstyle(1,0);
    fillellipse(x_ship,y_ship,50,30);
    enemy_num++;
    for(int a;enemy_num<40;enemy_num++)
      {
	if(enemy_num>35)
	  {
	    end e2;
	    e2.lvl2();
	    level3 l3;
	    l3.main3();
	  }
	a=random(10);
	if(a<2)
	     a=0;
	else if(a>=2&&a<5)
	     a=1;
	else
	     a=2;

	y_ship=165+(72*a);
	for(x_ship=700;x_ship>=0;x_ship-=8)
	  {
	    if(kbhit())
	      {
		ch=getch();
		choice(ch);
	      }
	    enemy_wo(x_ship,y_ship);

	    delay(25);
	    if((getpixel(x_ship-55,y_ship)==7||getpixel(x_ship-30,y_ship-12)==7||getpixel(x_ship-30,y_ship+12)==7||getpixel(x_ship+20,y_ship+18)==7||getpixel(x_ship-30,y_ship-18)==7||getpixel(x-65,y-35)==15)&&x_ship>40)
	      {
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(x_ship,y_ship,40,15);
		blink();
	      }
	  }
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(x_ship+8,y_ship,40,15);
      }
  }

//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


class level1
  {
    private:int x,y, ct,mnum,mx,score,life,platctr,t,ipl;

    public:level1()
	     {
	       x=10;y=339;ct=0;t=0;mnum=25;mx=700;score=0;life=3;
	     }
	  void rep_mario( int x, int y )
	    {
	      int poly[8];
	      setfillstyle(1,1);
	      setcolor(1);
	      poly[0]=x-15;
	      poly[1]=y-20;
	      poly[2]=x+33;
	      poly[3]=y-20;
	      poly[4]=x+33;
	      poly[5]=y+10;
	      poly[6]=x-20;
	      poly[7]=y+10;
	      fillpoly( 4,poly );
	    }

	  void black_vil( int xv, int c )
	    {
	      setfillstyle(1,c);                                     // BODY
	      setcolor(c);
	      fillellipse( xv, 329, 15, 15 );
	      if(c==1)
	      fillellipse( xv, 329, 18, 18 );
	      setfillstyle(1,15);                                    // EYE
	      setcolor(15);
	      fillellipse( xv-8, 325, 4, 4 );

	      setfillstyle(1,0);                                     // EYE
	      setcolor(0);
	      pieslice( xv-8, 322, 50, 200, 4 );

	      setfillstyle(1,c);
	      setcolor(c);
	      fillellipse( xv-10, 325, 2, 2);

	      setfillstyle(1,4);                                    // MOUTH
	      setcolor(4);

	      pieslice( xv-10, 339, 0, 120, 4 );
	      if(((getpixel(xv-25,330)==14)||(getpixel(xv,300)==14)||(getpixel(xv-7,310)==14))&&mx<(x+50))
		{
		  reduce();
		  mx=700;
		}
	      if(kbhit()&&c==0)
		{
		  gameplay();
		}
	    }

	  void mario( int ctr )
	    {
	      int sh=7,b ,f ;
	      if( ctr%2==0 )
		{
		  b=x-4;
		  f=x+6;
		}
	      else
		{
		  b=x+6;
		  f=x-4;
		}
	      setfillstyle(1,sh);                               // HIND SHOE
	      setcolor(0);
	      fillellipse( b, y+6, 7, 4 );

	      setfillstyle(1,14);
	      setcolor(14);               	                  // FACE
	      fillellipse( x, y-5, 10, 10 );

	      int l,e;
	      l=x+4;
	      e=l+2;

	      setfillstyle(1,15);
	      setcolor(0);                                      // EYE
	      fillellipse( l, y-7, 4, 4 );

	      setfillstyle(1,0);
	      fillellipse( e, y-7, 2, 2 );                      // EYE

	      setfillstyle(1,8);
	      setcolor(0);                                      // FORE SHOE
	      fillellipse( f, y+6, 7, 4 );

	      fillellipse( x+21, y-3, 12, 2 );              // DRAW GUN
	      fillellipse( x+14, y-2,  3, 3 );
	      fillellipse( x+12,   y,  1, 5 );

	      setfillstyle(1,14);                           // DRAW HAND
	      fillellipse( x+10, y+2,  7, 2 );
	    }

	  void draw_cloud( int x, int y, int c )
	    {
	      setfillstyle(1,c);
	      setcolor(c);
	      fillellipse(    x,    y, 25, 10 );
	      fillellipse( x-45,    y, 25, 10 );
	      fillellipse( x-15, y-10, 25, 10 );
	      fillellipse( x+15, y-10, 25, 10 );
	      fillellipse( x+45,    y, 25, 10 );
	      fillellipse( x+15, y+10, 25, 10 );
	      fillellipse( x-15, y+10, 25, 10 );
	    }

	  void cloudbk( int x, int y, int c )
	    {
	      setfillstyle(1,c);
	      setcolor(c);
	      ellipse( x-15, y-10,  50,  90, 25, 10 );
	      ellipse( x-15, y+10, 270, 310, 25, 10 );

	      ellipse( x+15, y-10,   0,  90, 25, 10 );
	      ellipse( x+15, y-10,   0,  30, 24,  9 );
	      ellipse( x+15, y+10, 270, 360, 25, 10 );
	      ellipse( x+15, y+10, 330, 360, 24,  9 );

	      ellipse( x+45,    y, 270, 360, 25, 10 );
	      ellipse( x+45,    y, 330, 360, 24,  9 );
	      ellipse( x+45,    y, 360,  90, 25, 10 );
	      ellipse( x+45,    y, 360,  30, 24,  9 );
	    }

	  void init()
	    {
	      clrscr();
	      int gd=DETECT,gm=DETECT;
	      initgraph( &gd, &gm, "c:\\turboc3\\bgi" );

	      game_bkgrd();
	      mario(1);
	    }

	  void badmove()
	    {
	      black_vil(mx+10,1);

	      black_vil(mx,0);
	      if(kbhit())
		{
		  gameplay();
		}
	      else
		   delay(60);
	    }


	  void main1();
	  void reduce();
	  void gun_sound();
	  void walk_sound();
	  void gameplay();
	  void movecloud();
	  void game_bkgrd();
	  void shoot();
	  void platform();
	  void move_all(int ch);
	  void jump();
	  void maine();
  };



void level1::reduce()
  {
    if (ct>0)
      {
	life--;
	if(life==0)
	     exit(0);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse( 95+((life+1)*18), 460, 6, 4 );
	mnum--;
	for( int i=0; i<=2; i++ )                 // BLINK
	  {
	    mario(1);
	    delay(40);
	    setcolor(1);
	    setfillstyle(1,1);
	    fillellipse( mx-5, y-10, 40, 20 );
	    fillellipse( mx-5, 329, 40, 20 );
	    delay(70);
	  }
	mario(1);
      }
  }
void level1::gun_sound()
  {
    for( int i=500; i>=450; i-- )
      {
	sound( i*10 );
	delay(1);
      }
    for( i=450; i<=500; i++ )
      {
	sound( i*10 );
	delay(1);
      }
    nosound();
  }
void level1::walk_sound()
  {
    for( int i=300; i>=275; i-- )
      {
	sound( i*3 );
	delay(1);
      }
    nosound();
  }
void level1::game_bkgrd()
  {
    graphdefaults();                                  // DRAW SKY AND PLATFORM
    int x1=1,x2=getmaxx(),y1=350,y2=350;
    setcolor(15);
    line( x1, y1, x2, y2);

    setfillstyle(9,8);   floodfill(20,400,15);

    setfillstyle(1,1);   floodfill(20,20,15);

    setfillstyle(1,14);
    setcolor(14);
    fillellipse( 400, 50, 40, 40 );
    int cc=15,cy=60;
    draw_cloud( 300, cy, cc );
    draw_cloud( 600, cy, cc );
    draw_cloud( 900, cy, cc );

    setcolor(15);
    setfillstyle(1,0);
    line   ( 200, 450, 300, 450 );
    line   ( 200, 470, 300, 470 );
    ellipse( 200, 460,  90, 270, 10, 10 );
    ellipse( 300, 460, 270,  90, 10, 10 );
    floodfill(301,451,15);

    setcolor(15);
    setfillstyle(1,0);
    line   (  50, 450, 150, 450 );
    line   (  50, 470, 150, 470 );
    ellipse(  50, 460,  90, 270, 10, 10 );
    ellipse( 150, 460, 270,  90, 10, 10 );
    floodfill(151,451,15);

    setcolor(9);                               // DISPLAY SCORE AND LIFE BOARD
    outtextxy( 210, 457, "SCORE: 000" );
    outtextxy(  59, 457, "LIFE:"      );
    for(int i=1; i<=3; i++ )
      {
	setcolor(14);
	setfillstyle(1,14);
	fillellipse( 95+(i*18), 460, 6, 4 );
      }
    for( i=0;i<=640;i+=3)
      {
       setcolor(1);
      setfillstyle(1,1);
      fillellipse(i,347,3,3);
      }
    setcolor(15);
    line( x1, y1+1, x2, y2+1);
  }
void level1::shoot()
  {
    int a=x+40;
    while( a<=645 )
      {
	setcolor(1);
	setfillstyle(1,1);
	fillellipse( a, y, 5, 5 );
	a=a+10;
	setfillstyle(1,0);
	fillellipse( a, y, 5, 5 );
	delay(5);

	if(getpixel(a+6,y)==0)
	  {
	    t=mx;   mx=700;
	    mario(1);

	    setcolor(1);
	    setfillstyle(1,1);
	    fillellipse( t, y-10, 40, 20 );
	    for( int i=0; i<=2; i++ )                 // BLINK ENEMY WHEN SHOT
	      {
		black_vil( t, 0 );
		delay(40);
		setcolor(1);
		setfillstyle(1,1);
		fillellipse( t, y-10, 20, 20 );
		delay(70);
		score=score+1;
	      }
	    t=0;
	    setfillstyle(1,0);
	    setcolor(0);
	    fillellipse( 278, 460, 20, 6 );
	    setcolor(9);
	    switch( score%10 )
	      {
		case 0:outtextxy( 210, 457, "        00" );   break;
		case 1:outtextxy( 210, 457, "        10" );   break;
		case 2:outtextxy( 210, 457, "        20" );   break;
		case 3:outtextxy( 210, 457, "        30" );   break;
		case 4:outtextxy( 210, 457, "        40" );   break;
		case 5:outtextxy( 210, 457, "        50" );   break;
		case 6:outtextxy( 210, 457, "        60" );   break;
		case 7:outtextxy( 210, 457, "        70" );   break;
		case 8:outtextxy( 210, 457, "        80" );   break;
		case 9:outtextxy( 210, 457, "        90" );   break;
	      }
	    switch( score/10 )
	      {
		case 0:outtextxy( 210, 457, "       0" );   break;
		case 1:outtextxy( 210, 457, "       1" );   break;
		case 2:outtextxy( 210, 457, "       2" );   break;
		case 3:outtextxy( 210, 457, "       3" );   break;
		case 4:outtextxy( 210, 457, "       4" );   break;
		case 5:outtextxy( 210, 457, "       5" );   break;
		case 6:outtextxy( 210, 457, "       6" );   break;
		case 7:outtextxy( 210, 457, "       7" );   break;
		case 8:outtextxy( 210, 457, "       8" );   break;
		case 9:outtextxy( 210, 457, "       9" );   break;
	      }
	    mx=700;
	    mnum--;
	    main1();
	  }
      }
  }
void level1::move_all(int ch)
  {
    static int ctr=0;
    ctr++;

    if( (ch==77) && (x>=300) )
      {
	mario( ctr );                                      // MOVE MARIO
	walk_sound();
	movecloud();
	platform();			    // MOVE ENEMIES
      }
    else
      {
	rep_mario( x, y );
	setcolor(1);
	setfillstyle(1,1);
	fillellipse( x, y, 10, 10 );
	if( ch==77 )
	     x=x+10;
	else if( (ch==75) && (x>15) )
	  {
	    x=x-10;
	  }
	mario(  ctr );
	walk_sound();
      }

    if( getpixel(x-13,y+20)==1&&getpixel(x+10,y+20)==1)
      {
	for(y=228;y<=339;y++)
	  {
	    rep_mario(x,y);
	    y+=3;
	    mario(1);
	    if(y>288&&y<293)
	      {
		ipl-=5;
		platform();
	      }
	  }
      }
  }
void level1::jump()
  {
    if(y<325)
	 return;

    char c;
    for( int i=1; i<=6; i++ )
      {
	c=0;
	for( int u=1; u<=20; u++ )
	  {
	    black_vil(mx+3,1);
	    black_vil(mx,0);

	    mx-=3;
	    if( kbhit() )
	      {
		c=getch();
	      }
	    rep_mario( x, y );
	    if( i<=3 )
		 y-=3;
	    else
		 y+=3;

	    if( getpixel(x-10,y-25)==6||getpixel(x+30,y-25)==6)
	      {
		for(int a=15;a>=1;a--)
		  {
		    y+=3;
		    rep_mario(x,y);
		    mario(1);
		  }
		return;
	      }
	    if( getpixel(x-10,y+15)==6||getpixel(x+10,y+15)==6)
	      {
		y+=3;
		y=228;
		mario(1);
		platform();
		return;
	      }

	    if( ((c==77) && (x<300))&& (( getpixel(x+45,y-4)!=6)&&( getpixel(x+25,y+19)!=6)&&( getpixel(x+37,y)!=6)&&(getpixel(x+37,y-10)!=6) &&getpixel(x+25,y-19!=6)&&getpixel(x+33,y+1)!=6))
		  x+=4;
	    else if( (c==75)&&x>=13 )
		  x-=4;
	    mario(1);

	    if( (c==77) && (x>297) )
	      {
		movecloud();
		platform();			    // MOVE ENEMIES
	      }
	    delay(10);
	  }
      }
    maine();
  }
void level1::gameplay()
  {
    char ch=0;
    if(ct==0)
      {
	ch=77;
	delay(50);
      }
    else
	ch=getch();

	if(t!=0)
	return;
    switch( ch )
      {
	case 77:                                    // 77  RIGHT ARROW KEY
	case 75:move_all(ch);               // 75  LEFT ARROW KEY
		break;
	case 72:jump();                       // 72  UP ARROW KEY
		break;
	case 32:if(getpixel(x,y+14)!=1)
		shoot();           // 32  SPACE BAR
		break;
	case 112:a:
		 ch=getch();
		 switch(ch)
		   {
		     case 'p':break;
		     default:goto a;
		   }
		 break;
	case 27:exit(0);
	default:break;
      }
  }
void level1::maine()
  {
    for(mx;mx>=-100;mx=mx-10)
	 badmove();
    mnum--;
    main1();
  }
void level1::movecloud()
  {
    static int ctr=0,xa=300,xb=600,xc=900,y=60;
    ctr++;
    cloudbk( xa, y, 1 );
    cloudbk( xb, y, 1 );
    cloudbk( xc, y, 1 );
    setfillstyle(1,14);
    setcolor(14);
    fillellipse( 400, 50, 40, 40 );
    xa-=2;   xb-=2;   xc-=2;

    draw_cloud( xa, y, 15 );
    draw_cloud( xb, y, 15 );
    draw_cloud( xc, y, 15 );
    if( xc==530 )
      {
	xa=230;
	xb=530;
	xc=830;
      }
  }
void level1::platform()
  {
    static int ipl=0;
    int p[]={640-ipl,240,800-ipl,240,800-ipl,270,640-ipl,270};
    int r[]={1120-ipl,240,1240-ipl,240,1240-ipl,270,1120-ipl,270};
    ipl+=5;
    setcolor(6);
    setfillstyle(6,6);
    fillpoly(4,p);fillpoly(4,r);
    int q[]={800-ipl,240,960-ipl,240,960-ipl,270,800-ipl,270};
    int s[]={1280-ipl,240,1400-ipl,240,1400-ipl,270,1280-ipl,270};
    setcolor(1);
    setfillstyle(1,1);
    fillpoly(4,q);
    fillpoly(4,s);

    if(ipl==800)
	 ipl=320;
  }
void level1::main1()
  {
    if(ct==0)
      {
	x=40;
	init();
	while(x<297)
	     gameplay();
      }
    ct++;

    for(mnum;mnum>=1;mnum--)
      {
	mx=700;
	maine();
      }
    end e1;
    e1.lvl1();
    level2 l2;
    l2.main2();
    closegraph();
  }

//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


//****************************************************************************
// MAIN FUNCTION ( TO CREATE CLASS OBJECTS AND INVOKE MEMBER FUNCTIONS )
//****************************************************************************

void main()
  {
    clrscr();
    int gd=DETECT,gm=DETECT;
    initgraph( &gd, &gm, "c:\\turboc3\\bgi" );
    password pd;
    pd.pass();
    if( check==1 )
      {
	introduction intro;
	intro.gname();
	intro.loadbar();
	menu_background bkgd;
	bkgd.menu_bkgrd();
	bkgd.help();
	bkgd.draw_mario();
	game_menu menu;
	menu.gmenu();
      }
    closegraph();
  }

//****************************************************************************
// FUNCTION TO ACCEPT KEYS TO VIEW MENU AND SELECT A MENU OPTION
//****************************************************************************

void game_menu::gmenu()
  {
    graphdefaults();
    char m1[]="1:   PLAY GAME      ",
	 m2[]="2:   ABOUT GAME     ",
	 m3[]="3:   GAME CONTROLS  ",
	 m4[]="4:   QUIT GAME      ";
    static int ctr=0;
    while(1)
      {
	ctr++;
	choice=1;                                           // DRAW MENU BOXES
	menu_box(1,14);
	menu_box(2,7);
	menu_box(3,7);
	menu_box(4,7);

	settextstyle(1,0,2);                      // DISPLAY MENU IN THE BOXES
	setcolor(4);
	outtextxy( 50, 100, m1 );
	setcolor(15);
	outtextxy( 50, 180, m2 );
	outtextxy( 50, 260, m3 );
	outtextxy( 50, 340, m4 );

	if( ctr==1 )
	  {
	    sound1();
	    sound1();
	    nosound();
	  }

	do                                                      // ACCEPT KEYS
	  {
	    temp=choice;
	    ch=getch();
	    switch( ch )
	      {
		case 72:choice=((--choice+4)%4);         // 72  UP ARROW KEY
			toggle(choice,temp);
			break;
		case 80:choice=(++choice%4);             // 80  DOWN ARROW KEY
			toggle(choice,temp);
			break;
		case 49:choice=1;                        // 49  '1' KEY
			toggle(choice,temp);
			break;
		case 50:choice=2;                        // 50  '2' KEY
			toggle(choice,temp);
			break;
		case 51:choice=3;                        // 51  '3' KEY
			toggle(choice,temp);
			break;
		case 52:choice=4;                        // 52  '4' KEY
			toggle(choice,temp);
			break;
		case 27:choice=4;                        // 27  Escape KEY
			toggle(choice,temp);
		case 13:select_effect(choice);           // 13  Enter KEY
			delay(500);
		default:break;
	      }
	  }
	while( (ch!=13) && (ch!=27) );

	setcolor(1);                                  // CREATE CLOSING EFFECT
	for( i=320; i>=0; i-- )
	  {
	    sound( 3*i );
	    line( 320-i,     0, 320-i,   480 );
	    line( 320+i,     0, 320+i,   480 );
	    line(     0, 320-i,   640, 320-i );
	    line(     0, 160+i,   640, 160+i );
	    delay(3);
	  }
	nosound();
				    // CREATE CLASS OBJECTS AND INVOKE
	if( choice==1 )             // MEMBER FUNCTIONS AS PER SELECTED CHOICE
	  {
	    cleardevice();
	    new_game ng;
	    ng.story();
	    level1 l1;
	    l1.main1();


	    e.congrats();
	  }
	else if( choice==2 )
	  {
	    cleardevice();
	    about_game ab;
	    ab.aboutg();
	  }
	else if( choice==3 )
	  {
	    cleardevice();
	    game_controls gc;
	    gc.gcontrols();
	  }
	else if( (choice==4) || (choice==0) )
	  {
	    cleardevice();
	    e.bye_bye();
	  }

	cleardevice();
	menu_background bkgd;
	bkgd.menu_bkgrd();
	bkgd.help();
	bkgd.draw_mario();
      }
  }

//*********************END****************************************************