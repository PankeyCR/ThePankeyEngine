
#ifndef Tpc_hpp
	#define Tpc_hpp

	namespace higgs{

		class Tpc{
			public:

				Tpc(){}
				virtual ~Tpc(){}
				
				virtual float tpc(){
					return m_tpc;
				}

				virtual float generateTpc(){
					this->m_now = System::microSeconds();

					this->m_tpc = (float)(this->m_now - this->m_prev)/1000000;
					this->m_prev = this->m_now;

					return this->m_tpc;
				}

			protected:
				long m_now = 0;
				long m_prev = 0;
				float m_tpc = 0;
		};

	}

#endif
