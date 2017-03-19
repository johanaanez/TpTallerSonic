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

           //  cout<<jcapas->getid()<<endl;
           //  cout<<jcapas->getindex()<<endl;
           //  cout<<jcapas->getrutaimagen()<<endl;
          //  escenario->setcapas(jcapas);
             capalista.push_back(*jcapas);

         }
          // agrego la lista total al escenario
         escenario->setcapas(capalista);


         jsonesescealto = json_object_get(jsondimension,"alto");
         jsonesesceancho = json_object_get(jsondimension,"ancho");


         escenario->setalto(json_number_value(jsonesescealto));
         escenario->setancho(json_number_value(jsonesesceancho));

         //cout << escenario->getalto() << endl;
         //cout << escenario->getancho() << endl;

         jentidades *entidades = new jentidades();

      return 0;
}
