#pragma once
#include <iostream>
#include <memory>
#include <string>
//~ #include <cstdlib>

using namespace std;


/*! Class for modeling multimedia objects */

class Media {
  protected:
    string m_name;
    string m_path; /*!< Absolute path */
    
  public:
    Media() { 
		cout << "Media object created from nothing" << endl;
		m_name = "Default Media Name";
		}
    
    Media(const string name, const string path){
	  cout << "Media object " << name << " created from " << path << endl;
	  m_name = name;
	  m_path = path;
	  }

    virtual ~Media() {
		cout << "Deleting Media object ";
		cout << "\"" << m_name << "\"" << endl;
		}

    void setName(const string name) {m_name = name;}
    string getName() const {return m_name;}
    
    void setPath(const string path) {m_path = path;}
    string getPath() const {return m_path;}
    
    void print(ostream & s/**< [in] output stream to print the info */) const{
		s << "Media object " << m_name << " (" << m_path << ")" << endl;}

    virtual void play() const = 0;

};

typedef shared_ptr<Media> MediaPtr;
