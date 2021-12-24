#include <iostream>
#include <list>
#include <set>


bool set_contenido(set<int> A, set<int> B){
    set<int>::iterator itA = A.begin();

    for(; itA != A.end(); ++itA){
        if(B.find((*itA)) == B.end()){      
            return false;
        }
    }
    return true;
}

bool proper_subset(list< set<int> > &L){
    list<set<int>>::iterator it,it2;
    bool contenido = true;
    bool terminar = false;
    
    for(it = L.begin(); it!=L.end() && !terminar; ++it){
        it2 = it;
        ++it2;
        if(!set_contenido( (*it), (*it2) ) ){
            contenido = false;
        }
        if(!contenido || it2 == L.end()){
            terminar  = true;
        }
    }
    return cotenido;
}



