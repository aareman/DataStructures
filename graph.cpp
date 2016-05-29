#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <fstream>
#include "graph.h"
#include <string>

//testfunction
void test(){
    //std::system("neato -Tpng test.dot > test.png");
    //std::system("gimp test.png");
    int sub = 1;
    for(int i=0;i<12;i++){
        for(int j=sub;j<12;j++){

        }
    }
}

int getLen(int* a){
    return a[0];
}

/*
node member functions
*/
node::node(){

}
node::node(const node& rhs){
    //implement
}
node::~node(){
    delete[] this->nodelist;
}

void node::printnode(){

    //commandline print
    for(unsigned int i = 0;i<this->graph_size;i++){
        if(this->nodelist[i] == true){
            std::cout << "   ->node " << i << std::endl;
        }
    }

	//myfile.open("graph.dot", ios::app);

}
/*
GRAPH member functions
*/
graph::graph(unsigned int graph_size){
    this->n = 0;
    this->graph_size = graph_size;
    this->nodes = new node[graph_size];
    for(unsigned int i=0;i<graph_size;i++){
        this->nodes[i].nodelist = new bool[this->graph_size];
        this->nodes[i].checked = false;
        this->nodes[i].graph_size = this->graph_size;
        this->nodes[i].inGraph = false;
        for(unsigned int j=0;j<this->graph_size;j++){
            this->nodes[i].nodelist[j] = false;
        }
    }
}
graph::graph(const graph& rhs){
    //need to implement
    this->n = 0;
    this->graph_size = rhs.graph_size;
    this->nodes = new node[graph_size];
    for(unsigned int i=0;i<graph_size;i++){
        this->nodes[i].nodelist = new bool[this->graph_size];
        this->nodes[i].checked = false;
        this->nodes[i].graph_size = this->graph_size;
        this->nodes[i].inGraph = false;
        for(unsigned int j=0;j<this->graph_size;j++){
            this->nodes[i].nodelist[j] = false;
        }
    }
}
graph::~graph(){
    delete[] this->nodes;
}

bool graph::isConnected(unsigned int a, unsigned int b){
    return true;
}
bool graph::is2way(unsigned int a, unsigned int b){
    return nodes[a].nodelist[b] && nodes[b].nodelist[a];
}
void graph::connect(unsigned int a, unsigned int b){//connect(a,b); a->b
    nodes[a].nodelist[b] = true;
}
void graph::connect2way(unsigned int a, unsigned int b){//connect(a,b); a<->b
    nodes[a].nodelist[b] = true;
    nodes[b].nodelist[a] = true;
}

//not sure if this will be used
unsigned int graph::addnode(unsigned int num){
    if(num < graph_size){
        nodes[num].inGraph = true;
        n++;
    }
    else{
        std::cout<<"cannot add node, value is out of bounds." << std::endl;
    }
    return 2;
}
void graph::revConnect(unsigned int a, unsigned int b){
    if(nodes[a].nodelist[b] == true){
        nodes[a].nodelist[b] = false;
        nodes[b].nodelist[a] = true;
    }
}

//just for testing
void graph::print(std::string title){

    //GraphViz print header

    std::ofstream myfile;
	myfile.open("graph.dot");
	myfile << "digraph output_graph {\n"
           << "node [shape=circle,fixedsize=true,width=0.4,color=black];\n"
           << "edge[color=blue,width=.01];"
           << std::endl;
	myfile.close();

    myfile.open("graph.dot", std::ios::app);
    //commandline print
    for(unsigned int i=0;i<this->graph_size;i++){
        std::cout << "connections for node " << i << std::endl;
        nodes[i].printnode();

    //graphviz print
        for(unsigned int j = 0;j<this->graph_size;j++){
            if(nodes[i].nodelist[j] == true){
                myfile << i << "->" << j << std::endl;
            }
        }

    }
    myfile.close();

    //GraphViz print footer

	myfile.open("graph.dot", std::ios::app);
	myfile << "overlap=false \n fontsize=12; \n }" << std::endl;
	myfile.close();

    std::system("neato -Tpng graph.dot > graph.png");
    std::system("gimp graph.png");
}

graph graph::dfs(unsigned int start){
    std::stack <unsigned int> q;
    //unsigned int visited = 0;
    int* result = new int[graph_size];
    int index = 0;
    std::cout<<"DFS: ";
    graph DFS(graph_size);
    //unmark all vertices
    for(unsigned int i=0;i<graph_size;i++) nodes[i].checked = false;
    //while(visited < graph_size){
    //start with node 0;
    q.push(start);
    nodes[start].checked = true;
    while(q.size() > 0){
        unsigned int temp = q.top();
        q.pop();
        //visited++;
        //nodes[temp].checked = true;
        for(unsigned int j =0; j<graph_size;j++){
            if(nodes[temp].nodelist[j] == true && nodes[j].checked == false){
                q.push(j);
                nodes[j].checked = true;
                DFS.connect(temp,j);
            }
        }
        std::cout << temp << ", ";
        result[index+1] = (int)temp;
        index++;
    }
    result[0] = index;
    DFS.print("DFS");
    //return result;
    return DFS;
}
graph graph::bfs(unsigned int start){

    /*
    choose some starting vertex x
    mark x
    list L = x
    tree T = x
    while L nonempty
    choose some vertex v from front of list
    visit v
    for each unmarked neighbor w
        mark w
        add it to end of list
        add edge vw to T*/

    std::queue <unsigned int> q;
    //unsigned int visited = 0;
    int* result = new int[graph_size];
    int index = 0;
    std::cout<<"BFS: ";
    graph BFS(graph_size);
    //unmark all vertices
    for(unsigned int i=0;i<graph_size;i++) nodes[i].checked = false;
    //while(visited < graph_size){
        //start with node 0;
    q.push(start);
    nodes[start].checked = true;
    while(q.size() > 0){
        unsigned int temp = q.front();
        q.pop();
        //visited++;
        //nodes[temp].checked = true;
        for(unsigned int j =0; j<graph_size;j++){
            if(nodes[temp].nodelist[j] == true && nodes[j].checked == false){
                q.push(j);
                nodes[j].checked = true;
                BFS.connect(temp,j);
            }
        }
        std::cout << temp << ", ";
        result[index+1] = (int)temp;
        index++;
    }
    result[0] = index;
    BFS.print("BFS");
    //return result;
    return BFS;
}
int* graph::shortestPath(unsigned int a, unsigned int b){
    graph temp = this->bfs(a);
    int* result = new int[graph_size];

    //reverse the paths in temp
    unsigned int sub = 1;
    //unsigned int en = graph_size-sub;
    for(unsigned int i=0;i<graph_size-1;i++){
        for(unsigned int j=sub;j<graph_size;j++){
            temp.revConnect(i,j);

        }
        sub++;
    }

    //now start from end and keep on stack
    std::stack<unsigned int> s;
    //unsigned int pos = b;
    while(b != a){
        for(unsigned int c=0;c<graph_size;c++){
            if(temp.nodes[b].nodelist[c] == true){
                s.push(b);
                b = c;

                break;
            }
        }
    }
    //print out list
    s.push(a);
    while(s.size()>0){
        std::cout<<s.top()<<": ";
        s.pop();
    }
    //temp.revConnect(5,11);
    temp.print("reversed BFS");
    return result;
}
