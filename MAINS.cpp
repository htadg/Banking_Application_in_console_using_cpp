//$$$$$$**********************************************************************$$$$$$\\
//$$$$$$**********************************************************************$$$$$$\\
//$$$$$$*****      	  <-----<< BANKING SYSTEM SOFTWARE® >>----->        *****$$$$$$\\
//$$$$$$**********************************************************************$$$$$$\\
//$$$$$$**********************************************************************$$$$$$\\
//$$$$$$    								: Developed By :	   		      $$$$$$\\
//$$$$$$                									            	  $$$$$$\\
//$$$$$$                	  		   						         		  $$$$$$\\
//$$$$$$                	  	 		  HITEN SHARMA                        $$$$$$\\
//$$$$$$                			      				                      $$$$$$\\
//$$$$$$				         				 							  $$$$$$\\
//$$$$$$				         				 							  $$$$$$\\
//$$$$$$         				 	 		  E-mail ID 		  	     	  $$$$$$\\
//$$$$$$         				 	 							              $$$$$$\\
//$$$$$$         				  		sharmahiten3@gmail.com  	          $$$$$$\\
//$$$$$$				         				 							  $$$$$$\\
//$$$$$$**********************************************************************$$$$$$\\
//$$$$$$**********************************************************************$$$$$$\\



//storing other special user-defined functions and header files
#include"Special_Functions.cpp"
#include"Resize Working.cpp"
#include"Password Creator.cpp"


  		char temp_name[25];
      unsigned attrib;


  		inline void Wrong()       //to display the string
  {
  		gotoxy(42,24);
      textcolor(12);		cputs("Wrong Password!!!");
  }


  		inline void notFound()    //to display the string
  {
  		gotoxy(42,20);
      textcolor(9);		cputs("Record not Found!!");
  }


  		inline void PAUSE()       //to display the string
  {
  		textcolor(14);
      cputs("Press any key to Return . . .");
  }



