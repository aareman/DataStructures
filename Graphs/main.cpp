#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    //test();
    graph g(12);
    g.connect2way(1,0);
    g.connect2way(4,0);
    g.connect2way(3,5);
    g.connect2way(3,0);
    g.connect2way(3,8);
    g.connect2way(3,6);
    g.connect2way(7,5);
    g.connect2way(7,11);
    g.connect2way(5,11);
    g.connect2way(4,5);
    g.connect2way(4,9);
    g.connect2way(9,11);
    g.connect2way(9,2);
    g.connect2way(9,10);

    g.print("my graph");
    //cout << g.is2way(2,3) << ", " << g.is2way(3,1) << ", " << g.is2way(1,3) << endl;
    //g.bfs(8);
    cout<<endl;
    //g.dfs(0);
    //g.shortestPath(1,7);

    return 0;

}
