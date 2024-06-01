def recur(i,stack,l):
    if len(stack)==4:
        return stack
    print('i:',i,'stack',stack,',l=',l)
    stack.append(i)
    recur(i, stack, l+1)
    stack.pop()
    stack.append(i+1)
    recur(i+1, stack, l+1)
    stack.pop()

print(recur(0,[],0))
print()
print('check')
print(len([]))