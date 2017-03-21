/*
 * parseadorJson.h
 *
 *  Created on: 20 mar. 2017
 *      Author: pato
 */

#ifndef PARSEADORJSON_H_
#define PARSEADORJSON_H_

#include <string>

namespace std {

class parseadorJson {
public:
	parseadorJson();
	virtual ~parseadorJson();
	void parsearArchivo(char*  nombreArchivo);
	json_t* parsearArchivoseg(char*  nombreArchivo);
	jventana* cargarVentana(json_t* raiz);
	jconfiguracion* cargarConfiguracion(json_t* raiz);
	jescenario* cargarEscenario(json_t* raiz);
	json_t getjson();
	void setjson(json_t);

private:
   //	jventana* cargarVentana(json_t* raiz);
	json_t raiz;
};

} /* namespace std */

#endif /* PARSEADORJSON_H_ */
