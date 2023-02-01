#include <bits/stdc++.h>
using namespace std;

template<class T>

class mySet{
    int set_sz;
    int cap;
    T *set;

public:

//    default constructor for initialise my set attributes

    mySet()
    {
        set_sz=0 ;
        cap=0;
        set=new T[set_sz];
    }

//       default destructor

    ~mySet()
    {
        delete [] set;
    }

//    constructor with the number of elements of my set

    mySet(int n ){
    cap = n;
    set_sz = 0 ;
    set = new T[cap];
}

//      my insertion function (act like push )

    void insert(T item){
        if (!found(item)) {    // to check if my element already in my set or not
            if (set_sz < cap) {
                set[set_sz++] = item;
            }
            else {
                cap *= 2;
                T *newArr = new T[cap];
                for (int i = 0; i < cap; i++) {
                    newArr[i] = '\0';
                }
                for (int i = 0; i < set_sz; i++) {
                    newArr[i] = set[i];
                }
                newArr[set_sz++] = item;
                delete[] set;
                set = newArr;
            }
            sort(set, set + set_sz);
        }
    }

//   function to return the size of my set

int getSize (){
    return set_sz ;
}

//      overloading for [] operator to get the element with its index from the set

T operator[](int index ){

//   exception handling to avoid user error if he asks for an index is not already in my set

    try {
        if (index >= set_sz) {
            throw " Index out of the Set range ";
        }
    }
    catch (const char *str) {
        cout << str<<"\n";
    }

    return set[index];
}

//      function to determine if this element is already in my set or not

bool found(T item){
    bool check =false;
    for (int i=0;i<set_sz;i++)
    {
        check = (item == set[i]);
        if (check) break;
    }

    return check;
}

//         function to remove items from the set  ( acts like pop )

    void removeItem(T item){
        if(!found(item))
        {
            cout<<"This element is not in your set \n";
        }
        else {
            int index;
            int index2=-1;
            for (int i = 0 ; i < set_sz ; i++) {
                if ( set[i] == item ) {
                    index =i;
                    break;
                }
            }
            set_sz--;
            T* newArr;
            newArr = new T [cap];
            for (int i=0;i<set_sz;i++)
            {
                for(int j=0;j<set_sz+1;j++)
                {
                    if (index!=j and index2<j)
                    {
                        newArr[i]=set[j];
                        index2 = j;
                        break;
                    }
                }
            }
            delete [] set;
            set =newArr;
            sort (set,set+set_sz);
        }
    }

//      overloading for == operator to determine if two sets are equal or not

    bool operator == (mySet<T> set2 ){
        if (this->set_sz!= set2.set_sz){
            return false;
        }

        for (int i = 0 ; i < set_sz ; ++i) {
            if  (this->set[i] != set2.set[i]){
                return false ;
            }
        }
        return true ;

}

//      overloading for != operator to determine if two sets are equal or not

    bool operator != (mySet<T> set2 ){
        return !(*this == set2);
}

//    function to return a pointer to a dynamically created array containing each item in the set

    T* getArr(){
        return set;
    }

//      overloading for << operator to show my set elements

    friend ostream &operator  <<(ostream &out , mySet<T> & set){
        for (int i = 0 ; i< set.set_sz ; i++){
            out << set[i] <<" ";
        }
        return out;
    }
};

int main() {

//     Trying the set

    mySet<int> set1 ;
    set1.insert(2);
    set1.insert(1);
    set1.insert(2);
    set1.insert(1);
    set1.insert(2);
    set1.insert(10236541);
    set1.insert(3);

    mySet<int> set2 ;
    set2.insert(2);
    set2.insert(1);
    set2.insert(5);
    set2.insert(3);

// Trying cout << overloaded

    cout << set1;
    cout<<endl;
    cout << set2;
    cout<<endl;

// == and != overloading
    if (set1==set2){
        cout <<"two sets are equal \n";
    }
    else {
        cout <<"are not equal \n";
    }

//    cout << (set1!=set2) ;
//    cout << "\n";



//          removing elements .

    set1.removeItem(12);
    set1.removeItem(10236541);
    cout << "After Removing: \n";
    cout << set1;
    cout << endl;


//          return a pointer to a dynamically created array containing each item in the set

//    cout<< set1.getArr();

// check if an element is found or not .

    if(set1.found(90)){
        cout << "item exist \n";
    }
    else {
        cout << "item not exist \n";
    }

//      showing the set size

    cout << set1.getSize();
}
