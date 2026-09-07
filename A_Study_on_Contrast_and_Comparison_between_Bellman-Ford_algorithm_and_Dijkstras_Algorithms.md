# A Study on Contrast and Comparison between Bellman-Ford algorithm and Dijkstra’s algorithm

Thippeswamy.K. Hanumanthappa.J. Dr.Manjaiah D.H. Asst. Professor and HOD,Department of Assistant Professor, Associate Professor and

Information Science and Department of Studies Chairman, Engg,RLJIT,Kodigehalli,Doddaballapura,Bangalore, in Computer Science, Department of Computer

Rural District,Karnataka,INDIA University of Mysore, Science, Email:-thippeswamy_yadav@yahoo.co.in. Manasagangotri,Mysore, Mangalore University,

Karnataka,INDIA Mangalagangothri,Mangalore,_Email:-_ Karnataka, INDIA

**hanums_j@yahoo.com** Email:- ylm321@yahoo.co.in

Abstract - In this article we made a study about the **Procedure**two well known shortest path searching algorithms,

which are used in routing. They are Bellman-Ford _Bellman-Ford (list vertices, list edges, vertex_algorithm and Dijkstra’s algorithm. They were _source)_

compared on the basis of their run time. Theanalysis of the comparison is given briefly. _// This implementation takes in a graph, represented_

as lists of vertices

1. INTRODUCTION // and edges, and modifies the vertices so that their distance and
| routing protocol can not handle the task of updating Today, an internet can be so large that one | // predecessor attributes store the shortest paths. |
| --- | --- |
| the routing table of all routers. For this reason internet is divided in to an autonomous systems. | // Step 1: Initialize graphe for each vertex v in vertices: |

| The routing inside an autonomous system is called as intra domain routing. And the communication | if v is source then v.distance := 0 |
| --- | --- |
| between autonomous systems is called inter domain routing. Bellman-Ford algorithm and the Dijkstra’s | else v.distance := infinity v.predecessor := null |

| algorithms are two popular algorithms used in intra domain routing to update the routing tables. | // Step 2: relax edges repeatedly |
| --- | --- |
| 1.1 Bellman-Ford algorithm | for i from 1 to size(vertices)-1: |

for each edge uv in edges:

The Bellman–Ford algorithm, sometimes u := uv.source referred to as the Label Correcting Algorithm, v := uv.destination

computes single-source shortest paths in a weighted // uv is the edge from u to v digraph (where some of the edge weights may be

| negative).Bellman-Ford very similar to Dijkstra's algorithm, but instead of is in its basic structure | if v.distance > u.distance + uv.weight: v.distance:= u.distance + uv.weight |
| --- | --- |
| greedily selecting the minimum-weight node not yet processed to relax, it simply relaxes all the | v.predecessor:= u |

| edges, and does this |V| - 1 times, where |V| is the | // Step 3: check for negative-weight cycles |
| --- | --- |
| number of vertices in the graph. The repetitions allow minimum distances to accurately propagate | for each edge uv in edges: u := uv.source |

| throughout negative cycles, the shortest path can only visit the graph, since, in the absence of | v := uv.destination |
| --- | --- |
| each approach, node which at most depends once. on Unlike certain the structural greedy | If v.distance > u.distance + uv.weight: error "Graph contains a negative-weight |

assumptions derived from positive weights, this cycle" straightforward approach extends to the general

case.

1.2 Dijkstra's algorithm **{**

int *distance ;// Should be allocated Dijkstra's algorithm, conceived by Dutch

