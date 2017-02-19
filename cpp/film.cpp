#include "film.h"
#include "mediaStorage.h"
#include <sstream>

/**
 * Simple constructor.
 */
Film::Film() : Video(){
	println("Film object created from nothing");
}
		
/**
 * Sets name and path of Film object.
 * @param name: the name of the object. Must be unique.
 * @param pathName: the path to the object (relative or absolute).
 */
Film::Film(const string name, const string pathName) : Video(name, pathName){
	println("Film object " + name + " created from " + pathName);
}		


/**
 * e.g. "Film,dog,~/Videos/dog.mkv,345,3,2 43 54"
 */
Film::Film(const string serial) : Video(){
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
    string nbChaptersStr;
    getline(ss, nbChaptersStr, ',');
    
    
	setName(objectName);
	setPath(path);
	setLength(stoi(length));
	
	int nbChaptersInt = stoi(nbChaptersStr);
	
	if(nbChaptersInt > -1){
		int i;
		unsigned int chapters[nbChaptersInt];
		string chapLength;

		for(i=0; i<nbChaptersInt; i++){
			getline(ss, chapLength, ' ');
			//~ println("Chapter n°"+to_string(i)+": "+chapLength);
			chapters[i] = stoul(chapLength);
		}
		setChapters(chapters, nbChaptersInt);
	}
	
	
	
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
		result += "Chapter " + to_string(i+1);
		result += " starts at " + to_string(f_chapters[i]);
		result += "\n";
	}
	return result;
}

string Film::serialize() const{
	string result = "Film,"+m_name+","+m_path+",";
	result += to_string(v_length);
	result += ","+to_string(f_length)+",";
	int i;
	for(i=0; i<f_length; i++){
		result += to_string(f_chapters[i]) + " ";
	}
	println("result = " + result);
	return result;
}
