

#ifndef FluxEvent_h
#define FluxEvent_h

#include "ArrayList.h"
#include "PList.h"
#include "List.h"
#include "Map.h"
#include "KPMap.h"
#include "FluxNMap.h"
#include "NMapEvent.h"
#include "Arduino.h"

template <class N,int Nm,int Nl,class K,class V,int Ms,class L, int Ls>
class FluxEvent : public NMapEvent<N,Nm,Nl,K,V,Ms,L,Ls> , public FluxNMap<N,K,V,L>{
	private:	
	
    public:
		KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nestMap;
		List<FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>> *fluxmaplist;     
		List<N> *fluxnames;     
		N fluxname;    
		N fluxsubname; 
		FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *fluxmap; 	
	
		FluxEvent(N n):NMapEvent<N,Nm,Nl,K,V,Ms,L,Ls>(n){
			nestMap = new KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm>();
			fluxnames = new ArrayList<N,11>();
			fluxmap = this;
			fluxmaplist = new PList<FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,11>();
		}
		FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> operator=(const FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>& a){
			return FluxEvent(this->getName());
		}
		bool operator==(FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>& a){
			return this->getName()==a.getName();
		}
		bool operator!=(FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>& a){
			return this->getName()!=a.getName();
		}
		
		void NestMap(N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested->get(this->getName()) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(this->getName())->get(subName);
					if(nmap == NULL){
						nested->get(this->getName())->add(subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(subName));
					}
					nested = nested->get(this->getName())->get(subName)->nestMap;   
				}else{
					nested->add(this->getName(), new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(this->getName())->add(subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(subName));
					nested = nested->get(this->getName())->get(subName)->nestMap;                  
				}		
		}
		
