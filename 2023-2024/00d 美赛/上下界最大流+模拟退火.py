from collections import defaultdict, deque
import pandas as pd
import csv
import math

a=[350,307,206,241,193]
a=a*5280
b=[160,118,183,57,53]
b=b*5280
d_max=[482,923,750,210,802]
d_max=d_max*5


data_2_to_3_max=[6827.191058, 6920.636643, 6866.834639, 6914.973274, 7002.75549, 6917.804958, 6940.458433, 7005.587174, 7011.250543, 6999.923806, 6943.290118, 6878.161377]
data_2_to_3_min=[3746.318444, 3802.952132, 4244.694897, 4607.150498, 4961.111047, 4966.774415, 4881.823884, 4876.160515, 4842.180302, 4819.526827, 4709.091136, 4621.30892]
data_3_to_4_max=[7530, 7700, 7660, 7920, 7850, 8070, 7830, 7650, 7280, 7150, 7200, 7200]
data_3_to_4_min = [5050, 4910, 5020, 5180, 5540, 5400, 5220, 5210, 5020, 5030, 5130, 5090]
data_2_to_3_max=data_2_to_3_max*2592000
data_2_to_3_min=data_2_to_3_min*2592000
data_3_to_4_max=data_3_to_4_max*2592000
data_3_to_4_min=data_3_to_4_min*2592000

lake1=[718.1677056, 713.5259873, 695.9285128, 712.2531474, 712.863734, 699.379932, 687.6707237, 745.7270618, 782.7508777, 651.098296, 751.2898764, 718.7754456]
lake2=[317.4646282, 344.7421451, 327.0215977, 317.1361599, 402.497064, 333.5372407, 348.9195425, 385.5900718, 282.5787824, 308.250243, 329.1309017, 329.2371922]
lake3=[600.0805037, 634.6898017, 606.569353, 623.8984295, 650.4566187, 594.7823198, 584.8081278, 667.3797964, 620.051188, 601.5397718, 626.9184223, 629.145095]
lake4=[331.7673852, 361.3454317, 364.4441065, 353.5289673, 393.4462183, 363.5857224, 332.0647159, 337.038912, 360.0810333, 359.7168389, 329.2914965, 370.7830051]
lake5=[191.1038455, 204.6380054, 208.0475827, 207.1970588, 228.0689554, 199.294413, 164.3279386, 203.9977158, 188.7977399, 205.994502, 174.3583271, 216.5090031]

lake1_in=[9402800000, 8020200000, 8739200000, 14304800000, 16469600000, 18869500000, 17828800000, 16630700000, 19793200000, 20650800000, 13457500000, 12155800000]
lake2_in=[8694147143, 7926989429, 9476122286, 14910184000, 17874172000, 17129952000, 14944004571, 15610286571, 15385932286, 17175492571, 11662655714, 10614636571]
lake3_in=[5730593143, 4921266857, 4806254571, 7555795714, 8147424857, 7846932857, 6957041143, 7768596857, 7444455429, 8551650857, 6621446571, 6452490857]
lake4_in=[6097198143, 5444553571, 6181957714, 7695657143, 9080132286, 8486030857, 8455107857, 7679679571, 7833675286, 7979455143, 6783242857, 6688161857]
lake5_in=[6063703333, 5594081429, 5460332857, 7306331905, 7551340000, 8332449048, 7474229048, 7268033333, 7283526667, 8923171905, 6913781429, 7464308571]

class Graph:
    def __init__(self):
        self.graph = defaultdict(dict)

    def add_edge(self, u, v, lower_bound, upper_bound):
        self.graph[u][v] = {'flow': 0, 'capacity': upper_bound - lower_bound, 'lower_bound': lower_bound}
        self.graph[v][u] = {'flow': 0, 'capacity': 0, 'lower_bound': 0}  # Reverse edge

    def capacity_scaling_max_flow(self, source, sink, scaling_factor):
        max_flow = 0
        delta = 2 ** scaling_factor

        while delta >= 1:
            while True:
                parent = self.bfs(source, sink, delta)
                if not parent:
                    break

                path_flow = float('inf')
                v = sink
                while v != source:
                    u = parent[v]
                    edge = self.graph[u][v]
                    path_flow = min(path_flow, edge['capacity'] - edge['flow'])
                    v = u

                v = sink
                while v != source:
                    u = parent[v]
                    self.graph[u][v]['flow'] += path_flow
                    self.graph[v][u]['flow'] -= path_flow
                    v = u

                max_flow += path_flow

            delta //= 2

        return max_flow

    def bfs(self, source, sink, delta):
        parent = {source: None}
        queue = deque([source])

        while queue:
            u = queue.popleft()

            for v, edge in self.graph[u].items():
                residual_capacity = edge['capacity'] - edge['flow']

                if residual_capacity >= delta and v not in parent:
                    parent[v] = u
                    queue.append(v)

                    if v == sink:
                        return parent

        return None
    
