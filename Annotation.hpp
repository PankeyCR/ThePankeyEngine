
#ifndef Annotation_hpp
	#define Annotation_hpp

	namespace ame{

		class Annotation{
			public:
				Annotation(){}
				virtual ~Annotation(){}

				virtual cppObjectClass* getClass(){return nullptr;}
				virtual bool instanceof(cppObjectClass* cls){return false;}

				virtual void operator=(Annotation b){}
				virtual bool operator==(Annotation b){return true;}
				virtual bool operator!=(Annotation b){return false;}
			protected:
		};

	}

#endif
