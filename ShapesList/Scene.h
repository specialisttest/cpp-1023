#ifndef _SCENE_H_
#define _SCENE_H_

#include <iostream>
#include "List.h"
#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"

using std::cout;
using std::endl;

class Scene
{
private:
	List<Shape>* list;
public:
	Scene() 
	{
		this->list = new List<Shape>;
	}
	
	bool add(Shape* s)
	{
		list->add(s);
	}
	
	void clear()
	{
		list->clear();
	}
	
	void draw()
	{
		cout << " ************ Drwaing Scene ************ " << endl;
		list->start();
		Shape* s;
		while ( (s = list->next()) != nullptr)
			s->draw();
			
		cout << " *************************************** "<< endl;
	}
	
	void scale(double factor)
	{
		list->start();
		Shape* s;
		while ( (s = list->next()) != nullptr) {
			IScaleable* sc = dynamic_cast<IScaleable*>(s);
			if (sc != nullptr)
				sc->scale(factor);
		}
	}
	void moveBy(int dx, int dy)
	{
		list->start();
		Shape* s;
		while ( (s = list->next()) != nullptr) {
			IMoveable* sc = dynamic_cast<IMoveable*>(s);
			if (sc != nullptr)
				sc->moveBy(dx,dy);
		}
	}
	
	virtual ~Scene()
	{
		delete list;
	}
	
	

};



#endif