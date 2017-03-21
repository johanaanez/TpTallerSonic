/*
 * parseadorJson.cpp
 *
 *  Created on: 20 mar. 2017
 *      Author: pato
 */

#include <iostream>
#include </usr/include/SDL2/SDL.h>
#include <jansson.h>
#include "jventana.h"
#include "jconfiguracion.h"
#include "jescenario.h"
#include "capas.h"
#include "jentidades.h"
#include <list>
#include "parseadorJson.h"
#include "dimensiones.h"
#include "jrectangulo.h"
#include "jcirculo.h"

namespace std {

parseadorJson::parseadorJson() {
	// TODO Auto-generated constructor stub

}

parseadorJson::~parseadorJson() {
	// TODO Auto-generated destructor stub
}

json_t parseadorJson::getjson(){
   return raiz;
}
void parseadorJson::setjson(json_t aux){
  raiz = aux;
}

json_t* parseadorJson::parsearArchivoseg(char* nombreArchivo){
	json_t *json;
		 json_error_t error;

		 json = json_load_file(nombreArchivo,0,&error);

		 return json;
}

jventana* parseadorJson::cargarVentana(json_t* raiz){

    json_t *jsonventana;
    json_t *jsonventanaalto;
    json_t *jsonventanaancho;

    jsonventana = json_object_get(raiz, "ventana");
    jsonventana = json_object_get(jsonventana,"dimensiones");

    jsonventanaalto = json_object_get(jsonventana,"alto");
    jsonventanaancho = json_object_get(jsonventana,"ancho");


    jventana *ventana = new jventana();

    ventana->setalto(json_number_value(jsonventanaalto));
    ventana->setancho(json_number_value(jsonventanaancho));

    return ventana;

}

jconfiguracion* parseadorJson::cargarConfiguracion(json_t* raiz){

	 json_t *jsonconfiguracion;

	 jsonconfiguracion = json_object_get(raiz, "configuracion");
	 jsonconfiguracion = json_object_get(jsonconfiguracion, "vel_scroll");

	 jconfiguracion *configuracion = new jconfiguracion();

	 configuracion->setvelscroll(json_number_value( jsonconfiguracion));

	 return configuracion;
}

jescenario* parseadorJson::cargarEscenario(json_t* raiz){

	json_t *jsonescenario;

	json_t *jdimensiones;
	json_t *jd_alto;
	json_t *jd_ancho;

	json_t *jcapas;

	jescenario *escenario = new jescenario();

	jsonescenario = json_object_get(raiz, "escenario");
	jdimensiones = json_object_get(jsonescenario,"dimensiones");
	jd_alto = json_object_get(jdimensiones,"alto");
	jd_ancho = json_object_get(jdimensiones,"ancho");

	escenario->setalto(json_number_value(jd_alto));
	escenario->setancho(json_number_value(jd_ancho));

	//cout<<escenario->getalto()<<endl;
	//cout<<escenario->getancho()<<endl;

	jcapas = json_object_get(jsonescenario, "capas");

	//lista de capas
	list<capas> capalista;

	for( int i = 0; i < json_array_size(jcapas); i++ ){

	   json_t *capai;
	   json_t *id;
	   json_t *index_z;
	   json_t *ruta_imagen;

	   capai = json_array_get(jcapas, i);

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
	  //ENTIDADES (viene de escenario)

	  json_t *jsonentidades;

	  jsonentidades = json_object_get(jsonescenario, "entidades");

	  list<jentidades> listaentidades;
	   for( int i = 0; i < json_array_size(jsonentidades); i++ ){

		   json_t *entidadi;

		   json_t *id;
		   json_t *tipo;
		   json_t *color;
		   json_t *ruta_imagen;
		   json_t *index_z;
		   json_t *dimensiones;
		   json_t *ancho;
		   json_t *alto;
		   json_t *radio;
		   json_t *coordenada;
		   json_t *coorx;
		   json_t *coory;

	              //voy creando nuevos objetos entidades
	       jentidades *entidades = new jentidades();

	       entidadi = json_array_get(jsonentidades, i);

	       id = json_object_get(entidadi,"id");
	       entidades->setid(json_number_value(id));

	       tipo = json_object_get(entidadi,"tipo");
	       entidades->settipo(json_string_value(tipo));

	       color = json_object_get(entidadi,"color");
	       entidades->setcolor(json_string_value(color));

	       dimensiones= json_object_get(entidadi,"dimensiones");
	              // devuelve 0...si eel elemento no tiene algun atributo
	       ancho = json_object_get(dimensiones,"ancho");
	       alto = json_object_get(dimensiones,"alto");
	       radio = json_object_get(dimensiones,"radio");

	       if (strcmp(json_string_value(tipo), "rectangulo") == 0){

	        //   jrectangulo* rectangulo = new jrectangulo();
	                  //entidades->dim->setalto(json_number_value(alto));
	                  //entidades->dim->setancho(json_number_value(ancho));
	            	  //cout<<"ENTRE AL IF RECTANGULO"<<endl;
	        }

	       if(strcmp(json_string_value(tipo),"circulo") == 0){
	                 // entidades->dim->setradio(json_number_value(radio));
	            	//  cout<<"ENTRE AL IF CIRCULO"<<endl;
	        }

	        coordenada = json_object_get(entidadi,"coordenada");
	        coorx = json_object_get(coordenada,"x");
	        entidades->setcoorx(json_number_value(coorx));

	        coory = json_object_get(coordenada,"y");
	        entidades->setcoory((json_number_value(coory)));

	        ruta_imagen = json_object_get(entidadi,"ruta_imagen");
	        entidades->setruta(json_string_value(ruta_imagen));

	        index_z= json_object_get(entidadi,"index_z");
	        entidades->setindex(json_number_value(index_z));

	        listaentidades.push_back(*entidades);

	              //  cout<<entidades->getid()<<endl;
	              //  cout<<entidades->gettipo()<<endl;
	              //  cout<<entidades->getcolor()<<endl;
	                //FALTA DIMENSION
	              //  cout<<entidades->getcoorx()<<endl;
	             //   cout<<entidades->getcoory()<<endl;
	             //   cout<<entidades->getruta()<<endl;
	             //   cout<<entidades->getindex()<<endl;
	          }
	           escenario->setentidades(listaentidades);

	           return escenario;

}

void parseadorJson::parsearArchivo(char* nombreArchivo){
	//TODO: Ir dividiendo el parseador json en pedacitos logicos
	//ue este pareseador en vez de void devuelva una clase jarchivo con todo cargado

	 json_t *json;
	 json_error_t error;

	 json = json_load_file(nombreArchivo,0,&error);


	  if(!json) {
	   /* the error variable contains error information */

	   cout << "!!! hay  probremas!!!" << endl; // prints !!!Hello World!!!
	   cout << error.text << endl;
}


	    //VENTANA
        jventana *ventana = this->cargarVentana(json);
        //cout<<ventana->getancho()<<endl;
        //cout<<ventana->getalto()<<endl;

        //CONFIGURACION

        json_t *jsonconfiguracion;

        jsonconfiguracion = json_object_get(json, "configuracion");
        jsonconfiguracion = json_object_get(jsonconfiguracion, "vel_scroll");

        jconfiguracion *configuracion = new jconfiguracion();

        configuracion->setvelscroll(json_number_value( jsonconfiguracion));

        //cout<<configuracion->getvelscroll()<<endl;

        //ESCENARIO

        json_t *jsonescenario;

        json_t *jdimensiones;
        json_t *jd_alto;
        json_t *jd_ancho;

        json_t *jcapas;

        jescenario *escenario = new jescenario();

        jsonescenario = json_object_get(json, "escenario");
        jdimensiones = json_object_get(jsonescenario,"dimensiones");
        jd_alto = json_object_get(jdimensiones,"alto");
        jd_ancho = json_object_get(jdimensiones,"ancho");

        escenario->setalto(json_number_value(jd_alto));
        escenario->setancho(json_number_value(jd_ancho));

        //cout<<escenario->getalto()<<endl;
        //cout<<escenario->getancho()<<endl;

        jcapas = json_object_get(jsonescenario, "capas");

        //lista de capas
        list<capas> capalista;

        for( int i = 0; i < json_array_size(jcapas); i++ ){
       	 json_t *capai;

       	 json_t *id;
       	 json_t *index_z;
       	 json_t *ruta_imagen;

       	 capai = json_array_get(jcapas, i);

       	 capas *jcapas = new capas();

       	 id = json_object_get(capai,"id");
       	 index_z = json_object_get(capai,"index_z");
       	 ruta_imagen = json_object_get(capai,"ruta_imagen");

       	 jcapas->setid(json_number_value(id));
       	 jcapas->setindex(json_number_value(index_z));
       	 jcapas->setrutaimagen(json_string_value(ruta_imagen));

           // cout<<jcapas->getid()<<endl;
          //  cout<<jcapas->getindex()<<endl;
          //  cout<<jcapas->getrutaimagen()<<endl;

       	 capalista.push_back(*jcapas);

        }
        // agrego la lista total al escenario
         escenario->setcapas(capalista);
        //ENTIDADES (viene de escenario)

         json_t *jsonentidades;

         jsonentidades = json_object_get(jsonescenario, "entidades");

         list<jentidades> listaentidades;
         for( int i = 0; i < json_array_size(jsonentidades); i++ ){

             json_t *entidadi;

             json_t *id;
             json_t *tipo;
             json_t *color;
             json_t *ruta_imagen;
             json_t *index_z;
             json_t *dimensiones;
             json_t *ancho;
             json_t *alto;
             json_t *radio;
             json_t *coordenada;
             json_t *coorx;
             json_t *coory;

             //voy creando nuevos objetos entidades
             jentidades *entidades = new jentidades();

             entidadi = json_array_get(jsonentidades, i);

             id = json_object_get(entidadi,"id");
             entidades->setid(json_number_value(id));

             tipo = json_object_get(entidadi,"tipo");
             entidades->settipo(json_string_value(tipo));

             color = json_object_get(entidadi,"color");
             entidades->setcolor(json_string_value(color));

             dimensiones= json_object_get(entidadi,"dimensiones");
             // devuelve 0...si eel elemento no tiene algun atributo
             ancho = json_object_get(dimensiones,"ancho");
             alto = json_object_get(dimensiones,"alto");
             radio = json_object_get(dimensiones,"radio");

             if (strcmp(json_string_value(tipo), "rectangulo") == 0){

           	    jrectangulo* rectangulo = new jrectangulo();
                rectangulo->setalto(json_number_value(alto));
                rectangulo->setancho(json_number_value(ancho));


              }

             if(strcmp(json_string_value(tipo),"circulo") == 0){
            	  jcirculo* circulo = new jcirculo();
            	  circulo->setradio(json_number_value(radio));


              }

             coordenada = json_object_get(entidadi,"coordenada");
             coorx = json_object_get(coordenada,"x");
             entidades->setcoorx(json_number_value(coorx));

             coory = json_object_get(coordenada,"y");
             entidades->setcoory((json_number_value(coory)));

             ruta_imagen = json_object_get(entidadi,"ruta_imagen");
             entidades->setruta(json_string_value(ruta_imagen));

             index_z= json_object_get(entidadi,"index_z");
             entidades->setindex(json_number_value(index_z));

             listaentidades.push_back(*entidades);

               cout<<entidades->getid()<<endl;
               cout<<entidades->gettipo()<<endl;
               cout<<entidades->getcolor()<<endl;
               //FALTA DIMENSION
               cout<<entidades->getcoorx()<<endl;
               cout<<entidades->getcoory()<<endl;
               cout<<entidades->getruta()<<endl;
               cout<<entidades->getindex()<<endl;
         }
          escenario->setentidades(listaentidades);


}

} /* namespace std */
