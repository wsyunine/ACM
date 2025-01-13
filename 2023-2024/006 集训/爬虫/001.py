import requests
for i in range(10):
    response = requests.get('https://source.unsplash.com/random/800x600')
    with open("006 集训/爬虫/"+str(i)+".jpg","wb+") as f:
        f.write(response.content)