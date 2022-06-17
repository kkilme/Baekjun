class node:
    def __init__(self, item, left, right):
        self.item = item
        self.left = left if left != '.' else None
        self.right = right if right != '.' else None

def preorder(rt):
        print(rt.item,end='')
        if(rt.left != None): preorder(tree[rt.left])
        if(rt.right != None): preorder(tree[rt.right])
    
def inorder(rt):
        if(rt.left != None): inorder(tree[rt.left])
        print(rt.item,end='')
        if(rt.right != None): inorder(tree[rt.right])
    
def postorder(rt):
        if(rt.left != None): postorder(tree[rt.left])
        if(rt.right != None): postorder(tree[rt.right])
        print(rt.item,end='')

n = int(input())
tree = dict()

for _ in range(n):
    item, left, right = input().split()
    tree[item] = node(item,left,right)

preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])