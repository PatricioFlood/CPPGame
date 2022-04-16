#ifndef _TJUEGO_T_
#define _TJUEGO_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
using namespace std;

struct Bala
{
   int x;
   int y;
};

struct Pers
{
   int x;
   int y;
   int vidas;
   bool player1;
};

void gotoxy(int x, int y)
{
   HANDLE hCon;
   hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X = x;
   dwPos.Y = y;
   SetConsoleCursorPosition(hCon,dwPos);
}

void mostrarGameOver(int x, int y)
{
   gotoxy(x,y);
   y++;
   cout<<"  _____                         ____";
   gotoxy(x,y);
   y++;
   cout<<" / ____|                       / __ \\";
   gotoxy(x,y);
   y++;
   cout<<"| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ";
   gotoxy(x,y);
   y++;
   cout<<"| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|";
   gotoxy(x,y);
   y++;
   cout<<"| |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |";
   gotoxy(x,y);
   y++;
   cout<<" \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|";

}

void borrarGameOver(int x, int y)
{
   int fin = y+6;
   for( int i = y; i<fin; i++ )
   {
      gotoxy(x,i);
      cout<<"                                                                    ";
   }
}

void mostrarSkull(int x, int y)
{
   gotoxy(x,y);
   y++;
   cout<<"                 uuuuuuu";
   gotoxy(x,y);
   y++;
   cout<<"             uu$$$$$$$$$$$uu";
   gotoxy(x,y);
   y++;
   cout<<"          uu$$$$$$$$$$$$$$$$$uu";
   gotoxy(x,y);
   y++;
   cout<<"         u$$$$$$$$$$$$$$$$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"        u$$$$$$$$$$$$$$$$$$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"       u$$$$$$$$$$$$$$$$$$$$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"       u$$$$$$$$$$$$$$$$$$$$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"       u$$$$$$\" \"$$$\" \"$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"       \"$$$$\"      u$u       $$$$\"";
   gotoxy(x,y);
   y++;
   cout<<"        $$$u       u$u       u$$$";
   gotoxy(x,y);
   y++;
   cout<<"        $$$u      u$$$u      u$$$";
   gotoxy(x,y);
   y++;
   cout<<"         \"$$$$uu$$$   $$$uu$$$$\"";
   gotoxy(x,y);
   y++;
   cout<<"          \"$$$$$$$\"   \"$$$$$$$\"";
   gotoxy(x,y);
   y++;
   cout<<"            u$$$$$$$u$$$$$$$u";
   gotoxy(x,y);
   y++;
   cout<<"             u$\"$\"$\"$\"$\"$\"$u";
   gotoxy(x,y);
   y++;
   cout<<"  uuu        $$u$ $ $ $ $u$$       uuu";
   gotoxy(x,y);
   y++;
   cout<<" u$$$$        $$$$$u$u$u$$$       u$$$$";
   gotoxy(x,y);
   y++;
   cout<<"  $$$$$uu      \"$$$$$$$$$\"     uu$$$$$$";
   gotoxy(x,y);
   y++;
   cout<<"u$$$$$$$$$$$uu    \"\"\"\"\"    uuuu$$$$$$$$$$";
   gotoxy(x,y);
   y++;
   cout<<"$$$$\"\"\"$$$$$$$$$$uuu   uu$$$$$$$$$\"\"\"$$$\"";
   gotoxy(x,y);
   y++;
   cout<<" \"\"\"      \"\"$$$$$$$$$$$uu \"\"$\"\"\"";
   gotoxy(x,y);
   y++;
   cout<<"           uuuu \"\"$$$$$$$$$$uuu";
   gotoxy(x,y);
   y++;
   cout<<"  u$$$uuu$$$$$$$$$uu \"\"$$$$$$$$$$$uuu$$$";
   gotoxy(x,y);
   y++;
   cout<<"  $$$$$$$$$$\"\"\"\"           \"\"$$$$$$$$$$$\"";
   gotoxy(x,y);
   y++;
   cout<<"   \"$$$$$\"                      \"\"$$$$\"\"";
   gotoxy(x,y);
   y++;
   cout<<"     $$$\"                         $$$$\"";
}

void borrarSkull(int x, int y)
{
   int fin = y+26;
   for( int i = y; i<fin; i++ )
   {
      gotoxy(x,i);
      cout<<"                                                                ";
   }
}


