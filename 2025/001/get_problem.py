import urllib.request
from bs4 import BeautifulSoup

def get_problem_content(contest_id, problem_index):
    url = f"https://codeforces.com/problemset/problem/{contest_id}/{problem_index}"

    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }

    request = urllib.request.Request(url, headers=headers)

    try:
        response = urllib.request.urlopen(request)
        html = response.read()

        # 使用 BeautifulSoup 解析 HTML
        soup = BeautifulSoup(html, 'html.parser')

        # 提取题目标题
        title_tag = soup.find("div", class_="title")
        title = title_tag.text.strip() if title_tag else "未找到题目标题"

        # 提取完整题目信息
        problem_statement_tag = soup.find("div", class_="problem-statement")
        if not problem_statement_tag:
            return title, "未找到题目内容"

        # 提取所有子部分
        parts = problem_statement_tag.find_all(["p", "div", "pre"])

        # 拼接完整的题目内容
        problem_text = "\n".join(part.text.strip() for part in parts if part.text.strip())

        return title, problem_text

    except urllib.error.HTTPError as e:
        print(f"HTTP Error: {e.code}")
        return None, None

if __name__ == "__main__":
    contest_id = input("请输入比赛 ID: ")
    problem_index = input("请输入题目编号 (如 A, B, C): ").upper()

    title, problem_text = get_problem_content(contest_id, problem_index)

    if title and problem_text:
        print("\n📌 题目标题:", title)
        print("\n📜 题目完整内容:\n")
        print(problem_text)