| computer scientist Edsger Dijkstra in 1959, is a graph search algorithm that solves the single-source | int i, j; if (distance == NULL) Then |
| --- | --- |
| shortest path problem for a graph with non negative edge path costs, outputting a shortest path tree.This | { |
| algorithm is often used in routing. For a given source vertex (node) in the graph, the algorithm | fprintf (stderr, "malloc () failed\n"); |
| finds the path with lowest cost (i.e. the shortest path) between that vertex and every other vertex. It | exit (EXIT_FAILURE); |
| can also be used for finding costs of shortest paths | } |
| from a single vertex to a single destination vertex by stopping the algorithm once the shortest path to | for (i 0; i < nodecount; ++i) |
| the destination vertex has been determined. | distance[i] INFINITY; |
| Procedure | distance[source] for (i 0; i < nodecount; ++i) 0; |
| can also be referred to as weight. It should be noted that distance between nodes | { for (j 0; j < edgecount; ++j) |

{ 1. Create a distance list, a previous vertex

list, a visited list, and a current vertex. if (distance [edges[j].source] != INFINITY)

2. All the values in the distance list are set to { infinity except the starting vertex which is
int new_distance set to zero.

| 3. All values in visited list are set to false. | distance[edges[j].source] + edges[j].weight; |
| --- | --- |
| 4. All values in the previous list are set to a special value signifying that they are | If (new_distance < distance[edges[j].dest]) |

undefined, such as null. distance[edges[j].dest] = new_distance;

| 5. Current vertex is set as the starting vertex. | } |
| --- | --- |
| 6. Mark the current vertex as visited. | } |

7. Update distance and previous lists based } on those vertices which can be
| immediately reached from the current | for (i 0; i < edgecount; ++i) |
| --- | --- |
| vertex. | { |

8. Update the current vertex to the unvisited If (distance[edges[i].dest] > vertex that can be reached by the shortest
path from the starting vertex. distance[edges[i].source] + edges[i].weight) {

9. Repeat (from step 6) until all nodes are visited. puts ("Negative edge weight cycles detected!");
free (distance);

2. ALGORITHMS return;
| procedure are given as follows. The algorithms for the above two | } |
| --- | --- |
| 2.1 Bellman-Ford algorithm | } Time complexity |
| I int source nput: Edge edges[], int edgecount, int nodecount, | Time a 10*n +18*m+27*n*m+3 |
| Output: Routing table | n - Node count |
| Begin: | m - Edge count |

i.e Time a n*m

| Time a 27 * Edges * Nodes | Time complexity |
| --- | --- |
| Time a (number of nodes) (number of edges) | The running time of Dijkstra's algorithm on a graph |
| For a general case of number of edges equals to number of nodes we can write(m=n) | with edges function of | E Edges and vertices | and | Vertices V can be expressed as a | using the Big-O |
| Time a 27*n 2 + 28*n + 3 | notation. |
| i.e Time a 27n 2 | The algorithm stores vertices of set simplest implementation of Q in an ordinary the Dijkstra's |
| 2.2 Dijkstra’s Algorithm | linked list or array, and operation Extract-Min( Q ) is |
| 1 function Dijkstra ( Graph , source ): | simply a linear search through all vertices in this case, the running time is O (| V | 2 +|E|) = O (| Q V . In | 2 ). |

_2 for each vertex_ v _in_ Graph_:_ // Initializations **O** _( |Vertices|2 + |Edges| )_

| 3 dist[ function from source to v v ] := infinity | // Unknown distance | For a general case of number of edges equals to number of nodes we can write (m=n) |
| --- | --- | --- |
| 4 previous[ v ] := undefined | // Previous node in | i.e. Time a 2n 2 (form the above algorithm) |

**optimal path from source** For a case of n=m we can plot the following graph

**Number of** _Nodes vs. time_**5 dist[**source**] := 0** // Distance from source to

**source**6 **Q**: = the set of all nodes in **Graph // All**

nodes in the graph are unoptimized - thus are in Q

7 while **Q** is not empty: **// The main loop**

| 8 | u := node in Q with smallest dist[] |
| --- | --- |
| 9 | remove u from Q |

**10 for each neighbor** v **of** u**:** // where vhas not yet been removed from Q.

11 **alt**: = dist[**u**] + dist_between (**u**, **v**) Form the above graph it is clear thatthough the nature of the two curves are same i.e

12 if _alt_ < dist[_v_] _// Relax (u,v)_ **O(n2)**, the Bellman ford algorithm requires moretime than Dijkstra’s algorithm.

13 dist[_v_] := _alt_

14 previous[**v**] := **u** The functionality of Dijkstra's originalalgorithm can be extended with a variety of

