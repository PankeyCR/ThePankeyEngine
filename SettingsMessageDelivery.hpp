
#ifndef SettingsMessageDelivery_hpp
	#define SettingsMessageDelivery_hpp

	#include "Application.hpp"
	#include "Note.hpp"

	namespace pankey{

		void SettingsMessageDelivery(Application& a_app, const Note& a_message){
			// System::console.println(a_message);
			int i_message_size = a_message.getPartSize(' ');
			if(i_message_size == 3){
				Note i_command_1 = a_message.split(0, ' ');
				Note i_command_2 = a_message.split(1, ' ');
				Note i_command_3 = a_message.split(2, ' ');
				auto& i_settings = a_app.getSettings();
				if(i_command_1 == "Settings"){
					if(i_command_2 == "getInt"){
						if(!i_command_3.isEmpty()){
							int i_val = i_settings.getInt(i_command_3);
							a_app.run("send_message", i_command_3 + Note(" ") + Note(i_val));
						}
					}
					if(i_command_2 == "removeInt"){
						if(!i_command_3.isEmpty()){
							i_settings.removeInt(i_command_3);
						}
					}
					if(i_command_2 == "containInt"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.containInt(i_command_3);
							a_app.run("send_message", Note(i_val));
						}
					}
					if(i_command_2 == "getLong"){
						if(!i_command_3.isEmpty()){
							long i_val = i_settings.getLong(i_command_3);
							a_app.run("send_message", i_command_3 + Note(" ") + Note(i_val));
						}
					}
					if(i_command_2 == "removeLong"){
						if(!i_command_3.isEmpty()){
							i_settings.removeLong(i_command_3);
						}
					}
					if(i_command_2 == "containLong"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.containLong(i_command_3);
							a_app.run("send_message", Note(i_val));
						}
					}
					if(i_command_2 == "getFloat"){
						if(!i_command_3.isEmpty()){
							float i_val = i_settings.getFloat(i_command_3);
							a_app.run("send_message", i_command_3 + Note(" ") + Note(i_val));
						}
					}
					if(i_command_2 == "removeFloat"){
						if(!i_command_3.isEmpty()){
							i_settings.removeFloat(i_command_3);
						}
					}
					if(i_command_2 == "containFloat"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.containFloat(i_command_3);
							a_app.run("send_message", Note(i_val));
						}
					}
					if(i_command_2 == "getNote"){
						if(!i_command_3.isEmpty()){
							Note i_val = i_settings.getNote(i_command_3);
							a_app.run("send_message", i_command_3 + Note(" ") + i_val);
						}
					}
					if(i_command_2 == "removeNote"){
						if(!i_command_3.isEmpty()){
							i_settings.removeNote(i_command_3);
						}
					}
					if(i_command_2 == "containNote"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.containNote(i_command_3);
							a_app.run("send_message", Note(i_val));
						}
					}
					if(i_command_2 == "getBoolean"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.getBoolean(i_command_3);
							a_app.run("send_message", i_command_3 + Note(" ") + Note(i_val));
						}
					}
					if(i_command_2 == "removeBoolean"){
						if(!i_command_3.isEmpty()){
							i_settings.removeBoolean(i_command_3);
						}
					}
					if(i_command_2 == "containBoolean"){
						if(!i_command_3.isEmpty()){
							bool i_val = i_settings.containBoolean(i_command_3);
							a_app.run("send_message", Note(i_val));
						}
					}
				}
			}
			if(i_message_size == 4){
				Note i_command_1 = a_message.split(0, ' ');
				Note i_command_2 = a_message.split(1, ' ');
				Note i_command_3 = a_message.split(2, ' ');
				Note i_command_4 = a_message.split(3, ' ');
				auto& i_settings = a_app.getSettings();
				if(i_command_1 == "Settings"){
					if(i_command_2 == "addInt"){
						if(!i_command_3.isEmpty() && i_command_4.isInt()){
							i_settings.addInt(i_command_3, i_command_4.toInt());
						}
					}
					if(i_command_2 == "putInt"){
						if(!i_command_3.isEmpty() && i_command_4.isInt()){
							i_settings.putInt(i_command_3, i_command_4.toInt());
						}
					}
					if(i_command_2 == "setInt"){
						if(!i_command_3.isEmpty() && i_command_4.isInt()){
							i_settings.setInt(i_command_3, i_command_4.toInt());
						}
					}
					if(i_command_2 == "changeInt"){
						if(!i_command_3.isEmpty() && i_command_4.isInt()){
							i_settings.changeInt(i_command_3, i_command_4.toInt());
						}
					}
					if(i_command_2 == "addLong"){
						if(!i_command_3.isEmpty() && i_command_4.isLong()){
							i_settings.addLong(i_command_3, i_command_4.toLong());
						}
					}
					if(i_command_2 == "putLong"){
						if(!i_command_3.isEmpty() && i_command_4.isLong()){
							i_settings.putLong(i_command_3, i_command_4.toLong());
						}
					}
					if(i_command_2 == "setLong"){
						if(!i_command_3.isEmpty() && i_command_4.isLong()){
							i_settings.setLong(i_command_3, i_command_4.toLong());
						}
					}
					if(i_command_2 == "changeLong"){
						if(!i_command_3.isEmpty() && i_command_4.isLong()){
							i_settings.changeLong(i_command_3, i_command_4.toLong());
						}
					}
					if(i_command_2 == "addFloat"){
						if(!i_command_3.isEmpty() && i_command_4.isFloat()){
							i_settings.addFloat(i_command_3, i_command_4.toFloat());
						}
					}
					if(i_command_2 == "putFloat"){
						if(!i_command_3.isEmpty() && i_command_4.isFloat()){
							i_settings.putFloat(i_command_3, i_command_4.toFloat());
						}
					}
					if(i_command_2 == "setFloat"){
						if(!i_command_3.isEmpty() && i_command_4.isFloat()){
							i_settings.setFloat(i_command_3, i_command_4.toFloat());
						}
					}
					if(i_command_2 == "changeFloat"){
						if(!i_command_3.isEmpty() && i_command_4.isFloat()){
							System::console.println("si es float");
							i_settings.changeFloat(i_command_3, i_command_4.toFloat());
						}
					}
					if(i_command_2 == "addNote"){
						if(!i_command_3.isEmpty()){
							i_settings.addNote(i_command_3, i_command_4);
						}
					}
					if(i_command_2 == "putNote"){
						if(!i_command_3.isEmpty()){
							i_settings.putNote(i_command_3, i_command_4);
						}
					}
					if(i_command_2 == "setNote"){
						if(!i_command_3.isEmpty()){
							i_settings.setNote(i_command_3, i_command_4);
						}
					}
					if(i_command_2 == "changeNote"){
						if(!i_command_3.isEmpty()){
							i_settings.changeNote(i_command_3, i_command_4);
						}
					}
					if(i_command_2 == "addBoolean"){
						if(!i_command_3.isEmpty() && i_command_4.isBool()){
							i_settings.addBoolean(i_command_3, i_command_4.toBool());
						}
					}
					if(i_command_2 == "putBoolean"){
						if(!i_command_3.isEmpty() && i_command_4.isBool()){
							i_settings.putBoolean(i_command_3, i_command_4.toBool());
						}
					}
					if(i_command_2 == "setBoolean"){
						if(!i_command_3.isEmpty() && i_command_4.isBool()){
							i_settings.setBoolean(i_command_3, i_command_4.toBool());
						}
					}
					if(i_command_2 == "changeBoolean"){
						if(!i_command_3.isEmpty() && i_command_4.isBool()){
							i_settings.changeBoolean(i_command_3, i_command_4.toBool());
						}
					}
				}
			}
		}

	}

#endif
