#ifndef GameBuilder_h
#define GameBuilder_h

namespace ame{

template <class Building>
class GameBuilder {
	public:
		virtual Building* build();
    
	private:
};

}

#endif