| 15 return previous [] | modifications. desirable to present solutions, which are less than For example, sometimes it is |
| --- | --- |
| If we are only interested in a shortest path between | mathematically optimal. To obtain a ranked list of less-than-optimal solutions, the optimal solution is |
| vertices search at line 10 if source and u = target target , we can terminate the . Now we can read the | first calculated. A single edge appearing in the |
| shortest path from source to target by iteration: | optimal solution is removed from the graph, and the optimum solution to this new graph is |
| 1 S := empty sequence | calculated. Each edge of the original solution is suppressed in turn and a new shortest-path |
| 2 u := target | calculated. The secondary solutions are then ranked |
| 3 while defined previous[ u ] | and Unlike presented Dijkstra's after algorithm, the first the optimal Bellman-Ford solution. |
| 4 insert u at the beginning of S | algorithm can be used on graphs with negative edge weights, as long as the graph contains no negative |

5 **u** := previous[**u**]

cycle reachable from the source vertex _s_. (The Section 21.7: Negative Edge Weights.presence of such cycles means there is no shortest [http://safari.oreilly.com/0201361213/ch21](http://safari.oreilly.com/0201361213/ch21)

path, since the total weight becomes lower each lev1sec7 time the cycle is traversed.). How ever the [5] Jin Y. Yen. "An algorithm for Finding

Bellman-Ford algorithm has another draw back. Shortest Routes from all Source Nodes to The Bellman-Ford algorithm does not prevent a Given Destination in General Network",

routing loops from happening and suffers from the Quart. Appl. Math., 27, 1970, 526-530.count-to-infinity problem. The core of the count-to- [6] Richard Bellman: **On a Routing Problem**,

infinity problem is that if A tells B that it has a path in Quarterly of Applied Mathematics, somewhere, there is no way for B to know if it is 16(1), pp.87-90, 1958.

| on the path. To see the problem clearly, imagine a subnet connected like A-B-C-D-E-F, and let the | [7] Lestor R. Ford jr., D. R. Fulkerson: in Networks , Princeton University Press, Flows |
| --- | --- |
| metric between the routers be "number of jumps". Now suppose that A goes down. In the vector- | [8] 1962. Thomas H. Cormen, Charles E. Leiserson, |

| update-process B notices that its once very short route of 1 to A is down - B does not receive the | Ronald Stein. Introduction L.Rivest, to Algorithms and , Clifford Second |
| --- | --- |
| vector update from A. The problem is, B also gets an update from C, and C is still not aware of the | Edition. MIT Press and McGraw-Hill, 2001. ISBN 0-262-03293-7. Section 24.1: The |
| fact that A is down - so it tells B that A is only two | Bellman-Ford Problem 24-1, pp.614–615. algorithm, pp.588–592. |

jumps from it, which is false. This slowly propagates through the network until it reaches

infinity (in which case the algorithm corrects itself, 5. ACKNOWLEDGEMENT due to the "Relax property" of Bellman Ford).

I would like to thank the Department of Information Science & Engineering, HKBK College

3. CONCLUSION of Engineering, Department of Studies in Computer
| algorithm soles a problem with a complexity of As the analysis shows the Bellman-Ford | Science, University of Mysore, Manasagangothri & |
| --- | --- |
| 27n problem with a lower running time, but requires 2 but the Dijkstra's algorithm solves the same | PG University, conduct this research work. Department Mangalore of Computer for providing Science, support Mangalore to |

| edge weights to be non-negative. Thus, Bellman– Ford is usually used only when there are negative | Mr.Hanumanthappa.J. is Lecturer at the |
| --- | --- |
| edge weights. | DoS in CS, University of Mysore, |
| source Both of these functions solve the single shortest path problem. The primary | Manasagangothri, currently pursuing Ph.D Mysore in Computer -06 and |

| difference in the function of the two algorithms is that Dijkstra's algorithm cannot handle negative | Mangalore Science University and under Engineering, the supervision from of |
| --- | --- |
| edge weights. Bellman-Ford's algorithm can handle some edges with negative weight. It must be | Dr.Manjaih.D.H Multimedia Stuffs ”. His teaching and Research on entitled “ IPv6 and |
| remembered, however, that if there is a negative cycle there is no shortest path. | interests and Sensor include Networks, Computer Networks,Wireless Mobile Ad-Hoc |

Networks,Intrusion detection System,Network**4. REFERENCES** Security and Cryptography, Internet Protocols,

| [1] en.wikipedia.org/ | Mobile management,Quality and Client Server Computing,Traffic of |
| --- | --- |
| [2] A note on two problems in connexion with graphs. In Numerische Mathematik, 1 | Service,RFID,Bluetooth,Unix internal, Kernel Programming ,Object Oriented internals, Linux |

(1959), S. 269–271. **Analysis and Design etc**. His most recent research

[3] Thomas H. Cormen, Charles E.Leiserson, focus is in the areas of Internet Protocols and theirRonald Rivest,and Clifford Stein. applications. He received his **Bachelor of**

| Introduction Edition. MIT to Press Algorithms, and McGraw-Hill, Second | Engineering Degree in Computer Science and Engineering from University B.D.T College of |
| --- | --- |
| 2001. ISBN 0-262-03293-7. Section 24.3: Dijkstra's algorithm, pp.595–601. | Engineering C),Kuvempu University,Shimoga in the year 1998 , Davanagere, Karnataka(S),India( |

and **Master of Technology in CS&Engineering**[4] Robert Sedgewick. Algorithms in Java. **from NITK** Surathkal,Karnataka(S),India (C) in

Third Edition. ISBN 0-201-36121-3. the year 2003.He has been associated as a faculty

of the Department of Studies in Computer Science Dr. Manjaiah D.H. is currently Reader and since 2004.He has worked as lecturer at Chairman of BoS in both UG/PG in the

**SIR.M.V.I.T,Y.D.I.T,S.V.I.T**,of Bangalore.He has Computer Science at Dept. of Computerguided about **50** Project thesis for Science, Mangalore University,

| BE,B.Tech,M.Tech,MCA,MSc/MS Published about 10 technical .He articles has in | Mangalore. Universities He of is Karnataka also the BoE and Member other reputed of all |
| --- | --- |
| International, conferences.He and is National a Life Peer member reviewed of | universities in India. He received PhD degree from University of Mangalore, M.Tech. from NITK, |
| CSI,ISTE,AMIE, IAENG group of TIFAC–CORE in Network Engineering , Embedded networking | Surathkal Dr.Manjaiah D.H has an extensive academic, Industry and B.E., from Mysore University. |
| ,ACM, Association(CSTA) Computer .He is also a Science BOE Member Teachers of | and Research experience. He has worked at many technical bodies like IAENG, WASET, ISOC, CSI, |
| all the Universities of Karnataka, INDIA also visited Republic of China as a . Visiting He has | ISTE, and ACS. He has authored more than - 25 research papers in international conferences and |
| Faculty OS and System Software and Software Engineering to teach Computer Science Subjects like | reputed journals. He is the recipient of the several talks for his area of interest in many public occasions. He is |
| for B.Tech Students of Huang Huai University in the year 2008. He has also visited Thailand as a | an expert committee member of an AICTE and various technical bodies. He had written Kannada text book, |
| Tourist to visit so many places in Thailand. | with an entitled, “COMPUTER PARICHAYA”, for the benefits of all teaching and Students Community |

| Mr. Professor B.I.D at the Kumar HKBK College of is Asst. | of Karnataka. Dr .Manjaiah.D.H D.H’s areas interest are Computer Networking & Sensor Networks, Mobile |
| --- | --- |
| Engineering Science, Bangalore-45 in . His teaching Information | Communication, Operations Research, E-commerce, Internet Technology and Web Programming. |

_and Research interests include_Algorithms, Data structure, Microprocessor_,_

Computer Networks, Unix internals, Linux internal, Kernel Programming, Object Oriented

Analysis and Design etc_. He received his_Bachelor of Engineering Degree in Computer

**Science and Engineering** from Shree SiddharthaInstitute of Engineering, Tumkur, Karnataka(

S),India( C),Bangalore University, Bangalore in theyear 2000 and **Master of Technology in Computer**

Science & Engineering from University BDTCollege of Engineering **, Davanagere, Kuvempu**

University , Shimoga, Karnataka( S ),India (C) in the year 2005. He has been associated as a faculty

of the Department of Information Science since August 2007. In his 7 years of Teaching experience,

he has guided many Project thesis for **BE,B.Tech**and involved in technical activities_._

This document was created with Win2PDF available at [http://www.win2pdf.com.](http://www.win2pdf.com.) The unregistered version of Win2PDF is for evaluation or non-commercial use only.

This page will not be added after purchasing Win2PDF.
