#ifndef _SCENE_H_
#define _SCENE_H_

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

const int MAX_SCENE_SIZE = 100;
class Scene
{
private:
	Shape** objects;
	int size;
public:
	Scene() : size(0)
	{
		objects = new Shape*[MAX_SCENE_SIZE];
	}
	
	bool add(Shape* s)
	{
		if (size < MAX_SCENE_SIZE)
		{
			objects[size++] = s;
			return true;
		}
		else
			return false;
	}
	
	void clear()
	{
		for(int i = 0; i < size; i++)
			delete objects[i];
		size = 0;
	}
	
	void draw()
	{
		cout << " ************ Drwaing Scene ************ " << endl;
		for(int i = 0; i < size; i++)
			objects[i]->draw();
			
		cout << " *************************************** "<< endl;
	}
	
	virtual ~Scene()
	{
		clear();
		delete[] objects;
	}
	
	

};



#endif