
#ifndef RawPointerTree_hpp
    #define RawPointerTree_hpp

    #include "Array.hpp"

    #ifdef RawPointerTree_LogApp
        #include "pankey_Logger_config.hpp"
        #define RawPointerTreeLog(location,method,type,mns) pankey_Log((void*)this,location,"RawPointerTree",method,type,mns)
    #else
        #define RawPointerTreeLog(location,method,type,mns)
    #endif

    namespace pankey{

        template <class T>
        class RawPointerTree{
            public:
                virtual ~RawPointerTree(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "Destructor", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "Destructor", "println", "");
                }
                
                virtual void setBranchOwner(bool a_owning){
                    RawPointerTreeLog(pankey_Log_StartMethod, "setBranchOwner", "println", "");
                    this->m_branch_owner = a_owning;
                    RawPointerTreeLog(pankey_Log_EndMethod, "setBranchOwner", "println", "");
                }
                virtual bool isBranchOwner()const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "isBranchOwner", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "isBranchOwner", "println", "");
                    return this->m_branch_owner;
                }
                virtual void setValueOwner(bool a_owning){
                    RawPointerTreeLog(pankey_Log_StartMethod, "setValueOwner", "println", "");
                    this->m_value_owner = a_owning;
                    RawPointerTreeLog(pankey_Log_EndMethod, "setValueOwner", "println", "");
                }
                virtual bool isValueOwner()const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "isValueOwner", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "isValueOwner", "println", "");
                    return this->m_value_owner;
                }
                virtual void setPosition(int a_position){
                    RawPointerTreeLog(pankey_Log_StartMethod, "setPosition", "println", "");
                    this->m_position = a_position;
                    RawPointerTreeLog(pankey_Log_EndMethod, "setPosition", "println", "");
                }
                virtual int getPosition()const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "getPosition", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "getPosition", "println", "");
                    return this->m_position;
                }
                
                virtual void setSize(int a_size){
                    RawPointerTreeLog(pankey_Log_StartMethod, "setSize", "println", "");
                    this->m_size = a_size;
                    RawPointerTreeLog(pankey_Log_EndMethod, "setSize", "println", "");
                }
                virtual int getSize()const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "getSize", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "getSize", "println", "");
                    return this->m_size;
                }
                
                virtual RawPointerTree<T>* setParent(RawPointerTree<T>* a_parent){
                    this->m_parent = a_parent;
                    return this->m_parent;
                }
                
                virtual RawPointerTree<T>* getParent(){
                    return this->m_parent;
                }
                
                virtual RawPointerTree<T>* removeParent(){
                    RawPointerTree<T>* i_parent = this->m_parent;
                    this->m_parent = nullptr;
                    return this->m_parent;
                }
                
                virtual bool removeDeleteParent(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeDeleteParent", "println", "");
                    RawPointerTree<T>* i_parent = this->removeParent();
                    if(i_parent == nullptr){
                        return false;
                    }
                    delete i_parent;
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeDeleteParent", "println", "");
                    return true;
                }
                
                virtual int setBranchPosition(int a_position){
                    this->m_branch_position = a_position;
                    return this->m_branch_position;
                }
                
                virtual int getBranchPosition(){
                    return this->m_branch_position;
                }
                
                virtual int removeBranchPosition(){
                    int i_position = this->m_branch_position;
                    this->m_branch_position = -1;
                    return i_position;
                }
                
                virtual RawPointerTree<T>* getNextBranchFromParent(){
                    if(this->m_parent == nullptr || this->m_branch_position == -1){
                        return nullptr;
                    }
                    if((this->m_parent->getPosition() - 1) == this->m_branch_position){
                        return nullptr;
                    }
                    return this->m_parent->getBranchByPosition(this->m_branch_position + 1);
                }
                
                virtual RawPointerTree<T>* getNextBranch(RawPointerTree<T>* a_branch){
                    if(a_branch == nullptr){
                        return nullptr;
                    }
                    if(a_branch->m_parent == nullptr || a_branch->m_branch_position == -1){
                        return nullptr;
                    }
                    if((a_branch->m_parent->getPosition() - 1) == a_branch->m_branch_position){
                        return nullptr;
                    }
                    return a_branch->m_parent->getBranchByPosition(a_branch->m_branch_position + 1);
                }
                
                virtual T* set(T* a_value)=0;
                
                virtual T* get()=0;
                
                virtual T* remove()=0;
                
                virtual bool removeDelete(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeDelete", "println", "");
                    T* i_var = this->remove();
                    if(i_var == nullptr){
                        return false;
                    }
                    delete i_var;
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeDelete", "println", "");
                    return true;
                }
                
                virtual bool isEmpty()const=0;

                virtual bool replaceBranch(int i, int j)=0;
                
                virtual void addMoveBranch(RawPointerTree<T>* a_list){
                    RawPointerTreeLog(pankey_Log_StartMethod, "addMoveBranch", "println", "");
                    for(int x = 0; x < a_list->getPosition(); x++){
                        RawPointerTree<T>* f_value = a_list->getBranchByPosition(x);
                        this->addBranchPointer(f_value);
                    }
                    a_list->clearBranches();
                    RawPointerTreeLog(pankey_Log_EndMethod, "addMoveBranch", "println", "");
                }
                
                virtual void addDuplicateBranch(RawPointerTree<T>* a_list){
                    RawPointerTreeLog(pankey_Log_StartMethod, "addDuplicateBranch", "println", "");
                    this->setBranchOwner(false);
                    for(int x = 0; x < a_list->getPosition(); x++){
                        RawPointerTree<T>* f_value = a_list->getBranchByPosition(x);
                        this->addBranchPointer(f_value);
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "addDuplicateBranch", "println", "");
                }

                virtual RawPointerTree<T>* addBranchPointer(RawPointerTree<T>* a_value)=0;
                
                virtual RawPointerTree<T>* putBranchPointer(RawPointerTree<T>* a_value){
                    RawPointerTreeLog(pankey_Log_StartMethod, "putPointer", "println", "");
                    if(this->containBranchByPointer(a_value)){
                        return a_value;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "putPointer", "println", "");
                    return this->addBranchPointer(a_value);
                }

                virtual RawPointerTree<T>* setBranchPointer(int a_position, RawPointerTree<T>* a_value)=0;

                virtual RawPointerTree<T>* insertBranchPointer(int a_position, RawPointerTree<T>* a_value)=0;

                virtual RawPointerTree<T>* getBranchByPointer(RawPointerTree<T>* a_value)=0;
                virtual RawPointerTree<T>* getBranchByPosition(int x)const=0;
                
                virtual int getBranchIndexByPointer(RawPointerTree<T>* a_value)=0;

                virtual bool containBranchByPointer(RawPointerTree<T>* a_value)=0;

                virtual void clearBranches()=0;
                virtual void clearDeleteBranches()=0;

                // virtual void clearValue()=0;
                // virtual void clearDeleteValue()=0;

                // virtual void clearNode()=0;
                // virtual void clearDeleteNode()=0;

                virtual RawPointerTree<T>* removeBranchByPointer(RawPointerTree<T>* a_value)=0;

                virtual RawPointerTree<T>* removeBranchByPosition(int a_position)=0;

                virtual bool removeDeleteBranchByPointer(RawPointerTree<T>* a_value){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeDeleteBranchByPointer", "println", "");
                    RawPointerTree<T>* t = this->removeBranchByPointer(a_value);
                    bool removed = t != nullptr;
                    if(removed && this->isBranchOwner()){
                        delete t;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeDeleteBranchByPointer", "println", "");
                    return removed;
                }

                virtual bool removeDeleteBranchByPosition(int a_position){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeDeleteBranchByPosition", "println", "");
                    RawPointerTree<T>* t = this->removeBranchByPosition(a_position);
                    bool removed = t != nullptr;
                    if(removed && this->isBranchOwner()){
                        delete t;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeDeleteBranchByPosition", "println", "");
                    return removed;
                }

                //special removes
                virtual bool removeBranchFirstIndex(int a_amount)=0;
                virtual bool removeBranchLastIndex(int a_amount)=0;
                
                virtual bool removeFirstBranch(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeFirstBranch", "println", "");
                    if(this->isEmpty()){
                        return false;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeFirstBranch", "println", "");
                    return this->removeDeleteBranchByPosition(0);
                }

                virtual bool removeLastBranch(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "removeLastBranch", "println", "");
                    if(this->isEmpty()){
                        return false;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "removeLastBranch", "println", "");
                    return this->removeDeleteBranchByPosition(this->getPosition() - 1);
                }

                virtual bool isInOrder(){return this->m_reorder;}
                virtual void setReorder(bool a_reorder){this->m_reorder = a_reorder;}
                virtual void reorder(){}

                virtual RawPointerTree<T>* createBranch(const Array<int>& a_location)=0;

                virtual void createBranches(const Array<int>& a_location, int a_branches_size)=0;

                virtual RawPointerTree<T>* getBranch(const Array<int>& a_location)=0;

                virtual T* setBranchValuePointer(const Array<int>& a_location, T* a_value){
					RawPointerTreeLog(pankey_Log_StartMethod, "setBranchValuePointer", "println", "");
					RawPointerTree<T>* i_sub_tree = this->createBranch(a_location);
					if(i_sub_tree == nullptr){
						return nullptr;
					}
					RawPointerTreeLog(pankey_Log_EndMethod, "setBranchValuePointer", "println", "");
                    return i_sub_tree->set(a_value);
                }

                virtual T* getBranchValuePointer(const Array<int>& a_location){
					RawPointerTreeLog(pankey_Log_StartMethod, "setBranchValuePointer", "println", "");
					RawPointerTree<T>* i_sub_tree = this->getBranch(a_location);
					if(i_sub_tree == nullptr){
						return nullptr;
					}
					RawPointerTreeLog(pankey_Log_EndMethod, "setBranchValuePointer", "println", "");
                    return i_sub_tree->get();
                }

                template<class IM, class... Args>
				void forEachTopDownPointer(IM a_iteration_method, Args... args){
					RawPointerTreeLog(pankey_Log_StartMethod, "forEachTopDownPointer", "println", "");

                    Array<int> i_location;
                    RawPointerTree<T>* i_actual_tree = this;
                    T* i_actual_value = this->get();
                    int i_branch_position = 0;
                    int i_branch_iteration = 0;

					a_iteration_method(i_branch_iteration, i_location, i_actual_tree, i_actual_value, args...);
                    i_branch_iteration++;

                    for(int x = 1; i_actual_tree != nullptr; x++){
						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "iteration: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", x);
						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "branch_position: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", i_branch_position);
                        
                        RawPointerTree<int>* i_sub_tree_iterator_sub = nullptr;

                        for(int x_sub = i_branch_position; x_sub < i_actual_tree->getPosition(); x_sub++){
                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "iteration sub: ");
                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", x_sub);
                            i_sub_tree_iterator_sub = i_actual_tree->getBranchByPosition(x_sub);
                            if(i_sub_tree_iterator_sub != nullptr){
                                RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "x_sub i_sub_tree_iterator_sub != nullptr");
                                i_location.addLocalValue(x_sub);
                                break;
                            }
                        }

                        if(i_sub_tree_iterator_sub != nullptr){
						    RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "i_sub_tree_iterator_sub != nullptr");
                            i_actual_tree = i_sub_tree_iterator_sub;
                            i_branch_position = 0;

                            i_actual_value = i_actual_tree->get();
                            a_iteration_method(i_branch_iteration, i_location, i_actual_tree, i_actual_value, args...);
                            i_branch_iteration++;
                            continue;
                        }

                        if(i_actual_tree == this){
                            i_actual_tree = nullptr;
                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "i_sub_tree_iterator_parent != nullptr");
                            continue;
                        }

                        RawPointerTree<int>* i_sub_tree_iterator_parent = i_actual_tree->getParent();

                        i_location.removeLastIndex();

                        if(i_sub_tree_iterator_parent->getPosition() == i_actual_tree->getBranchPosition() + 1){
                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "i_sub_tree_iterator_parent->getPosition() == i_actual_tree->getBranchPosition() + 1");
                            i_actual_tree = i_sub_tree_iterator_parent->getParent();
                            i_branch_position = i_sub_tree_iterator_parent->getBranchPosition() + 1;
                            
                            i_location.removeLastIndex();

                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "parent new branch_position: ");
                            RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", i_branch_position);
                            continue;
                        }

                        i_branch_position = i_actual_tree->getBranchPosition() + 1;
                        i_actual_tree = i_sub_tree_iterator_parent;

						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", "new branch_position: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachTopDownPointer", "println", i_branch_position);
                    }

					RawPointerTreeLog(pankey_Log_EndMethod, "forEachTopDownPointer", "println", "");
				}

                template<class IM, class... Args>
				void forEachDownTopPointer(IM a_iteration_method, Args... args){
					RawPointerTreeLog(pankey_Log_StartMethod, "forEachDownTopPointer", "println", "");

                    Array<int> i_location;
                    RawPointerTree<T>* i_actual_tree = this;
                    T* i_actual_value = this->get();
                    int i_branch_position = 0;
                    int i_branch_iteration = 0;

                    for(int x = 0; i_actual_tree != nullptr; x++){
						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "iteration: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", x);
						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "branch_position: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", i_branch_position);
                        
                        RawPointerTree<int>* i_sub_tree_iterator_sub = nullptr;

                        for(int x_sub = i_branch_position; x_sub < i_actual_tree->getPosition(); x_sub++){
                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "iteration sub: ");
                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", x_sub);
                            i_sub_tree_iterator_sub = i_actual_tree->getBranchByPosition(x_sub);
                            if(i_sub_tree_iterator_sub != nullptr){
                                RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "x_sub i_sub_tree_iterator_sub != nullptr");
                                i_location.addLocalValue(x_sub);
                                break;
                            }
                        }

                        if(i_sub_tree_iterator_sub != nullptr){
						    RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "i_sub_tree_iterator_sub != nullptr");
                            i_actual_tree = i_sub_tree_iterator_sub;
                            i_branch_position = 0;
                            continue;
                        }
                        
                        i_actual_value = i_actual_tree->get();
                        a_iteration_method(i_branch_iteration, i_location, i_actual_tree, i_actual_value, args...);
                        i_branch_iteration++;

                        if(i_actual_tree == this){
                            i_actual_tree = nullptr;
                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "i_sub_tree_iterator_parent != nullptr");
                            continue;
                        }

                        RawPointerTree<int>* i_sub_tree_iterator_parent = i_actual_tree->getParent();

                        i_location.removeLastIndex();

                        if(i_sub_tree_iterator_parent->getPosition() == i_actual_tree->getBranchPosition() + 1){
                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "i_sub_tree_iterator_parent->getPosition() == i_actual_tree->getBranchPosition() + 1");
                            i_actual_tree = i_sub_tree_iterator_parent->getParent();
                            i_branch_position = i_sub_tree_iterator_parent->getBranchPosition() + 1;

                            a_iteration_method(i_branch_iteration, i_location, i_sub_tree_iterator_parent, i_sub_tree_iterator_parent->get(), args...);
                            i_branch_iteration++;
                            
                            i_location.removeLastIndex();

                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "parent new branch_position: ");
                            RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", i_branch_position);
                            continue;
                        }

                        i_branch_position = i_actual_tree->getBranchPosition() + 1;
                        i_actual_tree = i_sub_tree_iterator_parent;

						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", "new branch_position: ");
						RawPointerTreeLog(pankey_Log_Statement, "forEachDownTopPointer", "println", i_branch_position);
                    }

					RawPointerTreeLog(pankey_Log_EndMethod, "forEachDownTopPointer", "println", "");
				}

				virtual void expandLocal(int a_size)=0;

				virtual RawPointerTree<T>* expand(int a_size)=0;
                
            protected:
                
                virtual void incrementPosition(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
                    this->m_position++;
                    RawPointerTreeLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
                }
                virtual void decrementPosition(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
                    this->m_position--;
                    if(this->m_position < 0){
                        this->m_position = 0;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
                }
                
                virtual void incrementPosition(int a_size){
                    RawPointerTreeLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
                    this->m_position += a_size;
                    RawPointerTreeLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
                }
                virtual void decrementPosition(int a_size){
                    RawPointerTreeLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
                    this->m_position -= a_size;
                    if(this->m_position < 0){
                        this->m_position = 0;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
                }
                
                virtual void incrementSize(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "incrementSize", "println", "");
                    this->m_size++;
                    RawPointerTreeLog(pankey_Log_EndMethod, "incrementSize", "println", "");
                }
                virtual void decrementSize(){
                    RawPointerTreeLog(pankey_Log_StartMethod, "decrementSize", "println", "");
                    this->m_size--;
                    if(this->m_size < 0){
                        this->m_size = 0;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "decrementSize", "println", "");
                }
                
                virtual void incrementSize(int a_size){
                    RawPointerTreeLog(pankey_Log_StartMethod, "incrementSize", "println", "");
                    this->m_size += a_size;
                    RawPointerTreeLog(pankey_Log_EndMethod, "incrementSize", "println", "");
                }
                virtual void decrementSize(int a_size){
                    RawPointerTreeLog(pankey_Log_StartMethod, "decrementSize", "println", "");
                    this->m_size -= a_size;
                    if(this->m_size < 0){
                        this->m_size = 0;
                    }
                    RawPointerTreeLog(pankey_Log_EndMethod, "decrementSize", "println", "");
                }

            public:
            
                virtual bool operator<(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator<", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator<", "println", "");
                    return this->getPosition() < x;
                }
                
                virtual bool operator>(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator>", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator>", "println", "");
                    return this->getPosition() > x;
                }
                
                virtual bool operator<=(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator<=", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator<=", "println", "");
                    return this->getPosition() <= x;
                }
                
                virtual bool operator>=(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator>=", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator>=", "println", "");
                    return this->getPosition() >= x;
                }
                
                virtual bool operator==(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator==", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator==", "println", "");
                    return this->getPosition() == x;
                }
                
                virtual bool operator!=(int x) const{
                    RawPointerTreeLog(pankey_Log_StartMethod, "operator!=", "println", "");
                    RawPointerTreeLog(pankey_Log_EndMethod, "operator!=", "println", "");
                    return this->getPosition() != x;
                }

            protected:
                bool m_reorder = true;
                bool m_branch_owner = true;
                bool m_value_owner = true;
                int m_position = 0;
                int m_size = 0;

                RawPointerTree<T>* m_parent = nullptr;
                int m_branch_position = -1;

            protected:
        };

    }

#endif