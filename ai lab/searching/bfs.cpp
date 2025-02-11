#include<bits/stdc++.h>
using namespace std;
vector<int> my_graph[100];
bool visited_nodes[100];
int goal;
void BFS(int src){
    queue<int> myqueue;
    myqueue.push(src);
    visited_nodes[src]=true;
    while(!myqueue.empty()){
        int current_node=myqueue.front();
        myqueue.pop();
        cout<<"Node "<<current_node<<" is visited\n";
        if(current_node==goal){
            cout<<"Goal is Reached.";
            return;
        }
        for(auto &x: my_graph[current_node]){
            if(!visited_nodes[x]){
            myqueue.push(x);
            visited_nodes[x]=true;

            }
        }
    }
}
int main()
{
    int tot_node,tot_edge;
    cout<<"How many nodes u have ? ";
    cin>>tot_node;
    cout<<"How many edges u have ? ";
    cin>>tot_edge;
    for(int i=0;i<tot_edge;i++){
        int p,q;
        cout<<"Edge number "<<(i+1)<<":";
        cin>>p>>q;
        my_graph[p].push_back(q);
        my_graph[q].push_back(p);
    }
    cout<<"Enter the goal node = ";
    cin>>goal;
    BFS(1);
    return 0;
}
