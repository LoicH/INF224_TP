#pragma once

#include "media.h"

class Video : public Media{
	private:
		unsigned int v_length; /*! Length in seconds */
		
	public:
		Video() : Media(){
			cout << "Video object created from nothing" << endl;
			v_length = 100;
		}
		Video(const string name, const string pathName) : Media(name, pathName){
			cout << "Video object " << name << " created from " << pathName << endl ;
			v_length = 10;
		}
		
		virtual ~Video() {cout << "Deleting Video object " << m_name << endl;}
		
		void play() const{
			system(("vlc " + m_path).c_str());
		}
	
};