/*************************************************************************************
***********************************CLASS DEFINITION***********************************
*************************************************************************************/

		class BANK
   {
      char BKPin[5];
      char Name[31];

   		struct DATE      //for Date of Birth
   	{
   		char dd[3], mm[3], yyyy[5];
   	}DOB;

      char AccType[8];
      char Occup[26];
      char Status[15];
      char HouseNo[11];
      char Locality[16];
      char City[21];
      char State[21];
      char PinCode[7];
      char Nationality[21];
      char STD_ISDCode[7];
      char Number[11];
      int Account[16];
      double Deposit;

      public :  	BANK()
      			 {
                	Deposit=0;
                  strcpy(BKPin,"\0");
                  strcpy(Name,"\0");
                  strcpy(Occup,"\0");
                  strcpy(HouseNo,"\0");
                  strcpy(Locality,"\0");
                  strcpy(City,"\0");
                  strcpy(State,"\0");
                  strcpy(PinCode,"\0");
                  strcpy(Nationality,"\0");
                  strcpy(STD_ISDCode,"\0");
                  strcpy(Number,"\0");
                }

                ~BANK()
                { }

                char DaTe[10], TiMe[10];  //Sotres transaction date and time

      			 void EnterDet();          //For entering account details
                void InitialDep();        //For first cash deposit
      			 void AccInfo();           //Displaying full account details
                void DispSUMM(int, int);  //Displaying brief account details
                void PinDigit();          //Generates random BANK PIN No.
                void AccDigit();          //Generates random Account No.
                void AccList(int);        //To display brief details of all account
                void DispMod(int, int);   //To display particular field of an account
                void Modify(char[], int, char[], char[], char[], char[]);
                //To modify particular field of an account


                	char *retbp()
                {  return BKPin;	}

                	char *retnm()
                {  return Name;	}

                	double retDep()
                {  return Deposit;	}

                	void UpdateDep(double dep)
                {  Deposit+=dep;	 }

                	void Withdraw(double amt)
                {  Deposit-=amt;	 }


                	int RETsize(int n)
                {
                	 switch(n)
                   {
                   	 case 1 : return strlen(Name);     		break;
                      case 2 : return strlen(Occup);	   	break;
                      case 3 : return strlen(HouseNo);		break;
                      case 4 : return strlen(Locality);		break;
                      case 5 : return strlen(City);	   	break;
                      case 6 : return strlen(STD_ISDCode); 	break;
                      case 7 : return strlen(Number);	   	break;
                      case 8 : return strlen(Status);    	break;
                   }
                }
   };



   	void BANK::EnterDet()        //For entering account details
   {
      int p;

      gotoxy(6,9);	textcolor(6);
      cputs("1.  Bank PIN");  				gotoxy(36,wherey());	 cputs(":  ");
      PinDigit();

      _setcursortype(_NOCURSOR);
      for(int i=1; i<=3; ++i)
      {
         delay(500);    gotoxy(43,40);	   textcolor(11);
      	cputs("Generating PIN No....");
         delay(900);    gotoxy(43,40);	   delline();
      }
      _setcursortype(_NORMALCURSOR);
      gotoxy(39,9);     puts(BKPin);

      gotoxy(6,11);		textcolor(6);
      cputs("2.  Enter Name");						gotoxy(36,wherey());	cputs(":  ");
      EnterWD(Name,wherex(),wherey(),30,' '); 	strcpy(temp_name, Name);

      gotoxy(6,13);
      cputs("3.  Enter Account Type(C/S)");	 gotoxy(36,wherey());	cputs(":  ");
      Accfunc(AccType, wherey());    			 cout<<AccType;

      gotoxy(6,15);     textcolor(6);
      cputs("4.  Enter Complete Address");	 gotoxy(36,wherey());	cputs(":  ");
      ADDress(HouseNo, Locality, City, State, PinCode, wherey());
      gotoxy(39,15);		cout<<HouseNo<<", "<<Locality<<", "<<City<<", ";
      gotoxy(39,17);		cout<<State<<" - "<<PinCode;

      gotoxy(6,19);     textcolor(6);
      cputs("5.  Enter Date of Birth");		 gotoxy(36,wherey());	cputs(":  ");
      p=wherey();   	DateMonYear(DOB.dd, DOB.mm, DOB.yyyy, 39, p);
      cout<<DOB.dd<<"."<<DOB.mm<<"."<<DOB.yyyy;

      gotoxy(6,21);     textcolor(6);
      cputs("6.  Enter Occupation");			gotoxy(36,wherey());	cputs(":  ");
      EnterWD(Occup,wherex(),wherey(),25,' ');

      gotoxy(6,23);
      cputs("7.  Enter Status");       	gotoxy(36,wherey());	cputs(":  ");
      getstatus(Status, wherey());    		cout<<Status;

      gotoxy(6,25);     textcolor(6);
      cputs("8.  Enter Nationality");		gotoxy(36, wherey());	cputs(":  ");
      EnterWD(Nationality,wherex(),wherey(),20,' ');

      gotoxy(6,27);
      cputs("9.  Enter Contact");					gotoxy(36,wherey());	cputs(":  ");
      contact(STD_ISDCode, Number, wherey());   if(STD_ISDCode[0]=='0')
                                                	cout<<STD_ISDCode;
      												   	else
                                             		cout<<'+'<<STD_ISDCode;
      						                     	cout<<' '<<Number;
      AccDigit();

      _setcursortype(_NOCURSOR);
      for(int i=1; i<=3; ++i)
      {
         delay(500);		gotoxy(43,40);		textcolor(9);
      	cputs("Creating Account No....");
         delay(900);    gotoxy(43,40);		delline();
      }
      _setcursortype(_NORMALCURSOR);

      gotoxy(6,29);		textcolor(6);
      cputs("10. Account No.: ");		gotoxy(36,wherey());		cputs(":  ");
      	for(int i=0; i<16; ++i)
         	cout<<Account[i];

      sleep(3);
   }




   /*Displaying brief account details
	  To display only Name, Account Type and Account No. of an Account
   */
    	void BANK::DispSUMM(int x, int y)
   {
      gotoxy(x,y); 	textcolor(6);
      cputs("Name");				  gotoxy(49,wherey());	 cputs(":   ");	 puts(Name);
      gotoxy(x,y+2);
      cputs("Account Type");	  gotoxy(49,wherey());   cputs(":   ");	 puts(AccType);
      gotoxy(x,y+4);
      cputs("Account No.");     gotoxy(49,wherey());   cputs(":   ");
      	for(int i=0; i<16; ++i)
         	cout<<Account[i];
   }



  		void BANK::PinDigit()      //Generates random BANK PIN No.
   {
      int i;
  		randomize();
      BKPin[0]=(random(9-1+1)+1)+48;
      for(i=1;i<4;i++)
      	BKPin[i]=(random(9-0+1)+0)+48;
      BKPin[i]='\0';
   }


   void BANK::AccDigit()        //Generates random Account No.
   {
      int num1=4, num2=5;
      randomize();

      for(int i=0; i<4; ++i)
        Account[i]=random(3-1+1)+1;
      for(int i=4; i<8; ++i)
        Account[i]=random(num1);
      for(int i=8; i<12; ++i)
        Account[i]=random(num2);
      for(int i=12; i<16; ++i)
        Account[i]=random(9-6+1)+6;
   }


   void BANK::InitialDep()    //For First Cash Deposit
   {
      double money;
      char cash[11];
      Deposit=0;

      //goto label
      Enter_clr :    //If wrong money entered!!

      clrscr();
      CB_Design();

      gotoxy(36,10);		textcolor(4);
      for(int i=0; i<6; ++i)
      	cputs("<");
      highvideo();	cputs(" FIRST CASH DEPOSIT ");	lowvideo();
      for(int i=0; i<6; ++i)
         cputs(">");

      Deposit_Des();      //Designing
      DispSUMM(35,16);
      gotoxy(34,31);   textcolor(11);	cputs("Enter Amount");
   	textcolor(8);	  cputs("*");
      GotoXY("Available Balance",26,3,3,2);	         textcolor(10);
   	cputs("Available Balance");	   lowvideo();		   cputs(" = ");
      highvideo();	  cputs("Rs ");   cout<<retDep();   cputs("/-");
      gotoxy(37,42);   textcolor(8);	cputs("* Min Deposit limit = Rs500!");

      gotoxy(55,31);		enterNUM(cash,10);
      money = convert_str_to_int(cash);

      gotoxy(33,31);   textcolor(11);	cputs("Entered Amount");
   	textcolor(3);    cputs(" = ");	highvideo();   cputs("Rs");
      gotoxy(55,31);   cout<<cash;
      getch();

      if(money<500)
      {
         gotoxy(37,42);
         delline();
         gotoxy(34,42);		textcolor(13);
         cputs("Deposit below Rs500 is not Accepted!!");
         getch();
         goto Enter_clr;
      }
      else if(money>2147483647)
      {
         gotoxy(37,42);
         delline();
         gotoxy(38,42);		textcolor(13);
      	cputs("Don't try to be Oversmart!! :P");
         getch();
         goto Enter_clr;
      }
      else               //all above data should be displayed again.
      {
         gotoxy(37,42);
         delline();
         char s=Sure_Retry(38,42, 's');

         if(s=='y'||s=='Y')
         {
            gotoxy(38,42);  	delline();
            gotoxy(51,32);		delline();
            gotoxy(33,31);		delline();
            gotoxy(51,30);		delline();


            gotoxy(45,40);		textcolor(10);
        		cputs("Please Wait");
            _setcursortype(_NOCURSOR);
        		for(int i=0; i<5; ++i)
     	  		{
        			cputs(".");
        			sleep(1);
        		}
            _setcursortype(_NORMALCURSOR);
            Deposit=money;
            _strdate(DaTe);
            _strtime(TiMe);
            GotoXY("Available Balance",26,3,count_digits(Deposit),3,2);  textcolor(10);
   			cputs("Available Balance");	lowvideo();		cputs(" = ");
      		highvideo();	cputs("Rs ");  convert_int_to_str(Deposit);   cputs("/-");
            gotoxy(45,40);	  delline();
            gotoxy(38,42);	  textcolor(14);  cputs("Press any key to Continue . . .");
         }
         else
            goto Enter_clr;
      }
   }




   /*To display brief details of all account
     Especially used by DispSummary() for dispalying details of all accounts
   */
   void BANK::AccList(int v)
   {
      gotoxy(12,v);	  	puts(Name);
      gotoxy(42,v);		puts(AccType);
      gotoxy(59,v);		textcolor(8);	  cputs("xxxxxxxxxxxx");
      						for(int u=12; u<=15; ++u)
      							cout<<Account[u];
   	gotoxy(83,v);     convert_int_to_str(Deposit);
   }




   /*To display particular field of an account
     Especially used in by ModifyAcc() for modifying account details
   */
   void BANK::DispMod(int z, int x=54)
   {
   	if(z==1)
      	puts(Name);
      else if(z==2)
      {
      	cout<<HouseNo<<", "<<Locality<<", "<<City<<", ";
         gotoxy(x,19);	  cout<<State<<" - "<<PinCode;
      }
      else if(z==3)
      	puts(Occup);
      else if(z==4)
      	puts(Status);
      else
      {
      	if(STD_ISDCode[0]=='0')
         	cout<<STD_ISDCode;
         else
         	cout<<'+'<<STD_ISDCode;
         cout<<' '<<Number;
      }
   }





   /*To modify particular field of an account
     Especially used by ModifyAcc() to modify account details
   */
   void BANK::Modify(char s1[],  int z, char s2[]="\0", char s3[]="\0", char s4[]="\0", char s5[5]="\0")
   {
   	if(z==1)
      	strcpy(Name, s1);
      else if(z==2)
      {
      	strcpy(HouseNo, s1);
         strcpy(Locality, s2);
         strcpy(City, s3);
         strcpy(State, s4);
         strcpy(PinCode, s5);
      }
      else if(z==3)
      	strcpy(Occup, s1);
      else if(z==4)
      	strcpy(Status, s1);
      else
      {
      	strcpy(STD_ISDCode, s1);
         strcpy(Number, s2);
      }
   }




      void BANK :: AccInfo()		//Displaying full account details
   {
   	clrscr();
      CB_Design();
      gotoxy(1,10);	  textcolor(2);
      for(int i=0; i<100; ++i)
          cputs("=");
   	gotoxy(1,12);
      for(int i=0; i<100; ++i)
          cputs("=");

   	textcolor(12);		gotoxy(42,11);
   	cputs("ACCOUNT DETAILS");

   	gotoxy(40,15);		textcolor(6);
   	cputs("NAME     :     ");		puts(Name);

   	gotoxy(30,17);
   	cputs("ACCOUNT NUMBER     :     ");		for(int i=0;i<16;i++)
      														cout<<Account[i];
   	gotoxy(32,19);
   	cputs("ACCOUNT TYPE     :     ");		puts(AccType);

   	gotoxy(31,21);
   	cputs("DATE OF BIRTH     :     ");		cout<<DOB.dd<<'.'<<DOB.mm<<'.'<<DOB.yyyy;

      gotoxy(37,23);
      cputs("ADDRESS     :     ");
                       cout<<HouseNo<<", "<<Locality<<", "<<City<<", ";
      gotoxy(55,25);	  cout<<State<<" - "<<PinCode;

      gotoxy(30,27);
   	cputs("CONTACT NUMBER     :     ");    if(STD_ISDCode[0]=='0')
         													cout<<STD_ISDCode;
         												else
         													cout<<'+'<<STD_ISDCode;
                                             cout<<' '<<Number;

   	gotoxy(38,29);
		cputs("STATUS     :     ");        puts(Status);

   	gotoxy(33,31);
   	cputs("NATIONALITY     :     ");	  puts(Nationality);

   	gotoxy(34,33);
   	cputs("OCCUPATION     :     ");    puts(Occup);

   	gotoxy(27,35);
   	cputs("AVAILABLE BALANCE     :     Rs ");
      convert_int_to_str(Deposit);  cputs("/-");
   }

