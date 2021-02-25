# Algorithm_Graph

### Graph
- 아이템(사물 또는 추상적 개념)들과 이들 사이의 **연결 관계**를 표현
- 정점들의 집합과 이들을 연결하는 간선들의 집합으로 구성
- 선형 자료구조나 트리 자료구조로 표현하기 어려운 **N:N 관계를 가지는 원소들을 표현**하기에 용이
- 유형
  - 무향 그래프(Undirected Graph)
  - 유향 그래프(Directed Graph)
  - 가중치 그래프(Weighted Graph)
  - 사이클 없는 방향 그래프(Directed Acyclic Graph)
  - 완전 그래프 : 정점들에 대해 가능한 모든 간선들을 가지는 그래프
  - 부분 그래프 : 원래 그래프에서 일부의 정점이나 간선을 제외한 그래프
- 인접 정점
  - 인접(Adjacency) : 두 개의 정점에 간선이 존재하면 서로 인접해 있다고 함

#### 그래프 경로
- 경로란 간선들을 순서대로 나열한 것
- 단순 경로 : 경로 중 한 정점을 최대한 한번만 지나는 경로
- 사이클 : 시작한 정점에서 끝나는 경로

#### 그래프 표현
- 간선의 정보를 저장하는 방식, 메모리나 성능을 고려해서 결정
- **인접 행렬**
  - |V| * |V| 크기의 2차원 배열을 이용해서 간선 정보를 저장
  - 두 정점을 연결하는 간선의 유무를 행렬로 표현
  - 행 번호와 열 번호는 그래프의 정점에 대응
  - 인접 되어있으면 1, 그렇지 않으면 0
- **인접 리스트**
  - 각 정점마다 해당 정점으로 나가는 간선의 정보를 저장
  - 하나의 정점에 대한 인접 정점들을 각각 노드로 하는 연결 리스트로 저장
- 간선의 배열
  - 간선(시작 정점, 끝 정점)을 배열에 연속적으로 저장
  
