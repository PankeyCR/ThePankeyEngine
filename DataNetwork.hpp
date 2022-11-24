
#ifndef CONFIGURATION_DataNetwork_hpp
#define CONFIGURATION_DataNetwork_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_DataNetwork)
		#define DataNetwork_hpp

		#define IMPLEMENTATION_DataNetwork
		#define IMPLEMENTING_DataNetwork
	#else
		#if defined(DISABLE_IMPLEMENTATION_DataNetwork)
			#define IMPLEMENTATION_DataNetwork
			#define IMPLEMENTING_DataNetwork
		#endif
	#endif
#endif

#ifndef DataNetwork_hpp
#define DataNetwork_hpp
#define DataNetwork_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_DataNetwork
	#define IMPLEMENTATION_DataNetwork IMPLEMENTATION(public DataNetwork)
	#define IMPLEMENTING_DataNetwork IMPLEMENTING(public DataNetwork)
#endif

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include "Printable.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "Class.hpp"
#include "PrimitiveList.hpp"
#include "LinkedList.hpp"
#include "Array.hpp"

#ifdef DataNetwork_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define DataNetworkLog(location,method,type,mns) ame_Log(this,location,"DataNetwork",method,type,mns)
	#define const_DataNetworkLog(location,method,type,mns)
#else
	#ifdef DataNetwork_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define DataNetworkLog(location,method,type,mns) ame_LogDebug(this,location,"DataNetwork",method,type)
		#define const_DataNetworkLog(location,method,type,mns)
	#else
		#define DataNetworkLog(location,method,type,mns)
		#define const_DataNetworkLog(location,method,type,mns)
	#endif
#endif

