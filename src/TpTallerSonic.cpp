//============================================================================
// Name        : TpTallerSonic.cpp
// Author      : Joha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include </usr/include/SDL2/SDL.h>
#include <jansson.h>
#include "jventana.h"
#include "jconfiguracion.h"
using namespace std;

int main() {
	 json_t *json;
	 json_error_t error;

	 json = json_load_file("/home/pato/workspace/TpTallerSonic/configuracion/f.json",0,&error);

	  if(!json) {
	   /* the error variable contains error information */

		   cout << "!!! hay  probremas!!!" << endl; // prints !!!Hello World!!!
		   cout << error.text << endl;
		 }

	  /*   json_t *jsonprueba;
	     jsonprueba = json_object_get(json, "prueba");
		 cout <<  json_number_value(jsonprueba)<< endl;

		 jsonprueba = json_object_get(json, "configuracion");
		 jsonprueba = json_object_get(jsonprueba, "vel_scroll");
		 cout <<  json_number_value(jsonprueba)<< endl;
      */

	    //ventana

         json_t *jsonventana;
         json_t *jsonventanaalto;
         json_t *jsonventanaancho;

         jsonventana = json_object_get(json, "ventana");
         jsonventana = json_object_get(jsonventana,"dimensiones");

         jsonventanaalto = json_object_get(jsonventana,"alto");
         jsonventanaancho = json_object_get(jsonventana,"ancho");


         jventana *ventana = new jventana();

         ventana->setalto(json_number_value(jsonventanaalto));
         ventana->setancho(json_number_value(jsonventanaancho));

         // configuracion

         json_t *jsonconfiguracion;

         jsonconfiguracion = json_object_get(json, "configuracion");
         jsonconfiguracion = json_object_get(jsonconfiguracion, "vel_scroll");

         jconfiguracion *configuracion = new jconfiguracion();

         configuracion->setvelscroll(json_number_value( jsonconfiguracion));

      return 0;
}
