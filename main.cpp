#include <iostream>

using namespace std;


int main()
{
    int nodes,edge,t1,t2;
    cout<<"enter the number of node and edge\n";
    cin>>nodes>>edge;
    cout<<"enter the start end and weight of edge\n";
    int E[edge][3];//start end weight
    for(int i=0;i<edge;i++){
       cin>>t1>>t2>>E[i][2];
        E[i][0]=t1-1;
        E[i][1]=t2-1;
    }
    int parent[nodes],distance[nodes],visited[nodes];
    //intilisation
    for(int i=0;i<nodes;i++){
        distance[i]=9999;
        visited[i]=0;
        parent[i]=-1;
    }
    distance[0]=0;

   //for(int i=0;i<nodes;i++)
    //cout<<parent[i]<<" "<<distance[i]<<" "<<visited[i]<<endl;
    //cout<<endl <<endl;

    int temp=9998,k=-1;
    for(int q=0;q<nodes;q++)
    {
    for(int i=0;i<nodes;i++)
       {
        if(distance[i]<=temp && visited[i]==0)
           {
            temp=distance[i];
            k=i;

            }
       }
    visited[k]=-1;
    if(k!=-1)
    {
      for(int i=0;i<edge;i++)
      {
        if(E[i][0]==k && distance[E[i][1]]>(distance[k]+E[i][2]))
           {
                distance[E[i][1]]=distance[k]+E[i][2];

                parent[E[i][1]]=k+1;

            }
        if(E[i][1]==k && distance[E[i][0]]>(distance[k]+E[i][2]))
           {
                distance[E[i][0]]=distance[k]+E[i][2];

                parent[E[i][0]]=k+1;

            }
        }

     }
    k=-1;  temp=9998;

    }
    cout<<"shortest path from node 1 to othters \n";
    cout<<"node\t"<<"total weight\t"<<"path   \n";
    int p[10],d,sum=0;
    for(int i=2;i<=nodes;i++)
    {
           int c=0;
            p[0]=i;
            d=i-1;

     while(parent[d]!=-1)
       {
        for(int j=0;j<edge;j++)
         {
            if(E[j][0]==parent[d]-1 && E[j][1]==d)
            {sum+=E[j][2];break;}
        }

         d=parent[d]-1;
         c++;
         p[c]=d+1;
      }

        cout<<i<<"\t"<<sum<<"\t";
        for(int j=c;j>=0;j--)
           cout<<p[j]<<" ";
        cout<<"\n";
        sum=0;
    }
//for(int i=0;i<nodes;i++)
//cout<<i+1<<" "<<parent[i]<<"    "<<distance[i]<<"    "<<visited[i]<<endl;





    return 0;
}
