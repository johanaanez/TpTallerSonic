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
#include "jescenario.h"
#include "capas.h"
#include "jentidades.h"
#include <list>
#include <map>
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

	    //VENTANA

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

         //CONFIGURACION

         json_t *jsonconfiguracion;

         jsonconfiguracion = json_object_get(json, "configuracion");
         jsonconfiguracion = json_object_get(jsonconfiguracion, "vel_scroll");

         jconfiguracion *configuracion = new jconfiguracion();

         configuracion->setvelscroll(json_number_value( jsonconfiguracion));

         //ESCENARIO

         jescenario *escenario = new jescenario();

         json_t *jsonescenario;
         json_t *jsonesescealto;
         json_t *jsonesesceancho;
         json_t *jsonescapas;

         json_t *jsondimension;

         jsonescenario = json_object_get(json, "escenario");

         jsondimension = json_object_get(jsonescenario,"dimensiones");
         // va a ser de tipo JsonArray, las capas
         jsonescapas = json_object_get(jsonescenario, "capas");

         list<capas> capalista;

         for( int i = 0; i < json_array_size(jsonescapas); i++ ){

        	 json_t *capai;
        	 json_t *id;
        	 json_t *index_z;
             json_t *ruta_imagen;

        	 capai = json_array_get(jsonescapas, i);

        	 capas *jcapas = new capas();

        	 id = json_object_get(capai,"id");
        	 index_z = json_object_get(capai,"index_z");
        	 ruta_imagen = json_object_get(capai,"ruta_imagen");

        	 jcapas->setid(json_number_value(id));
        	 jcapas->setindex(json_number_value(index_z));
        	 jcapas->setrutaimagen(json_string_value(ruta_imagen));


             capalista.push_back(*jcapas);

         }
          // agrego la lista total al escenario
         escenario->setcapas(capalista);


         jsonesescealto = json_object_get(jsondimension,"alto");
         jsonesesceancho = json_object_get(jsondimension,"ancho");


         escenario->setalto(json_number_value(jsonesescealto));
         escenario->setancho(json_number_value(jsonesesceancho));



         //ENTIDADES(viene de escenario)
         json_t *jsonentidades;

         jsonentidades = json_object_get(jsonescenario, "entidades");

         for( int i = 0; i < json_array_size(jsonentidades); i++ ){

        	 json_t *auxi;
        	 json_t *id;
        	 json_t *tipo;
        	 json_t *color;
        	 json_t *ruta_imagen;
        	 json_t *index_z;
        	 json_t *dimensiones;
        	 json_t *coordenada;
        	 json_t *coorx;
        	 json_t *coory;

        	 auxi = json_array_get(jsonentidades, i);

        	 id = json_object_get(auxi,"id");
        	 tipo = json_object_get(auxi,"tipo");
        	 color = json_object_get(auxi,"color");
        	 dimensiones= json_object_get(auxi,"dimensiones");


        	 //la dimension puede ser un rectangulo un circulo...
        	 const char *clave;
        	 json_t *valordimension;

        	 void *iter = json_object_iter(dimensiones);
        	 //en clave obtengo el ancho,alto y radio
        	 clave = json_object_iter_key(iter);
        	 while(iter)
        	     {
        	       clave = json_object_iter_key(iter);
        	       valordimension = json_object_iter_value(iter);
                   //me muestra perfecto el valor del rectangulo y el radio

        	        cout << json_integer_value(valordimension) << endl;
        	        iter = json_object_iter_next(dimensiones, iter);
        	      }

        	 coordenada = json_object_get(auxi,"coordenada");
        	 coorx = json_object_get(coordenada,"x");
        	 coory = json_object_get(coordenada,"y");
        	 ruta_imagen = json_object_get(auxi,"ruta_imagen");
        	 index_z= json_object_get(auxi,"index_z");

        	// cout << json_integer_value(id) << endl;
        	// cout << json_string_value(tipo) << endl;
        	// cout << json_string_value(color) << endl;
        	// cout << json_integer_value(valordimension) << endl;
        	// cout << json_integer_value(coorx) << endl;
        	// cout << json_integer_value(coory) << endl;
        	// cout << json_string_value(ruta_imagen) << endl;
        	 //cout << json_integer_value(index_z) << endl;
         }

         //jentidades *entidades = new jentidades();


 //     return 0;
}

