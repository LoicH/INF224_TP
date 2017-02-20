#include "photo.h"
#include <sstream>

void Photo::println(string c) const{
	printf("[%s:%d] ", __FILE__, __LINE__);
	cout << c << endl;
}

Photo::Photo() : Media(){
	println("Photo object created from nothing");
}

Photo::Photo(const string name, const string pathName) : Media(name, pathName){
	println("Photo object " + name + " created from " + pathName) ;
}

/**
 * e.g. "Photo,dog,~/Photos/dog.jpg,34.5,65.4"
 */
Photo::Photo(const string serial) : Media(){
	//~println("Creating an object from a serialized representation");
	stringstream ss;
    ss.str(serial);
    string className;
    getline(ss, className, ',');
    string objectName;
    getline(ss, objectName, ',');
    string path;
    getline(ss, path, ',');
    string latitude;
    getline(ss, latitude, ',');
    string longitude;
    getline(ss, longitude, ',');
	
	setName(objectName);
	setPath(path);
	setLatitude(atof(latitude.c_str()));
	setLongitude(atof(longitude.c_str()));
	
}

Photo::~Photo() {
	//~ println("Deleting Photo object \"" + m_name + "\"");
}


void Photo::play() const{
	string cmd = "ristretto " + m_path;
	//~ println("Command: "+cmd);
	system(cmd.c_str());
}

void Photo::setLatitude(const float lat) {p_latitude = lat;}

float Photo::getLatitude() const {return p_latitude;}

void Photo::setLongitude(const float longi) {p_longitude = longi;}

float Photo::getLongitude() const {return p_longitude;}

string Photo::toString() const{
	return ("Photo \"" + m_name + "\" (" + m_path + ")");
}


string Photo::serialize() const{
	string result = "Photo,"+m_name+","+m_path+",";
	result += to_string(p_latitude)+","+to_string(p_longitude);
	println("result = " + result);
	return result;
}
