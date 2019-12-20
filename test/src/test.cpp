/*
 * test.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: sidd
 */
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Movie
{
public:
	Movie();
	Movie(int i, float r): id(i), rating(r) {  }
	~Movie() { /*cout << "Deleting instance of t object [ " << id << ", " << rating << "]" << endl;*/ }
	int getID() { return id; }
	void set(int i) { id = i; }
	float getRating() { return rating; }
	void setRating(float r) { rating = r; }
	void addToRelatedMovies(Movie& aMovie) { relatedMovies.push_back(&aMovie); }
	vector<Movie*>& getRelatedMovies() { return relatedMovies; }
protected:
	int id;
	float rating;
	vector<Movie> relatedMovies;
};

void printMovie(Movie& aMovie)
{
	cout << "( " << aMovie.getID() << ", " << aMovie.getRating() << ")" << endl;
}

bool cycleDetected(Movie& aMovie, map<int,Movie*>& movieCycleDetector)
{
	pair<map<int,Movie*>::iterator, bool> ret;
	ret = movieCycleDetector.insert(pair<int,Movie*> (aMovie.getID(),&aMovie));
	return !ret.second;
}

void printAllRelatedMoviesHelper(Movie& aMovie, map<int,Movie*>& movieCycleDetector, list<Movie*>& relatedMovieList)
{
	vector<Movie>::iterator it;

	if(!cycleDetected(aMovie, movieCycleDetector))
	{
		//printMovie(aMovie);
		relatedMovieList.push_back(&aMovie);
		for(it = aMovie.getRelatedMovies().begin(); it != aMovie.getRelatedMovies().end(); ++it)
		{
			printAllRelatedMoviesHelper(**it, movieCycleDetector, relatedMovieList);
		}
	}
}
bool comareRating(Movie* Movie1, Movie* Movie2)
{
	if(Movie1 && Movie2)
	{
		return Movie1->getRating() > Movie2->getRating();
	}
	else
		return false;
}

void printAllRelatedMovies(Movie& aMovie, int N)
{
	map<int,Movie*> movieCycleDetector;
	list<Movie*> relatedMovieList;
	list<Movie*>::iterator it;

	printAllRelatedMoviesHelper(aMovie, movieCycleDetector, relatedMovieList);
	relatedMovieList.remove(&aMovie);
	relatedMovieList.sort(comareRating);
	int i = 0;
	for (it = relatedMovieList.begin(); it != relatedMovieList.end(); ++it)
	{
		if(i < N)
		{
			printMovie(**it);
		}
		i++;
	}
}

void printListOfTopRelated(Movie& aMovie, int N)
{
	printAllRelatedMovies(aMovie, N);
}

int main()
{
	/*		(1,2.3)
	 * 		/	  \
	 *   (2, 4.5)  (3, 1.6)
	 *      \	   /
	 *       (4,3.9)
	 */
	Movie a(1,2.3);
	Movie b(2,4.5);
	Movie c(3,1.6);
	Movie d(4,3.9);

	b.addToRelatedMovies(d);
	c.addToRelatedMovies(d);
	a.addToRelatedMovies(b);
	a.addToRelatedMovies(c);

	printListOfTopRelated(a, 5);
}
