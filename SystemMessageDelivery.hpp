
#ifndef SystemMessageDelivery_hpp
	#define SystemMessageDelivery_hpp

	#include "Application.hpp"
	#include "Note.hpp"

	namespace pankey{

		void SystemMessageDelivery(Application& a_app, const Note& a_message){
			int i_message_size = a_message.getPartSize(' ');
			if(i_message_size == 1){
				if(a_message == "getRamSize"){
					System::console.println(getRamSize());
				}
			}
			if(i_message_size == 2){
				Note i_command_1 = a_message.split(0, ' ');
				Note i_command_2 = a_message.split(1, ' ');
				if(i_command_1 == "System" && i_command_2 == "milliSeconds"){
					System::console.println(System::milliSeconds());
				}
				if(i_command_1 == "System" && i_command_2 == "microSeconds"){
					System::console.println(System::microSeconds());
				}
			}
			if(i_message_size == 3){
				Note i_command_1 = a_message.split(0, ' ');
				Note i_command_2 = a_message.split(1, ' ');
				Note i_command_3 = a_message.split(2, ' ');
				if(i_command_1 == "System" && i_command_2 == "sleep"){
					if(i_command_3.isInt()){
						System::sleep(i_command_3.toInt());
					}
				}
			}
			if(i_message_size == 4){
				Note i_command_1 = a_message.split(0, ' ');
				Note i_command_2 = a_message.split(1, ' ');
				Note i_command_3 = a_message.split(2, ' ');
				Note i_command_4 = a_message.split(3, ' ');
				if(i_command_1 == "System" && i_command_2 == "console" && i_command_3 == "print"){
					System::console.print(i_command_4);
				}
				if(i_command_1 == "System" && i_command_2 == "console" && i_command_3 == "println"){
					System::console.println(i_command_4);
				}
			}
		}

	}

#endif
