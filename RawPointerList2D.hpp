
#ifndef RawPointerList2D_hpp
    #define RawPointerList2D_hpp
    
    #include "RawPointerList.hpp"

    #ifdef RawPointerList2D_LogApp
        #include "pankey_Logger_config.hpp"
        #define RawPointerList2DLog(location,method,type,mns) pankey_Log(nullptr,location,"RawPointerList2D",method,type,mns)
    #else
        #define RawPointerList2DLog(location,method,type,mns)
    #endif

    namespace pankey{

        namespace RawPointerList2D{
                
                template<class L>
                bool isEmpty(const L& a_list){
                    RawPointerList2DLog(pankey_Log_StartMethod, "isEmpty", "println", "");
                    if(a_list.isEmpty()){
                        return true;
                    }
                    for(int x = 0; x < a_list.getPosition(); x++){
                        auto f_list = a_list.getByPosition(x);
                        if(f_list == nullptr){
                            continue;
                        }
                        if(!f_list->isEmpty()){
                            RawPointerList2DLog(pankey_Log_EndMethod, "isEmpty", "println", "");
                            return false;
                        }
                    }
                    RawPointerList2DLog(pankey_Log_EndMethod, "isEmpty", "println", "");
                    return true;
                }
                
            //     virtual void setOwner(bool a_owning){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "isOwner", "println", "");
            //         this->m_owner = a_owning;
            //         RawPointerList2DLog(pankey_Log_EndMethod, "isOwner", "println", "");
            //     }
            //     virtual bool isOwner()const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "isOwner", "println", "");
            //         RawPointerList2DLog(pankey_Log_Statement, "isOwner", "println", "isOwner:");
            //         RawPointerList2DLog(pankey_Log_Statement, "isOwner", "println", this->m_owner);
            //         RawPointerList2DLog(pankey_Log_EndMethod, "isOwner", "println", "");
            //         return this->m_owner;
            //     }
                
            //     virtual int getPosition1D()const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "getPosition", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "getPosition", "println", "");
            //         return this->m_position;
            //     }
            //     virtual int getPosition2D(int a_index)const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "getPosition", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "getPosition", "println", "");
            //         return this->m_position;
            //     }
                
            //     virtual int getSize1D()const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "getSize", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "getSize", "println", "");
            //         return this->m_size;
            //     }
            //     virtual int getSize2D(int a_index)const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "getSize", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "getSize", "println", "");
            //         return this->m_size;
            //     }
                
            //     virtual void addMove(RawPointerList2D<T>& a_list){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "addMove", "println", "");
            //         for(int x = 0; x < a_list.getPosition1D(); x++){
            //             T* f_value = a_list.getByPosition(x);
            //             this->addPointer(f_value);
            //         }
            //         a_list.reset();
            //         RawPointerList2DLog(pankey_Log_EndMethod, "addMove", "println", "");
            //     }
                
            //     virtual void addDuplicate(const RawPointerList2D<T>& a_list){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "addDuplicate", "println", "");
            //         for(int x = 0; x < a_list.getPosition(); x++){
            //             T* f_value = a_list.getByPosition(x);
            //             this->addPointer(f_value);
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "addDuplicate", "println", "");
            //     }

            //     virtual T* addPointer(T* a_value)=0;
                
            //     virtual T* putPointer(T* a_value){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "putPointer", "println", "");
            //         if(this->containByPointer(a_value)){
            //             return nullptr;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "putPointer", "println", "");
            //         return this->addPointer(a_value);
            //     }

            //     virtual T* setPointer(int a_position, T* a_value)=0;

            //     virtual T* insertPointer(int a_position, T* a_value)=0;

            //     virtual T* getByPointer(T* a_value)=0;
            //     virtual T* getByPosition(int x)const=0;

            //     virtual bool containByPointer(T* a_value)=0;
                
            //     virtual int getIndexByPointer(T* a_value)=0;

            //     virtual void reset()=0;
            //     virtual void resetDelete()=0;

            //     virtual T* removeByPointer(T* a_value)=0;

            //     virtual T* removeByPosition(int a_position)=0;

            //     virtual bool removeDeleteByPointer(T* a_value){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "removeDeleteByPointer", "println", "");
            //         T* t = this->removeByPointer(a_value);
            //         bool removed = t != nullptr;
            //         if(removed && isOwner()){
            //             delete t;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "removeDeleteByPointer", "println", "");
            //         return removed;
            //     }

            //     virtual bool removeDeleteByPosition(int a_position){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "removeDeleteByPosition", "println", "");
            //         T* t = this->removeByPosition(a_position);
            //         bool removed = t != nullptr;
            //         if(removed && isOwner()){
            //             RawPointerList2DLog(pankey_Log_Statement, "removeDeleteByPosition", "println", "deleting pointer");
            //             delete t;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "removeDeleteByPosition", "println", "");
            //         return removed;
            //     }

            //     //special removes
            //     virtual bool removeFirstIndex(int a_amount)=0;
            //     virtual bool removeLastIndex(int a_amount)=0;
                
            //     virtual bool removeFirst(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "removeFirst", "println", "");
            //         if(this->isEmpty()){
            //             RawPointerList2DLog(pankey_Log_EndMethod, "removeFirst", "println", "this->isEmpty()");
            //             return false;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "removeFirst", "println", "");
            //         return this->removeDeleteByPosition(0);
            //     }

            //     virtual bool removeLast(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "removeLast", "println", "");
            //         if(this->isEmpty()){
            //             return false;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "removeLast", "println", "");
            //         return this->removeDeleteByPosition(this->getPosition() - 1);
            //     }

            //     virtual bool isInOrder(){return this->m_reorder;}
            //     virtual void setReorder(bool a_reorder){this->m_reorder = a_reorder;}
            //     virtual void reorder(){}

            //     virtual void expand(int a_size)=0;
                
            // protected:
                
            //     virtual void incrementPosition(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
            //         this->m_position++;
            //         RawPointerList2DLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
            //     }
            //     virtual void decrementPosition(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
            //         this->m_position--;
            //         if(this->m_position < 0){
            //             this->m_position = 0;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
            //     }
                
            //     virtual void incrementPosition(int a_size){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
            //         this->m_position += a_size;
            //         RawPointerList2DLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
            //     }
            //     virtual void decrementPosition(int a_size){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
            //         this->m_position -= a_size;
            //         if(this->m_position < 0){
            //             this->m_position = 0;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
            //     }
                
            //     virtual void incrementSize(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "incrementSize", "println", "");
            //         this->m_size++;
            //         RawPointerList2DLog(pankey_Log_EndMethod, "incrementSize", "println", "");
            //     }
            //     virtual void decrementSize(){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "decrementSize", "println", "");
            //         this->m_size--;
            //         if(this->m_size < 0){
            //             this->m_size = 0;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "decrementSize", "println", "");
            //     }
                
            //     virtual void incrementSize(int a_size){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "incrementSize", "println", "");
            //         this->m_size += a_size;
            //         RawPointerList2DLog(pankey_Log_EndMethod, "incrementSize", "println", "");
            //     }
            //     virtual void decrementSize(int a_size){
            //         RawPointerList2DLog(pankey_Log_StartMethod, "decrementSize", "println", "");
            //         this->m_size -= a_size;
            //         if(this->m_size < 0){
            //             this->m_size = 0;
            //         }
            //         RawPointerList2DLog(pankey_Log_EndMethod, "decrementSize", "println", "");
            //     }

            // public:
            
            //     virtual bool operator<(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator<", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator<", "println", "");
            //         return this->getPosition() < x;
            //     }
                
            //     virtual bool operator>(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator>", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator>", "println", "");
            //         return this->getPosition() > x;
            //     }
                
            //     virtual bool operator<=(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator<=", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator<=", "println", "");
            //         return this->getPosition() <= x;
            //     }
                
            //     virtual bool operator>=(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator>=", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator>=", "println", "");
            //         return this->getPosition() >= x;
            //     }
                
            //     virtual bool operator==(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator==", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator==", "println", "");
            //         return this->getPosition() == x;
            //     }
                
            //     virtual bool operator!=(int x) const{
            //         RawPointerList2DLog(pankey_Log_StartMethod, "operator!=", "println", "");
            //         RawPointerList2DLog(pankey_Log_EndMethod, "operator!=", "println", "");
            //         return this->getPosition() != x;
            //     }

            // protected:
            //     bool m_reorder = true;
            //     bool m_owner = true;
            //     int m_position = 0;
            //     int m_size = 0;
        }

    }

#endif