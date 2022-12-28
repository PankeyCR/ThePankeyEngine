
#ifndef Computer_hpp
#define Computer_hpp
#define Computer_AVAILABLE

#include "cppObject.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"
#include "BaseAppState.hpp"
#include "PrintableList.hpp"
#include "ArrayList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"

#define COMPUTER_STATE_START 15

namespace ame{

struct MonkeyInstruction{
	static const ame_Byte move_value_to_reg;
};

const ame_Byte MonkeyInstruction::move_value_to_reg = 0b00000000;

class MonkeyHardware{
	public:

	using Flash = ByteArray;
	using Ram = ByteArray;
	using Instruction = ame_Byte;
	using Reg = ByteArray;

	public:
		MonkeyHardware(){}
		virtual ~MonkeyHardware(){}

		virtual Reg getRegister(int a_position){
			return m_reg_1;
		}

	public:
		Flash m_flash;
		Ram m_ram;
		Reg m_reg_1;

		Application* m_app = nullptr;
};

template<class Computer_HardWare = MonkeyHardware>
class Computer IMPLEMENTATION_BaseAppState {
	public:

		using InstructionMethod = void (*) (Computer<Computer_HardWare>*, const typename Computer_HardWare::Instruction&);

		using Computation = void (*) (Computer_HardWare*);

	public:
		Computer(){
			m_hardware = new Computer_HardWare();
		}
		virtual ~Computer(){
			delete m_hardware;
		}

		virtual Computer_HardWare* getHardware(){return this->m_hardware;}

		virtual void add(InstructionMethod a_method){
			m_instruction_event.addPointer(new InstructionMethod(a_method));
		}

		virtual void add(Computation a_method){
			m_active_computations.addPointer(new Computation(a_method));
		}

		virtual void compute(const typename Computer_HardWare::Instruction& a_instruction){
			for(int x = 0; x < m_instruction_event.getPosition(); x++){
				InstructionMethod* f_method = m_instruction_event.getByPosition(x);
				if(f_method == nullptr){
					continue;
				}
				(**f_method)(this, a_instruction);
			}
		}
		virtual void initializeState(Application* app){}

		virtual void updateState(float a_tpc){
			for(int x = 0; x < m_active_computations.getPosition(); x++){
				Computation* f_method = m_active_computations.getByPosition(x);
				if(f_method == nullptr || m_hardware == nullptr){
					continue;
				}
				(**f_method)(m_hardware);
			}
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<Computer>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Computer>::getClass() || BaseAppState::instanceof(cls);
		}
		#endif

	protected:
		PrimitiveMap<typename Computer_HardWare::Instruction, PrimitiveList<Computation>> m_computation_map;
		
		PrimitiveList<Computation> m_active_computations;
		
		PrimitiveList<InstructionMethod> m_instruction_event;

		Computer_HardWare* m_hardware = nullptr;
};

}

#endif