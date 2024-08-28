
#ifndef Button_hpp
	#define Button_hpp

	namespace pankey{
		
	class Button {
		private:
		
		public:
			virtual bool isPressed()=0;
			virtual bool isReleased()=0;
			virtual bool isClick()=0;
	};

	}

#endif