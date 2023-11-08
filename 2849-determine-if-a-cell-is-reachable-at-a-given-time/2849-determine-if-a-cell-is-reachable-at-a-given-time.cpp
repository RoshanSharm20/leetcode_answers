class Solution {
public:
//     bool isValid(int x,int y)
//     {
//         if(x<1 || y<1 || x>1e9 || y>1e9)
//             return false;
//         return true;
//     }
//     int bfs(int sx,int sy,int fx,int fy)
//     {
//         queue<pair<int,pair<int,int>>> nodes;
//         nodes.push({0,{sx,sy}});
//         while(true)
//         {
//             auto it = nodes.front();
//             nodes.pop();
//             int cost = it.first;
//             int x = it.second.first;
//             int y = it.second.second;
//             if(x==fx && y==fy)
//                 return cost;
            
//             for(int i=-1;i<=1;++i)
//             {
//                 for(int j=-1;j<=1;++j)
//                 {
//                     int xrow = x+i;
//                     int ycol = y+j;
//                     if(isValid(xrow,ycol))
//                     {
//                         nodes.push({cost+1,{xrow,ycol}});
//                     }
//                 }
//             }
//         }
//         return INT_MAX;
//     }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int count=0;
        int vxdistance = abs(sx-fx);
        int vydistance = abs(sy-fy);
        
        if(vxdistance<=vydistance)
        {
            count=vxdistance;
            vydistance=vydistance-vxdistance;
            count+=vydistance;
        }
        else
        {
            count=vydistance;
            vxdistance=vxdistance-vydistance;
            count+=vxdistance;
        }
        
        if(count==0 && t==1)
            return false;
        return(count<=t);
    }
};