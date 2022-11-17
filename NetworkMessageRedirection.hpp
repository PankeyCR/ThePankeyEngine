
#ifndef CONFIGURATION_NetworkMessageRedirection_hpp
#define CONFIGURATION_NetworkMessageRedirection_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_NetworkMessageRedirection)
		#define NetworkMessageRedirection_hpp
	#endif
#endif

#ifndef NetworkMessageRedirection_hpp
#define NetworkMessageRedirection_hpp
#define NetworkMessageRedirection_AVAILABLE

#include "Command.hpp"
#include "SerialNetwork.hpp"
#include "NoteHelper.hpp"
#include "Class.hpp"

namespace ame{

class NetworkMessageRedirection : public Command<Note>{
    public:
		NetworkMessageRedirection(){}
		NetworkMessageRedirection(SerialNetwork* c_serialNetwork){
			m_serialNetwork = c_serialNetwork;
		}
		virtual ~NetworkMessageRedirection(){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<NetworkMessageRedirection>::getClass();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<NetworkMessageRedirection>::getClass();
		}
		#endif
		
		virtual void execute(Note* a_execute){
			if (a_execute == nullptr || m_serialNetwork == nullptr) {
				System::console.println("a_execute == nullptr || m_serialNetwork == nullptr");
				return;
			}
			System::console.println("NetworkMessageRedirection");
			
			PrimitiveList<Note> commands = splitFirstNote(4, *a_execute, ' ');

			if(commands.getPosition() != 4){
				return;
			}
			Note command_0 = commands[0];
			Note command_1 = commands[1];
			Note command_2 = commands[2];
			Note command_3 = commands[3];
			if (command_0 == "ram") {
				System::console.print("ram: ");
				System::console.println(getRamSize());
			}
		}
		
	protected:
		SerialNetwork* m_serialNetwork = nullptr;
};

}

#endif