g=Graph()
g.__init__()

import math
import random

def jiantu(x,j):

    g.__init__()

    g.add_edge(1, 2, 0, x[0])
    g.add_edge(2, 3, 0, data_2_to_3_max[j])
    g.add_edge(3, 4, 0, data_3_to_4_max[j])
    g.add_edge(4, 5, 0, x[1])
    g.add_edge(10, 1, 0, 5)
    g.add_edge(1, 6, 0, 2)
    g.add_edge(2, 7, 0, 4)
    g.add_edge(3, 8, 1, 100)
    g.add_edge(4, 9, 0, 5)
    g.add_edge(11, 2, 0, 5)
    g.add_edge(12, 3, 0, 5)
    g.add_edge(13, 4, 0, 5)
    g.add_edge(14, 10, 0, 5)
    g.add_edge(14, 11, 0, 5)
    g.add_edge(14, 12, 0, 5)
    g.add_edge(14, 13, 0, 5)
    g.add_edge(14, 1, 6, 6)
    g.add_edge(14, 2, 6, 6)
    g.add_edge(14, 3, 6, 6)
    g.add_edge(14, 4, 6, 6)
    g.add_edge(1, 15, 0, 5)
    g.add_edge(2, 15, 0, 5)
    g.add_edge(3, 15, 0, 5)
    g.add_edge(4, 15, 0, 5)
    g.add_edge(5, 15, 0, 1e18)
    g.add_edge(6, 15, 0, 1e18)
    g.add_edge(7, 15, 0, 1e18)
    g.add_edge(8, 15, 0, 1e18)
    g.add_edge(9, 15, 0, 1e18)

    return None

def objective_function(x,j):

    jiantu(x,j)

    g.capacity_scaling_max_flow(14,15,32)

    sum=0
    for i in [1,2,3,4]:
        sum=sum+abs(g.graph[1][15])
    
    return 1

def acceptance_probability(old_cost, new_cost, temperature):
    """
    计算接受新解的概率。
    """
    if new_cost < old_cost:
        return 1.0
    return math.exp((old_cost - new_cost) / temperature)

def simulated_annealing(initial_solution, temperature, cooling_rate, iterations,j):
    current_solution = initial_solution
    current_cost = objective_function(current_solution,j)

    for iteration in range(iterations):
        # 生成新解
        new_solution = [current_solution[i] + random.uniform(-3, 3) for i in range(len(current_solution))]
        new_cost = objective_function(new_solution,j)

        # 接受新解的概率
        probability = acceptance_probability(current_cost, new_cost, temperature)

        # 判断是否接受新解
        if random.random() < probability:
            current_solution = new_solution
            current_cost = new_cost

        # 降低温度
        temperature *= cooling_rate

    return current_solution, current_cost

# 示例用法

for num in [1,2,3,4,5,6,7,8,9,10,11,12]:

    initial_solution = [0.0, 0.0]
    initial_temperature = 1.0
    cooling_rate = 0.95
    iterations = 1000

    final_solution, final_cost = simulated_annealing(initial_solution, initial_temperature, cooling_rate, iterations,num)

    print("Final Solution:", final_solution)
    print("Final Cost:", final_cost)


# # 示例用法
# g = Graph()
# g.add_edge(1, 2, 0, 5)
# g.add_edge(2, 3, 0, 3)
# g.add_edge(3, 4, 0, 4)
# g.add_edge(4, 5, 0, 3)
# g.add_edge(10, 1, 0, 5)
# g.add_edge(1, 6, 0, 2)
# g.add_edge(2, 7, 0, 4)
# g.add_edge(3, 8, 1, 100)
# g.add_edge(4, 9, 0, 5)
# g.add_edge(11, 2, 0, 5)
# g.add_edge(12, 3, 0, 5)
# g.add_edge(13, 4, 0, 5)
# g.add_edge(14, 10, 0, 5)
# g.add_edge(14, 11, 0, 5)
# g.add_edge(14, 12, 0, 5)
# g.add_edge(14, 13, 0, 5)
# g.add_edge(14, 1, 6, 6)
# g.add_edge(14, 2, 6, 6)
# g.add_edge(14, 3, 6, 6)
# g.add_edge(14, 4, 6, 6)
# g.add_edge(1, 15, 100, 100)
# g.add_edge(2, 15, 100, 100)
# g.add_edge(3, 15, 100, 100)
# g.add_edge(4, 15, 100, 100)
# g.add_edge(5, 15, 100, 100)
# g.add_edge(6, 15, 100, 100)
# g.add_edge(7, 15, 100, 100)
# g.add_edge(8, 15, 100, 100)
# g.add_edge(9, 15, 100, 100)

# max_flow = g.capacity_scaling_max_flow(14, 15, 32)
# print("Maximum Flow:", max_flow)
