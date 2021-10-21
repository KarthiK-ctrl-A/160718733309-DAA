import heapq,sys
from collections import defaultdict

def dijkstra(graph,src,dest):
    h = []

    heapq.heappush(h,(0,src))
    while len(h)!=0:
        currcost, curvtx = heapq.heappop(h)
        if curvtx == dest:
            print("Path <{} {}> : cost = {}".format(src,dest,currcost))
            break
        for neigh,neighcost in graph[curvtx]:
            heapq.heappush(h,(currcost+neighcost , neigh))

graph = defaultdict(list)
print("Enter no.of verices and edges")
v,e = map(int,input().split())
for i in range(e):
    print("Enter {} edge".format(i))
    u,v,w = map(str,input().split())
    graph[u].append((v,int(w)))
print("Enter source and destination")
src,dest = map(str,input().split())
dijkstra(graph,src,dest)