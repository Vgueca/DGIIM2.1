#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>

using namespace std;

/**
 * Cada componente del vector representa una fila de la matriz, cuyos elementos
 * se encuentran contenidos en una lista. (vector de filas = vector de listas).
*/
class MatrizSingular{
    private:
        vector<list<int>> m;

    public:
        int & operator()(pair<int,int> p){
            if(p.first>=0 && p.first < m.size() && p.second >=0 && p.second<m.size()){
                list<int>::iterator it = m[p.first].begin();
                for(int i=0; i<p.second; i++)
                    it++;
                return *it;
            }
        }

        class iterator{
			private:
				list<int>::iterator l;

			public:
				iterator(){}

				iterator(const iterator & it){
					*this = it;
				}

				iterator & operator = (const iterator &it){
					if(this != &it){
						l = it.l;
					}
					return *this;
				}

				iterator & operator ++(){
					++l;
					return * this;
				}
				
				iterator & operator --(){
					--l;
					return * this;
				}

				bool operator == (const iterator  & it) const{
					return it.l == l;
				}

				bool operator !=(const iterator  & it) const{
					return it.l !=l;
				}

				int & operator*(){
					return *l;
				}

				friend class MatrizSingular;
		};

        iterator begin(){
			iterator it;
			it.l = m[0].begin();
			return it;
		} 

        iterator end(){
			iterator it;
			it.l = m[m.size()-1].end();
			return it;
		}

        class it_impar{
			private:
				MatrizSingular::iterator l;

			public:
				it_impar(){}

				it_impar(const it_impar & it){
					*this = it;
				}

				it_impar & operator = (const it_impar &it){
					if(this != &it){
						l = it.l;
					}
					return *this;
				}

				it_impar & operator ++(){
					++l;
                    bool fin = false;
                    while(!fin){
                        if((*l)/2==0){
                            ++l;
                        }
                        else{
                            fin = true;
                        }
                    }
					return *this;
				}
				
				it_impar & operator --(){
					--l;
                    bool fin = false;
                    while(!fin){
                        if((*l)/2==0){
                            --l;
                        }
                        else{
                            fin = true;
                        }
                    }
					return *this;
				}

				bool operator == (const it_impar  & it) const{
					return it.l == l;
				}

				bool operator !=(const it_impar  & it) const{
					return it.l !=l;
				}

				int & operator*(){
					return *l;
				}

				friend class MatrizSingular;
		};

        it_impar begin_i(){
			it_impar it;
            bool fin = false;
            MatrizSingular::iterator mit = begin();
            while(!fin){
                if(*(mit)/2==0){
                    ++mit;
                }
                else{
                    it.l = mit;
                    fin = true;
                }
            }
			return it;
		} 

        it_impar end_i(){
			it_impar it;
            bool fin = false;
            MatrizSingular::iterator mit = end();
            --mit;
            while(!fin){
                if(*(mit)/2==0){
                    --mit;
                }
                else{
                    it.l = mit;
                    fin = true;
                }
            }
			return it;
		}

};
