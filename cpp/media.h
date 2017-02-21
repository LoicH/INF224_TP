#pragma once
#include <iostream>
#include <memory>
#include <string>
//~ #include <cstdlib>

using namespace std;


/** Class modeling multimedia objects */

class Media {
	private:
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c) const;
	
	protected:
	
		/** Name of the media */
		string m_name;
		
		/** Absolute or relative path */
		string m_path; 

  public:
  
	/**
	 * Default constructor
	 */
    Media();
    
    /** Creates a media object with a name and a path to the file
     * @param name: the name of the media
     * @param path: the path to the file, relative or absolute.
     */
    Media(const string name, const string path);

    virtual ~Media();

	/**
	 * Sets the name of the media
	 */
    void setName(const string name);
    
    /** 
     * Returns the name of the media
     */
    string getName() const;
    
    /**
     * Sets the path to the file represented by the object.
     */
    void setPath(const string path);
    
    /**
     * Returns the path to the file represented by the object.
     */
    string getPath() const;
    
    /**
     * Prints the representation of the object.
     * @param s: the outputstream that will print the representation
     */
    void print(ostream & s) const;

	/**
	 * Play the media
	 */
    virtual void play() const = 0;
    
    /**
     * Returns a "pretty" representation of the media 
     */
    virtual string toString() const = 0;
    
    /**
     * Returns a serialized representation of the media 
     */
    virtual string serialize() const = 0;

};

typedef shared_ptr<Media> MediaPtr;
