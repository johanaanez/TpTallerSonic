/*
 * Logger.cpp
 *
 *  Created on: 18/03/2017
 *      Author: joha
 */

#include "Logger.h"

Logger::Logger() {
	this->nivel = 2;
}

Logger::Logger(string fileName, int level){
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

int Logger::addLogMessage(string logMessage){
	if (validateFileName() == 0){
		ofstream myfile;
		time_t t = time(NULL);
		char *dateTime;
		strftime(dateTime, 100, "%d/%m/%Y %T", localtime(&t));
		myfile.open("file");
		myfile << "["<< this->nivel<< "] "<<dateTime << logMessage;
		myfile.close();
		return 0;
	}

	return -1;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}
