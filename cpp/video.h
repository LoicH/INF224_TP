#pragma once

#include "media.h"

class MediaStorage;
/**
 * Represents a video object.
 * 
 */
class Video : public Media{
	private:
		
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c) const;
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	protected:
		/** Length of the movie in seconds */
		unsigned int v_length; 
		
		/**
		 * Default constructor
		 */
		Video();
		
		/**
		 * Creates a new video with a name and a path to the file
		 * @param name: The name of the movie
		 * @param pathName: the path to the file (relative or absolute)
		 */
		Video(const string name, const string pathName);
		
		/**
		 * Creates a new video with a serialized representation of the movie
		 * @param serialized: a valid serialized representation of the movie,
		 * format: "Video,[name],[path],[length]"
		 * e.g.: "Video,dog,~/Videos/dog.mkv,345"
		 * 
		 */
		Video(const string serialized);
		
		
	public:
		
		/** Destroys the object and its components
		 */
		virtual ~Video();
		
		/** 
		 * Set the length of the movie
		 * @param length: The duration of the movie in seconds.
		 */
		void setLength(const int length);
		
		/**
		 * Starts playing the movie.
		 */
		void play() const;
		
		/**
		 * Prints a representation of the movie in the standard output.
		 */
		string toString() const;
		
		/**
		 * Serializes the object.
		 * @returns a string representing the object. 
		 *
		 * Format: "Video,[name],[path],[length]" 
		 *
		 * e.g.: "Video,dog,~/Videos/dog.mkv,345"
		 */
		string serialize() const;
};

typedef shared_ptr<Video> VideoPtr;
