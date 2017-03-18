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

	     json_t *jsonprueba;
	     jsonprueba = json_object_get(json, "prueba");
		 cout <<  json_number_value(jsonprueba)<< endl;

		 jsonprueba = json_object_get(json, "configuracion");
		 jsonprueba = json_object_get(jsonprueba, "vel_scroll");
		 cout <<  json_number_value(jsonprueba)<< endl;

		//json_string_value();

	    for( int i = 0; i < json_array_size(json); i++ )
	    {
		  json_t *data; // data tiene el tamaño de todo el json parece
          json_t *ventana;
          json_t *configuracion;
          json_t *entidades;
		  data = json_array_get( json, i );

	  }



      return 0;
}
