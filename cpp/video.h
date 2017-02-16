#pragma once

#include "media.h"

class Video : public Media{
	private:
		unsigned int v_length; /*! Length in seconds */
		
		void println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			println(c);
		}
		
	public:
		Video() : Media(){
			//~ println("Video object created from nothing");
			v_length = 100;
		}
		Video(const string name, const string pathName) : Media(name, pathName){
			//~ println("Video object " + name + " created from " + pathName);
			v_length = 10;
		}
		
		virtual ~Video() {
			println("Deleting Video object") ;
			println("\"" + m_name + "\"");
		}
		
		void play() const{
			system(("vlc " + m_path).c_str());
		}
		
		
	
};

typedef shared_ptr<Video> VideoPtr;