/*************************************************************************************
**************************************************************************************
**************************************************************************************/





                          //========= MAIN FUNCTION =========
   	void main()
   {
      SetConsoleTitle("The Central Bank");
      fstream f;
      if((_dos_getfileattr("Password.dat",&attrib)))
      	create();
      SetWindow(100,45);
      void CreateAcc();        //For creating a new Account
      void Transaction(int);   //For Transaction : Cash Deposit and Withdrawal
      void BalQuery();         //To display Balance and last transaction date and time
      void DispSummary();      //Displays all Accounts and facilitates Searching
      void DeleteAcc();        //For deleting an Account
      void ChangePWD();        //For changing the Current Password
      void ModifyAcc();        //For modifying Account Details

      char choice;
      int exit_conf;
      int allow;
      int colour;

      _setcursortype(_NOCURSOR);   //to make the cursor invisible
      for(int i=1; i<=5; ++i)      //this for loop displays the flickering string
      {
         randomize();
         colour=random(15-9+1)+9;
         textcolor(colour);
         delay(500);
      	gotoxy(38,20);	  cputs("Preparing For Start Up . . .");
         delay(500);
         clrscr();
      }

      clrscr();
      delay(1000);
      Starting_up();    //Function meant for designing output
      Welcome();        //			 		  ,,
      delay(3000);

      _setcursortype(_NORMALCURSOR);   //to make the cursor visible
      allow=Security_check();          //Enter Password
      clrscr();
      if(allow==0)     //If entering password limit reached
      {
      	exit(1);
      }

      Bouncing();     //Function meant for designing output

   	for(; ;)
   	{
      	clrscr();
         textbackground(8);
         _setcursortype(_NORMALCURSOR);    //making cursor visible
         choice=MENUwindow();     			 //Displays MAIN MENU

         switch(choice)
      	{
      		case '1' : CreateAcc();
            			  break;

         	case '2' : Transaction(2);		//2 for Cash Deposit
                       break;

         	case '3' : Transaction(3);    //3 for Cash Withdrawal
            			  break;

         	case '4' : BalQuery();
            			  break;

         	case '5' : DispSummary();
            			  break;

         	case '6' : ModifyAcc();
            			  break;

         	case '7' : DeleteAcc();
            			  break;

         	case '8' : ChangePWD();
            			  break;

         	case '9' : exit_conf=quit();    //quit() function asks to quit or not
                       if(exit_conf == 1)   //if quit confirmed
   						  		exit(0);
      	}
      }
   }


                            //========= CREATE NEW ACCOUNT =========
                              	 //For creating a new Account
   	void CreateAcc()
   {
      fstream crin;         //object for output accounts
      fstream cust_count;   //object for output no. of accounts
      fstream pin;          //object for output bkpin and name (just not to forget!)
      crin.open("Accounts.dat", ios::app|ios::binary);
      //Accounts.dat stores all the accounts
      _dos_getfileattr("Accounts.dat",&attrib);
      attrib |= _A_HIDDEN	;
      _dos_setfileattr("Accounts.dat",attrib);

      char more='y';
      char sure;
      GoBack();      //Asks whether you really want to enter or not

      if(back==13)
         while(more=='y' || more=='Y')
            {
               clrscr();
               pin.open("Bkpin.txt",ios::app);
               //Bkpin.txt stores Bkpin and corresponding name, just to remember.
               cust_count.open("Customer_no.dat", ios::in|ios::out);
               //Customer_no.dat stores the total no. of accounts

               _dos_getfileattr("Customer_no.dat",&attrib);
      			attrib |= _A_HIDDEN	;
      			_dos_setfileattr("Customer_no.dat",attrib);

               cust_count>>count;              //getting total no customers
               cust_count.seekg(0,ios::beg);
               //so that input can be done as if out mode

               BANK Cenbk;

               textcolor(3);              //designs
               for(int i=1; i<=100; ++i)
               	cputs("=");

               gotoxy(1,3);
               for(int i=1; i<=100; ++i)
               	cputs("=");

               textcolor(12);		lowvideo();
               gotoxy(39,2);
      		 	for(int k=0; k<5; k++)
      		 		cputs("<");
     				highvideo();   cputs(" CREATE ACCOUNT ");		lowvideo();
      			for(int k=0; k<5; k++)
      				cputs(">");

               gotoxy(46,5); 	  textcolor(8);  cputs("CUSTOMER : ");
               cout<<(count+1)<<endl;  			//showing fresh customer no.

               Cenbk.EnterDet();
               sure=Sure_Retry(38,40, 's');

               	if(sure=='y'||sure=='Y')
                  {
                     cust_count<<(count+1);     //adding new customer no.
                     pin<<temp_name<<' '<<Cenbk.retbp()<<endl;
                     pin.close();
                     cust_count.close();
                     clrscr();
         				gotoxy(45,20);   textcolor(10);
        					cputs("Please Wait");
                     _setcursortype(_NOCURSOR);
                     for(int i=0; i<5; ++i)
     	  					{
        						cputs(".");
        						sleep(1);
        					}
                     sleep(3);
                     _setcursortype(_NORMALCURSOR);

                     clrscr();
                     Cenbk.InitialDep();   		//Calling for First cash deposit
                     getch();		     clrscr();
                     gotoxy(43,20);	  textcolor(14);
                     cputs("Account Created!!");
                 		crin.write((char*)&Cenbk,sizeof(BANK));
                  }

               gotoxy(38,40);		clreol();

               //If user want to add more or 'wrong data' entered
               if(sure=='y'||sure=='Y')
               	more=Sure_Retry(38,40,'w','m');
               else
               	more=Sure_Retry(40,40,'w');

               crin.close();
            }
      else
      	Refreshing(1,"Redirecting");     //design - displaying process
      crin.close();
   }




   									//========= BALANCE QUERY =========
   						//To display Balance and last transaction date and time
   	void BalQuery()
   {
   	BANK Cenbk;

      fstream bqy;
      bqy.open("Accounts.dat", ios::binary|ios::in);

      char PIN[5]="\0";
      char found='n';    //checks whether data is present or not

      EnterPIN(PIN);     //Enters Bank PIN No.

      while(bqy.read((char*)&Cenbk, sizeof(BANK)))
      {
         if(!strcmp(PIN, Cenbk.retbp()))      //If Bank PIN matched!
         {
            clrscr();
            CB_Design();
            found='y';

            gotoxy(40,9);    textcolor(4);
            for(int k=0; k<5; k++)
      			cputs("<");
      		highvideo();	cputs(" BALANCE QUERY ");	 lowvideo();
      		for(int k=0; k<5; k++)
      			cputs(">");

            textcolor(2);
            for(int j=0,k=28; j<46; ++j,++k)
      		{
               gotoxy(k,11);
      			cputs("=");
         		gotoxy(k,40);
         		cputs("=");
      		}

      		for(int j=0,k=11; j<30; ++j,++k)
      		{
               gotoxy(28,k);
      			cputs("|");
         		gotoxy(74,k);
         		cputs("|");
      		}

            Cenbk.DispSUMM(34,14);
            gotoxy(44,25);   textcolor(10); 	cputs("Available Balance");

            gotoxy(41,28);   textcolor(3);    cputs("|");
      			for(int p=42; p<=63; ++p)
         		{
           			gotoxy(p,27);    	cputs("-");
            		gotoxy(p,29);     cputs("-");
         		}
            gotoxy(64,28);    cputs("|");
            textcolor(9);     gotoxy(37,24);		cputs("*");
            						gotoxy(66,24);		cputs("*");
           							gotoxy(37,31);    cputs("*");
            						gotoxy(66,31);    cputs("*");

            textcolor(10);	  gotoxy(39,28);		cputs("Rs");
            gotoxy(43,28);   convert_int_to_str(Cenbk.retDep());  cputs("/-");
            gotoxy(37,34);	  textcolor(13);
            cputs("Last Transaction Date and Time");
            gotoxy(43,36);		textcolor(11);
            cputs("Date  :  ");	 cout<<Cenbk.DaTe;
            gotoxy(43,38);
            cputs("Time  :  ");	 cout<<Cenbk.TiMe;

            gotoxy(39,44);		PAUSE();
            getch();
         }
      }
      bqy.close();

      if(found=='n')      //if data not found
      {
      	clrscr();  	   notFound();
         bqy.close();
         delay(1500);	Refreshing(1,"Redirecting");
      }
   }




                              //========= TRANSACTION =========
                                //Cash Deposit and Withdrawal
   	void Transaction(int trans)
   {
      BANK Cenbk;

      fstream dep;
      dep.open("Accounts.dat", ios::binary|ios::in|ios::out);

      char PIN[5]="\0";
      int fpos;
      char found='n';

      EnterPIN(PIN);      //Enters Bank PIN No.

      double money;

      char confirm='y';
      char re_ent='y';
      char cash[11]="\0";

      while(dep.read((char*)&Cenbk,sizeof(BANK)))
      {
         if(!strcmp(PIN, Cenbk.retbp()))
         {
            //goto label
            DispMoney :       //required if wrong money entered!!

            clrscr();
            CB_Design();
            Deposit_Des();    //designing

            Cenbk.DispSUMM(34,16);         textcolor(10);
            GotoXY("Available Balance",26,3,count_digits(Cenbk.retDep()),3,2);
            cputs("Available Balance");    lowvideo();		cputs(" = ");
      		highvideo();   cputs("Rs ");   convert_int_to_str(Cenbk.retDep());
            cputs("/-");

            if(trans==2)     //accepts cash deposit
         	{
             		gotoxy(40,11);		textcolor(4);
               	for(int k=0; k<5; k++)
      					cputs("<");
      				highvideo();	cputs(" CASH DEPOSIT ");	lowvideo();
      				for(int k=0; k<5; k++)
      					cputs(">");

      				gotoxy(55,31);		enterNUM(cash,10);
                  money = convert_str_to_int(cash);

						gotoxy(33,31);   textcolor(11);	cputs("Entered Amount");
   					textcolor(3);    cputs(" = ");	highvideo();   cputs("Rs");
                  gotoxy(55,31);    cout<<cash;
                  getch();

                  //beyond this value, entered money is not allowed
                  if(money>2147483647)
                  {
                  	gotoxy(38,42);		textcolor(13);
      					cputs("Don't try to be Oversmart!! :P");
         				getch();
                     Refreshing(2);
                     goto DispMoney;
                  }

                  confirm=Sure_Retry(38,42, 's');

               	if(confirm=='y'||confirm=='Y')
      				{
                     found='y';
                     Cenbk.UpdateDep(money);     //updating Deposit
                     _strdate(Cenbk.DaTe);       //storing transaction date
            			_strtime(Cenbk.TiMe);       //storing transaction time
                  }
               	else
                  {
                     found='y';
                     delline();
                   	re_ent=Sure_Retry(40,42, 'w');
                     if(re_ent=='y'||re_ent=='Y')
                     {
                         Refreshing(2);
                         goto DispMoney;    //if user want to enter the money again
                     }
                     else
                     	break;
                  }
   			}


            if(trans==3)       //accepts cash withdrawal
         	{
             		gotoxy(38,11); 	textcolor(4);
               	for(int k=0; k<5; k++)
      					cputs("<");
      				highvideo();	cputs(" CASH WITHDRAWAL ");	lowvideo();
      				for(int k=0; k<5; k++)
      					cputs(">");

                  if(Cenbk.retDep()==500)      //balance should not be below Rs500
                  {
                  	gotoxy(34,42); 	textcolor(8);
                     cout<<"NOTE : Balance limit reached (=Rs500)";
                  }

               	long balance;

                  gotoxy(55,31);		enterNUM(cash,10);
                  money = convert_str_to_int(cash);

						gotoxy(33,31);   textcolor(11);	cputs("Entered Amount");
   					textcolor(3);    cputs(" = ");	highvideo();   cputs("Rs");
            		gotoxy(55,31);	  cout<<cash;
                  getch();

                  balance=Cenbk.retDep()-money;
               	if(balance<500)     //if balance is below Rs500
               	{
                     gotoxy(35,42);		delline();
               		gotoxy(41,41);    textcolor(13);
                  	cputs("Insufficient Balance!!");
                     gotoxy(35,43);
                     cputs("Balance below 500 is not Accepted...");
                    	getch();
                     gotoxy(35,43);		delline();
                   	gotoxy(41,41);		delline();

                     found='y';
                    	re_ent=Sure_Retry(40,42, 'w');
                    	if(re_ent=='y'||re_ent=='Y')
                   	{
                         Refreshing(2);
                         goto DispMoney;    //if user want to enter the money again
                     }
							else
                     	break;
                  }
               	else
      				{
                    	found='y';
               		confirm=Sure_Retry(38,42, 's');

                    	if(confirm=='y'||confirm=='Y')
                    	{
                     	Cenbk.Withdraw(money);       //updating Deposit
                        _strdate(Cenbk.DaTe);        //Storing Transaction date
            				_strtime(Cenbk.TiMe);        //Storing Transaction time
                     }
                    	else
               		{
                    		delline();
                  		re_ent=Sure_Retry(40,42, 'w');
                    		if(re_ent=='y'||re_ent=='Y')
                    		{
                           Refreshing(2);
                          	goto DispMoney;     //if user want to enter the money again
                        }
                    		else
                    			break;
                  	}
            		}
            }

         		fpos=(-1)*sizeof(Cenbk);
         		dep.seekp(fpos,ios::cur);
         		dep.write((char*)&Cenbk,sizeof(BANK));
               dep.close();

               Processing();		sleep(3);
               clrscr();
               gotoxy(34,20);    textcolor(10);
               cputs("Transaction successfully completed!!");

               sleep(3);    BalQuery();
               Refreshing(2,"Redirecting");
         }
      }

      	if(found=='n')      //if data not found
      	{
      		clrscr();      notFound();
            dep.close();
            delay(1500);   Refreshing(1,"Redirecting");
      	}

         if(re_ent=='n'||re_ent=='N')
         	Refreshing(1,"Redirecting");
   }





   							  //========= DISPLAY ACCOUNTS DETAILS =========
                        //Displays all Accounts and facilitates Searching
   	void DispSummary()
   {
      BANK Cenbk;

      fstream sum;
      sum.open("Accounts.dat", ios::binary|ios::in);

      int pwdcode=AccountPWD();		//enters and stores password
      if(pwdcode==0)
      {
      	Wrong();   getch();
         return;
      }

      clrscr();

      int empty=sum.tellg();
      sum.seekg(0,ios::end);
      if(empty==sum.tellg())      //Checking whether file has any account (i.e. 0 KB).
      {
      	gotoxy(45,20);		       textcolor(12);
         cputs("No Accounts!!");  getch();
         sum.close();
         return;
      }
      sum.close();

      Refreshing(3,"Loading...");


      //goto label
      Return :         //displays all the contents again

    	clrscr();
      CB_Design();

      gotoxy(32,8);    textcolor(4);
      for(int k=0; k<5; k++)
      	cputs("<");
      highvideo();    cputs(" CUSTOMERS' ACCOUNTS LIST ");	  lowvideo();
      for(int k=0; k<5; k++)
      	cputs(">");

         gotoxy(1,10);		textcolor(1);
         for(int i=0; i<100; ++i)
          cputs("=");
            textcolor(10);
            gotoxy(2,11);   cputs("SR.No.");
         	gotoxy(12,11);	 cputs("NAME");
            gotoxy(40,11);  cputs("ACCOUNT TYPE");
            gotoxy(61,11);  cputs("ACCOUNT NO.");
            gotoxy(83,11);	 cputs("DEPOSIT(Rs)");
         gotoxy(1,12);     textcolor(1);
         for(int i=0; i<100; ++i)
          cputs("=");

      int y=14;
      int srno=1;
      int ypos;
      int erxy;

      sum.open("Accounts.dat", ios::binary|ios::in);
      while(sum.read((char*)&Cenbk,sizeof(BANK)))
      {
         gotoxy(4,y);	cout<<srno;
         textcolor(10);	cputs(" .");
         srno++;
      	Cenbk.AccList(y);
         y+=2;
         ypos=wherey();     //storing y-coordinate's location
      }
      sum.close();


      //User can Search either by entering Name or Bank PIN
      if(45-ypos>=5)
      {
         gotoxy(2, 44);
      	textcolor(14);		cputs("Esc to Back");
      	gotoxy(85,44);
      	textcolor(14);		cputs("Enter to Search");
         erxy=wherey();
      }
      else
      {
      	gotoxy(2, ypos+7);
      	textcolor(14);		cputs("Esc to Back");
      	gotoxy(85,ypos+7);
      	textcolor(14);		cputs("Enter to Search");
         erxy=wherey();
      }


      for(; ;)
      {
         int pos=search(ypos);

         char name[31], num[5], gotit='n';
         srno=1, y=14;    		  //reintialing values

      	if(pos==0)     //if 'ESC' entered
        	{
         	Refreshing(1,"Redirecting");
            return;
         }

      	if(pos==40 || pos==(y+8))    //for searching by name
      	{
            if(45-ypos>=5)
            	EnterWD(name,wherex(),40,30,' ');
            else
     			   EnterWD(name,wherex(),ypos+8,30,' ');

            int size = strlen(name);
            strlwr(name);

         	fstream sch;
      		sch.open("Accounts.dat", ios::binary|ios::in);

            for(int i=erxy; i>=14; --i)
            {
            	gotoxy(2,i);
               delline();
            }

         	while(sch.read((char*)&Cenbk,sizeof(BANK)))
         	{
               int countwd=0;
               char temp_wd[25];
         		strcpy(temp_wd, Cenbk.retnm());
               strlwr(temp_wd);

               for(int i=0; i<size; ++i)
      	  		   if(name[i]==temp_wd[i])
           				countwd++;

               //displays all the record with the initials matching
               if(countwd == size)
            	{
               	gotit='y';

            		gotoxy(4,y);  cout<<srno;   textcolor(10);  cputs(" .");
         			srno++;
      				Cenbk.AccList(y);
         			y+=2;
            	}
         	}
         	sch.close();

            if(gotit == 'y')     //if data found
            {
               gotoxy(38,44);		PAUSE();
            	getch();
               goto Return;
            }

         	if(gotit == 'n')     //if data not found
      		{
            	 for(int i=erxy; i>=14; --i)
            	 {
               	gotoxy(2,i);
                  delline();
                }
         		gotoxy(42,25);		textcolor(9);
            	cputs("Record not found!!");
               getch();
            	goto Return;
         	}
      	}

      	if(pos==42 || pos==(ypos+10))      //for searching by BANK PIN
      	{
      		if(45-ypos>=5)
            	EnterWD(num,wherex(),42,4,'-','n');
            else
            	EnterWD(num,wherex(),ypos+10,4,'-','n');

         	fstream sch;
      		sch.open("Accounts.dat", ios::binary|ios::in);

         	while(sch.read((char*)&Cenbk,sizeof(BANK)))
         	{
         		if(!strcmp(Cenbk.retbp(), num))
            	{
               	gotit='y';
               	for(int i=erxy; i>=14; --i)
            		{
               		gotoxy(2,i);
                  	delline();
               	}

            		gotoxy(4,y);	cout<<srno;	  textcolor(10);  cputs(" .");
         			srno++;
      				Cenbk.AccList(y);
         			++y;

                  //After search user can also see the full details
                  gotoxy(2, 44);
      				textcolor(14);		cputs("Esc to Back");
                  gotoxy(75,44);
                  textcolor(14);		cputs("Enter to see full Details");

                  char temp=getch();
                  if(temp==13)
                  {
                  	Cenbk.AccInfo();
                     gotoxy(38,42);		PAUSE();
                     getch();
                  }
            	}
         	}
         	sch.close();

            if(gotit == 'y')       //if data found
               goto Return;


         	if(gotit == 'n')       //if data not found
      		{
             	for(int i=erxy; i>=14; --i)
            	{
               	gotoxy(2,i);
                  delline();
               }
         		gotoxy(42,25);		textcolor(9);
            	cputs("Record not found!!");
               getch();
            	goto Return;
         	}
      	}
      }
   }



                             //========= DELETE ACCOUNT =========
                                 //For deleting an Account
   	void DeleteAcc()
   {
      BANK Cenbk;

      char sure;
      char PIN[10];
      char found='n';

   	fstream old, updated, cust_count;
      old.open("Accounts.dat",ios::binary|ios::in);
      updated.open("temp.dat",ios::binary|ios::out);

      _dos_getfileattr("temp.dat",&attrib);
     	attrib |= _A_HIDDEN	;
     	_dos_setfileattr("temp.dat",attrib);

      EnterPIN(PIN);

      while(old.read((char*)&Cenbk,sizeof(BANK)))
      {
         if(!strcmp(PIN, Cenbk.retbp()))
         {
            clrscr();
            CB_Design();
            found='y';

         	Cenbk.DispSUMM(35,16);
            gotoxy(35,22);			textcolor(6);
            cputs("Deposit");	  	gotoxy(49,wherey());	  	cputs(":   Rs ");
            convert_int_to_str(Cenbk.retDep());				cputs("/-");
            sure=Sure_Retry(38,30, 's');

            if(sure=='n'||sure=='N')
      			updated.write((char *)&Cenbk,sizeof(BANK));
         }
         else
         	updated.write((char *)&Cenbk,sizeof(BANK));
      }

      old.close();
      updated.close();
      remove("Accounts.dat");
      rename("temp.dat","Accounts.dat");

      _dos_getfileattr("Accounts.dat",&attrib);
   	attrib |= _A_HIDDEN	;
      _dos_setfileattr("Accounts.dat",attrib);


      if(found=='n')
      {
      	clrscr();      notFound();
         delay(1500);   Refreshing(1,"Redirecting");
      }
      else
      {
         if(count>1)
         	--count;     //subtracting 1 customer from accounts no.

         if(sure=='y'||sure=='Y')
         {
            cust_count.open("Customer_no.dat", ios::out);
            cust_count<<count;
            cust_count.close();

            clrscr();
            gotoxy(42,18);
            cout<<"Account Closed!!";
            delay(1500);
      	   Refreshing(1,"Redirecting");
         }
         else
         	Refreshing(1,"Redirecting");
      }
   }



                               //========= MODIFY ACCOUNTS =========
                                 //For modifying Account Details
   void ModifyAcc()
   {
      BANK Cenbk;
      fstream Acc;
      Acc.open("Accounts.dat",ios::binary|ios::in|ios::out);

      char PIN[10], found='n';
      int pos;

      EnterPIN(PIN);

      while(Acc)
      {
         pos=Acc.tellg();

         Acc.read((char*)&Cenbk,sizeof(BANK));
         if(!strcmp(PIN, Cenbk.retbp()))
         {
            char str1[31], str2[26], str3[20], str4[20], str5[7];
            char choice, cfm;
      	   int ret_chk=0;
            int xpos;
            found='y';

            //Modify Account MENU
            for(; ;)
				{
         		clrscr();
      			CB_Design();
      			gotoxy(36,11);   textcolor(4);	cputs("<<<<<<<<");
  		  			highvideo();	  cputs(" MODIFY ACCOUNT ");
      			lowvideo();      cputs(">>>>>>>>");

      			gotoxy(42,14);	 textcolor(2);	 cputs("1");  highvideo(); cputs(".");
               textcolor(3);	 cputs(" Change Name");
      			gotoxy(42,16);  textcolor(2);	 cputs("2");  highvideo(); cputs(".");
     	   		textcolor(3);   cputs(" Change Address");
      			gotoxy(42,18);  textcolor(2);	 cputs("3");  highvideo(); cputs(".");
      			textcolor(3);   cputs(" Change Occupation");
      			gotoxy(42,20);  textcolor(2);	 cputs("4");  highvideo(); cputs(".");
      			textcolor(3);   cputs(" Change Status");
      			gotoxy(42,22);  textcolor(2);	 cputs("5");  highvideo(); cputs(".");
      			textcolor(3);   cputs(" Change Contact");
               gotoxy(42,24);  textcolor(2);	 cputs("6");  highvideo(); cputs(".");
      			textcolor(3);   cputs(" View Account Details");
      			gotoxy(42,26);  textcolor(2);	 cputs("7");  highvideo(); cputs(".");
         		textcolor(3);   cputs(" Return");
      			gotoxy(42,31);  textcolor(8);	 cputs("Enter Your Choice : ");

      			choice=OPTION('n','7');

               switch(choice)
      			{
      				case '1' : clrscr();
                             CB_Design();
                             GotoXY("Old Name    :    ",17,Cenbk.RETsize(1));
                             xpos=wherex();
                  			  textcolor(6);     cputs("Old Name    :    ");	 Cenbk.DispMod(1);
                             gotoxy(xpos,20);  cputs("New Name    :    ");
                             EnterWD(str1,wherex(),wherey(),30,' ');

                             cfm = Sure_Retry(38,30, 's');
                             if(cfm == 'y' || cfm == 'Y')
                             {
                             		Cenbk.Modify(str1,1);
                             		ret_chk=1;
                             }
                             break;

         			case '2' : clrscr();
                             CB_Design();
                             GotoXY("Old Address   :   ",17,Cenbk.RETsize(3),2,Cenbk.RETsize(4),2,Cenbk.RETsize(5));
                             xpos=wherex();
                             textcolor(6);     cputs("Old Address   :   ");  Cenbk.DispMod(2, xpos+18);
                             gotoxy(xpos,22);  cputs("New Address   :   ");
                             ADDress(str1, str2, str3, str4, str5, wherey());
                             gotoxy(xpos+18, 22);	cout<<str1<<", "<<str2<<", "<<str3;
      							  gotoxy(xpos+18, 24);  cout<<str4<<" - "<<str5;

                             cfm = Sure_Retry(38,30, 's');
                             if(cfm == 'y' || cfm == 'Y')
                             {
                             		Cenbk.Modify(str1,2,str2,str3,str4,str5);
                                 ret_chk=1;
                             }
                             break;

     	      		case '3' : clrscr();
                             CB_Design();
                             GotoXY("Old Occupation    :    ",17,Cenbk.RETsize(2));
                             xpos=wherex();
                             textcolor(6);  cputs("Old Occupation    :    ");	Cenbk.DispMod(3);
                             gotoxy(xpos,20); cputs("New Occupaton     :    ");
                             EnterWD(str2,wherex(),wherey(),25,' ');

                             cfm = Sure_Retry(38,30, 's');
                             if(cfm == 'y' || cfm == 'Y')
                             {
                             		Cenbk.Modify(str2,3);
                                 ret_chk=1;
                             }
                             break;

         			case '4' : clrscr();
                             CB_Design();
                             GotoXY("Old Status   :   ",17,Cenbk.RETsize(8));
                             xpos=wherex();
                             textcolor(6);  cputs("Old Status   :   ");	 Cenbk.DispMod(4);
                             gotoxy(xpos,20);
                             cputs("New Status   :   ");	  getstatus(str2,wherey());
                             gotoxy(xpos+17,wherey());	  puts(str2);

                             cfm = Sure_Retry(38,30, 's');
                             if(cfm == 'y' || cfm == 'Y')
                             {
                             		Cenbk.Modify(str2,4);
                                 ret_chk=1;
                             }
                             break;

         			case '5' : clrscr();
                             CB_Design();
                             GotoXY("Old Contact No.   :   ",17,Cenbk.RETsize(6),Cenbk.RETsize(7));
                             xpos=wherex();
                             textcolor(6);  cputs("Old Contact No.   :   ");	Cenbk.DispMod(5);
                             gotoxy(xpos,20);    cputs("New Contact No.   :   ");
                             contact(str5,str2,wherey());
                             gotoxy(xpos+22,wherey());  if(str5[0]=='0')
                             									    cout<<str5;
                             								     else
                                                   	    cout<<'+'<<str5;
                                                        cout<<' '<<str2;

                             cfm = Sure_Retry(38,30, 's');
                             if(cfm == 'y' || cfm == 'Y')
                             {
                             		Cenbk.Modify(str5,5,str2);
                                 ret_chk=1;
                             }
                             break;

         			case '6' : Cenbk.AccInfo();
                  			  gotoxy(38,42);    textcolor(14);
                             PAUSE();	  getch();
                             break;

                  case '7' : if(ret_chk == 0)
                  				  Refreshing(1,"Redirecting");
                  			  else
                             	  Refreshing(2,"Modifying");
                             break;
      			}

               if(choice == '7')
               	break;			//to come out of for loop
            }

            Acc.seekp(pos);
            Acc.write((char*)&Cenbk,sizeof(BANK));
            Acc.close();
            break;
         }
      }

      if(found=='n')
      {
      	clrscr();  		 notFound();
         delay(1500);    Refreshing(1,"Redirecting");
      }
   }



                              //========= CHANGE PASSWORD =========
                               //For changing the Current Password
   void ChangePWD()
   {
      int pwdcode=AccountPWD(1);

      if(pwdcode==0)
      {
      	Wrong();    getch();
         return;
      }

      clrscr();

      int l;
      gotoxy(5,3);	cout<<(char)175;
      gotoxy(96,3);	cout<<(char)174;
   	gotoxy(5,43);	cout<<(char)175;
   	gotoxy(96,43);	cout<<(char)174;


      char d1=201, d2=187;
      char d3=205, d4=186;
      char d5=200, d6=188;

   	gotoxy(32,14);
  		cout<<d1;
   	for(l=1; l<=35; ++l)
   		cout<<d3;
   	cout<<d2;
   	for(l=15; l<=25; ++l)
   	{
      	gotoxy(32,l);	 cout<<d4;
      	gotoxy(68,l);   cout<<d4;
      }

   	gotoxy(32,25);
   	cout<<d5;
   	for(l=1; l<=35; ++l)
   		cout<<d3;
   	cout<<d6;

      char pwd1[10], pwd2[10];
      gotoxy(37,18);   textcolor(10);
      cputs("Enter New Password : ");	textcolor(15);  cputs("-----");
      enterPASS(pwd1,58,18,11);
      gotoxy(39,21);   textcolor(10);
      cputs("Confirm Password : ");	   textcolor(15);	 cputs("-----");
      enterPASS(pwd2,58,21,11);

      if(!strcmp(pwd1, pwd2))
      {
         gotoxy(42,29);		textcolor(13);
      	cputs("Password Changed!");
         DeleteFile("Password.dat");
         fstream cng("Password.dat", ios::binary|ios::out);
         _dos_getfileattr("Password.dat",&attrib);
         attrib |= _A_HIDDEN;
         _dos_setfileattr("Password.dat",attrib);
         cng<<pwd1;
         cng.close();
      }
      else
      {
         gotoxy(39,29);		textcolor(12);
      	cputs("Password Didn't Matched!");
      }
      gotoxy(37,41);		PAUSE();
      getch();
   }
