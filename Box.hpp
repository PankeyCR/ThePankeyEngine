
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Box)
	#define Box_hpp
#endif

#ifndef Box_hpp
#define Box_hpp
#define Box_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Mesh.hpp"

namespace ame{

class Box : public Mesh{
    public:
		Box(){
			set(1,1,1);
		}
		Box(const Box& mesh){
			triangles = mesh.triangles;
			set(1,1,1);
		}
		Box(int x, int y, int z){
			set(x,y,z);
		}
		virtual ~Box(){}
		void set(int x, int y, int z){
			//Top
			triangles.add(Triangle(Vector3f(0,0,0), Vector3f(0,1,0), Vector3f(1,1,0)));
			triangles.add(Triangle(Vector3f(0,0,0), Vector3f(1,1,0), Vector3f(1,0,0)));

			//Top
			triangles.add(Triangle(Vector3f(1,0,0), Vector3f(1,1,0), Vector3f(1,1,1)));
			triangles.add(Triangle(Vector3f(1,0,0), Vector3f(1,1,1), Vector3f(1,0,1)));

			//Top
			triangles.add(Triangle(Vector3f(1,0,1), Vector3f(1,1,1), Vector3f(0,1,1)));
			triangles.add(Triangle(Vector3f(1,0,1), Vector3f(0,1,1), Vector3f(0,0,1)));

			//Top
			triangles.add(Triangle(Vector3f(0,0,1), Vector3f(0,1,1), Vector3f(0,1,0)));
			triangles.add(Triangle(Vector3f(0,0,1), Vector3f(0,1,0), Vector3f(0,0,0)));

			//Top
			triangles.add(Triangle(Vector3f(0,1,0), Vector3f(0,1,1), Vector3f(1,1,1)));
			triangles.add(Triangle(Vector3f(0,1,0), Vector3f(1,1,1), Vector3f(1,1,0)));

			//Top
			triangles.add(Triangle(Vector3f(1,0,1), Vector3f(0,0,1), Vector3f(0,0,0)));
			triangles.add(Triangle(Vector3f(1,0,1), Vector3f(0,0,0), Vector3f(1,0,0)));
			
		}
};

}

#endif