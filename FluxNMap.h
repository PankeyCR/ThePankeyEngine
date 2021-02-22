

#ifndef FluxNMap_h
#define FluxNMap_h

#include "List.h"
#include "Map.h"
#include "NMap.h"

template <class N,class K,class V,class L>
class FluxNMap{
public:
	virtual void NestMap(N subName)=0;
	virtual void NestMap(N* subName)=0;
	virtual void NestMap(N mainName,N subName)=0;
	virtual void NestMap(N* mainName,N* subName)=0;
	virtual void NestMap(N mainName,List<N>* arrayMap)=0;
	virtual void NestMap(N *mainName,List<N>* arrayMap)=0;
	virtual void NestMap(List<N>* arrayMap)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N subName)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N* subName)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N mainName, N subName)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N* mainName, N* subName)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(List<N>* n)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N mainName, List<N>* n)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N *mainName, List<N>* n)=0;
	virtual NMap<N,K,V,L>* getNMap(N subName)=0;
	virtual NMap<N,K,V,L>* getNMap(N *subName)=0;
	virtual NMap<N,K,V,L>* getNMap(N mainName,N subName)=0;
	virtual NMap<N,K,V,L>* getNMap(N* mainName,N* subName)=0;
	virtual NMap<N,K,V,L>* getNMap(N mainName, List<N>* n)=0;
	virtual NMap<N,K,V,L>* getNMap(N *mainName, List<N>* n)=0;
	virtual N getFluxName()=0;
	virtual List<N>* getFluxNames()=0;
	virtual N getFluxSubName()=0;
	virtual NMap<N,K,V,L>* getFluxMap()=0;
	virtual FluxNMap<N,K,V,L>* next(N subName)=0;
	virtual FluxNMap<N,K,V,L>* next(N *subName)=0;
	virtual FluxNMap<N,K,V,L>* next(N mainName,N subName)=0;
	virtual FluxNMap<N,K,V,L>* next(N *mainName,N *subName)=0;
	virtual FluxNMap<N,K,V,L>* next(N mainName, List<N> *n)=0;
	virtual FluxNMap<N,K,V,L>* next(N *mainName, List<N> *n)=0;
	virtual FluxNMap<N,K,V,L>* last()=0;
	virtual FluxNMap<N,K,V,L>* restart()=0;
private:
};

#endif 
