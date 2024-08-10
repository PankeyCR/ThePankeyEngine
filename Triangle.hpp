
#ifndef Triangle_hpp
#define Triangle_hpp

#include "Vector3f.hpp"

namespace higgs{

class Triangle : public Printable{
    public:
		Triangle(){}
		Triangle(const Triangle& triangle){
			point_1 = triangle.point_1;
			point_2 = triangle.point_2;
			point_3 = triangle.point_3;
		}
		Triangle(Vector3f v1, Vector3f v2, Vector3f v3){
			point_1 = v1;
			point_2 = v2;
			point_3 = v3;
		}
		virtual ~Triangle(){}
		
		size_t printTo(Print& p) const{
			p.print(point_1);p.print(';');p.print(point_2);p.print(';');p.print(point_3);
			return 	sizeof(point_1) + sizeof(point_2) + sizeof(point_3);
		}
		
		Vector3f get1(){return point_1;}
		Vector3f get2(){return point_2;}
		Vector3f get3(){return point_3;}
		void set(int point, Vector3f v){
			if(point == 0){
				point_1 = v;
			}
			if(point == 1){
				point_2 = v;
			}
			if(point == 2){
				point_3 = v;
			}
		}
		void set(Vector3f v1, Vector3f v2, Vector3f v3){
			point_1 = v1;
			point_2 = v2;
			point_3 = v3;
		}
		virtual Triangle& operator=(const Triangle& t){
			point_1 = t.point_1;
			point_2 = t.point_2;
			point_3 = t.point_3;
			return *this;
		}
		virtual bool operator==(Triangle t){
			return 	point_1 == t.point_1 &&
					point_2 == t.point_2 &&
					point_3 == t.point_3;
		}
		
		virtual bool operator!=(Triangle t){
			return 	point_1 == t.point_1 &&
					point_2 == t.point_2 &&
					point_3 == t.point_3;
		}
		
		Vector3f& operator[](int p){
			if(p == 0){
				return point_1;
			}
			if(p == 1){
				return point_2;
			}
			if(p == 2){
				return point_3;
			}
			return point_1;
		}

		// int collideWith(Collidable *other, CollisionResults *results){
			// return other->collideWith(this, results);
		// }
	private:
		Vector3f point_1;
		Vector3f point_2;
		Vector3f point_3;
		wchar_t sym;
		short col;
}; 

}

#endif