		void NestMap(N *subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested->get(this->getName()) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(this->getName())->get(*subName);
					if(nmap == NULL){
						nested->get(this->getName())->add(*subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*subName));
					}
					nested = nested->get(this->getName())->get(*subName)->nestMap;   
				}else{
					nested->add(this->getName(), new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(this->getName())->add(*subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*subName));
					nested = nested->get(this->getName())->get(*subName)->nestMap;                  
				}		
		}
		
		void NestMap(N mainName,N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested->get(mainName) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(mainName)->get(subName);
					if(nmap == NULL){
						nested->get(mainName)->add(subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(subName));
					}
					nested = nested->get(mainName)->get(subName)->nestMap;   
				}else{
					nested->add(mainName, new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(mainName)->add(subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(subName));
					nested = nested->get(mainName)->get(subName)->nestMap;                  
				}		
		}
		
		void NestMap(N *mainName,N *subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested->get(*mainName) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(*mainName)->get(*subName);
					if(nmap == NULL){
						nested->get(*mainName)->add(*subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*subName));
					}
					nested = nested->get(*mainName)->get(*subName)->nestMap;   
				}else{
					nested->add(*mainName, new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(*mainName)->add(*subName,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*subName));
					nested = nested->get(*mainName)->get(*subName)->nestMap;                  
				}		
		}
		
		void NestMap(N mainName,List<N> *arrayMap){
			int size = arrayMap->getPos();
			if(size == 0){
				return;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < size; x++) {
				N *arrayGet = arrayMap->getByPos(x);
				if(nested->get(mainName) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(mainName)->get(*arrayGet);
					if(nmap == NULL){
						nested->get(mainName)->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					}
					nested = nested->get(mainName)->get(*arrayGet)->nestMap;   
				}else{
					nested->add(mainName, new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(mainName)->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					nested = nested->get(mainName)->get(*arrayGet)->nestMap;                  
				}    
			}			
		}
		
		void NestMap(N *mainName,List<N> *arrayMap){
			int size = arrayMap->getPos();
			if(size == 0){
				return;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < size; x++) {
				N *arrayGet = arrayMap->getByPos(x);
				if(nested->get(mainName) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(mainName)->get(*arrayGet);
					if(nmap == NULL){
						nested->get(mainName)->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					}
					nested = nested->get(mainName)->get(*arrayGet)->nestMap;   
				}else{
					nested->add(mainName, new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(mainName)->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					nested = nested->get(mainName)->get(*arrayGet)->nestMap;                  
				}    
			}			
		}
		
		void NestMap(List<N> *arrayMap){
			int size = arrayMap->getPos();
			if(size == 0){
				return;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < size; x++) {
				N *arrayGet = arrayMap->getByPos(x);
				if(nested->get(this->getName()) != NULL){
					FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls> *nmap = nested->get(this->getName())->get(*arrayGet);
					if(nmap == NULL){
						nested->get(this->getName())->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					}
					nested = nested->get(this->getName())->get(*arrayGet)->nestMap;   
				}else{
					nested->add(this->getName(), new KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>());
					nested->get(this->getName())->add(*arrayGet,new FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>(*arrayGet));
					nested = nested->get(this->getName())->get(*arrayGet)->nestMap;                  
				}    
			}			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested != NULL){
					if(nested->get(this->getName()) != NULL){
						nested = nested->get(this->getName())->get(subName)->nestMap; 
					}
				}else{
					return NULL;
				}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N *subName){
			if(subName == NULL){
				return NULL;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested != NULL){
					if(nested->get(this->getName()) != NULL){
						nested = nested->get(this->getName())->get(*subName)->nestMap; 
					}
				}else{
					return NULL;
				}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(List<N> *n){
			if(n->getPos() == 0){
				return (Map<N,Map<N,NMap<N,K,V,L>>>*)nestMap;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < n->getPos(); x++) {
				N *nGet = n->getByPos(x);
				if(nested != NULL){
					if(nested->get(this->getName()) != NULL){
						nested = nested->get(this->getName())->get(*nGet)->nestMap; 
					}
				}else{
					return NULL;
				}
			}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N mainName, N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested != NULL){
					if(nested->get(mainName) != NULL){
						nested = nested->get(mainName)->get(subName)->nestMap; 
					}
				}else{
					return NULL;
				}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N *mainName, N *subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
				if(nested != NULL){
					if(nested->get(*mainName) != NULL){
						nested = nested->get(*mainName)->get(*subName)->nestMap; 
					}
				}else{
					return NULL;
				}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N mainName, List<N> *n){
			if(n->getPos() == 0){
				return (Map<N,Map<N,NMap<N,K,V,L>>>*)nestMap;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < n->getPos(); x++) {
				N *nGet = n->getByPos(x);
				if(nested != NULL){
					if(nested->get(mainName) != NULL){
						nested = nested->get(mainName)->get(*nGet)->nestMap; 
					}
				}else{
					return NULL;
				}
			}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;			
		}
		
		Map<N,Map<N,NMap<N,K,V,L>>> *getNestMap(N *mainName, List<N> *n){
			if(n->getPos() == 0){
				return (Map<N,Map<N,NMap<N,K,V,L>>>*)nestMap;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			for (int x = 0; x < n->getPos(); x++) {
				N *nGet = n->getByPos(x);
				if(nested != NULL){
					if(nested->get(*mainName) != NULL){
						nested = nested->get(*mainName)->get(*nGet)->nestMap; 
					}
				}else{
					return NULL;
				}
			}
			return (Map<N,Map<N,NMap<N,K,V,L>>>*)nested;
			
		}
		
		NMap<N,K,V,L> *getNMap(N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
				if(nested != NULL){
					if(nested->get(this->getName()) != NULL){
						nmap = nested->get(this->getName())->get(subName);
						nested = nested->get(this->getName())->get(subName)->nestMap;
					}
				}else{
					return NULL;
				}
			this->fluxsubname = subName;
			this->fluxname = this->getName();
			return nmap;			
		}
		
		NMap<N,K,V,L> *getNMap(N *subName){
			if(subName == NULL){
				return this;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
				if(nested != NULL){
					if(nested->get(this->getName()) != NULL){
						nmap = nested->get(this->getName())->get(*subName);
						nested = nested->get(this->getName())->get(*subName)->nestMap;
					}
				}else{
					return NULL;
				}
			this->fluxsubname = *subName;
			this->fluxname = this->getName();
			return nmap;			
		}
		
		NMap<N,K,V,L> *getNMap(N mainName,N subName){
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
				if(nested != NULL){
					if(nested->get(mainName) != NULL){
						nmap = nested->get(mainName)->get(subName);
						nested = nested->get(mainName)->get(subName)->nestMap;
					}
				}else{
					return NULL;
				}
			this->fluxsubname = subName;
			this->fluxname = mainName;
			return nmap;			
		}
		
		NMap<N,K,V,L> *getNMap(N *mainName,N *subName){
			if(subName == NULL){
				return this;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
				if(nested != NULL){
					if(nested->get(*mainName) != NULL){
						nmap = nested->get(*mainName)->get(*subName);
						nested = nested->get(*mainName)->get(*subName)->nestMap;
					}
				}else{
					return NULL;
				}
			this->fluxsubname = *subName;
			this->fluxname = *mainName;
			return nmap;			
		}
		
		NMap<N,K,V,L> *getNMap(N mainName, List<N> *n){
			if(n->getPos() == 0){
				return this;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
			for (int x = 0; x < n->getPos(); x++) {
				N *nGet = n->getByPos(x);
				if(nested != NULL){
					if(nested->get(mainName) != NULL){
						nmap = nested->get(mainName)->get(*nGet);
						nested = nested->get(mainName)->get(*nGet)->nestMap;
					}
				}else{
					return NULL;
				}
			}
			this->fluxsubname = mainName;
			this->fluxname = *n->getByPos(n->getPos()-1);
			this->fluxnames = n;
			return nmap;			
		}
		
		NMap<N,K,V,L> *getNMap(N *mainName, List<N> *n){
			if(n->getPos() == 0){
				return this;
			}
			KPMap<N,KPMap<K,FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>,Ms>,Nm> *nested = this->nestMap;
			NMap<N,K,V,L> *nmap = this;
			for (int x = 0; x < n->getPos(); x++) {
				N *nGet = n->getByPos(x);
				if(nested != NULL){
					if(nested->get(*mainName) != NULL){
						nmap = nested->get(*mainName)->get(*nGet);
						nested = nested->get(*mainName)->get(*nGet)->nestMap;
					}
				}else{
					return NULL;
				}
			}
			this->fluxsubname = *mainName;
			this->fluxname = *n->getByPos(n->getPos()-1);
			this->fluxnames = n;
			return nmap;			
		}
		
		N getFluxName(){
			return fluxname;
		}
		
		List<N> *getFluxNames(){
			return fluxnames;			
		}
		
		N getFluxSubName(){
			return fluxsubname;	
		}
		
		NMap<N,K,V,L> *getFluxMap(){
			return fluxmap;	
		}
		
		FluxNMap<N,K,V,L> *next(N subName){
			fluxmap->NestMap(subName);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(subName);
			fluxmaplist->add(fluxmap);
		}
		
		FluxNMap<N,K,V,L> *next(N *subName){
			fluxmap->NestMap(subName);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(subName);	
			fluxmaplist->add(fluxmap);				
		}
		
		FluxNMap<N,K,V,L> *next(N mainName,N subName){
			fluxmap->NestMap(mainName,subName);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(mainName,subName);	
			fluxmaplist->add(fluxmap);				
		}
		
		FluxNMap<N,K,V,L> *next(N *mainName,N *subName){
			fluxmap->NestMap(mainName,subName);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(mainName,subName);
			fluxmaplist->add(fluxmap);			
		}
		
		FluxNMap<N,K,V,L> *next(N mainName, List<N> *n){
			fluxmap->NestMap(mainName,n);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(mainName,n);	
			fluxmaplist->add(fluxmap);		
		}	
		
		FluxNMap<N,K,V,L> *next(N *mainName, List<N> *n){
			fluxmap->NestMap(mainName,n);
			fluxmap = (FluxEvent<N,Nm,Nl,K,V,Ms,L,Ls>*)getNestMap(mainName,n);	
			fluxmaplist->add(fluxmap);
		}
		
		FluxNMap<N,K,V,L> *last(){			
			fluxmaplist->remove(fluxmap);
			fluxmap = fluxmaplist->getByPos(fluxmaplist->getPos()-1);	
		}	
		
		FluxNMap<N,K,V,L> *restart(){
			fluxmaplist->reset();
			fluxmap = this;	
		}	
};

#endif 
