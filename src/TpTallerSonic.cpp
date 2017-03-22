#include <iostream>
#include </usr/include/SDL2/SDL.h>
#include "Logger.h"

using namespace std;

int main() {

	char *file = "log.txt";

	Logger *log = new Logger(file, 2);
	string apertura = "Se abrio el archivo.";
	string cierre = "Se cerro el archivo.";



	log->addLogMessage(apertura);
	log->addLogMessage(cierre);
	return 0;
}