namespace ame{
	
template <class T>
class DataNetwork : public LinkedList<DataNetwork<T>>{
	public:
		DataNetwork(){
			DataNetworkLog(ame_Log_StartMethod, "Constructor", "println", "");
			DataNetworkLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		DataNetwork(const T& c_value){
			DataNetworkLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->set(c_value);
			DataNetworkLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		DataNetwork(const DataNetwork<T>& c_network){
			DataNetworkLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->set(c_network.get());

			if(c_network.isTransfinite()){
				return;
			}
			for(int x = 0; x < c_network.getPosition(); x++){
				DataNetwork<T>* f_network = c_network.getByPosition(x);
				if(f_network == nullptr){
					this->addPointer(nullptr);
					continue;
				}
				DataNetwork<T>* f_network_2 = new DataNetwork<T>();
				*f_network_2 = *f_network;
				this->addPointer(nullptr);
			}
			DataNetworkLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~DataNetwork(){
			DataNetworkLog(ame_Log_StartMethod, "Destructor", "println", "");
			DataNetworkLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void setData(T* a_value){
			m_value = a_value;
		}
		
		virtual T* getData(){
			return m_value;
		}
		
		virtual void set(T a_value){
			DataNetworkLog(ame_Log_StartMethod, "set", "println", "");
			if(m_value == nullptr){
				m_value = new T();
			}
			*m_value = a_value;
			DataNetworkLog(ame_Log_EndMethod, "set", "println", "a_value");
			DataNetworkLog(ame_Log_EndMethod, "set", "println", a_value);
			DataNetworkLog(ame_Log_EndMethod, "set", "println", "");
		}
		
		virtual T get()const{
			if(m_value == nullptr){
				return T();
			}
			return *m_value;
		}

		virtual void setTransfinite(bool a_transfinite){
			m_transfinite = a_transfinite;
		}

		virtual bool isTransfinite()const{
			return m_transfinite;
		}
		
		virtual DataNetwork<T>* addValue(T a_value){
			DataNetworkLog(ame_Log_StartMethod, "addValue", "println", "");
			DataNetwork<T>* dateNetwork = new DataNetwork<T>();
			dateNetwork->set(a_value);
			this->addPointer(dateNetwork);
			DataNetworkLog(ame_Log_EndMethod, "addValue", "println", "a_value");
			DataNetworkLog(ame_Log_EndMethod, "addValue", "println", a_value);
			DataNetworkLog(ame_Log_EndMethod, "addValue", "println", "");
			return dateNetwork;
		}

		virtual LinkedList<T> getValues(){
			LinkedList<T> i_list;
			i_list.setOwner(false);

			for(int x = 0; x < this->getPosition(); x++){
				LinkedListNode<DataNetwork<T>>* f_node = this->getNode(x);
				DataNetwork<T>* f_network = f_node->get();
				i_list.addPointer(f_network->getData());
			}

			return i_list;
		}

		virtual LinkedList<T> getCloneValues(){
			LinkedList<T> i_list;

			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* f_network = this->getByPosition(x);
				i_list.add(f_network->get());
			}

			return i_list;
		}

		virtual void addValues(const LinkedList<T>& a_values){
			for(int x = 0; x < a_values.getPosition(); x++){
				this->addValue(a_values[x]);
			}
		}

		virtual bool belongs(const T& a_value){
			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* f_network = this->getByPosition(x);
				if(f_network == nullptr){
					continue;
				}
				T* f_value = f_network->getData();
				if(f_value == nullptr){
					continue;
				}
				if(a_value == *f_value){
					return true;
				}
			}
			return false;
		}

		virtual bool similar(DataNetwork<T>& a_network){
			return a_network.getPosition() == this->getPosition();
		}

		virtual bool similarToAll(DataNetwork<T>& a_network){
			if(a_network.getPosition() != this->getPosition()){
				return false;
			}
			if(a_network.isTransfinite() && this->isTransfinite()){
				return true;
			}
			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* i_set_1 = this->getByPosition(x);
				DataNetwork<T>* i_set_2 = a_network.getByPosition(x);
				if(!i_set_1->similar(*i_set_2)){
					return false;
				}
			}
			return true;
		}
		
		virtual DataNetwork<T> Intersection(DataNetwork<T>& a_set){
			DataNetwork<T> i_network;

			//LinkedList<T>
			// for(int x = 0; x < a_set.getPosition(); x++){
			// 	DataNetwork<T>* i_set_1 = a_set.getByPosition(x);
			// 	if(this->belongs(i_set_1->get())){
			// 		i_network.addValue(i_set_1);
			// 	}
			// }
			return i_network;
		}
		
		virtual DataNetwork<T>* Union(DataNetwork<T>* a_set){
			DataNetwork<T>* i_network = new DataNetwork<T>();

			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* i_set_1 = this->getByPosition(x);
				i_network->addPointer(i_set_1);
			}
			for(int x = 0; x < a_set->getPosition(); x++){
				DataNetwork<T>* i_set_1 = a_set->getByPosition(x);
				i_network->addPointer(i_set_1);
			}
			return i_network;
		}
		
		virtual DataNetwork<T>* NoRepeatUnion(DataNetwork<T>* a_set){
			DataNetwork<T>* i_network = new DataNetwork<T>();

			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* i_set_1 = this->getByPosition(x);
				i_network->putPointer(i_set_1);
			}
			for(int x = 0; x < a_set->getPosition(); x++){
				DataNetwork<T>* i_set_1 = a_set->getByPosition(x);
				i_network->putPointer(i_set_1);
			}
			return i_network;
		}
		virtual DataNetwork<T>* Difference(DataNetwork<T>* a_set){
			return nullptr;
		}
		virtual DataNetwork<T>* Complement(DataNetwork<T>* a_set){
			return nullptr;
		}

		template<class... INTS>
		void createFlatNetwork(INTS... a_layer_size){
			DataNetworkLog(ame_Log_StartMethod, "createFlatNetwork", "println", "");
			PrimitiveList<int> i_ints;
			i_ints.addPack(a_layer_size...);
			for(int x = 0; x < i_ints.getPosition(); x++){
				int f_size = i_ints.getByIndex(x);
				DataNetwork<T>* i_layer = this->addPointer(new DataNetwork<T>());
				i_layer->createVerticalLayer(f_size);
			}
			DataNetworkLog(ame_Log_EndMethod, "createFlatNetwork", "println", "");
		}

		virtual void createVerticalLayer(int a_size){
			DataNetworkLog(ame_Log_StartMethod, "createVerticalLayer", "println", "");
			for(int x = 0; x < a_size; x++){
				this->addPointer(new DataNetwork<T>());
			}
			DataNetworkLog(ame_Log_EndMethod, "createVerticalLayer", "println", "");
		}

