#pragma once
#include "video.h"
#include <cstring>

class MediaStorage;

/**
 * Represents a movie, with chapters.
 */

class Film : public Video{	
	private:
		/** The length of each chapter, in seconds */
		unsigned int* f_chapters; 
		
		/** Number of chapters. 
		 *
		 * Default value: -1 */
		int f_length = -1; 
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(const string c) const;
		
		/** 
		 * Default constructor
		 */
		Film();
		
		/**
		 * Creates a new film object.
		 * @param name: the name of the object. Must be unique.
		 * @param pathName: the path to the object (relative or absolute).
		 */
		Film(const string, const string);
		
		/**
		 * Creates a new film object from a serialized representation. 
		 *
		 * Format: "Film,[name],[path],[length],[n],[durations]" 
		 *
		 * where *n* is the number of chapters and *durations* is the 
		 * list of the durations of each chapter, separated by the space
		 * character.
		 * e.g.: "Film,dog,~/Videos/dog.mkv,345,3,2 43 54"
		 */
		Film(const string serialized);
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	public:
		
		/**
		 * Destroys the object and its members.
		 */
		~Film() ;
		
		/**
		* Sets the length and number of chapters.
		* @param chapters: the length of each chapter in seconds
		* @param length: the number of chapters
		*/
		void setChapters(const unsigned int chapters[], const int length);
		
		/**
		 * Returns the number of chapters and the array of chapters
		 * @param destination a pointer to the destination array
		 * @returns the number of chapters
		 */
		int getChapters(unsigned int * destination) const;
		
		/**
		 * Returns the number of chapters
		 */
		int getNumberChapters() const;
		
		
		/**
		 * Prints each chapter and its length.
		 */
		void printChapters() const;
		
		/**
		 * Prints a representation of the film in the standard output.
		 */
		string toString() const;
		
		/**
		 * Serializes the object.
		 * @returns a string representing the object. 
		 *
		 * Format: "Film,[name],[path],[length],[n],[durations]" 
		 *
		 * where *n* is the number of chapters and *durations* is the 
		 * list of the durations of each chapter, separated by the space
		 * character.
		 * e.g.: "Film,dog,~/Videos/dog.mkv,345,3,2 43 54"
		 */
		string serialize() const;

};


typedef shared_ptr<Film> FilmPtr;
