#include <iostream>
#include <list>

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
        if(exploree_node[i] == 0 || explorer_node==0) //skip own node path
            continue;

        int metric_to_path = exploree_node[i];

        if(explorer_node[i] > exploree_node[i] + basement_metric || explorer_node[i]==-1) // if via metric value is less than  explorer's metric value, or unreachable node can be reacable,
        {
            exploree_node[i] = exploree_node[i] + basement_metric; // update metric
        }
    }

}
void find_shortest(int buf[], int idx)
{



}

void find_min_metric(int buf[], int min_metric_buf[], int number_of_nodes) //this fucntion uses selection sort algorithm. will be replaced other sorting algorithms (e.g., bubble,  merge sort, quick sort ...)
{

    int min = INT_MAX;
    int min_idx = -1;
    int idx = 0;
    int tmp[number_of_nodes];
    memcpy(tmp,buf, number_of_nodes * sizeof(int));

    for (int i = 0; i < number_of_nodes; ++i) {
        for (int j = 0; j < number_of_nodes; ++j) {
            if(min> tmp[j] )
            {
                min = tmp[j];
                min_idx=j;
            }

        }
        min = INT_MAX;

        min_metric_buf[idx++] = min_idx;
        tmp[min_idx] = INT_MAX; // replace min value to INT_MAX value to avoid duplication.


    }
}
int main()
{

    int nodes[][6] = {
        {0, 2, 5, 1, -1, -1},
        {2, 0, 3, 2, -1, -1},
        {5, 3, 0, 3, 1, 5},
        {1, 2, 3, 0, 1, -1},
        {-1, -1, 1, 1, 0, 2},
        {-1, -1, 5, -1, 2, 0}

    };

    int number_of_nodes = sqrt(sizeof(nodes)/sizeof(int));
    int min_metric_buf[number_of_nodes];


    memset(min_metric_buf, 0, number_of_nodes*sizeof(int));








    for (int i = 0; i < number_of_nodes ; ++i) {
        find_min_metric(nodes[i], min_metric_buf, number_of_nodes); // find metrics by lowest.

        for (int j = 0; j < number_of_nodes; ++j) {
            if(nodes[i][min_metric_buf[j]] <=0) // if lowest metric is 0, -1 this is, node[i][x] is own self or unreachable
                continue;

            int lowest_metric_idx = min_metric_buf[j];
            print_array(nodes[i], number_of_nodes);
            explore_lowest_metric_node(nodes[i], nodes[lowest_metric_idx], nodes[i][lowest_metric_idx], number_of_nodes); //explore lowest metric node
            print_array(nodes[i], number_of_nodes);

            cout<<"@@@@@@@@@@@@@@@@@@@@@"<<endl;
        }
        cout<<endl;




    }


    return 0;
}
