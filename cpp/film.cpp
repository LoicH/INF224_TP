#include "film.h"
#include "mediaStorage.h"


/**
 * Simple constructor.
 */
Film::Film() : Video(){
	//~ println("Film object created from nothing");
}
		
/**
 * Sets name and path of Film object.
 * @param name: the name of the object. Must be unique.
 * @param pathName: the path to the object (relative or absolute).
 */
Film::Film(const string name, const string pathName) : Video(name, pathName){
	//~ println("Film object " + name + " created from " + pathName);
}		

/**
 * Used to log output.
 * @param c: the string to print. Should not contain newlines
 */
void Film::println(const string c) const{
	printf("[%s:%d] ", __FILE__, __LINE__);
	cout << c << endl;
}
		
/**
 * Destroys the object and its members.
 */
Film::~Film() {
	//~ println("Deleting Film object \"" + m_name + "\"");
	if(f_length >= 0){
		delete[] f_chapters;
	}
}


void Film::setChapters(const unsigned int chapters[], const int length) { 
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


int Film::getChapters(unsigned int * destination) const{
	for(int i=0; i<f_length; i++){
		destination[i] = f_chapters[i];
	}
	return f_length; 
}

int Film::getNumberChapters() const{ return f_length; }
	
void Film::printChapters() const{
	println("Chapters: ");
	for(int i = 0; i<f_length; i++){
		printf("[%s:%d] ", __FILE__, __LINE__);
		cout << "Chapter " << i+1;
		cout << " starts at " << f_chapters[i] << endl;
	}
	println("End of chapters.");
}

string Film::toString() const{
	string result = "Film \"" + m_name + "\" (" + m_path + ")\n";
	for(int i = 0; i<f_length; i++){
		result += "Chapter " + i+1;
		result += " starts at " + f_chapters[i];
		result += "\n";
	}
	return result;
}
