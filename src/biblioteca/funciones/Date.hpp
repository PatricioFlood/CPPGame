#ifndef _TDATE_T_
#define _TDATE_T_

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "strings.hpp"
using namespace std;

// --[Funciones DATE]--
void getDate(int& diaDeSemana)
{
 // fecha actual expresada en segundos
 time_t timestamp;
 time(&timestamp);
 // separo la fecha actual en atributos
 struct tm* fechaActual = localtime(&timestamp);
 diaDeSemana = fechaActual->tm_wday;
}

void getDate(int& dia, int& mes, int& anio)
{
 // fecha actual expresada en segundos
 time_t timestamp;
 time(&timestamp);
 // separo la fecha actual en atributos
 struct tm* fechaActual = localtime(&timestamp);
 dia = fechaActual->tm_mday;
 mes = fechaActual->tm_mon+1;
 anio = fechaActual->tm_year+1900;
}

// --[/Funciones Token]--

#endif
