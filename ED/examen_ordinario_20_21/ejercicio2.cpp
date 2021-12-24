#include <iostream>
#include <vector>
#include <list>
#include <cassert>


class matriz_singular{

    private:
        vector<list<int>> matriz;

    public:

    int & operator()(pair<int i , int j> par){
        assert(par.first >=0 && par.first< matriz.size() && par.second >=0 && par.second < matriz.size())
        list<int>::iterator lit;
        lit = matriz[par.first].begin();

        for( int i = 0; i < par.second; i++){
           ++lit;
        }
        
        return *lit
    }

}