void pintarPers(Pers p)
{
   gotoxy(p.x,p.y);
   cout<<" O";
   gotoxy(p.x,p.y+1);
   cout<<"/|\\";
   gotoxy(p.x,p.y+2);
   cout<<"/ \\";
}
void borraPers(Pers p)
{
   gotoxy(p.x,p.y);
   cout<<"  ";
   gotoxy(p.x,p.y+1);
   cout<<"   ";
   gotoxy(p.x,p.y+2);
   cout<<"   ";
}

void moverPers1(Pers& p, char tecla)
{

   borraPers(p);
   if( tecla==IZQUIERDA&&p.x>2 )
      p.x--;
   else
      if( tecla==DERECHA&&p.x<115 )
         p.x++;
      else
         if( tecla==ARRIBA&&p.y>4 )
            p.y--;
         else
            if( tecla==ABAJO&&p.y<27 )
               p.y++;

   pintarPers(p);

}
void moverPers2(Pers& p2, char tecla)
{

   borraPers(p2);

   if( tecla=='a'&&p2.x>2 )
      p2.x--;
   if( tecla=='d'&&p2.x<115 )
      p2.x++;
   if( tecla=='w'&&p2.y>4 )
      p2.y--;
   if( tecla=='s'&&p2.y<27 )
      p2.y++;

   pintarPers(p2);

}

void pintarBala(Bala b)
{
   gotoxy(b.x,b.y);
   cout<<(char)254;
}
void borrarBala(Bala b)
{
   gotoxy(b.x,b.y);
   cout<<" ";
}

void moverBalaP2(Bala& b)
{
   borrarBala(b);
   b.x++;
   pintarBala(b);
}

void moverBalaP1(Bala& b)
{
   gotoxy(b.x,b.y);
   cout<<" ";
   if( b.x>2 )
   {
      b.x--;
      pintarBala(b);
   }
}

bool fueraBala(Bala b)
{
   if( b.x>116||b.x<3 )
      return true;
   return false;
}

bool choqueBala(Bala b, Pers p)
{
   if( b.x==p.x+1&&b.y==p.y )
   {
      return true;
   }
   else
      if( b.x>=p.x&&b.x<p.x+3&&b.y==p.y+1 )
      {
         return true;
      }
      else
         if( b.x>=p.x&&b.x<p.x+3&&b.y==p.y+2 )
         {
            return true;
         }
   return false;
}

void ocultarCursor()
{
   HANDLE hCon;
   hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cci;
   cci.dwSize = 2;
   cci.bVisible = false;
   SetConsoleCursorInfo(hCon,&cci);
}

void pintarLimites()
{
   for( int i = 2; i<118; i++ )
   {
      gotoxy(i,3);
      cout<<(char)205;
      gotoxy(i,30);
      cout<<(char)205;
   }

   for( int i = 4; i<30; i++ )
   {
      gotoxy(1,i);
      cout<<(char)186;
      gotoxy(118,i);
      cout<<(char)186;
   }
   gotoxy(1,3);
   cout<<(char)201;
   gotoxy(118,3);
   cout<<(char)187;
   gotoxy(1,30);
   cout<<(char)200;
   gotoxy(118,30);
   cout<<(char)188;
}

void muerte(Pers& p, Pers& p2)
{
   p.vidas--;
   gotoxy(p.x,p.y);
   cout<<" X";
   gotoxy(p.x,p.y+1);
   cout<<"xxx";
   gotoxy(p.x,p.y+2);
   cout<<"x x";
   Sleep(500);
   borraPers(p);
   borraPers(p2);
   if( p.player1 )
   {
      p.x = 95;
      p.y = 15;
      p2.x = 20;
      p2.y = 15;
   }
   else
   {
      p2.x = 95;
      p2.y = 15;
      p.x = 20;
      p.y = 15;
   }
   pintarPers(p);
   pintarPers(p2);
}

string balaToString(Bala b)
{
   return intToString(b.x)+";"+intToString(b.y);
}

Bala stringToBala(string s)
{
   Bala b;
   b.x = stringToInt(getTokenAt(s,';',0));
   b.y = stringToInt(getTokenAt(s,';',1));
   return b;
}

void mostrarVidas(Pers p1, Pers p2, string n1, string n2,int ln2)
{
   gotoxy(2,2);
   cout<<n1<<": "<<p2.vidas;
   if( p2.vidas==1 )
   {
      cout<<" Vida. ";
   }
   else
   {
      cout<<" Vidas.";
   }
   gotoxy(109-ln2,2);
   cout<<n2<<": "<<p1.vidas;
   gotoxy(112,2);
   if( p1.vidas==1 )
   {
      cout<<" Vida. ";
   }
   else
   {
      cout<<" Vidas.";
   }
}


#endif
