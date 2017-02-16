#pragma once
#include "video.h"
#include <cstring>

class Film : public Video{	
	private:
		unsigned int* f_chapters; /*! The length of each chapter, in seconds */
		size_t f_length;
		
		void println(const string c) const{
			printf("[%s:%d] ", __FILE__, __LINE__);
			println(c);
		}
		
	public:
		Film() : Video(){
			//~ println("Film object created from nothing");
		}
		Film(const string name, const string pathName) : Video(name, pathName){
			//~ println("Film object " + name + " created from " + pathName);
		}
		
		~Film() {
			println("Deleting Film object \"" + m_name + "\"");
			delete[] f_chapters;
			}
		
		void setChapters(const unsigned int chapters[], const size_t length) { 
			f_chapters = new unsigned int[length];
			for(size_t i=0; i<length; i++){
				f_chapters[i] = chapters[i];
				// Debug:
				//~ println("Copy i="+i+",src[i]="+chapters[i]);
				
			}
			f_length = length;
			printChapters();
		}
		
		size_t getChapters(unsigned int * destination) const{
			for(size_t i=0; i<f_length; i++){
				destination[i] = f_chapters[i];
			}
			return f_length; 
		}
		
		size_t getNumberChapters() const{ return f_length; }
			
		void printChapters() const{
			println("Chapters: ");
			for(size_t i = 0; i<f_length; i++){
				println("Chapter " + i+1 + " starts at " + f_chapters[i]);
			}
			println("End of chapters.");
		}
		
};

typedef shared_ptr<Film> FilmPtr;
