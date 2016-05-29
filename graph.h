/*
NODE class to be used in GRAPH class.
*/
void test();
int getLen(int* a);
class node{
  public:
    node();
    node(const node& rhs);
    ~node();

    void printnode();

    //include array of length n (binary array)
    bool* nodelist;
    //include "data"
    int data;
    bool checked;
    unsigned int graph_size;
    bool inGraph;

};

/*
GRAPH class.
*/

class graph{
  public:
    graph(unsigned int graph_size);
    graph(const graph& rhs);
    ~graph();

    bool isConnected(unsigned int a, unsigned int b);
    bool is2way(unsigned int a, unsigned int b);
    void connect(unsigned int a, unsigned int b); //connect(a,b); a->b
    void connect2way(unsigned int a, unsigned int b); // connects a<->b
    void revConnect(unsigned int a, unsigned int b); // if a->b, then b->a, if no connection do nothing
    unsigned int addnode(unsigned int num); // may be removed. don't think I need it.


    graph dfs(unsigned int start);
    graph bfs(unsigned int start);
    int* shortestPath(unsigned int a, unsigned int b);

    void print(std::string title);

  private:
    unsigned int n; // number of nodes in graph
    unsigned int graph_size;
    //include an array of nodes of length n.
    node* nodes;

};
