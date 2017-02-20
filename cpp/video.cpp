#include "video.h"
#include <sstream>

void Video::println(string c) const{
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}

Video::Video() : Media(){
	println("Video object created from nothing");
	v_length = 100;
}
Video::Video(const string name, const string pathName) : Media(name, pathName){
	println("Video object " + name + " created from " + pathName);
	v_length = 10;
}


/**
 * e.g. "Video,dog,~/Videos/dog.mkv,345"
 */
Video::Video(const string serial) : Media(){
	//~println("Creating an object from a serialized representation");
	stringstream ss;
    ss.str(serial);
    string className;
    getline(ss, className, ',');
    string objectName;
    getline(ss, objectName, ',');
    string path;
    getline(ss, path, ',');
    string length;
    getline(ss, length, ',');
	
	setName(objectName);
	setPath(path);
	setLength(stoi(length));
	
}


Video::~Video() {
	//~ println("Deleting Video object \"" + m_name + "\"");
}

void Video::setLength(const int length){
	v_length = length;
}


void Video::play() const{
	system(("mpv " + m_path).c_str());
}

string Video::toString() const{
	return ("Video \"" + m_name + "\" (" + m_path + ")");
}


string Video::serialize() const{
	string result = "Video,"+m_name+","+m_path+",";
	result += to_string(v_length);
	println("result = " + result);
	return result;
}
