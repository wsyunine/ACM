import pandas as pd
from sklearn import tree
import matplotlib.pyplot as plt

data = {
    "weather":["晴朗","阴天","雨天","晴朗","晴朗","阴天","雨天","晴朗"],
    "degree":["热","温暖","冷","温暖","冷","热","温暖","温暖"],
    "humidity":["高","高","高","正常","正常","正常","高","高"],
    "decision":["去","不去","不去","去","去","去","不去","不去"]
}

df=pd.DataFrame(data)

print(df)

mapping={
    'weather':{'晴朗':0,'阴天':1,'雨天':2},
    'degree':{'热':0,'温暖':1,'冷':2},
    'humidity':{'高':0,'正常':1},
    'decision':{'去':0,'不去':1}
}

for column, map in mapping.items():
    df[column]=df[column].map(map)

X=df[['weather','degree','humidity']]
y=df['decision']

clf=tree.DecisionTreeClassifier(criterion='entropy')
clf=clf.fit(X,y)

plt.figure(figsize=(7,7))
tree.plot_tree(clf, filled=True,
               feature_names=['weather','degree','humidity'],
               class_names=['go','no go'])
plt.show()