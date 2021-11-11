#include <iostream>
#include <queue>
#include <ctime>

using namespace std;


void print_array(int* buf, int size_of_buf)
{
    for (int i = 0; i < size_of_buf; ++i) {
        cout<<(int)buf[i]<<' ';
    }
    cout<<endl;
}


void explore_lowest_metric_node(int explorer_node[], int exploree_node[], int basement_metric, int number_of_nodes) //basement metric is metric value way to exploree node from explorer node
{
    for (int i = 0; i < number_of_nodes; ++i) {
        if(exploree_node[i] == 0 || explorer_node[i]==0) //skip own node path
            continue;

        int metric_to_path = exploree_node[i];

        if((explorer_node[i] > exploree_node[i] + basement_metric || explorer_node[i]==-1) && (exploree_node[i] !=-1 && explorer_node[i] !=0) ) // if via metric value is less than  explorer's metric value, or unreachable node can be reacable,
        {
            explorer_node[i] = exploree_node[i] + basement_metric; // update metric
        }
    }

}

int find_min_metric(int buf[], bool explored_metric_idx[], int number_of_nodes) //this fucntion uses selection sort algorithm. will be replaced other sorting algorithms (e.g., bubble,  merge sort, quick sort ...)
{
    int min = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < number_of_nodes; ++i) {
        if(explored_metric_idx[i]==1) // if already explored in previous step
            continue; //skip

        if (buf[i] < min && (buf[i]!=0 && buf[i] !=-1)) //check metric value and unreachable or itself
        {
            min_idx = i; // save index of mininum metric
            min = buf[i];
        }

    }

    return min_idx;

}
int main()
{

    int nodes[][6] = { //initalizing nodes metrics
        {0, 2, 5, 1, -1, -1},
        {2, 0, 3, 2, -1, -1},
        {5, 3, 0, 3, 1, 5},
        {1, 2, 3, 0, 1, -1},
        {-1, -1, 1, 1, 0, 2},
        {-1, -1, 5, -1, 2, 0}

    };

    int number_of_nodes = sqrt(sizeof(nodes)/sizeof(int));


    for (int i = 0; i < number_of_nodes ; ++i) {
        bool explored_metric_idx[number_of_nodes];
        memset(explored_metric_idx, false, number_of_nodes*sizeof(int));

        for (int j = 0; j < number_of_nodes -1 ; ++j) { // we don't need to explore own node. that's why set a number of iteration count to number_of_nodes -1
            int lowest_metric_idx = find_min_metric(nodes[i], explored_metric_idx, number_of_nodes); // find metrics by lowest.
            if(lowest_metric_idx ==-1)
            {
                cout<<"There is unreachable Node"<<endl;
                continue;
            }

            explore_lowest_metric_node(nodes[i], nodes[lowest_metric_idx], nodes[i][lowest_metric_idx], number_of_nodes); //explore lowest metric node
            explored_metric_idx[lowest_metric_idx] = true; //set flag to avoid duplicate node explore


        }

        cout<<"Optimized node["<<i<<"] : "<<endl;
        print_array(nodes[i], number_of_nodes);
        cout<<endl;



    }


    return 0;
}