		virtual void createHorizontalLayer(int a_line, int a_size){
			DataNetworkLog(ame_Log_StartMethod, "createHorizontalLayer", "println", "");
			DataNetwork<T>* i_layer = this;
			for(int x = 0; x < a_size; x++){
				i_layer = i_layer->insertPointer(a_line, new DataNetwork<T>());
				if(i_layer == nullptr){
					return;
				}
			}
			DataNetworkLog(ame_Log_StartMethod, "createHorizontalLayer", "println", "");
		}

		virtual DataNetwork<T>* getHorizontalLayer(int a_line, int a_position){
			DataNetwork<T>* i_layer = this;
			for(int x = 0; x < a_position + 1; x++){
				i_layer = i_layer->getByPosition(a_line);
				if(i_layer == nullptr){
					return nullptr;
				}
			}
			return i_layer;
		}

		template<class... INTS>
		void setFlatNetwork(int a_position, INTS... a_layer_value){
			DataNetwork<T>* i_data = this->getByPosition(a_position);
			if(i_data == nullptr){
				return;
			}
			PrimitiveList<int> i_ints;
			i_ints.addPack(a_layer_value...);
			if(i_ints.getPosition() != i_data->getPosition()){
				return;
			}
			for(int x = 0; x < i_data->getPosition(); x++){
				int f_value = i_ints.getByIndex(x);
				i_data->setVerticalLayerValue(x, f_value);
			}
		}

		virtual void setVerticalLayerValue(int a_position, T a_value){
			DataNetwork<T>* i_data = this->getByPosition(a_position);
			if(i_data == nullptr){
				return;
			}
			i_data->set(a_value);
		}

		virtual void setHorizontalLayerValue(int a_line, int a_position, T a_value){
			DataNetwork<T>* i_data = this->getHorizontalLayer(a_line, a_position);
			if(i_data == nullptr){
				return;
			}
			i_data->set(a_value);
		}

		virtual Array<T> getFlatLayerArray(int a_position){
			DataNetworkLog(ame_Log_StartMethod, "getVerticalLayerArray", "println", "");
			Array<T> i_array;
			if(this->isEmpty()){
				return i_array;
			}
			int i_layer_size = this->getPosition();
			i_array.expandLocal(i_layer_size);
			DataNetworkLog(ame_Log_Statement, "getVerticalLayerArray", "println", "i_layer_size");
			DataNetworkLog(ame_Log_StartMethod, "getVerticalLayerArray", "println", i_layer_size);

			for(int x = 0; x < i_layer_size; x++){
				DataNetwork<T>* f_container = this->getByPosition(x);
				T value = f_container->get();
				i_array.addLocalValue(value);
			}

			DataNetworkLog(ame_Log_EndMethod, "getVerticalLayerArray", "println", "");
			return i_array;
		}

		virtual Array<T> getVerticalLayerArray(){
			DataNetworkLog(ame_Log_StartMethod, "getVerticalLayerArray", "println", "");
			Array<T> i_array;
			if(this->isEmpty()){
				return i_array;
			}
			int i_layer_size = this->getPosition();
			i_array.expandLocal(i_layer_size);
			DataNetworkLog(ame_Log_Statement, "getVerticalLayerArray", "println", "i_layer_size");
			DataNetworkLog(ame_Log_StartMethod, "getVerticalLayerArray", "println", i_layer_size);

			for(int x = 0; x < i_layer_size; x++){
				DataNetwork<T>* f_container = this->getByPosition(x);
				T value = f_container->get();
				i_array.addLocalValue(value);
			}

			DataNetworkLog(ame_Log_EndMethod, "getVerticalLayerArray", "println", "");
			return i_array;
		}

		virtual Array<T> getHorizontalLayerArray(int a_line){
			DataNetworkLog(ame_Log_StartMethod, "getHorizontalLayerArray", "println", "");
			Array<T> i_array;
			if(this->getPosition() < a_line){
				return i_array;
			}
			DataNetwork<T>* i_layer = this;
			
			for(int x = 0; i_layer != nullptr; x++){
				i_layer = i_layer->getByPosition(a_line);
				if(i_layer == nullptr){
					return i_array;
				}
				T value = i_layer->get();
				i_array.addLocalValue(value);
			}

			DataNetworkLog(ame_Log_EndMethod, "getHorizontalLayerArray", "println", "");
			return i_array;
		}

