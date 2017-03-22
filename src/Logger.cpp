#include "Logger.h"

Logger::Logger() {
	this->nivel = 2;
}

Logger::Logger(char *fileName, int level){
	this->archivo = fileName;
	this->nivel = level;
}

Logger::Logger(int level){
	this->nivel = level;
}


void Logger::setLevel(int level)
{
    this->nivel = level;
}


int Logger::getLevel() const
{
    return nivel;
}

int Logger::validateFileName(){

	return 0;
}
int Logger::validateLevel(){
	return 0;

}

char *Logger::getArchivo() const
{
    return archivo;
}

void Logger::setArchivo(char *archivo)
{
    this->archivo = archivo;
}

int Logger::addLogMessage(string logMessage){
	if (validateFileName() == 0){
		ofstream myfile;
		myfile.open(this->archivo);

		//imprime la fecha actual con horas de usa
		time_t t = time(0);   // get time now
	    struct tm * now = localtime( & t );
	    myfile <<"["
	    	 <<	(now->tm_year + 1900) << '-'
	         << (now->tm_mon + 1) << '-'
	         <<  now->tm_mday
	         <<  " "
	         <<  now->tm_hour
	         <<  ":"
	         <<  now->tm_min
	         <<  ":"
	         <<  now->tm_sec
	         <<  "] ";

	    // imprime el nivel+ mensaje
		myfile <<"["<< this->nivel<<"] "<<" [modulo] "<<logMessage<< endl;
		myfile.close();
		return 0;
	}

	return -1;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}
