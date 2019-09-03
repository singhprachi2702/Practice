struct cell
{
    int value;
    int row;
    int col;
    
};

struct comparison
{
bool operator()(cell a,cell b)
    {return a.value>b.value;}
};
int *mergeKArrays(int arr[][N], int k)
{
//code here

    int *result;
    result = new int[k*k];
    priority_queue<cell, vector<cell>,comparison> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],i,0});
    }
    int j=0;
    while(j<k*k)
    {
        cell t = pq.top();
        pq.pop();
        result[j++]=t.value;
        
        if(t.col<k-1)
        {
            pq.push({arr[t.row][(t.col)+1],t.row,t.col+1});
        }
    }
    return result;
}