#### 그래프 탐색
- [DFS](https://github.com/KimUJin3359/Algorithm_Stack)
- [BFS](https://github.com/KimUJin3359/Algorithm_Queue)

### DISJOINT-SETS
- 서로소 또는 상호배타 집합들은 서로 **중복 포함된 원소가 없는 집합들**
- 집합에 속한 하나의 특정 멤버(**대표자**)를 통해 각 집합들을 구분
- 표현 방법
  - 연결 리스트
    - 같은 집합의 원소들은 하나의 연결리스트로 관리
    - 맨 앞의 원소를 집합의 대표로 지정
    - 각 원소는 집합의 대표 원소를 가리키는 링크를 가짐
  - 트리
    - 하나의 집합을 하나의 트리로 표현
    - 자식 노드가 부모 노드를 가리키며 루트 노드가 대표자
- 연산
  - Make-Set(x)
    - 유일한 멤버 x를 포함하는 새로운 집합을 생성하는 연산
  - Find-Set(x)
    - x를 포함하는 집합을 찾는 연산
  - Union(x, y)
    - x와 y를 포함하는 두 집합을 통합하는 연산
- 연산의 효율을 높이는 방법
  - Rank를 이용한 Union
    - 각 노드는 자신을 루트로 하는 subtree의 높이를 rank로 저장
    - 두 집합을 합칠 때 rank가 낮은 집합을 rank가 높은 집합에 붙임
  - Path Compression
    - Find-Set을 행하는 과정에서 만나는 모든 노드들이 직접 root를 가리키도록 포인터를 바꿈
    
### MST(최소비용신장트리)
- 그래프에서 **최소 비용 문제**
  - 모든 정점을 연결하는 간선들의 가중치의 합이 최소가 되는 트리
- 신장 트리
  - n개의 정점으로 이루어진 무방향 그래프에서 **n개의 정점과 n - 1개의 간선**으로 이루어진 트리
- 최소 신장 트리(Minimum Spanning Tree)
  - 무방향 가중치 그래프에서 **신장 트리를 구성하는 간선들의 가중치의 합이 최소**인 신장 트리
  
### PRIM Algorithm
- 하나의 정점에서 **연결된 간선들 중에 하나씩 선택**하면서 MST를 만들어 가는 방식
  - 임의 정점을 하나 선택해서 시작
  - 선택한 정점과 인접하는 정점들 중의 최소 비용의 간선이 존재하는 정점을 선택
  - 모든 젇점이 선택될 때 까지 위 과정 반복
- 2개의 정보를 유지
  - tree 정점 : MST를 만들기 위해 선택된 정점들
  - nontree 정점 : 선택되지 않은 정점들
  
### KRUSKAL Algorithm
- 간선을 하나씩 선택해서 MST를 찾는 알고리즘
  - 최초, 모든 간선을 가중치에 따라 오름차순으로 정렬
  - **가중치가 낮은 간선**부터 선택하면서 트리를 증가시킴
    - 사이클이 존재하면 넘김
  - n - 1 개의 간선이 선택될 때 까지 반복

### 최단 경로
- 간선의 가중치가 있는 그래프에서 두 정점 사이의 경로들 중에 간선의 가중치의 합이 최소인 경로
- 최단 경로를 구하는 알고리즘
  - 다익스트라 알고리즘 : 음의 가중치를 허용하지 않음
  - 벨만-포드 알고리즘 : 음의 가중치를 허용
- 모든 정점들에 대한 최단 경로
  - 플로이드-워셜 알고리즘

### DIJKSTRA Algorithm
- 시작 정점에서 거리가 **최소인 정점을 선택**해 나가면서 최단 경로를 구하는 방식
- 시작 정점(s)에서 끝 정점(e) 까지의 최단 경로에 정점 x가 존재
- 이 때, 최단경로는 s에서 e까지의 최단 경로와 x에서 e까지의 최단 경로로 구성
- Greedy 방식을 사용한 알고리즘으로 프림 알고리즘과 유사

#### 관련 문제
[1.Supply Route(SW Expert Academy : 보급로)](https://github.com/KimUJin3359/Algorithm_Graph/blob/master/SupplyRoute/SupplyRoute/main.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV15QRX6APsCFAYD&probBoxId=AXfR0f36NEsDFAUO&type=PROBLEM&problemBoxTitle=Day+12%28Graph%29&problemBoxCnt=2)
- 전투로 인해 도로 곳곳이 파손된 상태
- 출발지(S)에서 도착지(G)까지 가기 위한 도로 복구 작업을 빠른 시간내에 수행해야 함
- 출발지에서 도착지까지 가는 경로 중에 복구 시간이 가장 짧은 겨올에 대한 총 복구 시간을 구하는 문제
- 접근 방법
  - 실력 향상을 위한 Back Tracking(원래는 BFS로 찾는다면 바로 결과를 도출할 수 있음)
  - 상하좌우 순이 아닌 하우상좌의 순으로 최적의 결과를 먼저 구함
  - 현재 방문한 지점 까지의 결과값을 저장하고 있다가, 다음 순서에 또 방문 했을 때 기존의 값보다 결과값이 더 클 시 더 이상 다음 경로를 확인하지 않음
    
[2.Supply Route(위와 동일)](https://github.com/KimUJin3359/Algorithm_Graph/blob/master/SupplyRoute_Dijkstra/SupplyRoute_Dijkstra/main.cpp)
- 접근 방법
  - 다익스트라 알고리즘을 활용
  - 현재 연결되어있는 경로 중 최소값을 빠르게 찾기 위해 priority queue 사용

[3.For One(SW Expert Academy : 하나로)](https://github.com/KimUJin3359/Algorithm_Graph/blob/master/ForOne/ForOne/main.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV15StKqAQkCFAYD&probBoxId=AXfR0f36NEsDFAUO&type=PROBLEM&problemBoxTitle=Day+12%28Graph%29&problemBoxCnt=2)
- 인도네시아 N개의 섬들을 연결하는 교통시스템 설계 프로젝트인 하나로
- 환경 부담 세율(E)과 각 해저터널 길이(L)의 제곱의 곱(E * L^2)만큼 지불
- 환경 부담금을 최소로 하며 모든 섬을 연결할 때 그 값을 구하는 문제
- 접근 방법
  - 최소비용신장트리를 구하는 문제(크루스칼 알고리즘 사용)
  - 사이클의 존재 유무를 위하여 Disjoin set 사용
  - 최소 비용의 간선을 찾기 위해 priority queue 사용
- 까다로운 부분
  - 알고리즘 자체를 구현하는 것은 어렵지 않았음
  - 계산을 할 때 long long = int + int -> int의 값으로 계산이 되 overflow/underflow 발생 가능
  - 해당 결과 값이 반올림 값을 사용
  - E * L^2의 값이 각각에 대한 계산 후 합이 아니라 전체를 구한 후 E를 곱해주는 방식

