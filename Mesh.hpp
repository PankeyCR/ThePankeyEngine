
#include "pankey_Enviroment.hpp"

#if defined(DISABLE_Mesh)
	#define Mesh_hpp
#endif

#ifndef Mesh_hpp
#define Mesh_hpp
#define Mesh_AVAILABLE

#ifndef pankey_Enviroment_Defined

#endif

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "SD.h"
	#include "Arduino.h"
#endif

#include "Triangle.hpp"
#include "PrimitiveList.hpp"
#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "LinkedList.hpp"
#include "CommandReader.hpp"

namespace pankey{

class Mesh : public Printable{
    public:
		PrimitiveList<Triangle> triangles;
		Mesh(){}
		Mesh(const Mesh& mesh){
			triangles = mesh.triangles;
		}
		virtual ~Mesh(){}
		
		size_t printTo(Print& p) const{
			size_t t = 0;
			for(int x = 0; x < triangles.getPosition(); x++){
				Triangle triangle = triangles[x];
				p.print(triangle);
				t += sizeof(triangle);
				if(x != triangles.getPosition() - 1){
					p.print('-');
				}
			}
			return t;
		}
		
		void add(Triangle triangle){
			triangles.add(triangle);
		}
		
		void add(Vector3f vec_0, Vector3f vec_1, Vector3f vec_2){
			triangles.add(Triangle(vec_0, vec_1, vec_2));
		}
		
		void set(int tri, int point, Vector3f vec){
			if(tri >= triangles.getPosition()){
				return;
			}
			triangles[tri].set(point, vec);
		}
		
		Triangle& operator[](int tri){
			return triangles[tri];
		}
		
		bool loadOBJ(Note file){
			DefaultMonkeyFile<SDFileSystemClass> f = DefaultMonkeyFile<SDFileSystemClass>(SD);
			if(!f.isOpen()){
				return false;
			}
			triangles.resetDelete();
			
			LinkedList<Vector3f> verts;
			
			Note text = f.read(file);
			CommandReader reader;
			
			int size = reader.getEnterSize();
			for(int x = 0; x < size; x++){
				Note line = reader.getLine(x);
				if(line[0] == 'v'){
					Note argument = reader.getArgument(x);
					float xx = reader.split(argument, 0, ' ').toFloat();
					float yy = reader.split(argument, 1, ' ').toFloat();
					float zz = reader.split(argument, 2, ' ').toFloat();
					verts.add(Vector3f(xx,yy,zz));
				}
				if(line[0] == 'f'){
					Note argument = reader.getArgument(x);
					Note f_1 = reader.split(argument, 0, ' ');
					Note f_2 = reader.split(argument, 1, ' ');
					Note f_3 = reader.split(argument, 2, ' ');
					
					int f_x = reader.split(f_1, 0, "//").toInt();
					int f_y = reader.split(f_2, 0, "//").toInt();
					int f_z = reader.split(f_3, 0, "//").toInt();
					triangles.add(Triangle(verts[f_x - 1], verts[f_y - 1], verts[f_z - 1]));
				}
			}
			return true;
		}

};

}

#endif