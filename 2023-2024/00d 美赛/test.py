from collections import defaultdict
import pandas as pd

import csv
cnt=0
data_d=[]
with open('/Users/wsy/后端/new code/00d 美赛/T1ans.csv', 'r') as csvfile:
    data = csv.reader(csvfile)
    
    for row in data:
        cnt=cnt+1
        data_d[cnt]=row


print(data_d)