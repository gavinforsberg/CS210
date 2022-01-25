#include "LeftistHeap.cpp"
#include <iostream>
using namespace std ;

int main()
{
    LeftistHeap<int> h1;
    LeftistHeap<int> h2;
    LeftistHeap<int> h3;
    
    cout << "-------------Displaying First Fest case---------------" << endl << endl ;
    h1.insert(5) ;
    h1.insert(6) ;
    h1.insert(12) ;
    h1.insert(15) ;
    
    h2.insert(7) ;
    h2.insert(14) ;
    h2.insert(3) ;
    h2.insert(8) ;
    h2.insert(11) ;
    
    h1.merge(h2) ;
    cout << "Leftist Min-Heap:" << endl ;
    h1.showLH() ;
    cout << "\nSPL Values:" << endl ;
    h1.showSPL() ;
    
    cout << "\n\n-------------Displaying Second Test Case--------------" << endl << endl ;
    h3.insert(77) ;
    h3.insert(22) ;
    h3.insert(9) ;
    h3.insert(68) ;
    h3.insert(16) ;
    h3.insert(34) ;
    h3.insert(13) ;
    h3.insert(8) ;
    h3.deleteRoot();
    h3.deleteRoot() ;
    cout << "Leftist Min-Heap:" << endl ;
    h3.showLH() ;
}
