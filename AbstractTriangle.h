

#ifndef AbstractTriangle_h
#define AbstractTriangle_h


class AbstractTriangle : public Collidable {
    public:
		Vector3f *get1();
		Vector3f *get2();
		Vector3f *get3();
		void set(Vector3f *v1, Vector3f *v2, Vector3f *v3);

		int collideWith(Collidable *other, CollisionResults *results){
			return other->collideWith(this, results);
		}

    
	private:	
};

#endif 
