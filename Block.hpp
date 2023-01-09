
#ifndef Block_hpp
#define Block_hpp
#define Block_AVAILABLE

namespace ame{

class Block{
    public:
		Block(){}
		virtual ~Block(){}
		
		virtual void setCode(Note c){code = c;}
		
		virtual void operator=(Block b){code = b.code;}
		virtual bool operator==(Block b){code == b.code;}
		virtual bool operator!=(Block b){code != b.code;}
	protected:
		Note code;
};

}

#endif
