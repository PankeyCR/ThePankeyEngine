
#ifndef ClassTYPE_hpp
	#define ClassTYPE_hpp

	namespace pankey{
		/*
			BC = is the base class that represents all classes
			IC = is the intance of the base class
			O = is the object
		*/
		template<class BC, class IC, class O>
		struct ClassTYPE{
			using CLASS_TYPE = BC*;

			static CLASS_TYPE type;
			
			static CLASS_TYPE get(){return type;}
		};

		template<class BC, class IC, class O>
		BC* ClassTYPE<BC,IC,O>::type = new IC();

	}

#endif