
#ifndef RawPointerList_hpp
    #define RawPointerList_hpp

    #ifdef RawPointerList_LogApp
        #include "pankey_Logger_config.hpp"
        #define RawPointerListLog(location,method,type,mns) pankey_Log((void*)this,location,"RawPointerList",method,type,mns)
    #else
        #define RawPointerListLog(location,method,type,mns)
    #endif

    namespace pankey{

        template <class T>
        class RawPointerList{
            public:
                virtual ~RawPointerList(){
                    RawPointerListLog(pankey_Log_StartMethod, "Destructor", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "Destructor", "println", "");
                }
                
                virtual bool isEmpty()const=0;
                
                virtual void setOwner(bool a_owning){
                    RawPointerListLog(pankey_Log_StartMethod, "isOwner", "println", "");
                    this->m_owner = a_owning;
                    RawPointerListLog(pankey_Log_EndMethod, "isOwner", "println", "");
                }
                virtual bool isOwner()const{
                    RawPointerListLog(pankey_Log_StartMethod, "isOwner", "println", "");
                    RawPointerListLog(pankey_Log_Statement, "isOwner", "println", "isOwner:");
                    RawPointerListLog(pankey_Log_Statement, "isOwner", "println", this->m_owner);
                    RawPointerListLog(pankey_Log_EndMethod, "isOwner", "println", "");
                    return this->m_owner;
                }
                virtual void setPosition(int a_position){
                    RawPointerListLog(pankey_Log_StartMethod, "setPosition", "println", "");
                    this->m_position = a_position;
                    RawPointerListLog(pankey_Log_EndMethod, "setPosition", "println", "");
                }
                virtual int getPosition()const{
                    RawPointerListLog(pankey_Log_StartMethod, "getPosition", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "getPosition", "println", "");
                    return this->m_position;
                }
                
                virtual void setSize(int a_size){
                    RawPointerListLog(pankey_Log_StartMethod, "setSize", "println", "");
                    this->m_size = a_size;
                    RawPointerListLog(pankey_Log_EndMethod, "setSize", "println", "");
                }
                virtual int getSize()const{
                    RawPointerListLog(pankey_Log_StartMethod, "getSize", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "getSize", "println", "");
                    return this->m_size;
                }

                virtual bool replace(int i, int j)=0;
                
                virtual void addMove(RawPointerList<T>& a_list){
                    RawPointerListLog(pankey_Log_StartMethod, "addMove", "println", "");
                    for(int x = 0; x < a_list.getPosition(); x++){
                        T* f_value = a_list.getByPosition(x);
                        this->addPointer(f_value);
                    }
                    a_list.reset();
                    RawPointerListLog(pankey_Log_EndMethod, "addMove", "println", "");
                }
                
                virtual void addDuplicate(const RawPointerList<T>& a_list){
                    RawPointerListLog(pankey_Log_StartMethod, "addDuplicate", "println", "");
                    for(int x = 0; x < a_list.getPosition(); x++){
                        T* f_value = a_list.getByPosition(x);
                        this->addPointer(f_value);
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "addDuplicate", "println", "");
                }

                virtual T* addPointer(T* a_value)=0;
                
                virtual T* putPointer(T* a_value){
                    RawPointerListLog(pankey_Log_StartMethod, "putPointer", "println", "");
                    if(this->containByPointer(a_value)){
                        return nullptr;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "putPointer", "println", "");
                    return this->addPointer(a_value);
                }

                virtual T* setPointer(int a_position, T* a_value)=0;

                virtual T* insertPointer(int a_position, T* a_value)=0;

                virtual T* getByPointer(T* a_value)=0;
                virtual T* getByPosition(int x)const=0;

                virtual bool containByPointer(T* a_value)=0;
                
                virtual int getIndexByPointer(T* a_value)=0;

                virtual void reset()=0;
                virtual void resetDelete()=0;

                virtual T* removeByPointer(T* a_value)=0;

                virtual T* removeByPosition(int a_position)=0;

                virtual bool removeDeleteByPointer(T* a_value){
                    RawPointerListLog(pankey_Log_StartMethod, "removeDeleteByPointer", "println", "");
                    T* t = this->removeByPointer(a_value);
                    bool removed = t != nullptr;
                    if(removed && isOwner()){
                        delete t;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "removeDeleteByPointer", "println", "");
                    return removed;
                }

                virtual bool removeDeleteByPosition(int a_position){
                    RawPointerListLog(pankey_Log_StartMethod, "removeDeleteByPosition", "println", "");
                    T* t = this->removeByPosition(a_position);
                    bool removed = t != nullptr;
                    if(removed && isOwner()){
                        RawPointerListLog(pankey_Log_Statement, "removeDeleteByPosition", "println", "deleting pointer");
                        delete t;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "removeDeleteByPosition", "println", "");
                    return removed;
                }

                //special removes
                virtual bool removeFirstIndex(int a_amount)=0;
                virtual bool removeLastIndex(int a_amount)=0;
                
                virtual bool removeFirst(){
                    RawPointerListLog(pankey_Log_StartMethod, "removeFirst", "println", "");
                    if(this->isEmpty()){
                        RawPointerListLog(pankey_Log_EndMethod, "removeFirst", "println", "this->isEmpty()");
                        return false;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "removeFirst", "println", "");
                    return this->removeDeleteByPosition(0);
                }

                virtual bool removeLast(){
                    RawPointerListLog(pankey_Log_StartMethod, "removeLast", "println", "");
                    if(this->isEmpty()){
                        return false;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "removeLast", "println", "");
                    return this->removeDeleteByPosition(this->getPosition() - 1);
                }

                virtual bool isInOrder(){return this->m_reorder;}
                virtual void setReorder(bool a_reorder){this->m_reorder = a_reorder;}
                virtual void reorder(){}

                virtual void expand(int a_size)=0;
                
            protected:
                
                virtual void incrementPosition(){
                    RawPointerListLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
                    this->m_position++;
                    RawPointerListLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
                }
                virtual void decrementPosition(){
                    RawPointerListLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
                    this->m_position--;
                    if(this->m_position < 0){
                        this->m_position = 0;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
                }
                
                virtual void incrementPosition(int a_size){
                    RawPointerListLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
                    this->m_position += a_size;
                    RawPointerListLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
                }
                virtual void decrementPosition(int a_size){
                    RawPointerListLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
                    this->m_position -= a_size;
                    if(this->m_position < 0){
                        this->m_position = 0;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
                }
                
                virtual void incrementSize(){
                    RawPointerListLog(pankey_Log_StartMethod, "incrementSize", "println", "");
                    this->m_size++;
                    RawPointerListLog(pankey_Log_EndMethod, "incrementSize", "println", "");
                }
                virtual void decrementSize(){
                    RawPointerListLog(pankey_Log_StartMethod, "decrementSize", "println", "");
                    this->m_size--;
                    if(this->m_size < 0){
                        this->m_size = 0;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "decrementSize", "println", "");
                }
                
                virtual void incrementSize(int a_size){
                    RawPointerListLog(pankey_Log_StartMethod, "incrementSize", "println", "");
                    this->m_size += a_size;
                    RawPointerListLog(pankey_Log_EndMethod, "incrementSize", "println", "");
                }
                virtual void decrementSize(int a_size){
                    RawPointerListLog(pankey_Log_StartMethod, "decrementSize", "println", "");
                    this->m_size -= a_size;
                    if(this->m_size < 0){
                        this->m_size = 0;
                    }
                    RawPointerListLog(pankey_Log_EndMethod, "decrementSize", "println", "");
                }

            public:
            
                virtual bool operator<(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator<", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator<", "println", "");
                    return this->getPosition() < x;
                }
                
                virtual bool operator>(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator>", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator>", "println", "");
                    return this->getPosition() > x;
                }
                
                virtual bool operator<=(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator<=", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator<=", "println", "");
                    return this->getPosition() <= x;
                }
                
                virtual bool operator>=(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator>=", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator>=", "println", "");
                    return this->getPosition() >= x;
                }
                
                virtual bool operator==(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator==", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator==", "println", "");
                    return this->getPosition() == x;
                }
                
                virtual bool operator!=(int x) const{
                    RawPointerListLog(pankey_Log_StartMethod, "operator!=", "println", "");
                    RawPointerListLog(pankey_Log_EndMethod, "operator!=", "println", "");
                    return this->getPosition() != x;
                }

            protected:
                bool m_reorder = true;
                bool m_owner = true;
                int m_position = 0;
                int m_size = 0;
        };

    }

#endif