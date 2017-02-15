#pragma once
#include "video.h"
#include <cstring>

class Film : public Video{	
	private:
		unsigned int* f_chapters; /*! The length of each chapter, in seconds */
		size_t f_length;
		
	public:
		Film() : Video(){
			cout << "Film object created from nothing" << endl;
		}
		Film(const string name, const string pathName) : Video(name, pathName){
			cout << "Film object " << name << " created from " << pathName << endl ;
		}
		
		~Film() {
			cout << "Deleting Film object " ;
			cout << "\"" << m_name << "\"" << endl;
			delete[] f_chapters;
			}
		
		void setChapters(const unsigned int chapters[], const size_t length) { 
			f_chapters = new unsigned int[length];
			for(size_t i=0; i<length; i++){
				f_chapters[i] = chapters[i];
				// Debug:
				//~ cout << "Copying, i = " << i << ", src[i] = " << chapters[i];
				//~ cout << ", dest[i] = " << f_chapters[i] << endl;
				
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
			cout << "Chapters: " << endl;
			for(size_t i = 0; i<f_length; i++){
				cout << "Chapter " << i+1 << " starts at " << f_chapters[i] << endl;
			}
			cout << "End of chapters." << endl;
		}
		
};

typedef shared_ptr<Film> FilmPtr;
