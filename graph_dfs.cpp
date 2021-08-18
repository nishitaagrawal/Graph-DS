#include<iostream>   //DFS using adjacency list
#include<bits/stdc++.h>
#define MAX 15
using namespace std;
class graph;
class graph_node  //vertex linked list (node)
{
    graph_node *link;  //self referential
    int vertex;  //data
	public:
	    graph_node(int data)
	    { 
	        vertex=data;
	        link=NULL;
	    }
	    friend class graph;
};
class graph  // create lined list of the graph
{
    graph_node *list[MAX];  // array of pointer
    int vertex_no; //no of vertices i want to store in list array
	public:
	    graph(int no_ver)
	    {
	        vertex_no=no_ver;
	        for(int i =0; i<no_ver;i++)
	        {
	            list[i]=NULL;   // assign entire vertex list as NULL
	        }
	    }
	    void create();
	    void display();
	    void dfs(int);
};
void graph::create() // create adjacency list
{
    int i, j,data;
    graph_node *temp, *newnode,*temp2;
    int n= vertex_no;
    char ans;
    for(int m =0;m<n;m++)  // enter data of n vertex
    {
        cout<<"Enter vertex data : ";
        cin>>data;
        newnode= new graph_node(data);
        list[m]=newnode;
    }
    for(i=0; i<n;i++)  //run for vertex
    {
        for(j=0;j<n;j++)   //run for individual linked list
        {
            int h = list[j]->vertex;
            cout<<"Is there an edge between vertex(y/n) " <<list[i]->vertex<<" and "<<h<<" : ";
            cin>>ans;
            temp=list[i];
            if (ans=='y')  // extend link of vertex and add direction between 2 vertex
            {
                temp2=new graph_node(h);
                if(temp->link!=NULL)
                {temp=temp->link;}
                temp->link=temp2;
                temp=temp2;
            }
        }
    }
}
void graph::display()
{
    graph_node *temp;  //for traversal purpose
    for(int i=0;i<vertex_no;i++)  // run for no of vertices we have - array of pointers
    {
        temp=list[i];  //temp assigned to 1st node of adjacency list	
        cout<<"Vertex:\t";  //display vertex
        temp=list[i];
        while(temp!=NULL)   //display complete linked list of each vertex in this while loop 
        {
            cout<<temp->vertex<<" -> ";
            temp=temp->link;
        }
        cout<<"NULL\n";
    }
}
void graph::dfs(int d)
{
    cout<<"\nDFS of the graph : \n";
    graph_node *temp, *temp1;
    stack<int> s;
    vector<bool> visited(vertex_no,false); //dynamic array
    s.push(d);  //push starting vertex of dfs
    while(!s.empty())  // till adjacency list has vertex; while loop will run
    {
        d=s.top();
        s.pop();
        if(!visited[d])  //if vertex is not visited we will display it and make visited = true
        {
            cout<<d<<"\t";
            visited[d]=true;
        }
        for(int i=0;i<vertex_no;i++)  //search in adjacenecy list if vertex value is equal to d (start vertex)
        {
            if(list[i]->vertex == d)
            {
                temp1 = list[i];  //temp 1 assigned to starting dfs vertex
                break;
            }
        }
        for(temp=temp1;temp->link!=NULL;temp=temp->link)  // print the linked list of d ;if the vertex is not visited 
        {
            if(!visited[temp->vertex])
            {
                s.push(temp->vertex);
            }
         } 
        temp=temp1;
        while(temp!=NULL) //if any vertex is left unvisited the we backtrack and display that vertex 
        {                            //and unvisited elements of its linked list
            if(!visited[temp->vertex])
                {
                    s.push(temp->vertex);
                }
             temp=temp->link;
        }
    }
}
int main()
{
    int n,d;
    cout<<"Enter no of vertices : ";
    cin>>n;
    graph g(n);
    g.create();
    cout<<"\nDISPLAY GRAPH USING ADJACENCY LIST\n\n";
    g.display();
    cout<<"\nDFS \n\nEnter starting vertex: \t";
    cin>>d;
    g.dfs(d);
    return 0;
}