		virtual cppObjectClass* getClass(){return Class<DataNetwork<T>>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return LinkedList<DataNetwork<T>>::instanceof(cls) || 
					cls == Class<DataNetwork<T>>::getClass();
		}

		virtual DataNetwork<T>& operator=(const DataNetwork<T>& c_network){
			DataNetworkLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->resetDelete();

			this->set(c_network.get());
			
			if(c_network.isTransfinite()){
				return *this;
			}
			for(int x = 0; x < c_network.getPosition(); x++){
				DataNetwork<T>* f_network = c_network.getByPosition(x);
				if(f_network == nullptr){
					this->addPointer(nullptr);
					continue;
				}
				DataNetwork<T>* f_network_2 = new DataNetwork<T>();
				*f_network_2 = *f_network;
				this->addPointer(nullptr);
			}
			DataNetworkLog(ame_Log_EndMethod, "Constructor", "println", "");
			return *this;
		}

		virtual bool operator==(const DataNetwork<T>& c_dateNetwork){
			DataNetworkLog(ame_Log_StartMethod, "operator==", "println", "");
			if(c_dateNetwork.getPosition() != this->getPosition()){
				DataNetworkLog(ame_Log_EndMethod, "operator==", "println", "c_dateNetwork.getPosition() != this->getPosition()");
				return false;
			}
			if(c_dateNetwork.isTransfinite() && this->isTransfinite()){
				DataNetworkLog(ame_Log_EndMethod, "operator==", "println", "c_dateNetwork.isTransfinite() && this->isTransfinite()");
				return true;
			}
			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* i_set_1 = this->getByPosition(x);
				DataNetwork<T>* i_set_2 = c_dateNetwork.getByPosition(x);
				if(i_set_1 != i_set_2 && (i_set_1 == nullptr || i_set_2 == nullptr)){
					return false;
				}
				if(i_set_1->get() != i_set_2->get()){
					DataNetworkLog(ame_Log_EndMethod, "operator==", "println", "i_set_1.get() != i_set_2.get()");
					return false;
				}
				if(*i_set_1 != *i_set_2){
					DataNetworkLog(ame_Log_EndMethod, "operator==", "println", "i_set_1 != i_set_2");
					return false;
				}
			}
			DataNetworkLog(ame_Log_EndMethod, "operator=", "println", "");
			return true;
		}

		virtual bool operator!=(const DataNetwork<T>& c_dateNetwork){
			DataNetworkLog(ame_Log_StartMethod, "operator!=", "println", "");
			if(c_dateNetwork.getPosition() != this->getPosition()){
				DataNetworkLog(ame_Log_EndMethod, "operator!=", "println", "c_dateNetwork.getPosition() != this->getPosition()");
				return true;
			}
			if(c_dateNetwork.isTransfinite() && this->isTransfinite()){
				DataNetworkLog(ame_Log_EndMethod, "operator!=", "println", "c_dateNetwork.isTransfinite() && this->isTransfinite()");
				return false;
			}
			for(int x = 0; x < this->getPosition(); x++){
				DataNetwork<T>* i_set_1 = this->getByPosition(x);
				DataNetwork<T>* i_set_2 = c_dateNetwork.getByPosition(x);
				if(i_set_1 != i_set_2 && (i_set_1 == nullptr || i_set_2 == nullptr)){
					return true;
				}
				if(i_set_1->get() != i_set_2->get()){
					DataNetworkLog(ame_Log_EndMethod, "operator!=", "println", "i_set_1.get() != i_set_2.get()");
					return true;
				}
				if(*i_set_1 != *i_set_2){
					DataNetworkLog(ame_Log_EndMethod, "operator!=", "println", "i_set_1 != i_set_2");
					return true;
				}
			}
			DataNetworkLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}
	protected:
		T* m_value = nullptr;
		bool m_transfinite = false;
};

}

#endif