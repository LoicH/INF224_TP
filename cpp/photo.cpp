#include "photo.h"


void Photo::println(string c){
	printf("[%s:%d] ", __FILE__, __LINE__);
	cout << c << endl;
}

Photo::Photo() : Media(){
	//~ println("Photo object created from nothing");
}

Photo::Photo(const string name, const string pathName) : Media(name, pathName){
	//~ println("Photo object " + name + " created from " + pathName) ;
}



Photo::~Photo() {
	//~ println("Deleting Photo object \"" + m_name + "\"");
}


void Photo::play() const{
	system(("ristretto " + m_path).c_str());
}

void Photo::setLatitude(const float lat) {p_latitude = lat;}

float Photo::getLatitude() const {return p_latitude;}

void Photo::setLongitude(const float longi) {p_longitude = longi;}

float Photo::getLongitude() const {return p_longitude;}

string Photo::toString() const{
	return ("Photo \"" + m_name + "\" (" + m_path + ")\n");
}
