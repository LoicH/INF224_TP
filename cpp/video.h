#pragma once

#include "media.h"

class MediaStorage;

class Video : public Media{
	private:
		unsigned int v_length; /*! Length in seconds */
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	protected:
		Video() : Media(){
			//~ println("Video object created from nothing");
			v_length = 100;
		}
		Video(const string name, const string pathName) : Media(name, pathName){
			//~ println("Video object " + name + " created from " + pathName);
			v_length = 10;
		}
		
		
		
	public:
		
		virtual ~Video() {
			//~ println("Deleting Video object \"" + m_name + "\"");
		}
		
		void play() const{
			system(("vlc " + m_path).c_str());
		}
		
		
	
};

typedef shared_ptr<Video> VideoPtr;
