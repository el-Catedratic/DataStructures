import stack as st

def nge(lst):
    temp = dict()
    stk = st.stack()
    stk.push(lst[0])
    cnt = 0
    for i in lst:
        cnt+=1
        if cnt ==1:
            continue
        else:
            if stk.wh_top() < i:
                while stk.wh_top()<i:
                    temp[stk.wh_top()] = i
                    stk.pop()
                stk.push(i)
            else:
                stk.push(i) 
    return temp               



if __name__ == "__main__":
    vec = []
    vec = input()
    res = nge(vec)
    for key,value in res.items():
        print(f"{key}-->{value}")