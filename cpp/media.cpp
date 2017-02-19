#include "media.h"

void Media::println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}


Media::Media() { 
		println("Media object created from nothing");
		m_name = "Default Media Name";
		}
    
Media::Media(const string name, const string path){
  println("Media object " + name + " created from " + path);
  m_name = name;
  m_path = path;
  }

Media::~Media() {
	println("Deleting Media object \"" + m_name + "\"");
	}

void Media::setName(const string name) {m_name = name;}
string Media::getName() const {return m_name;}

void Media::setPath(const string path) {m_path = path;}
string Media::getPath() const {return m_path;}

void Media::print(ostream & s/**< [in] output stream to print the info */) const{
	s << "Media object " << m_name << " (" << m_path << ")" << endl;}
