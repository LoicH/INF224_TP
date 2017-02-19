#pragma once
#include <iostream>
#include <memory>
#include <string>
//~ #include <cstdlib>

using namespace std;


/*! Class modeling multimedia objects */

class Media {
	private:
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c);
	
	protected:
		string m_name;
		string m_path; /*!< Absolute or relative path */

  public:
    Media();
    
    Media(const string name, const string path);

    virtual ~Media();

    void setName(const string name);
    string getName() const;
    
    void setPath(const string path);
    string getPath() const;
    
    void print(ostream & s) const;

    virtual void play() const = 0;
    
    virtual string toString() const = 0;

};

typedef shared_ptr<Media> MediaPtr;
