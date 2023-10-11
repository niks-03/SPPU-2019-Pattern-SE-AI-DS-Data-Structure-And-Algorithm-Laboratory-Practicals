import array as hash

class Linear:
    def __init__(self):
        self.n=int(input("Enter size of hash table: "))
        self.table=hash.array("i", [-1]*self.n)

    def insert(self):
        key=int(input("enter key: "))
        location=key % self.n

        if (self.table[location]==-1):
            self.table[location]=key

        else:
            print("\nThrough which method u want to solve collision\n1.Linear Probing\n2.Quadratic Probing ")
            choice=int(input("choice: "))

            if choice==1:
                index= location
                for i in range(location, self.n):
                    if self.table[index]==-1:
                        self.table[index]=key

                        print("\ncollision is occurring....\n")
                        print("collision is resolved using \"Linear Probing without replacement\"")
                        print("key is stored at location \"", index, "\"")
                        break
                    else:
                        index+=1

                if index==self.n:
                    print("free space not available")

            if choice==2:
                for i in range(1, self.n):
                    new_location=(key + i*i)%self.n
                    if self.table[new_location]==-1:
                        self.table[new_location]=key
                        print("\ncollision is occurring....\n")
                        print("collision is resolved using \"Quadratic Probing\"")
                        print("key is stored at location \"", new_location, "\"")
                        break

        print("----------------------------------------")

    def display(self):
        print("\nHash Table: ", end=" ")
        print("\n|", end=" ")
        for i in range(self.n):
            print(self.table[i], "|", end=" ")
        print("\n")

        print("----------------------------------------")

    def delete(self):
        delkey=int(input("enter key to be deleted: "))

        location= delkey % self.n


        if self.table[location]==delkey:
            self.table[location]= -1
            print("key is deleting....")
            print("key is deleted")
            print("----------------------------------------")
        else:
            index=location
            for i in range(location, self.n):
                if (self.table[index]==delkey):
                    self.table[index]= -1
                    print("deleting key...")

                else:
                    index+=1

            if index==self.n:
                print("key is not present in hash table")
                print("----------------------------------------")

    def search(self):
        searchkey=int(input("enter key to be searched: "))

        location= searchkey % self.n

        if self.table[location]==searchkey:
            print("key is present at location ", location)
        else:
            for i in range(location+1, self.n):
                if self.table[i]==searchkey:
                    print("key is present at location ", location)

            print("key is not found")

        print("----------------------------------------")


def main():
    hash_obj=Linear()

    loop=True
    while loop:
        print("1.insert\n2.display\n3.search\n4.delete\n5.exit")
        ch=int(input("choice: "))

        if ch==1:
            hash_obj.insert()
        elif ch==2:
            hash_obj.display()
        elif ch==3:
            hash_obj.search()
        elif ch==4:
            hash_obj.delete()
        elif ch==5:
            loop=False

        print("----------------------------------------")


main()
