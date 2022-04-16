//============================================================================
// Name        : Juego.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "biblioteca/tads/Juego.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/funciones/strings.hpp"

using namespace std;


int main()
{
   bool repetir = true;
   pintarLimites();
   string nombre1;
   string nombre2;
   gotoxy(40,17);
   cout<<"Ingrese Nombre del Jugador 1: ";
   cin>>nombre1;
   gotoxy(69,17);
   cout<<"                    ";
   gotoxy(40,17);
   cout<<"Ingrese Nombre del Jugador 2: ";
   cin>>nombre2;
   gotoxy(69,17);
   cout<<"                    ";

   gotoxy(40,10);
   cout<<"---------------Controles---------------";
   gotoxy(40,11);
   cout<<"Jugador 1:";
   gotoxy(40,12);

   cout<<"Movimiento: WASD";
   gotoxy(40,13);
   cout<<"Disparo: Espacio";
   gotoxy(60,11);
   cout<<"Jugador 2:";
   gotoxy(60,12);
   cout<<"Movimiento: Flechas";
   gotoxy(60,13);
   cout<<"Disparo: Intro";
   gotoxy(40,14);
   cout<<"---------------------------------------";
   nombre1 = substring(nombre1,0,11);
   nombre2 = substring(nombre2,0,11);
   int ln2 = length(nombre2);

   while( repetir )
   {

      gotoxy(40,17);
      cout<<"Presione cualquier tecla para comenzar:";
      getch();
      gotoxy(40,17);
      cout<<"                                       ";
      gotoxy(40,10);
      cout<<"                                                               ";
      gotoxy(40,11);
      cout<<"                                                               ";
      gotoxy(40,12);
      cout<<"                                                         ";
      gotoxy(40,13);
      cout<<"                                                               ";
      gotoxy(40,14);
      cout<<"                                                               ";
      ocultarCursor();
      bool gameOver = false;
      Pers p = { 95, 15, 3, 1 };
      Pers p2 = { 20, 15, 3, 0 };
      pintarPers(p);
      pintarPers(p2);
      Coll<Bala> b1 = collCreate<Bala>();
      Coll<Bala> b2 = collCreate<Bala>();
      mostrarVidas(p,p2,nombre1,nombre2,ln2);
      int c1 = 0;
      int c2 = 0;
      while( !gameOver )
      {

         if( kbhit() )
         {
            char tecla = getch();
            if( tecla==13 /*INTRO*/&&c1>4 )
            {
               collAdd(b1,{ p.x-1, p.y+1 },balaToString);
               c1 = 0;
            }
            if( tecla==32 /*ESPACIO*/&&c2>4 )
            {
               collAdd(b2,{ p2.x+4, p2.y+1 },balaToString);
               c2 = 0;
            }
            moverPers2(p2,tecla);
            moverPers1(p,tecla);
            c1++;
            c2++;
         }

         // Balas P1
         for( int i = 0; i<collSize(b1); i++ )
         {
            Bala b = collGetAt(b1,i,stringToBala);
            moverBalaP1(b);
            collSetAt(b1,b,i,balaToString);

            if( choqueBala(b,p2) )
            {
               for( int j = 0; j<collSize(b2); j++ )
               {
                  b = collGetAt(b2,j,stringToBala);
                  borrarBala(b);
               }
               for( int j = 0; j<collSize(b1); j++ )
               {
                  b = collGetAt(b1,j,stringToBala);
                  borrarBala(b);
               }
               collRemoveAll(b1);
               collRemoveAll(b2);

               muerte(p2,p);
               mostrarVidas(p,p2,nombre1,nombre2,ln2);
            }
            else
               if( fueraBala(b) )
               {
                  borrarBala(b);
                  collRemoveAt(b1,i);
                  i--;
               }

         }

         // Balas P2
         for( int i = 0; i<collSize(b2); i++ )
         {
            Bala b = collGetAt(b2,i,stringToBala);
            moverBalaP2(b);
            collSetAt(b2,b,i,balaToString);

            if( choqueBala(b,p) )
            {
               for( int j = 0; j<collSize(b2); j++ )
               {
                  b = collGetAt(b2,j,stringToBala);
                  borrarBala(b);
               }
               for( int j = 0; j<collSize(b1); j++ )
               {
                  b = collGetAt(b1,j,stringToBala);
                  borrarBala(b);
               }
               collRemoveAll(b1);
               collRemoveAll(b2);
               muerte(p,p2);
               mostrarVidas(p,p2,nombre1,nombre2,ln2);
            }
            else
               if( fueraBala(b) )
               {
                  borrarBala(b);
                  collRemoveAt(b2,i);
                  i--;
               }
         }

         if( p.vidas==0||p2.vidas==0 )
         {
            gameOver = true;
         }
         Sleep(20);
      }
      borraPers(p);
      borraPers(p2);

      mostrarSkull(40,4);
      Sleep(1000);
      borrarSkull(40,4);

      gotoxy(55,17);
      cout<<"Ganador: ";
      if( p.vidas>p2.vidas )
      {
         cout<<nombre2;
      }
      else
      {
         cout<<nombre1;
      }

      Sleep(3000);


      gotoxy(55,17);
            cout<<"                        ";

            mostrarGameOver(35,13);
            Sleep(2000);
            borrarGameOver(35,13);
            while( kbhit() )
                     getch();
      p.vidas = 3;
      p2.vidas = 3;
      mostrarVidas(p,p2,nombre1,nombre2,ln2);


   }
   return 0;
}

