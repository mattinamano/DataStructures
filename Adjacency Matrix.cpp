#include <iostream>
#include <cstdlib>
using namespace std;

class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
    public:
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }

        void add_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }

         void remove_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 0;
            }
        }

        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};

class AdjacencyList
{
public:
struct edge;
struct node
{
	struct node *next;
	char name;
	struct edge *adj;
}*start=NULL;

struct edge
{
	char dest;
	struct edge *link;
};



void insert_node(char node_name)
{
	struct node *tmp,*ptr;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->name=node_name;
	tmp->next=NULL;
	tmp->adj=NULL;

	if(start==NULL)
	{
		start=tmp;
		return;
	}
	ptr=start;
	while( ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=tmp;
}/*End of insert_node()*/

void delete_node(char u)
{
	struct node *tmp,*q;
	if(start->name == u)
	{
		tmp=start;
		start=start->next;  /* first element deleted */
		free(tmp);
		return;
	}
	q=start;
	while(q->next->next != NULL)
	{
		if(q->next->name==u)     /* element deleted in between */
		{
			tmp=q->next;
			q->next=tmp->next;
			free(tmp);
			return;
		}
		q=q->next;
	}/*End of while*/
	if(q->next->name==u)    /* last element deleted */
	{
		tmp=q->next;
		free(tmp);
		q->next=NULL;
	}
}/*End of delete_node()*/

void delnode_edge(char u)
{
	struct node *ptr;
	struct edge *q,*start_edge,*tmp;
	ptr=start;
	while(ptr!=NULL)
	{
		/* ptr->adj points to first node of edge linked list */
		if(ptr->adj->dest == u)
		{
			tmp=ptr->adj;
			ptr->adj=ptr->adj->link;  /* first element deleted */
			free(tmp);
			continue; /* continue searching in another edge lists */
		}
		q=ptr->adj;
		while(q->link->link != NULL)
		{
			if(q->link->dest==u)  /* element deleted in between */
			{
				tmp=q->link;
				q->link=tmp->link;
				free(tmp);
				continue;
			}
			q=q->link;
		}/*End of while*/
		if(q->link->dest==u)    /* last element deleted */
		{
			tmp=q->link;
			free(tmp);
			q->link=NULL;
		}
		ptr=ptr->next;
	}/*End of while*/
}/*End of delnode_edge()*/

void insert_edge(char u,char v)
{
	struct node *locu,*locv;
	struct edge *ptr,*tmp;
	locu=find(u);
	locv=find(v);

	if(locu==NULL )
	{
		cout<<"Source node not present ,first insert node"<<u;
		return;
	}
	if(locv==NULL )
	{
		cout<<"Destination node not present ,first insert node"<<v;
		return;
	}
	tmp=(struct edge *)malloc(sizeof(struct edge));
	tmp->dest=v;
	tmp->link=NULL;


	if(locu->adj==NULL)   /* item added at the begining */
	{
		 locu->adj=tmp;
		  return;
	}
	ptr=locu->adj;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=tmp;

}/*End of insert_edge()*/

struct node *find(char item)
{
	struct node *ptr,*loc;
	ptr=start;
	while(ptr!=NULL)
	{
		if(item==ptr->name)
		{
			loc=ptr;
			return loc;
		}
		else
			ptr=ptr->next;
	}
	loc=NULL;
	return loc;
}/*End of find()*/

void del_edge(char u,char v)
{
	struct node *locu,*locv;
	struct edge *ptr,*tmp,*q;
	locu=find(u);

	if(locu==NULL )
	{
		cout<<"Source node not present"<<endl;
		return;
	}

	if(locu->adj->dest == v)
	{
		tmp=locu->adj;
		locu->adj=locu->adj->link;  /* first element deleted */
		free(tmp);
		return;
	}
	q=locu->adj;
	while(q->link->link != NULL)
	{
		if(q->link->dest==v)  /* element deleted in between */
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}/*End of while*/
	if(q->link->dest==v)    /* last element deleted */
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	cout<<"This edge not present in the graph"<<endl;
}/*End of del_edge()*/

void display()
{
	struct node *ptr;
	struct edge *q;

	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->name<<"->";
		q=ptr->adj;
		while(q!=NULL)
		{
			cout<<" "<<q->dest;
			q=q->link;
		}
		cout<<""<<endl;
		ptr=ptr->next;
	 }
}/*End of display()*/
};

int main()
{
    int nodes, max_edges, origin, destin;
    cout<<endl<<endl<<"graph using Adjacency Matrix"<<endl<<endl;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    cout<<"you can add/remove only "<<max_edges<<" edges"<<endl;
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter the edge you want to add / else give the nodes -1 -1 to exit:";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.add_edge(origin, destin);
    }
     am.display();
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter the edge you want to remove / else give the nodes -1 -1 to exit:";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.remove_edge(origin, destin);
    }
    am.display();
    cout<<endl<<endl<<"graph using Adjacency List"<<endl<<endl;
    AdjacencyList al;
	int choice;
	char node,orign,destination;
	while(1)
	{
		cout<<"1.Insert a node"<<endl;
		cout<<"2.Insert an edge"<<endl;
		cout<<"3.Delete a node"<<endl;
		cout<<"4.Delete an edge"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice)
		{
		 case 1:
			cout<<"Enter a node to be inserted : ";

			cin>>node;
			al.insert_node(node);
			break;
		 case 2:
			cout<<"Enter an edge to be inserted : ";

			cin>>orign>>destination;
			al.insert_edge(orign,destination);
			break;
		 case 3:
			cout<<"Enter a node to be deleted : ";

			cin>>node;
			/*This fn deletes the node from header node list*/
			al.delete_node(node);
			/* This fn deletes all edges coming to this node */
			al.delnode_edge(node);
			break;
		 case 4:
			cout<<"Enter an edge to be deleted : ";

			cin>>orign>>destination;
			al.del_edge(orign,destination);
			break;
		 case 5:
			al.display();
			break;
		 case 6:
			break;
		 default:
			cout<<"Wrong choice"<<endl;
			break;
		 }/*End of switch*/
	}
    return 0;
}
