text = """"
# def f(): 
def f1():  # f1 
pass 
def   
f2 (x ) : 
    def t1(x): 
pass 
    return t1 
def f3(x, y, z): 
print(x, y, z) 
def f4 f5(): pass 
"""

import re 
count = pos = 0 
""" 提取函数名的正则表达式中，有如下要求：某一行以def开始，函数名必须是合法的
python 标识符;在此之后有一个左括号表示参数部分的开始。""" 
regexp = re.compile(r"^def\s+(\w+)\s*\(" , re.M)          
while True: 
    match = regexp.search(text, pos) 
    if not match: 
        break 
    count += 1 
    print(count, match.group(1)) 
    pos = match.end()         