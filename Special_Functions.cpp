#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	  	//for exit()
#include<ctype.h>
#include<dos.h>  			//for sleep()
#include<time.h>        //for _strdate(), _strtime(), clock() and clock_t
#include<math.h>        //for pow()
#include<windows.h>     //for Sleep()

   char temp;
   char back;
   int incr;
   int count;  	//storing total no. of accounts
   int j;


   	void delay(long seconds)     	//to make delay function to work
	{
		clock_t time1 = clock();  		// use clock time
   	clock_t time2 = time1 + seconds;

  		while(time1 < time2)
    		time1 = clock();
  		return;
	}


   //for erasing one space back and array address by -1
   inline void delspace(char s=' ')
   {
   	--j;           	//To go back at previous address
   	cout<<'\b';    	//Moves back the character
      cout<<s;     		//Displays blank there
      cout<<'\b';    	//Moves back the character again
   }


   //for entering password
   void enterPASS(char pass[], int x, int y, int _colour=15)
   {
      gotoxy(x,y);
      strcpy(pass,"\0");
      textcolor(_colour);

   	j=0;
      for(; ;)
      {
         char temp;       	//for storing input temporarily
         temp=getch();

         if(temp==13)    	//Checking whether "Enter" have been entered or not
         {
            if(pass[0]=='\0')
            {
            	cout<<'\a';
               continue;
            }
            else
           		break;
         }

         if(j==5)             //don't let the user to enter more than
         {                    //the desired characters
            if(temp=='\b')
        		{
              	delspace('-');
              	continue;
           	}

            cout<<'\a';
            continue;
         }
         else if(temp=='\b')
         {
            if(j==0)         //don't let 'j' to go beyond 0
            {
              	cout<<'\a';
               pass[0]='\0';
              	continue;
            }
            else
            {
               delspace('-');    //--j is performed by delspace()
           		continue;
         	}
         }
         else
         {
            pass[j]=temp;       //storing in string character
            ++j;
         	cputs("*");
         }
      }
      pass[j]='\0';    //Terminating string
   }





   	int Security_check()		//for entering password at opening
	{
      fstream f("Password.dat", ios::in);

      int i;
      int count=1;            //Variable to check no. of chances
      char pword[15];
      char pwd[15];
      f>>pwd;

      for(i=0; i<3; ++i)     //Giving user only 3 chances to enter password
      {
         clrscr();

      	int j;
			char c1=201, c2=187;
   		char c3=205, c4=186;
   		char c5=200, c6=188;

  			gotoxy(3,2);   cout<<c1;
   		for(j=0; j<94; ++j)
   			cout<<c3;
   		cout<<c2;

   		for(j=3; j<=43; ++j)
      	{
      		gotoxy(3,j);   cout<<c4;
        		gotoxy(98,j); 	cout<<c4;
      	}

   		gotoxy(3,44);	cout<<c5;
   		for(j=0; j<94; ++j)
   			cout<<c3;
   		cout<<c6;

   		gotoxy(5,3);	cout<<(char)175;
   		gotoxy(96,3);	cout<<(char)174;
   		gotoxy(5,43);	cout<<(char)175;
   		gotoxy(96,43);	cout<<(char)174;

   		char d1=218, d2=191;
   		char d3=196, d4=179;
   		char d5=192, d6=217;

   		gotoxy(36,17);
  			cout<<d1;
   		for(j=1; j<=28; ++j)
   			cout<<d3;
   		cout<<d2;
   		for(j=18; j<=25; ++j)
   		{
        		gotoxy(36,j);	 cout<<d4;
        		gotoxy(65,j);   cout<<d4;
      	}

   		gotoxy(36,26);
   		cout<<d5;
   		for(j=1; j<=28; ++j)
   			cout<<d3;
   		cout<<d6;

   		gotoxy(42,20);   textcolor(3);   cputs("Username : ");
      	gotoxy(42,23);   					   cputs("Password : ");

     	 	gotoxy(53,20);	  textcolor(14);
      	char temp[5]="admin";
      	Sleep(1500);

      	for(int j=0; j<5; ++j)
      	{
      		putch(temp[j]);
        		Sleep(150);
      	}

      	Sleep(350);
      	gotoxy(53,23); 	cputs("-----");


      	enterPASS(pword,53,23,14);

      	if(!strcmp(pword,pwd))
      	{
         	gotoxy(43,30);   textcolor(6);	cputs("ACCESS GRANTED!");
         	getch();
        		break;
      	}
      	else
      	{
         	gotoxy(44,30);	  textcolor(12);	 cputs("ACCESS DENIED!");
         	gotoxy(40,33);   cout<<(3-count)<<" chance(s) are left...";
         	count++;
         	getch();
         	continue;
      	}
   	}
      f.close();


      if(i==3)       //if all chances ran out
      	return 0;
      else
      	return 1;

      //if 'i=3', it means the 3 turns have been utilised
   }




   	int AccountPWD(int change = 0)		//asks for password
	{
      fstream fin("Password.dat", ios::in);

      clrscr();
      char pword[10]="\0";
      char pwd[10];

      fin>>pwd;

      if(change==0)
      {
         gotoxy(39,20);		textcolor(14);
      	cputs("Enter Password : ");	  textcolor(15);   cputs("-----");
      }
      else
      {
      	gotoxy(35,20);    textcolor(14);
         cputs("Enter Old Password : ");	 textcolor(15);   cputs("-----");
      }

      enterPASS(pword,56,20);

      if(!fin)
      	return 0;

      fin.close();

      if(!strcmp(pword,pwd))
        	return 1;
      else
        	return 0;
   }




      //enters string character - words, numbers, and bank pin (****) also

   	void EnterWD(char p[], int x, int y, int limit, char s='-', char dig_wd='w')
	{
      gotoxy(x,y);
      j=0;
      strcpy(p,"\0");

      for(; ;)
      {
         char temp;
         temp=getch();

         if(temp==13)    		//Checking whether "Enter" have been entered or not
         {
            if(p[0]=='\0')
            	cout<<'\a';
            else
           		break;
         }
         else if(j==limit)    //cheking string limit
         {
            if(temp=='\b')
        		{
               delspace(s);
              	continue;
           	}

            cout<<'\a';
            continue;
         }
         else if(temp=='\b')
         {
            if(j==0)         //don't let 'j' to go beyond 0
            {
              	cout<<'\a';
               p[0]='\0';
              	continue;
            }
            else
            {
              	delspace(s);
           		continue;
         	}
         }
         else
         {
            if(dig_wd=='n')
            {
               p[j]=temp;
              	if(isdigit(temp))
               {
                  if(p[0]=='0' && limit==10)   //0 not allowed at first position
            			{
            				cout<<'\a';
               			continue;
            			}

                  if(limit==4)
            			cout<<"*";
            		else
            			cout<<temp;
                  ++j;
               }
               else
               	cout<<'\a';
            }
            else
            {
               p[j]=temp;       			//storing in string character

               if(j==0)
               	p[0]=toupper(p[0]);

               if(p[j-1]==' ')
               	p[j]=toupper(p[j]);

               cout<<p[j];

               ++j;
            }
         }
      }
   		p[j]='\0';    //Terminating string
   }




	//calculates the centre of the width of screen for the received string
		void GotoXY(char str[],int y,int s1,int s2=0,int s3=0,int s4=0,int s5=0)
	{
   	int tot_size = strlen(str) + s1 + s2 + s3 + s4 + s5;
   	int x = 50 - tot_size/2;
   	gotoxy(x,y);
	}	




		void Starting_up()		//Design for program start up and loading
	{
   	char b=205;

   	_setcursortype(_NOCURSOR);
   	textcolor(14);

   	//For c
   	gotoxy(36,15);			 cputs(".d88888888b,");      delay(50);
   	gotoxy(35,16);   	   cputs("d8PP88888888b,");     delay(50);
   	gotoxy(34,17);  	  cputs("d8888P'");             delay(50);
   	gotoxy(33,18);     cputs("d8888P'");              delay(50);
   	gotoxy(32,19);    cputs(":88888");                delay(50);
   	gotoxy(32,20);    cputs(".d8888");                delay(50);
   	gotoxy(33,21);     cputs("d888B,");               delay(50);
   	gotoxy(34,22);      cputs("d8888b,");             delay(50);
   	gotoxy(35,23);       cputs("Y88888888888P");      delay(50);
   	gotoxy(36,24);        cputs("\"d8bbd888P'");      delay(50);
   	gotoxy(48,22);		  cputs(",");

   	textcolor(10);
   	//For b
   	gotoxy(50,7);        cputs("88888");     delay(50);
   	gotoxy(50,8);        cputs("88888");     delay(50);
   	gotoxy(50,9);        cputs("88888");     delay(50);
   	gotoxy(50,10);       cputs("88888");     delay(50);
   	gotoxy(50,11);       cputs("88888");     delay(50);
   	gotoxy(50,12);       cputs("88888");     delay(50);
   	gotoxy(50,13);       cputs("88888");     delay(50);
   	gotoxy(50,14);       cputs("88888");     delay(50);
   	gotoxy(50,15);       cputs("88888");     delay(50);
   	gotoxy(50,16);       cputs("88888");     delay(50);
   	gotoxy(50,17);       cputs("88888");     delay(50);
   	gotoxy(50,18);       cputs("88888");     delay(50);
   	gotoxy(50,19);       cputs("88888");     delay(50);
   	gotoxy(50,20);       cputs("88888");     delay(50);
   	gotoxy(50,21);       cputs("88888");     delay(50);
   	gotoxy(50,22);       cputs("88888");     delay(50);
   	gotoxy(50,23);       cputs("\"888");     delay(50);
   	gotoxy(50,24);       cputs(" \"\"");     delay(50);

   	gotoxy(53,24);       cputs("Y88888888P\"");     delay(50);
   	gotoxy(54,23);       cputs("88d88888888\"");    delay(50);
   	gotoxy(60,22);       cputs(",d888b");           delay(50);
   	gotoxy(62,21);       cputs("d8888'");           delay(50);
   	gotoxy(63,20);       cputs("8888b.");           delay(50);
   	gotoxy(63,19);       cputs("88888:");           delay(50);
   	gotoxy(62,18);       cputs("'88888");           delay(50);
   	gotoxy(61,17);       cputs("\"M8888b");         delay(50);
   	gotoxy(56,16);       cputs(",d88888PP8b");      delay(50);
   	gotoxy(58,15);       cputs(",d8888b.");         delay(50);

   	gotoxy(1,28);
   	for(int i=1,j=95; i<=46,j>=52; ++i,--j)	//design for moving string
   	{
   		textcolor(14);		gotoxy(i,28);		cputs("CENTRAL ");
      	textcolor(10);    gotoxy(j,28);		cputs("BANK");

      	gotoxy(i-1,28);   cout<<' ';
      	gotoxy(j+4,28);   cout<<' ';
      	delay(16);
   	}


   	delay(2000);

   	gotoxy(36,33);		cout<<char(201);
   	gotoxy(36,34);    cout<<char(186);
   	gotoxy(36,35);		cout<<char(200);


   	for(int i=1, j=37; i<=28; ++i, ++j)
   	{
   		gotoxy(j,33);
   		cout<<b;
   		gotoxy(j,35);
   		cout<<b;
   	}

   	int x=wherex();
   	gotoxy(x,33);		cout<<char(187);
   	gotoxy(x,34);     cout<<char(186);
   	gotoxy(x,35);		cout<<char(188);

   	textcolor(12);
   	gotoxy(43,37);		cputs("---- Loading ----");
   	delay(1800);

   	for(int i=1; i<=6; ++i)
    		for(int z=38; z<=60; ++z)
      	{
       		gotoxy(z,34);	  textcolor(12);	  cputs("||||");
         	delay(65);

         	for(int j=1; j<=5; ++j)
         		cout<<'\b'<<' '<<'\b';
      	}
   	delay(900);
   	gotoxy(43,37);		delline();
   	gotoxy(36,35);		delline();
   	gotoxy(36,34);		delline();
   	gotoxy(36,33);		delline();

   	delay(2000);
   	clrscr();
	}


   	void Welcome()      //Design for Welcome screen
	{
   	randomize();
   	int j=10;
  	 	_setcursortype(_NOCURSOR);

   	for(int i=1; i<=5; ++i)
     {
      textcolor(j++);
   	gotoxy(11,18);		Sleep(120);
		cputs("    _/      _/   _/_/_/_/   _/        _/_/_/_/   _/_/_/_/   _/_/  _/_/   _/_/_/_/");
   	gotoxy(11,19);    Sleep(120);
   	cputs("   _/      _/   _/         _/        _/         _/    _/   _/ _/_/ _/   _/");
   	gotoxy(11,20);    Sleep(120);
   	cputs("  _/  _/  _/   _/_/_/     _/        _/         _/    _/   _/  _/  _/   _/_/_/");
   	gotoxy(11,21);    Sleep(120);
   	cputs(" _/ _/_/ _/   _/         _/        _/         _/    _/   _/      _/   _/");
   	gotoxy(11,22);    Sleep(120);
   	cputs("_/_/  _/_/   _/_/_/_/   _/_/_/_/  _/_/_/_/   _/_/_/_/   _/      _/   _/_/_/_/");
      Sleep(800);

      if(j==15)
      	j=10;
     }
   	Sleep(1500);
	}

   	void Bouncing()      //Design for Screen-saver
	{
      randomize();
      _setcursortype(_NOCURSOR);

      int i=1,j=1,x=(random(65-1+1)+1),y=(random(36-9+1)+9);
      Sleep(2000);

      while(!kbhit())
      {
         clrscr();
			textcolor(14);

  			//For c
         gotoxy(x+4,y);			 cputs(".d88888888b,");
 			gotoxy(x+3,y+1);   	   cputs("d8PP88888888b,");
  			gotoxy(x+2,y+2);  	  cputs("d8888P'");
      	gotoxy(x+1,y+3);     cputs("d8888P'");
      	gotoxy(x,y+4);    cputs(":88888");
			gotoxy(x,y+5);    cputs(".d8888");
			gotoxy(x+1,y+6);     cputs("d888B,");
			gotoxy(x+2,y+7);      cputs("d8888b,");
   		gotoxy(x+3,y+8);       cputs("Y88888888888P");
   		gotoxy(x+4,y+9);        cputs("\"d8bbd888P'");
   		gotoxy(x+16,y+7);		cputs(",");

   		textcolor(10);
   		//For b
   		gotoxy(x+18,y-8);        cputs("88888");
   		gotoxy(x+18,y-7);        cputs("88888");
   		gotoxy(x+18,y-6);        cputs("88888");
   		gotoxy(x+18,y-5);       cputs("88888");
   		gotoxy(x+18,y-4);       cputs("88888");
   		gotoxy(x+18,y-3);       cputs("88888");
   		gotoxy(x+18,y-2);       cputs("88888");
   		gotoxy(x+18,y-1);       cputs("88888");
         gotoxy(x+18,y);       cputs("88888");
   		gotoxy(x+18,y+1);       cputs("88888");
   		gotoxy(x+18,y+2);       cputs("88888");
   		gotoxy(x+18,y+3);       cputs("88888");
	 	  	gotoxy(x+18,y+4);       cputs("88888");
   		gotoxy(x+18,y+5);       cputs("88888");
   		gotoxy(x+18,y+6);       cputs("88888");
   		gotoxy(x+18,y+7);       cputs("88888");
   		gotoxy(x+18,y+8);       cputs("\"888");
   		gotoxy(x+18,y+9);       cputs(" \"\"");

   		gotoxy(x+21,y+9);       cputs("Y88888888P\"");
   		gotoxy(x+22,y+8);       cputs("88d88888888\"");
   		gotoxy(x+28,y+7);       cputs(",d888b");
   		gotoxy(x+30,y+6);       cputs("d8888'");
   		gotoxy(x+31,y+5);       cputs("8888b.");
   		gotoxy(x+31,y+4);       cputs("88888:");
   		gotoxy(x+30,y+3);       cputs("'88888");
   		gotoxy(x+29,y+2);       cputs("\"M8888b");
   		gotoxy(x+24,y+1);       cputs(",d88888PP8b");
   		gotoxy(x+26,y);       cputs(",d8888b.");

         if(i==1)    x++;

         if(x==65)   i=2;

         if(x==1)    i=1;

         if(i==2)    x--;

         if(j==1)    y++;

         if(y==36)   j=2;

         if(y==9)    j=1;

         if(j==2)    y--;

			Sleep(50);
      }
	}



   	void Processing()       //Design showing Processing
	{
      clrscr();
   	char a=219, b=196, c=179;

   	gotoxy(24,20);
   	cout<<c;


   	for(int i=0, j=25; i<=50; ++i, ++j)
   	{
   		gotoxy(j,19);
   		cout<<b;
   		gotoxy(j,21);
   		cout<<b;
   	}

   	gotoxy(wherex(),wherey()-1);
   	cout<<c;

		gotoxy(44,23); 	textcolor(9);
   	cputs("Processing....");
   	gotoxy(26,20);

   	for(int i=0; i<=48; i++)
   	{
      	cout<<a;
   		delay(90);
  	 	}
   	gotoxy(57,23);
	}



   //Design showing refreshing - moving dots in circle
   	void Refreshing(int TM, char head[]="Refreshing")
   {
     clrscr();
     char o=248;
     gotoxy(46,15);
     cout<<head;
     for(int j=1; j<=TM; ++j)
     		for(int i=1; i<=10; ++i)
     		{
         	gotoxy(49,24);		cout<<o;
      		gotoxy(47,23);		cout<<o;
      		gotoxy(46,21);		cout<<o;
      		gotoxy(47,19);		cout<<o;
      		gotoxy(49,18);		cout<<o;
      		gotoxy(52,18);		cout<<o;
      		gotoxy(54,19);		cout<<o;
      		gotoxy(55,21);		cout<<o;
      		gotoxy(54,23);		cout<<o;
            gotoxy(52,24);		cout<<o;

            switch(i)
            {
            	case 1 :  gotoxy(49,24);		cout<<' ';
      						 gotoxy(47,23);		cout<<' ';
                         gotoxy(46,21);		cout<<' ';
                         delay(130);
                         break;
      			case 2 :  gotoxy(47,23);		cout<<' ';
               			 gotoxy(46,21);		cout<<' ';
                         gotoxy(47,19);		cout<<' ';
                         delay(130);
                         break;
      			case 3 :  gotoxy(46,21);		cout<<' ';
               			 gotoxy(47,19);		cout<<' ';
                         gotoxy(49,18);		cout<<' ';
                         delay(130);
                         break;
               case 4 :  gotoxy(47,19);		cout<<' ';
				         	 gotoxy(49,18);		cout<<' ';
                         gotoxy(52,18);		cout<<' ';
                         delay(130);
                         break;
      			case 5 :  gotoxy(49,18);		cout<<' ';
               			 gotoxy(52,18);		cout<<' ';
                         gotoxy(54,19);		cout<<' ';
                         delay(130);
                         break;
               case 6 :  gotoxy(52,18);		cout<<' ';
       						 gotoxy(54,19);		cout<<' ';
                         gotoxy(55,21);		cout<<' ';
                         delay(130);
                         break;
               case 7 :  gotoxy(54,19);		cout<<' ';
      					    gotoxy(55,21);		cout<<' ';
                         gotoxy(54,23);		cout<<' ';
                         delay(130);
                         break;
               case 8 :  gotoxy(55,21);		cout<<' ';
      						 gotoxy(54,23);		cout<<' ';
                         gotoxy(52,24);		cout<<' ';
                         delay(130);
                         break;
               case 9 : gotoxy(54,23);		cout<<' ';
            				 gotoxy(52,24);		cout<<' ';
                         gotoxy(49,24);		cout<<' ';
                         delay(130);
                         break;
               case 10 : gotoxy(52,24);		cout<<' ';
                         gotoxy(49,24);		cout<<' ';
                         gotoxy(47,23);		cout<<' ';
                         delay(130);
                         break;
            }
      	}
      delay(150);
      clrscr();
   }


     

   	void CB_Design()     //Design for BANK logo
	{
   	int x;
   	textcolor(14);

   	//Desing for C
   	x=17;
   	gotoxy(x,1);    cputs("  ___");
   	gotoxy(x,2);    cputs(" / __|");
   	gotoxy(x,3);    cputs("| |");
   	gotoxy(x,4);    cputs("| |__");
   	gotoxy(x,5);    cputs(" \\___|");

		//Design for e
 		x=wherex();
 		gotoxy(x,2);  	cputs("  ___");
 		gotoxy(x,3);   cputs(" / _ \\");
 		gotoxy(x,4);	cputs("|  __/");
 		gotoxy(x,5);	cputs(" \\___|");

 		//Design for n
 		x=wherex();
 		gotoxy(x,2);  cputs(" _ __");
 		gotoxy(x,3);  cputs("| '_ \\");
 		gotoxy(x,4);  cputs("| | | |");
 		gotoxy(x,5);  cputs("|_| |_|");

 		//Design for t
 		x=wherex();
 		gotoxy(x,1);   cputs(" _ ");
 		gotoxy(x,2);	cputs("| |_");
 		gotoxy(x,3);   cputs("| __|");
 		gotoxy(x,4);	cputs("\\ |_");
 		gotoxy(x,5);   cputs(" \\__|");

 		//Design for r
 		x=wherex();
 		gotoxy(x,2);  cputs(" _ _");
 		gotoxy(x,3);  cputs("| '_|");
 		gotoxy(x,4);  cputs("| |");
 		gotoxy(x,5);  cputs("|_|");

   	//Design for a
 		x=wherex()+2;
 		gotoxy(x,2);  cputs("  ___");
 		gotoxy(x,3);  cputs(" /   |");
 		gotoxy(x,4);  cputs("| <| |");
 		gotoxy(x,5);  cputs(" \\_,_|");

 		//Disgn for l;
 		x=wherex();
 		gotoxy(x,1);	cputs(" _ ");
 		gotoxy(x,2);   cputs("| |");
 		gotoxy(x,3);   cputs("| |");
 		gotoxy(x,4);   cputs("| |_");
 		gotoxy(x,5);   cputs(" \\__|");

 		//Design for B;
 		x=wherex()+3;
		gotoxy(x,1);  cputs(" ____");
 		gotoxy(x,2);  cputs("|    \\");
 		gotoxy(x,3);  cputs("| |> /");
 		gotoxy(x,4);  cputs("| |> \\");
		gotoxy(x,5);  cputs("|____/");

 		//Design for a
 		x=wherex();
 		gotoxy(x,2);  cputs("  ___");
 		gotoxy(x,3);  cputs(" /   |");
 		gotoxy(x,4);  cputs("| <| |");
 		gotoxy(x,5);  cputs(" \\_,_|");

 		//Design for n
 		x=wherex();
 		gotoxy(x,2);  cputs(" _ __");
 		gotoxy(x,3);  cputs("| '_ \\");
 		gotoxy(x,4);  cputs("| | | |");
 		gotoxy(x,5);  cputs("|_| |_|");

 		//Design for K
 		x=wherex();
 		gotoxy(x,1);  cputs(" _  _");
 		gotoxy(x,2);  cputs("| |/ |");
 		gotoxy(x,3);  cputs("|   /");
 		gotoxy(x,4);  cputs("|   \\");
 		gotoxy(x,5);  cputs("|_|\\_|");

   	textcolor(15);
   }




   	void box(int x1, int x2, int y1, int y2)
	{
		char a=201, b=187, c=200, d=188;
   	char m=205, n=186;

   	gotoxy(x1,y1);		cout<<a;
   	gotoxy(x2,y1);    cout<<b;
   	gotoxy(x1,y2);		cout<<c;
   	gotoxy(x2,y2);		cout<<d;

   	for(int i=x1+1; i<=x2-1; i++)
   	{
      	gotoxy(i,y1);  	cout<<m;
      	gotoxy(i,y2);		cout<<m;
   	}

   	for(int j=y1+1; j<=y2-1; ++j)
   	{
   		gotoxy(x1,j);		cout<<n;
      	gotoxy(x2,j);     cout<<n;
   	}

   	for(int l=y1+1; l<=y2-1; ++l)
   		for(int k=x1+1; k<=x2-1; ++k)
   		{
   			gotoxy(k,l);
         	textbackground(2);
         	cputs(" ");
     		}
	}



   int quit()      ////Design asking for termination
{
   clrscr();
   CB_Design();

   int arrow;
   int quit;

   for(int p=39,q=62,r=21,s=23; p>=34,q>=67,r>=16,s<=28; p-=2,q+=2,r-=2,s+=2)
   {
   	box(p,q,r,s);
      delay(28);
   }

   gotoxy(36,18);
   for(int i=0; i<11; ++i)
   	cputs("=");
   cputs(" NOTICE ");
   for(int i=0; i<11; ++i)
   	cputs("=");

   gotoxy(38,20);		cputs("Are you sure want to quit?");

   gotoxy(43,23);		cputs("      QUIT      ");
   textbackground(1);
   gotoxy(43,25);		cputs("     CANCEL     ");

   arrow = getch();


   for(;;)
   {
   	arrow = getch();

      if(arrow==13)
      {
        	if(wherey()==23)
           	quit=1;
         else
         	quit=0;

         break;
      }


      if(arrow==72)
      {
      	textbackground(2);
   		gotoxy(43,25);		cputs("     CANCEL     ");
         textbackground(1);
         gotoxy(43,23);		cputs("      QUIT      ");
      }

      if(arrow==80)
      {
      	textbackground(2);
         gotoxy(43,23);		cputs("      QUIT      ");
   		textbackground(1);
   		gotoxy(43,25);		cputs("     CANCEL     ");
      }
	}

   return quit;
}


   //for searching in DispSummary() - moving ':' with arrows (up - down)
	int search(int pos)
{
   int arrow, y=pos;

   if(45-pos>=10)
   {
      y=37;
   	gotoxy(39, y);     textcolor(3);	         cputs("<----<<< SEARCH >>>---->");
   	gotoxy(40, y+5);	 textcolor(7);	         cputs("Bank PIN     ----");
   	gotoxy(40, y+3);	 cputs("Name      ");   textcolor(11);    cputs(":");
   	gotoxy(wherex()+2, wherey());
   }
   else
   {
   	gotoxy(44, y+5);    textcolor(3);	      cputs("((( SEARCH )))");
   	gotoxy(40, y+10);	  textcolor(7);	      cputs("Bank PIN     ----");
   	gotoxy(40, y+8);	  cputs("Name      ");  textcolor(11);    cputs(":");
   	gotoxy(wherex()+2, wherey());
   }

	for(;;)
   {
   	arrow = getch();                      

      if(arrow==13)
         return wherey();

      if(arrow==27)
      	return 0;

      if(arrow==72)
      {
      	if(y==37)
         {
         	gotoxy(50,y+5);	  cout<<" ";
         	gotoxy(50,y+3);	  cputs(":  ");
         }
         else
         {
         	gotoxy(50,y+10);	  cout<<" ";
         	gotoxy(50,y+8);	  cputs(":  ");
         }
      }

      if(arrow==80)
      {
      	if(y==37)
         {
         	gotoxy(50,y+3);		cout<<" ";
         	gotoxy(50,y+5);		cputs(":  ");
         }
         else
         {
         	gotoxy(50,y+8);		cout<<" ";
         	gotoxy(50,y+10);		cputs(":  ");
         }
      }
	}
}



   //let you chose only numbers b/w 1-9 and options - (y/n)
   char OPTION(char wd_num, char num_lim='9')
	{
   	char opt;

      for(; ;)
      {
         AGAIN :
      	opt=getch();

         if(wd_num=='w')         //checking if option is for y/n
         {
      		if(isalpha(opt))
      		{
       			if(opt=='y'||opt=='Y'||opt=='n'||opt=='N')
               {
               	cout<<opt;
                  break;
               }
            	else
            		cout<<'\a';
         	}
            else
            	cout<<'\a';
         }


         if(wd_num=='n')       //checking if option is for numbers
         {
         	if(isdigit(opt))
      		{
       			if(opt>='1' && opt<=num_lim)
               {
               	cout<<opt;
                  break;
               }
            	else
            		cout<<'\a';
         	}
            else
            	cout<<'\a';
      	}
      }


      for(; ;)               		//checking enter and backspace
      {
         char enter_bs;
         enter_bs=getch();
         if(enter_bs==13)     	//finalising input
            break;
         else if(enter_bs=='\b')
         {
         	cout<<'\b'<<' '<<'\b';
            goto AGAIN;
         }
         else
          	cout<<'\a';   			//if 'enter' not entered
      }

      return opt;
	}




   void GoBack()           //Function for going back from a window option
   {
      _setcursortype(_NOCURSOR);
   	do
      {
         clrscr();
         gotoxy(30,20);    textcolor(14);
         cputs("Press ");	textcolor(12);	 cputs("'ESC'");	textcolor(14);
         cputs(" to go back or ");   textcolor(12);   cputs("'ENTER'");
         textcolor(14);    cputs(" to continue");
      	back=getch();
         if(back!=27 && back!=13)
         	cout<<'\a';
      }while(back!=27 && back!=13);

      _setcursortype(_NORMALCURSOR);
   }



   //Displays and asks for confirmation and retry
   char Sure_Retry(int x, int y, char chk, char acc='a')
	{
      char s;
      gotoxy(x,y);    textcolor(2);
      if(chk=='s')
       	cputs("Enter < y/n > to confirm : ");
      else
      {
         textcolor(3);
         if(acc=='m')
         {
            getch();
         	cputs("Add more Customer < y/n > : ");
         }
         else
      		cputs("Want to Retry < y/n > : ");
      }

      s=OPTION('w');

      return s;
	}



   char MENUwindow()			//Design for Main MENU
	{
      clrscr();
      CB_Design();

      char c1=201, c2=187;
   	char c3=205, c4=186;
   	char c5=200, c6=188;

   	gotoxy(40,10);
      cout<<c1;
      for(int i=0; i<20; ++i)
      	cout<<c3;
      cout<<c2;

      gotoxy(40,11);
      	cout<<c4;
      gotoxy(61,11);
      	cout<<c4;

      gotoxy(40,12);
      cout<<c5;
      for(int i=0; i<20; ++i)
      	cout<<c3;
      cout<<c6;

      gotoxy(49,11);
      textcolor(12);
   	cputs("MENU");

      gotoxy(43,11);
      cout<<char(175);
      gotoxy(58,11);
      cout<<char(174);

   	gotoxy(42,14);	 textcolor(13);  cputs("1");  textcolor(14);  cputs(".");
      textcolor(10);	 cputs(" CREATE ACCOUNT");
   	gotoxy(42,16);	 textcolor(13);  cputs("2");  textcolor(14);  cputs(".");
      textcolor(10);	 cputs(" DEPOSIT");
   	gotoxy(42,18);	 textcolor(13);  cputs("3");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" WITHDRAW");
   	gotoxy(42,20);	 textcolor(13);  cputs("4");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" BALANCE QUERY");
   	gotoxy(42,22);	 textcolor(13);  cputs("5");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" ACCOUNT'S LIST");
   	gotoxy(42,24);	 textcolor(13);  cputs("6");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" MODIFY ACCOUNT");
   	gotoxy(42,26);	 textcolor(13);  cputs("7");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" CLOSE ACCOUNT");
   	gotoxy(42,28);	 textcolor(13);  cputs("8");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" CHANGE PASSWORD");
   	gotoxy(42,30);	 textcolor(13);  cputs("9");  textcolor(14);  cputs(".");
      textcolor(10);  cputs(" QUIT");

      gotoxy(42,35);	 textcolor(3);
      cputs("Enter your choice: ");

      char temp=OPTION('n');

   	return temp;
	}




   void enterNUM(char n[], int limit)		//for entering numbers only
   {
  		j=0;
      strcpy(n,"\0");

      for(; ;)
      {
         temp=getch();

         if(temp==13)    	//Checking whether "Enter" have been entered or not
         {
         	if(n[0]=='\0' || n[0]=='0')
           		cout<<'\a';
            else
               break;
       	}
         else if(j==limit)    //checking string character limit
         {
            if(temp=='\b')
        		{
               delspace();
              	continue;
           	}

            cout<<'\a';
            continue;
         }
         else if(temp=='\b')
         {
         	if(j==0)         //don't let 'j' to go beyond 0
           	{
           		cout<<'\a';
               n[0]='\0';
             	continue;
            }
            else
            {
               delspace();
           		continue;
            }
         }
         else if(isdigit(temp))
         {
            n[j]=temp;       //storing in string character
            if(n[0]=='0')    //0 not allowed at first position
            {
            	cout<<'\a';
               continue;
            }

            cout<<temp;
            ++j;
         }
         else
         	cout<<'\a';
      }
      n[j]='\0';    //Terminating string
   }




   	void EnterPIN(char pin[])		//displays and enter bank pin
   {
      clrscr();

   	gotoxy(40,20);		textcolor(14);
      cputs("Enter Bank PIN : ");   textcolor(15);	  cputs("----");
      EnterWD(pin,57,20,4,'-','n');
   }




      void Accfunc(char c[], int q)		//displays input account-type
   {
   	gotoxy(77,34);		textcolor(2);
      cputs("~~~~~~~~~~~~~~~~");
      gotoxy(80,36);		textcolor(10);
      cputs("1. Current");
      gotoxy(80,37);
      cputs("2. Savings");
      gotoxy(80,39);
      cputs("Option :");
      gotoxy(77,41);    textcolor(2);
      cputs("~~~~~~~~~~~~~~~~");

      char temp;

      gotoxy(89,39);
      temp=OPTION('n','2');

      if(temp=='1')
         strcpy(c,"Current");
      else
         strcpy(c,"Savings");


      for(int m=1; m<=8; ++m)
      {
         	gotoxy(77,34);
            delline();
      }

      gotoxy(39,q);
   }


      //Displays and enters address
   	void ADDress(char h[], char l[], char c[], char s[], char p[], int y)
   {
   	gotoxy(60,33);   textcolor(2);	cputs("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(61,35);   textcolor(10);	cputs("House No.     : ");	 cout<<"----------";
   	gotoxy(61,36);   						cputs("Locality      : ");  cout<<"---------------";
   	gotoxy(61,37);   						cputs("City/District : ");	 cout<<"--------------------";
      gotoxy(61,38);   						cputs("State         : ");  cout<<"--------------------";
      gotoxy(61,39);	  						cputs("Pincode       : ");	 cout<<"------";
   	gotoxy(60,41);	  textcolor(2);	cputs("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

      EnterWD(h,77,35,10);
      EnterWD(l,77,36,15);
      EnterWD(c,77,37,20);
      EnterWD(s,77,38,20);
      EnterWD(p,77,39,6,'-','n');


      for(int x=1; x<=9; ++x)
      {
       	gotoxy(60,33);
         delline();
      }

      gotoxy(39,y);
   }


   //converts numbers in string to double value
      double convert_str_to_int(char n[])
	{
	int pvalue=strlen(n)-1;
   int i=0;
   double number=0;

   while(n[i]!='\0' && pvalue>=0)
   {
      double expand;
   	int digit;
      digit=n[i]-48;
      expand=digit*pow(10,pvalue);
      number+=expand;
      --pvalue;
      ++i;
   }
   return number;
}



      //to input date of birth
      void enterDOB(char dmy[], int limit, int what, int dd_num=1, int Feb=28)
   {
      //dd_num to check the no. of dates in a month
      //Feb to check whether the month of Feb is 28 or 29
      
  		j=0;
      strcpy(dmy,"\0");

      for(; ;)
      {
         temp=getch();

         if(temp==13)    	//Checking whether "Enter" have been entered or not
         {
         	if(dmy[0]=='\0' || j!=limit)
           		cout<<'\a';
            else
               break;
       	}
         else if(j==limit)
         {
            if(temp=='\b')
        		{
               delspace('-');
              	continue;
           	}

            cout<<'\a';
            continue;
         }
         else if(temp=='\b')
         {
         	if(j==0)         //don't let 'j' to go beyond 0
           	{
           		cout<<'\a';
               dmy[0]='\0';
             	continue;
            }
            else
            {
               delspace('-');
           		continue;
            }
         }
         else if(isdigit(temp))
         {
            if(what==1)        //for year
            {
            	if(j==0)               //only 1 and 2 allowed at 1st pos.
               {
               	if(temp=='1' || temp=='2')
                  	cout<<temp;
                  else
                  {
                  	cout<<'\a';
               		continue;
               	}
               }
               else if(j==1)
               {
               	if(dmy[0]=='1')
                  {
                     if(temp=='9')     //only 9 at 2nd pos. if 1st value is 1
                  		cout<<temp;
                     else
                     {
                     	cout<<'\a';
               			continue;
                     }
                  }
                  else
                  {
                  	if(temp=='0')     //only 0 at 2nd pos. if 1st value is 2
                     	cout<<temp;
                     else
                     {
                     	cout<<'\a';
                        continue;
                     }
                  }
               }
               else if(j==2)       //only 0 and 1 at 3rd pos. if 2 is 1st value
               {
               	if(dmy[0]=='2')
                  {
                  	if(temp=='1' || temp=='0')
                     	cout<<temp;
                     else
                     {
                     	cout<<'\a';
                        continue;
                     }
                  }
                  else
                  	cout<<temp;    //otherwise any no.
               }
               else
               {
                  if(dmy[0]=='2')     //only 0-4 at 4th pos. if 2 is 1st value
                  {
                  	if(temp>='0' && temp<='4')
                     	cout<<temp;
                     else
                     {
                     	cout<<'\a';
                        continue;
                     }
                  }
                  else
                  	cout<<temp;     //otherwise any no.
               }
            }
            else if(what==2)     //for month
            {
            	if(j==0)          //only 0 and 1 at 1st pos.
               {
            		if(temp=='0' || temp=='1')
                  	cout<<temp;
               	else
                  {
                  	cout<<'\a';
               		continue;
               	}
               }
               else             //for j=1
               {
                  if(dmy[0]=='1') 	//only 0-2 at 2nd pos. if 1st value is 1
               	{
                     if(temp>='0' && temp<='2')
                  		cout<<temp;
                     else
                     {
                     	cout<<'\a';
               			continue;
                     }
                  }
               	else            //if 1st value is 0, then 1-9 at 2nd pos.
                  {
                  	if(temp>='1' && temp<='9')
                  		cout<<temp;
                     else
                     {
                     	cout<<'\a';
               			continue;
                     }
                  }
               }
            }
            else               //for date
            {
            	if(dd_num==1)      //the month is of 31 days
               {
                	if(j==0)        //only 0-3 at 1st pos.
               	{
            			if(temp>='0' && temp<='3')
                  		cout<<temp;
               		else
                  	{
                  		cout<<'\a';
               			continue;
               		}
               	}
                  else
                  {
                  	if(dmy[0]=='3')   //only 0 and 1 at 2nd pos if 3 is 1st value
                     {
                        if(temp=='0' || temp=='1')
                  			cout<<temp;
                     	else
                     	{
                     		cout<<'\a';
               				continue;
                     	}
                     }
                     else
                     {
                        if(dmy[0]=='0')   //only 1-9 at 2nd pos. if 1st value is 0
                        {
                     		if(temp>='1' && temp<='9')
                  				cout<<temp;
                     		else
                     		{
                     			cout<<'\a';
               					continue;
                     		}
                        }
                        else
                        	cout<<temp;   //otherwise any no. at 2nd pos.
                     }
                  }
               }
               else if(dd_num==2)   //the month is of 30 days
               {
                	if(j==0)
               	{
            			if(temp>='0' && temp<='3')	  //only 0 and 3 at 1st pos.
                  		cout<<temp;
               		else
                  	{
                  		cout<<'\a';
               			continue;
               		}
               	}
                  else
                  {
                  	if(dmy[0]=='3')  	//only 0 at 2nd pos. if first value is 3
                     {
                        if(temp=='0')
                  			cout<<temp;
                     	else
                     	{
                     		cout<<'\a';
               				continue;
                     	}
                     }
                     else
                     {
                        if(dmy[0]=='0')   //only 1-9 at 2nd pos. if 1st value is 0
                        {
                     		if(temp>='1' && temp<='9')
                  				cout<<temp;
                     		else
                     		{
                     			cout<<'\a';
               					continue;
                     		}
                        }
                        else
                        	cout<<temp;     //otherwise any no. at 2nd pos.
                     }
                  }
               }
               else       //the month is of 28/29 days
               {
                	if(j==0)
               	{
            			if(temp>='0' && temp<='2')		//only 0-2 at 1st pos.
                  		cout<<temp;
               		else
                  	{
                  		cout<<'\a';
               			continue;
               		}
               	}
                  else
                  {
                  	if(dmy[0]=='2')   //if 2 is the 1st value
                     {
                        if(Feb==28)    //February is of 28 days
                        {
                        	if(temp<='8')    //only <=8 at 2nd pos.
                  				cout<<temp;
                     		else
                     		{
                     			cout<<'\a';
               					continue;
                     		}
                        }
                        else
                        	cout<<temp;      //otherwise (i.e Feb is of 29 days)
                     }                      //any no. at 2nd pos.
                     else
                     {
                        if(dmy[0]=='0')   //only 1-9 at 2nd pos. if 0 is 1st value
                        {
                     		if(temp>='1' && temp<='9')
                  				cout<<temp;
                     		else
                     		{
                     			cout<<'\a';
               					continue;
                     		}
                        }
                        else
                        	cout<<temp;    //otherwise any no. at 2nd pos.
                     }
                  }
               }
            }

            dmy[j]=temp;
            ++j;
         }
         else
         	cout<<'\a';
      }
      dmy[j]='\0';    //Terminating string
   }




      //enters Date of Birth - capable of calculating no. of days in a month and
      //also the no. of days in February (i.e. leap year or common year)
   	void DateMonYear(char date_dd[], char date_mm[], char date_yyyy[], int x, int y)
   {
   	gotoxy(77,35);		textcolor(2);
      cputs("~~~~~~~~~~~~~~~");
      gotoxy(79,37);    textcolor(10);
      cputs("Year  : ");	cout<<"----";
      gotoxy(79,38);
      cputs("Month : ");	cout<<"--";
      gotoxy(79,39);
      cputs("Date  : ");	cout<<"--";
      gotoxy(77,41);    textcolor(2);
      cputs("~~~~~~~~~~~~~~~");

      gotoxy(87,37);		enterDOB(date_yyyy,4,1);
      gotoxy(87,38);		enterDOB(date_mm,2,2);
      gotoxy(87,39);

      int year  = convert_str_to_int(date_yyyy);     //stores year
      int month = convert_str_to_int(date_mm);       //stores month

      if(month==2)      //i.e. Feb
      {
      	if((year%4==0 && year%100!=0) || (year%400==0))		//condition for leap year
         	enterDOB(date_dd,2,3,3,29);
         else
            enterDOB(date_dd,2,3,3,28);
      }
      else
      {
      	switch(month)
         {
         	case 1  :
            case 3  :
            case 5  :
            case 7  :
            case 8  :
            case 10 :
            case 12 : enterDOB(date_dd,2,3,1);		 break;	//month of 31 days

            case 4  :
            case 6  :
            case 9  :
            case 11 : enterDOB(date_dd,2,3,2);		 break;  //month of 30 days
         }
      }

      for(int m=1; m<=7; ++m)
         {
         	gotoxy(77,35);
            delline();
         }

      gotoxy(x,y);
      return;
   }



      //Displays and asks for status
   	void getstatus(char stat[], int y)
   {
      gotoxy(75,30);    textcolor(2);
      cputs("~~~~~~~~~~~~~~~~~~~~~");
      gotoxy(82,31);    textcolor(10);
      cputs("STATUS");
      gotoxy(77,33);
      cputs("1. Minor");
      gotoxy(77,34);
      cputs("2. Senior Citizen");
      gotoxy(77,35);
      cputs("3. Staff");
      gotoxy(77,36);
      cputs("4. NRI");
      gotoxy(77,37);
      cputs("5. General/Others");
      gotoxy(80,39);
      cputs("Option :");
      gotoxy(75,41);    textcolor(2);
      cputs("~~~~~~~~~~~~~~~~~~~~~");

      char temp;

      gotoxy(89,39);
      temp=OPTION('n','5');

      switch(temp)
      {
          case '1' : strcpy(stat, "Minor");
                     break;

          case '2' : strcpy(stat, "Senior Citizen");
                     break;

          case '3' : strcpy(stat, "Staff");
                     break;

          case '4' : strcpy(stat, "NRI");
                     break;

          case '5' : strcpy(stat, "General/Others");
                     break;
      }


      for(int m=1; m<=12; ++m)
      {
       	gotoxy(75,30);
         delline();
      }

      gotoxy(39,y);
   }



      //Displays and enters contact no - mobile or telephone
   	void contact(char pin[], char number[], int y)
   {
      gotoxy(75,32);   textcolor(2); 	  cputs("~~~~~~~~~~~~~~~~~~~");
      gotoxy(79,34);   textcolor(10);	  cputs("CONTACT NO.");
      gotoxy(78,36);   						  cputs("1. Telephone");
      gotoxy(78,37);   						  cputs("2. Mobile");
      gotoxy(79,39);   						  cputs("Option : ");
      gotoxy(75,41);	  textcolor(2);     cputs("~~~~~~~~~~~~~~~~~~~");

      gotoxy(88,39);
      int num=OPTION('n','2');

      for(int x=1; x<=10; ++x)
      {
       	gotoxy(75,32);
         delline();
      }

      switch(num)
      {
      	case '1' :	gotoxy(75,33);   textcolor(2);	 cputs("~~~~~~~~~~~~~~~~~~~~~~");
     						gotoxy(81,35);   textcolor(10);   cputs("TELEPHONE");
      					gotoxy(76,37);   		cputs("Pincode : "); 	cout<<"------";
      					gotoxy(76,38);   		cputs("Number  : "); 	cout<<"----------";
      					gotoxy(75,40);	  textcolor(2);	 cputs("~~~~~~~~~~~~~~~~~~~~~~");

                     EnterWD(pin,86,37,6,'-','n');
                     EnterWD(number,86,38,10,'-','n');

                     break;

         case '2' :  gotoxy(75,33);   textcolor(2);	cputs("~~~~~~~~~~~~~~~~~~~~~~~");
     						gotoxy(83,35);   textcolor(10);	cputs("MOBILE");
      					gotoxy(76,37);   		cputs("ISD Code : ");   cout<<"---";
      					gotoxy(76,38);   		cputs("Number   : ");	cout<<"----------";
      					gotoxy(75,40);	  textcolor(2);	cputs("~~~~~~~~~~~~~~~~~~~~~~~");

                     EnterWD(pin,87,37,3,'-','n');
                     EnterWD(number,87,38,10,'-','n');
      }

      for(int x=1; x<=8; ++x)
      {
       	gotoxy(75,33);
         delline();
      }

      gotoxy(39,y);
   }



   //converts a integer value (mainly money) to string and displays in
   //Indian-metric style
   void convert_int_to_str(double n)
{
	char num[100];
   int comma=0;
   int i=0;
   int rem=0;
   long int x=n;

   while(x>0)                    // 2,14,74,83,647
   {
      if(i<3)
      {
         rem=x%10;
   		num[i]=rem+48;
         x/=10;
      }
      else if(i>3)
		{
         if(comma!=2)
         {
         	rem=x%10;
   			num[i]=rem+48;
         	x/=10;
            ++comma;
         }
         else
         {
           	num[i]=',';
            comma=0;
         }
      }
      else
      	num[i]=',';

      ++i;
   }
   num[i]='\0';
   strrev(num);	  cout<<num;
}


   //count the no. of digits in a constant
   int count_digits(double num)
{
	int Count = 0;
   int temp=num;
   while(temp>0)
   {
   	Count++;
      temp/=10;
   }

   return Count;
}



   //Design for transaction purpose
	void Deposit_Des()
{
   textcolor(1);
	for(int j=0,k=27; j<50; ++j,++k)
   {
      gotoxy(k,13);    cputs("*");
      gotoxy(k,35);    cputs("*");
   }

   for(int j=0,k=14; j<22; ++j,++k)
   {
      gotoxy(27,k);	  cputs("*");
      gotoxy(76,k);    cputs("*");
   }

   gotoxy(53,31);		textcolor(3);    cputs("|");

   for(int p=54; p<=70; ++p)
   {
   	gotoxy(p,30);   cputs("-");
   	gotoxy(p,32);   cputs("-");
   }

   gotoxy(71,31);		cputs("|");

   gotoxy(35,31);   textcolor(11);	cputs("Enter Amount");
   textcolor(3);    cputs(" = ");	highvideo();   cputs("Rs");
}

