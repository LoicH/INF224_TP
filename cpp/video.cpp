#include "video.h"

void Video::println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}

Video::Video() : Media(){
	//~ println("Video object created from nothing");
	v_length = 100;
}
Video::Video(const string name, const string pathName) : Media(name, pathName){
	//~ println("Video object " + name + " created from " + pathName);
	v_length = 10;
}


Video::~Video() {
	//~ println("Deleting Video object \"" + m_name + "\"");
}

void Video::play() const{
	system(("vlc " + m_path).c_str());
}

string Video::toString() const{
	return ("Video \"" + m_name + "\" (" + m_path + ")\n");
}
