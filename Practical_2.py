A=set()
B=set()
C=set()
n=int(input("Enter no. of elements to be inserted \n"))

def display():
    print("Set 1st is ",A)
    print("Set 2nd is ",B)
    
def insert():
    ch=int(input("Enter the set in which element is to be inserted (1/2)"))
    if (ch==1):
        for i in range (0,n):
            ele=int(input("Enter the element = "))
            A.add(ele)
    elif (ch==2):
        for i in range (0,n):
            ele=int(input("Enter the element = "))
            B.add(ele)
    else:
        print("Enter valid set")
    display()
    
def delete():
    x=int(input("Enter the element to be deleted = "))
    ch=int(input("Enter the set from which element is to be deleted (1/2) ="))
    if (ch==1):
        A.remove(x)
    elif (ch==2):
        B.remove(x)
    else:
        print("Enter valid set ")
    display()    
        
def union():
    print("union of both sets are ",A | B)
    
def inter():
    print("Intersection of set are ",A & B)
    
def diff():
    print("Difference of both sets are ", A - B)
    
def symm():
    print("Symmetric Diff are ", A ^ B)

def sub():
    m=int(input("Enter no. of elements "))
    for i in range(0,m):
        ele=int(input("Elements = "))
        C.add(ele)
    ch=int(input("Enter the set to find the subset from  (1/2) ="))
    if (ch==1):
        print("C is a subset of A ",C.issubset(A))
    if (ch==2):
        print("C is a subset of B ",C.issubset(B))
 
def search():
    key=int(input("Enter the element to be searched "))
    ch=int(input("Enter the set from which the element is to found  (1/2) ="))
    if (ch==1):
        for i in A:
            if (key==i):
                print("Element found in 1st set")
                break
        print("Element not found ")
    
    elif (ch==2):
        for i in B:
            if (key==i):
                print("Element found ")
        
        print("Elememt not found ")
def main():
    loop=True
    while loop:
        print("1>Display\t2>Insert\t3>Delete\t4>Union\n5>Intersection\t6>Difference\t7>Symmetric Diff\t8>Subset\n9>Search")
        c=int(input("Enter your choice ="))
        if (c==1):
            display()
        elif (c==2):
            insert()
        elif (c==3):
            delete()
        elif (c==4):
            union()
        elif (c==5):
            inter()
        elif (c==6):
            diff()
        elif (c==7):
            symm()
        elif (c==8):
            sub()
        elif (c==9):
            search()
main()
