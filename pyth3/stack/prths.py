import stack as st

def main(temp):
    stk = st.stack()
    for ch in temp:
        if ch == '{' or ch == '(' or ch == '[':
            stk.push(ch)
        else:
            if ((ch == '}' and stk.wh_top() == '{') or (ch == ']' and stk.wh_top() == '[') or (ch == ')' and stk.wh_top() == '(')):
                stk.pop()
            else:
                return False
        print(f"value at string {ch} value at stack {stk.wh_top()}")        

    if stk.isEmpty():
        return True
    else:
        return False



if __name__  == "__main__":
    srt = ""
    srt = input()
    if main(srt):
        print("it is valid")
    else:
        print("It is invalid")    