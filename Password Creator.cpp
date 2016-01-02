#include <fstream>
#include <conio>
#include <stdlib>
#include <dos>
#include <windows>

void create()
{
   unsigned attrib;
	char pass[6];
   randomize();
   pass[5]='\0';
   pass[0]=random(57-49+1)+49;
   for(int i=1;i<5;i++)
   	pass[i]=random(57-48+1)+48;
   cout<<"\n\n\n\n\t\tYour Password is : "<<pass;
   DeleteFile("Password.dat");
   fstream pas;
   pas.open("Password.dat",ios::binary|ios::out);
   pas<<pass;
   pas.close();
   _dos_getfileattr("Password.dat", &attrib);
   attrib |= _A_HIDDEN;
   _dos_setfileattr("Password.dat", attrib);
   getch();
   clrscr();
}