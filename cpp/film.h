#pragma once
#include "video.h"
#include <cstring>

class Film : public Video{	
	private:
		unsigned int* f_chapters; /*! The length of each chapter, in seconds */
		int f_length = -1; /*! Number of chapters. */
		
		void println(const string c) const{
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		
	public:
		Film() : Video(){
			//~ println("Film object created from nothing");
		}
		Film(const string name, const string pathName) : Video(name, pathName){
			//~ println("Film object " + name + " created from " + pathName);
		}
		
		~Film() {
			//~ println("Deleting Film object \"" + m_name + "\"");
			if(f_length >= 0){
				delete[] f_chapters;
			}
		}
		
		void setChapters(const unsigned int chapters[], const int length) { 
			//If there was previously an array:
			if(f_length >= 0){
				delete[] f_chapters;
			}
			f_chapters = new unsigned int[length];
			for(int i=0; i<length; i++){
				f_chapters[i] = chapters[i];
				// Debug:
				//~ println("Copy i="+i+",src[i]="+chapters[i]);
				
			}
			f_length = length;
		}
		
		/**
		 * Returns the number of chapters and the array of chapters
		 * @param destination a pointer to the destination array
		 * @returns the number of chapters
		 */
		int getChapters(unsigned int * destination) const{
			for(int i=0; i<f_length; i++){
				destination[i] = f_chapters[i];
			}
			return f_length; 
		}
		
		int getNumberChapters() const{ return f_length; }
			
		void printChapters() const{
			println("Chapters: ");
			for(int i = 0; i<f_length; i++){
				printf("[%s:%d] ", __FILE__, __LINE__);
				cout << "Chapter " << i+1;
				cout << " starts at " << f_chapters[i] << endl;
			}
			println("End of chapters.");
		}
		
};

typedef shared_ptr<Film> FilmPtr;
